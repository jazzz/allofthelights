#include "Strobe.h"
#include "NeumarkMacros.h"



Strobe::Strobe(){

}

void Strobe::init(uint16_t pixels, uint16_t startingIndex){

	//Serial.println("INIT Strobe");
	numPixels = pixels;
	color = random(2000);

  // dt = 0;

}

void Strobe::draw(uint32_t* buf ){

//	Serial.println("G");
	color = color & 0xFFFFFF; // Mask off top Byte

	// index = (int(dx)+ numPixels) % numPixels;
	// dx += dx_step;

	// Serial.print(index,DEC );	Serial.print (" "); Serial.print(dx,DEC);  Serial.print(" ");  Serial.print(numPixels,DEC); 
	// buf[index] = color ;
	// Serial.println ("  DONE");
	tick++;
	// Serial.print(" DRAW "); Serial.print(color,HEX);Serial.print(" "); Serial.print(index,DEC); Serial.print(" ");Serial.println(dx,DEC);
	//index = index++ % numPixels;

}

void Strobe::onMidiNoteOn(uint8_t channel, uint8_t note, uint8_t velocity){
  	Serial.println("ENTER  NOTEON");
}
void Strobe::onMidiNoteOff(uint8_t channel, uint8_t note, uint8_t velocity){
  Serial.println("ENTER OFF");
}
void Strobe::onMidiControlChange(uint8_t channel, uint8_t control, uint8_t value){

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
  			// dx += delta * jogScalingFactor;
    	}

    	else if( isOutsideSlider(control) ) {
    		// dx_step = (value) ? (float(value) / 200) : 0;  // Scale between 1 and 0;
    	}
	}
    
 
}