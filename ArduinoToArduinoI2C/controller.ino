/*
  Based off of:
  I2C Master Demo
  i2c-master-demo.ino
  Demonstrate use of I2C bus
  Master sends character and gets reply from Slave
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Include Arduino Wire library for I2C
#include <Wire.h>

// Define peripheral I2C Address
#define PERPH_ADDR 9

// Define peripheral answer size
#define ANSWERSIZE 6

void setup() {

  // Initialize I2C communications as controller
  Wire.begin();
  
  // Setup serial monitor
  Serial.begin(9600);
  Serial.println("I2C controller Demonstration");
}

void loop() {
  delay(200);
  Serial.println("Write data to peripheral");
  
  
    
  Serial.println("Receive data");
  
  // Read response from peripheral
  // Read back 6 characters
  Wire.requestFrom(PERPH_ADDR,ANSWERSIZE);
  
  // Add characters to string
  String response = "";
  while (Wire.available()) {
      char b = Wire.read();
      response += b;
  } 
  
  // Print to Serial Monitor
  Serial.println(response);

  // Write a charater to the peripheral
  // This is how we will control an output on the peripheral device
  Wire.beginTransmission(PERPH_ADDR);
  if(response == "event1"){
    Wire.write(1);
  }else if(response == "event0"){
    Wire.write(0);
  }
  
  Wire.endTransmission();
}
