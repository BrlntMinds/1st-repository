#include <MeMCore.h>
#include <Pixy2.h>

Pixy2 pixy;
Servo servo_2_1;
MePort port_2(2);

void setup() {
  pixy.init();
}

void loop() {
  pixy.ccc.getBlocks();
  servo_2_1.attach(port_2.pin1());

  if(pixy.ccc.numBlocks > 0){
    for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      // Get the block
      Block *block = &pixy.ccc.blocks[i];
      if (block->m_signature == 1) {
       servo_2_1.write(75);
      }
      if (block->m_signature == 2) {
       servo_2_1.write(25);
      }
    }  
  }else{

      servo_2_1.write(50);
  }
}
