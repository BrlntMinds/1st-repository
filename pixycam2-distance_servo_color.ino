#include <Pixy2.h>
#include <MeMCore.h>

#define DISTANCE_THRESHOLD 25 // Distance threshold in centimeters
#define TARGET_SIGNATURE 3    // Signature ID to detect

Pixy2 pixy;
Servo servo_2_1;
MePort port_2(2);
MeUltrasonicSensor ultrasonic_4(4); // Left sensor
MeUltrasonicSensor ultrasonic_3(3); // Right sensor
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
  Serial.begin(9600);
  pixy.init();
  pixy.setLamp(1,1);
}

void loop() {
  int pixyDistance = getPixyDistance(); // Get distance from the PixyCam2
  servo_2_1.attach(port_2.pin1());
  move(1, 90 / 100.0 * 255);
  pixy.ccc.getBlocks();

  if (pixyDistance < DISTANCE_THRESHOLD) {
    // Object detected within threshold distance
    int signature = getDetectedSignature(); // Get the signature ID of the detected object

    if (signature == TARGET_SIGNATURE) {
      // Detected the target object
      Serial.print("Target object detected! Pixy Distance: ");
      Serial.print(pixyDistance);
      Serial.println(" cm");
      
    if(ultrasonic_4.distanceCm() > ultrasonic_3.distanceCm()){

      servo_2_1.write(10);

  }else{

      servo_2_1.write(90);

  }
      
    } else {
      // Detected an object, but not the target
      Serial.print("Non-target object detected! Pixy Distance: ");
      Serial.print(pixyDistance);
      Serial.println(" cm");
      
      // Take appropriate action for non-target objects
      servo_2_1.write(50);// Add your code here
      
    }
  } else {
    // No object detected within threshold distance
    Serial.println("No object detected.");
    servo_2_1.write(50);
  }

  if(pixy.ccc.numBlocks > 0){
    for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      // Get the block
      Block *block = &pixy.ccc.blocks[i];
      if (block->m_signature == 2) {
       servo_2_1.write(90);
      }
      if (block->m_signature == 1) {
       servo_2_1.write(10);
      }
    }  
  }else{

      servo_2_1.write(50);
  }
  
  delay(500); // Delay between measurements
}

int getPixyDistance() {
  pixy.ccc.getBlocks(); // Update the block data from the PixyCam2
  
  if (pixy.ccc.numBlocks) {
    // Object detected, calculate the distance based on the detected block size
    int blockWidth = pixy.ccc.blocks[0].m_width;
    int pixyDistance = (int)(20.0 / blockWidth);
    return pixyDistance;
  }
  
  return -1; // No object detected
}

int getDetectedSignature() {
  pixy.ccc.getBlocks(); // Update the block data from the PixyCam2
  
  if (pixy.ccc.numBlocks) {
    // Object detected, return the signature ID of the detected object
    return pixy.ccc.blocks[0].m_signature;
  }
  
  return -1; // No object detected
}
