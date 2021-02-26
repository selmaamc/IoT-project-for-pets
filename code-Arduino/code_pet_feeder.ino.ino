#include <Servo.h>
#include <IRremote.h>
int servoPin = 2;
int infrarougePin= 10;
int ledPin= 3;
int soundPin= 4;

IRrecv reception(infrarougePin);
decode_results resultat;
Servo myservo;
int pos = 0;
int melody = 262;
int noteDuration = 1000 / 4;

void setup()
{
  pinMode(soundPin, OUTPUT); 
  myservo.attach(servoPin);
  pinMode(ledPin, OUTPUT); 
  reception.enableIRIn();
  Serial.begin(9600);
}
void loop()
{
  if(reception.decode(&resultat)){
     if(resultat.value == 1033561079){
      tone(soundPin, melody, noteDuration);
      digitalWrite(ledPin, HIGH);
      myservo.writeMicroseconds(600);
      delay(2000);
      myservo.writeMicroseconds(1550);
      digitalWrite(ledPin, LOW);
      noTone(soundPin);
      delay(2000);
    }
    reception.resume();
  }
}
