#include "alarmapm.h"

AlarmApm::AlarmApm(QObject *parent) : QObject(parent)
{

}
void AlarmApm::initThis()
{
    timerTest=new QTimer;
    connect(timerTest,SIGNAL(timeout()),this,SLOT(doTest()));
    timerTest->start(25);

    timerAlertDelay=new QTimer;
    connect(timerAlertDelay,SIGNAL(timeout()),this,SLOT(doAlert()));



}
void AlarmApm::doTest()
{
    if(g->maxValue[No]>=g->alarmGate[No])
    {
        alarmCount++;
        if(g->getNowFreq(transmitterNo)>0)
        {
            g->logFlag=true;
        }

    }
    else
    {
        alarmCount=0;
    }



    if(alarmCount>10||g->getNowFreq(transmitterNo)<=0)
    {
        timerAlertDelay->stop();
        //移除列表
        g->alarmCountMutex.lock();
        for(int i=0;i<g->alarmInfoList.count();i++)
        {
            if(g->alarmInfoList.at(i).alarmNo==No && g->alarmInfoList.at(i).alarmType==Range)
            {
                g->alarmInfoList.removeAt(i);
            }
        }
        g->alarmCountMutex.unlock();
        //修改状态
        if(g->stateCh[No]==Range)
        {
            g->stateCh[No]=Normal;
            emit alert(No,RangeCancel,QDateTime::currentDateTime());
            g->logInfo(No,RangeCancel);
        }
        else if(g->stateCh[No]==All)
        {
            g->stateCh[No]=Similar;
            emit alert(No,RangeCancel,QDateTime::currentDateTime());
            g->logInfo(No,RangeCancel);
        }
    }
    else
    {

        if(!timerAlertDelay->isActive())
        {
            timerAlertDelay->start(g->alarmDelay[No]*1000);

        }

    }
}
void AlarmApm::doAlert()
{
    qDebug()<<" ch:"<<No<<" transmitterNo:"<<transmitterNo<<" fre:"<<g->getNowFreq(transmitterNo);
    if(g->getNowFreq(transmitterNo)>0)
    {
        //添加信息
        int tmp;
        //修改状态
        if(g->stateCh[No]==Similar)
        {
            g->stateCh[No]=All;
            tmp=g->addAlarmInfo(No,Range);
            emit alert(tmp);
            g->logInfo(No,Range);

        }
        else if(g->stateCh[No]==Normal)
        {
            g->stateCh[No]=Range;
            tmp=g->addAlarmInfo(No,Range);
            emit alert(tmp);
            g->logInfo(No,Range);
        }


    }

}
