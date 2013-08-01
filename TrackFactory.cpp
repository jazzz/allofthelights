

#include "TrackFactory.h"



   
TrackFactory::TrackFactory(uint16_t nPixels) {
	numPixels = nPixels;

}


  LightTrack* TrackFactory::createTrackFromId(uint8_t id){

  	switch(id){
  		case TRACK_TYPE_BULLET:
  			return createBulletTrack();
  			break;
  		case TRACK_TYPE_BLINKER:
  			return createBlinkerTrack();
  			break;
  		case TRACK_TYPE_COLORFILL:
  			return createColorFillTrack();
  			break;
  	}

  	return createBlinkerTrack();
  }

  Bullet* TrackFactory::createBulletTrack(){
      Bullet* b = new Bullet();
      b->init(numPixels,2);
  		return b;
  }

  Blinker* TrackFactory::createBlinkerTrack(){
      Blinker* b = new Blinker();
      b->init(numPixels);
  		return b;
  }
  ColorFill* TrackFactory::createColorFillTrack(){
      ColorFill* c = new ColorFill();
      c->init(numPixels);
  		return c;
  }



