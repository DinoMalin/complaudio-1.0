#pragma once

#include <Wire.h>
#include <hd44780.h>           
#include <hd44780ioClass/hd44780_I2Cexp.h>

class LCD {
public:
	hd44780_I2Cexp lcd;

	LCD(hd44780_I2Cexp lcd);

	void drawChar(int x, int y, char c);
	void drawRectangle(int x, int y);
	void drawBlink(int x, int y);
	void clear();
};
