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
    String data = Serial3.readString();
    // Serial.println(data[0]);
  }
} 
