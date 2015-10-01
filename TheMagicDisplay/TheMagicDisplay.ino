// include the library for the liquid crystal
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// LiquidCrystal(rs, enable, d4, d5, d6, d7) 
// rs: the number of the Arduino pin that is connected to the RS pin on the LCD 
// enable: the number of the Arduino pin that is connected to the enable pin on the LCD 
// d4, d5, d6, d7: the numbers of the Arduino pins that are connected to the corresponding data pins on the LCD. 
// the LCD will be controlled using only the four data lines (d4, d5, d6, d7). 

// set up a constant for the tilt switchPin
const int switchPin = 6;

// variable to hold the value of the switchPin
int switchState = 0;

// variable to hold previous value of the switchpin
int prevSwitchState = 0;

// a variable to choose which reply from the crystal ball
int reply;

void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2); // 16,2 = max
  // lcd.begin(cols, rows)
  // cols: the number of columns that the display has
  // rows: the number of rows that the display has 

  // set up the switch pin as an input
  pinMode(switchPin, INPUT);
}

void loop() {
  
  // Print a message to the LCD.
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 0);
  // print to the first line
  lcd.print("Frag das");
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  // print to the second line
  lcd.print("magische Display");
  
  // check the status of the switch
  switchState = digitalRead(switchPin);

  // compare the switchState to its previous state
  if (switchState != prevSwitchState) {
    // if the state has changed from HIGH to LOW
    // you know that the ball has been tilted from
    // one direction to the other
    if (switchState == LOW) {
      // randomly chose a reply
      reply = random(8);
      // clean up the screen before printing a new reply
      lcd.clear();
      // set the cursor to column 0, line 0
      lcd.setCursor(0, 0);
      // print some text
      lcd.print("Das Display sagt");
      // move the cursor to the second line
      lcd.setCursor(0, 1);
      // print prefix
      lcd.print("- ");

      // choose a saying to print baed on the value in reply
      switch (reply) {
        case 0:
          lcd.print("Ja");
          break;

        case 1:
          lcd.print("Wahrscheinlich");
          break;

        case 2:
          lcd.print("Sicher");
          break;

        case 3:
          lcd.print("Sieht gut aus");
          break;

        case 4:
          lcd.print("Unsicher");
          break;

        case 5:
          lcd.print("Frag nochmal");
          break;

        case 6:
          lcd.print("Zweifelhaft");
          break;

        case 7:
          lcd.print("Nein");
          break;
      }
      delay(5000);
      // clean up the screen
      lcd.clear();
    }
  }
  // save the current switch state as the last state
  prevSwitchState = switchState;

}

