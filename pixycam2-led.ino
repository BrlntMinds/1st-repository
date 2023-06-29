#include <MeMCore.h>
#include <Pixy2.h>

Pixy2 pixy;
MeRGBLed rgbled_1(2, 4);

void setup() {
  pixy.init();
}

void loop() {
  pixy.ccc.getBlocks();

  if(pixy.ccc.numBlocks > 0){
    for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      // Get the block
      Block *block = &pixy.ccc.blocks[i];
      if (block->m_signature == 1) {
       rgbled_1.setColor(0,  0,255,0);
       rgbled_1.show();
      }
      if (block->m_signature == 2) {
       rgbled_1.setColor(0,  255,0,0);
       rgbled_1.show();
      }
    }  
  }else{

      rgbled_1.setColor(0,  0,0,0);
      rgbled_1.show();
  }
}