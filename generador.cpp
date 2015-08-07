#include "generador.h"

void generador::init(double t,...) {

va_list parameters;
va_start(parameters,t);
tasa = va_arg(parameters,double);
velCalle = va_arg(parameters,double);
seed= (int) va_arg(parameters,double);
stor=new StochasticLib1(seed);

}
double generador::ta(double t) {
return sigma;
}
void generador::dint(double t) {
  bool flag = true;
  while (flag){
	 double proxArribo= stor->exponential(tasa); 
   if (proxArribo > (tamanioAuto/velCalle)){ 
	  sigma= proxArribo;
     flag = false;
   }
  }
}
void generador::dext(Event x, double t) {

}
Event generador::lambda(double t) {
y=1;
return Event(&y,0);
}
void generador::exit() {

}
