// frequencies of c, d, e, and f
// e.g., http://www.phy.mtu.edu/~suits/notefreqs.html
int notes[] = {262, 294, 330, 349};
#define C notes[0]
#define D notes[1]
#define E notes[2]
#define F notes[3]

void setup() {
  Serial.begin(9600);

  tone(8,C,250); delay(250);
  tone(8,D,250); delay(250);
  tone(8,C,250); delay(250);
  tone(8,F,250); delay(250);
  tone(8,C,250); delay(250);
  tone(8,D,250); delay(250);
  tone(8,C,250); delay(250);
  tone(8,F,250); delay(250);
  tone(8,C,250); delay(250);
  tone(8,D,250); delay(250);
  tone(8,C,250); delay(250);
  tone(8,E,500); delay(500);
}

void loop() {
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

// ranges for keyVal
  if (keyVal == 1023) {
    tone(8, F);
  }
  else if (keyVal >= 990 && keyVal <= 1010) {
    tone(8, E);
  }
  else if (keyVal >= 505 && keyVal <= 515) {
    tone(8, D);
  }
  else if (keyVal >= 5 && keyVal <= 10) {
    tone(8, C);
  }
  else {
    noTone(8);
  }
}

