#ifndef TRACKFACTORY_H
#define TRACKFACTORY_H
/*--------------------------------------------------------------------

  --------------------------------------------------------------------*/


#include <Arduino.h>
#include "LightTrack.h"

#include "TrackTypeList.h"


#define NUM_TRACKS 8

class TrackFactory {

 public:

  // Constructor:
   
  TrackFactory(uint16_t numPixels);


  LightTrack* createTrackFromId(uint8_t id);
  Bullet* createBulletTrack();
  Blinker* createBlinkerTrack();
  ColorFill* createColorFillTrack();



 private:

    uint16_t numPixels;


};

#endif 