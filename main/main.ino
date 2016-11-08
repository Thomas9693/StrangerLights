#include <WS2812.h>
#define LED_NUM 100

WS2812 LED(LED_NUM); // 100 LED

int a=0;

//****************COLOR DEFINITIONS*************
cRGB colors[] = {red, blue, yellow, purple, white, green, orange, cyan, pink};
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
  LED.setOutput(6); // Digital Pin 6
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
  resetLEDs();
  }
}

void loop() {
  LED.sync(); // Sends the value to the LED
}

void setColor(int led, cRGB color){
  LED.set_crgb_at(led, color);
}
  
void lightLetter(int[] letter){
  for(i=0; i<letter.length(); i++){
    LED.set_crgb_at(i,ledcolors[i]);
    delay(1000); //wait 1 sec
  }
  delay(5000); //wait 5 sec
}

void resetLEDs(){
  value.b = 0; value.g = 0; value.r = 0;
  for(int i=0; i<ledcolors.length(); i++){
    int color = random(0,colors.length()-1);
    ledcolors[i] = colors[color];
    LED.set_crgb_at(i,value);
  }
}


