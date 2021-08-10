#include<string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop 

Ejercicio Nro. 2:
Dado un vector de notas que contiene el c�digo de la materia y la cantidad de alumnos inscriptos obtenida. Se sabe que hay 50 materias, determinar:
a- �Cu�l fue la materia que m�s inscriptos tuvo?
b- �Cu�l fue la materia que menos inscriptos tuvo?
c- Calcular el promedio de inscriptos en todas las materias.

*/

struct CodigoInscripciones {
	
	int codigo;
	int inscriptos;
};

#ifndef vectores
#define vectores

int BuscarMinimo(CodigoInscripciones materia, int len);
int BuscarMaximo(CodigoInscripciones materia, int len);
float PromedioInscripciones(CodigoInscripciones materia, int len);

#endif
