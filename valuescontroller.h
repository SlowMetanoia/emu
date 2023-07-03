#ifndef VALUESCONTROLLER_H
#define VALUESCONTROLLER_H

#include <QObject>
#include <QVector>
//#include <QDebug>
#include "pulsecontroller.h"
#include "imitatorconfig.h"
#include "RandomTypes.h"
#include "registrconfig.h"
#include "reggenerator.h"
#include "binmessage.h"

class ValuesController : public QObject
{
    Q_OBJECT
public:
    explicit ValuesController(QObject *parent = nullptr);

    static ValuesController* controller;
    static ValuesController* getInstance();
    static ValuesController* init(ImitatorConfig* config);

    ValuesController(ImitatorConfig* config);
    QVector<RegGenerator*> regs;
    int valuesNumber;
    ScenarioType scenario;
    BinMessage* composeMessage();
public slots:
    void publishValues(double x);
signals:
    void valuesPublished();
};

#endif // VALUESCONTROLLER_H
