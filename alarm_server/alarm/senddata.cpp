#include "senddata.h"

SendData::SendData(QObject *parent) : QObject(parent)
{

}
void SendData::initThis()
{
    senderSocket=new QUdpSocket;
}
void SendData::onAlert(int AlertNum)
{
    for(int i=0;i<g->alarmInfoList.count();i++)
    {
        if(g->alarmInfoList.at(i).alarmNo==AlertNum)
        {
            AlarmInfo info=g->alarmInfoList[i];
            QString data;
            data+="2|";
            data+=QString::number(info.alarmCh);
            data+="|";
            int type=info.alarmType;
            data+=QString::number(type);
            data+="|";
            data+=info.startTime.toString("yyyy-MM-dd hh:mm:ss");
            data+=";";
            senderSocket->writeDatagram(data.toLatin1(),QHostAddress(g->serverIp),g->serverPort);
            break;
        }
    }

}
void SendData::onAlert(int ch,int type,QDateTime time)
{

    QString data;
    data+="2|";
    data+=QString::number(ch);
    data+="|";
    data+=QString::number(type);
    data+="|";
    data+=time.toString("yyyy-MM-dd hh:mm:ss");
    data+=";";
    senderSocket->writeDatagram(data.toLatin1(),QHostAddress(g->serverIp),g->serverPort);
    qDebug()<<"alarm send"<<data;
}
void SendData::simData(int ch,float sim)
{
    QString data;
    data+="3|";
    data+=QString::number(ch);
    data+="|";
    data+=QString::number(sim);
    data+="|";
    data+=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    data+=";";
    senderSocket->writeDatagram(data.toLatin1(),QHostAddress(g->serverIp),g->serverPort);

}
