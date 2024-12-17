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

// Function to convert HSL to RGB
uint16_t HSL(float h, float s, float l)
{
  float c = (1.0 - abs(2.0 * l - 1.0)) * s;             // Chroma
  float x = c * (1.0 - abs(fmod(h / 60.0, 2.0) - 1.0)); // Intermediate value
  float m = l - c / 2.0;

  float r1, g1, b1;

  if (h >= 0 && h < 60)
  {
    r1 = c;
    g1 = x;
    b1 = 0;
  }
  else if (h >= 60 && h < 120)
  {
    r1 = x;
    g1 = c;
    b1 = 0;
  }
  else if (h >= 120 && h < 180)
  {
    r1 = 0;
    g1 = c;
    b1 = x;
  }
  else if (h >= 180 && h < 240)
  {
    r1 = 0;
    g1 = x;
    b1 = c;
  }
  else if (h >= 240 && h < 300)
  {
    r1 = x;
    g1 = 0;
    b1 = c;
  }
  else
  {
    r1 = c;
    g1 = 0;
    b1 = x;
  }

  return matrix.Color((r1 + m) * 255, (g1 + m) * 255, (b1 + m) * 255);
}

void setup()
{
  matrix.begin();
  matrix.show(); // Initialize all pixels to 'off'
  matrix.setBrightness(50);

  // matrix.drawPixel(1, 0, matrix.Color(255, 128, 0));
  // matrix.show();
}

int c = 0;

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

  // for (int i = 0; i < 8; i++)
  // {
  //   matrix.clear();
  //   matrix.drawCircle(0, 0, i, matrix.Color(255, 128, 0));
  //   matrix.drawCircle(7, 7, i, matrix.Color(128, 128, 0));
  //   matrix.drawCircle(0, 7, i, matrix.Color(0, 128, 255));
  //   matrix.drawCircle(7, 0, i, matrix.Color(255, 0, 255));
  //   matrix.show();
  //   delay(100);
  // }

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      // matrix.clear();
      matrix.drawPixel(j, i, HSL(((i + j + c) * (360 / (7 + 7))) % 360, 1, 0.5)); // rgb
      // matrix.drawPixel(j, i, matrix.ColorHSV(((i * j) * 4) * (65535 / 255))); // rgb
      // matrix.drawPixel(j, i, matrix.ColorHSV((65535 / 64) * (i*8 + j), 255, 255)); //
      // matrix.drawPixel(j, i, matrix.Color(random(0, 255), random(0, 255), random(0, 255))); // random
    }
  }

  matrix.show();
  delay(50);

  c = c - 1 % 360;
  if (c < 0)
    c = 360;
}