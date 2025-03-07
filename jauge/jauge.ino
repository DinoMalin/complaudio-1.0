#include "Jauge.h"
#include "characters.h"

hd44780_I2Cexp lcd;
LCD _lcd(&lcd);
Jauge jauge(_lcd);

void setup() {
  	lcd.begin(16, 2);
  	lcd.createChar(0, rectangle);
	Serial.begin(9600);
	jauge.update(5);
}

void loop() {
	if (Serial.available() > 0) {
		char c = Serial.read();

		if (c >= '0' && c <= '8') {
			jauge.update(c - '0');
		}
	}
}
