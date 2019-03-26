#ifndef ALARMAPM_H
#define ALARMAPM_H

#include <QObject>
#include "global.h"
class AlarmApm : public QObject
{
    Q_OBJECT
public:
    explicit AlarmApm(QObject *parent = nullptr);
    int No=0;
    int transmitterNo=0;
    QTimer *timerTest;
    QTimer *timerAlertDelay;
    int  alarmCount=0;
signals:
    void alert(int);
    void alert(int,int,QDateTime);
public slots:
    void initThis();
private slots:
    void doTest();
    void doAlert();
};

#endif // ALARMAPM_H
