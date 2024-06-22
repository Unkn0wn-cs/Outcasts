//6/22/24
// Ultrasonic sensing and Camera test
//New motors, pins, and driving mechanism
#include <Servo.h>
#include <Pixy2.h>

// This is the main Pixy object 
Pixy2 pixy;
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

  //PIXY
   Serial.begin(9600);
  Serial.print("Starting...\n");
  
  pixy.init();

  //Pins -----------------------------------------------------------------------
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  //
  pinMode(2, OUTPUT);
}

void loop() {
//Fw-----------------
  fw();
  delay(1250);
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

//Conditionals --------------------------------------------------------------------------------------------------------------------------------------
  if  (left > 149 && left < 400){
    rr(2500, 120);
  } else if (right > 149 && right < 400){
    rl(2500, 60);
  } else   if (left > 149 && left < 400){
    rr(2500, 120);
  } else if (right > 149 && right < 400){
    rl(2500, 60);
  }else {
        
  //Camara ------------------------------------------------------------------------------------------------------------------------------------------
        int i; 
  // grab blocks!
  pixy.ccc.getBlocks();
  
  // If there are detect blocks, print them!
  if (pixy.ccc.numBlocks){
      if (pixy.ccc.blocks[i].m_signature == 1)
  {
    Serial.print("Block 1\n");
    myservo.write(45);
    delay (1000);
    myservo.write(135);
    delay (700);
    myservo.write(90);
    

  } else if (pixy.ccc.blocks[i].m_signature == 2){
    Serial.print("Block 2\n");
    myservo.write(135);
    delay (1000);
    myservo.write(45);
    delay (700);
    myservo.write(90);
  }
  }
  }

}

void rr(int t, int d){


  myservo.write(135);              


  delay (t);
}

void rl(int t, int d){


  myservo.write(45);              


  delay (t);
}

void fw(){
  analogWrite(2, 135);
  
  myservo.write(90); 

  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);


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
