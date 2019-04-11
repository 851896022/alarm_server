#include "global.h"

Global::Global(QObject *parent) : QObject(parent)
{
    for(int i=0;i<200;i++)
    {
        maxValue[i]=-1;
        alarmDelay[i]=10;
        alarmGate[i]=500;
        simDelay[i]=30;
        simGate[i]=0.3;
        similar[i]=-1;
        standardList[i]=-1;
        similarity[i]=-1;
    }
    //Normal,Similar,Range,All,SimilarCancel,RangeCancel,Other,
    alarmTypeString<<"正常"<<"相似度报警"<<"幅度报警"<<"相似度和幅度报警"<<"相似度恢复"<<"幅度恢复"<<"其他"<<"";
    //读取redis服务器
    {
        QString fileDir=(qApp->applicationDirPath()+"/sav/yxtserver.sav");
        QFile *file = new QFile(fileDir);
        if(file->open(QIODevice::ReadOnly))
        {

            for(int i=0;i<10000;i++)
            {
                {
                    QByteArray ba= file->readLine();
                    QString msg(QString::fromUtf8(ba));
                    QStringList msgList=msg.split(":");
                    if(msgList.count()==2)
                    {
                        g->redisIp=msgList.at(0);
                        g->redisPort=msgList.at(1).toInt();
                    }

                    msg.remove("\r");
                    msg.remove("\n");

                }
                if(file->atEnd())break;
            }
            file->close();

        }
        else
        {
            qDebug()<<"open error"<<fileDir;
        }
        qDebug()<<transmitterName;
        file->deleteLater();
    }
    //读取发射机列表
    {
        QString fileDir=(qApp->applicationDirPath()+"/sav/transmitterlist.sav");
        QFile *file = new QFile(fileDir);
        if(file->open(QIODevice::ReadOnly))
        {

            for(int i=0;i<10000;i++)
            {
                {
                    QByteArray ba= file->readLine();
                    QString msg(QString::fromUtf8(ba));


                    msg.remove("\r");
                    msg.remove("\n");
                    transmitterName.append(msg);
                }
                if(file->atEnd())break;
            }
            file->close();

        }
        else
        {
            qDebug()<<"open error"<<fileDir;
        }
        qDebug()<<transmitterName;
        file->deleteLater();
    }
    //读取通道绑定参数
    {
        QString fileDir=(qApp->applicationDirPath()+"/sav/chinfo.sav");
        QFile *file = new QFile(fileDir);
        if(file->open(QIODevice::ReadOnly))
        {

            for(int i=0;i<10000;i++)
            {
                {
                    QByteArray ba= file->readLine();
                    QString msg(QString::fromUtf8(ba));


                    msg.remove("\r");
                    msg.remove("\n");

                    QStringList msglist=msg.split("|");
                    if(msglist.count()>=3)
                    {
                        int ch=msglist[0].toInt();
                        transmitterNoList[ch]=msglist[1].toInt();
                        standardList[ch]=msglist[2].toInt();
                    }

                }
                if(file->atEnd())break;
            }
            file->close();

        }
        else
        {
            qDebug()<<"open error"<<fileDir;
        }

        file->deleteLater();
    }

    //野指针
    QTimer *timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(outPutState()));
    timer->start(5000);
    QTimer *timerSec=new QTimer;
    connect(timerSec,SIGNAL(timeout()),this,SLOT(refTime()));
    timerSec->start(800);
    mySql.initThis("127.0.0.1","ggd","admin","admin");
}
void Global::outPutState()
{
    qRedis *redis=new qRedis(QString("127.0.0.1"),6379);
    if (!redis->openConnection())
    {
        return;
    }
    else
    {
        {
           QString msg=redis->get("alarmGate");
           int num=msg.toInt();
           for(int i=0;i<200;i++)
           {
               alarmGate[i]=num;
           }
        }
        {
           QString msg=redis->get("simGate");
           float num=msg.toFloat();
           for(int i=0;i<200;i++)
           {
               simGate[i]=num;
           }
        }
        {
           QString msg=redis->get("alarmDelay");
           int num=msg.toInt();
           for(int i=0;i<200;i++)
           {
               alarmDelay[i]=num;
           }

        }
        {
            QString msg=redis->get("simDelay");
            int num=msg.toInt();
            for(int i=0;i<200;i++)
            {
                simDelay[i]=num;
            }
        }
    }
    delete redis;


}
void Global::refTime()
{
    QDateTime date=QDateTime::currentDateTime();
    QTime timeNow=date.time();
    g->hourNow=timeNow.hour();
    g->minNow=(g->hourNow*60)+timeNow.minute();
    g->secondNow=(g->minNow*60)+timeNow.second();
    g->weekNow=date.date().dayOfWeek()-1;
}
int Global::getNowFreq(int transmitterNo)
{

    return ch[transmitterNo].day[weekNow].min[minNow].info.freq.toInt();
}
int Global::addAlarmInfo(int ch,AlarmType alarmType)
{
    alarmCountMutex.lock();
    AlarmInfo tmp;
    tmp.alarmNo=alarmCount;
    tmp.alarmCh=ch;
    tmp.alarmType=alarmType;
    tmp.startTime=QDateTime::currentDateTime();
    g->alarmInfoList.append(tmp);
    alarmCount++;
    bool ok=g->mySql.takeLog(/*日志内容*/"通道"+QString::number(ch)+alarmTypeString.at(alarmType),
                     /*表*/"alarm_log",
                     /*类型*/alarmTypeString.at(alarmType),
                     /*用户名*/"server"
                     );//日志模板
    qDebug()<<"alarm log"<<ok<<"通道"+QString::number(ch)+alarmTypeString.at(alarmType);
    alarmCountMutex.unlock();

    return tmp.alarmNo;
}

