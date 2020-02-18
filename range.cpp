#include "range.h"

Range::Range(int32_t min, int32_t max){
    this->min = min;
    this->max = max;
}

int32_t Range::getMin(){
    return min;
}

int32_t Range::getMax(){
    return max;
}

void Range::setMin(int32_t min){
    this->min = min;
}

void Range::setMax(int32_t max){
    this->max = max;
}

uint8_t Range::isInRange(int32_t value){
    if((value >= min) && (value <= max))
        return true;
    return false;
}
