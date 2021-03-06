
// Rotary potentiometer sound controller
// and hotkeys emulator keyboard.

#include <math.h>
#include <Keyboard.h>

#define PORT_POTENTIOMETER 5    // analog
#define PORT_BUTTON_A      8    // digital
#define PORT_BUTTON_B      6    // digital
#define PORT_BUTTON_C      4    // digital

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
  read_button(0, raise);
  read_button(1, camera);
  read_button(2, mute);
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
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('d');
  Keyboard.releaseAll();
}

void camera() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('e');
  Keyboard.releaseAll();
}

void raise() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('h');
  Keyboard.releaseAll();
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
