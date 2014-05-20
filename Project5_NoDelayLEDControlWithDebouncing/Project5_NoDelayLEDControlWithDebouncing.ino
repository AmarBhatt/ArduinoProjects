const int led1 = 8;
const int led2 = 9;
const int button = 13;
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
  int reading = digitalRead(button);
  
  if (reading != lastButtonState){      
     lastDebounceTime = millis();
  }//end if
  
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
  ledOn(pressCount);
  
}//end loop

void ledOn (int count){
  if (count == 1){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }//end if
  else if (count == 2){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }//end else if
  else if (count == 3){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }//end else if
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    pressCount = 0;
  }//end else
}//end ledOn

