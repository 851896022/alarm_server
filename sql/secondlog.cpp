#include "secondlog.h"

SecondLog::SecondLog(QObject *parent) : QObject(parent)
{
    initThis();
}
void SecondLog::initThis()
{
    logTimer=new QTimer;
    connect(logTimer,SIGNAL(timeout()),this,SLOT(logSecondData()));
    logTimer->start(1000);
}
void SecondLog::logSecondData()
{
    if(g->logFlag==true)
    {
        g->logFlag=false;
        QString cmd;
        cmd+="insert into ";
        cmd+="second_log";
        cmd+=" values('";
        cmd+=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"', '";
        cmd+=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"', ";
        for(int i=0;i<200;i++)
        {
            cmd+=QString::number(g->maxValue[i])+", ";
            cmd+=QString::number(g->similar[i])+", ";
        }

        cmd+="NULL);";
        g->mySql.command(cmd);
    }


}
