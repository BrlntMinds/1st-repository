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

int carril = 0; //variable que define el carril
int direccion = 0; //variable que define direccion del robot

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

  //definir en que direccion va, si horaria o antihoraria
  if (direccion == 0) {
    int dd = ultrasonic_3.distanceCm(); //distancia a la derecha
    int di = ultrasonic_4.distanceCm(); //distancia a la izquierda

    Serial.print("DD: ");
    Serial.print(dd);
    Serial.println(" cm");

    Serial.print("DI: ");
    Serial.print(di);
    Serial.println(" cm");

    if (dd >= 95) { //rango de distancia para carril de adentro
      direccion = 1;                          //carril de adentro (más cercano al centro)
      /*rgbled_4.setColor(0,  255,0,0);
       rgbled_4.show();*/
    } else if (di >= 95) { //rango de distancia para carril del medio
      direccion = 2;                          //carril del medio
      /*rgbled_4.setColor(0,  0,255,0);
       rgbled_4.show();*/
    }
  }

  //si el robot va en sentido horario
  //Giro si el carril es 1, el de adentro
  if (carril == 1 && direccion == 1) {
    
    if (ultrasonic_3.distanceCm() < 5) {
     servo_2_1.write(10);
    } else if (ultrasonic_3.distanceCm() > 27) {
     servo_2_1.write(90);
    } else {
     servo_2_1.write(55);
    } 
  }

  //giro si el carril es 2, el del medio
  if (carril == 2 && direccion == 1) {
    if (ultrasonic_3.distanceCm() < 40) {
     servo_2_1.write(10);
    } else if (ultrasonic_3.distanceCm() > 47) {
     servo_2_1.write(90);
    } else {
     servo_2_1.write(55);
    }
  }

  //giro si el carril es 3, el de afuera
  if (carril == 3 && direccion == 1) {
    if (ultrasonic_3.distanceCm() < 59) {
     servo_2_1.write(10);
    } else if (ultrasonic_3.distanceCm() > 81) {
     servo_2_1.write(90);
    } else {
     servo_2_1.write(55);
    }
  }  

  //si el robot va en sentido antihorario
  //giro si el carril es 1, el de afuera
  if (carril == 1 && direccion == 2) {
    if (ultrasonic_4.distanceCm() < 59) {
     servo_2_1.write(90);
    } else if (ultrasonic_4.distanceCm() > 81) {
     servo_2_1.write(10);
    } else {
     servo_2_1.write(55);
    }
  }  

  //giro si el carril es 2, el del medio
  if (carril == 2 && direccion == 2) {
    if (ultrasonic_4.distanceCm() < 40) {
     servo_2_1.write(90);
    } else if (ultrasonic_4.distanceCm() > 47) {
     servo_2_1.write(10);
    } else {
     servo_2_1.write(55);
    }
  }

   //Giro si el carril es 3, el de adentro
  if (carril == 3 && direccion == 2) {
    
    if (ultrasonic_4.distanceCm() < 5) {
     servo_2_1.write(90);
    } else if (ultrasonic_4.distanceCm() > 27) {
     servo_2_1.write(10);
    } else {
     servo_2_1.write(55);
    } 
  }             
}