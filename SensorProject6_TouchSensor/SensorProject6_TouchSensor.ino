/* Arduino Sensor Project
*
* Name: Touch Module
*
* Description: Using a touch sensor, sound an alarm
*              when the sensor is touched.  Used interrupts
*              to make sure that blinking led light array
*              is not paused when sensor is being read and
*              acted upon
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
  attachInterrupt(0, displayWarning, CHANGE); //interrupt on change
}

void loop (){
  ledsOff(); //Turn off all leds
  //Forward blink light array
   for(int i=redPin; i < greenPin + 1; i++) {
     ledsOff();
     digitalWrite(i, HIGH);
     delay(100);
   }
   //backward blink light array
   for(int i=greenPin; i > redPin - 1; i--) {
     ledsOff();
     digitalWrite(i, HIGH);
     delay(100);
   }
      
}

//Interrupt function
void displayWarning() { //Sound buzzer
  digitalWrite(buzzPin, digitalRead(sensorPin));
  //delayMicroseconds(10000);  //Works with Interrupts, however will pause the entire system
}

//Turn off LEDs
void ledsOff() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
}
