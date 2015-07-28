#include "calle.h"
void calle::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type
velocidad = va_arg(parameters,double);
tamanioCalle = va_arg(parameters,double);
tamanioAuto= va_arg(parameters,double);

					

sigma = 1e20;

}
double calle::ta(double t) {
return sigma;							
}
void calle::dint(double t) {
/*actualizacion de autos en movimiento*/
		
		if(color== 1){
			int j = 0;
			while(j<Cola.size()){
				if(Cola.getDistancia(j)> j*tamanioAuto){
					Cola.setDistancia(j,Cola.getDistancia(j)-(Cola.getVelocidad(j)*e));
				}else{
					Cola.setDistancia(j,Cola.getDistancia(j)-(Cola.getVelocidad(j)*e));
					Cola.setVelocidad(j,0);
				}
				j++;
			}
		}else{
			int i = 0;
			while(i<Cola.size()){
				Cola.setDistancia(i,Cola.getDistancia(i)-(Cola.getVelocidad(i)*e));
				i++;
			}
			Cola.dequeue();
		}
	}

void calle::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition
if(x.port == 0){
	int i = 0;
	while(i<Cola.size()){
				Cola.setDistancia(i,Cola.getDistancia(i)-(Cola.getVelocidad(i)*e));
				Cola.setVelocidad(i,velocidad);
				Cola.enqueue(tamanioCalle,velocidad);
				i++;
			}
}else{
	if(*((int*)x.value) == 1){//rojo
		int i = 0;
		while(i<Cola.size()){
				Cola.setDistancia(i,Cola.getDistancia(i)-(velocidad*e));
				color = 1;
				i++;
		}	
	}
	if(*((int*)x.value) == 2){//amarillo
		int i = 0;
		while(i<Cola.size()){
				Cola.setDistancia(i,Cola.getDistancia(i)-(Cola.getVelocidad(i)*e));
				color = 2;
				i++;
		}	
	}
	if(*((int*)x.value) == 3){//verde
		int i=0;
		while(i<Cola.size()){
				Cola.setDistancia(i,Cola.getDistancia(i)-(Cola.getVelocidad(i)*e));
				color = 3;
				i++;
		}	
	}

}
}

Event calle::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

if(color != 1){
	y = 1;
    return Event(&y,0);
}
	y=1;
	return Event(&y,0); //ver esto del if que charlamos, lo pongo así para que compile
}

void calle::exit() {
//Code executed at the end of the simulation.

}

