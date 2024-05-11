
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;  


void setup() {

  pinMode(1, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(6, OUTPUT);
   myservo.attach(40);  // attaches the servo on pin 9 to the servo object


  // put your setup code here, to run once:
  myservo.write(90);              
delay(3000);
  myservo.write(120);              
delay(3000);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);

  delay (2500);

  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(8, LOW);

}

void loop(){}
