#include <Arduino.h>
#include <ICM_20948.h>

#include "Encoder.hpp"
//#include "IMU.hpp"

// Set up encoders.
void readLeftEncoder();
void readRightEncoder();
mtrn3100::Encoder l_encoder(18, 23, readLeftEncoder);
mtrn3100::Encoder r_encoder(19, 22, readRightEncoder);
void readLeftEncoder() { l_encoder.readEncoder(); }
void readRightEncoder() { r_encoder.readEncoder(); }

namespace encoder_odometry {
// Pose estimated from encoder odometry.
float x = 0;
float y = 0;
float h = 0;

// COMPLETE THIS BLOCK.
// Robot parameters.
float R = 23;  // mm.
float L = 65;  // mm.

// Last wheel positions.
float lastLPos = 0;
float lastRPos = 0;

void update() {
    const float leftValue = l_encoder.position;
    const float rightValue = r_encoder.position;

    Serial.print(leftValue);
    Serial.print(" ");
    Serial.print(rightValue);

    // COMPLETE THIS BLOCK.
    const float tL = leftValue - lastLPos;  // Change in left wheel position.
    const float tR = rightValue - lastRPos;  // Change in right wheel position.
    /*
    float sR = tR * R;
    float sL = tL * R;
    float ds = (sL + sR) / 2;
    float hL = sL / (L * 2);
    float hR = - hL;
    float dh = (hL + hR) / 2;
    x = x + ds * cos(h + dh/2);
    y = y + ds * sin(h + dh/2);
    h = h + dh;
    */
    x += (R * (tR + tL) / 2) * cos(h);
    y += (R * (tR + tL) / 2) * sin(h);
    h += (R * (tR - tL) / L);

    lastLPos = leftValue;
    lastRPos = rightValue;
}

}  // namespace encoder_odometry

void setup() {
    Serial.begin(115200);
    delay(100);
    //Wire.begin();  // This must be called before IMU::begin().

    //imu.begin();
    //imu.calibrateAcceleration();
    //while (imu.dataReady())
        //;
    //imu.reset();
}

void loop() {
    // This updates the pose estimated by encoder odometry.
    encoder_odometry::update();
    // TODO: Print encoder odometry results.
    
    //Serial.print(encoder_odometry::x);
    //Serial.print(" ");
    //Serial.print(encoder_odometry::y);
    //Serial.print(" ");
    //Serial.print(encoder_odometry::h);
    

    // This updates the pose estimated by IMU odometry.
    /*
    if (imu.dataReady()) {
        imu.read();
         //TODO: Print encoder odometry results.
         
        Serial.print(imu.posX());
        Serial.print(" ");
        Serial.print(imu.posY());
        Serial.print(" ");
        Serial.print(imu.posH());
        
    }
    */

    Serial.println();
}