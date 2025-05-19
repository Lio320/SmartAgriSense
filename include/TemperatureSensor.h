#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class TemperatureSensor {
    private:
        const int digitalPin_;
        OneWire oneWire_;
        DallasTemperature dallas_;
    public:
        TemperatureSensor(int digitalPin);
        float readTemp();
};

#endif