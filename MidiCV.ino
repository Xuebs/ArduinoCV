#include <MIDI.h>

int OutVoltPin=11;

int Voltage=0;

MIDI_CREATE_DEFAULT_INSTANCE();

void HandleNoteOn(byte channel, byte pitch, byte velocity){ 
  double PITCH=(pitch-16)/(5588-16); //Based on https://en.wikipedia.org/wiki/Piano_key_frequencies The pitch should be between 16 and 5588
  Voltage=PITCH*1023;
  analogWrite(OutVoltPin,Voltage);
}

/* I don't know what this does
void HandleCC(byte channel, byte pitch, byte velocity){
  // Do something here with your data!
} */

void HandleNoteOff(byte channel, byte pitch, byte velocity){
  analogWrite(OutVoltPin,0);
}

void setup() {
  pinMode(OutVoltPin,OUTPUT);
  
  MIDI.setHandleNoteOn(HandleNoteOn); 
  // MIDI.setHandleControlChange(HandleCC);
  MIDI.setHandleNoteOff(HandleNoteOff);

}

void loop() {
  MIDI.read();
}
