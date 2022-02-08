
// Rotary potentiometer sound controller
// and hotkeys emulator keyboard.

#include <math.h>
#include <Keyboard.h>

#define PORT_POTENTIOMETER 10   // analog
#define PORT_BUTTON 7           // digital

#define LIMIT 50

// Keyboard
void mute();
void quit();
void raise();

// Volume
void volume_up();
void volume_down();

// Controllers
void read_button();
void read_rotary();

// Main
void setup() {
	pinMode(PORT_BUTTON, INPUT);
	Keyboard.begin();
}

void loop() {
	read_button();
	read_rotary();
}

// Implementations

int is_high = 1;
void read_button() {
	int state = digitalRead(PORT_BUTTON);
	if (is_high == 1 && state == LOW) {
		Keyboard.print("pressed\n");
	}
	if (is_high == 0 && state == HIGH) {
		Keyboard.print("released\n");
	}
	if (state == HIGH) {
		is_high = 1;
	} else {
		is_high = 0;
	}
}

int current = 0;

void read_rotary() {
	int value = analogRead(PORT_POTENTIOMETER);
 	int diff = value - current;
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

void mute() {
	Keyboard.print("mute\n");
//	Keyboard.press('D');
//	Keyboard.press(KEY_LEFT_CTRL);
//	Keyboard.releaseAll();
}

void raise() {
	Keyboard.print("raise\n");
//	Keyboard.press(KEY_LEFT_CTRL);
//	Keyboard.press(KEY_LEFT_GUI);
//	Keyboard.press('H');
//	Keyboard.releaseAll();
}

void quit() {
	Keyboard.print("quit\n");
//	Keyboard.press(KEY_LEFT_CTRL);
//	Keyboard.press('W');
//	Keyboard.releaseAll();
}

void volume_up() {
	Keyboard.print("up\n");
//	Keyboard.press(KEY_RIGHT_GUI);
//	Keyboard.press(KEY_F10);
//	Keyboard.releaseAll();
}

void volume_down() {
	Keyboard.print("down\n");
// 	Keyboard.press(KEY_RIGHT_GUI);
// 	Keyboard.press(KEY_F9);	
// 	Keyboard.releaseAll();
}