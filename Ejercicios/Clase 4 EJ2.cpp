#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
float calcularPorcentajeDiferencia (long a, long b);
int main() {
	int a,b;
	
	cout<<"ingrese a";
	cin>>a; 
	cout<<"ingrese b";
	cin>>b;
	
	cout<<"el resultado es" << calcularPorcentajeDiferencia (a,b);

}

float calcularPorcentajeDiferencia (long a, long b){
	int porcentaje;
	porcentaje=(b-a)*100/(a+b);
	
	return porcentaje;
}


