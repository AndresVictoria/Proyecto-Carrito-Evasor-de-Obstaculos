#include "Arduino.h"
#include "MoverCarro.h"
MoverCarro::MoverCarro(int x,int y, int z, int w){
    motor1A = x;
    motor1B = y;
    motor2C = z;
    motor2D = w; 
    pinMode(motor1A, OUTPUT);
    pinMode(motor1B, OUTPUT);
    pinMode(motor2C, OUTPUT);
    pinMode(motor2D, OUTPUT);
}

void MoverCarro::detenerCarro() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);                       
  digitalWrite(motor2C, LOW);
  digitalWrite(motor2D, LOW); 

}

void MoverCarro::avanzarCarro() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);                       
  digitalWrite(motor2C, HIGH);
  digitalWrite(motor2D, LOW); 
  delay(60);
  detenerCarro();
  delay(20);
}

void MoverCarro::girarDerecha() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);                       
  digitalWrite(motor2C, HIGH);
  digitalWrite(motor2D, LOW); 
  delay(60);
  detenerCarro();
  delay(20);
}

void MoverCarro::girarIzquierda() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);                       
  digitalWrite(motor2C, LOW);
  digitalWrite(motor2D, LOW); 
  delay(60);
  detenerCarro();
  delay(20);
}