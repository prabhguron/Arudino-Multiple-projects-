
const int switchPin = 8;
unsigned long previousTime = 0;
int swtichState = 0;
int prevSwtichState = 0;
int led = 2;
long interval = 600;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int x = 3; x < 8; x++){
    pinMode(x, OUTPUT);
    
  }
  pinMode(switchPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
    if(currentTime - previousTime > interval){
      previousTime = currentTime;
      digitalWrite(led,HIGH);
      led++;
        if(led ==7){
      }
    }
  swtichState = digitalRead(switchPin);
  if(swtichState != prevSwtichState){
    for(int x=2; x < 8; x++){
      delay(100);
      digitalWrite(x,LOW);
    }
    led = 2;
    previousTime = currentTime;
  }
  prevSwtichState = swtichState;
}
