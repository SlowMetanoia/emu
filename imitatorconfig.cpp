#include "imitatorconfig.h"

ImitatorConfig::ImitatorConfig(QObject *parent) : QObject(parent)
{

}

QString ImitatorConfig::toString(){
    QString out;
    out.append("ImitatorConfig{ ");
    out.append("Scenario:");
    out.append(QString::number(this->scenario));
    out.append(", pulse delay:");
    out.append(QString::number(this->pulseWaitMs));

    //out.append(", number of values:");
    //out.append(QString::number(this->numberOfValues));

    out.append("\nRegisters config:\n");
    for(int i =0 ; i<regsConfig.size(); i++){
        out.append(this->regsConfig[i].toString());
        out.append("\n");
    }
    //out.remove(out.size()-1,1);
    return out;
}
