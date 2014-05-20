/*
Name: LED Fade Using PWM and Analog
Project: 4
Author: Amar Bhatt
Description: Fade two LED's opposite-wise
              using Analog values
*/
int brightness = 0;
int fade = 5;
void setup(){
  pinMode(8, OUTPUT); // Set PWM Pin 8 for output
  pinMode(9, OUTPUT); // Set PWM Pin 9 for output
}//end setup

void loop(){
  analogWrite(8, brightness); // Set LED1 to brighten positively
  analogWrite(9, 255 - brightness); // Set LED2 to brighten negatively
  
  brightness = brightness + fade; // Adjust brightness for next loop
  
  if ((brightness==0) || (brightness==255)){ // Fade toggle at extremes (0-255)
      fade = -fade;
  }//end if
  delay(15); //Delay to see fade
}//end loop
