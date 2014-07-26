/*
* Name: Blinking LED with Potentiometer
*
* Description: Use potentiometer to set rate of blinkage
* 
* Author: Amar Bhatt
*
*/

//Define LED pin
int led1 = 22;
// Define potentiometer pin
int potPin = A0;

void setup(){
  pinMode(led1, OUTPUT); //Initialize LED pin as an output
  Serial.begin(9600);
}//end setup

void loop(){
  int sensorValue = analogRead(potPin); //Read the potentiometer for delay interval
  Serial.println(sensorValue);
  digitalWrite(led1, HIGH);
  delay(sensorValue); //Delay for blinking
  digitalWrite(led1,LOW);
  delay(sensorValue); //Delay for blinking
}//end loop
