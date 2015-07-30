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
tamanioCalle = 100;
tamanioAuto= va_arg(parameters,double);

					
color = 1;
sigma = 1e20;

}
double calle::ta(double t) {
return sigma;							
}
void calle::dint(double t) {
/*actualizacion de autos en movimiento*/
		printLog("delta interna \n");
		if(color== 1){	//rojo
			int j = 0;
			while(j<Cola.size()){
				if(Cola.getDistancia(j)> j*tamanioAuto){
					printLog("delta int seteo dist %f \n",Cola.getDistancia(j)-(Cola.getVelocidad(j)*e));
					Cola.setDistancia(j,Cola.getDistancia(j)-(Cola.getVelocidad(j)*e));
				}else{
					Cola.setDistancia(j,Cola.getDistancia(j)-(Cola.getVelocidad(j)*e));
					Cola.setVelocidad(j,0);
				}
				j++;
			}
			if(Cola.size()>0){ 
				if (Cola.getVelocidad(0) == 0){ //si al menos hay un frenado
					j = Cola.size()-1;
					if (Cola.getVelocidad(j) == 0) //estan todos frenados
							sigma= 1e20;
					else {
					int k = 0;
						j--;
						while (j>0 && k == 0){
							if (Cola.getVelocidad(k) == 0)
								k = j;
							j--;
						}
						sigma = ((Cola.getDistancia(k+1)-(k*tamanioAuto)) - (velocidad*e))/velocidad; //calculo la distancia al proximo auto
					}
				} else { //si no hay autos frenados sigma es igual que siempre
					sigma= (Cola.getDistancia(0)-(Cola.getVelocidad(0)*e))/Cola.getVelocidad(0);
				}
			} else {
				sigma= 1e20;
			}	
		}else{ //este else está mal, solo va a ejecutarse cuando la cola es cero, podés tener 2 autos y ya un auto debe salir pero no sale
			Cola.dequeue();

			if(Cola.size()>0)
				sigma= (Cola.getDistancia(0)-(Cola.getVelocidad(0)*e))/Cola.getVelocidad(0);
			else
				sigma= 1e20;			
		}
	
}
void calle::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

if(x.port == 0){
	//printLog("ingresa auto en tiempo %f\n",t);
		int i = 0;
		while(i<Cola.size()){
printLog("e %f velocidad %f la distancia vieja es %f seteo la distancia %f \n",e,Cola.getVelocidad(i),Cola.getDistancia(i),Cola.getDistancia(i)-(Cola.getVelocidad(i)*e));
					Cola.setDistancia(i,Cola.getDistancia(i)-(Cola.getVelocidad(i)*e));					
					i++;
				}
		if(Cola.size()<tamanioCalle){// hay lugar, entonces encolo
		Cola.enqueue(tamanioCalle,velocidad);
		}else{
			printLog("colapsa la calle en tiempo %f \n",t);
		}
		if(Cola.getVelocidad(0)==0){//si la velocidad del primer auto es 0, el sigma es infinito
			sigma= 1e20;
		}
		else{//sino calculo cuanto le falta al primer auto para llegar a la esquina
			sigma= Cola.getDistancia(0)/Cola.getVelocidad(0);
		}
		printLog("sigma %f \n",sigma);
}else{
	printLog("cambia semaforo en tiempo %f",t);

	if(*((int*)x.value) == 1){//rojo
	printLog("ahora el color es roojo \n");

		int i = 0;
		while(i<Cola.size()){
				Cola.setDistancia(i,Cola.getDistancia(i)-(Cola.getVelocidad(i)*e));				
				i++;
		}
		color = 1;
		if(Cola.size()>0){

				if (Cola.getVelocidad(0) == 0){ //si al menos hay un frenado
					int j = Cola.size()-1;
					if (Cola.getVelocidad(j) == 0) //estan todos frenados
							sigma= 1e20;
					else {
					int k = 0;
						j--;
						while (j>0 && k == 0){
							if (Cola.getVelocidad(k) == 0)
								k = j;
							j--;
						}
						sigma = ((Cola.getDistancia(k+1)-(k*tamanioAuto)) - (velocidad*e))/velocidad; //calculo la distancia al proximo auto
					}
				} else { //si no hay autos frenados sigma es igual que siempre
					sigma= (Cola.getDistancia(0)-(Cola.getVelocidad(0)*e))/Cola.getVelocidad(0);
				}
			} else {
				sigma= 1e20;
			}		
	}
	if(*((int*)x.value) == 2){//amarill
	printLog("ahora el color es amarillo \n");

		int i = 0;
		while(i<Cola.size()){
				Cola.setDistancia(i,Cola.getDistancia(i)-(Cola.getVelocidad(i)*e));				
				i++;
		}
		color = 2;
		if(Cola.size()>0)
			sigma= (Cola.getDistancia(0)-(Cola.getVelocidad(0)*e))/Cola.getVelocidad(0);
		else
			sigma= 1e20;
	}
	if(*((int*)x.value) == 3){//verde
	printLog("ahora el color es verde \n");

		int i=0;
		while(i<Cola.size()){
				Cola.setDistancia(i,Cola.getDistancia(i)-(Cola.getVelocidad(i)*e));
				Cola.setVelocidad(i,velocidad);				
				i++;
		}
		color = 3;
		if(Cola.size()>0)
			sigma= (Cola.getDistancia(0)-(Cola.getVelocidad(0)*e))/Cola.getVelocidad(0);
		else
			sigma= 1e20;
	}
}
}
Event calle::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

y = 1;	
if(color != 1){	
	printLog("SALGO DE CALLE en tiempo %f\n",t);
    return Event(&y,0);
}
	return Event(&y,1); 
}
void calle::exit() {
//Code executed at the end of the simulation.

}
