/* Arduino Sensor Project
*
* Name: Infrared Obstacle Avoidance Sensor
*
* Description: Using an IR obstacle sensor, a stepper motor
*              switches direction and an led lights up when
*              an obstacle is detected. Interrupt is used to
*              read sensor asynchronously and act on the reading
*
* Author: Amar Bhatt
*
*/

//Notes: the EN pin on the sensor is active LOW
//       the OUTPUT is active LOW
//       if there is a jumper pin between the EN and VR1 
//          then EN does not need to be connected

//Include stepper motor library
#include <Stepper.h>

// Define Constants

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
                                     // for your motor
                                     
const int ledPin = 7; //Pin for the LED control
const int senPin = 2; //Pin for the sensor
volatile int dir = 1; //Direction, 1 = forward, -1 = backward

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11); 

void setup(){
  pinMode(ledPin, OUTPUT);
  attachInterrupt(0, switchDirection, CHANGE); //Set intterupt on change
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
}

void loop(){
  Serial.println("clockwise");
  myStepper.step(dir*stepsPerRevolution);
}

//Interrupt function
void switchDirection() {
  int reading = digitalRead(senPin);
  dir = (reading == HIGH) ? -1 : 1;
  digitalWrite(ledPin, !reading);
}
