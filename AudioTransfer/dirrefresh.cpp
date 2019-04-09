#include "dirrefresh.h"

DirRefresh::DirRefresh(QObject *parent) : QObject(parent)
{

}
void DirRefresh::initThis()
{
    QStringList nameList;
    qDebug()<<"asd";
    //================================================================
        {
            QString filename;
            filename+=(qApp->applicationDirPath()+"/sav/equ.sav");
            //判断文件是否存在
            QFile *file = new QFile(filename);
            if(file->open(QIODevice::ReadOnly))
            {
                for(int i=0;i<10;i++)
                {
                    {
                        QString ba(file->readLine());
                        ba=QString::fromStdString( ba.toStdString());
                        QStringList list=ba.split("|");

                        for(int j=0;j<18;j++)
                        {
                            nameList.append(list.at(j+1));
                        }
                    }


                    if(file->atEnd())break;
                }
                file->close();
            }
            file->deleteLater();
        }
    qDebug()<<"asd";
    int c=200-nameList.count();
    for(int i=0;i<(c);i++)
    {
        nameList.append(QString(""));
    }
    qDebug()<<"asd"<<nameList.count();
    for(int i=0;i<200;i++)
    {
        QString str;
        str="ch"+QString("%1").arg((i+1),3,10,QLatin1Char('0'));
        str+=nameList.at(i);
        g->chName[i]=str;
    }
    qDebug()<<"asd";
    QString tmp2;//存储位置

    QString filename;
    filename+=(qApp->applicationDirPath()+"/sav/savedir.sav");
    QFile *file = new QFile(filename);
    if(file->open(QIODevice::ReadOnly))
    {

        QString ba(file->readLine());
        tmp2=ba;

        file->close();
    }
    qDebug()<<"asd";
    file->deleteLater();

    if(tmp2==QString(""))
    {
        tmp2="D:/mp3";
    }
    for(int i=0;i<200;i++)
    {
        g->audioDirBase[i]=tmp2+"/"+g->chName[i];
    }
    qDebug()<<"dir ok";
    //======================================================
    addTaskTimer=new QTimer;
    connect(addTaskTimer,SIGNAL(timeout()),this,SLOT(addTask()));
    addTaskTimer->start(1000);
}
void DirRefresh::addTask()
{
    for(int i=0;i<200;i++)
    {
        if(g->stateCh[i]!=Normal)
        {
            //前1分钟
            addTaskTest(i,QDateTime::currentDateTime().addSecs(-60));
            //当前分钟
            addTaskTest(i,QDateTime::currentDateTime());
            //后1分钟
            addTaskTest(i,QDateTime::currentDateTime().addSecs(60));
        }
    }
}
bool DirRefresh::addTaskTest(int ch,QDateTime time)
{
    int i=0;
    for(i=0;i<g->transTaskList.count();i++)
    {
        if(g->transTaskList[i].ch==ch&&
                g->transTaskList[i].time==time)
        {
            return false;
        }
    }
    if(i==g->transTaskList.count())
    {
        TransTask newTask;
        newTask.ch=ch;
        time.setTime(QTime(time.time().hour(),time.time().minute()));
        newTask.time=time;
        newTask.sourceDir=g->audioDirBase[ch]+"/"+time.toString("yyyy-MM-dd/hh时/");
                //+"/"+g->chName[ch]+time.toString("-yyyy年MM月dd日hh时mm分");
        newTask.targetDir=g->audioDirBase[ch]+"_alarm/"+time.toString("yyyy-MM-dd/hh时/");
                //+"/"+g->chName[ch]+time.toString("-yyyy年MM月dd日hh时mm分");
        newTask.fileName=g->chName[ch]+time.toString("-yyyy年MM月dd日hh时mm分")+".mp3";
        g->transTaskList.append(newTask);
        return true;
    }
    return false;
}
