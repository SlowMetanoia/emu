#include "reggenerator.h"



//сборка генератора
ValueGenerator* buildGen(RegistrConfig rc){
    ValueGenerator* vg = new ValueGenerator(
                rc.TrueValueFunction,
                rc.zeroShift,
                rc.DinamicErrorFunction,
                rc.randomDistributionType,
                rc.randomDistributionParams
                );
    return vg;
}

RegGenerator::RegGenerator(RegistrConfig rc){
    this->regNumber = rc.registrNumber;
    this->valueType = rc.valueType;
    this->generator = buildGen(rc);
    this->value = generator->generateValue(0);
}

double RegGenerator::update(double x){
    this->value = generator->generateValue(x);
    return this->value;
}
