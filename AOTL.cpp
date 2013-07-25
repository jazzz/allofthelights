#include "AOTL.h"
#include "NeumarkMacros.h"
LightTrackManager::LightTrackManager(uint16_t pixels) : tick(0) {
  numPixels = pixels;
  trackSelectorValue =0;

randomSeed(4);
  for(uint8_t i=0; i < NUM_TRACKS;i++){
    trackListing[i] = 0;
  }
  controllerTrackMappings[CENTER] = -1;
  controllerTrackMappings[LEFT] = -1;
  controllerTrackMappings[RIGHT] = -1;


    Blinker* b;
    int8_t trackIndex ;
    b = new Blinker();  
    b->init(numPixels, 1);
    addTrack(b);

    b = new Blinker();  
    b->init(numPixels, 2);
    addTrack(b);

    b = new Blinker();  
    b->init(numPixels, 3);
    addTrack(b);

    controllerTrackMappings[RIGHT] = trackIndex;


}

int8_t LightTrackManager::addTrack(LightTrack* track){
  for (int i =0; i < NUM_TRACKS;i++){
    if (0 == trackListing[i] ){
      trackListing[i] = 1;
      tracks[i] = track;
      return i;
    }
  }
  return -1;
}

// Set pixel color from 'packed' 32-bit RGB color:
void LightTrackManager::draw(uint32_t* buf){
  
  // blinkerR.draw(buf);
  // blinker->draw(buf);
  //buf[9] |= uint32_t(200) << 16;

  for(int trackIndex =0 ;trackIndex < NUM_TRACKS; trackIndex++){
    if(trackListing[trackIndex]){
       tracks[trackIndex]->draw(buf);
    }
  }
  tick++;

}

uint32_t LightTrackManager::getTick() {
  return tick;
}

void LightTrackManager::onMidiNoteOn(uint8_t channel, uint8_t source, uint8_t velocity){

   switch  ( get_group(source) ) {
     case LEFT:
        if(controllerTrackMappings[LEFT] >= 0){
           tracks[controllerTrackMappings[LEFT]]->onMidiNoteOn(channel,source,velocity);
         }
         break;
     case RIGHT:
          if(controllerTrackMappings[RIGHT] >= 0 ){  
           tracks[controllerTrackMappings[RIGHT]]->onMidiNoteOn(channel,source,velocity);
         }
         break;
     case CENTER:
          if(controllerTrackMappings[CENTER] >= 0){
           //globalOnMidiNoteOn(channel,source,velocity);
         }
         break;
   }
  

}

void LightTrackManager::onMidiNoteOff(uint8_t channel, uint8_t source, uint8_t velocity){
   switch  ( get_group(source) ) {
     case LEFT:
        if(controllerTrackMappings[LEFT])
           tracks[controllerTrackMappings[LEFT]]->onMidiNoteOff(channel,source,velocity);
         break;
     case RIGHT:
          if(controllerTrackMappings[RIGHT])
           tracks[controllerTrackMappings[RIGHT]]->onMidiNoteOff(channel,source,velocity);
         break;
     case CENTER:
          if(controllerTrackMappings[CENTER])
           tracks[controllerTrackMappings[CENTER]]->onMidiNoteOff(channel,source,velocity);
         break;
   }
  
}

void LightTrackManager::onMidiControlChange(uint8_t channel, uint8_t source, uint8_t value){
  Serial.print( "CONTROLSLSS "); Serial.println( get_group(source) , DEC);
     switch  ( get_group(source) ) {
     case LEFT:
        if(controllerTrackMappings[LEFT] >= 0){
           tracks[controllerTrackMappings[LEFT]]->onMidiControlChange(channel,source,value);
         }
         Serial.println();
         break;
     case RIGHT:
          if(controllerTrackMappings[RIGHT] >= 0){
           tracks[controllerTrackMappings[RIGHT]]->onMidiControlChange(channel,source,value);
         }
         break;
     case CENTER:
           globalOnMidiControlChange(channel,source,value);
         break;
   }
 }


void LightTrackManager::globalOnMidiControlChange(int8_t channel, uint8_t source, uint8_t value){

  if( channel == 1){
    if( source == DIAL_TRACK){
        int8_t delta = (value > 63) ?  value - 128 : value;
        trackSelectorValue += delta;
        trackSelectorValue = trackSelectorValue % NUM_TRACKS;
        Serial.print("TRack: "); Serial.println(trackSelectorValue,DEC);

    }
 }
}

