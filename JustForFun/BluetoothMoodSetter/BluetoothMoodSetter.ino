
const int red = 3;
const int green = 5;
const int blue = 6;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.println("Welcome to mood setter!");
  Serial.println("Enter R,O,Y,G,B,P,X,W or F to set the mood.");
}

void loop() {
  //if an input has been entered
 if (Serial.available()){ 
   char value = Serial.read(); //get the int
   Serial.println(value); 
 
   switch (value) {
     case 'R' || 'r':
       setRGB(200,0,0);
       break;
     case 'O' || 'o':
       setRGB(240,20,0);
       break;
     case 'Y' || 'y':
       setRGB(220,80,0);
       break;
     case 'G' || 'g':
       setRGB(0,200,0);
       break;
     case 'B' || 'b':
       setRGB(0,0,200);
       break;
     case 'P' || 'p':
       setRGB(240,0,70);
       break;
     case 'X' || 'x':
       setRGB(0,0,0);
       break;
     case 'W' || 'w':
       setRGB(200,200,200);
       break;
     case 'F' || 'f':
       for (int r = 0; r < 256; r+=51){
          analogWrite(red, r);
          //Loop green
          for (int g = 0; g < 256; g+=51){
            analogWrite(green, g);
            //Loop blue
            for (int b = 0; b < 256; b+=51){
                char value = Serial.read(); //get the int
                if (value == 'X') {
                  Serial.println(value);
                  setRGB(0,0,0);
                  return;
                }            
                analogWrite(blue, b);
                delay(1000);
              }//end for
          }//end for
      }//end for
       break;
     default:
       Serial.println("Only R,O,Y,G,B,P,X,W,F allowed");    
     
   } 
 }
}
 
void setRGB (int r, int g, int b) {
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}
 
