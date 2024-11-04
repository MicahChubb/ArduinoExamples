/*  Test suite for testing an Arduino
 *  =================================
 *  POWER
 *  -----
 *  1. Plug in a 12v powersupply into the barrel jack
 *  2. Multimeter the 5v and GND pins, if you get anything higher than 5v +/- 0.5v, it is dead, throw out
 *  
 *  I/O PINS  
 *  --------
 *  1. Test an LED- every ~ pin, will fade on and off
 *  2. Test an LED on every digital pin
 *  3. Test an Audio sensor on every analog pin
 */
 
const int led1[] = {2,4,7,8,12,13}; //Digital Pin test
const int audio[] = {A0,A1,A2,A3,A4,A5}; //Analog Pin test
const int led2[] = {3,5,6,9,10,11}; //~ PWM pin

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 6; i++){
    pinMode(led1[i], OUTPUT);
    pinMode(audio[i], INPUT);
    pinMode(led2[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 6; i++){
    digitalWrite(led1[i], HIGH);
    fade(i);
    digitalWrite(led1[i], LOW);
    audioTest(i);
  } 
}
void audioTest(int pin){
  int val = analogRead(audio[pin]);
  char text[50];
  sprintf(text, "A%d: %d", pin, val);
  Serial.println(text);
}
void fade(int pin){
  int count = 0;
  while(count < 255){
    analogWrite(led2[pin], count);
    count += 10;
    delay(10);
  }
}
