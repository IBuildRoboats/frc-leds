#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN        6
#define NUMPIXELS 20

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 50

int stripeLen = 8;

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin();


  //Startup animation
  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
  }
  delay(500);

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();
  }
  delay(500);

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
  }
  delay(500);

  pixels.clear();

}

void loop() {
  

  fade();
  stripe();
  if(random(1, 20) == 9){
    rainbow();
  }
  

}

void stripe() {
  for(int i=0; i<NUMPIXELS + stripeLen; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 208, 255));
    pixels.setPixelColor(i - stripeLen, pixels.Color(0, 0, 0));
    pixels.show();
    delay(DELAYVAL);
  }
}

void fade() {
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 208, 255));
    pixels.show();
    delay(DELAYVAL);
  }

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    delay(DELAYVAL);
  }
}

void rainbow() {
    pixels.rainbow();
    pixels.show();
    delay(10000);
}