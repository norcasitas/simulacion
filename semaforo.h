//CPP:prooo/semaforo.cpp
#if !defined semaforo_h
#define semaforo_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

class semaforo: public Simulator { 

//parameters
	double tiempoRojo; 
	double tiempoVerde;
	double tiempoAmarillo;
	int colorInicial;

//estado
	double sigma; 
	int color; 

//aux
	int y;

	public:
		semaforo(const char *n): Simulator(n) {};
		void init(double, ...);
		double ta(double t);
		void dint(double);
		void dext(Event , double );
		Event lambda(double);
		void exit();
};
#endif
