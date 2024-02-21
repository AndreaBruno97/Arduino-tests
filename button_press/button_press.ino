int IN_PIN = 2;
int OUT_PIN = 4;

void setup() {
	pinMode(IN_PIN, INPUT);
  pinMode(OUT_PIN, OUTPUT);
}

void loop() {
  bool isButtonPressed = digitalRead(IN_PIN);
  digitalWrite(OUT_PIN, isButtonPressed);
}
