#include<Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
int m,s,i,count=10,buzz_count=5;
const int startButtonPin = 1;
const int stopButtonPin = 9;
void setup() {
  
  lcd.begin(16, 2);
  
  pinMode(startButtonPin, INPUT);
  pinMode(stopButtonPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  while (digitalRead(startButtonPin) == LOW) {
    // Show "Press start button" on the LCD
    lcd.clear();   
    lcd.print("Press start");
    lcd.setCursor(0, 1);
    lcd.print("button.");
    delay(100);
  }
  
  // put your main code here, to run repeatedly:
  for(i=count;i>=0;i--){
    m=i/60;
    s=i%60;
    if(i!=0){
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("time up!!");
      while(buzz_count!=0){
        digitalWrite(LED_BUILTIN,LOW);
        buzz_count--;
        delay(1000);
      }
      digitalWrite(LED_BUILTIN,LOW );
   }
    lcd.clear();
    lcd.print("Time Remaining");
    if(i==0){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("time up!!");
      exit(0);
    }
    else if(digitalRead(stopButtonPin) == HIGH){
      lcd.clear();
      //lcd.setCursor(0, 0);
      lcd.print("forced stop");
      lcd.setCursor(0, 1);
      lcd.print("restart in 5 sec");
      digitalWrite(LED_BUILTIN,LOW);
      while(digitalRead(stopButtonPin) == HIGH){
        // Wait for stop button release
        delay(50);
      }
      delay(4000); // Wait for 1 second before restarting the countdown
      break; // Exit the countdown loop
    }
    else{

      
      lcd.setCursor(0,1);
      lcd.print(m);
      lcd.print(":");
      if(s>=10){
        lcd.print(s);
      }
      else{
        lcd.print("0");
        lcd.print(s);
      }
      delay(1000);
    }
  }
}
