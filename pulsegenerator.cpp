#include "pulsegenerator.h"

PulseGenerator::PulseGenerator(QObject *parent) : QObject(parent)
{
    //connect(this,&PulseGenerator::pulse,this,&PulseGenerator::recTimePulse);
    //QThread::sleep(1);
    //emit pulse();
}


PulseGenerator* PulseGenerator::pulseGenerator = nullptr;

PulseGenerator::PulseGenerator(int pulseSleepMs){
    this->pulseWaitMs = pulseSleepMs;
    auto f = [=](){
        while(true){
            emitPulse();
            //emit pulse();

            QThread::msleep(this->pulseWaitMs);
        }
    };
    QThread* thr = new QThread();
    this->pulseThread = thr->create(f);
}

int PulseGenerator::getPulseWaitMs() const
{
    return pulseWaitMs;
}

void PulseGenerator::setPulseWaitMs(int value)
{
    pulseWaitMs = value;
}

void PulseGenerator::init(){
    this->pulseThread->start(QThread::HighestPriority);
    //qDebug()<<"cycle inited";
}

void PulseGenerator::emitPulse(){
    emit pulse();
    //QThread::sleep(1);
    //qDebug()<<"pulse";
}

PulseGenerator* PulseGenerator::getInstance(){
    if(PulseGenerator::pulseGenerator == nullptr){
        pulseGenerator = new PulseGenerator(DEFAULT_DELAY);
    }
    return PulseGenerator::pulseGenerator;
}



