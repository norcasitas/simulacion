//CPP:/prooo/cola/cola.cpp
//CPP:prooo/esquina.cpp
#if !defined esquina_h
#define esquina_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "lib/randomc.h"
#include "cola/cola.h"


class esquina: public Simulator { 
// Declare the state,
// output variables
// and parameters
//puerto de salida
double y;

//random
CRandomMersenne *rng;

//parametros
double tamanioEsquina;
double velocidad;
double probabilidad;
int seed;
double tamanioAuto;


//estado
double sigma;
cola Cola;

public:
	esquina(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
