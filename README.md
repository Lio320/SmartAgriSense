# SmartAgriSensev🌿📡

**SmartAgriSense** is a modular embedded system designed for smart agriculture applications. Built on an STM32 Nucleo board, it combines capacitive soil moisture sensors and digital temperature probes (DS18B20) to monitor environmental conditions in real-time.

The system features:
- 🌱 **4 capacitive soil moisture sensors**
- 🌡️ **4 temperature sensors (DS18B20) on a shared 1-Wire bus**
- 🖥️ **16x2 LCD display** to visualize plant-specific data
- 🔘 **User button** to cycle through monitored plants
- ⚙️ Designed with modular C++ classes (`HumiditySensor`, `TemperatureSensor`, `PlantVase`, `Display`)

It’s ideal for:
- Research prototypes in precision agriculture
- Educational embedded systems projects
- Scalable smart farming node development

---

## 💡 Goals

- Provide a clear, extensible platform for plant condition monitoring
- Enable integration with wireless modules or SD card logging in future versions
- Keep code modular and hardware-agnostic for easy porting

---

## 🔧 Built With

- STM32 Nucleo-F401RE (Arduino-compatible with PlatformIO)
- OneWire & DallasTemperature libraries
- Capacitive soil sensors (v2.0)
- Standard HD44780 16x2 LCD


# 🔭 TODO / Future Work
The following features are planned to expand SmartAgriSense into a complete remote monitoring platform:

- 📶 Bluetooth module integration
Enable local data transfer to a smartphone or laptop without needing a wired connection.

- 🌐 Wi-Fi module support (e.g., ESP8266 or ESP32)
Allow real-time remote data upload to a local server or cloud platform.

- 📱 Companion mobile/web app
A simple pairing interface to:

    - Connect to the SmartAgriSense node

    - Download historical measurements

    - Visualize temperature and soil trends using interactive graphs

    - 💾 Data logging to SD card (optional fallback)
    Enable offline data recording for later download or analysis.

    - ⚡ Low-power optimization
    Add power-saving sleep modes for long-term deployment in field conditions.

