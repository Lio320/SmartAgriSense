#ifndef HUMIDITY_SENSOR_H
#define HUMIDITY_SENSOR_H

#include <Arduino.h>

class HumiditySensor {
    private:
        const int analogPin_;
        const int dryThresh_;
        const int wetThresh_;
    public:
        HumiditySensor(int analogPin, int dryThresh, int wetThresh);
        int readRaw();
        int readPercentage();
};

#endif