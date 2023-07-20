#include <MeMCore.h>
#include <Pixy2.h>

MeUltrasonicSensor ultrasonic_3(3); //sensor derecha
MeUltrasonicSensor ultrasonic_4(4); //sensor izquierda
Pixy2 pixy; //cámara delantera
Servo servo_2_1; //servo
MePort port_2(2);
MeRGBLed rgbled_4(4, 4); //led
MeDCMotor motor_9(9);
MeDCMotor motor_10(10);

double currentTime = 0;
double lastTime = 0;
int carril = 0; //variable que define el carril
int direccion = 0; //variable que define direccion del robot
int count = 0; //variable caso 1 - 1

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

double getLastTime(){
  return currentTime = millis() / 1000.0 - lastTime;
}

void setup() {
  Serial.begin(9600);
  pixy.init();
  pixy.setLamp(1,0);
}

void loop() {
  servo_2_1.attach(port_2.pin1());
  pixy.ccc.getBlocks();
  lastTime = millis() / 1000.0;

  //Definir en cuál carril está
  if (carril == 0) {
    int distance = ultrasonic_3.distanceCm(); //distancia a la derecha, hacia el centro

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance >= 5 && distance <= 35) { //rango de distancia para carril de adentro
      carril = 1;                          //carril de adentro (más cercano al centro)

    } else if (distance >= 40 && distance <= 47) { //rango de distancia para carril del medio
      carril = 2;                          //carril del medio
      
    } else if (distance >= 59 && distance <= 81) { //rango de distancia para carril de afuera
      carril = 3;                          //carril de afuera (más alejado al centro)
    }
  }

  //definir en que direccion va, si horaria o antihoraria
  if (direccion == 0) {
    servo_2_1.write(55);
    move(1, 50 / 100.0 * 255);

    int dd = ultrasonic_3.distanceCm(); //distancia a la derecha
    delay(500);
    int di = ultrasonic_4.distanceCm(); //distancia a la izquierda

    Serial.print("DD: ");
    Serial.print(dd);
    Serial.println(" cm");

    Serial.print("DI: ");
    Serial.print(di);
    Serial.println(" cm");

    if (dd >= 95 ) { //rango de distancia para carril de adentro
      direccion = 1;                          //carril de adentro (más cercano al centro)

    } else if (di >= 95) { //rango de distancia para carril del medio
      direccion = 2;                          //carril del medio

    }
  }

  if (carril == 1 && direccion == 1 && count == 0) {
    move(2, 70 / 100.0 * 255);
    delay(1000);
   if (count == 0) {
    if (ultrasonic_3.distanceCm() < 95) {
     count = 1;
    }
   }
  }

  //si el robot va en sentido horario
  //Giro si el carril es 1, el de adentro
  if (carril == 1 && direccion == 1 && count == 1) {
    move(1, 80 / 100.0 * 255);
   while(1) {
    if (ultrasonic_3.distanceCm() < 18) {
     servo_2_1.write(25);
    } else if (ultrasonic_3.distanceCm() > 30) {
     servo_2_1.write(100);
    } else {
     servo_2_1.write(55);
    }
    if(getLastTime() > 60){
     move(0,0);
    }
   }
  }

  //giro si el carril es 2, el del medio
  if (carril == 2 && direccion == 1) {
    move(1, 70 / 100.0 * 255);

    if (ultrasonic_3.distanceCm() < 42) {
     servo_2_1.write(35);
    } else if (ultrasonic_3.distanceCm() > 50) {
     servo_2_1.write(95);
    } else {
     servo_2_1.write(55);
    }
    if (pixy.ccc.numBlocks > 0) {
    for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      // Get the block
      Block *block = &pixy.ccc.blocks[i];
      if (block->m_signature == 2) {
       servo_2_1.write(90);
      }
      if (block->m_signature == 1) {
       servo_2_1.write(15);
      }
    }
    }
    delay(100);
  }

  //giro si el carril es 3, el de afuera
  if (carril == 3 && direccion == 1) {
    move(1, 80 / 100.0 * 255);
   while(1) {
    if (ultrasonic_3.distanceCm() < 67) {
     servo_2_1.write(30);
    } else if (ultrasonic_3.distanceCm() > 72) {
     servo_2_1.write(80);
    } else {
     servo_2_1.write(55);
    }
    if(getLastTime() > 87){
     move(0,0);
    }
   }
  }  

  //si el robot va en sentido antihorario
  //giro si el carril es 1, el de afuera
  if (carril == 1 && direccion == 2) {
    move(1, 80 / 100.0 * 255);
   while(1) {
    if (ultrasonic_4.distanceCm() < 67) {
     servo_2_1.write(62);
    } else if (ultrasonic_4.distanceCm() > 72) {
     servo_2_1.write(30);
    } else {
     servo_2_1.write(55);
    }
    if(getLastTime() > 87){
     move(0,0);
    }
   }
  }  

  //giro si el carril es 2, el del medio
  if (carril == 2 && direccion == 2) {
    move(1, 70 / 100.0 * 255);

    if (ultrasonic_4.distanceCm() < 42) {
     servo_2_1.write(75);
    } else if (ultrasonic_4.distanceCm() > 50) {
     servo_2_1.write(20);
    } else {
      servo_2_1.write(55);
    }
    if (pixy.ccc.numBlocks > 0) {
    for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      // Get the block
      Block *block = &pixy.ccc.blocks[i];
      if (block->m_signature == 2) {
       servo_2_1.write(25);

      }
      if (block->m_signature == 1) {
       servo_2_1.write(75);
      }
    }
    }
      delay(100);
  }

   //Giro si el carril es 3, el de adentro
  if (carril == 3 && direccion == 2) {
   move(1, 80 / 100.0 * 255);
  while(1) {
    if (ultrasonic_4.distanceCm() < 15) {
     servo_2_1.write(90);
    } else if (ultrasonic_4.distanceCm() > 27) {
     servo_2_1.write(15);
    } else {
     servo_2_1.write(55);
    }
    if(getLastTime() > 60){
     move(0,0);
    }
   }
  }           
}