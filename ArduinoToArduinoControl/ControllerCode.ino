void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // Send strings to serial, these will be read and tell the controller what to do
  // Remember to put a \n so the peripheral knows when the string is over
Serial.write("on\n");
delay(1000);
Serial.write("off\n");
delay(1000);
}
