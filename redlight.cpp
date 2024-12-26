#include "SK6812.h"

#define NUM_LEDS 119
#define DATA_PIN 4
#define HEARTBEAT_PIN A0
#define THRESHOLD 550

SK6812 strip(NUM_LEDS);

void setup() {
  strip.set_output(DATA_PIN);

  // Initialize all LEDs to off
  RGBW black = {0, 0, 0, 0};
  for (uint16_t i = 0; i < NUM_LEDS; i++) {
    strip.set_rgbw(i, black);
  }
  strip.sync();
  Serial.begin(9600);
}

void loop() {
  int signal = analogRead(HEARTBEAT_PIN);

  if (signal > THRESHOLD) {
    // Set all LEDs to red when a heartbeat is detected
    RGBW red = {0, 255, 0, 0};
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
      strip.set_rgbw(i, red);
    }
    strip.sync();
  } else {
    // Set LEDs to a dim red when no heartbeat is detected
    RGBW dimRed = {0, 50, 0, 0};
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
      strip.set_rgbw(i, dimRed);
    }
    strip.sync();
  }

  delay(50); // Small delay for stability
}
