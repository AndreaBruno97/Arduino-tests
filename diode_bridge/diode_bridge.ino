int AC_HIGH = D10;
int AC_GND = D3;
int DC_IN = A5;

int _HIGH = 255;
int GND = 127;
int _LOW = 0;

int DELAY = 10;
int STEP_NUM = 200;

void setup() {
  	pinMode(AC_HIGH, OUTPUT);
  	pinMode(AC_GND, OUTPUT);
  	pinMode(DC_IN, INPUT);

    analogWrite(AC_GND, GND);

    Serial.begin(9600);
}

void loop() {
	for(int i = 0; i< STEP_NUM; i++){
    // Generate AC signal
    float x = i * ((2 * PI) / STEP_NUM);
    float y = sin(x) * (_HIGH - GND);
    int ac_out = (int)y + GND;

    analogWrite(AC_GND, GND);
    analogWrite(AC_HIGH, ac_out);

    delay(DELAY);
    
    // Read DC signal
    int cur_dc_in = analogRead(DC_IN);
    Serial.println(cur_dc_in);
  }
}
