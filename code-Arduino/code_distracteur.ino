#include <Servo.h>
#include <IRremote.h>
IRrecv reception(2);
decode_results resultat;
Servo myservo;
Servo myservo2;
int pos = 0;
int laserPin = 13;
void setup()
{
  myservo.attach(9);
  myservo2.attach(10);
  pinMode(laserPin, OUTPUT); 
  reception.enableIRIn();
  Serial.begin(9600);
}
void loop()
{
  if(reception.decode(&resultat)){
    //etape 1 (Serial.println(resultat.value))
    Serial.println(resultat.value);
    if(resultat.value == 3238126971){
      digitalWrite(laserPin, HIGH);
    }
        if(resultat.value == 2534850111){
      digitalWrite(laserPin, LOW);
    }
     if(resultat.value == 1033561079){
      myservo.writeMicroseconds(600);
      delay(2000);
      myservo.writeMicroseconds(1375);
      delay(2000);
    }
         if(resultat.value == 1635910171){
      myservo2.writeMicroseconds(600);
      delay(2000);
      myservo2.writeMicroseconds(1375);
      delay(2000);
    }
    reception.resume();
  }

  

}
