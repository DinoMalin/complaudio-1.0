
#include <Wire.h>
#include <hd44780.h>           
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd; // auto-detects the I2C address

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

#define RECTANGLE 0
#define BLINK 1

#define draw_rectangle(x, y) draw_char(x, y, RECTANGLE);
#define draw_blink(x, y) draw_char(x, y, BLINK);

void draw_char(int x, int y, char c) {
	lcd.setCursor(x,y);
	lcd.write(byte(c));
}

void draw_eyes(int x) {
  draw_rectangle(x, 0);
  draw_rectangle(x+1, 0);
  draw_rectangle(x+7, 0);
  draw_rectangle(x+8, 0);
  draw_char(x, 1, '\n');
  draw_char(x+1, 1, '\n');
  draw_char(x+7, 1, '\n');
  draw_char(x+8, 1, '\n');
}

void do_blink(int x) {
  draw_blink(x, 0);
  draw_blink(x+1, 0);
  draw_rectangle(x+7, 0);
  draw_rectangle(x+8, 0);
  draw_char(x, 1, '\n');
  draw_char(x+1, 1, '\n');
  draw_char(x+7, 1, '\n');
  draw_char(x+8, 1, '\n');
}

void setup() {
  	lcd.begin(16, 2);
  	lcd.createChar(0, rectangle);
  	lcd.createChar(1, blink);
}

void loop() {
	draw_eyes(3);
	delay(1200);
	lcd.clear();

	do_blink(3);
	delay(200);
	lcd.clear();

	draw_eyes(3);
	delay(1200);
	lcd.clear();

	// look to the sides
	draw_eyes(1);
	delay(800);
	lcd.clear();
	draw_eyes(5);
	delay(800);
	lcd.clear();

	Serial.

}
