#include "pitches.h"

int notes[] = {NOTE_B0, NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1,NOTE_FS1, NOTE_G1, NOTE_GS1};
int s1 = 12;
int s3 = 13;
void setup(){
  Serial.begin(9600);
  for (int i = 2; i<12; i++){
    pinMode(i, INPUT);
  }
}

void loop(){
  for(int i = 2; i<12; i++){
    if(digitalRead(i) == 1){
      Serial.println(i);
      tone(s1, notes[i - 2],250);
    }
  }
}
