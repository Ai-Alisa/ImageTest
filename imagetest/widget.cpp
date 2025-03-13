#include "widget.h"
#include "ui_widget.h"
#include "worker.h"
#include <QCamera>
#include <QMediaCaptureSession>
#include <QVideoWidget>
#include <QImageCapture>
#include <QImage>
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QSslConfiguration>
#include <QNetworkReply>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QBuffer>
#include <QJsonArray>
#include <QPainter>
#include <QFont>
#include <QThread>
#include <QMediaDevices>
#include <QCameraDevice>
#include <QRandomGenerator>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //遍历摄像头
    cameras=QMediaDevices::videoInputs();
    for(const QCameraDevice &cameraDevice:cameras){
        qDebug()<<cameraDevice.description();
        ui->comboBox->addItem(cameraDevice.description());
    }
    connect(ui->comboBox,&QComboBox::currentIndexChanged,this,&Widget::cameraChange);
    //摄像头环境配置
    camera = new QCamera;
    capture = new QMediaCaptureSession(ui->lable1);
    videowidget = new QVideoWidget(ui->lable2);
    videowidget->resize(ui->lable2->size());
    imagecapture = new QImageCapture;
    capture->setImageCapture(imagecapture);
    capture->setCamera(camera);
    capture->setVideoOutput(videowidget);
    camera->start();

    //定时器进行捕捉
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::takepicture);
    timer->start(20);

    //将捕捉的画面进行显示
    connect(imagecapture,&QImageCapture::imageCaptured,this,&Widget::showpicture);

    //游戏界面设置
    gamecnt=3;
    gameTimer=new QTimer(this);
    ui->pushButton->setText("开始游戏！");
    ui->gamelabel->setText("猜拳游戏！");
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::beginGame);
    connect(gameTimer,&QTimer::timeout,this,&Widget::analyGame);

    //进行token的获取
    tokenManager = new QNetworkAccessManager(this);

    QUrl qurl("https://aip.baidubce.com/oauth/2.0/token");

    //人脸token获取
    QUrlQuery qurlQuery;
    qurlQuery.addQueryItem("grant_type","client_credentials");
    qurlQuery.addQueryItem("client_id","YQ7mtHjm7NkCfE80CFiBH2qf");
    qurlQuery.addQueryItem("client_secret","V5XUKU7A5por2v3HUTIN1MKorUqDYVd2");
    qurl.setQuery(qurlQuery);


    //游戏token获取
    // QUrlQuery qurlQuery;
    // qurlQuery.addQueryItem("grant_type","client_credentials");
    // qurlQuery.addQueryItem("client_id","8huBr3gtRKmG2ngOEYwL5Pwq");
    // qurlQuery.addQueryItem("client_secret","R1k7qyENvl0vgHjxWzEA3UFQkRw9w3kw");
    // qurl.setQuery(qurlQuery);

    sslConfiguration= QSslConfiguration::defaultConfiguration();
    sslConfiguration.setPeerVerifyMode(QSslSocket::QueryPeer);
    sslConfiguration.setProtocol(QSsl::TlsV1_2);

    QNetworkRequest req;
    req.setUrl(qurl);
    req.setSslConfiguration(sslConfiguration);
    tokenManager->get(req);
    connect(tokenManager,&QNetworkAccessManager::finished,this,&Widget::tokenReply);

    //进行imageReply
    imageManager = new QNetworkAccessManager(this);
    connect(imageManager,&QNetworkAccessManager::finished,this,&Widget::imageReply);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::cameraChange(int index){
    if(camera){
        timer->stop();
        camera->stop();
        delete camera;
        delete capture;
        camera=nullptr;
        capture=nullptr;
    }
    camera=new QCamera(cameras.at(index));
    capture = new QMediaCaptureSession(ui->lable1);
    capture->setImageCapture(imagecapture);
    capture->setCamera(camera);
    capture->setVideoOutput(videowidget);
    camera->start();
    timer->start(20);
    connect(timer,&QTimer::timeout,this,&Widget::takepicture);

}
void Widget::takepicture(){
    imagecapture->capture();
}
void Widget::readyImage(){
    workerThread=new QThread(this);
    worker* work=new worker;
    work->moveToThread(workerThread);
    connect(workerThread, &QThread::finished, work, &QObject::deleteLater);
    connect(this,&Widget::beginWork, work,&worker::doWork);
    connect(work, &worker::resultReady, this,&Widget::imageRequery);
    workerThread->start();
    emit beginWork(img,workerThread);
}



