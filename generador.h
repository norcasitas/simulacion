//CPP:/prooo/lib/stocc.cpp
//CPP:/prooo/lib/randomc.cpp
//CPP:prooo/generador.cpp
#if !defined generador_h
#define generador_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"
#include "lib/randomc.h"
#include "lib/stocc.h"


class generador: public Simulator { 

//estado
double sigma;

//salida
int y;

//parametros
double tasa;
double velCalle;
int seed;

StochasticLib1 *stor;
int tamanioAuto = 2;
	double INF  = 1e20;


public:
	generador(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
