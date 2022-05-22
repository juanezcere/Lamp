#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>

#define TOUCH_PIN     0
#define PIXEL_PIN     2
#define PIXEL_COUNT   14

Adafruit_NeoPixel led(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

uint8_t cycle = 0;
uint8_t red = 0;
uint8_t green = 0;
uint8_t blue = 0;

void setup(void) {
  Serial.begin(115200);
  EEPROM.begin(1);
  delay(100);
  Serial.println();
  delay(100);
  cycle = EEPROM.read(0);
  if (cycle > 29) {
    cycle = 0;
    EEPROM.write(0, cycle);
    EEPROM.commit();
  }
  led.begin();
}

void loop(void) {
  if (!digitalRead(TOUCH_PIN)) {
    cycle++;
    if (cycle > 29) {
      cycle = 0;
    }
    EEPROM.write(0, cycle);
    EEPROM.commit();
    delay(250);
  }
  switch (cycle) {
    case 0:
      //off
      red = 0;
      green = 0;
      blue = 0;
      break;
    case 1:
      //white 100%
      red = 255;
      green = 255;
      blue = 255;
      break;
    case 2:
      //white 75%
      red = 192;
      green = 192;
      blue = 192;
      break;
    case 3:
      //white 50%
      red = 127;
      green = 127;
      blue = 127;
      break;
    case 4:
      //white 25%
      red = 64;
      green = 64;
      blue = 64;
      break;
    case 5:
      //red 100%
      red = 255;
      green = 0;
      blue = 0;
      break;
    case 6:
      //red 75%
      red = 192;
      green = 0;
      blue = 0;
      break;
    case 7:
      //red 50%
      red = 127;
      green = 0;
      blue = 0;
      break;
    case 8:
      //red 25%
      red = 64;
      green = 0;
      blue = 0;
      break;
    case 9:
      //green 100%
      red = 0;
      green = 255;
      blue = 0;
      break;
    case 10:
      //green 75%
      red = 0;
      green = 192;
      blue = 0;
      break;
    case 11:
      //green 50%
      red = 0;
      green = 127;
      blue = 0;
      break;
    case 12:
      //green 25%
      red = 0;
      green = 64;
      blue = 0;
      break;
    case 13:
      //blue 100%
      red = 0;
      green = 0;
      blue = 255;
      break;
    case 14:
      //blue 75%
      red = 0;
      green = 0;
      blue = 192;
      break;
    case 15:
      //blue 50%
      red = 0;
      green = 0;
      blue = 127;
      break;
    case 16:
      //blue 25%
      red = 0;
      green = 0;
      blue = 64;
      break;
    case 17:
      //red + green 100%
      red = 255;
      green = 255;
      blue = 0;
      break;
    case 18:
      //red + green 75%
      red = 192;
      green = 192;
      blue = 0;
      break;
    case 19:
      //red + green 50%
      red = 127;
      green = 127;
      blue = 0;
      break;
    case 20:
      //red + green 25%
      red = 64;
      green = 64;
      blue = 0;
      break;
    case 21:
      //red + blue 100%
      red = 255;
      green = 0;
      blue = 255;
      break;
    case 22:
      //red + blue 75%
      red = 192;
      green = 0;
      blue = 192;
      break;
    case 23:
      //red + blue 50%
      red = 127;
      green = 0;
      blue = 127;
      break;
    case 24:
      //red + blue 25%
      red = 64;
      green = 0;
      blue = 64;
      break;
    case 25:
      //green + blue 100%
      red = 0;
      green = 255;
      blue = 255;
      break;
    case 26:
      //green + blue 75%
      red = 0;
      green = 192;
      blue = 192;
      break;
    case 27:
      //green + blue 50%
      red = 0;
      green = 127;
      blue = 127;
      break;
    case 28:
      //green + blue 25%
      red = 0;
      green = 64;
      blue = 64;
      break;
    case 29:
      //random
      red = random(256);
      green = random(256);
      blue = random(256);
      break;
  }
  for (uint8_t i = 0; i < led.numPixels(); i++) {
    led.setPixelColor(i, led.Color(red, green, blue));
    delay(10);
  }
  led.show();
  delay(250);
}
