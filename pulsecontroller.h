#ifndef PULSECONTROLLER_H
#define PULSECONTROLLER_H

#include <QObject>
#include "pulsegenerator.h"
#include <QDebug>

class PulseController : public QObject
{
    Q_OBJECT
public:
    explicit PulseController(QObject *parent = nullptr);
    static PulseController* pulseController;
    static PulseController* getInstance();
    double calcTime();
    timespec zero;
    void start();
    void stop();
    void pause();
    void reset();
    bool isUp = true;
public slots:
    void gotNewPulse();
signals:
    void valuePulse(double);
};

#endif // PULSECONTROLLER_H
