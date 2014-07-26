/*
* Name: Fading Lights in a Line
*
* Description: Fading an array of LEDs
* 
* Author: Amar Bhatt
*
*/

void setup(){
  //initialize the led pins 4-11
  for (int i=4; i<12; i++){
    pinMode(i, OUTPUT);
  }//end for
}//end setup

void loop(){
  //Fade leds up
  for (int i=4; i<12; i++){
    for (int b = 0; b < 256; b++){
      analogWrite(i,b);
      delay(2);
    }//end for
    //Fade leds down
    for (int b = 255; b >=0; b--){
      analogWrite(i,b);
      delay(2);
    }//end for 
    delay(100);
  }//end for
}//end loop
