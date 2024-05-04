#include <Servo.h>

Servo myservo;


void setup() {
  myservo.attach(7);

  // put your setup code here, to run once:
 pinMode(1, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(11, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  //if no blocks detected on field 
  myservo.write(95);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

  delay(3500);

  myservo.write(120);              

  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);

  delay (1250); 
  
  for (int i = 3; i == 0; i--){
  
  myservo.write(95); 

  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

  delay(10000);

  myservo.write(120);              

  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);

  delay (1200);
  }

}
