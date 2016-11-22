/*
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 6
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 4
 * LCD D7 pin to digital pin 3
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */


#include <PS2Keyboard.h>
#include <LiquidCrystal.h>
#include <WS2812.h>
#define LED_NUM 100

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
const int DataPin = 8;
const int IRQpin =  2;
String Str1;
PS2Keyboard keyboard;
WS2812 LED(LED_NUM); // 100 LED

//****************COLOR DEFINITIONS*************
cRGB value;
cRGB red;
cRGB blue;
cRGB yellow;
cRGB purple;
cRGB white;
cRGB off;
cRGB green;
cRGB orange;
cRGB cyan;
cRGB pink;
cRGB colors[] = {red, blue, yellow, purple, white, green, orange, cyan, pink};
//***************LETTER DEFINITIONS**************

int A[] = {0,1,2,3};
int B[] = {4,5,6,7};
int C[] = {8,9,10,11};
int D[] = {12,13,14,15};
int E[] = {15,16,17,18};
int F[] = {19,20,21};
int G[] = {22,23,24,25};
int H[] = {26,27,28,29};
int I[] = {30,31,32,33};
int J[] = {34,35,36,37};
int K[] = {38,39,40};
int L[] = {41,42,43,44};
int M[] = {45,46,47,48};
int N[] = {49,50,51,52};
int O[] = {53,54,55,56};
int P[] = {57,58,59};
int Q[] = {60,61,62,63};
int R[] = {64,65,66,67};
int S[] = {68,69,70,71};
int T[] = {72,73,74,75};
int U[] = {76,77,78,79};
int V[] = {80,81,82};
int W[] = {83,84,85,86};
int X[] = {87,88,89,90};
int Y[] = {91,92,93,94};
int Z[] = {95,96,97,99};

//*************LED Colors

cRGB ledcolors[100];

void setup() {  
  Serial.begin(9600);
  LED.setOutput(10); // Digital Pin 10 
  //************Define Colors*******************
  red.b = 0; red.g = 255; red.r = 0;
  colors[0] = red;
  blue.b = 255; blue.g = 0; blue.r = 0;
  colors[1] = blue;
  yellow.b = 0; yellow.g = 255; yellow.r = 255;
  colors[2] = yellow;
  purple.b = 255; purple.g = 165; purple.r = 0;
  colors[3] = purple;
  white.b = 255; white.g = 255; white.r = 255;
  colors[4] = white;
  off.b = 0; off.g = 0; off.r = 0;
  green.b = 0; green.g = 0; green.r = 255;
  colors[5] = green;
  orange.b = 0; orange.g = 255; orange.r = 165;
  colors[6] = orange;
  cyan.b = 255; cyan.g = 0; cyan.r = 255;
  colors[7] = cyan;
  pink.b = 255; pink.g = 255; pink.r = 0;
  colors[8] = pink;
  //************Reset all LEDs & initialize colors*****************
  for(int i=0; i<100; i++){
    int color = random(0,8);
    ledcolors[i] = colors[color];
  }

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Stranger Lights!");
  delay(1000);
  keyboard.begin(DataPin, IRQpin, PS2Keymap_German);
  resetLEDs();
}

void loop() {
  if (keyboard.available()) {  
    // read the next key
    char c = keyboard.read();
    
    // check for some of the special keys
    if (c == PS2_ENTER) {
      if(Str1[0] == '#'){
        Serial.println(Str1[0]);
      }else{
        int l = Str1.length();
        for(int i=0;i<l;i++){
          char a = Str1[i];
          Serial.println(a);
          if(a == 'a'){
            lightLetter(A);
          }else if(a == 'b'){
            lightLetter(B);
          }else if(a == 'c'){
            lightLetter(C);
          }else if(a == 'd'){
            lightLetter(D);
          }else if(a == 'e'){
            lightLetter(E);
          }else if(a == 'f'){
            lightLetter(F);
          }else if(a == 'g'){
            lightLetter(G);
          }else if(a == 'h'){
            lightLetter(H);
          }else if(a == 'i'){
            lightLetter(I);
          }else if(a == 'j'){
            lightLetter(J);
          }else if(a == 'k'){
            lightLetter(K);
          }else if(a == 'l'){
            lightLetter(L);
          }else if(a == 'm'){
            lightLetter(M);
          }else if(a == 'n'){
            lightLetter(N);
          }else if(a == 'o'){
            lightLetter(O);
          }else if(a == 'p'){
            lightLetter(P);
          }else if(a == 'q'){
            lightLetter(Q);
          }else if(a == 'r'){
            lightLetter(R);
          }else if(a == 's'){
            lightLetter(S);
          }else if(a == 't'){
            lightLetter(T);
          }else if(a == 'u'){
            lightLetter(U);
          }else if(a == 'v'){
            lightLetter(V);
          }else if(a == 'w'){
            lightLetter(W);
          }else if(a == 'x'){
            lightLetter(X);
          }else if(a == 'y'){
            lightLetter(Y);
          }else if(a == 'z'){
            lightLetter(Z);
          }
        }
      }
      clearLCD();
      Str1 = "";
    } else if (c == PS2_ESC) {
      clearLCD();
      Str1 = "";
    } else if (c == PS2_DELETE) {
      clearLCD();
      int position = Str1.length();
      position -= 1;
      Str1.remove(position);
    } else {
      Str1 += c;
    }
  }
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):

  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(Str1);
}

void setColor(int led, cRGB color){
  ledcolors[led] = color;
}
  
void lightLetter(int letter[]){
  int s = 0;
  if(letter[3] == 0){
    s = 3;
  }else{
    s = 4;
  }
  for(int i=0; i<s; i++){
    int pos = letter[i];
    LED.set_crgb_at(pos,ledcolors[pos]);
    delay(1000); //wait 1 sec
    LED.sync(); // Sends the value to the LED
  }
  delay(3000); //wait 5 sec
  resetLEDs();
}

void resetLEDs(){
  value.b = 0; value.g = 0; value.r = 0;
  for(int i=0; i<100; i++){
    LED.set_crgb_at(i,value);
  }
  LED.sync();
}

void clearLCD() {
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("Stranger Lights!");
}


