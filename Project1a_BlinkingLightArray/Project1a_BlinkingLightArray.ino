/*
  Name: Blink
  Description: Turn an LED on and then off, repeatedly
                for some time delay
  Author: Amar Bhatt
*/

int led1 = 13; //LED is connected to Pin 13
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;
int X = 100; //Time delay
int flip = 0;

//Setup
void setup(){
  pinMode(led1,OUTPUT); //Initialize pin 13 for output
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
}// end setup

void loop(){ 
  while (X != 0){    
    if (flip == 0){
      for (int i=8; i<13; i++){
        digitalWrite(i, HIGH);
        delay(X);
        digitalWrite(i, LOW);
        delay(X);
      }//end for
      flip = 1;
    }//end if
    else{
       for (int i=13; i>8; i--){
        digitalWrite(i, HIGH);
        delay(X);
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
