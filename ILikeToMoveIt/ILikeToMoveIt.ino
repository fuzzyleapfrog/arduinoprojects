// Stay still for 10 Seconds
// *************************

const int tiltswitchPin = 8; // tilt switch

unsigned long previousTime = 0; // last time an LED was updated

int switchState = 0; // urrent switch state
int prevSwitchState = 0; // previous switch state

int led = 2;

long standstilltime = 10000; // in ms
int amountofLEDs = 6;

long interval = standstilltime/amountofLEDs; // interval at which to light the next LED

// *************
// *** SETUP ***
// *************

void setup() {
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(tiltswitchPin, INPUT);
}

// ************
// *** LOOP ***
// ************

void loop() {

  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval) {
    
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;

    if (led == 7) {
      // Congratulations, you stood still for 10 seconds
    }

  }

  switchState = digitalRead(tiltswitchPin);

  if (switchState != prevSwitchState) {
    
    // turn LEDs off
    for (int x = 2; x < 8; x++) {
      digitalWrite(x, LOW);
    }

    // reset
    led = 2;
    previousTime = currentTime;

  }
  
  prevSwitchState = switchState;
  
}
