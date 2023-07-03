#include "climanager.h"
CLIManager* CLIManager::clim = nullptr;
CLIManager* CLIManager::getInstance(){
    if(CLIManager::clim==nullptr)
        CLIManager::clim = new CLIManager;
    return CLIManager::clim;
}
CLIManager::CLIManager(QObject *parent) : QObject(parent){
    qDebug()<<"cli mode activated";
    CLICycle = QThread::create([](){
        PulseController* pc = PulseController::getInstance();
        std::string command;
        while(1){
            std::cin>>command;
            if(command.compare("exit")==0) exit(0);
            if(command.compare("start")==0) pc->start();
            if(command.compare("stop")==0) pc->stop();
            if(command.compare("pause")==0) pc->pause();
            if(command.compare("reset")==0) pc->reset();
        }
    });
    CLICycle->start();
}
