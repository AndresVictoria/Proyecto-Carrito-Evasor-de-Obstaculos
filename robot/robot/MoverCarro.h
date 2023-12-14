#ifndef MoverCarro_h
#define MoverCarro_h
#include "Arduino.h"

// La librería se crea como una clase denominada ObjetoLibreria
class MoverCarro {
  // Atributos
  private:
  int motor1A;
  int motor1B;
  int motor2C;
  int motor2D;

  // Métodos
  public:
    MoverCarro(int motor1A,int motor1B, int motor2C, int motor2D);
    void detenerCarro();
    void avanzarCarro();
    void girarDerecha();
    void girarIzquierda();


};

#endif