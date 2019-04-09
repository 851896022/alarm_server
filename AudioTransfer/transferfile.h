#ifndef TRANSFERFILE_H
#define TRANSFERFILE_H

#include <QObject>
#include <global.h>
class TransferFile : public QObject
{
    Q_OBJECT
public:
    explicit TransferFile(QObject *parent = nullptr);
    QTimer *doTaskTimer;
signals:

public slots:
    void initThis();
    void doTask();
    bool newlyDir(QString dir);

};

#endif // TRANSFERFILE_H
