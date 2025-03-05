#include "Face.h"

hd44780_I2Cexp lcd; // auto-detects the I2C address
LCD _lcd(&lcd);
Face face(_lcd);

byte rectangle[8] = {
	0xff,
	0xff,
	0xff,
	0xff,
	0xff,
	0xff,
	0xff,
	0xff,
};

byte blink[8] = {
	0,
	0,
	0,
	0,
	0,
	0b11111,
	0b11111,
};

void setup() {
  	lcd.begin(16, 2);
  	lcd.createChar(0, rectangle);
  	lcd.createChar(1, blink);
	Serial.begin(9600);
}

void loop() {
	face.drawEyes();
	delay(1200);

	face.drawLeftSideEye();
	delay(500);

	face.drawRightSideEye();
	delay(500);

	face.defaultPos();
	face.drawEyes();
	delay(800);

	face.blink();
	delay(300);

	Serial.print("[CMD]");
	Serial.println("[firefox --new-window 'https://www.terre-plate.org/terre-plate-preuve-ultime/']");
	Serial.print("[CMD]");
	Serial.println("[pwd]");
}
