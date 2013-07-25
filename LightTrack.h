#ifndef LIGHTTRACK_H
#define LIGHTTRACK_H

#include <Arduino.h>

class LightTrack {
public:

	virtual void draw(uint32_t* buf) = 0;

	virtual void onMidiNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) = 0;
   	virtual void onMidiNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) = 0;
   	virtual void onMidiControlChange(uint8_t channel, uint8_t control, uint8_t value) = 0;


};

#endif