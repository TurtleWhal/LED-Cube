#include <Arduino.h>

#include "Adafruit_NeoPixel.h"
#include "Adafruit_GFX.h"
#include "Adafruit_NeoMatrix.h"

#define NUM_LEDS 64
#define PIN 1

// Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

Adafruit_NeoMatrix frontDisp = Adafruit_NeoMatrix(8, 8, 1,
                                                  NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
                                                      NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
                                                  NEO_GRB + NEO_KHZ800);

Adafruit_NeoMatrix rightDisp = Adafruit_NeoMatrix(8, 8, 3,
                                                  NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
                                                      NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
                                                  NEO_GRB + NEO_KHZ800);

Adafruit_NeoMatrix leftDisp = Adafruit_NeoMatrix(8, 8, 13,
                                                 NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
                                                     NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
                                                 NEO_GRB + NEO_KHZ800);

Adafruit_NeoMatrix topDisp = Adafruit_NeoMatrix(8, 8, 15,
                                                NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
                                                    NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
                                                NEO_GRB + NEO_KHZ800);

// Front, Right, Left, Top
Adafruit_NeoMatrix *disps[] = {
    &frontDisp,
    &rightDisp,
    &leftDisp,
    &topDisp};

#define Color(r, g, b) disps[0]->Color(r, g, b)

// Function to convert HSL to RGB
uint16_t HSL(float h, float s, float l)
{
  h = fmod(h, 360.0);

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

  return Color((r1 + m) * 255, (g1 + m) * 255, (b1 + m) * 255);
}

void setup()
{
  // Serial.begin(115200);
  // Serial.println("Setup");

  for (int i = 0; i < 4; i++)
  {
    disps[i]->begin();
    disps[i]->setBrightness(50);
    disps[i]->show();
  }

  //* identify screens

  // disps[0].fillRect(0, 0, 8, 8, Color(255, 0, 0));
  // disps[0].show();

  // disps[1].fillRect(0, 0, 8, 8, Color(0, 255, 0));
  // disps[1].show();

  // disps[2].fillRect(0, 0, 8, 8, Color(0, 0, 255));
  // disps[2].show();

  // disps[3].fillRect(0, 0, 8, 8, Color(255, 0, 255));
  // disps[3].show();
}

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

  #include "designs/rainbow.h"
  // #include "designs/breathing.h"
  // #include "designs/rainbowborder.h"
}