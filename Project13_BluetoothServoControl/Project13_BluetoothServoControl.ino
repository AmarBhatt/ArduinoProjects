/*
* Name: Bluetooth Servo Control
*
* Description: Controlling the position of a servo
*              by inputting a value through a bluetooth
*              connected device
*
* Author: Amar Bhatt
*/

// NOTE: your bluetooth module needs to be connected to the transmit and recieve pin on the arduino
//       that's it, it will then work just like serial and you can use all the serial commands to read
//       and write data

// Include servo library
#include <Servo.h>
 
Servo myservo;  // create servo object to control a servo
 
void setup(){  
 myservo.attach(9);  // attaches the servo on pin 9 to the servo object
 myservo.write(0);
 Serial.begin(9600); 
 Serial.println("Welcome to Servo Control"); 
 Serial.println("Type a value between 0 and 179 to control servo."); 
 Serial.println("Enjoy :)"); 
} 
 
void loop(){ 
 //if an input has been entered
 if (Serial.available()){ 
   int value = Serial.parseInt(); //get the int
   Serial.println(value);
   if (value > 180){ //I only used a 180 degree servo, also this checks for NaN
     Serial.println("Invalid Entry. Please Try Again.");
   }//end if
   else {
     myservo.write(value); //reposition servo to entered value
   }
   Serial.read(); //clears the buffer for the next loop
 }
}

