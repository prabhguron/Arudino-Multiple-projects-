#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

const int ButtonPin = 6; //what pin button is on
int switchState = 0; //to keep track of whether we pressed the button
int prevSwitchState =0; //to keep track of previous state
int reply; // what we will output to the lcd
void setup() {
  // put your setup code here, to run once:

  lcd.begin(16,2); // tell how large the screen should be
  pinMode(ButtonPin, INPUT); // have bttonPin an input to listen for changes
  lcd.print("Ask the");
  lcd.setCursor(0,1); //tell the lcd where to display text
  lcd.print("Crystal Ball!");

}

void loop() {
  // put your main code here, to run repeatedly:
 switchState = digitalRead(ButtonPin);// set the state to what switchPin is outputting right now;
 if(switchState != prevSwitchState){ // check if the two states are the same they wont be

  if(switchState == HIGH){// check if button is pressed if it is go inside the if statement
      reply = random(8);
      lcd.clear();

      lcd.setCursor(0,0);

      lcd.println("The ball says");

     lcd.setCursor(0,1);

switch (reply) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
    lcd.print("Yes");
    lcd.clear();
    lcd.print("take a shot ") +  lcd.print(reply );
    
  delay(5000);
  lcd.clear();
  lcd.print("Ask the");
  // set the cursor to column 0, line 1
  // line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);
  // print to the second line
  lcd.print("Crystal Ball!");

  break; 
  case 5:
  case 6:
  case 7:
  case 8:
  lcd.clear();
    lcd.print("No shot");
    break;
  
}// this tracks what to output for reply
  }     

 }
    prevSwitchState = switchState ;  
}
