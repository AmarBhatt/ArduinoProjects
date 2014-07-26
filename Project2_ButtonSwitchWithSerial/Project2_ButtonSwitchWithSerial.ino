/* Name: Digital Serial Reader
   Project: 2
   Author: Amar Bhatt
   Description: Create Serial Input on to Serial 
                 with Switch circuit
*/

int pushButton = 2; // Define pin button is on
void setup(){
  Serial.begin(9600); //9600 bits of data per second (Baud rate)
  pinMode(pushButton, INPUT); //Read Pin 2
}//end setup

void loop(){
   int sensorValue = digitalRead(pushButton); //Read button
   if (sensorValue == 1){
     Serial.println("LED on."); //print value, can also print digits
   }//end if
   else {
     Serial.println("LED off."); //print value
   }//end else
   delay(1); //delay reads
}//end loop
