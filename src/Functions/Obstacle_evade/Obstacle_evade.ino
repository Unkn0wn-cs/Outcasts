#include <Pixy2.h>
#include <Servo.h>

Pixy2 pixy;
Servo myservo;

void setup() {
  pixy.init();
  myservo.attach(7);

}

void loop() {
//detect colour of the obstacle
  int i;
  int evade = 0;
  pixy.ccc.getBlocks();
    if (pixy.ccc.numBlocks){
      if (pixy.ccc.blocks[i].m_signature == 1)
  {
    Serial.print("Block 1\n");
    evade = 1;

  } else if (pixy.ccc.blocks[i].m_signature == 2){
    Serial.print("Block 2\n");
    evade = 2;
  }
  }else {
    //FOWARD (X)
  }

//evasion
  // rotate 45 

  //fw 

  //rotate 90

  //fw 

  //rotate 45 


}
