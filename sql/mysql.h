#ifndef MYSQL_H
#define MYSQL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
class MySQL : public QObject
{
    Q_OBJECT
public:
    explicit MySQL(QObject *parent = nullptr);
    QString SqlHostName;
    QString SqlDataBaseName;
    QString SqlUserName;
    QString SqlPassWord;
    QSqlDatabase db;
    QSqlQuery query;
signals:

public slots:
    void initThis(QString HostName,QString DataBaseName,QString UserName,QString PassWord);
    bool command(QString);
    bool takeLog(QString log="NULL",QString sheet="log",QString type="NULL",QString user="admin");
};

#endif // MYSQL_H
