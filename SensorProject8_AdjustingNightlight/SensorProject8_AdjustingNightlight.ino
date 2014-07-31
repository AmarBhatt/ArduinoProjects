/*
* Name: Light adjusting night light
*
* Description: Photoresistor sensor controls brightness
*              of LEDs
*
* Author: Amar Bhatt
*/

//NOTE: When there is light sensor is LOW, when it is not it is HIGH
//      Range: 0-1023


//Define Pins used
const int sensorPin = A0; //analog
const int led1 = 3; //PWM pin for brightness control
const int led2 = 5; //PWN pin for brightness control
const int led3 = 6; //PWM pin for brightness control

void setup () {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin (9600);
}
void loop () {
  int value = analogRead (sensorPin);
  //Serial.println (value, DEC);
  value = map(value, 150, 900, 0, 255); //map the low and the high
  value = constrain(value, 0, 255); //constrain any outliers
  //Serial.println(value);
  analogWrite(led1, value);
  analogWrite(led2, value);
  analogWrite(led3, value);
  delay (50);
}

