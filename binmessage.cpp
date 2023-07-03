#include "binmessage.h"

void BinMessage::addValue(const char* value, uint len){
    data.append(value,len);
}
