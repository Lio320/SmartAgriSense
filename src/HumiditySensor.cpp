#include <HumiditySensor.h>

HumiditySensor::HumiditySensor(int analogPin, int dryThresh, int wetThresh)
    :   analogPin_(analogPin),
        dryThresh_(dryThresh),
        wetThresh_(wetThresh)
{
    // Empty body
};

int HumiditySensor::readRaw() {
    int raw = analogRead(this->analogPin_);
    return raw;
};

int HumiditySensor::readPercentage() {
    int raw = analogRead(this->analogPin_);
    int value = map(raw, this->dryThresh_, this->wetThresh_, 0, 100);
    return value;
};