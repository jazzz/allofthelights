
//#include "AOTL_util.h"
#include "Blinker.h"
#include "NeumarkMacros.h"



Blinker::Blinker(){

}

void Blinker::init(uint16_t pixels){

	//Serial.println("INIT BLINKER");
	// numPixels = pixels;
   numBlinkers = 1;
	 color = 0xFFFFFF;

}

void Blinker::draw(uint32_t* buf ){

//	Serial.println("G");

	// color = color & 0xFFFFFF; // Mask off top Byte
   uint16_t index = 0;
   for(int i = numBlinkers; i >0; --i){

    index = random(numPixels);
    // Serial.println(index,DEC);
	  buf[index] = color ;
   }

	// tick++;

}

void Blinker::onMidiNoteOn(uint8_t channel, uint8_t note, uint8_t velocity){
  	Serial.println("ENTER  NOTEON");
}
void Blinker::onMidiNoteOff(uint8_t channel, uint8_t note, uint8_t velocity){
  Serial.println("ENTER OFF");
}
void Blinker::onMidiControlChange(uint8_t channel, uint8_t control, uint8_t value){

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


    	else if( isJogWheel(control) ){
    		int8_t delta;
  			Serial.println("JOG");
  			delta =  (value > 63) ?  value - 128 : value;
  			//dx += delta * jogScalingFactor;
    	}

    	else if( isOutsideSlider(control) ) {
    		//dx_step = (value) ? (float(value) / 200) : 0;  // Scale between 1 and 0;
    	}
	}
    
 
}


