// Test for Ultrasonic Ranging Module HC-SR04
// According to Data Sheet: http://www.micropik.com/PDF/HCSR04.pdf

int triggerPin = 9;
int echoPin = 8;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // send 10 us trigger pulse:
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // wait for high echo:
  while (digitalRead(echoPin) == LOW) {
  }
  unsigned long pulseStart = micros();
  
  // wait for low echo:
  while (digitalRead(echoPin) == HIGH) {
  }
  unsigned long pulseStop = micros();
  
  // calculate duration and distance:
  unsigned long pulseDuration = pulseStop - pulseStart;
  unsigned long distance = pulseDuration / 58;

  // output to serial:
  Serial.print(pulseDuration);
  Serial.print(" us pulse => ");
  Serial.print(distance);
  Serial.println(" cm");

  // wait a second
  delay(1000);
}
