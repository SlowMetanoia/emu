#include "series.h"

Series::Series(genfunc genFunc){
    generatingFunction = genFunc;
    size = 0;
}

double Series::next(){
    double value = generatingFunction(values);
    values.append(value);
    size++;
    return value;
}

QVector<double> Series::getCurrentValues(){
    return values;
}

void Series::generateNextValues(int n){
    for(int m = size + n; size < m; next());
}

int32_t Series::length(){
    return size;
}

bool Series::isEmpty(){
    return size == 0;
}
