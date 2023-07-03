#ifndef IMITATORCONFIG_H
#define IMITATORCONFIG_H

#include <QObject>
#include "registrconfig.h"
#include <QVector>
#include "RandomTypes.h"

class ImitatorConfig : public QObject
{
    Q_OBJECT
public:
    explicit ImitatorConfig(QObject *parent = nullptr);
    ScenarioType scenario;
    int pulseWaitMs;
    long numberOfValues;
    QVector<RegistrConfig> regsConfig;
    QString toString();
signals:
};

#endif // IMITATORCONFIG_H
