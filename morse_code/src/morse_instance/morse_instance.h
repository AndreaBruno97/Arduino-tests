#ifndef MORSE_INSTANCE_H
#define MORSE_INSTANCE_H
#include "Arduino.h" 

class Morse_instance{
	private:
		int output_pin;
		int unit;
	public:
		Morse_instance(int init_output_pin, int init_unit); 
		void print(String string_to_print);
};

#endif MORSE_INSTANCE_H