#include <PlantVase.h>


PlantVase::PlantVase(String label, HumiditySensor* humSensor, TemperatureSensor* tempSensor)
    :   name(label),
        temp(0.0),
        hum(0.0),
        humSensor_(humSensor),
        tempSensor_(tempSensor)
{
    //Body empty
}

void PlantVase::update() {
    this->temp = 0.0;
    this->hum = humSensor_->readPercentage();
    this->temp = tempSensor_->readTemp();
    Serial.print(temp);
};

SensorData PlantVase::getSensorData() {
    SensorData data;
    data.temp = this->temp;
    data.hum = this->hum;
    return data;
};