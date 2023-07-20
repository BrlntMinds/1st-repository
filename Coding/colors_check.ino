#include <MeMCore.h>
#include <Pixy2.h>

Pixy2 pixy; //cámara delantera
Servo servo_2_1; //servo
MePort port_2(2);

void setup() {
  Serial.begin(9600);
  pixy.init();
}

void loop() {
  servo_2_1.attach(port_2.pin1());
  pixy.ccc.getBlocks();

  if (pixy.ccc.numBlocks > 0) {
    for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      // Get the block
      Block *block = &pixy.ccc.blocks[i];
      if (block->m_signature == 2) {
       servo_2_1.write(85);
      }
      if (block->m_signature == 1) {
       servo_2_1.write(15);
      } 
    } 
  } else {
        servo_2_1.write(55);
      }
}
