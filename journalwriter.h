#ifndef JOURNALWRITER_H
#define JOURNALWRITER_H

#include <QObject>
#include <QFile>
#include <QDateTime>
#include <QDebug>
struct JournalID{
    char headerString[strlen("gasanalyser_S601_journal")];
    int32_t version;
};

class JournalWriter : public QObject
{
    Q_OBJECT
public:
    explicit JournalWriter(QObject *parent = nullptr);
    static JournalWriter* journalWirter;
    static JournalWriter* getInstance();

    QFile outputFile;
    static QString generateNameFromTime();
    void openWriteFile(QString filename);
    void write(QByteArray data);
    void closeFile();
signals:
};

#endif // JOURNALWRITER_H
