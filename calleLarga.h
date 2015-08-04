//CPP:/prooo/cola/cola.cpp
//CPP:prooo/calleLarga.cpp
#if !defined calleLarga_h
#define calleLarga_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "lib/randomc.h"
#include "cola/cola.h"


class calleLarga: public Simulator { 
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
double tamanioAuto;
//variables auxiliares
FILE * data;



public:
	calleLarga(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
