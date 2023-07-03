#ifndef REGGENERATOR_H
#define REGGENERATOR_H


#include <string>
#include <exprtk.hpp>
#include <string>
#include <cstdio>
#include <QDebug>
#include "registrconfig.h"
#include "RandomTypes.h"
#include "valuegenerator.h"

typedef exprtk::symbol_table<double> symbol_table_t;
typedef exprtk::expression<double>   expression_t;
typedef exprtk::parser<double>       parser_t;

using namespace std;

class RegGenerator
{
public:
    RegGenerator(RegistrConfig rc);
    int regNumber;
    ValueType valueType;
    double value;
    ValueGenerator* generator;
    double update(double x);
};

#endif // REGGENERATOR_H
