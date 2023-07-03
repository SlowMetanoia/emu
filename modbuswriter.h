#ifndef MODBUSWRITER_H
#define MODBUSWRITER_H

#include <QObject>
#include </usr/local/include/modbus/modbus.h>
#include <QThread>

class ModbusWriter : public QObject
{
    Q_OBJECT
public:
    explicit ModbusWriter(QObject *parent = nullptr);
    modbus_t* ctx;
    modbus_mapping_t* mbMapping;
    QThread* modbusReply;
    void write();
signals:
};

#endif // MODBUSWRITER_H
