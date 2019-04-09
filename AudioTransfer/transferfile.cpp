#include "transferfile.h"

TransferFile::TransferFile(QObject *parent) : QObject(parent)
{

}
void TransferFile::initThis()
{
    doTaskTimer=new QTimer;
    connect(doTaskTimer,SIGNAL(timeout()),this,SLOT(doTask()));
    doTaskTimer->start(2000);
}
void TransferFile::doTask()
{
    QDateTime nowTime=QDateTime::currentDateTime().addSecs(-60);
    if(nowTime.time().second()>5)
    {
        return;
    }
    for(int i=0;i<g->transTaskList.count();i++)
    {
        if(g->transTaskList[i].time<nowTime)
        {
            newlyDir(g->transTaskList[i].targetDir);
            bool as=QFile::copy(g->transTaskList[i].sourceDir+g->transTaskList[i].fileName,
                        g->transTaskList[i].targetDir+g->transTaskList[i].fileName);
            if(as)
            {
                qDebug()<< g->transTaskList[i].fileName<<"copy sucess";
            }
            else
            {
                qDebug()<< g->transTaskList[i].fileName<<"copy error";
            }
            g->transTaskList.removeAt(i);
            i--;
        }
    }
}
bool TransferFile::newlyDir(QString fullPath)
{
    //QStringList dirList=dir.split("/");
    QDir dir(fullPath);
    if(dir.exists())
    {
      return true;
    }
    else
    {
       bool ok = dir.mkpath(fullPath);//创建多级目录
       return ok;
    }
}
