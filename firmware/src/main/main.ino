
// Rotary potentiometer sound controller
// and hotkeys emulator keyboard.

#include <math.h>
#include <Keyboard.h>

#define PORT_POTENTIOMETER 10   // analog
#define PORT_BUTTON_A      7    // digital
#define PORT_BUTTON_B      6    // digital
#define PORT_BUTTON_C      5    // digital

#define LIMIT 50

// Keyboard
void mute();
void raise();
void camera();

// Volume
void volume_up();
void volume_down();

// Controllers
void read_rotary();
void read_button(int, void (*fun)());

// Main
void setup() {
	pinMode(PORT_BUTTON_A, INPUT);
	pinMode(PORT_BUTTON_B, INPUT);
	pinMode(PORT_BUTTON_C, INPUT);
	Keyboard.begin();
}

void loop() {
	read_rotary();
	read_button(0, camera);
	read_button(1, mute);
	read_button(2, raise);
}

// Implementations

int ports[3] = { 
	PORT_BUTTON_A, 
	PORT_BUTTON_B, 
	PORT_BUTTON_C
};

int states[3] = {1, 1, 1};

void read_button(int number, void (*fun)()) {
	int is_high = states[number];
	int port = ports[number];
	int state = digitalRead(port);
	if (is_high == 1 && state == LOW) {
		fun();
	}
	if (state == HIGH) {
		is_high = 1;
	} else {
		is_high = 0;
	}
	states[number] = is_high;
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

void camera() {
	Keyboard.print("camera\n");
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