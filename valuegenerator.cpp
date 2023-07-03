#include "valuegenerator.h"

ValueGenerator::ValueGenerator(QObject *parent) : QObject(parent)
{

}

ValueGenerator::ValueGenerator(QString rvf,
                               double zeroShift,
                               QString dinamicSystemError,
                               RandomDistributionType disrType,
                               QVector<double> distrParams){
    while(distrParams.size()<RandomParametrType::Illegal) distrParams.append(0);

    std::string rvfExp = rvf.toStdString();
    std::string dseExp = dinamicSystemError.toStdString();

    //qDebug()<<rvf;
    //qDebug()<<dinamicSystemError;

    rvf_symbol_table.add_variable("t",this->t);
    //rvf_symbol_table.add_variable("x",this->x);
    rvf_symbol_table.add_constants();


    dse_symbol_table.add_variable("x",this->x);
    rvf_symbol_table.add_constants();

    rvfExpression.register_symbol_table(rvf_symbol_table);
    dseExpression.register_symbol_table(dse_symbol_table);

    parser_t rfv_parser;
    rfv_parser.compile(rvfExp,rvfExpression);
    parser_t dse_parser;
    dse_parser.compile(dseExp,dseExpression);

    this->realValueFunc = &rvfExpression;
    this->dinamicSystemError = &dseExpression;
    this->zeroShiftError = zeroShift;
    this->disrType = disrType;
    this->distrParams = distrParams;
}

double ValueGenerator::generateValue(double x){
    this->t = x;
    const double realValue = realValueFunc->value();
    this->x = realValue;
    double dinamicDeviation = dinamicSystemError->value();
    double randomError = randomErrorFunc(disrType, distrParams);
    double resultValue = realValue + zeroShiftError + dinamicDeviation + randomError;
    return resultValue;
}

double ValueGenerator::randomErrorFunc(RandomDistributionType functionType, QVector<double> params){
    double error = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> normal(
            params[RandomParametrType::Expectation],
            params[RandomParametrType::Variance]
            );
    std::uniform_real_distribution<double> flat(params[Left], params[Right]);
    //QRandomGenerator rGen = QRandomGenerator::securelySeeded();
    switch (functionType) {
    case Zero: error = 0;
        break;
    case Flat: error = flat(gen);
        break;
    case Norm: error = normal(gen);
        break;
    default:
        break;
    }
    return error;
}
