#include "ColorFill.h"
#include "NeumarkMacros.h"



ColorFill::ColorFill(){

}

void ColorFill::init(uint16_t pixels){

	//Serial.println("INIT ColorFill");
	numPixels = pixels;
	color = random(2000);

}

void ColorFill::draw(uint32_t* buf ){

//	Serial.println("G");
	color = color & 0xFFFFFF; // Mask off top Byte

	
  for(int index = 0 ; index < numPixels; index++)
  {
	 buf[index] = color ;
	}

}

void ColorFill::onMidiNoteOn(uint8_t channel, uint8_t note, uint8_t velocity){

}
void ColorFill::onMidiNoteOff(uint8_t channel, uint8_t note, uint8_t velocity){

}
void ColorFill::onMidiControlChange(uint8_t channel, uint8_t control, uint8_t value){

Serial.println("ENTER");
	if( channel == 1 ) {
		if( isTrebleDial(control) )						//////// RGB Values
		{
			Serial.println("TREBLE0");
			color = color & 0x00FFFF ;
    		color |= (uint32_t(value) << 17 + LEFT);
    	}
    	else if ( isMidDial(control) )
    	{
    		color = color & 0xFF00FF;
    		color |= uint32_t(value) << 9;
    	}else if( isBassDial(control) )
    	{
    		color = color & 0xFFFF00;
    		color |= uint32_t(value) << 1;
    	}

	}
    
 
}


