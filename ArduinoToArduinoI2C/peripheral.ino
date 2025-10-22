/*
  Based off of:
  I2C Slave Demo
  i2c-slave-demo.ino
  Demonstrate use of I2C bus
  Slave receives character from Master and responds
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Include Arduino Wire library for I2C
#include <Wire.h>

// Define Peripheral I2C Address
const int PERPH_ADDR = 9;

// Define Peripheral answer size
const int ANSWERSIZE = 6;

// Define string with response to controller
String answer;

// State of button press
bool on = false;

void setup() {

  // Initialize I2C communications as Peripheral
  Wire.begin(PERPH_ADDR);
  
  // Function to run when data requested from controller
  Wire.onRequest(outputEvent); 
  
  // Function to run when data received from controller
  Wire.onReceive(inputEvent);
  
  // Setup Serial Monitor 
  Serial.begin(9600);
  Serial.println("I2C Peripheral Demonstration");

  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
}

void inputEvent() {

  // Read while data received
  while (0 < Wire.available()) {
    byte x = Wire.read();
    if(x == 1){
      digitalWrite(13, HIGH);
    }else{
      digitalWrite(13, LOW);
    }
  }
  
  // Print to Serial Monitor
  Serial.println("Input event");
}

void outputEvent() {

  // Setup byte variable in the correct size
  byte response[ANSWERSIZE];
  
  if(on){
    answer = "event1";
  }else{
    answer = "event0";
  }

  // Format answer as array
  for (byte i=0;i<ANSWERSIZE;i++) {
    response[i] = (byte)answer.charAt(i);
  }
  
  // Send response back to controller
  Wire.write(response,sizeof(response));
  
  // Print to Serial Monitor
  Serial.println("Output event");
}

void loop() {
  if(digitalRead(7) == HIGH){
    on = true;
  }else{
    on = false;
  }
  // Time delay in loop
  delay(200);
}
