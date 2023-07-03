#ifndef BINMESSAGE_H
#define BINMESSAGE_H

#include <QObject>
#include <QDataStream>

class BinMessage
{
public:    
    QByteArray data;
    void addValue(const char* value, uint len);
};

#endif // BINMESSAGE_H
