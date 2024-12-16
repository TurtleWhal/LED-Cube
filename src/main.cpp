#include <Arduino.h>
#include "Adafruit_NeoPixel.h"
#include "Adafruit_GFX.h"
#include "Adafruit_NeoMatrix.h"

#define NUM_LEDS 64
#define PIN 1

// Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
                                               NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
                                                   NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
                                               NEO_GRB + NEO_KHZ800);

void setup()
{
  matrix.begin();
  matrix.show(); // Initialize all pixels to 'off'
  matrix.setBrightness(50);

  // matrix.drawPixel(1, 0, matrix.Color(255, 128, 0));
  // matrix.show();
}

// uint16_t i = 0;

void loop()
{
  // for (int i = 0; i < NUM_LEDS; i++) {
  //   strip.setPixelColor(i, strip.Color(255, 0, 0));
  //   strip.show();
  //   delay(50);
  // }
  // for (int i = 0; i < NUM_LEDS; i++) {
  //   strip.setPixelColor(i, strip.Color(0, 255, 0));
  //   strip.show();
  //   delay(50);
  // }
  // for (int i = 0; i < NUM_LEDS; i++) {
  //   strip.setPixelColor(i, strip.Color(0, 0, 255));
  //   strip.show();
  //   delay(50);
  // }

  // strip.rainbow(i);
  // strip.show();

  // i -= 1000;

  // delay(50);

  // for (int i = 0; i < 8; i++)
  // {
  //   matrix.clear();
  //   matrix.drawLine(0, 0, i, 7, matrix.Color(255, 128, 0));
  //   matrix.show();
  //   delay(100);
  // }

  for (int i = 0; i < 8; i++)
  {
    matrix.clear();
    matrix.drawCircle(0, 0, i, matrix.Color(255, 128, 0));
    matrix.show();
    delay(100);
  }
}