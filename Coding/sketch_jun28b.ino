#include <Pixy2.h>
#include <MeMCore.h>

Pixy2 pixy;
MeRGBLed rgbled_7(7, 2);

// Pin for the action (e.g., LED, motor, etc.)
const int actionPin = 13;

void setup() {
  pixy.init();
  
}

void loop() {
  pixy.ccc.getBlocks();
  
  if (pixy.ccc.numBlocks > 0) {
    // Iterate over all the blocks detected
    for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      // Get the block
      Block *block = &pixy.ccc.blocks[i];
      
      // Check if the block has the desired signature
      if (block->m_signature == 1) {  // Change the signature number as per your setup
        // Perform the desired action
        rgbled_7.setColor(2,100,0,0);
        rgbled_7.show();
        delay(1000);  // Wait for 1 second (adjust as needed)
        rgbled_7.setColor(2,0,0,0);
        rgbled_7.show();
        break;  // Exit the loop after performing the action for one block
      }
    }
  }
}
