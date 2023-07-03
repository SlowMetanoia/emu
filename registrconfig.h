#ifndef REGISTRCONFIG_H
#define REGISTRCONFIG_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QStringList>
#include "RandomTypes.h"



class RegistrConfig : public QObject
{
    Q_OBJECT
public:
    explicit RegistrConfig(QObject *parent = nullptr);
    RegistrConfig(int registrNumber,
                  ValueType valueType,
                  QString TrueValueFunction,
                  QString DinamicErrorFunction,
                  double zeroShift,
                  RandomDistributionType randomDistributionType,
                  QVector<double> randomDistributionParams);
    RegistrConfig& operator=(const RegistrConfig&);
    RegistrConfig(const RegistrConfig& o);
    int registrNumber;
    ValueType valueType;
    QString TrueValueFunction;
    QString DinamicErrorFunction;
    double zeroShift;
    RandomDistributionType randomDistributionType;
    QVector<double> randomDistributionParams;
    QString toString();
signals:
};

#endif // REGISTRCONFIG_H
