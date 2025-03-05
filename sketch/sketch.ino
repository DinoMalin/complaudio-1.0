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

	face.drawEyes();
	delay(800);

	face.drawAngry();
	delay(800);

	face.drawEyes();
	delay(800);

	face.drawLove();
	delay(1000);

	Serial.print("[CMD]");
	Serial.println("[firefox --new-window 'https://www.terre-plate.org/terre-plate-preuve-ultime/']");
	Serial.print("[CMD]");
	Serial.println("[pwd]");
}
