#include "src/morse_instance/morse_instance.h";
Morse_instance morse_print(D13, 100);

void setup() {
}

void loop() {
	morse_print.print("hello world");
  delay(1000);
}
