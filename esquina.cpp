#include "esquina.h"
void esquina::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type
//obtengo los parametros
tamanioEsquina = va_arg(parameters,double);
velocidad = va_arg(parameters,double);
probabilidad = va_arg(parameters,double);
seed= (int) va_arg(parameters,double);
tamanioAuto= (int) va_arg(parameters,double);

//obtengo el puntero para generar el random
rng= new CRandomMersenne(seed);

//inicio la cola

sigma = 1e20; //sigma 1e20inito


}
double esquina::ta(double t) {
//This function returns a double.
return sigma;
}
void esquina::dint(double t) {
//debo recorrer la cola,  e ir desencolando los autos que salen, y actualizar los autos que quedan
	int i=0;
	Cola.dequeue();
	while(i< Cola.size()){
		Cola.setDistancia(i,Cola.getDistancia(i)-(velocidad*e));
		i++;
	}
	if(Cola.size()>0)
		sigma= (Cola.getDistancia(0)-(velocidad*e))/velocidad;
	else
		sigma= 1e20;

}
void esquina::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

//Actualizo la distancia que le falta a los autos que estan en la lista y encolo el auto que ingresa.
			printLog("entrada esquina en tiempo: %d   \n",t);
	if(Cola.size()*tamanioAuto >= tamanioEsquina)
		printLog("Error: se lleno la esquina");
	else{
		int i=0;
		while(i< Cola.size()){
			Cola.setDistancia(i,Cola.getDistancia(i)-(velocidad*e));
			i++;
		}		
		Cola.enqueue(tamanioEsquina,velocidad);
		sigma= (Cola.getDistancia(0)-(velocidad*e))/velocidad;


	}

}
Event esquina::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
	double r = rng->Random();
	y=1;
	printLog("salida esquina en tiempo: %d   \n",t);
	if (r<probabilidad){
		return Event(&y,0);
	}
	else{
		return Event(&y,1);	
	}
}
void esquina::exit() {
//Code executed at the end of the simulation.

}
