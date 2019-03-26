#ifndef SENDDATA_H
#define SENDDATA_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include "global.h"
class SendData : public QObject
{
    Q_OBJECT
public:
    explicit SendData(QObject *parent = nullptr);
    QUdpSocket *senderSocket;
signals:

public slots:
    void initThis();
    void onAlert(int);
    void onAlert(int ch,int type,QDateTime time);
    void simData(int ch,float sim);
};

#endif // SENDDATA_H
