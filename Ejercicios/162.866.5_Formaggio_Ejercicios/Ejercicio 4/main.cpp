#include <iostream>
#include <string>
#include "Datosalumnos.hpp"
using std::string;
using namespace std;
/* 
Ejercicio Nro. 4:
Realizar un programa que sea capaz de 
gestionar las notas de una clase de 
20 estudiantes de los cuales sabemos el 
legajo, el nombre y la nota. 
El programa debe ser capaz de:
a- Buscar un alumno.
b- Modificar su nota.
c- Mostrar el promedio de todas las notas.
*/

int main(int argc, char** argv) {
	
	DatosAlumnos alumno[3]={{1628665,"Ezequiel",8},{1628664,"Edgar",4},{1628663,"Maian",10}};
	int operacion, exist=0, legajo, code=0, suma=0;
	string comparacion;
	
	cout << "Bienvenido, ingrese el numero de operacion que desea realizar:" << endl << "1) Buscar un alumno" << endl << "2) Modificar la nota de un alumno" << endl << "3) Mostrar el promedio de todas las notas" << endl;
	cin >> operacion;
	
//	a- Buscar un alumno.
		if (operacion==1){
		
		cout << "Ingrese el nombre del alumno que desea buscar:" << endl;
		cin >> comparacion;
		
		for(int i=0;i<3;i++){
			
			if(comparacion.compare(alumno[i].nombre)==0){
				
				cout << "Informacion del alumno que busca:" << endl;
				cout << "legajo: " << alumno[i].legajo << endl;
				cout << "Nombre del alumno: " << alumno[i].nombre << endl;
				cout << "La nota del alumno es :" << alumno[i].nota << endl;
				exist=1;
		}
	}
				
			if(exist==0){
				
				cout << "El alumno no existe" << endl;
			}

		
	}
	
	
//	b- Modificar su nota.

		if (operacion==2) {
		
		cout << "Inserte el legajo del alumno del cual desea modificar la nota: " << endl;
		cin >> legajo;
		
		for (int j=0;j<3;j++){
			
			if(legajo==alumno[j].legajo){
				
				cout << "Ingrese la nota nueva: " << endl;
				cin >> alumno[j].nota;
				code = 1;
			} 
		}
			if(code==0){
				
				cout << "El alumno no existe" << endl;
			}

// 	c- Mostrar el promedio de todas las notas.

		if (operacion==3) {
			
			for (int k=0;k<3;k++){
				
				suma += alumno[k].nota;
			
	}
				cout << "El promedio de notas es de " << suma/3 << endl;
}
	return 0;
}

}
