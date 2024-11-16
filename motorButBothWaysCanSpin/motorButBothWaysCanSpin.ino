const int  controlPin1=2;
const int  controlPin2=3;
const int enablePin=9;
const int directionSwitchPin=4;
const int onOffSwitchStateSwitchPin=5;
const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState=0;
int directionSwitchState =0;
int previousDirectionSwitchState =0;

int motorEnabled=0;
int motorSpeed=0;
int motorDirection = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(directionSwitchPin, INPUT); // make both buttons inputs
  pinMode(onOffSwitchStateSwitchPin, INPUT);

  pinMode(controlPin1, OUTPUT);// will be giving power to the motor
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);// read if the button is on
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);// read if the button is on
  motorSpeed = analogRead(potPin)/4;// set potentiometers speed

  if(onOffSwitchState != previousOnOffSwitchState){
    if(onOffSwitchState == HIGH){ // if the button is on 
     motorEnabled = !motorEnabled; // turn on or off motor 
    } // check if button is the same as before 
  }
    if(directionSwitchState != previousDirectionSwitchState){
      if(directionSwitchState == HIGH){
        motorDirection = !motorDirection;
      }
    }
  if(motorDirection == 1){
    digitalWrite(controlPin1, HIGH);// if the motor is one way spin one way 
    digitalWrite(controlPin2, LOW);
  }else{
    digitalWrite(controlPin1, LOW);// else spin it the other way
    digitalWrite(controlPin2, HIGH);

  }
  if(motorEnabled == 1){// if motor is on
    analogWrite(enablePin,motorSpeed);// set the speed to motorspeed
  } else{
    analogWrite(enablePin, 0);// turn the motor off
  }
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState; // save the previous states for loop
}

