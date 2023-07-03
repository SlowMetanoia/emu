#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <QFile>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
//#include <QDebug>
#include "RandomTypes.h"

#include "imitatorconfig.h"

class Configurator : public QObject
{
    Q_OBJECT
public:
    static Configurator* configurator;
    static Configurator* getIntance();
    explicit Configurator(QObject *parent = nullptr);
    ImitatorConfig* readConfig(QString fileName);
    ImitatorConfig* config;
    void createConfig(QString fileName);
signals:

};

#endif // CONFIGREADER_H
