#include "registrconfig.h"

RegistrConfig::RegistrConfig(QObject *parent) : QObject(parent){}
RegistrConfig::RegistrConfig(const RegistrConfig& o){
    this->registrNumber = o.registrNumber;
    this->valueType = o.valueType;
    this->TrueValueFunction = o.TrueValueFunction;
    this->DinamicErrorFunction = o.DinamicErrorFunction;
    this->zeroShift = o.zeroShift;
    this->randomDistributionType = o.randomDistributionType;
    this->randomDistributionParams = o.randomDistributionParams;
}
RegistrConfig::RegistrConfig(int registrNumber,
                             ValueType valueType,
                             QString TrueValueFunction,
                             QString DinamicErrorFunction,
                             double zeroShift,
                             RandomDistributionType randomDistributionType,
                             QVector<double> randomDistributionParams){
    this->registrNumber = registrNumber;
    this->valueType = valueType;
    this->TrueValueFunction = TrueValueFunction;
    this->DinamicErrorFunction = DinamicErrorFunction;
    this->zeroShift = zeroShift;
    this->randomDistributionType = randomDistributionType;
    this->randomDistributionParams = randomDistributionParams;
}
QString RegistrConfig::toString(){
    QStringList list;
    list << "RegistrConfig{"
         << "registrNumber = "
         << QString::number(registrNumber)
         << ", Value type = "
         << QString::number(valueType)
         << ", TrueValueFunction = "
         << TrueValueFunction
         << ", DinamicErrorFunction = "
         << DinamicErrorFunction
         << ", zeroShift = "
         << QString::number(zeroShift)
         << ", randomDistributionType = "
         << QString::number(randomDistributionType)
         << ", randomDistributionParams[";
    for(int i = 0; i<randomDistributionParams.size();i++){
        list << QString::number(randomDistributionParams[i]) <<",";
    }
    list.removeLast();
    list<<"]";
    list<<"}";
    QString out;
    for(QString str: list) out.append(str);
    return out;
}
