#pragma once
#include "LCD.h"

class Face {
private:
	int x;
	LCD lcd;
public:
	void blink();
	void drawEyes();
	Face(LCD lcd);
};
