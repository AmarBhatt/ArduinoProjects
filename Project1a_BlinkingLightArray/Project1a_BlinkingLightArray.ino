/*
  Name: Blinking Light Array
  Description: Turn a series of LEDs on and then off, repeatedly
                for some time delay that constantly gets smaller
  Author: Amar Bhatt
*/

//Define LED pins
int led1 = 13; 
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;
int X = 100; //Time delay
int flip = 0; //if 0 the leds are lit left to right, if 1 leds are lit right to left

//Setup
void setup(){
  // Initialize the leds s outputs
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
}// end setup

void loop(){
  //While there is a time delay turn off and on leds
  while (X != 0){    
    if (flip == 0){
      for (int i=8; i<13; i++){
        digitalWrite(i, HIGH);
        delay(X); //Time delay
        digitalWrite(i, LOW);
        delay(X);
      }//end for
      flip = 1;
    }//end if
    else{
       for (int i=13; i>8; i--){
        digitalWrite(i, HIGH);
        delay(X);// time delay
        digitalWrite(i, LOW);
        delay(X);
       }//end for
       flip = 0;
    }//end else
    
    X = X-10;
  }//end while
  
  if (X == 0){
    X = 100;
  }//end if
}//end loop
