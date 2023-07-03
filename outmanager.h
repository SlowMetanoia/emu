#ifndef OUTMANAGER_H
#define OUTMANAGER_H

#include <QObject>
#include "RandomTypes.h"
#include "journalwriter.h"
#include "socketwriter.h"
#include "valuescontroller.h"

class OutManager : public QObject
{
    Q_OBJECT
public:
    explicit OutManager(QObject *parent = nullptr);

    static OutManager* manager;
    static OutManager* getInstance();

    static void init(ScenarioType scenario);


    ScenarioType scenario;

    void writeSocket();
    void writeJournal();
    void writeModbus();

    void stopWriting();

    //modbus
    //socket
    JournalWriter* journalWriter;
    SocketWriter* socketWriter;
    //SocketWriter
    //ModbusWriter
public slots:
    void write();
signals:
};

#endif // OUTMANAGER_H
