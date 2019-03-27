#ifndef GLOBAL_H
#define GLOBAL_H
#include <QApplication>
#include <QObject>
#include <windows.h>
#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QList>
#include <QDateTime>
#include <QMutex>
#include <JQCPUMonitor>
#include "alarm/yxt/qRedis.h"
struct yxtbase
{
    int startTimeInt=0;
    int endTimeInt=0;
    int afterGapMinute=0;
    QString antUsedCode="";
    QString azimuthM="";
    int beforeGapMinute=0;
    QString days="";
    QString endTime="";
    QString freq="";
    QString power="";
    QString progChannel="";
    QString progCode="";
    QString progName="";
    QString rmks="";
    int runid=0;
    QString startTime="";
    QString syncTime="";
    QString taskType="";
    QString transUsedCode="";



};
struct mindata
{
    bool transmit;
    int timeFormStart=0;
    int timeToEnd=0;
    yxtbase info;


};

struct yxtOfDay
{
    mindata min[1440]; //给程序看的
    yxtbase timeQuantum[50];//给人看的
};
struct yxtOfWeek
{
    yxtOfDay day[7];
    QString name="";
};
enum AlarmType
{
    Normal,
    Similar,
    Range,
    All,
    SimilarCancel,
    RangeCancel,
    Other,

};
struct AlarmInfo
{
    int alarmNo=0;
    int alarmCh=0;
    AlarmType alarmType=Other;
    QDateTime startTime;
    QDateTime endTime;
};
class Global : public QObject
{
    Q_OBJECT
public:
    explicit Global(QObject *parent = nullptr);

    //音频缓存
    QByteArray audioCache[200];
    int cacheSize=131072;
    //相似度
    double similarity[200]={0};
    //峰值
    int maxValue[200]={0};
    //运行图相关
    QString redisIp="127.0.0.1";
    int redisPort=6379;
    QStringList transmitterName;//发射机名称列表
    yxtOfWeek ch[30];//支持至多30个通道运行图
    const yxtbase yxtEmpty;
    
    //通道的发射机号
    int transmitterNoList[200]={0};
    //通道的参考通道号
    int standardList[200];
    
    //报警信息列表
    QList<AlarmInfo> alarmInfoList;
    //通道状态
    AlarmType stateCh[200];
    //幅度报警延时 秒
    int alarmDelay[200]={0};
    //幅度报警计数
    int alarmCount=0;
    //幅度报警线程 锁
    QMutex alarmCountMutex;
    //幅度报警门限 0~32768
    int alarmGate[200]={0};
    //当前时间 从0点开始经过了多少时分秒
    int minNow;
    int weekNow;//(0 = Monday to 6 = Sunday)
    int hourNow;
    int secondNow;
    //计时更新时间
    QTimer *timerCountTime;
    //服务器地址
    QString serverIp="127.0.0.1";
    int serverPort=2500;


    //====================
    //相似度门限
    float simGate[200];
    //相似度
    float similar[200];
    //相似度延时
    int simDelay[200]={0};

signals:

public slots:
    void outPutState();
    void refTime();
    int getNowFreq(int transmitterNo);
    int addAlarmInfo(int ch,AlarmType alarmType);
};
extern Global *g;
#endif // GLOBAL_H
