#include "Face.h"
#include "characters.h"

hd44780_I2Cexp lcd; // auto-detects the I2C address
LCD _lcd(&lcd);
Face face(_lcd);

void setup() {
  	lcd.begin(16, 2);
  	lcd.createChar(0, rectangle);
  	lcd.createChar(1, blink);

  	lcd.createChar(2, Heart1);
  	lcd.createChar(3, Heart2);
  	lcd.createChar(4, Heart3);
  	lcd.createChar(5, Heart4);

  	lcd.createChar(6, angryL);
  	lcd.createChar(7, angryR);

	Serial.begin(9600);
}

void loop() {
	char last = 0;
	if (Serial.available() > 0) {
		char c = Serial.read();
		if (c != last && c >= '0' && c <= '5')
			lcd.clear();
		if (c == '1') {
			face.drawEyes();
		} else if (c == '2') {
			face.blink();
			delay(300);
			face.drawEyes();
		} else if (c == '3') {
			face.drawLeftSideEye();
			delay(500);
			lcd.clear();
			face.drawRightSideEye();
			delay(500);
			lcd.clear();
			face.defaultPos();
			face.drawEyes();
		} else if (c == '4') {
			face.drawAngry();
		} else if (c == '5') {
			face.drawLove();
		}
	}
}
