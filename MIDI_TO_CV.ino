#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

uint32_t voltage = 5;

void setup(void) {
  Serial.begin(9600);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  
  // For Adafruit MCP4725A1 the address is 0x62 (default) or 0x63 (ADDR pin tied to VCC)
  // For MCP4725A0 the address is 0x60 or 0x61
  // For MCP4725A2 the address is 0x64 or 0x65
  dac.begin(0x60);
  dac.setVoltage(0, true);
}

void loop(void) {

  if(digitalRead(8) == HIGH)
  {
//    Serial.println("UP");
    if(voltage < 4000)
    voltage++;
    
      Serial.println(voltage);
  }
   else if(digitalRead(9) == HIGH)
  {
//    Serial.println("DOWN");
    if(voltage > 0)
    voltage--;
    
    Serial.println(voltage);
  }
 
  dac.setVoltage(voltage, false);

}
