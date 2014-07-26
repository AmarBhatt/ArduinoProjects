/*
* Name: Color Change with Serial
*
* Description: Input using the serial monitor to set an RGB led
* 
* Author: Amar Bhatt
*
 
 Circuit: Common-anode RGB LED wired like so:
 * Red cathode: digital pin 3
 * Green cathode: digital pin 5
 * blue cathode: digital pin 6
 * anode: Ground
 
 Reference: Tom Igoe
 
 */

// pins for the LEDs
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  // if there's any serial available, read it
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int red = Serial.parseInt();
    // do it again
    int green = Serial.parseInt();
    // do it again
    int blue = Serial.parseInt();

    // look for the newline. That's the end of your input
    if (Serial.read() == '\n') {
      // constrain the values read to 0 - 255 and invert
      red = constrain(red, 0, 255);
      green = constrain(green, 0, 255);
      blue = constrain(blue, 0, 255);

      // set the red, green, and blue legs of the LED:
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);

      // print the three numbers in one string as hexadecimal
      Serial.print(red, HEX);
      Serial.print(green, HEX);
      Serial.println(blue, HEX);
    }
  }
}

