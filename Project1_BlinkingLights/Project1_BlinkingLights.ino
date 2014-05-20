/*
  Name: Blink
  Description: Turn an LED on and then off, repeatedly
                for some time delay
  Author: Amar Bhatt
*/

int led1 = 13; //LED is connected to Pin 13
int X = 1000; //Time delay

//Setup
void setup(){
  pinMode(led1,OUTPUT); //Initialize pin 13 for output
}// end setup

void loop(){
  digitalWrite(led1, HIGH); //Turn on LED on pin 13
  delay(X); //wait for X ms
  digitalWrite(led1, LOW); //Turn off LED on pin 13
  delay(X); //wait for X ms
}//end loop
