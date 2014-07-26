/*
* Name: Infrared Transmitter
*
* Description: Using an IR transmitter led, send an input
*              based on a button press
*
* Author: Amar Bhatt
*/

// NOTE: An IR LED must be connected to Arduino PWM pin 3.

//Include IR library
#include <IRremote.h>

//define button inputs
const int redInput = 6;
const int greenInput = 5;
const int blueInput = 4;
const int whiteInput = 8;
const int buzzerInput = 2;
//value being sent
unsigned long sendVal = 0;

// New IR transmiter object
IRsend irsend;

//Initialize
void setup(){
  pinMode(redInput, INPUT);
  pinMode(greenInput, INPUT);
  pinMode(blueInput, INPUT);
  pinMode(whiteInput, INPUT);
  pinMode(buzzerInput, INPUT);
  Serial.begin(9600);
  Serial.println("Start Send");
}

void loop() { 
  //read button inputs
  sendVal = digitalRead(redInput) == HIGH ? 0xa10 : sendVal;
  sendVal = digitalRead(greenInput) == HIGH ? 0xa20 : sendVal;
  sendVal = digitalRead(blueInput) == HIGH ? 0xa30 : sendVal;
  sendVal = digitalRead(whiteInput) == HIGH ? 0xa40 : sendVal;
  sendVal = digitalRead(buzzerInput)== HIGH ? 0xa50 : sendVal;  
  //Serial.println(sendVal, HEX);
  
  //Send HEX value in bytes as defined by SONY
  // for SONY: input must be sent three times in 40 ms intervals
  if (sendVal != 0){
    Serial.println("Sending");
    for (int i = 0; i < 3; i++) {
      irsend.sendSony(sendVal, 12);
      delay(40);
    }
  }
  Serial.println(sendVal);
  sendVal = 0; //reset send value
}
