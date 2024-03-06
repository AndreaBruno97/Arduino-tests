int ANALOG_IN = 0; // A0
int ANALOG_OUT = 3; // D3

int MAX_READ = 1023;
int MAX_WRITE = 255;

void setup() {
	Serial.begin(9600);
  
  pinMode(ANALOG_IN, INPUT);
  pinMode(ANALOG_OUT, OUTPUT);	
}

void loop() {
	int input_read = analogRead(ANALOG_IN);
  int output_write = (int)(input_read * MAX_WRITE / MAX_READ);
  Serial.println(String(input_read));

  analogWrite(ANALOG_OUT, output_write);
}
