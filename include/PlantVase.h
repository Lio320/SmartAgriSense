#ifndef PLANT_VASE_H
#define PLANT_VASE_H

#include <Arduino.h>
#include "HumiditySensor.h"
#include "TemperatureSensor.h"


struct SensorData {
    float temp;
    int hum;
};

class PlantVase {
    private:
        HumiditySensor* humSensor_;
        TemperatureSensor* tempSensor_;
    public:
        String name;
        float temp;
        int hum;

        PlantVase(String name, HumiditySensor* humSensor, TemperatureSensor* tempSensor_);
        void update();
        SensorData getSensorData();
};

#endif