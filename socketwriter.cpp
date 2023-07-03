#include "socketwriter.h"
SocketWriter* SocketWriter::writer = nullptr;

SocketWriter* SocketWriter::getInstance(){
    if(SocketWriter::writer == nullptr)
        SocketWriter::writer = new SocketWriter();
    return SocketWriter::writer;
}


SocketWriter::SocketWriter(QObject *parent) : QObject(parent)
{

}
void SocketWriter::init(QString addr, int port){
    SocketWriter* sw = SocketWriter::getInstance();
    sw->addr.setAddress(addr);
    sw->port = port;
}

void SocketWriter::write(QByteArray data){
    QUdpSocket* socket;
    socket = new QUdpSocket();
    //qDebug()<<"writing2socket";
    //socket->bind(addr, 30000);
    socket->writeDatagram(data,addr,30000);
    socket->close();
    socket->deleteLater();
}
