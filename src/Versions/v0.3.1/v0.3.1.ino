#include <Servo.h>

Servo myservo;
// Ultrasomnic Trigonometry
const int trigPin1 = 53;
const int echoPin1 = 51;
const int trigPin2 = 22;
const int echoPin2 = 24;

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
    myservo.attach(40);  // attaches the servo on pin 9 to the servo object


  //Pins -----------------------------------------------------------------------
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  //
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  analogWrite(10, 100);
  analogWrite(11, 100);

}

void loop() {
//Fw-----------------
  fw();

  delay(1000);
  
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
  if (left > 80 && left < 150 ){
    rr(500, 105);
  } else if (right > 80 && right < 150){
    rl(500, 75);
  } else if (left > 149 && left < 400){
    rr(750, 120);
  } else if (right > 149 && right < 400){
    rl(750, 60);
  } else   if (left > 80 && left < 150 ){
    rr(500, 105);
  } else if (right > 80 && right < 150){
    rl(500, 75);
  } else if (left > 149 && left < 400){
    rr(750, 120);
  } else if (right > 149 && right < 400){
    rl(750, 60);
  } 

}

void rr(int i, int d){
  highen();

  myservo.write(120);              


  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);

  delay (i);
}

void rl(int i, int d){
  highen();

  myservo.write(60);              

  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);

  delay (i);
}

void fw(){
  analogWrite(10, 165);
  analogWrite(11, 165);  
  
  myservo.write(93); 

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);

}

void highen (){
  analogWrite(10, 175);
  analogWrite(11, 175);
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}