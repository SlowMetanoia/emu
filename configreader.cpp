#include "configreader.h"
Configurator* Configurator::configurator = nullptr;

Configurator::Configurator(QObject *parent) : QObject(parent)
{

}

Configurator* Configurator::getIntance(){
    if(Configurator::configurator == nullptr){
        Configurator::configurator = new Configurator();
    }
    return Configurator::configurator;
}

ImitatorConfig* Configurator::readConfig(QString fileName){
    QString val;
    QFile file;
    file.setFileName(fileName);
    if(!file.exists()){

        //#########сделать файл, если такого нет.
        createConfig(fileName);
    }
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    //bool isValid = true;

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject json = doc.object();
    QString scenario = json["scenario"].toString();
    int pulseWaitMs = json["pulseWaitMs"].toInt();
    int numberOfValues = json["numberOfValues"].toInt();
    QJsonArray regArray = json["regs"].toArray();
    QVector<RegistrConfig> regs;
    for(int i = 0; i<regArray.size(); i++){
        QJsonObject jreg = regArray[i].toObject();
        int regNum = jreg["regNum"].toInt();
        QString valType = jreg["valType"].toString();
        QString trueValueFunction = jreg["trueValueFunction"].toString();
        QString dinamicErrorFunction = jreg["dinamicErrorFunction"].toString();
        int zeroShift = jreg["zeroShift"].toInt();
        QString randomDistributionType = jreg["randomDistributionType"].toString();
        double M = jreg["Expectation"].toDouble();
        double Variance = jreg["Variance"].toDouble();
        double Left = jreg["Left"].toDouble();
        double Right = jreg["Right"].toDouble();

        ValueType valueType;
        RandomDistributionType randonDistrType;
        valueType = (valType.compare("float") == 0)? ValueType::Float :
                    (valType.compare("int") == 0)? ValueType::Int :
                    (valType.compare("unsigned") == 0)? ValueType::Unsigned :
                    (valType.compare("time") == 0)? ValueType::Time :
                                                    ValueType::Undefined;
        randonDistrType = (randomDistributionType.compare("normal")==0)? RandomDistributionType::Norm :
                          (randomDistributionType.compare("natural")==0)? RandomDistributionType::Flat :
                          (randomDistributionType.compare("zero")==0)? RandomDistributionType::Zero :
                                                                    RandomDistributionType::Unknown;

        QVector<double> parametrs(RandomParametrType::Illegal);
        parametrs[RandomParametrType::Expectation] = M;
        parametrs[RandomParametrType::Variance] = Variance;
        parametrs[RandomParametrType::Left] = Left;
        parametrs[RandomParametrType::Right] = Right;

        RegistrConfig reg(regNum,
                          valueType,
                          trueValueFunction,
                          dinamicErrorFunction,
                          zeroShift,
                          randonDistrType,
                          parametrs
                    );
        regs.append(reg);
    }

    if(config == nullptr){
        config = new ImitatorConfig();
    }
    //qDebug()<<scenario;
    config->scenario = (scenario.compare("journal")==0)? ScenarioType::Journal:
                       (scenario.compare("modbus")==0)? ScenarioType::Modbus:
                       (scenario.compare("socket")==0)? ScenarioType::Socket:
                                                        ScenarioType::Fake;
    config->pulseWaitMs = pulseWaitMs;
    config->numberOfValues = numberOfValues;
    config->regsConfig = regs;
    return config;
}

void Configurator::createConfig(QString fileName){
    QFile file;
    file.setFileName(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.close();
    return;
}
