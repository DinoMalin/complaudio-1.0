#pragma once
#include "LCD.h"

class Jauge {
private:
	LCD lcd;
public:
	Jauge(LCD lcd);
	void update(int newScore);
};
