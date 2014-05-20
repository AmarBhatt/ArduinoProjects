int led1 = 22;

void setup(){
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
}//end setup

void loop(){
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  digitalWrite(led1, HIGH);
  delay(sensorValue);
  digitalWrite(led1,LOW);
  delay(sensorValue);
}//end loop
