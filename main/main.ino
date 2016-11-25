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
int mode = 0;
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

//used as input for RandomSeed
int unusedPin = 0;

void setup() {  
  Serial.begin(9600);

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(unusedPin));

  
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
  orange.b = 0; orange.g = 255; orange.r = 128;
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
  clearLCD();
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
        String substr = Str1.substring(1,3);
        int index = substr.toInt();
        char color = Str1[3];
        Serial.println(substr);
        Serial.println(index);
        Serial.println(color);
        if(color == 'r'){
          setColor(index, red);
        }else if(color == 'b'){
          setColor(index, blue);
        }else if(color == 'y'){
          setColor(index, yellow);
        }else if(color == 'p'){
          setColor(index, purple);
        }else if(color == 'w'){
          setColor(index, white);
        }else if(color == 'g'){
          Serial.println("green");
          setColor(index, green);
        }else if(color == 'o'){
          setColor(index, orange);
        }else if(color == 'c'){
          setColor(index, cyan);
        }else{
          setColor(index, pink);
        }
        clearLCD();
        Str1 = "";
      }else if(Str1[0] == '$'){
        if(Str1[1] == '2'){
          mode = 1;  
        }else{
          mode = 0;
        }
        clearLCD();
        Str1 = "";
      }else{
        int l = Str1.length();
        for(int i=0;i<l;i++){
          char a = Str1[i];
          Serial.println(a);
          if(a == 'a' || a == 'A'){
            lightLetter(A);
          }else if(a == 'b' || a == 'B'){
            lightLetter(B);
          }else if(a == 'c' || a == 'C'){
            lightLetter(C);
          }else if(a == 'd' || a == 'D'){
            lightLetter(D);
          }else if(a == 'e' || a == 'E'){
            lightLetter(E);
          }else if(a == 'f' || a == 'F'){
            lightLetter(F);
          }else if(a == 'g' || a == 'G'){
            lightLetter(G);
          }else if(a == 'h' || a == 'H'){
            lightLetter(H);
          }else if(a == 'i' || a == 'I'){
            lightLetter(I);
          }else if(a == 'j' || a == 'J'){
            lightLetter(J);
          }else if(a == 'k' || a == 'K'){
            lightLetter(K);
          }else if(a == 'l' || a == 'L'){
            lightLetter(L);
          }else if(a == 'm' || a == 'M'){
            lightLetter(M);
          }else if(a == 'n' || a == 'N'){
            lightLetter(N);
          }else if(a == 'o' || a == 'O'){
            lightLetter(O);
          }else if(a == 'p' || a == 'P'){
            lightLetter(P);
          }else if(a == 'q' || a == 'Q'){
            lightLetter(Q);
          }else if(a == 'r' || a == 'R'){
            lightLetter(R);
          }else if(a == 's' || a == 'S'){
            lightLetter(S);
          }else if(a == 't' || a == 'T'){
            lightLetter(T);
          }else if(a == 'u' || a == 'U'){
            lightLetter(U);
          }else if(a == 'v' || a == 'V'){
            lightLetter(V);
          }else if(a == 'w' || a == 'W'){
            lightLetter(W);
          }else if(a == 'x' || a == 'X'){
            lightLetter(X);
          }else if(a == 'y' || a == 'Y'){
            lightLetter(Y);
          }else if(a == 'z' || a == 'Z'){
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

//light all LEDs of a letter one after the other
void lightLetter(int letter[]){
  if(mode == 0){
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
  }else{
    lightLetterAllLEDs(letter);
  }
}

//light all leds of a letter at once
void lightLetterAllLEDs(int letter[]) {
  int s = 0;
  if(letter[3] == 0){
    s = 3;
  }else{
    s = 4;
  }
  for(int i=0; i<s; i++){
    int pos = letter[i];
    LED.set_crgb_at(pos,ledcolors[pos]);
  }
  LED.sync(); // Sends the value to the LED
  delay(3000); //wait 5 sec
  resetLEDs();
  delay(1000);
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


