int OUTPUT_PIN_RED = 9;  // D9
int OUTPUT_PIN_GREEN = 6;  // D6
int OUTPUT_PIN_BLUE = 3;  // D3

int MAX_OUT = 100;
int DELAY = 50;

void setup() {
	pinMode(OUTPUT_PIN_RED, OUTPUT);
	pinMode(OUTPUT_PIN_GREEN, OUTPUT);
	pinMode(OUTPUT_PIN_BLUE, OUTPUT);

  analogWrite(OUTPUT_PIN_RED, 0);
  analogWrite(OUTPUT_PIN_GREEN, 0);
  analogWrite(OUTPUT_PIN_BLUE, 0);
}

void loop() {
  smoothTransition(OUTPUT_PIN_RED, OUTPUT_PIN_GREEN);
  smoothTransition(OUTPUT_PIN_GREEN, OUTPUT_PIN_BLUE);
  smoothTransition(OUTPUT_PIN_BLUE, OUTPUT_PIN_RED); 
}

void smoothTransition(int pinFrom, int pinTo){
  for(int i = 0; i <= MAX_OUT; i++){
      analogWrite(pinTo, i);
      analogWrite(pinFrom, MAX_OUT - i);
      
      delay(DELAY);
  }
}