#ifndef NODO_H
#define NODO_H
#include <stdio.h>
#include <stdlib.h>

class nodo {
   public:
    nodo(double dist,double ve, nodo *sig = NULL)
    {
       distancia = dist;
       velocidad = ve;
       siguiente = sig;
    }


    double distancia;//distancia que falta recorrer
    double velocidad; //velocidad del auto
    nodo *siguiente;        
};

#endif // NODO_H
