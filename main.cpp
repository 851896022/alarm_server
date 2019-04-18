#include "window.h"
#include <QApplication>
#include "global.h"
#include "reaudiodata.h"
#include <QThread>
#include <QObject>
#include "alarm/yxt/qredismanager.h"
#include <iostream>
#include <QDir>
#include <QDateTime>
#include "alarm/alarmapm.h"
#include "alarm/senddata.h"
#include "alarm/alarmsimilar.h"
#include "AudioTransfer/dirrefresh.h"
#include "AudioTransfer/transferfile.h"
#include <QProcess>
Global *g;
void setDebugOutput(const QString &targetFilePath, const bool &argDateFlag = false);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString log_dir;
    log_dir=qApp->applicationDirPath()+"/log3/%1.log";
    setDebugOutput( log_dir, true );

    JQCPUMonitor::initialize();
    g=new Global;
    qDebug()<<"init audio receiver";
    QThread reDataThread[20];
    ReAudioData rd[200];
    for(int i=0;i<200;i++)
    {
        rd[i].moveToThread(&reDataThread[i%20]);

        rd[i].No=i;
        QObject::connect(&reDataThread[i%20],SIGNAL(started()),&rd[i],SLOT(initThis()));

    }
    for(int i=0;i<20;i++)
    {
        reDataThread[i].start();
    }
    //===========================
    qDebug()<<"init redis manager";
    qRedisManager redisManager;
    qDebug()<<"init alarm apm";
    AlarmApm *alarmApm[200];
    for(int i=0;i<200;i++)
    {
        alarmApm[i]=new AlarmApm;
        alarmApm[i]->No=i;
        alarmApm[i]->transmitterNo=g->transmitterNoList[i];
        alarmApm[i]->initThis();
    }
    qDebug()<<"init alarm sim";
    ALarmSimilar *alarmSimilar[200];
    QThread *alarmSimilarThread[20];
    //alarmSimilarThread[]=new QThread;
    for(int i=0;i<20;i++)
    {
        alarmSimilarThread[i]=new QThread;
    }
    for(int i=0;i<200;i++)
    {
        if(g->standardList[i]>=0)
        {
            alarmSimilar[i]=new ALarmSimilar;

            alarmSimilar[i]->No=i;
            alarmSimilar[i]->standard=g->standardList[i];
            alarmSimilar[i]->transmitterNo=g->transmitterNoList[i];
            alarmSimilar[i]->moveToThread(alarmSimilarThread[i%20]);
            QObject::connect(alarmSimilarThread[i%20],SIGNAL(started()),alarmSimilar[i],SLOT(initThis()));
        }
    }
    for(int i=0;i<200;i++)
    {
        if(g->standardList[i]>=0)
        {
            alarmSimilarThread[i]->start();
        }
    }


    qDebug()<<"init send data";
    SendData *sendData=new SendData;
    sendData->initThis();

    qDebug()<<"init dirRefresh";
    DirRefresh  *dirRefresh=new DirRefresh;
    dirRefresh->initThis();
    qDebug()<<"init transferFile";
    TransferFile * transferFile= new TransferFile;
    transferFile->initThis();
    qDebug()<<"connect signal and slot";
    for(int i=0;i<200;i++)
    {
        QObject::connect(alarmApm[i],SIGNAL(alert(int)),sendData,SLOT(onAlert(int)));
        QObject::connect(alarmApm[i],SIGNAL(alert(int,int,QDateTime)),sendData,SLOT(onAlert(int,int,QDateTime)));
        if(g->standardList[i]>=0)
        {
            QObject::connect(alarmSimilar[i],SIGNAL(alert(int)),sendData,SLOT(onAlert(int)));
            QObject::connect(alarmSimilar[i],SIGNAL(alert(int,int,QDateTime)),sendData,SLOT(onAlert(int,int,QDateTime)));
            QObject::connect(alarmSimilar[i],SIGNAL(simInfo(int,float)),sendData,SLOT(simData(int,float)));
        }
    }
    //Window w;
    //w.setGeometry(0,0,0,0);
    //w.show();
    int e = a.exec();

    if(e == 776)

    {

       QProcess::startDetached(qApp->applicationFilePath(), QStringList());

       qDebug()<<"重启";
       return 0;

    }

    return e;
    //return a.exec();
}
//日志生成
void setDebugOutput(const QString &rawTargetFilePath_, const bool &argDateFlag_)
{
    static QString rawTargetFilePath;
    static bool argDateFlag;

    rawTargetFilePath = rawTargetFilePath_;
    argDateFlag = argDateFlag_;

    class HelperClass
    {
    public:
        static void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &message_)
        {
            QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);

            QString message;

            switch ( type )
            {
                case QtDebugMsg:
                {
                    message = message_;
                    break;
                }
                case QtWarningMsg:
                {
                    message.append("Warning: ");
                    message.append(message_);
                    break;
                }
                case QtCriticalMsg:
                {
                    message.append("Critical: ");
                    message.append(message_);
                    break;
                }
                case QtFatalMsg:
                {
                    message.append("Fatal: ");
                    message.append(message_);
                    break;
                }
                default: { break; }
            }

            QString currentTargetFilePath;

            if ( argDateFlag )
            {
                currentTargetFilePath = rawTargetFilePath.arg( ( ( argDateFlag ) ? ( QDateTime::currentDateTime().toString("yyyy_MM_dd") ) : ( "" ) ) );
            }
            else
            {
                currentTargetFilePath = rawTargetFilePath;
            }

            if ( !QFileInfo::exists( currentTargetFilePath ) )
            {
                QDir().mkpath( QFileInfo( currentTargetFilePath ).path() );
            }

            QFile file( currentTargetFilePath );
            file.open( QIODevice::WriteOnly | QIODevice::Append );

            QTextStream textStream( &file );

            textStream << QDateTime::currentDateTime().toString( "yyyy-MM-dd hh:mm:ss" ) << ": "  <<context_info<<"->"<< message << "\r\n";
            QTextStream textStreamStd( stdout );
            textStreamStd << QDateTime::currentDateTime().toString( "yyyy-MM-dd hh:mm:ss" ) << ": " <<context_info<<"->"<< message << "\r\n";
        }
    };

    qInstallMessageHandler( HelperClass::messageHandler );
}
