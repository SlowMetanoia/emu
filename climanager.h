#ifndef CLIMANAGER_H
#define CLIMANAGER_H

#include <QObject>
#include "pulsecontroller.h"
#include <iostream>
#include <QThread>
#include <QDebug>
#include <list>

class CLIManager : public QObject
{
    Q_OBJECT
public:
    explicit CLIManager(QObject *parent = nullptr);
    static CLIManager* clim;
    static CLIManager* getInstance();
    QThread* CLICycle;
signals:

};

#endif // CLIMANAGER_H
