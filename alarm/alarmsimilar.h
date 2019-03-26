#ifndef ALARMSIMILAR_H
#define ALARMSIMILAR_H

#include <QObject>
#include <QThread>
#include "global.h"
#include "similarthread.h"
class ALarmSimilar : public QObject
{
    Q_OBJECT
public:
    explicit ALarmSimilar(QObject *parent = nullptr);
    int No=0;
    int standard=-1;
    int transmitterNo=0;
    QTimer *workDelay;
    QTimer *alarmDelay;
    int delayTime=100;
    SimilarThread *simThread;
signals:
    void alert(int);
    void alert(int,int,QDateTime);
    void simInfo(int ,float);
public slots:
    void initThis();
    void doWork();
    void doAlert();
};

#endif // ALARMSIMILAR_H
