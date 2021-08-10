#include <iostream>
#include "vectores.hpp"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop 

Ejercicio Nro. 2:
Dado un vector de notas que contiene el código de la materia y la cantidad de alumnos inscriptos obtenida. Se sabe que hay 50 materias, determinar:
a- ¿Cuál fue la materia que más inscriptos tuvo?
b- ¿Cuál fue la materia que menos inscriptos tuvo?
c- Calcular el promedio de inscriptos en todas las materias.

*/

int main(int argc, char** argv) {
	//Vectores con Struct - Ejercicio 1
	CodigoInscripciones materia[50];
	int lenMaterias =0;
	int pos;
	float promedio;
	
	cout << "ingrese la cantidad de materias a registrar" << endl;
	cin >> lenMaterias;
	
	for(int i=0;i<lenMaterias;i++){
		
		cout << "ingrese el codigo de la materia" << endl;
		cin >> materia[i].codigo;
		cout << "ingrese la cantidad de alumnos inscritos de la materia" << endl;
		cin >> materia[i].inscriptos;
		i++;
	}
	pos = BuscarMinimo(materia[],lenMaterias);
	cout << "La materia de codigo " << materia[pos].codigo << " tiene " << materia[pos].inscriptos << " cantidad de alumnos inscriptos siendo la materia con menor cantidad de los mismos" << endl;
	pos = BuscarMaximo(materia[],lenMaterias);
	cout << "La materia de codigo " << materia[pos].codigo << " tiene " << materia[pos].inscriptos << " cantidad de alumnos inscriptos siendo la materia con mayor cantidad de los mismos" << endl;	
	promedio = PromedioInscripciones(materia[],lenMaterias);
	cout << "El promedio de inscriptos es " << promedio << endl;
	return 0;
}
