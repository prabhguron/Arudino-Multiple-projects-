#include "SR04.h"

int trig_pin = 12;
int echo_pin = 11;
int pin = 2;

SR04 sensor = SR04(echo_pin, trig_pin);

long distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  delay(1000);

  pinMode(pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  distance = sensor.Distance();
  Serial.println(distance);
  delay(1000);
  if(distance < 10){
digitalWrite(pin, HIGH);
  }else{
    digitalWrite(pin, LOW);
  }

 

}
