/*
* Name: Infrared Reciever
*
* Description: Using an IR reciever, read an input and designate
*              what output will be active
*
* Author: Amar Bhatt
*/

//Inclide IR library
#include <IRremote.h>

//Define constants for output pins
const int redOutput = 2;
const int greenOutput = 3;
const int blueOutput = 4;
const int whiteOutput = 5;
const int buzzerOutput = 6;

//Toggle variables for outputs
int rVal = LOW;
int bVal = LOW;
int gVal = LOW;
int wVal = LOW;

// Pin reciever is on
int RECV_PIN = 11;

// New IR reciever object
IRrecv irrecv(RECV_PIN);

// IR reciever input decoder
decode_results results;

//Initialize
void setup()
{
  pinMode(redOutput, OUTPUT);
  pinMode(greenOutput, OUTPUT);
  pinMode(blueOutput, OUTPUT);
  pinMode(whiteOutput, OUTPUT);
  pinMode(buzzerOutput, OUTPUT);
  Serial.begin(9600);
  Serial.println("Start Recieve");
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    //Serial.println(results.value);
    
    //Read input
    switch (results.value){
      case 2576:
        digitalWrite(redOutput, !rVal);
        rVal = !rVal;
        break;
      case 2592:
        digitalWrite(greenOutput, !gVal);
        gVal = !gVal;
        break;
      case 2608:
        digitalWrite(blueOutput, !bVal);
        bVal = !bVal;
        break;
      case 2624:
        digitalWrite(whiteOutput, !wVal);
        wVal = !wVal;
        break;
      case 2640:
        digitalWrite(buzzerOutput, HIGH);
        delay(500);
        digitalWrite(buzzerOutput, LOW);
        break;
      default:
       Serial.println("Invalid Input");
       Serial.println(results.value);
    }
    
    Serial.println(results.value, HEX);
    delay(250);
    irrecv.resume(); // Receive the next value
  }
}
