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
    
    controllerTrackMappings[LEFT] = trackIndex;

    b = new Blinker();  
    b->init(numPixels, 2);
    addTrack(b);
    // controllerTrackMappings[RIGHT] = trackIndex;
    b = new Blinker();  
    b->init(numPixels, 3);
    trackIndex = addTrack(b);

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

int8_t LightTrackManager::addTrack(LightTrack* track, uint8_t trackId){
  Serial.print("Add Tack"); Serial.print(trackId,DEC);
  if( trackListing[trackId] == 1) { Serial.println("  FAIL ");return -1;}
  trackListing[trackId] = 1;
  tracks[trackId] = track;
  Serial.println("GOOD");
  return trackId;
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
    Serial.print("NoteOn: "); Serial.println(get_group(source), DEC); 
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
           globalOnMidiChange(channel,source,velocity);
         break;
   }
  

}

void LightTrackManager::onMidiNoteOff(uint8_t channel, uint8_t source, uint8_t velocity){
      Serial.print("NoteOff: "); Serial.println(get_group(source), DEC); 
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
          globalOnMidiChange(channel,source,velocity);
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
           globalOnMidiChange(channel,source,value);
         break;
   }
 }


void LightTrackManager::globalOnMidiChange(int8_t channel, uint8_t source, uint8_t value){

  if( channel == 1){
    Serial.print("GLOBAL Event "); Serial.println(source,DEC);
    if( source == DIAL_TRACK){
        int8_t delta = (value > 63) ?  value - 128 : value;
        trackSelectorValue += delta;
        trackSelectorValue = trackSelectorValue % NUM_TRACKS;
        Serial.print("TRack: "); Serial.println(trackSelectorValue,DEC);
    }
    
    else if( source == BUTTON_LOADTRACK_L && value == BUTTON_DOWN){
      if(trackListing[trackSelectorValue]){
       controllerTrackMappings[LEFT] = trackSelectorValue;
     }
    }else if( source == BUTTON_LOADTRACK_R && value == BUTTON_DOWN){
      Serial.println("LAOD R");
        if(trackListing[trackSelectorValue]){
            Serial.println("A");
          controllerTrackMappings[RIGHT] = trackSelectorValue;
        }
    }

    else if( source == BUTTON_PAGE && value == BUTTON_DOWN){
        if(trackListing[trackSelectorValue]){
          trackListing[trackSelectorValue] = 0;
          delete tracks[trackSelectorValue];
        }
        spawnNewBlinker(trackSelectorValue);
    }
 }

}

bool LightTrackManager::spawnNewBlinker(uint8_t trackId){
    Serial.println("SPAWN ENTER");
    Blinker* b = new Blinker();  
    b->init(numPixels, trackId);
    Serial.println("SPAWN LEAVE");
    return addTrack(b,trackId) == trackId;
}

