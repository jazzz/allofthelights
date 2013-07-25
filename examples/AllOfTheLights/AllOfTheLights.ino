#include <MIDI.h>
#include <AOTL.h>
#include <Adafruit_NeoPixel.h>

#define PIN 10

#define PIXEL_COUNT 220

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void printMidiSignal(String str, byte channel,byte note, byte velocity)
{
  Serial.print(str);
    Serial.print(" channel - " );
    Serial.print(channel, DEC);
    Serial.print(" Note - " );
    Serial.print( note, DEC);
    Serial.print(" Velo= " );
    Serial.print( velocity, DEC);
    Serial.println();
}

void printMidiSignal(String str, byte channel,byte val)
{
  Serial.print(str);
    Serial.print(" channel - " );
    Serial.print(channel, DEC);
    Serial.print(" Note - " );
    Serial.print( val, DEC);
    Serial.println();
}


unsigned long t=0;
int led = 11;
uint32_t blue =0;
LightTrackManager ltm = LightTrackManager(PIXEL_COUNT);


uint32_t buf[PIXEL_COUNT];

void OnNoteOn(byte channel, byte source, byte value){
//  printMidiSignal("Note", channel,note,velocity);
//  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
////  delay(1000);               // wait for a second
//  digitalWrite(led, LOW);
//  Serial.println(ltm.getTick(), DEC);
//  blue += 5;
//  Serial.println(blue,DEC);
  ltm.onMidiNoteOn(channel,source,value);
}

  void OnNoteOff(byte channel, byte note, byte velocity){
      printMidiSignal("Note", channel,note,velocity);
  }
  void OnVelocityChange(byte channel, byte note, byte velocity){
      printMidiSignal("Velo", channel,note,velocity);
  }
  void OnControlChange(byte channel, byte control, byte value){
      printMidiSignal("Control", channel,control,value);
      ltm.onMidiControlChange(channel,control,value);
  }
  void OnProgramChange(byte channel, byte program){
    printMidiSignal("Program", channel,program);
  }
  void OnAfterTouch(byte channel, byte pressure){
     printMidiSignal("Pressure", channel,pressure);
  }
  void OnPitchChange(byte channel, int pitch){
     printMidiSignal("Pitch", channel,pitch);
  }




void setup() {
  Serial.begin(9600); // USB is always 12 Mbit/sec
  
 usbMIDI.setHandleNoteOn(OnNoteOn);
   usbMIDI.setHandleNoteOff(OnNoteOff);
  usbMIDI.setHandleVelocityChange(OnVelocityChange);
  usbMIDI.setHandleControlChange(OnControlChange);
  usbMIDI.setHandleProgramChange(OnProgramChange);
  usbMIDI.setHandleAfterTouch(OnAfterTouch);
  usbMIDI.setHandlePitchChange(OnPitchChange);
   pinMode(led, OUTPUT);  
   
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
   
//   
 //buf = (uint32_t*)malloc(sizeof(uint32_t) * strip.numPixels());
//  for(int i =0; i < strip.numPixels(); i++)
//  {
//    buf[i] = 0;
//  }
}

void loop() {

    
    usbMIDI.read();
    //Serial.println("Lo");
    zeroBuf(buf);
     ltm.draw(buf);
    for(int i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i,buf[i]);
    }  
    strip.show();
}

void zeroBuf(uint32_t* buf){
  for(int i=0; i<strip.numPixels(); i++) {
      buf[i] = 0;
    }  
}
uint32_t Color(uint8_t r,uint8_t g,uint8_t b){
 uint32_t C= 0;
  C=C | uint32_t(r) << 16 | uint32_t(g) << 8 | uint32_t(b); 
  return C;
}
