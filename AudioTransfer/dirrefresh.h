#ifndef DIRREFRESH_H
#define DIRREFRESH_H

#include <QObject>
#include <global.h>
class DirRefresh : public QObject
{
    Q_OBJECT
public:
    explicit DirRefresh(QObject *parent = nullptr);
    QTimer *addTaskTimer;
signals:

public slots:
    void initThis();
    void addTask();
    bool addTaskTest(int ch,QDateTime time);
};

#endif // DIRREFRESH_H
