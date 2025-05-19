#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "PlantVase.h"

struct Pins {
    int rs;
    int e;
    int d4;
    int d5;
    int d6;
    int d7;
};

class Display {
  private:
    int _cols;
    int _rows;
    Pins _pins;
    LiquidCrystal _lcd;

  public:
    Display(Pins pinsConf, int cols, int rows);
    void loadCustomChars();
    void clear();
    void writeTextLine(int row, String text);
    void writeVaseStatus(PlantVase vase);
};

#endif