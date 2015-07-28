#if !defined cola_cpp
#define cola_cpp
#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void cola::enqueue(double distancia, double velocidad)
{
   pnodo nuevo;

   /* Crear un nodo nuevo */
   /* Este será el último nodo, no debe tener siguiente */
   nuevo = new nodo(distancia,velocidad);
   /* Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo */
   if(ultimo) ultimo->siguiente = nuevo;
   /* Ahora, el último elemento de la cola es el nuevo nodo */
   ultimo = nuevo;
   /* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
   if(!primero) primero = nuevo;
   tamanio++;

}

double cola::readDistancia()
{
   pnodo nodo; /* variable auxiliar para manipular nodo */
   /* Nodo apunta al primer elemento de la pila */
   nodo = primero;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   return nodo->distancia;
}

double cola::readVelocidad()
{
   pnodo nodo; /* variable auxiliar para manipular nodo */
   /* Nodo apunta al primer elemento de la pila */
   nodo = primero;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   return nodo->velocidad;
}

double cola::getDistancia(int index)
{
   pnodo aux;

   /* Crear un nodo nuevo auxliar*/
   /* Este será el último nodo, no debe tener siguiente */
   int i=0;
   if (primero){
    aux = primero;
    while(aux && i< index){
      aux = aux->siguiente;
      i++;
    }
    if(aux)
      return aux->distancia;
  }
  return -1;
}

double cola::getVelocidad(int index)
{
   pnodo aux;

   /* Crear un nodo nuevo auxliar*/
   /* Este será el último nodo, no debe tener siguiente */
   int i=0;
   if (primero){
    aux = primero;
    while(aux && i< index){
      aux = aux->siguiente;
      i++;
    }
    if(aux)
      return aux->velocidad;
  }
  return -1;
}


void cola::setDistancia(int index,double v)
{
   pnodo aux;

   /* Crear un nodo nuevo auxliar*/
   /* Este será el último nodo, no debe tener siguiente */
   int i=0;
   if (primero){
    aux = primero;
    while(aux && i< index){
      aux = aux->siguiente;
      i++;
    }
    if(aux)
       aux->distancia=v;
  }

}

void cola::setVelocidad(int index,double v)
{
   pnodo aux;

   /* Crear un nodo nuevo auxliar*/
   /* Este será el último nodo, no debe tener siguiente */
   int i=0;
   if (primero){
    aux = primero;
    while(aux && i< index){
      aux = aux->siguiente;
      i++;
    }
    if(aux)
       aux->velocidad= v;
  }
}

int cola::dequeue()
{
   pnodo nodo; /* variable auxiliar para manipular nodo */
   
   /* Nodo apunta al primer elemento de la pila */
   nodo = primero;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a primero la dirección del segundo nodo */
   primero = nodo->siguiente;
   /* Borrar el nodo */
   delete nodo;
   /* Si la cola quedó vacía, ultimo debe ser NULL también*/
   if(!primero) ultimo = NULL;
   tamanio--;
   return 1;
}

int cola::size()
{
  return tamanio;
}
 #endif

