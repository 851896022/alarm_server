#include "alarmsimilar.h"

ALarmSimilar::ALarmSimilar(QObject *parent) : QObject(parent)
{

}
void ALarmSimilar::initThis()
{
    workDelay=new QTimer;
    connect(workDelay,SIGNAL(timeout()),this,SLOT(doWork()));
    workDelay->setSingleShot(true);
    if(standard>=0)
    {
        workDelay->start(delayTime);
    }

    alarmDelay=new QTimer;
    connect(alarmDelay,SIGNAL(timeout()),this,SLOT(doAlert()));
    simThread=new SimilarThread;

}
void ALarmSimilar::doWork()
{
    workDelay->stop();

    simThread->No=No;
    simThread->standard=standard;
    simThread->run();
#ifdef asdaf
    simThread->start();
    while (simThread->isRunning())
    {
        QEventLoop loop;
        QTimer timer;
        connect(&timer,SIGNAL(timeout()),&loop,SLOT(quit()));
        timer.start(5);
        loop.exec();
    }
#endif
    float xiangdiu=simThread->simResult;
    g->watchDogCount[No]=0;
    g->similar[No]=xiangdiu;
    //qDebug()<<No<<simThread->isRunning()<<QThread::currentThreadId();

    //delete simThread;
    //发送信息
    emit simInfo(No,xiangdiu);
    //判断状态
    qDebug()<<No<<"xiangsidu="<<xiangdiu<<"simGate="<<g->simGate[No];
    if(xiangdiu>g->simGate[No]||g->getNowFreq(transmitterNo)<=0)
    {
        //移除列表
        for(int i=0;i<g->alarmInfoList.count();i++)
        {
            if(g->alarmInfoList.at(i).alarmNo==No && g->alarmInfoList.at(i).alarmType==Similar)
            {
                g->alarmInfoList.removeAt(i);
            }
        }
        //修改状态
        if(g->stateCh[No]==Similar)
        {
            g->stateCh[No]=Normal;
            emit alert(No,SimilarCancel,QDateTime::currentDateTime());
            g->logInfo(No,SimilarCancel);
        }
        else if(g->stateCh[No]==All)
        {
            g->stateCh[No]=Range;
            emit alert(No,SimilarCancel,QDateTime::currentDateTime());
            g->logInfo(No,SimilarCancel);

        }
        if(alarmDelay->isActive())
        {
            alarmDelay->stop();
        }
    }
    else
    {
        //qDebug()<<No<<"sim lost of gate";
        if(!alarmDelay->isActive())
        {
            //qDebug()<<No<<"start delay time="<<g->simDelay[No]*1000<<"ms";
            alarmDelay->start(g->simDelay[No]*1000);
        }

    }
    //计算延时









    workDelay->start(delayTime);

 }
void ALarmSimilar::doAlert()
{
    //qDebug()<<No<<"sim do alert start fre=";
    alarmDelay->stop();
    if(g->getNowFreq(transmitterNo)>0)
    {
        //添加信息
        int tmp;
        //修改状态
        if(g->stateCh[No]==Range)
        {
            g->stateCh[No]=All;
            tmp=g->addAlarmInfo(No,Similar);
            emit alert(tmp);
            g->logInfo(No,Similar);
            qDebug()<<No<<"sim do alert all";

        }
        else if(g->stateCh[No]==Normal)
        {
            g->stateCh[No]=Similar;
            tmp=g->addAlarmInfo(No,Similar);
            emit alert(tmp);
            g->logInfo(No,Similar);
            qDebug()<<No<<"sim do alert similar";
        }


    }
}
