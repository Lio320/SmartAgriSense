#include "Display.h"

Display::Display(Pins pinsConf, int cols, int rows)
    : _cols(cols),
      _rows(rows),
      _pins(pinsConf),
      _lcd(pinsConf.rs, pinsConf.e, pinsConf.d4, pinsConf.d5, pinsConf.d6, pinsConf.d7)
{
    _lcd.begin(this->_cols, this->_rows);
    _lcd.clear();
    delay(100);
    _lcd.setCursor(0, 0);
    _lcd.print("DISPLAY OK");
    loadCustomChars();
}

void Display::loadCustomChars() {

    byte thermometer[8] = {
        B00100, B01010, B01010, B01010,
        B01110, B11111, B11111, B01110
    };

    byte waterDrop[8] = {
        B00100, B00100, B01010, B01010,
        B10001, B10001, B10001, B01110
    };

    byte plant[8] = {
        B00100, B01110, B00100, B01110,
        B10101, B00100, B00100, B00100
    };

    _lcd.createChar(0, thermometer);
    _lcd.createChar(1, waterDrop);
    _lcd.createChar(2, plant);
}

void Display::clear() {
    _lcd.clear();
}

void Display::writeTextLine(int row, String text) {
    _lcd.setCursor(0, row);
    _lcd.print(text);
}

void Display::writeVaseStatus(PlantVase vase) {
    Serial.println("[Display] Updating LCD");

    _lcd.clear();
    delay(10);

    _lcd.setCursor(0, 0);
    _lcd.write(byte(2));  // plant icon
    _lcd.print(" ");
    _lcd.print(vase.name);

    _lcd.setCursor(0, 1);
    _lcd.write(byte(0));  // thermometer icon
    _lcd.print((int)vase.temp);
    _lcd.print("*C ");
    _lcd.write(byte(1));  // water drop icon
    _lcd.print((int)vase.hum);
    _lcd.print("%");
}
