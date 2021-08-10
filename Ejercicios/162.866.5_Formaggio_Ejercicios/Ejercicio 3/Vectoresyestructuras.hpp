/*
Ejercicio Nro. 3:
Realizar un programa que gestione los datos de stock de un quiosco, la información a guardar será: 
código del producto, nombre del producto, precio y cantidad en stock. 
El quiosco dispone de 10 productos distintos.
El programa debe ser capaz de:
a- Dar de alta un producto nuevo.
b- Buscar un producto por su nombre.
c- Modificar el stock y precio de un producto dado.
*/
#include <iostream>
#include <string>
using std::string;
using namespace std;

struct Stockquiosco {
	int codigo;
	string nombre;
	int precio;
	int cantidad;
} producto;


