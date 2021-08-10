#include <iostream>
#include <string>
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

struct DatosAlumnos {
	int legajo;
	string nombre;
	int nota;

} alumno;

