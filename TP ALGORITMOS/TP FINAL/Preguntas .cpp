//�Qui�n quiere ser billonario?
#include<iostream>
#include<cstring>
#include<conio.h>

using namespace std;

struct informacion{
	char categoria[20];
	char pregunta[120];
	char respuestaCorrecta[50];
	bool preguntaHabilitada;
};

int main(){
	// alcance del programa modificado
	// a debe ser 42 (6 preguntas* 7 categorias)
	int a=42;
	// b debe ser 7 (7 categorias)
	int b=6;
	
	informacion base[a];
	informacion reg;
	FILE*Preguntas=fopen("preguntas.dat","wb+");
	
	
	cout<<"Bienvenido a �Quien quiere ser billonario?"<<endl;
	cout<<"El juego cuenta con 7 categorias de preguntas"<<endl;
	
	// CAT 1 
	strcpy(base[0].categoria,"Arte");
	strcpy(base[0].pregunta,"�Qu� tendencia musical es la que m�s incursiona en Jamaica? A) Rock B) Reggae C) Pop");
	strcpy(base[0].respuestaCorrecta,"B");
	strcpy(base[1].categoria,"Arte");
	strcpy(base[1].pregunta,"�Qu� usamos para diluir los colores de las acuarelas? A) Agua B) Tiner C) Nafta");
	strcpy(base[1].respuestaCorrecta,"A");
	strcpy(base[2].categoria,"Arte");
	strcpy(base[2].pregunta,"�Qu� nota musical hay entre re y fa? A) Sol B) Do C) Mi");
	strcpy(base[2].respuestaCorrecta,"C");
	strcpy(base[3].categoria,"Arte");
	strcpy(base[3].pregunta,"�Qui�n escribi� 'El Diario de Ana Frank'? A) Ana Frank B) Su madre C) Su tio");
	strcpy(base[3].respuestaCorrecta,"A");
	strcpy(base[4].categoria,"Arte");
	strcpy(base[4].pregunta,"�En qu� pa�s naci� Jorge Luis Borges?  A) Argentina B) Chile C) Colombia");
	strcpy(base[4].respuestaCorrecta,"A");
	strcpy(base[5].categoria,"Arte");
	strcpy(base[5].pregunta,"�Qui�n era la diosa de la sabidur�a en la mitolog�a griega? A) Medusa B) Atenea C) Afrodita");
	strcpy(base[5].respuestaCorrecta,"B");
	
	// CAT 2
	strcpy(base[6].categoria,"Ciencia");
	strcpy(base[6].pregunta,"�A qu� edad alcanzan la madurez las cr�as de elefante? A) 12-15 A�os B) 20-25 A�os C) 5-10 A�os");
	strcpy(base[6].respuestaCorrecta,"B");
	strcpy(base[7].categoria,"Ciencia");
	strcpy(base[7].pregunta,"�En matem�ticas, �qu� es 3,14 ?  A) PI B) E C) PE");
	strcpy(base[7].respuestaCorrecta,"A");
	strcpy(base[8].categoria,"Ciencia");
	strcpy(base[8].pregunta,"�Qu� �rgano es el encargado de fabricar insulina?  A) Higado B) Pancreas C) Ri�ones");
	strcpy(base[8].respuestaCorrecta,"B");
	strcpy(base[9].categoria,"Ciencia");
	strcpy(base[9].pregunta,"�Qu� registra un sism�grafo?  A) Temblores de la tierra B) Temperatura de la tierra C) Densidad de la tierra");
	strcpy(base[9].respuestaCorrecta,"A");
	strcpy(base[10].categoria,"Ciencia");
	strcpy(base[10].pregunta,"�Cuantas patas tienen las ara�as?  A) 6 B) 4 C) 8 ");
	strcpy(base[10].respuestaCorrecta,"C");
	strcpy(base[11].categoria,"Ciencia");
	strcpy(base[11].pregunta,"�Cu�l es el s�mbolo qu�mico de la plata?  A) P B) Ag C) Pl ");
	strcpy(base[11].respuestaCorrecta,"B");
	
	// CAT 3
	strcpy(base[12].categoria,"Deportes");
	strcpy(base[12].pregunta,"�Qui�n gan� el mundial de 2010 en Sud�frica? A) Italia B) Espa�a C) Holanda");
	strcpy(base[12].respuestaCorrecta,"B");
	strcpy(base[13].categoria,"Deportes");
	strcpy(base[13].pregunta,"�Cu�l es el nombre de pila del tenista Federer? A) Roger B) Rick C) Robert ");
	strcpy(base[13].respuestaCorrecta,"A");
	strcpy(base[14].categoria,"Deportes");
	strcpy(base[14].pregunta,"�Cu�ntos jugadores componen usualmente un equipo de rugby? A) 10 B) 15 C) 20 ");
	strcpy(base[14].respuestaCorrecta,"B");
	strcpy(base[15].categoria,"Deportes");
	strcpy(base[15].pregunta,"�Qui�n tiene m�s balones de oro? A) C.Ronaldo B) Maradona C) L.Messi");
	strcpy(base[15].respuestaCorrecta,"C");
	strcpy(base[16].categoria,"Deportes");
	strcpy(base[16].pregunta,"�A qu� deporte le corresponde el *c�rner corto*? A) Hockey sobre cesped B) Futbol para enanos C) Golf en shorts");
	strcpy(base[16].respuestaCorrecta,"A");
	strcpy(base[17].categoria,"Deportes");
	strcpy(base[17].pregunta,"�Cu�ntas jugadoras participan en un juego de volleyball? A) 8 B) 6 C) 10");
	strcpy(base[17].respuestaCorrecta,"B");
	
	// CAT 4
	strcpy(base[18].categoria,"Entretenimiento");
	strcpy(base[18].pregunta,"�Quien era Jay Jay? A) Un avioncito B) Un autito C) Una motito");
	strcpy(base[18].respuestaCorrecta,"A");
	strcpy(base[19].categoria,"Entretenimiento");
	strcpy(base[19].pregunta,"�Qu� fruta es la casa de Bob Esponja?  A) Banana B) Pi�a C) Melon ");
	strcpy(base[19].respuestaCorrecta,"B");
	strcpy(base[20].categoria,"Entretenimiento");
	strcpy(base[20].pregunta,"�Cu�l fue la primera pel�cula de Disney? A) Peter pan B) Blancanieves C) Mulan");
	strcpy(base[20].respuestaCorrecta,"B");
	strcpy(base[21].categoria,"Entretenimiento");
	strcpy(base[21].pregunta,"�Qu� grupo musical cantaba *Mamma M�a*?  A) U2 B) High School Musical C) ABBA ");
	strcpy(base[21].respuestaCorrecta,"C");
	strcpy(base[22].categoria,"Entretenimiento");
	strcpy(base[22].pregunta,"�C�mo se llama el hermano menor de Mario Bros? A) Luigi B) Pepe C) Giuseppe ");
	strcpy(base[22].respuestaCorrecta,"A");
	strcpy(base[23].categoria,"Entretenimiento");
	strcpy(base[23].pregunta,"�En qu� a�o naci� Michael Jackson? A) 1959 B) 1958 C) 1960");
	strcpy(base[23].respuestaCorrecta,"B");
	
	// CAT 5
	strcpy(base[24].categoria,"Geograf�a");
	strcpy(base[24].pregunta,"�Cu�l es la capital de Uruguay?  A) Montevideo B) Punta del este C) Colonia ");
	strcpy(base[24].respuestaCorrecta,"A");
	strcpy(base[25].categoria,"Geograf�a");
	strcpy(base[25].pregunta,"�D�nde se encuentra el r�o Nilo? A) America B) Africa C) Asia ");
	strcpy(base[25].respuestaCorrecta,"B");
	strcpy(base[26].categoria,"Geograf�a");
	strcpy(base[26].pregunta,"�Cu�ntas estrellas tiene la bandera de China?  A) 6 B) 7 C) 5");
	strcpy(base[26].respuestaCorrecta,"C");
	strcpy(base[27].categoria,"Geograf�a");
	strcpy(base[27].pregunta,"�D�nde queda el pa�s de Per�? A) Sudamerica B) Asia C) Europa");
	strcpy(base[27].respuestaCorrecta,"A");
	strcpy(base[28].categoria,"Geograf�a");
	strcpy(base[28].pregunta,"�Que pais no tiene costas? A) Argentina B) Bolivia C) Ecuador");
	strcpy(base[28].respuestaCorrecta,"B");
	strcpy(base[29].categoria,"Geograf�a");
	strcpy(base[29].pregunta,"�Con cuantos paises limita Argentina? A) 4 B) 5 C) 6");
	strcpy(base[29].respuestaCorrecta,"B");
	
	// CAT 6
	strcpy(base[30].categoria,"Historia");
	strcpy(base[30].pregunta,"�Qu� civilizaci�n antigua ten�a faraones como gobernantes? A) Griegos B) Egipcios C) Nordicos");
	strcpy(base[30].respuestaCorrecta,"B");
	strcpy(base[31].categoria,"Historia");
	strcpy(base[31].pregunta,"�Qu� pa�s comenz� la Segunda Guerra Mundial? A) Alemania B) EEUU C) China");
	strcpy(base[31].respuestaCorrecta,"A");
	strcpy(base[32].categoria,"Historia");
	strcpy(base[32].pregunta,"�Cu�ndo se viaja por primera vez al espacio?  A) 1959 B) 1961 C) 1960");
	strcpy(base[32].respuestaCorrecta,"B");
	strcpy(base[33].categoria,"Historia");
	strcpy(base[33].pregunta,"�Qu� ciudad qued� partida en dos tras la Segunda Guerra Mundial? A) Frankfurt B) Munich C) Berlin");
	strcpy(base[33].respuestaCorrecta,"C");
	strcpy(base[34].categoria,"Historia");
	strcpy(base[34].pregunta,"�Qui�n fue Lu�s XIV?  A) Rey de Espa�a B) Rey de Inglaterra C) Rey de Francia");
	strcpy(base[34].respuestaCorrecta,"C");
	strcpy(base[35].categoria,"Historia");
	strcpy(base[35].pregunta,"�Qui�n fue el primer presidente de los Estados Unidos? A) Washington B) Lincoln C) Jefferson");
	strcpy(base[35].respuestaCorrecta,"A");
	


	for(int i=0;i<a;i++){
		base[i].preguntaHabilitada=1;
	}
	for(int i=0;i<a;i++){
		fwrite(&base[i],sizeof(informacion),1,Preguntas);
	}

	cout<<"Todas las preguntas y respuestas han sido cargadas"<<endl;
	cout<<"Desea conocer la Base de Preguntas y Respuestas del Juego"<<endl;
	cout<<"Presione 1 para conocerla. Presione 0 para finalizar"<<endl;
	
	int boton;
	cin>>boton;
	system("cls");
	
	if(boton==1){
		
		cout<<"Base de Preguntas y Respuestas del Juego"<<endl<<endl;
		
		for(int i=0; i<a; i++){
			cout<<i+1<<")"<<endl;
			cout<<"Categoria: "<<base[i].categoria<<endl;
			cout<<"Pregunta: "<<base[i].pregunta<<endl;
			cout<<"Respuesta: "<<base[i].respuestaCorrecta<<endl;
			cout<<"Status: "<<base[i].preguntaHabilitada<<endl<<endl;
		}
	
	fclose(Preguntas);	
	
	}else{
		
		cout<<"Etapa de carga de informacion finalizada";
		
	}
	
	fclose(Preguntas);
	
	system("pause");
	
	}
