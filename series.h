#ifndef SERIES_H
#define SERIES_H
#include <QVector>

typedef double(*genfunc)(QVector<double>);

class Series
{
    QVector<double> values;
    genfunc generatingFunction;
    int32_t size;

public:
    QVector<double> getCurrentValues();
    void generateNextValues(int n);
    double next();
    int32_t length();
    bool isEmpty();

    Series(const genfunc genFunc);
};

#endif // SERIES_H
