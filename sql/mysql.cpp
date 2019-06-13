#include "mysql.h"
#include <QMessageBox>
#include "QDateTime"
MySQL::MySQL(QObject *parent) : QObject(parent)
{

}
void MySQL::initThis(QString HostName,QString DataBaseName,QString UserName,QString PassWord)
{
    SqlHostName=HostName;
    SqlDataBaseName=DataBaseName;
    SqlUserName=UserName;
    SqlPassWord=PassWord;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setConnectOptions("MYSQL_OPT_RECONNECT=1");
    db.setHostName(SqlHostName);
    db.setDatabaseName(SqlDataBaseName);       //这里输入你的数据库名
    db.setUserName(SqlUserName);
    db.setPassword(SqlPassWord);   //这里输入你的密码

    if (!db.open())
    {
        qDebug()<<"数据库打开失败！";
    }
    else
    {
        query=QSqlQuery(db);
        qDebug()<<"数据库打开成功！";
    }
}
bool MySQL::command(QString cmd)
{
    return query.exec(cmd);
    return false;



    if(query.exec(cmd))
    {
        return true;//一切正常
    }
    else //尝试重新连接
    {

        db.close();
        if(db.open())
        {

            if(query.exec(cmd))//重新尝试执行
            {
                qDebug()<<"重新连接后，执行成功。";
                return  true; //成功
            }
            else
            {
                qDebug()<<"重新连接后，执行失败。";
                return false; //失败
            }
        }
        else
        {
            qDebug()<<"重新连接失败。";
            return false;//打开失败
        }
    }
}
bool MySQL::takeLog(QString log,QString sheet,QString type,QString user)
{
    //return mySql.command("log values('"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"', '"+QString::number(type)+"', 'admin','"+str+"',NULL)");
    //时间 字符时间 类型 用户 日志 编号
    QMutexLocker locker(&mutex);
    QString cmd;
    cmd+="insert into ";
    cmd+=sheet;
    cmd+=" values('";
    cmd+=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"', '";
    cmd+=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"', '";
    cmd+=type+"', '";
    cmd+=user+"', '";
    cmd+=log+"', ";
    cmd+="NULL);";
    qDebug()<<cmd;
    return command(cmd);
}
