#ifndef RANDOMTYPES_H
#define RANDOMTYPES_H

enum RandomDistributionType{
    Norm,
    Flat,
    Zero,
    Unknown
};

enum RandomParametrType{
    Expectation,
    Variance,
    Left,
    Right,
    Illegal
};

enum ValueType{
    Int,
    Unsigned,
    Float,
    Time,
    Undefined
};

enum ScenarioType{
    Journal,
    Modbus,
    Socket,
    Fake
};

#endif // RANDOMTYPES_H
