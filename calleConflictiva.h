//CPP:/prooo/cola/cola.cpp
//CPP:prooo/calleConflictiva.cpp
#if !defined calleConflictiva_h
#define calleConflictiva_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"
#include "lib/randomc.h"
#include "cola/cola.h"



class calleConflictiva: public Simulator { 
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
//variables auxiliares
FILE * data;


int tamanioAuto = 2;
	double INF  = 1e20;
public:
	calleConflictiva(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
