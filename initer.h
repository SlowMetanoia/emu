#ifndef INITER_H
#define INITER_H

#include <QObject>
#include "pulsegenerator.h"
#include "configreader.h"
#include "pulsecontroller.h"
#include "valuescontroller.h"
#include "journalwriter.h"
#include "outmanager.h"
#include "climanager.h"
#include <QThread>

class Initer : public QObject
{
    Q_OBJECT
public:
    explicit Initer(QObject *parent = nullptr);
    static void GeneralInit();
signals:
};

#endif // INITER_H
