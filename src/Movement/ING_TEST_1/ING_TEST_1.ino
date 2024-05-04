#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;  

void setup() {
  // put your setup code here, to run once:
 pinMode(1, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(11, OUTPUT);

   myservo.attach(6);  // attaches the servo on pin 9 to the servo object
myservo.write(90);              // tell servo to go to position in variable 'pos'

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

    myservo.write(120);
  delay (5000);

  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);

      myservo.write(60); 
    delay (5000);
}
