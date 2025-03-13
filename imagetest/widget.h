#ifndef WIDGET_H
#define WIDGET_H
#include"worker.h"
#include <QWidget>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QImageCapture>
#include <QVideoWidget>
#include <QTimer>
#include <QImage>
#include <QNetworkAccessManager>
#include <QSslConfiguration>
#include <QString>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void takepicture();
    void showpicture(int id, const QImage &preview);
    void tokenReply(QNetworkReply *reply);
    void imageRequery(QByteArray postData,QThread*workerThread);
    void imageReply(QNetworkReply *reply);
    void readyImage();
    void cameraChange(int index);
    void beginGame();
    void analyGame();
signals:
    void beginWork(QImage img,QThread*workerThread);
private:
    Ui::Widget *ui;
    QCamera *camera;
    QList<QCameraDevice> cameras;
    QMediaCaptureSession* capture;
    QVideoWidget* videowidget;
    QTimer *timer;
    QTimer *tokenTimer;
    QImageCapture *imagecapture;
    QImage img;
    QNetworkAccessManager* tokenManager;
    QNetworkAccessManager* imageManager;
    QSslConfiguration sslConfiguration;
    QString token;
    QString expression;
    QString gender;
    QString glasses;
    QString faceshape;
    QThread *workerThread;


    int mask;
    double imgleft;
    double imgtop;
    double imgwidth;
    double imgheight;
    double age;
    double beauty;

    int gamecnt;
    int gamePlayer;
    int player;
    QTimer* gameTimer;
    QString gameText;


};
#endif // WIDGET_H
