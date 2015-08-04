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

					
color = 1;
sigma = 1e20;

}
double calle::ta(double t) {
return sigma;							
}
void calle::dint(double t) {
/*actualizacion de autos en movimiento*/
	Cola.dequeue();
	int i=0;
		while(i<Cola.size()){
			Cola.setDistancia(i,Cola.getDistancia(i)-(Cola.getVelocidad(i)*e));
			i++;
		}
		if(Cola.size() == 0){
			sigma= 1e20;
		}else{
			sigma = Cola.getDistancia(0)/velocidad;
		}	
}
void calle::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

if(x.port == 0){// viene un auto
	//printLog("Ingresa auto en tiempo: %f\n",t);
	if(color == 1){//rojo
		int j = 0;
			while(j<Cola.size()){
				if(Cola.getDistancia(j) - j*tamanioAuto <= Cola.getVelocidad(j)*e){//si la distancia que le falta al auto j para chocar al auto j-1
					//es menor a la distancia que debio recorrer desde el ultimo evento. CHOCA
					if(j !=0 ){
						Cola.setDistancia(j,Cola.getDistancia(j-1)+tamanioAuto);
					}else{
						Cola.setDistancia(j,0);
					}
					Cola.setVelocidad(j,0);
				}else{
					Cola.setDistancia(j,Cola.getDistancia(j)-(Cola.getVelocidad(j)*e));
				}
				j++;
			}
	}else{// verde o amarillo solo actualizo y encolo
		int i=0;
		while(i<Cola.size()){
				Cola.setDistancia(i,Cola.getDistancia(i)-(Cola.getVelocidad(i)*e));
				Cola.setVelocidad(i,velocidad);				
				i++;
		}
	}
	if(tamanioAuto*Cola.size() < tamanioCalle){// si la calle no colapsa encolo
		Cola.enqueue(tamanioCalle,velocidad);
	}else{
		printLog("Colapso la calle \n");
	}

/*
([d[i-1]+tamanioAuto,V],(d[0]-v.e)/V,V o A) Si d[i]-i*tamanioAuto <= v[i]*e & X=(V || A)
([d[i-1]+tamanioAuto,0],inf,ROJO) Si d[i]-i*tamanioAuto <= v[i]*e & X=ROJO
*/
}else{
	if(*((int*)x.value) == 1){//rojo
		//printLog("Cambio semaforo a rojo en tiempo: %f\n",t);
		int i = 0;
		while(i<Cola.size()){
				Cola.setDistancia(i,Cola.getDistancia(i)-(Cola.getVelocidad(i)*e));				
				i++;
		}
		sigma = 1e20;
		color = 1;
	}else{
		int j = 0;
			while(j<Cola.size()){
				if(Cola.getDistancia(j) - j*tamanioAuto <= Cola.getVelocidad(j)*e){//si la distancia que le falta al auto j para chocar al auto j-1
					//es menor a la distancia que debio recorrer desde el ultimo evento. CHOCA
					if(j !=0 ){
						Cola.setDistancia(j,Cola.getDistancia(j-1)+tamanioAuto);
					}else{
						Cola.setDistancia(j,0);
					}
					Cola.setVelocidad(j,velocidad);
				}else{
					Cola.setDistancia(j,Cola.getDistancia(j)-(Cola.getVelocidad(j)*e));
				}
				j++;
			}
			sigma = Cola.getDistancia(0)/velocidad;
			if(*((int*)x.value) == 2){//amarill
				//printLog("Cambio semaforo a amarillo en tiempo: %f\n",t);
				color = 2;
			}else{
				//printLog("Cambio semaforo a verde en tiempo: %f\n",t);
				color = 3;
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
	//printLog("Sale auto de la calle en tiempo: %f\n",t);
	y = 1;	
	return Event(&y,0); 
}
void calle::exit() {
//Code executed at the end of the simulation.
}