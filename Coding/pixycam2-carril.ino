#include <MeMCore.h>
#include <Pixy2.h>

MeUltrasonicSensor ultrasonic_3(3); //sensor derecha
Pixy2 pixy; //cámara delantera
Servo servo_2_1; //servo
MePort port_2(2);
MeRGBLed rgbled_4(4, 4); //led
MeDCMotor motor_9(9);
MeDCMotor motor_10(10);

int carril = 0; //variable que define el carril

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
  servo_2_1.attach(port_2.pin1());
  pixy.ccc.getBlocks();
  move(1, 85 / 100.0 * 255);

  //Definir en cuál carril está
  if (carril == 0) {
    int distance = ultrasonic_3.distanceCm(); //distancia a la derecha, hacia el centro

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance >= 5 && distance <= 27) { //rango de distancia para carril de adentro
      carril = 1;                          //carril de adentro (más cercano al centro)
      rgbled_4.setColor(0,  255,0,0);
       rgbled_4.show();
    } else if (distance >= 40 && distance <= 47) { //rango de distancia para carril del medio
      carril = 2;                          //carril del medio
      rgbled_4.setColor(0,  0,255,0);
       rgbled_4.show();
    } else if (distance >= 59 && distance <= 81) { //rango de distancia para carril de afuera
      carril = 3;                          //carril de afuera (más alejado al centro)
      rgbled_4.setColor(0,  0,0,255);
       rgbled_4.show();
    } else {
      rgbled_4.setColor(0,  0,0,0);
       rgbled_4.show();
    }
  }

  //Giro si el carril es 1, el de adentro
  if (carril == 1) {
    int blocks = pixy.ccc.getBlocks();

    if (blocks) {
      for (int i = 0; i < blocks; i++) {
        if (pixy.ccc.blocks[i].m_signature == 3) {             //detección del borde
          int signatureDistance = pixy.ccc.blocks[i].m_width;  //tamaño representado por el ancho del objeto, mientras más ancho, más cerca
          
          Serial.print("Signature Distance: ");
          Serial.print(signatureDistance);
          Serial.println(" units");

          if (signatureDistance > 100) { //unidades de ancho
            servo_2_1.write(90); //giro a derecha
            delay(1000);
          } else {
            servo_2_1.write(55); //recto
          }

          /*if (ultrasonic_3.distanceCm() < 5) {
            servo_2_1.write(25);
          } else if (ultrasonic_3.distanceCm() > 27) {
            servo_2_1.write(75);
          } else {
            servo_2_1.write(55);
          } */     
        }
      }
    }
  }

  //giro si el carril es 2, el del medio
  if (carril == 2) {
    int blocks = pixy.ccc.getBlocks();

    if (blocks) {
      for (int i = 0; i < blocks; i++) {
        if (pixy.ccc.blocks[i].m_signature == 3) { 
          int signatureDistance = pixy.ccc.blocks[i].m_width; 
          Serial.print("Signature Distance: ");
          Serial.print(signatureDistance);
          Serial.println(" units");

          if (signatureDistance > 150) { 
            servo_2_1.write(90);
            delay(1600);
          } else {
            servo_2_1.write(55);
          }

          /*if (ultrasonic_3.distanceCm() < 40) {
            servo_2_1.write(25);
          } else if (ultrasonic_3.distanceCm() > 47) {
            servo_2_1.write(75);
          } else {
            servo_2_1.write(55);
          }*/
        }
      }
    }
  }

  //giro si el carril es 3, el de afuera
  if (carril == 3) {
    int blocks = pixy.ccc.getBlocks();

    if (blocks) {
      for (int i = 0; i < blocks; i++) {
        if (pixy.ccc.blocks[i].m_signature == 3) { 
          int signatureDistance = pixy.ccc.blocks[i].m_width; 
          Serial.print("Signature Distance: ");
          Serial.print(signatureDistance);
          Serial.println(" units");

          if (signatureDistance > 250) {
            servo_2_1.write(90);
            delay(1000);
          } else {
            servo_2_1.write(55);
          }

          /*if (ultrasonic_3.distanceCm() < 59) {
            servo_2_1.write(25);
          } else if (ultrasonic_3.distanceCm() > 81) {
            servo_2_1.write(75);
          } else {
            servo_2_1.write(55);
          }*/ 
        }
      }
    }
  }                
}