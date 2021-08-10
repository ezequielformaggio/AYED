//¿Quién quiere ser billonario?
#include<iostream>
#include<cstring>
#include<ctime>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

//Definición de estructuras
struct categorias{
	char categoria[30];
	int categoriaHabilitada;
};

struct informacion{
	char categoria[20];
	char pregunta[120];
	char respuestaCorrecta[50];
	bool preguntaHabilitada;
};

struct partida{
	char jugador[30];
	int puntajeTotal;
	bool habilitado;
};

struct consolidado{
	char jugador[30];
	int puntajeTotal;
	char preguntaDada[120];
	char respuestaDada[50];
	char resultado[10]; // si es que respondio bien o no
	char hora[9];	
};
struct Nodo{
	consolidado info;
	Nodo* sig;
};

void cargaPreguntas(informacion base[]);



int main(){

	informacion base[42]; //debe ser 42
	consolidado historico[42];//debe ser 42
	
	int confirmacion;
	char confirmacionNombre;
	int continuar;
	
	//Estructura de hora
	char hora[3];
	char min[3];
	char sec[3];
	char horario[9];
	
	time_t now= time(0);
	tm*timeh=localtime(&now);
	
	itoa(timeh->tm_hour,hora,10);
	itoa(timeh->tm_min,min,10);
	itoa(timeh->tm_sec,sec,10);
	
	strcat(horario,hora);
	strcat(horario,":");
	strcat(horario,min);
	strcat(horario,":");
	strcat(horario,sec);
	
	cout<<"Hora de inicio  "<<horario<<endl;
	
	// FILE*preguntas=fopen("preguntas.dat","rb+");
	FILE*history=fopen("historico.dat","wb+");

 
	cargaPreguntas(base);	

//Presentacion del juego                                                                                                 
	cout<<"Bienvenido a ¿QUIEN QUIERE SER BILLONARIO?"<<endl<<endl;
	cout<<"Menu principal"<<endl;
	cout<<"1) Nueva partida"<<endl;
	cout<<"2) Cargar partida anterior"<<endl;
	cout<<"Presione una opcion (1 o 2) para continuar..."<<endl;
	int menu;
	cin>>menu;
	system("cls");
	

	
//1) Nueva Partida

	
	if(menu==1){
		
		int contadorDePreguntas=0;
		partida nombreJugador[5];
		consolidado reg;
		
		
		//Ingresar participantes 
		cout<<"Bienvenido al juego ¿Quien quiere ser billonario?"<<endl<<endl;
		cout<<"Para comenzar la partida reuna 5 Jugadores"<<endl;
		
		//
		int cantidadDeJugadores=5;
		//
		cout<<"Ingresen los nombres de los Jugadores"<<endl<<endl;
		for(int i=0;i<cantidadDeJugadores;i++){
			cout<<"Jugador "<<i+1<<endl;
   			cin>>nombreJugador[i].jugador;
   			
			//Confirmacion de los nombres ingresados
/*
	for(int i=0;i<5;i++){
			cout <<"Jugador"<< i <<endl<<endl;
   			cin >> jugadores[i].jugador;
    		cout <<endl<< "acaba de ingresar el nombre: "<< jugadores[i].jugador << ", ¿es este nombre correcto?"<< endl << "Responda 's' para continuar, o 'n' para modificarlo"<< endl<<endl;
    		cin >> confirmacion;
    		
			switch(confirmacion){

				case 's':
				strcpy(reg.jugador,jugadores[i].jugador);
				fwrite(&reg.jugador,sizeof(consolidado),1,history);
				system("cls"); 
				
				break;
		
				case 'n':
					while(confirmacion=='n'){
						cout << endl << "bien, ingrese el nombre nuevamente" <<endl << endl; 
    					cin >> jugadores[i].jugador;
    					cout << endl <<"acaba de ingresar el nombre: "<< jugadores[i].jugador << ", ¿es este nombre correcto?"<< endl << "Responda 's' para continuar, o 'n' para modificarlo"<< endl;
    					cin >> confirmacion;
    				}
				break;
		
				default:
					cout << "default" << endl;
					while(confirmacion!='n' && confirmacion!='s'){
						cout <<endl<< "opcion incorrecta, por favor responda 's' para continuar, o 'n' para cambiar el nombre"<<endl;
						cin >> confirmacion;
						while(confirmacion=='n'){
							cout << endl << "bien, ingrese el nombre nuevamente" <<endl << endl; 
    						cin >> jugadores[i].jugador;
    						cout << endl <<"acaba de ingresar el nombre: "<< jugadores[i].jugador << ", ¿es este nombre correcto?"<< endl << "Responda si para continuar, o no para modificarlo"<< endl;
    						cin >> confirmacion;
    						
    						if(confirmacion=='s'){
    							strcpy(reg.jugador,jugadores[i].jugador);
								fwrite(&reg.jugador,sizeof(consolidado),1,history);
							}
						}
				   }
				break;
			}*/
		}
		
		// se cargaron 5 jugadores en el archivo
			
		cout<<"Presione 0 para continuar"<<endl;
		cin>>confirmacion;
		system("cls");
			
		//Imprimir los jugadores por pantalla 
		cout<<"Comienza la partida!"<<endl<<endl;
		cout<<"Los jugadores son: "<<endl;
		for(int n=0;n<cantidadDeJugadores;n++){
			cout <<nombreJugador[n].jugador<<endl;
		}
		//Puntajes en cero y Jugadores habilitados
		for(int i=0;i<cantidadDeJugadores;i++){
			nombreJugador[i].puntajeTotal=0;
			nombreJugador[i].habilitado=true;
		}
				
				
	//Comienza la Jugada

	cout<<endl<<"Cada participante respondera 5 preguntas, una por turno. "<<endl;
	cout<<"El participante con mas respuestas correctas sera el ganador. "<<endl<<"¡Comencemos!"<<endl;
	cout<<endl<<"Presione una tecla para continuar..."<<endl;
	getch();
	system("cls");
		
	char respuestaJugador[10];
	
//La primera ronda tiene 25 preguntas


		for(int j=0;j<1;j++){ 
						
// pregunta aleatoria
		
		int numAleatorio;
		srand(time(NULL));		 
		numAleatorio = rand()%36;
		
		
		for (int i=0; i<5; i++){
		cout<<"Es el turno de "<<nombreJugador[i].jugador<<endl<<endl;  
		//strcpy(historico[i].jugador,jugadores[i].jugador);
		
		if(base[numAleatorio].preguntaHabilitada==true){
			
			cout<<"Categoria: " << base[numAleatorio].categoria<<endl;
			cout<<"La pregunta es: "<<base[numAleatorio].pregunta<<endl;
			strcpy(historico[i].preguntaDada,base[numAleatorio].pregunta);
			
		}else{
			
		while(base[numAleatorio].preguntaHabilitada==false){
			
			numAleatorio = rand()%36;
			
			if(base[numAleatorio].preguntaHabilitada==true){
				
				cout<<"Categoria: " << base[numAleatorio].categoria<<endl;
				cout<<"La pregunta es: "<<base[numAleatorio].pregunta<<endl;
				strcpy(historico[i].preguntaDada,base[numAleatorio].pregunta);
		}
		}
	}
		    // INGRESAR RESPUESTA
		    
			cout<<"Ingrese su respuesta: "<<endl;
			cin>>respuestaJugador;
			base[numAleatorio].preguntaHabilitada=false;
			//strcpy(historico[m].respuestasRespondidas,respuestaJugador);
						
			
			if(strcmp(respuestaJugador, base[numAleatorio].respuestaCorrecta)==0){
				cout<<"Respuesta correcta!"<<endl<<endl;
				nombreJugador[i].puntajeTotal=nombreJugador[i].puntajeTotal+1;	
				//strcpy(historico[m].resultado,"Correcto");
				
			}else{
				cout<<"Respuesta incorrecta"<<endl<<endl;
				nombreJugador[i].puntajeTotal=nombreJugador[i].puntajeTotal+0;
				//strcpy(historico[m].resultado,"Incorrecto");
			}
			
			//historico[m].puntajeParcial=jugadores[i].puntajeTotal;
			cout<<horario<<endl;
			//strcpy(historico[m].hora,horario);
			
			//fwrite(&historico[m],sizeof(consolidado),1,history);
			
			cout<<endl<<"Presione una tecla para continuar..."<<endl;
			getch();
			system("cls");	
		
			}	
			contadorDePreguntas=contadorDePreguntas+1;
			cout<<"Estado parcial de Juego"<<endl<<endl;
			cout<<"Acaba de terminar la ronda n°"<<j+1<<endl;
			for(int i=0;i<cantidadDeJugadores;i++){ //La cantidad de jugadores default es 5
				cout<<"Jugador "<<nombreJugador[i].jugador<<" tiene "<<nombreJugador[i].puntajeTotal<<" puntos"<<endl;
			}
		
		
		
		
		
		cout<<endl<<"Presione una tecla para continuar..."<<endl;
		getch();
		system("cls");	
		
				

		
}


	//Resultados: Ganador o empate 
	bool hayGanador=false;
	cout<<"La ronda de preguntas ha terminado"<<endl<<endl;
	cout<<"El centro de computos dice que.."<<endl;
	
	int puntajeMaximo=-1;
	int cantJugadoresMaximo=0;
	char jugadorGanador[30];
		
	for(int i=0;i<5;i++){ 
	
		if(nombreJugador[i].puntajeTotal > puntajeMaximo){
			
			puntajeMaximo=nombreJugador[i].puntajeTotal;

		}
	}
	
	for (int i=0;i<5;i++){
			
		 if(nombreJugador[i].puntajeTotal == puntajeMaximo){
		 	
			cantJugadoresMaximo++;
			
			if(cantJugadoresMaximo==1){
			
			strcpy(jugadorGanador,nombreJugador[i].jugador);
		}
		
	}
				
 }


	
	switch(cantJugadoresMaximo){
		case 1:
			cout<<"Tenemos un ganador"<<endl;
			hayGanador=true;
			cout<<jugadorGanador<<" ha ganado!"<<endl<<endl;
			
			for(int i=0;i<cantidadDeJugadores;i++){
				nombreJugador[i].habilitado=false;
			}
			
			cout<<"Presione 0 para continuar. Presione 1 para ver el Historico completo."<<endl;
			cin>>confirmacion;
			system("cls");
			
			if(confirmacion==1){
				cout<<"Historico completo:"<<endl<<endl;
				for(int m=0; m<contadorDePreguntas; m++){
					cout<<m+1<<")"<<endl;
					cout<<"Jugador: "<<historico[m].jugador<<". Puntaje total acumulado: "<<historico[m].puntajeTotal<<" puntos"<<endl;
					cout<<"Pregunta: "<<historico[m].preguntaDada<<". Respuesta: "<<historico[m].respuestaDada<<". Resultado: "<<historico[m].resultado<<endl;
					cout<<"Hora: "<<historico[m].hora<<endl<<endl;	
				}
				cout<<"Presione 0 para finalizar"<<endl;
				cin>>continuar;
				system("cls");
			}
			else{
				cout<<"La partida ha finalizado"<<endl;
			}
			break;
			
			 // caso empate
			 
		default:
			
			cout<<"Hay empate"<<endl;
			hayGanador=false;
			cout<<"La disputa esta entre:.. "<<endl;
			
			// buscamos que cantidad de jugadores tienen puntaje maximo y los habilitamos
			
			for(int i=0;i<cantJugadoresMaximo;i++){
				
				if(nombreJugador[i].puntajeTotal==puntajeMaximo){
					cout<<nombreJugador[i].jugador<<endl;					
				}
				
				else{ // deshabilitamos jugadores que no tienen puntaje mazimo
				nombreJugador[i].habilitado=false;	
				}
				
			}
			
			cout<<"Continuemos la ronda por el desempate!"<<endl;
			cout<<"Recuerde que si no acierta la respuesta quedara fuera de juego."<<endl;
			cout<<"Presione 0 para continuar"<<endl;
			cin>>confirmacion;
			system("cls");
					
			
			int t=6; //numero de ronda inicial
			char jugadorGanador[30];
			
			while(cantJugadoresMaximo>1){
				
				cout<<"Ronda"<<t<<endl;
				t++;
				int numAleatorio;
				
				for(int j=0;j<cantJugadoresMaximo;j++){  
					
						
					if(nombreJugador[j].habilitado==true){
						//fread(&base[i],sizeof(informacion),1,Preguntas);
				 
						cout<<"Es el turno de "<<nombreJugador[j].jugador<<endl<<endl;
						//strcpy(historico[i].jugador,nombreJugador[j].jugador);
						
						numAleatorio = rand()%36;
						
						if(base[numAleatorio].preguntaHabilitada==true){
			
						cout<<"Categoria: " << base[numAleatorio].categoria<<endl;
						cout<<"La pregunta es: "<<base[numAleatorio].pregunta<<endl;
						//strcpy(historico[i].preguntaDada,base[numAleatorio].pregunta);
			
						}else{
			
						while(base[numAleatorio].preguntaHabilitada==false){
			
						numAleatorio = rand()%36;
			
						if(base[numAleatorio].preguntaHabilitada==true){
				
						cout<<"Categoria: " << base[numAleatorio].categoria<<endl;
						cout<<"La pregunta es: "<<base[numAleatorio].pregunta<<endl;
						//strcpy(historico[i].preguntaDada,base[numAleatorio].pregunta);
								
								
						}
					}
				}
				
				cin>>respuestaJugador;
				if(strcmp(respuestaJugador, base[numAleatorio].respuestaCorrecta)==0){
				cout<<"Respuesta correcta!"<<endl<<endl;
				nombreJugador[j].puntajeTotal++;	
				//strcpy(historico[m].resultado,"Correcto");
				
			}else{
				
				cout<<"Respuesta incorrecta"<<endl<<endl;
				nombreJugador[j].habilitado==false;
				cantJugadoresMaximo--;
			}
			
			cout<<horario<<endl;
			
			cout<<endl<<"Presione una tecla para continuar..."<<endl;
			getch();
			system("cls");	
		
			}	
			contadorDePreguntas++;
			cout<<"Estado parcial de Juego"<<endl<<endl;
			cout<<"Acaba de terminar la ronda n°"<<j+1<<endl;
			for(int i=0;i<cantJugadoresMaximo;i++){ 
			cout<<"Jugador "<<nombreJugador[i].jugador<<" tiene "<<nombreJugador[i].puntajeTotal<<" puntos"<<endl;
			}	
			
  

	 } 
	 
	 	break;
	 	
} // cierra el while, ya tenemos ganador

		for(int i=0;i<5;i++){
			if(nombreJugador[i].habilitado==true){
			
			strcpy(jugadorGanador,nombreJugador[i].jugador);
		}
	 }
				 
// indicar quien gano
cout<<"gano "<<jugadorGanador<<endl;

} // cierra el switch


	}	//cierre if(menu ==1)

} // cierro el main





	
	//fclose(history);

////////////////////////////////////////////////////////////////////FUNCIONES/////////////////////////////////////////////////////////////////////////////////////////

		void cargaPreguntas(informacion base[]){
			
			FILE*preguntas=fopen("preguntas.dat","rb+");
			
			informacion reg;
			for(int I=0;I<35;I++){
				fread(&reg,sizeof(informacion),1,preguntas);
				strcpy(base[I].categoria,reg.categoria);
				strcpy(base[I].pregunta,reg.pregunta);
				strcpy(base[I].respuestaCorrecta,reg.respuestaCorrecta);
				base[I].preguntaHabilitada=reg.preguntaHabilitada;
				
			}
			fclose(preguntas);
			return;
			
			
			
		}
		
