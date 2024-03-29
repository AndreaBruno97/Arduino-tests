#include "Arduino.h" 
#include "morse_instance.h"

int DIT = 1;
int DAH = 3;
int INTRA_CHARACTER_SPACE = 1;
int INTER_CHARACTER_SPACE = 3;
int WORD_SPACE = 7;

int char_map[36][5] = {
	{DIT, DAH},					// A
	{DAH, DIT, DIT, DIT},		// B
	{DAH, DIT, DAH, DIT},		// C
	{DAH, DIT, DIT},			// D
	{DIT},						// E
	{DIT, DIT, DAH, DIT},		// F
	{DAH, DAH, DIT},			// G
	{DIT, DIT, DIT, DIT},		// H
	{DIT, DIT},					// I
	{DIT, DAH, DAH, DAH},		// J
	{DAH, DIT, DAH},			// K
	{DIT, DAH, DIT, DIT},		// L
	{DAH, DAH},					// M
	{DAH, DIT},					// N
	{DAH, DAH, DAH},			// O
	{DIT, DAH, DAH, DIT},		// P
	{DAH, DAH, DIT, DAH},		// Q
	{DIT, DAH, DIT},			// R
	{DIT, DIT, DIT}, 			// S
	{DAH},						// T
	{DIT, DIT, DAH},			// U
	{DIT, DIT, DIT, DAH},		// V
	{DIT, DAH, DAH},			// W
	{DAH, DIT, DIT, DAH},		// X
	{DAH, DIT, DAH, DAH},		// Y
	{DAH, DAH, DIT, DIT},		// Z
	{DAH, DAH, DAH, DAH, DAH},	// 0
	{DIT, DAH, DAH, DAH, DAH},	// 1
	{DIT, DIT, DAH, DAH, DAH},	// 2
	{DIT, DIT, DIT, DAH, DAH},	// 3
	{DIT, DIT, DIT, DIT, DAH},	// 4
	{DIT, DIT, DIT, DIT, DIT},	// 5
	{DAH, DIT, DIT, DIT, DIT},	// 6
	{DAH, DAH, DIT, DIT, DIT},	// 7
	{DAH, DAH, DAH, DIT, DIT},	// 8
	{DAH, DAH, DAH, DAH, DIT}	// 9
};

Morse_instance::Morse_instance(int init_output_pin, int init_unit){
	output_pin = init_output_pin;
	pinMode(output_pin, OUTPUT);
	
	unit = init_unit;
}

void Morse_instance::print(String string_to_print){
	string_to_print.toLowerCase();
	
	for(int char_index = 0; char_index < string_to_print.length(); char_index ++){
		char cur_char = string_to_print[char_index];
		
		if(cur_char == ' '){
			digitalWrite(output_pin, LOW);
			delay(WORD_SPACE * unit);
		}
		else{
			int map_index;
			if(isDigit(cur_char)){
				map_index = 26 + (int)cur_char - (int)'0';
			}
			else{
				map_index = (int)cur_char - (int)'a';
			}
			
			int* cur_char_map = char_map[map_index];
			int morse_char_len = sizeof(char_map[map_index]) / sizeof(char_map[map_index][0]);
			for(int morse_char_index = 0; morse_char_index < morse_char_len; morse_char_index++){
				int is_last_morse_char = morse_char_index == morse_char_len - 1; 
				int char_duration = char_map[map_index][morse_char_index];
				
				digitalWrite(output_pin, HIGH);
				delay(char_duration * unit);
				digitalWrite(output_pin, LOW);
				if(is_last_morse_char){
					delay(INTER_CHARACTER_SPACE * unit);
				}
				else{
					delay(INTRA_CHARACTER_SPACE * unit);
				}
			}
		}
	}			
}