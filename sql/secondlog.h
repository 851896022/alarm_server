#ifndef SECONDLOG_H
#define SECONDLOG_H

#include <QObject>
#include <QTimer>
class SecondLog : public QObject
{
    Q_OBJECT
public:
    explicit SecondLog(QObject *parent = nullptr);
    QTimer *logTimer;
signals:

public slots:
    void initThis();
    void logSecondData();
};
#include "global.h"
#endif // SECONDLOG_H
