void setup(){
  for (int i=4; i<12; i++){
    pinMode(i, OUTPUT);
  }//end for
}//end setup

void loop(){
  for (int i=4; i<12; i++){
    for (int b = 0; b < 256; b++){
      analogWrite(i,b);
      delay(2);
    }//end for
    for (int b = 255; b >=0; b--){
      analogWrite(i,b);
      delay(2);
    }//end for 
    delay(100);
  }//end for
}//end loop
