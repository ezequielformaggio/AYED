#include <iostream>
using namespace std;

int DiaNumero(int D, int M, int A){
	
	int bisiestoo=0,x,d;
	int vecRegular[12]={0,3,3,6,1,4,6,2,5,0,3,5};
	int vecBisiesto[12]={0,3,4,0,2,5,0,3,6,1,4,6};
	
	if ((A%4==0 && A%100!=0)||(A%400==0)){
		
		bisiestoo=1;
		x=vecRegular[M-1];
		
	} else {
		
		x=vecBisiesto[m-1];
	}
	
	d=((A-1)%7+((A-1)/4)-((3*((A-1)/100+1))/4)%7+X+D%7)%7;
	
	return d;
}
