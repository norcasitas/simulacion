//CPP:/prooo/cola/cola.cpp
//CPP:prooo/calle.cpp
#if !defined calle_h
#define calle_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"
#include "lib/randomc.h"
#include "cola/cola.h"



class calle: public Simulator { 
// Declare the state,
// output variables
// and parameters

//estado
cola Cola;
double sigma;
int color;

	
//salida
double y;

//parametros
double velocidad;
double tamanioCalle;



int tamanioAuto = 2;
double INF  = 1e20;

public:
	calle(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
