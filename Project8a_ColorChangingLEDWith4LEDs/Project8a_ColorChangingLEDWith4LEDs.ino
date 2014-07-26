/*
* Name: Color Changing LED with 4 LEDs
*
* Description: Using an RGB led, with red, green, and blue leds
*              I changed the color, and represented the color in the
*              RGB led witht the red, green, and blue leds
* 
* Author: Amar Bhatt
*/

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
  //Loop red
  for (int r = 0; r < 256; r+=51){
      analogWrite(redPin, r);
      //Loop green
      for (int g = 0; g < 256; g+=51){
        analogWrite(greenPin, g);
        //Loop blue
        for (int b = 0; b < 256; b+=51){            
            analogWrite(bluePin, b);
            //Print values            
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

