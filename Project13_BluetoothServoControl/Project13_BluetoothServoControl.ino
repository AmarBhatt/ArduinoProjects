
#include <Servo.h>
 
Servo myservo;  // create servo object to control a servo
 
void setup(){  
 myservo.attach(9);  // attaches the servo on pin 9 to the servo object
 myservo.write(0);
 Serial.begin(9600); //note this may need to be changed to match your module 
 Serial.println("Welcome to Servo Control"); 
 Serial.println("Type a value between 0 and 179 to control servo."); 
 Serial.println("Enjoy :)"); 
} 
 
void loop(){ 
 
 if (Serial.available()){ 
   int value = Serial.parseInt();
   Serial.println(value);
   if (value > 180){
     Serial.println("Invalid Entry. Please Try Again.");
   }//end if
   else {
     myservo.write(value);
   }
   Serial.read();
 }
}

