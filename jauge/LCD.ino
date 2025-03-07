#include "LCD.h"

LCD::LCD(hd44780_I2Cexp *_lcd) : lcd(_lcd) {}

void LCD::drawChar(int x, int y, char c) {
	lcd->setCursor(x,y);
	int w = lcd->write(byte(c));
}

void LCD::drawRectangle(int x, int y) {
	drawChar(x, y, 0);
}
void LCD::drawBlink(int x, int y) {
	drawChar(x, y, 1);
}

void LCD::clear() {lcd->clear();}
