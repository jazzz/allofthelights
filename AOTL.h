#ifndef AOTL_H
#define AOTL_H
/*--------------------------------------------------------------------

  --------------------------------------------------------------------*/


#include <Arduino.h>
#include "LightTrack.h"
#include "Blinker.h"



// // 'type' flags for LED pixels (third parameter to constructor):
// #define NEO_RGB     0x00 // Wired for RGB data order


#define NUM_TRACKS 8

class LightTrackManager {

 public:

  // Constructor:
  LightTrackManager(uint16_t numPixels);

  uint32_t getTick();
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

    int8_t controllerTrackMappings[3];

    uint32_t tick;
    uint16_t numPixels;

    LightTrack* blinker;
    Blinker blinkerR;
    LightTrack* tracks[NUM_TRACKS];
    uint8_t trackListing[NUM_TRACKS];

    int8_t addTrack(LightTrack* track);
    void globalOnMidiControlChange(int8_t channel, uint8_t source, uint8_t value);

    uint8_t trackSelectorValue;

};

#endif 
