/*
* Name: No Delay LED Control with Debouncing
*
* Description: Using debouncing (checking an input twice in a short time interval)
*              a button is pushed to change the state of an led
* 
* Author: Amar Bhatt
*
*/

// Define constants
const int led1 = 8; //LED
const int led2 = 9; // LED
const int button = 13; //Tactile Switch
int buttonState = 0;
int lastButtonState = 0;
int pressCount = 0;

long lastDebounceTime = 0;
long debounceDelay = 50;

void setup(){
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button,INPUT);
}//end setup

void loop(){  
  int reading = digitalRead(button); //read state of button
  
  // Make sure the currentButton state isnt the same as the last
  if (reading != lastButtonState){      
     lastDebounceTime = millis();
  }//end if
  //If this a new input then add one to the press count
  if ((millis() - lastDebounceTime) > debounceDelay){
    if (reading != buttonState){
      buttonState = reading;
      if (buttonState == HIGH){
        pressCount += 1;
      }//end if
    }//end if
  }//end if
  lastButtonState = reading;
  Serial.print("pressCount = ");
  Serial.println(pressCount);
  ledOn(pressCount); //Control LED
  
}//end loop

void ledOn (int count){
  if (count == 1){//Button prrssed once
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }//end if
  else if (count == 2){//Button pressed twice
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }//end else if
  else if (count == 3){//Button pressed three times
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }//end else if
  else {//button pressed four times
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    pressCount = 0; //reset count
  }//end else
}//end ledOn

