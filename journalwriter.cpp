#include "journalwriter.h"

JournalWriter* JournalWriter::journalWirter = nullptr;
JournalWriter* JournalWriter::getInstance(){
    if(JournalWriter::journalWirter==nullptr){
        JournalWriter::journalWirter = new JournalWriter();
    }
    return JournalWriter::journalWirter;
}

JournalWriter::JournalWriter(QObject *parent) : QObject(parent)
{

}

void JournalWriter::openWriteFile(QString filename){
    if(outputFile.isOpen()){
        outputFile.close();
    }
    outputFile.setFileName(filename);
    JournalID journalID;
    strcpy(journalID.headerString,"gasanalyser_S601_journal");
    journalID.version = 0;
    outputFile.open(QIODevice::WriteOnly);
    outputFile.write((char*)&journalID,sizeof(journalID));
}

void JournalWriter::write(QByteArray data){
    outputFile.write(data);
    //убрать это убожество
    outputFile.close();
    outputFile.open(QIODevice::WriteOnly|QIODevice::Append);
}

void JournalWriter::closeFile(){
    outputFile.close();
}

QString JournalWriter::generateNameFromTime(){
    timespec ts;
    clock_gettime(CLOCK_REALTIME,&ts);
    QString result =
            (QDateTime::fromSecsSinceEpoch(ts.tv_sec).toString() + ".gdat")
            .simplified()
            .replace(" ","_");
    qDebug()<<"writing to journal:"<<result;
    return result;
}
