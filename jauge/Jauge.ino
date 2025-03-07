#include "Jauge.h"

Jauge::Jauge(LCD _lcd) : lcd(_lcd) {}

void Jauge::update(int newScore) {
	lcd.clear();
	for (int i = 0; i < newScore*2; i++) {
		lcd.drawRectangle(i, 0);
		lcd.drawRectangle(i+1, 0);
		lcd.drawRectangle(i,1);
		lcd.drawRectangle(i+1, 1);
	}
}
