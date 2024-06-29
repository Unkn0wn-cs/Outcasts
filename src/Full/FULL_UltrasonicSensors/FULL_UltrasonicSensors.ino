#include <QuadratureEncoder.h>


#include <Servo.h>

Servo myservo;
// Ultrasomnic Trigonometry
const int trigPin1 = 10;
const int echoPin1 = 9;
const int trigPin2 = 13;
const int echoPin2 = 12;

//Funtions ------------------------------------------------------------------
  void fw();
  void rr();
  void rl();
  void highen();

void setup() {
  // Pins, Ultrasonic sensors, servos
  //Ultrasonic ----------------------------------------------------------------
    Serial.begin(9600);
    pinMode(trigPin1,OUTPUT);
    pinMode(echoPin1,INPUT);
    pinMode(trigPin2,OUTPUT);
    pinMode(echoPin2,INPUT);

  //Servos -------------------------------------------------------------------
    myservo.attach(7);  // attaches the servo on pin 9 to the servo object


  //Pins -----------------------------------------------------------------------
  pinMode(53, OUTPUT);
  pinMode(51, OUTPUT);
  //
  pinMode(49, OUTPUT);
}

void loop() {
//Fw-----------------
  fw();

  delay(3500);
  digitalWrite(51, LOW);
  digitalWrite(53, LOW);
  delay(2000);
//Ultrasonic detection -----------------------------------------------------
    long dleft, dright, left, right;

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  dleft = pulseIn(echoPin1, HIGH);
  left = microsecondsToCentimeters(dleft);
  Serial.print(left);
  Serial.println(", ");

  delay(100);

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  dright = pulseIn(echoPin2, HIGH);
  right = microsecondsToCentimeters(dright);
  Serial.print(right);
  Serial.println();

  delay(100);

//Conditionals 
  if  (left > 149 && left < 400){
    rr(2500, 120);
  } else if (right > 149 && right < 400){
    rl(2500, 60);
  } else   if (left > 149 && left < 400){
    rr(2500, 120);
  } else if (right > 149 && right < 400){
    rl(2500, 60);
  } 

}

void rr(int t, int d){
  // highen();

  // myservo.write(135);              


  // digitalWrite(2, HIGH);
  // digitalWrite(3, LOW);
  // digitalWrite(4, LOW);
  // digitalWrite(5, HIGH);

  // delay (t);
}

void rl(int t, int d){
  // highen();

  // myservo.write(45);              

  // digitalWrite(2, LOW);
  // digitalWrite(3, HIGH);
  // digitalWrite(4, HIGH);
  // digitalWrite(5, LOW);

  // delay (t);
}

void fw(){
  analogWrite(49, 90);
  
  myservo.write(90); 

  digitalWrite(53, HIGH);
  digitalWrite(51, LOW);


}

void highen (){
  int i = 250;
  analogWrite(10, 255);
  analogWrite(11, 90);
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
