#include "worker.h"
#include<QJsonObject>
#include<QJsonDocument>
#include<QImage>
#include<QBuffer>

worker::worker(QObject *parent)
    : QObject{parent}
{

}
void worker::doWork(QImage img,QThread*workerThread){
    QByteArray ba;
    QBuffer buffer(&ba);
    img.save(&buffer,"png");

    // 人脸识别请求
    QString base64=ba.toBase64();
    QJsonDocument doc;
    QJsonObject obj;
    obj.insert("image",base64);
    obj.insert("image_type","BASE64");
    obj.insert("face_field","age,expression,face_shape,gender,glasses,mask,beauty");
    doc.setObject(obj);
    QByteArray postData=doc.toJson(QJsonDocument::Compact);


    //游戏请求
    //postData.append("image=").append(ba.toBase64().toPercentEncoding());

    emit resultReady(postData,workerThread);
}
