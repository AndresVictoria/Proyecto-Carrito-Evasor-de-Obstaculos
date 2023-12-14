#include <Servo.h>
#include "MoverCarro.h"
Servo servo;
MoverCarro carro(5,6,11,10);
int echoPin = 2;
int trigPin = 3;
long duracion;
int distancia;

int servoPos = 80;
int servoLeerIzquierda = 0;
int servoLeerDerecha = 0;

void setup() {
  delay(1000);
  servo.attach(9);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.write(0);
  Serial.begin(9600);
}

void loop() {
    
  distancia = medirDistancia();
  Serial.println(distancia);

  if (distancia < 15) {
    carro.detenerCarro();
     Serial.println("detener");

    servo.write(0);  
    delay(600);  
    servoLeerDerecha = medirDistancia();
    Serial.println(servoLeerDerecha);

    servo.write(160);  
    delay(600); 
    servoLeerIzquierda = medirDistancia();
    Serial.println(servoLeerIzquierda);
    servo.write(80);
     
        

     if(servoLeerDerecha > servoLeerIzquierda){
     Serial.println("girarDerecha");
     carro.girarDerecha();
     carro.girarDerecha();
     carro.girarDerecha();
     carro.girarDerecha();

      delay(700); 
     }

     if(servoLeerIzquierda > servoLeerDerecha){
     Serial.println("girarIzquierda");
     carro.girarIzquierda();
     carro.girarIzquierda();
     carro.girarIzquierda();
     carro.girarIzquierda();
      delay(700); 
     }
     
  }
  else {
    carro.avanzarCarro();
     Serial.println("avanzar");

     Serial.println("avanzar");
    
  }
}



int medirDistancia() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracion = pulseIn(echoPin, HIGH);
  distancia = duracion * 0.034 / 2;

  return distancia;    
}