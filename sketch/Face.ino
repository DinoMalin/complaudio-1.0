#include "Face.h"

Face::Face(LCD _lcd) : x(3), lcd(_lcd) {}

void Face::blink() {
	lcd.drawBlink(x, 0);
	lcd.drawBlink(x+1, 0);
	lcd.drawRectangle(x+8, 0);
	lcd.drawRectangle(x+9, 0);
	lcd.drawRectangle(x+8, 1);
	lcd.drawRectangle(x+9, 1);
}

void Face::drawEyes() {
	lcd.drawRectangle(x, 0);
	lcd.drawRectangle(x+1, 0);
	lcd.drawRectangle(x+8, 0);
	lcd.drawRectangle(x+9, 0);

	lcd.drawRectangle(x, 1);
	lcd.drawRectangle(x+1, 1);
	lcd.drawRectangle(x+8, 1);
	lcd.drawRectangle(x+9, 1);
}

void Face::drawLeftSideEye() {
	this->x = 1;
	drawEyes();
}

void Face::drawRightSideEye() {
	this->x = 6;
	drawEyes();
}

void Face::defaultPos() {
	this->x = 3;
	drawEyes();
}

void Face::drawAngry() {
	lcd.drawRectangle(x, 0);
	lcd.drawChar(x+1, 0, 6);
	lcd.drawChar(x+8, 0, 7);
	lcd.drawRectangle(x+9, 0);

	lcd.drawRectangle(x, 5);
	lcd.drawRectangle(x+1, 1);
	lcd.drawRectangle(x+8, 1);
	lcd.drawRectangle(x+9, 1);
}

void Face::drawLove() {
	lcd.drawChar(x, 0, 2);
	lcd.drawChar(x+1, 0, 3);
	lcd.drawChar(x, 1, 4);
	lcd.drawChar(x+1, 1, 5);

	lcd.drawChar(x+8, 0, 2);
	lcd.drawChar(x+9, 0, 3);
	lcd.drawChar(x+8, 1, 4);
	lcd.drawChar(x+9, 1, 5);
}
