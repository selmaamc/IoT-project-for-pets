#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
int maximumRange = 30;
long duration, distance;
int counter=0;
bool count= true;
bool ishere=true;
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
void setup()
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
 
  if((counter > 5)&&(count==true)) {
      tone(9, 262, 2000);
       lcd.clear();
        lcd.setCursor(0, 0);
    lcd.print("The litter needs to");
            lcd.setCursor(0, 1);
    lcd.print("be CHANGED");
      delay(1000);
  }
  if ((distance <= maximumRange) &&(count==true) && (ishere==true))
    {
      tone(9, 220, 500);
      delay(100);
      noTone(9);
      counter=counter+1;
      Serial.println("counter=");
      Serial.println(counter);
      ishere=false;
    }
    else if (distance > maximumRange){
      ishere=true;
    }
  int sensorVal = digitalRead(2);
  if (sensorVal == LOW) {
    noTone(9);
    count=false;
    lcd.clear();
    }
  int sensorVal2 = digitalRead(1);
  if (sensorVal2 == LOW) {
    counter=0;
    count=true;
           lcd.clear();

    } 
    lcd.setCursor(0, 0);
    lcd.print("The cat was here");
    lcd.setCursor(0, 1);
    lcd.print(counter);
    lcd.print(" times");    
delay(50);
}
