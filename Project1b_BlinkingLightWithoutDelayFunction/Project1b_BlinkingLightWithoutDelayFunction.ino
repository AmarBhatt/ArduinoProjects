/*
* Name: Blinking Light Without Delay Function
*
* Description: Use the millis() function to read the time to determine
*              if it has been some interval since the last action,
*              if so, toggle the led.
* 
* Author: Amar Bhatt
*
*/


const int ledPin =  13;      // the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);      
}

void loop(){

  //Get the current time in milliseconds
  unsigned long currentMillis = millis();
 
  //If the difference between the current and previous time is greater than the interval toggle the led
  if(currentMillis - previousMillis > interval) {
    // save the last time you toggled the LED
    previousMillis = currentMillis;  

    // if the LED is off turn it on and vice-versa
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable
    digitalWrite(ledPin, ledState);
  }
}
