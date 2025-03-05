#pragma once
#include "LCD.h"

class Face {
private:
	int x;
	LCD lcd;
public:
	void blink();
	void drawEyes();
	void drawLeftSideEye();
	void drawRightSideEye();
	void defaultPos();
	Face(LCD lcd);
};
