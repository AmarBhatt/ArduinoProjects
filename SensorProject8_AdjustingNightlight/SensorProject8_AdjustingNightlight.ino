/*
* Name: Light adjusting night light
*
* Description: Photoresistor sensor controls brightness
*              of LEDs
*
* Author: Amar Bhatt
*/

//NOTE: When there is light sensor is LOW, when there is not it is HIGH
//      Range: 0-1023


//Define Pins used
const int sensorPin = A0; //Photoresistor sensor
const int ledPin = 6; //PWM pin for LEDs (connected in parallel)

void setup () {
  pinMode(ledPin, OUTPUT);
  Serial.begin (9600);
}
void loop () {
  int value = analogRead (sensorPin); //Get the brightness value as determined by the sensor
  //Serial.println (value, DEC);
  value = map(value, 400, 900, 0, 255); //map the low and the high
  value = constrain(value, 0, 255); //constrain any outliers
  Serial.println(value);
  analogWrite(ledPin, value);
  delay (50);
}

