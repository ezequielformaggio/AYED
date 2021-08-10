#include <iostream>
#include <string>
using std::string;
using namespace std;

	struct TipoDocumento {
		
		string tipo;
		int numero;
	} documento;
	

	struct TipoAlumno {
		
		long legajo;
		string nombre;
		string apellido;
		TipoDocumento documento;
		float promedio;
	} alumno;
	
int main() {
	
	TipoAlumno alumno;
	alumno.legajo = 1628665;
	alumno.nombre = "Edo";
	alumno.apellido = "sorba";
	alumno.documento.numero = 41138345;
	alumno.documento.tipo = "DNI";
	
	cout << alumno.documento.tipo << alumno.documento.numero << alumno.nombre << alumno.apellido << endl;
	
	return 0;
}
