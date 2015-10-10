// constants for switch and motor pins
const int switchPin = 2; // number of the switch pin
const int motorPin =  9; // number of the motor pin

int switchState = 0;  // variable for reading the switch's status

void setup() {
  // initialize the motor pin as an output:
  pinMode(motorPin, OUTPUT);
  // initialize the switch pin as an input:
  pinMode(switchPin, INPUT);
}

void loop() {
  // read the state of the switch value:
  switchState = digitalRead(switchPin);

  // check if the switch is pressed.
  if (switchState == HIGH) {
    // turn motor on:
    // digitalWrite(motorPin, HIGH); // simple on

//    for(int motorValue = 100 ; motorValue <= 255; motorValue +=5){
    for(int motorValue = 100 ; motorValue <= 200; motorValue +=5){
      analogWrite(motorPin, motorValue); 
      delay(300);      
    }
//    for(int motorValue = 255 ; motorValue >= 100; motorValue -=5){
    for(int motorValue = 200 ; motorValue <= 100; motorValue +=5){
      analogWrite(motorPin, motorValue); 
      delay(300);      
    }
    
  }
  else {
    // turn motor off:
    digitalWrite(motorPin, LOW);
  }
}
