#include <iostream>
#include <string>
#include "Vectoresyestructuras.hpp"
using std::string;
using namespace std;

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


// preguntar si es mejor usar funciones por el hecho de que cada operacion devuelve mas de un valor

int main(int argc, char** argv) {
	
	Stockquiosco producto[10] = {{10,"caramelos",1,60},{20,"caramelos",1,60},{30,"cigarrillos",150,3},{40,"cocacola",98,80},{50,"yogurt",40,70},{60,"agua",25,60},{70,"sanguche",60,80},{80,"cafe",20,20},{90,"chupetines",3,50},{100,"chocolate",30,5}};
	int operacion=0, pos=0, exist=0, codigo=0, code=0;
	string comparacion;
	
	cout << "Bienvenido, ingrese el numero de operacion que desea realizar:" << endl << "1) Dar de alta un producto nuevo" << endl << "2) Buscar un prducto por su nombre" << endl << "3) Modificar el stock y precio de un producto dado" << endl;
	cin >> operacion;
	
	if (operacion==1){
		
		Stockquiosco.cantidad
		St
		
		cout << "Ingrese los datos del producto, comenzando por su codigo:" << endl;
		cin >> producto[pos].codigo;
		// si se ingresa el nomnre del producto con espacios, el programa termina y no se porque
		cout << "Ahora ingrese el nombre del producto por favor (sin espacios):" << endl;
		cin >> producto[pos].nombre;
		cout << "Ahora ingrese el precio:" << endl;
		cin >> producto[pos].precio;
		cout << "Para finalizar, indique la cantidad en stock:" << endl;
		cin >> producto[pos].cantidad;
		pos++;
	} 
	
	//b- Buscar un producto por su nombre.
	if (operacion==2){
		
		cout << "Ingrese el nombre del producto que desea buscar:" << endl;
		cin >> comparacion;
		
		for(int i=0;i<10;i++){
			
			if(comparacion.compare(producto[i].nombre)==0){
				
				cout << "Informacion del producto que busca:" << endl;
				cout << "Codigo de producto: " << producto[i].codigo << endl;
				cout << "Nombre del producto: " << producto[i].nombre << endl;
				cout << "El precio del prducto es $" << producto[i].precio << endl;
				cout << "El stock disponible del producto es: " << producto[i].cantidad << endl;
				exist=1;
		}
	}
				
			if(exist==0){
				
				cout << "El producto no existe" << endl;
			}

		
	}
	
	//c- Modificar el stock y precio de un producto dado.
	if (operacion==3) {
		
		cout << "Inserte el codigo del producto del cual desea modificar los datos: " << endl;
		cin >> codigo;
		
		for (int j=0;j<10;j++){
			
			if(codigo==producto[j].codigo){
				
				cout << "Ingrese la cantidad nueva de stock: " << endl;
				cin >> producto[j].cantidad;
				cout << "Ingrese el nuevo precio del producto: " << endl;
				cin >> producto[j].precio;
				code = 1;
			} 
		}
			if(code==0){
				
				cout << "El producto no existe" << endl;
			}

		
		
		
	}
	
	
	return 0;
}
