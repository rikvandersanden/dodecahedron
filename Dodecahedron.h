#ifdef ARDUINO
  #include "Arduino.h"
#else
  #include <cstdint>
#endif

#ifndef Dodecahedron_h
#define Dodecahedron_h

static const uint8_t EDGES = 30;
static const uint8_t VERTICES = 20;
static const uint8_t LEDS_PER_EDGE = 7;

// find a way to encode angles for LEDS for creating rotating patterns.
// Pre-define edges or vertices in static assy like Adafruit_NeoPixel does with leds?

#endif