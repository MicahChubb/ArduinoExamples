/* This code is a proof of concept for Arduino controlling another Arduino
 * This is the PERIPHERAL code
 * 
 * This was developed by combining:
 * https://github.com/MicahChubb/ArduinoRaspberryPi
 * https://iot-guider.com/arduino/serial-communication-between-two-arduino-boards/
 * 
 * Dedicated to a very angy year 12 developer
 */
 
void setup() {
  // This baud rate needs to match on the two different Arduinos
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  // If the serial go brrrrr  
  if (Serial.available() > 0) {

    // Read the incomming string until we see the new line character
    // Our Controller code needs to send strings such as "this is a command\n"
    String data = Serial.readStringUntil('\n');
    Serial.println(data); //Print data on Serial Monitor

    // If our data says on, push the led high
    if(data == "on"){
      digitalWrite(LED_BUILTIN, HIGH);
      
    // Else, push it low
    }else if(data == "off"){
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
