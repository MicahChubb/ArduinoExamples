#include <SD.h>
#include <DFRobot_DS1307.h>

DFRobot_DS1307 RTC;

File myFile;
const int CSPin = 10;

const int cellPin = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("Initialising SD card...");

  pinMode(CSPin, OUTPUT);
  pinMode(cellPin, INPUT);

  if(!SD.begin(CSPin)){
    Serial.println("Initialisation failed!");
    return;
  }
  Serial.println("Initialisation done.");

  while(!(RTC.begin())){
    Serial.println("Communication with RTC failed");
    delay(3000);
  }
  RTC.setSqwPinMode(RTC.eSquareWave_1Hz);
}

void loop() {
  // Calling write out function, sending it the output of our solar read function
  writeOut(solarRead());
  delay(2000); // Placeholder time offset, should move to basing it off time read to RTC (every hour or so)
}

// Simple solar read function, converts to mV value
float solarRead(){
  float raw = analogRead(cellPin);
  float V = (float)raw * 5 / 1023;
  float mV = V * 1000;
  Serial.println(mV);
  return mV;
}

// Adjusted to get one data point in, you can add more data as you add more sensors
void writeOut(float solar){
  myFile = SD.open("plantLog.txt", FILE_WRITE);

  if(myFile){
    Serial.println("Trying to write!");

    // Timestamp
    uint16_t getTimeBuff[7] = {0};
    RTC.getTime(getTimeBuff);
    char outputarr[128];
                      //8/5/2025,10:7:26,
    sprintf(outputarr, "%d/%d/%d,%d:%d:%d,", 
                        getTimeBuff[6],
                        getTimeBuff[5],
                        getTimeBuff[4],
                        getTimeBuff[2],
                        getTimeBuff[1],
                        getTimeBuff[0]);
    Serial.print(outputarr);
    myFile.print(outputarr);

    // Sensors - Add each sensor, make sure there is a , after each piece of sensor data
    // I've added a , so you can chuck your next piece of data under, like I have commented out
    Serial.print(solar);
    myFile.print(solar);
    Serial.print(",");
    myFile.print(",");
    //e.g
    //Serial.print(temp);
    //myFile.print(temp);

    
    //New Line - Adds a new line after all your sensor data is written
    Serial.println();
    myFile.println();

    myFile.close();
    Serial.println("Finished.");
  } else{
    Serial.println("Error opening text file");
  }
}
