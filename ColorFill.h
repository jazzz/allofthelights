#ifndef COLOR_FILL_H
#define COLOR_FILL_H

#include <Arduino.h>
#include "LightTrack.h"

class ColorFill : public LightTrack {

 public:

  // Constructor:
  ColorFill();
  void init(uint16_t numPixels);

  void draw(uint32_t* buf);

   void onMidiNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
   void onMidiNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
   void onMidiControlChange(uint8_t channel, uint8_t control, uint8_t value);

  //   show(void),
  //   setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b),
  //   setPixelColor(uint16_t n, uint32_t c),
  //   setBrightness(uint8_t);
  // uint16_t
  //   numPixels(void);
  // static uint32_t
  //   Color(uint8_t r, uint8_t g, uint8_t b);
  // uint32_t
  //   getPixelColor(uint16_t n);

 private:
    uint32_t tick;
    uint16_t numPixels;
    int32_t index;
    uint32_t color;

    float jogScalingFactor; 
	float dx ;								// BUFFER OVERFLOW
	float dx_step;

};
  

#endif //