#include <Arduino.h>

void setup() { 
  Serial.begin(9600);
  Serial3.begin(9600);
}

void loop() { 
  if(Serial.available()) {
    Serial3.write(Serial.read());
  }
  
  if(Serial3.available()) {
    Serial.write(Serial3.read());
    Serial.println(Serial3.readString());
  }
} 
