#include <Arduino.h>
#include "Adafruit_NeoPixel.h"

#define NUM_LEDS 64
#define PIN 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(50);
}

// uint16_t i = 0;

void loop()
{
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));
    strip.show();
    delay(50);
  }
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(0, 255, 0));
    strip.show();
    delay(50);
  }
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 255));
    strip.show();
    delay(50);
  }

  // strip.rainbow(i);
  strip.show();

  // i -= 1000;

  // delay(50);
}