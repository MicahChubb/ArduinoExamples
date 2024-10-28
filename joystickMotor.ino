//Define input and output pins
const int stick = A0;
const int in1 = 8; //H bridge pin 1
const int in2 = 7; //H bridge pin 1

void setup() {
  //Set pin modes
  pinMode(stick, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}
//change
void loop() {
  //Read in value of joystick then map it to a range of 0 - 100
  int val = analogRead(stick);
  val = map(val, 0, 1024, 0, 100);

  if(val > 60){
    //Run motor forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }else if(val < 40){
    //Run motor backward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }else{
    //Turn off motor, this will be triggered when joystick is back in the neutral position (50ish)
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}
