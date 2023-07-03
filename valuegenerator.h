#ifndef VALUEGENERATOR_H
#define VALUEGENERATOR_H

#include <QObject>
#include "RandomTypes.h"
#include <iostream>
#include <QDebug>
#include <string>
#include <vector>
#include <QVector>
#include <QRandomGenerator>
#include <exprtk.hpp>


typedef exprtk::symbol_table<double> symbol_table_t;
typedef exprtk::expression<double>   expression_t;
typedef exprtk::parser<double>       parser_t;

class ValueGenerator : public QObject
{
    Q_OBJECT

public:
    explicit ValueGenerator(QObject *parent = nullptr);
    ValueGenerator(QString rvf,
                   double zeroShift,
                   QString dinamicSystemError,
                   RandomDistributionType disrType,
                   QVector<double> distrParams
                   );
    //Функция реального значения f(t)
    expression_t* realValueFunc;
    double t;
    //смещение нуля
    double zeroShiftError;
    //динамическая системная ошибка
    expression_t* dinamicSystemError;
    double x;
    symbol_table_t dse_symbol_table;
    symbol_table_t rvf_symbol_table;

    expression_t rvfExpression;
    expression_t dseExpression;
    //функция случайного распределения
    RandomDistributionType disrType;
    QVector<double> distrParams;
    double generateValue(double x);
    double randomErrorFunc(RandomDistributionType functionType, QVector<double>);
signals:

};

#endif // VALUEGENERATOR_H
