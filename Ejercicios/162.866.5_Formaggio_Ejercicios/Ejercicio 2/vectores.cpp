using namespace std;
#include "vectores.hpp"
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop 

Ejercicio Nro. 2:
Dado un vector de notas que contiene el código de la materia y la cantidad de alumnos inscriptos obtenida. Se sabe que hay 50 materias, determinar:
a- ¿Cuál fue la materia que más inscriptos tuvo?
b- ¿Cuál fue la materia que menos inscriptos tuvo?
c- Calcular el promedio de inscriptos en todas las materias.

*/

int BuscarMinimo(CodigoInscripciones materia[], int len){
	float minimo = 999999999999999;
	int pos;
	for(int i=0;i<len;i++){
		if(materia[i].inscriptos < minimo){
			minimo = materia[i].inscriptos;
			pos = i;
		}
	}
	return pos;
}

int BuscarMaximo(CodigoInscripciones materia[], int len){
	float maximo = 0;
	int pos;
	for(int i=0;i<len;i++){
		if(materia[i].inscriptos > maximo){
			maximo = materia[i].inscriptos;
			pos = i;
		}
	}
	return pos;
}

float PromedioInscripciones(CodigoInscripciones materia[], int len){
	float promedio;
	float suma = 0;
	for(int i=0;i<len;i++){
		suma += materia[i].inscriptos;
	}
	promedio = suma/ len;
	return promedio;
}

