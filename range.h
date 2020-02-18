#ifndef RANGE_H
#define RANGE_H

#include <cstdint>

class Range{
public:
    Range(int32_t min = INT32_MIN, int32_t max = INT32_MAX);
    int32_t getMin();
    int32_t getMax();

    void setMin(int32_t min);
    void setMax(int32_t max);

    uint8_t isInRange(int32_t value);
private:
    int32_t min, max;
};

#endif // RANGE_H
