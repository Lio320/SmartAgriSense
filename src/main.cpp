#include <Arduino.h>
#include <Display.h>
#include <PlantVase.h>
#include <HumiditySensor.h>
#include <TemperatureSensor.h>

// --- DISPLAY CONFIGURATION --- //
int lcd_rows = 2;
int lcd_cols = 16;
Pins pinsConfig = {D12, D11, D5, D4, D3, D2};
Display display = Display(pinsConfig, lcd_rows, lcd_cols);

// --- BUTTON CONFIGURATION --- //
const int buttonPin = PC13; // Onboard user button for STM32
int switchState = 0;

// --- HUMIDITY SENSORS --- //
HumiditySensor humSensors[] = {
    HumiditySensor(A0, 350, 180),
    HumiditySensor(A1, 350, 180),
    HumiditySensor(A2, 350, 180),
    HumiditySensor(A3, 350, 180)
};
const int num_sensors = sizeof(humSensors) / sizeof(humSensors[0]);

// --- TEMPERATURE SENSORS (DS18B20) --- //
TemperatureSensor tempSensors[] = {
    TemperatureSensor(D6),  // PA8
    TemperatureSensor(D7),  // PB10
    TemperatureSensor(D8),  // PB4
    TemperatureSensor(D9)   // PB5
};

// --- PLANT VASE SETUP --- //
PlantVase vases[] = {
    PlantVase("Khali", &humSensors[0], &tempSensors[0]),
    PlantVase("Jeremy", &humSensors[1], &tempSensors[1]),
    PlantVase("Richard", &humSensors[2], &tempSensors[2]),
    PlantVase("James", &humSensors[3], &tempSensors[3])
};
const int num_vases = sizeof(vases) / sizeof(vases[0]);
int activeVase = 0;

void setup() {
    Serial.begin(9600);
    // delay(500);  // Let system and LCD settle
    pinMode(buttonPin, INPUT);
}

void loop() {
    // Update sensor data for all vases
    for (int i = 0; i < num_vases; i++) {
        vases[i].update();
    }

    // Handle button press to switch vase
    switchState = digitalRead(buttonPin);
    Serial.print(switchState);
    if (switchState == LOW) {  // Active LOW on STM32 user button
        activeVase = (activeVase + 1) % num_vases;
    }

    // Show current vase status on LCD
    display.writeVaseStatus(vases[activeVase]);

}
