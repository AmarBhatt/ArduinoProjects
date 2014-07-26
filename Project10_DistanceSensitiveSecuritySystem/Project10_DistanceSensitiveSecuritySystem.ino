/*
/*
* Name: Distance Sensitive Security System
*
* Description: Using an Ultrasonic ping sensor, detecting the
*              the distance to an object for security purposes
* 
* Author: Amar Bhatt
*


LED:  Red - Too Close
      Yellow - Be Careful
      Green - You're Good
      
Buzzer: Too Close

*/

//Ultra Sonic Ping Sensor Variables
const int trigPin = 7;
const int echoPin = 8;
//LED Variables
const int redPin = 2;
const int yellowPin = 3;
const int greenPin = 4;
//Buzzer Pin
const int buzzPin = 5;
//Threshold
const int TooClose = 5;
const int OK = 10;
const int Good = 15;

//Initialize
void setup(){
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}//end setup

void loop (){
  //Variables for inches and centimeter conversion
  long inches, cent, duration;
  //Ensure clean pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  
  //Read Pulse Back
  duration = pulseIn(echoPin, HIGH);
  
  //convert to inches and cm
  inches = microsecondsToInches(duration);
  cent = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print(" in, ");
  Serial.print(cent);
  Serial.print(" cm");
  Serial.println();
  
  resetLEDs();
  
  if (inches <= TooClose){
    digitalWrite(redPin, HIGH);
    //BUZZER
    while (inches <= TooClose){
      digitalWrite(buzzPin, HIGH);
      delay(25);
      digitalWrite(buzzPin, LOW);
      delay(25);
      digitalWrite(buzzPin, HIGH);
      delay(25);
      digitalWrite(buzzPin, LOW);
      
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(5);
      digitalWrite(trigPin, LOW);
  
      //Read Pulse Back
      duration = pulseIn(echoPin, HIGH);
  
      //convert to inches and cm
      inches = microsecondsToInches(duration); 
      cent = microsecondsToCentimeters(duration);
  
      Serial.print(inches);
      Serial.print(" in, ");
      Serial.print(cent);
      Serial.print(" cm");
      Serial.println();     
    }//end while
  }//end if
  else if (inches <= OK){
    digitalWrite(yellowPin, HIGH);
  }//end else if
  else {
    digitalWrite(greenPin, HIGH);
  }//end else
  
  delay(100);
}//end loop

void resetLEDs(){
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
}//end resetLEDs
long microsecondsToInches(long microseconds){
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  return microseconds / 73.746 / 2;
}//end microsecondsToInches

long microsecondsToCentimeters(long microseconds){
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
