/*
Name: Analog Read Serial with Potentiometer
Project: 3
Author: Amar Bhatt
Description: Read potentiometer values using
              built in ATD (Analog to Digital) conversion
*/

void setup(){
  Serial.begin(9600); //9600 bits of data
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}//end setup

void loop(){
  int sensorValue = analogRead(A0); // Get analog read
  Serial.println(sensorValue, DEC); //Print Potentiometer value in Decimal
  float voltage = sensorValue*(5.0/1023.0); //calculate the voltage
  Serial.print("Voltage = ");
  Serial.println(voltage);
  if (sensorValue == 0){ //potentiometer towards VCC
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  }//end if
  else if (sensorValue == 1023){//potentiometer towards GND
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
  }//end else if
  else if (sensorValue == 511){//potentiometer in the middle
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
  }//end else if
  else{
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }//end else
  delay(1);
}//end loop
