#include <iostream>
using namespace std;

void unionvectores(int vecA[], int lenA, int vecB[], int lenB, int vecC[], int &lenC){
	
	bool enc;
	
	for(int i=0;i<lenA;i++){
		buscaeinserta(vecC,lenC,vecA[i],enc);
	}
	
	for(int i=0;i<lenB;i++){
		buscaeinserta(vecC,lenC,vecB[i],enc);
	}
	
	return;
}
	
