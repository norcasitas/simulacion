#include "semaforo.h"
void semaforo::init(double t,...) {
	
	va_list parameters;
	va_start(parameters,t);
	tiempoRojo=va_arg(parameters,double);
	tiempoAmarillo=va_arg(parameters,double);
	tiempoVerde=va_arg(parameters,double);
	colorInicial=(int) va_arg(parameters,double);
	color=colorInicial;
	if(color=='1'){	
		sigma=tiempoRojo;
	}else{ 
		if(color=='2'){
			sigma=tiempoAmarillo;	
		}else{ 
			sigma= tiempoVerde;
		}
	}
}
double semaforo::ta(double t) {
	return sigma;
}
void semaforo::dint(double t) {

if(color==1){
		color= 3;
		sigma=tiempoVerde;
	}else{
		if (color==3){
			color= 2;
			sigma= tiempoAmarillo;
		}else{
			if(color==2){
				color=1;
				sigma= tiempoRojo;
			}
		}
	}
}
void semaforo::dext(Event x, double t) {

}
Event semaforo::lambda(double t) {
	if (color==1){
		y=3;
		return Event(&y,0);
	}else{
			if (color==3){
				y=2;
				return Event(&y,0);
			}else{		
						y=1;
						return Event(&y,0);
				 }
		 }
}
void semaforo::exit() {

}
