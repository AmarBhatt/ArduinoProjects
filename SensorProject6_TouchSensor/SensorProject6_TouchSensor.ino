/* Arduino Sensor Project
*
* Name: Touch Module
*
* Author: Amar Bhatt
*
*/

//Define pins!
const int greenPin = 10;
const int yellowPin = 9;
const int redPin = 8;
int buzzPin = 13;
int sensorPin = 2; // Sensor pin attached to pin 2 (Interrupt)

void setup ()
{
  pinMode (buzzPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  attachInterrupt(0, displayWarning, CHANGE);
}

void loop ()
{
  ledsOff();
   for(int i=redPin; i < greenPin + 1; i++) {
     ledsOff();
     digitalWrite(i, HIGH);
     delay(100);
   }
   for(int i=greenPin; i > redPin - 1; i--) {
     ledsOff();
     digitalWrite(i, HIGH);
     delay(100);
   }
      
}

void displayWarning() {

  digitalWrite(buzzPin, digitalRead(sensorPin));
  //delayMicroseconds(10000);  //Works with Interrupts, however will pause the entire system
}

void ledsOff() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
}
