int sensorValue;

int sensorLow = 1023;
int sensorHigh = 0;

int maxFreq = 4000;
int minFreq = 50;

int highestSound = 3000;
int lowestSound = 50;

const int ledPin = 13;

int const toneDur = 1000;

void setup() {
  pinMode(ledPin, OUTPUT);
  
  // mark beginning of calibration with LED ...
  digitalWrite(ledPin, HIGH);
  // ... and sound
  int y = 0;
  for(int x = lowestSound; x < highestSound; x+=1000){
    tone(8, x,toneDur);
    delay(toneDur);
    y++;
  }

  while (millis() < toneDur*y+5000) {
    // maximum sensor value
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // minimum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  
  // end of calibration with LED ...
  digitalWrite(ledPin, LOW);
  // ... and sound
  for(int x = highestSound+lowestSound; x >= lowestSound; x-=1000){
    tone(8, x,toneDur);
    delay(toneDur);
  }

  Serial.begin(9600);
  delay(1000);
}

void loop() {
  sensorValue = analogRead(A0);

  Serial.println(sensorValue);

  int pitch = map(sensorValue, sensorLow, sensorHigh, maxFreq, minFreq);

  tone(8, pitch, 20);

  delay(10);
}

