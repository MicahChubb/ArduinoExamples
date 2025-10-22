This example has been reworked from the very helpful page from DroneBot Workshop, you can find their tutorial here: [I2C Communications Part 1 – Arduino to Arduino](https://dronebotworkshop.com/i2c-arduino-arduino/)

# Goal
We will be using a controller Arduino to make decisions and a peripheral Arduino to provide input (a button press) and somewhere to output the decision the controller makes (LED turning on)

# Setup
![Circuit diagram for I2C communication between 2 Arduinos)(https://github.com/MicahChubb/ArduinoExamples/blob/main/ArduinoToArduinoI2C/I2cArduinos.png)

| Peripheral Arduino | Controller Arduino |
| ------------- | ------------- |
| A4 (SDA) | A4 (SDA) |
| A5 (SCLK) | A5 (SCLK) |
| 7 (Button) | N/A |
