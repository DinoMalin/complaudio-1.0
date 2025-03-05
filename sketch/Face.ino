#include "Face.h"

Face::Face(LCD _lcd) : x(3), lcd(_lcd) {}

void Face::blink() {
	//lcd.clear();
	lcd.drawBlink(x, 0);
	lcd.drawBlink(x+1, 0);
	lcd.drawRectangle(x+7, 0);
	lcd.drawRectangle(x+8, 0);
	lcd.drawRectangle(x+7, 1);
	lcd.drawRectangle(x+8, 1);
}

void Face::drawEyes() {
	//lcd.clear();
	lcd.drawRectangle(x, 0);
	lcd.drawRectangle(x+1, 0);
	lcd.drawRectangle(x+7, 0);
	lcd.drawRectangle(x+8, 0);
	lcd.drawRectangle(x, 1);
	lcd.drawRectangle(x+1, 1);
	lcd.drawRectangle(x+7, 1);
	lcd.drawRectangle(x+8, 1);
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
	//lcd.clear();
	lcd.drawRectangle(x, 0);
	lcd.drawChar(x+1, 0, 6);
	lcd.drawChar(x+7, 0, 7);
	lcd.drawRectangle(x+8, 0);
	lcd.drawRectangle(x, 5);
	lcd.drawRectangle(x+1, 1);
	lcd.drawRectangle(x+7, 1);
	lcd.drawRectangle(x+8, 1);
}

void Face::drawLove() {
	//lcd.clear();

	lcd.drawChar(x, 0, 2);
	lcd.drawChar(x+1, 0, 3);
	lcd.drawChar(x, 1, 4);
	lcd.drawChar(x+1, 1, 5);

	lcd.drawChar(x+7, 0, 2);
	lcd.drawChar(x+8, 0, 3);
	lcd.drawChar(x+7, 1, 4);
	lcd.drawChar(x+8, 1, 5);
}
