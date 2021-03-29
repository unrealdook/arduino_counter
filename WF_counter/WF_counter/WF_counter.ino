/*  The circuit:
  - pushbutton attached to pin 2 from +5V
  - 10 kilohm resistor attached to pin 2 from ground
*/
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int  buttonPin = 7;    // the pin that the pushbutton is attached to

int featherCounter = 0;   // counter for the number of button presses
int switchState = 0;         // current state of the button
int lastSwitchState = 0;     // previous state of the button

unsigned long ms = 0;
int h;
int m;
int s;
unsigned long over;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Count:");
  lcd.setCursor(0,1);
  lcd.print("Run Time:");

}



void loop() {
  timeResults();
  switchState = digitalRead(buttonPin);

  if (switchState != lastSwitchState) {
    if (switchState == HIGH) {
      featherCounter++;
    } else {

    }
    // Delay a little bit to avoid bouncing
    delay(50);
    
  }
  lastSwitchState = switchState;
  
  lcd.setCursor(7, 0);
  lcd.print(featherCounter);

}


void timeResults(){
  ms = millis();
  h=int(ms/3600000);
  over=ms%3600000;
  m=int(over/60000);
  over=over%60000;
  s=int(over/1000);

  lcd.setCursor(9,1);
  lcd.print(h);
  lcd.setCursor(10,1);
  lcd.print(":");
  lcd.setCursor(11,1);
  if (m < 10){
    lcd.print(0);
    lcd.setCursor(12,1);
    lcd.print(m);
  }
  else{
    lcd.print(m);
  }
  lcd.setCursor(13,1);
  lcd.print(":");
  lcd.setCursor(14,1);
    if (s < 10){
    lcd.print(0);
    lcd.setCursor(15,1);
    lcd.print(s);
  }
  else{
    lcd.print(s);
  }
}
