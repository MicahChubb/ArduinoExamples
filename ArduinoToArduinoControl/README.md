# Arduino to Arduino Control
This code is a proof of concept for Arduino controlling another Arduino. The control Arduino will seen a string to the peripheral Arduino. The peripheral Arduino will read this string and either turn its LED on or off. It is basically a more advanced Blink sketch.

This was developed by combining:
- [My Arduino to Raspberry Pi repository](https://github.com/MicahChubb/ArduinoRaspberryPi)
- [Iotguider](https://iot-guider.com/arduino/serial-communication-between-two-arduino-boards/)

Dedicated to a very angy year 12 developer

## Pin Connections
| Control Arduino | Peripheral Arduino |
| --------------- | ------------------ |
| RX (0) | TX (1) |
| TX (1) | Rx (0) |
| GND | GND |
