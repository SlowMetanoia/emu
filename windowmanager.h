#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QObject>
#include "form.h"
#include <QVector>

class WindowManager : public QObject
{
    Q_OBJECT
public:
    explicit WindowManager(QObject *parent = nullptr);
    static WindowManager* windowManager;
    static WindowManager* getInstance();
    Form* getNewRegistrForm();
signals:

};

#endif // WINDOWMANAGER_H
