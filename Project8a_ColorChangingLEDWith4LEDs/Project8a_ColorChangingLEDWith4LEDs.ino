
// pins for the LEDs:
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  for (int r = 0; r < 256; r+=51){
      analogWrite(redPin, r);
      
      for (int g = 0; g < 256; g+=51){
        analogWrite(greenPin, g);
        for (int b = 0; b < 256; b+=51){            
            analogWrite(bluePin, b);            
            Serial.print(r, DEC);
            Serial.print(" ");
            Serial.print(g, DEC);
            Serial.print(" ");
            Serial.println(b, DEC);
            delay(1000);
          }//end for
      }//end for
  }//end for
}

