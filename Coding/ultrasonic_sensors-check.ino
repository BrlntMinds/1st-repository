#include <MeMCore.h>

MeUltrasonicSensor ultrasonic_3(3); //sensor derecha
MeUltrasonicSensor ultrasonic_4(4); //sensor izquierda
MeRGBLed rgbled_4(4, 4); //led

void setup() {
  Serial.begin(9600);
}

void loop() {
   
   int dd = ultrasonic_3.distanceCm(); //distancia a la derecha
    int di = ultrasonic_4.distanceCm(); //distancia a la izquierda

    Serial.print("DD: ");
    Serial.print(dd);
    Serial.println(" cm");

    Serial.print("DI: ");
    Serial.print(di);
    Serial.println(" cm");
}
