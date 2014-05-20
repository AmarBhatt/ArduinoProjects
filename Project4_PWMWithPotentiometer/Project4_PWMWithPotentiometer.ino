/*
Name: LED Fade Using PWM and Potentiometer
Project: 4
Author: Amar Bhatt
Description: Read potentiometer values using
              built in ATD conversion, set LED brightness
              accordingly
*/

void setup(){
  Serial.begin(9600); //9600 bits of data
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}//end setup

void loop(){
  int brightness = analogRead(A0)/4; // Get analog read and divide by 4
  Serial.println(brightness, DEC);
  analogWrite(8, brightness);
  analogWrite(9, (1023/4)-brightness);
  delay(1);
}//end loop
