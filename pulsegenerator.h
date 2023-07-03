#ifndef PULSEGENERATOR_H
#define PULSEGENERATOR_H

#define DEFAULT_DELAY 1000

#include <QObject>
#include <QThread>
//#include <QDebug>

class PulseGenerator : public QObject
{
    Q_OBJECT
public:
    explicit PulseGenerator(QObject *parent = nullptr);

    static PulseGenerator* pulseGenerator;
    static PulseGenerator* getInstance();

    PulseGenerator(int pulseWaitMs);

    int pulseWaitMs;
    QThread* pulseThread;
    void emitPulse();
    void init();
    int getPulseWaitMs() const;
    void setPulseWaitMs(int value);
public slots:
signals:
    void pulse();
};

#endif // PULSEGENERATOR_H
