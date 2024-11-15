
const int switchPin = A0;
const int motorPin = 9;
int pot;
int speed;


void setup() {
  // put your setup code here, to run once:



}

void loop() {
  // put your main code here, to run repeatedly:
pot = analogRead(switchPin);
speed = map(pot, 0,1023, 0, 255);
analogWrite(motorPin, speed);
}
