#include <iostream>
#include <string.h>
#include<stdio.h> 
#include<string> 
using namespace std;

// Ejercicio 1 
int DiaNumero(int D, int M, int A);
int main(int argc, char** argv) {
	
	int D,M,A,F;
	char c[10];
	
	cout<<"Ingrese un dia"<<endl;
	cin>>D;
	
	cout<<"Ingrese un mes"<<endl;
	cin>>M;
	
	cout<<"Ingrese un año"<<endl;
	cin>>A;
	
	F=DiaNumero(D,M,A);
	
	switch(F){
		
		case 0: Strcpy (c,"Domingo");
		case 1: Strcpy (c,"Lunes");
		case 2: Strcpy (c,"Martes");
		case 3: Strcpy (c,"Miercoles");
		case 4: Strcpy (c,"Jueves");
		case 5: Strcpy (c,"Viernes");
		case 6: Strcpy (c,"Sabado");
		
	}
	
	cout<<"La fecha ingresada corresponde al dia" << c <<endl;
	return 0;
}
