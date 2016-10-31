/*
 * light_ws2812 example
 *
 * Created: 07.03.2014 12:49:30
 *  Author: Matthias Riegler
 */ 

#include <WS2812.h>
#define LED_NUM 100

WS2812 LED(LED_NUM); // 1 LED

int a=0;
  
cRGB value;

void setup() {
  LED.setOutput(6); // Digital Pin 9
  //************Reset all LEDs*****************
  value.b = 0; value.g = 0; value.r = 0;
  for(int i=0; i<LED_NUM; i++){
    LED.set_crgb_at(i,value);
  }
  //*******************************************
}

void loop() {
for(int i=0; i<LED_NUM; i++){
  value.b = 255; value.g = 0; value.r = 255; // RGB Value -> Blue
  LED.set_crgb_at(i, value); // Set value at LED found at index 0
  LED.sync(); // Sends the value to the LED
  delay(0); // Wait 500 ms
  
  value.b = 255; value.g = 0; value.r = 0; // RGB Value -> Red
  LED.set_crgb_at(i, value); // Set value at LED found at index 0
  LED.sync(); // Sends the value to the LED
  delay(0); // Wait 500 ms
}
}
