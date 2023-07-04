#include <Arduino.h>

#define Pin14  14
#define Pin15  15
char character;

void setup() { 
  Serial.begin(9600);
  pinMode(Pin14, OUTPUT); 
  pinMode(Pin15, OUTPUT); 
}

void loop() { 
  if(Serial.available()) {
  character = Serial.read();
  
    if(character == 'a'){ digitalWrite(Pin14, HIGH);}
    if(character == 'b'){ digitalWrite(Pin14, LOW);} 
    if(character == 'c'){ digitalWrite(Pin15, HIGH);}
    if(character == 'd'){ digitalWrite(Pin15, LOW);}
  } 

} 