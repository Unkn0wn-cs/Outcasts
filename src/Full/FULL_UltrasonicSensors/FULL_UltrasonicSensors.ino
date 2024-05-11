
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
}

void loop() {
//Fw-----------------
  fw();

  delay(500);
  
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

  delay(1000);

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  dright = pulseIn(echoPin2, HIGH);
  right = microsecondsToCentimeters(dright);
  Serial.print(right);
  Serial.println();

  delay(1000);

//Conditionals 
  if (left > 80 && left < 500 ){
    rr();
  } else if (right > 80 && right < 500){
    rl();
  } 

}

void rr(){
  myservo.write(120);              
  delay(500);

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);

  delay (5000);
}

void rl(){
  myservo.write(60);              
  delay(500);

  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);

  delay (5000);
}

void fw(){  
  
  myservo.write(90); 
  delay(500);

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
