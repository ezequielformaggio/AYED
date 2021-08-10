#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
long sumarHora(long h, long o);
int main() {
	long h,o;
	long dia;
	
	cout<<"ingrese hora minutos y segundos";
	cin>>h; 
	cout<<"ingrese tiempo adicional";
	cin>>o;
	
	dia=(h/10000+o/10000)/24;
	
	cout<<"resultado= "<<sumarHora(h,o)<<" y pasaron "<<dia<<" dias";

}

long sumarHora(long h, long o){
	long res;
	
	res=h+o;
	
	return res;
}


