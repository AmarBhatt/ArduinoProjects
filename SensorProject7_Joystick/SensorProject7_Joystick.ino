/*
* 3D Joystick
*
* Description: Using a PS2 Joystick sensor, X, Y, and Z positions
*              control various features.  
*              X axis controls position of a servo motor
*              Y axis controls speed of a stepper motor
*              Z axis controls a set of LEDs
*              
*
* Author: Amar Bhatt
*
*/

//Libraries
#include <Stepper.h>
#include <Servo.h>


// Define constants
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
                                     // for your motor
const int zPin = 3; //Z-axis is read digitally
const int yPin = A1; //Y-axis is read with analog
const int xPin = A0; //X-axis is read with analog
const int ledPin = 7; //Pin for the 3 LEDs (connected in parallel)

//NOTE: The Z-axis is active low, also it requires a
//      pull-up resistor to account for noise


//Define variables
volatile int val = LOW; //Value of the z-axis reading

// initialize the stepper library on pins 10 through 13:
Stepper myStepper(stepsPerRevolution, 9, 11, 12, 13); 
// create servo object to control a servo
Servo myservo;  

void setup(){
  pinMode(ledPin, OUTPUT);
  attachInterrupt(1, ledToggle, RISING); //Z axis is connected to an interrupt pin 3
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  int x = analogRead(xPin); //Read X positon
  int y = analogRead(yPin); //Read Y position
  
  x = map(x, 0, 1023, 0, 179); //Map to proper servo angles
  myservo.write(x); //Position servo

  y = map(y, 0, 1023, 20, 60); //Map to proper speed
  myStepper.setSpeed(y); //Set speed
  myStepper.step(stepsPerRevolution); //Move stepper motor  
}

/*
* ledToggle()
*
* Interrupt function that turns on and off LEDs when the z position goes from low to high
*/
void ledToggle() {
 val = !val; //Toggle current value
 digitalWrite(ledPin, val); // Write to LEDs
}
