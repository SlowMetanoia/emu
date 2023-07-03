#include "outmanager.h"


OutManager* OutManager::manager = nullptr;
OutManager* OutManager::getInstance(){
    if(OutManager::manager == nullptr)
        OutManager::manager = new OutManager();
}

OutManager::OutManager(QObject *parent) : QObject(parent)
{
    journalWriter = JournalWriter::getInstance();
    socketWriter = SocketWriter::getInstance();
    connect(ValuesController::getInstance(),&ValuesController::valuesPublished,this,&OutManager::write);
}

void OutManager::init(ScenarioType scenario){
    OutManager* mgr = OutManager::getInstance();
    //connect()
    mgr->scenario = scenario;
    /*switch (scenario) {
    case ScenarioType::Journal :
        writeJournal();
        break;
    case ScenarioType::Modbus :
        writeModbus();
        break;
    case ScenarioType::Socket :
        writeSocket();
        break;
    }*/
}

void OutManager::writeSocket(){
    auto msg = ValuesController::getInstance()->composeMessage();
    socketWriter->write(msg->data);
}

void OutManager::write(){
    writeJournal();
    switch (scenario) {
    case ScenarioType::Journal :
        break;
    case ScenarioType::Modbus :
        //writeModbus();
        break;
    case ScenarioType::Socket :
        writeSocket();
        break;
    }
}

void OutManager::writeJournal(){
    auto msg = ValuesController::getInstance()->composeMessage();
    journalWriter->write(msg->data);
}
