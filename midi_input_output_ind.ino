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
  
  switch (pitch)
  {
      case 48:
      voltage = 1500;
      break;
      case 49:
      voltage = 1532;
      break;
      case 50:
      voltage = 1596;
      break;
      case 51:
      voltage = 1628;
      break;
      case 52:
      voltage = 1660;
      break;
      case 53:
      voltage = 1692;
      break;
      case 54:
      voltage = 1724;
      break;
      case 55:
      voltage = 1756;
      break;
      case 56:
      voltage = 1788;
      break;
      case 57:
      voltage = 1820;
      break;
      case 58:
      voltage = 1852;
      break;
      case 59:
      voltage = 1884;
      break;
      case 60:
      voltage = 1916;
      break;
      case 61:
      voltage = 1948;
      break;
      case 62:
      voltage = 1980;
      break;
      case 63:
      voltage = 2012;
      break;
      case 64:
      voltage = 2044;
      break;
      case 65:
      voltage = 2076;
      break;
      case 66:
      voltage = 2108;
      break;
      case 67:
      voltage = 2140;
      break;
      case 68:
      voltage = 2172;
      break;
      case 69:
      voltage = 2204;
      break;
      case 70:
      voltage = 2236;
      break;
      case 71:
      voltage = 2268;
      break;
      case 72:
      voltage = 2300;
      break;
      case 73:
      voltage = 2332;
      break;
      case 74:
      voltage = 2364;
      break;
      case 75:
      voltage = 2396;
      break;
      case 76:
      voltage = 2428;
      break;
      case 77:
      voltage = 2460;
      break;
      case 78:
      voltage = 2492;
      break;
      case 79:
      voltage = 2524;
      break;
      case 80:
      voltage = 2556;
      break;
      case 81:
      voltage = 2588;
      break;
      case 82:
      voltage = 2620;
      break;
      case 83:
      voltage = 2652;
      break;

     default:
      voltage = 0;    
  }

    dac.setVoltage( voltage , false);
  
}


void HandleNoteOff(byte channel, byte pitch, byte velocity) 
{
  dac.setVoltage(0, false);
}

void setup() 
{
  pinMode(13, OUTPUT); 

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
