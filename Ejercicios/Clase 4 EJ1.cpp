#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
bool esMultiplo (int a, int b);
int main() {
	int a,b;
	
	cout<<"ingrese a";
	cin>>a; 
	cout<<"ingrese b";
	cin>>b;
	
	if (esMultiplo(a,b) == 1){
		cout<<"true";
	} else {
		cout<<"false";
	}

}

bool esMultiplo (int a, int b){
	int multiplo;
	if (a%b==0){
		multiplo=1;
	} else {
		multiplo=0;
	}
	
	return multiplo;
}


