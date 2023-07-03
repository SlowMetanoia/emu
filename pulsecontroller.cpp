#include "pulsecontroller.h"

PulseController* PulseController::pulseController = nullptr;
PulseController::PulseController(QObject *parent) : QObject(parent)
{
    connect(PulseGenerator::getInstance(),&PulseGenerator::pulse,this,&PulseController::gotNewPulse);
    zero.tv_sec = 0;
    zero.tv_nsec = 0;
}

double PulseController::calcTime(){
    timespec now;
    clock_gettime(CLOCK_REALTIME,&now);
    double s = now.tv_sec - zero.tv_sec;
    double ns = now.tv_nsec - zero.tv_nsec;
    return s + ns/1000000000;
}

void PulseController::gotNewPulse(){
    if(isUp){
        //qDebug()<<"t = "<<calcTime();
        emit valuePulse(calcTime());
    }
}

PulseController* PulseController::getInstance(){
    if(PulseController::pulseController==nullptr)
        PulseController::pulseController = new PulseController();
    return PulseController::pulseController;
}
void PulseController::start(){
    qDebug()<<"started";
    if(zero.tv_sec==0)
        clock_gettime(CLOCK_REALTIME,&zero);
    isUp = true;
    //qDebug()<<zero.tv_sec;
}
void PulseController::stop(){
    qDebug()<<"stoped";
    zero.tv_sec = 0;
    isUp = false;
}
void PulseController::reset(){
    qDebug()<<"reseted";
    clock_gettime(CLOCK_REALTIME,&zero);
    isUp = true;
}
void PulseController::pause(){
    qDebug()<<"paused";
    isUp = false;
}