void Widget::showpicture(int id, const QImage &preview){
    Q_UNUSED(id);
    this->img=preview;

    //绘制人脸信息
    QPainter p(&img);
    p.setPen(Qt::red);
    QFont font= p.font();
    font.setPixelSize(30);
    p.setFont(font);
    p.drawText(imgleft+imgwidth+5,imgtop,QString("年龄：").append(QString::number(age)));
    p.drawText(imgleft+imgwidth+5,imgtop+40,QString("性别：").append(gender));
    p.drawText(imgleft+imgwidth+5,imgtop+80,QString("颜值：").append(QString::number(beauty)));
    p.drawText(imgleft+imgwidth+5,imgtop+120,QString("表情：").append(expression));
    p.drawText(imgleft+imgwidth+5,imgtop+160,QString("眼镜：").append(glasses=="none"?"没戴":(glasses=="common"?"普通眼镜":"墨镜")));
    p.drawText(imgleft+imgwidth+5,imgtop+200,QString("口罩：").append(mask==0?"没戴":"戴了 "));
    p.drawText(imgleft+imgwidth+5,imgtop+240,QString("脸型：").append(faceshape));
    p.drawRect(imgleft,imgtop,imgwidth,imgheight);

    ui->lable1->setPixmap(QPixmap::fromImage(img));
}
void Widget::tokenReply(QNetworkReply *reply){
    if(reply->error()!=QNetworkReply::NoError){
        qDebug()<<reply->error();
        return;
    }
    const QByteArray tokenByte=reply->readAll();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(tokenByte,&jsonError);
    if(jsonError.error!=QJsonParseError::NoError){
        qDebug()<<jsonError.errorString();
        return;
    }
    QJsonObject jsonObj=jsonDoc.object();
    if(jsonObj.contains("access_token"))
        token=jsonObj.take("access_token").toString();
    qDebug()<<token;
    reply->deleteLater();
    ui->textBrowser->setText(token);
    readyImage();//手势识别时此行代码注释

}
void Widget::imageRequery(QByteArray postData,QThread*workerThread){

    workerThread->quit();
    workerThread->wait();
    //人脸url
    QUrl url("https://aip.baidubce.com/rest/2.0/face/v3/detect");
    //手势url
    //QUrl url("https://aip.baidubce.com/rest/2.0/image-classify/v1/gesture");
    QUrlQuery qurlQuery;
    qurlQuery.addQueryItem("access_token",token);
    url.setQuery(qurlQuery);
    QNetworkRequest req;

    //人脸Header
    req.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));

    //手势Header
    //req.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/x-www-form-urlencoded"));

    req.setUrl(url);
    req.setSslConfiguration(sslConfiguration);



    imageManager->post(req,postData);

}
void Widget::imageReply(QNetworkReply *reply){
    if(reply->error()!=QNetworkReply::NoError){
        qDebug()<<reply->errorString();
        return;
    }else{
        //qDebug()<<reply->readAll();
        const QByteArray imgReply=reply->readAll();
        qDebug()<<imgReply;
        QJsonParseError jsonErr;
        QJsonDocument imgdoc=QJsonDocument::fromJson(imgReply,&jsonErr);
        if(jsonErr.error!=QJsonParseError::NoError){
            qDebug()<<jsonErr.errorString();
            return;
        }else{
            QJsonObject imgobj=imgdoc.object();
               QString info;

            //手势解析
            // player=-1;
            // if(imgobj.contains("result_num")){
            //     int resultnum = imgobj.take("result_num").toInt();
            //     if(imgobj.contains("result")){
            //         QJsonArray gameResult=imgobj.take("result").toArray();
            //            for(int i=0;i<resultnum;i++){
            //             QJsonObject resultObj=gameResult.at(i).toObject();
            //                if(resultObj.contains("classname")){
            //                 QString classname=resultObj.take("classname").toString();
            //                    info.append(QString::number(i+1)).append(".").append(classname).append("\r\n");
            //                 if(classname=="Fist"){
            //                     player=0;
            //                     break;
            //                 }else if(classname=="Two"){
            //                     player=1;
            //                     break;
            //                 }else if(classname=="Five"){
            //                     player=2;
            //                     break;
            //                 }
            //             }
            //         }
            //         }
            //     if(player<0){
            //             ui->gamelabel->clear();
            //             ui->gamelabel->setText("识别失败！请重试！");
            //     }else{
            //         int res=(player+3-gamePlayer)%3;
            //         gameText.clear();
            //         ui->gamelabel->clear();
            //         gameText.append("电脑:").append(gamePlayer==0?"石头.":(gamePlayer==1?"剪刀.":"布.")).append("你:").append(player==0?"石头.":(player==1?"剪刀.":"布.")).append("结局:").append(res==0?"平局!":(res==1?"你输了！":"你赢了！"));
            //         ui->gamelabel->setText(gameText);
            //     }






            //人脸解析
            if(imgobj.contains("result")){
                QJsonObject resultobj= imgobj.take("result").toObject();
                if(resultobj.contains("face_list")){
                    QJsonArray facelistarr=resultobj.take("face_list").toArray();
                    QJsonObject faceobj=facelistarr.at(0).toObject();
                    if(faceobj.contains("location")){
                        QJsonObject locationobj=faceobj.take("location").toObject();
                        if(locationobj.contains("left")){
                            imgleft=locationobj.take("left").toDouble();
                        }
                        if(locationobj.contains("top")){
                            imgtop=locationobj.take("top").toDouble();
                        }
                        if(locationobj.contains("width")){
                            imgwidth=locationobj.take("width").toDouble();
                        }
                        if(locationobj.contains("height")){
                            imgheight=locationobj.take("height").toDouble();
                        }
                    }
                    if(faceobj.contains("age")){
                        age=faceobj.take("age").toDouble();
                        info.append("年龄：").append(QString::number(age)).append("\r\n");
                    }
                    if(faceobj.contains("beauty")){
                        beauty=faceobj.take("beauty").toDouble();
                        info.append("颜值：").append(QString::number(beauty)).append("\r\n");
                    }
                    if(faceobj.contains("expression")){
                        QJsonObject expressionobj=faceobj.take("expression").toObject();
                        if(expressionobj.contains("type")){
                            expression=expressionobj.take("type").toString();
                            info.append("表情：").append(expression).append("\r\n");

                        }
                    }
                    if(faceobj.contains("gender")){
                        QJsonObject genderobj=faceobj.take("gender").toObject();
                        if(genderobj.contains("type")){
                            gender=(genderobj.take("type").toString())=="male"?"男":"女";
                            info.append("性别：").append(gender).append("\r\n");
                        }
                    }
                    if(faceobj.contains("glasses")){
                        QJsonObject glassesobj=faceobj.take("glasses").toObject();
                        if(glassesobj.contains("type")){
                            glasses=glassesobj.take("type").toString();
                            info.append("眼镜：").append(glasses=="none"?"没戴":(glasses=="common"?"普通眼镜":"墨镜")).append("\r\n");
                        }
                    }
                    if(faceobj.contains("face_shape")){
                        QJsonObject faceshapeobj=faceobj.take("face_shape").toObject();
                        if(faceshapeobj.contains("type")){
                            faceshape=faceshapeobj.take("type").toString();
                            info.append("脸型：").append(faceshape).append("\r\n");
                        }
                    }
                    if(faceobj.contains("mask")){
                        QJsonObject maskobj=faceobj.take("mask").toObject();
                        if(maskobj.contains("type")){
                            mask=maskobj.take("type").toInt();
                            info.append("口罩：").append(mask==0?"没戴":"戴了 ").append("\r\n");
                        }
                    }
                }
                ui->textBrowser->setText(info);
                qDebug()<<info;
            }
        }
        readyImage();//手势识别时此行代码注释
    }
}
void Widget::beginGame(){
    ui->pushButton->setEnabled(false);
    ui->gamelabel->clear();
    gameText.clear();
    gameText.append("出拳倒计时").append(QString::number(gamecnt));
    ui->gamelabel->setText(gameText);
    gameTimer->start(1000);
}
void Widget::analyGame(){
    if(--gamecnt>0){
        ui->gamelabel->clear();
        gameText.clear();
        gameText.append("出拳倒计时").append(QString::number(gamecnt));
        ui->gamelabel->setText(gameText);
    }else{
        gamePlayer=QRandomGenerator::global()->generate()%3;
        ui->gamelabel->clear();
        gameText.clear();
        gameText.append("请出拳！");
        ui->gamelabel->setText(gameText);
        gameTimer->stop();
        gamecnt=3;
        ui->pushButton->setEnabled(true);
        readyImage();
    }
}
