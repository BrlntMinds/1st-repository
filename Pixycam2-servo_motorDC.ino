#include <MeMCore.h>
#include <Pixy2.h>

Pixy2 pixy;
Servo servo_2_1;
MePort port_2(2);
MeDCMotor motor_9(9);
MeDCMotor motor_10(10);

void move(int direction, int speed) {
  int leftSpeed = 0;
  int rightSpeed = 0;
  if(direction == 1) {
    leftSpeed = speed;
    rightSpeed = speed;
  } else if(direction == 2) {
    leftSpeed = -speed;
    rightSpeed = -speed;
  } else if(direction == 3) {
    leftSpeed = -speed;
    rightSpeed = speed;
  } else if(direction == 4) {
    leftSpeed = speed;
    rightSpeed = -speed;
  }
  motor_9.run((9) == M1 ? -(leftSpeed) : (leftSpeed));
  motor_10.run((10) == M1 ? -(rightSpeed) : (rightSpeed));
}

void setup() {
  pixy.init();
}

void loop() {
  pixy.ccc.getBlocks();
  servo_2_1.attach(port_2.pin1());

  move(1, 50 / 100.0 * 255);

  if(pixy.ccc.numBlocks > 0){
    for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      // Get the block
      Block *block = &pixy.ccc.blocks[i];
      if (block->m_signature == 2) {
       servo_2_1.write(75);
      }
      if (block->m_signature == 1) {
       servo_2_1.write(25);
      }
    }  
  }else{

      servo_2_1.write(50);
  }
}