
#include <Wire.h>
#include <hd44780.h>           
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd; // auto-detects the I2C address

void setup() {
  lcd.begin(16, 2);
  lcd.print("lorem ipsum dolor sit amet");
}

void loop() {
}
