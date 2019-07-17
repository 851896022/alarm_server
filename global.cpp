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
                    if(msglist.count()>=4)
                    {
                        int ch=msglist[0].toInt();
                        transmitterNoList[ch]=msglist[1].toInt();
                        standardList[ch]=msglist[2].toInt();
                        //目标通道音频滞后，数字为正数。
                        simAudioDelay[ch]=msglist[3].toInt();
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
    timer->start(500);
    QTimer *timerSec=new QTimer;
    connect(timerSec,SIGNAL(timeout()),this,SLOT(refTime()));
    timerSec->start(800);
    mySql.initThis("127.0.0.1","ggd","admin","admin");

    //看门口
    connect(&watchDogTimer,SIGNAL(timeout()),this,SLOT(watchDogTimerSlot()));
    watchDogTimer.start(1000);
    //计算间隔
    connect(&countSimPeriodTimer,SIGNAL(timeout()),this,SLOT(countSimPeriod()));
    countSimPeriodTimer.start(1000);

}
//读取门限数据
void Global::outPutState()
{
    //qDebug()<<"start"<<"outPutState()";
    qRedis *redis=new qRedis(QString("127.0.0.1"),6379);
    if (!redis->openConnection())
    {
        return;
    }
    else
    {
        {
           QString msg=redis->get("alarmGate");
           QStringList msgList=msg.split("|");
           if(msgList.count()>=200)
           {
               for(int i=0;i<200;i++)
               {
                   alarmGate[i]=(msgList.at(i).toInt());
               }
           }
           else
           {
                for(int i=0;i<200;i++)
                {
                    alarmGate[i]=(-1);
                }
           }


        }
        {
           QString msg=redis->get("simGate");
           QStringList msgList=msg.split("|");
           if(msgList.count()>=200)
           {
               for(int i=0;i<200;i++)
               {
                   simGate[i]=(msgList.at(i).toFloat());
               }
           }
           else
           {
                for(int i=0;i<200;i++)
                {
                    simGate[i]=(-1);
                }
           }
        }
        {
           QString msg=redis->get("alarmDelay");
           QStringList msgList=msg.split("|");
           if(msgList.count()>=200)
           {
               for(int i=0;i<200;i++)
               {
                   alarmDelay[i]=(msgList.at(i).toInt());
               }
           }
           else
           {
                for(int i=0;i<200;i++)
                {
                    alarmDelay[i]=(999999);
                }
           }

        }
        {
            QString msg=redis->get("simDelay");
            QStringList msgList=msg.split("|");
            if(msgList.count()>=200)
            {
                for(int i=0;i<200;i++)
                {
                    simDelay[i]=(msgList.at(i).toInt());
                }
            }
            else
            {
                 for(int i=0;i<200;i++)
                 {
                     simDelay[i]=(999999);
                 }
            }
        }
    }
    delete redis;
    //qDebug()<<"send"<<"outPutState()";
//    QString ag,ad,sg,sd;
//    for(int i=0;i<200;i++)
//    {
//        ag.append(QString::number(alarmGate[i])+"|");
//        ad.append(QString::number(alarmDelay[i])+"|");
//        sg.append(QString::number(simGate[i])+"|");
//        sd.append(QString::number(simDelay[i])+"|");
//    }
//    qDebug()<<"ag"<<ag;
//    qDebug()<<"ad"<<ad;
//    qDebug()<<"sg"<<sg;
//    qDebug()<<"sd"<<sd;


}
void Global::refTime()
{
    //qDebug()<<"start"<<"refTime()";
    QDateTime date=QDateTime::currentDateTime();
    QTime timeNow=date.time();
    g->hourNow=timeNow.hour();
    g->minNow=(g->hourNow*60)+timeNow.minute();
    g->secondNow=(g->minNow*60)+timeNow.second();
    g->weekNow=date.date().dayOfWeek()-1;
    //qDebug()<<"end"<<"refTime()";
}
int Global::getNowFreq(int transmitterNo)
{

    return ch[transmitterNo].day[weekNow].min[minNow].info.freq.toInt();
}
int Global::addAlarmInfo(int ch,AlarmType alarmType)
{
    //qDebug()<<"start"<<"addAlarmInfo(int ch,AlarmType alarmType)";
    alarmCountMutex.lock();
    AlarmInfo tmp;
    tmp.alarmNo=alarmCount;
    tmp.alarmCh=ch;
    tmp.alarmType=alarmType;
    tmp.startTime=QDateTime::currentDateTime();
    g->alarmInfoList.append(tmp);
    alarmCount++;

    //qDebug()<<"alarm log"<<ok<<"通道"+QString::number(ch)+alarmTypeString.at(alarmType);
    alarmCountMutex.unlock();
    //qDebug()<<"end"<<"addAlarmInfo(int ch,AlarmType alarmType)";
    return tmp.alarmNo;
}
void Global::logInfo(int ch,AlarmType alarmType)
{
    //qDebug()<<"start"<<"logInfo(int ch,AlarmType alarmType)";
    mySql.takeLog(/*日志内容*/chName[ch]+alarmTypeString.at(alarmType),
                     /*表*/"alarm_log",
                     /*类型*/alarmTypeString.at(alarmType),
                     /*用户名*/"server"
                     );//日志模板

    //qDebug()<<"end"<<"logInfo(int ch,AlarmType alarmType)";
}
void Global::watchDogTimerSlot()
{
    //qDebug()<<"start"<<"watchDogTimerSlot()";
    for(int i=0;i<200;i++)
    {
       if(g->standardList[i]>=0)
       {
           g->watchDogCount[i]++;


           if(g->watchDogCount[i]>10)
           {
               reBoot();
           }
       }
    }
    //qDebug()<<"end"<<"watchDogTimerSlot()";
}
void Global::reBoot()
{
    //qDebug()<<"start"<<"reBoot()";
    qApp->exit(776);
    //qDebug()<<"end"<<"reboot";
}
void Global::countSimPeriod()
{
    //qDebug()<<"start"<<"countSimPeriod()";
    double s0=0,s1=0,s2=0;

    double temp=0;

    s0 = JQCPUMonitor::cpuUsagePercentage() - cpu;
    temp = kp * ( s0 - s1 ) + ki * s0 + kd * (s0 + s2 - 2 * s1);
    s2 = s1;
    s1 = s0;

    temp = simPeriod + temp;

    if(temp<1) temp=1;
    if(temp>5000) temp=5000;
    simPeriod=temp;
    //qDebug()<<"end"<<"countSimPeriod()";
    //qDebug()<<JQCPUMonitor::cpuUsagePercentage()<<temp;
}

