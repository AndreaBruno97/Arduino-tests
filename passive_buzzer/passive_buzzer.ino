const int output_pin = D8;
const int bpm = 130; // beats per minute
const int pause_between_notes = 5;  // milliseconds
const int pause_between_loops = 3000;  // milliseconds

const int c   = 261;
const int d_b = 277;
const int d   = 294;
const int e_b = 311;
const int e   = 330;
const int f   = 349;
const int g_b = 370;
const int g   = 392;
const int a_b = 415;
const int a   = 440;
const int b_b = 466;
const int b   = 493;
const int c_1 = 523;

const int beat = 60000 / bpm; 
const int whole       = beat * 4; 
const int dotted_half = beat * 3;
const int half        = beat * 2; 
const int quarter     = beat; 
const int eighth      = beat / 2; 
const int sixteenth   = beat / 4;

const int note_number = 9;
const int note_array[note_number] = {c_1, c_1, c_1, c_1, a_b, b_b, c_1, b_b, c_1};
const int duration_array[note_number] = {eighth, eighth, eighth, quarter, quarter, quarter, quarter, eighth, dotted_half};

void setup() {
	pinMode(output_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i=0; i < note_number; i++){
    int note_frequency = note_array[i];
    int note_duration = duration_array[i];

    Serial.println(note_frequency);
    tone(output_pin, note_frequency, note_duration);
    delay(note_duration + pause_between_notes);
  }

    tone(output_pin, 0, pause_between_loops);
    delay(pause_between_loops);
}
