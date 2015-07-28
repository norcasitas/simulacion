//CPP:prooo/cola/cola.cpp
#ifndef COLA_H
#define COLA_H
#include <iostream>
using namespace std;
#include "nodo.h"



typedef nodo *pnodo;

class cola {
   public:
    cola() : primero(NULL), ultimo(NULL),tamanio(0) {}
    
    void enqueue(double distancia,double velocidad);
    double readDistancia();
    double readVelocidad();
    double getDistancia(int index);
    double getVelocidad(int index);
    void setDistancia(int index,double v);
    void setVelocidad(int index,double v);
    int dequeue();
    int size();
   private:
    pnodo primero, ultimo;
    int tamanio;
};

#endif
 

