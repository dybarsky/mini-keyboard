
// Rotary potentiometer sound controller
// and hotkeys emulator keyboard.

#include <math.h>
#include <Keyboard.h>

#define PORT_INPUT 41
#define LIMIT 50

void volume_up();
void volume_down();

void setup() {
	Keyboard.begin();
}

char current = 0;

void loop() {
	char value = analogRead(PORT_INPUT);
 	char diff = value - current;
	if (abs(diff) <= LIMIT) {
		return;
	}
	if (diff > 0) {
		volume_up();
	} else {
		volume_down();
	}
	current = value;	
}

void volume_up() {
	Keyboard.press(KEY_RIGHT_GUI);
	Keyboard.press(KEY_F10);
	Keyboard.releaseAll();
}

void volume_down() {
	Keyboard.press(KEY_RIGHT_GUI);
	Keyboard.press(KEY_F9);	
	Keyboard.releaseAll();
}
