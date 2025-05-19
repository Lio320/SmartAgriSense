#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(int digitalPin)
    :   digitalPin_(digitalPin),
        oneWire_(digitalPin_),
        dallas_(&oneWire_)
{
    dallas_.begin();
};

float TemperatureSensor::readTemp() {
    dallas_.requestTemperatures();
    return dallas_.getTempCByIndex(0);
}