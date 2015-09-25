/*
 * RainbowDash
 * 
 * utilises an RGB LED to show rainbow colours
 */
const int rPin = 9;  // red pin
const int gPin = 10; // green pin
const int bPin = 11; // blue pin

const int initialBlink = 500; // inital blink duration in ms

const int high = 255; // maximum value for analogWrite()

void setup() {
  // initialise and test red pin:
  pinMode(rPin, OUTPUT);
  analogWrite(rPin, high);
  delay(initialBlink);
  analogWrite(rPin,   0);
  // initialise and test green pin:
  pinMode(gPin, OUTPUT);
  analogWrite(gPin, high);
  delay(initialBlink);
  analogWrite(gPin,   0);
  // initialise and test blue pin:
  pinMode(bPin, OUTPUT);
  analogWrite(bPin, high);
  delay(initialBlink);
  analogWrite(bPin,   0);
  delay(initialBlink);
}

const int loopDelay = 10;
const int loopIncrement = 1;

int i = 0;

void loop() {
  if (i < (high + 1)) {
    // from red via yellow to green:
    int j = i;
    analogWrite(rPin, high - j);
    analogWrite(gPin,        j);
    analogWrite(bPin,        0);
    i += loopIncrement;
  } else if (i < 2 * (high +1)) {
    // from green via cyan to blue:
    int j = i - (high + 1);
    analogWrite(rPin,        0);
    analogWrite(gPin, high - j);
    analogWrite(bPin,        j);
    i += loopIncrement;
  } else if (i < 3 * (high + 1)) {
    // from blue via magenta to red:
    int j = i - 2 * (high + 1);
    analogWrite(rPin,        j);
    analogWrite(gPin,        0);
    analogWrite(bPin, high - j);
    i += loopIncrement;
  } else {
    i = 0;
  }
  delay(loopDelay);
}
