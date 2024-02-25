int ANALOG_IN = 0;      // A0
int DIGITAL_OUT_25 = 6;  // D6
int DIGITAL_OUT_50 = 5;  // D5
int DIGITAL_OUT_75 = 4;  // D4
int DIGITAL_OUT_100 = 3; // D3

int MAX_READ = 1023;

void setup() {
	Serial.begin(9600);
  
  pinMode(ANALOG_IN, INPUT);
  pinMode(DIGITAL_OUT_25, OUTPUT);
  pinMode(DIGITAL_OUT_50, OUTPUT);
  pinMode(DIGITAL_OUT_75, OUTPUT);
  pinMode(DIGITAL_OUT_100, OUTPUT);
}

void loop() {
  int potentiometer_read = analogRead(ANALOG_IN);
  int potentiometer_percent = (int)((potentiometer_read * 100) / MAX_READ);
  
	Serial.println(String(potentiometer_read) + ": " + String(potentiometer_percent));

  digitalWrite(DIGITAL_OUT_25, (potentiometer_percent >= 25) ? HIGH : LOW);
  digitalWrite(DIGITAL_OUT_50, (potentiometer_percent >= 50) ? HIGH : LOW);
  digitalWrite(DIGITAL_OUT_75, (potentiometer_percent >= 75) ? HIGH : LOW);
  digitalWrite(DIGITAL_OUT_100, (potentiometer_percent >= 100) ? HIGH : LOW);
}
