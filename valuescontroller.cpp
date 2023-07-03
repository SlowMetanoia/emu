#include "valuescontroller.h"
ValuesController* ValuesController::controller = nullptr;

ValuesController* ValuesController::getInstance(){
    return ValuesController::controller;
}

ValuesController* ValuesController::init(ImitatorConfig* config){
    ValuesController::controller = new ValuesController(config);
}

ValuesController::ValuesController(QObject *parent) : QObject(parent)
{

}

ValuesController::ValuesController(ImitatorConfig* config){
    connect(PulseController::getInstance(),&PulseController::valuePulse, this, &ValuesController::publishValues);
    scenario = config->scenario;
    valuesNumber = config->numberOfValues;

    for(int i = 0; i < config->regsConfig.size(); i++){
        this->regs.append(new RegGenerator(config->regsConfig[i]));
    }
    (config->scenario == ScenarioType::Journal);
    switch (config->scenario) {
    case ScenarioType::Journal :
        break;
    case ScenarioType::Modbus :
        break;
    case ScenarioType::Socket :
        break;
    case ScenarioType::Fake :
        break;
    }


}

void ValuesController::publishValues(double t){
    for(RegGenerator* rg:regs){
        rg->update(t);
        //qDebug()<<rg->regNumber<<rg->value;
    }
    auto msg = composeMessage();
    //qDebug()<<msg->data;
    emit valuesPublished();
}

BinMessage* ValuesController::composeMessage(){
    BinMessage* msg = new BinMessage();
    for(int i =0; i< regs.size(); i++){
        RegGenerator* rg = regs[i];
        int intValue = int(rg->value);
        float floatValue = float(rg->value);
        unsigned unsignedValue = unsigned(rg->value);
        switch (rg->valueType) {
        case ValueType::Int:
            msg->addValue((char*)&intValue,sizeof (intValue));
            break;
        case ValueType::Float:
            msg->addValue((char*)&floatValue,sizeof (floatValue));
            break;
        case ValueType::Unsigned:
            msg->addValue((char*)&unsignedValue,sizeof (unsignedValue));
            break;
        case ValueType::Time:
            timespec now;
            clock_gettime(CLOCK_REALTIME,&now);
            msg->addValue((char*)&now,sizeof (now));
            break;
        }
    }
    return msg;
}

