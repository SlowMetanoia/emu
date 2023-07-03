#ifndef SOCKETWRITER_H
#define SOCKETWRITER_H

#include <QObject>
#include <QUdpSocket>

class SocketWriter : public QObject
{
    Q_OBJECT
public:
    static SocketWriter* writer;
    static SocketWriter* getInstance();

    static void init(QString addr, int port);

    QHostAddress addr;
    int port;
    //QUdpSocket* socket;

    void write(QByteArray data);
    explicit SocketWriter(QObject *parent = nullptr);

signals:

};

#endif // SOCKETWRITER_H
