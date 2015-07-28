#include "generador.h"
void generador::init(double t,...) {

va_list parameters;
va_start(parameters,t);
tasa = va_arg(parameters,double);
velCalle = va_arg(parameters,double);
seed= (int) va_arg(parameters,double);
tamAuto = va_arg(parameters,double);
stor=new StochasticLib1(seed);

}
double generador::ta(double t) {
return sigma;
}
void generador::dint(double t) {
double proxArribo= stor->exponential(tasa); 
	if (proxArribo > (tamAuto/velCalle)){ 
		sigma= proxArribo;
	}else{
		sigma= (tamAuto / velCalle) + proxArribo; 
	}
}
void generador::dext(Event x, double t) {

}
Event generador::lambda(double t) {
y=1;
printLog("%dgenero tiempo", t);
return Event(&y,0);
}
void generador::exit() {

}
