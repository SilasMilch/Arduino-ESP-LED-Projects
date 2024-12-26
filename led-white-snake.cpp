#include <FastLED.h>

#define NUM_LEDS 30      // Number of LEDs in the strip
#define DATA_PIN 4       // Data pin that the strip is connected to
#define BRIGHTNESS 150   // Maximum brightness of the LEDs
CRGB leds[NUM_LEDS];     // Array of LED color objects

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS); // Set initial brightness
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) { // Move light forward
    leds[i] = CRGB::White; // Set current LED to white
    FastLED.show();
    delay(30);
    leds[i] = CRGB::Black; // Turn off LED after showing
  }

  for (int i = NUM_LEDS - 1; i >= 0; i--) { // Move light backward
    leds[i] = CRGB::White; // Set current LED to white
    FastLED.show();
    delay(30);
    leds[i] = CRGB::Black; // Turn off LED after showing
  }
}
