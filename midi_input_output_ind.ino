///////////////////////////////////////////////////////////
//  midi_input_output.ino                                //
//  Example: MIDI input & MIDI output                    //
//  https://github.com/ddiakopoulos/hiduino              //
//  Last Updated: 17 December 2015                       //
///////////////////////////////////////////////////////////

#include <MIDI.h>
#include <Adafruit_MCP4725.h>

//input range for DAC is 0-4096
Adafruit_MCP4725 dac;

MIDI_CREATE_DEFAULT_INSTANCE();

const int ledPin = 13; 

uint32_t voltage = 0;
int baseVoltage = 1000;

void HandleNoteOn(byte channel, byte pitch, byte velocity) 
{ 
  
  voltage=32+32*pitch;
  dac.setVoltage( voltage , false);
  digitalWrite(ledPin, HIGH);
}


void HandleNoteOff(byte channel, byte pitch, byte velocity) 
{
  dac.setVoltage(0, false);
}

void setup() 
{
  pinMode(ledPin, OUTPUT); 

  // For Adafruit MCP4725A1 the address is 0x62 (default) or 0x63 (ADDR pin tied to VCC)
  // For MCP4725A0 the address is 0x60 or 0x61
  // For MCP4725A2 the address is 0x64 or 0x65
  dac.begin(0x60);
  dac.setVoltage(0, true);
  
  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.setHandleNoteOn(HandleNoteOn);
  MIDI.setHandleNoteOff(HandleNoteOff); 
}

void loop() 
{
  MIDI.read();
  digitalWrite(ledPin, LOW);

}
