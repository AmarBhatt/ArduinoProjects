/*
Name: RGB LED With Potentiometers
Project: 13
Author: Amar Bhatt
Description: Modify the color of an RGB LED using 3 potentiometers for R, G, B values
*/

// Define analog pins for potentiometers
const int redPot = A0;
const int greenPot = A1;
const int bluePot = A2;
// Define pwm pins for RGB LED pins
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

void setup(){
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}//end setup

void loop(){
  //Multiple line solution
  //Read potentiometers
//  int r = analogRead(redPot); 
//  int g = analogRead(greenPot);
//  int b = analogRead(bluePot);
  // map analog values to pwm outputs
//  int r_map = map(r, 0,1023,0,255); 
//  int g_map = map(g, 0,1023,0,255);
//  int b_map = map(b, 0,1023,0,255);
  //Write as pwm to RGB pins
//  analogWrite(redPin, r_map);
//  analogWrite(greenPin, g_map);
//  analogWrite(bluePin, b_map);

  // One line solution (same as above)
  analogWrite(redPin, map(analogRead(redPot),0,1023,0,255));
  analogWrite(greenPin, map(analogRead(greenPot),0,1023,0,255));
  analogWrite(bluePin, map(analogRead(bluePot),0,1023,0,255));
}//end loop
