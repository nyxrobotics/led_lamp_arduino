
#include <Adafruit_NeoPixel.h>

#define PIN 13

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1
#define BRIGHTNESS 10
#define DELAY_MS 2000

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int turn_on_timer = 0;

void set_color(const uint8_t red, const uint8_t green, const uint8_t blue)
{
  for (size_t i = 0; i < NUMPIXELS; i++)
  {
    pixels.setPixelColor(i, red, green, blue);
  }
  pixels.show();  // This sends the updated pixel color to the hardware.
}

void setup()
{
  // initialize an LED output pin
  const int led_pin = PIN;
  pinMode(led_pin, OUTPUT);
  pixels.begin();  // This initializes the NeoPixel library.
  for (size_t i = 0; i < NUMPIXELS; i++)
    pixels.setPixelColor(i, 0, 0, 0);
  pixels.show();
}


void loop()
{
  if (turn_on_timer > DELAY_MS){
    set_color(BRIGHTNESS,BRIGHTNESS,BRIGHTNESS);
  }else{
    turn_on_timer++;
    uint16_t brightness = BRIGHTNESS * turn_on_timer / DELAY_MS;
    set_color(brightness,brightness,brightness);
  }
  delay(1);
}
