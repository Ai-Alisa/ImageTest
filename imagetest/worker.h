#ifndef WORKER_H
#define WORKER_H

#include <QObject>

#include <QImage>

class worker : public QObject
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = nullptr);
private:
    QByteArray postData;
public slots:
    void doWork(QImage img,QThread*workerThread);

signals:
    void resultReady(QByteArray postData,QThread*workerThread);
};

#endif // WORKER_H
