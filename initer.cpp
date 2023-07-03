#include "initer.h"
#include <iostream>
Initer::Initer(QObject *parent) : QObject(parent)
{

}

void Initer::GeneralInit(){
    Configurator* configurator = Configurator::getIntance();
    qDebug()<<"configurator loaded";
    ImitatorConfig* config = configurator->readConfig("config.json");
    qDebug()<<"config:";
    std::cout<<config->toString().toStdString();
    PulseGenerator::getInstance()->setPulseWaitMs(config->pulseWaitMs);
    PulseGenerator::getInstance()->init();
    PulseController::getInstance()->start();
    qDebug()<<"pulse inited";
    ValuesController::init(config);
    qDebug()<<"generators inited";
    JournalWriter::getInstance()->openWriteFile(JournalWriter::generateNameFromTime());
    SocketWriter::init("127.0.01",30000);
    qDebug()<<"socket is up";
    OutManager::getInstance()->init(config->scenario);
    qDebug()<<"output manager is up";
    CLIManager::getInstance();
}
