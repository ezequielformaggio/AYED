



int main(){
	partida jugadores[5];
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
	
	FILE*billonario=fopen("billonario.dat","rb+");
	FILE*history=fopen("historico.dat","wb+");

	
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
		consolidado reg;
		
		// seteo el archivo historico en 0
		fwrite(&reg,sizeof(consolidado),1,history);
		
		while(!feof(history)){
			strcpy(reg.jugador,"no se ingreso un nombre todavia...")
			reg.preguntasRespondidas=0;
			reg.puntajeParcial=0;
			reg.respuestasRespondidas=0;
			reg.resultado=0;
		}
		
		//Ingresar participantes 
		cout<<"Bienvenido al juego ¿Quien quiere ser billonario?"<<endl<<endl;
		cout<<"Para comenzar la partida reuna 5 Jugadores"<<endl;
		
		//
		int cantidadDeJugadores=5;
		//
		cout<<"Ingresen los nombres de los Jugadores"<<endl<<endl;
		for(int i=0;i<cantidadDeJugadores;i++){
			cout<<"Jugador "<<i+1<<endl;
   			cin>>jugadores[i].jugador;
   			
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
			cout <<jugadores[n].jugador<<endl;
		}
		//Puntajes en cero y Jugadores habilitados
		for(int i=0;i<cantidadDeJugadores;i++){
			jugadores[i].puntajeTotal=0;
			jugadores[i].habilitado=true;
		}
				
	
	//Comienza la Jugada
	cout<<"El juego consta de 5 rondas de preguntas"<<endl;
	cout<<"Cada participante respondera 5 preguntas. El participante con mas respuestas correctas sera el ganador. ¡Comencemos!"<<endl<<endl;
		
	int m=0;
	char respuestaJugador[50];
	
	for(int r=0;r<1;r++){ //Son 5 rondas de juego
		cout<<"Ronda"<<r+1<<endl<<endl;
		for(int i=0;i<5;i++){ //La primera ronda tiene 25 preguntas
			fread(&base[m],sizeof(informacion),1,billonario);
			cout<<"Es el turno de "<<jugadores[i].jugador<<endl<<endl;
			strcpy(historico[m].jugador,jugadores[i].jugador);
			cout<<"Categoria: "<<base[m].categoria<<endl;
			cout<<"La pregunta es: "<<base[m].pregunta<<endl;
			strcpy(historico[m].preguntasRespondidas,base[m].pregunta);
			cout<<"Ingrese su respuesta: "<<endl;
			cin>>respuestaJugador;
			strcpy(historico[m].respuestasRespondidas,respuestaJugador);
						
			
			if(strcmp(respuestaJugador, base[m].respuestaCorrecta)==0){
				cout<<"Respuesta correcta!"<<endl<<endl;
				jugadores[i].puntajeTotal=jugadores[i].puntajeTotal+1;	
				strcpy(historico[m].resultado,"Correcto");
			}else{
				cout<<"Respuesta incorrecta"<<endl<<endl;
				jugadores[i].puntajeTotal=jugadores[i].puntajeTotal+0;
				strcpy(historico[m].resultado,"Incorrecto");
			}
			historico[m].puntajeParcial=jugadores[i].puntajeTotal;
			cout<<horario<<endl;
			strcpy(historico[m].hora,horario);
			
			fwrite(&historico[m],sizeof(consolidado),1,history);
			
			
			m=m+1; 
			contadorDePreguntas=contadorDePreguntas+1;
			cout<<"Estado parcial de Juego"<<endl<<endl;
			for(int i=0;i<cantidadDeJugadores;i++){ //La cantidad de jugadores default es 5
				cout<<"Jugador "<<jugadores[i].jugador<<" tiene "<<jugadores[i].puntajeTotal<<" puntos"<<endl;
			}
			cout<<"Presione 0 para continuar. Presione 1 para ver el Historico hasta el momento. Caso contrario se cerrara la partida"<<endl;
			cin>>confirmacion;
			system("cls");
			
			switch(confirmacion){
				case 0:
				cout<<"Continuamos!"<<endl;
				break;
					
				case 1:
				cout<<"Historico hasta el momento:"<<endl<<endl;
				for(int m=0; m<contadorDePreguntas; m++){
					cout<<m+1<<")"<<endl;
					cout<<"Jugador: "<<historico[m].jugador<<". Puntaje total acumulado: "<<historico[m].puntajeParcial<<" puntos"<<endl;
					cout<<"Pregunta: "<<historico[m].preguntasRespondidas<<". Respuesta: "<<historico[m].respuestasRespondidas<<". Resultado: "<<historico[m].resultado<<endl;
					cout<<"Hora: "<<historico[m].hora<<endl<<endl;	
				}
				cout<<"Presione 0 para continuar"<<endl;
				cin>>continuar; 
				system("cls");
				break;
				
			}//cierro switch
			/*
			if(confirmacion==1){
				cout<<"Historico hasta el momento:"<<endl<<endl;
				for(int m=0; m<contadorDePreguntas; m++){
					cout<<m+1<<")"<<endl;
					cout<<"Jugador: "<<historico[m].jugador<<". Puntaje total acumulado: "<<historico[m].puntajeParcial<<" puntos"<<endl;
					cout<<"Pregunta: "<<historico[m].preguntasRespondidas<<". Respuesta: "<<historico[m].respuestasRespondidas<<". Resultado: "<<historico[m].resultado<<endl;
					cout<<"Hora: "<<historico[m].hora<<endl<<endl;	
				}
				cout<<"Presione 0 para continuar"<<endl;
				cin>>continuar;
				system("cls");
			}
			else{cout<<"Continuamos!"<<endl;	
			}
			*/
		
		}//cierre for
	
		
	}
		
	
	//Resultados: Ganador o empate 
	bool hayGanador;
	cout<<"La ronda de preguntas ha terminado"<<endl<<endl;
	cout<<"El centro de computos dice que.."<<endl;
	
	int puntajeMaximo=0;
	int cantJugadoresMaximo=0;
	char jugadorGanador[30];
		
	for(int i=0;i<cantidadDeJugadores;i++){ 
		if(jugadores[i].puntajeTotal >puntajeMaximo){
			cantJugadoresMaximo=0;
			puntajeMaximo=jugadores[i].puntajeTotal;
			cantJugadoresMaximo=cantJugadoresMaximo+1;
			strcpy(jugadorGanador,jugadores[i].jugador);
		}
		else{ if(jugadores[i].puntajeTotal == puntajeMaximo){
				puntajeMaximo=jugadores[i].puntajeTotal;
				cantJugadoresMaximo=cantJugadoresMaximo+1;
				strcpy(jugadorGanador,jugadores[i].jugador);
				}		
		}
	}
	
	switch(cantJugadoresMaximo){
		case 1:
			cout<<"Tenemos un ganador"<<endl;
			hayGanador=true;
			cout<<jugadorGanador<<" ha ganado!"<<endl<<endl;
			for(int i=0;i<cantidadDeJugadores;i++){
				jugadores[i].habilitado=false;
			}
			
			cout<<"Presione 0 para continuar. Presione 1 para ver el Historico completo."<<endl;
			cin>>confirmacion;
			system("cls");
			
			if(confirmacion==1){
				cout<<"Historico completo:"<<endl<<endl;
				for(int m=0; m<contadorDePreguntas; m++){
					cout<<m+1<<")"<<endl;
					cout<<"Jugador: "<<historico[m].jugador<<". Puntaje total acumulado: "<<historico[m].puntajeParcial<<" puntos"<<endl;
					cout<<"Pregunta: "<<historico[m].preguntasRespondidas<<". Respuesta: "<<historico[m].respuestasRespondidas<<". Resultado: "<<historico[m].resultado<<endl;
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
			
		default:
			cout<<"Hay empate"<<endl;
			hayGanador=false;
			cout<<"La disputa esta entre:.. "<<endl;
			for(int i=0;i<cantidadDeJugadores;i++){
				if(jugadores[i].puntajeTotal==puntajeMaximo){
					cout<<jugadores[i].jugador<<endl;					
				}
				else{
				jugadores[i].habilitado=false;	
				}
			}
			
			cout<<"Continuemos la ronda por el desempate!"<<endl;
			cout<<"Presione 0 para continuar"<<endl;
			cin>>confirmacion;
			system("cls");
					
			
			int t=5; //numero de ronda inicial
			int i=25;
			while(hayGanador!=true && i<42){
				cout<<"Ronda"<<t<<endl;
				for(int j=0;j<cantidadDeJugadores;j++){
					if(jugadores[j].habilitado==true){
						fread(&base[i],sizeof(informacion),1,billonario);
				 
						cout<<"Es el turno de "<<jugadores[j].jugador<<endl<<endl;
						strcpy(historico[i].jugador,jugadores[j].jugador);
						cout<<"Categoria: "<<base[i].categoria<<endl;
						cout<<"La pregunta es: "<<base[i].pregunta<<endl;
						strcpy(historico[i].preguntasRespondidas,base[i].pregunta);
						cout<<"Ingrese su respuesta: "<<endl;
						cin>>respuestaJugador;
						strcpy(historico[i].respuestasRespondidas,respuestaJugador);
						if(strcmp(respuestaJugador, base[i].respuestaCorrecta)==0){
							cout<<"Respuesta correcta!"<<endl<<endl;
							jugadores[j].puntajeTotal=jugadores[j].puntajeTotal+1;	
							strcpy(historico[i].resultado,"Correcto");
						}else{
							cout<<"Respuesta incorrecta"<<endl<<endl;
							jugadores[j].puntajeTotal=jugadores[j].puntajeTotal+0;
							strcpy(historico[i].resultado,"Incorrecto");
						}
						historico[i].puntajeParcial=jugadores[j].puntajeTotal;
						fwrite(&historico[i],sizeof(consolidado),1,history);
						
						i=i+1; 
						contadorDePreguntas=contadorDePreguntas+1;
						cout<<"Estado parcial de Juego"<<endl<<endl;
						for(int i=0;i<cantidadDeJugadores;i++){ //La cantidad de jugadores default es 5
							cout<<"Jugador "<<jugadores[i].jugador<<" tiene "<<jugadores[i].puntajeTotal<<" puntos"<<endl;
						}
						cout<<"Presione 0 para continuar. Presione 1 para ver el Historico hasta el momento."<<endl;
						cin>>confirmacion;
						system("cls");
			
						if(confirmacion==1){
							cout<<"Historico hasta el momento:"<<endl<<endl;
							for(int m=0; m<contadorDePreguntas; m++){
								cout<<m+1<<")"<<endl;
								cout<<"Jugador: "<<historico[m].jugador<<". Puntaje total acumulado: "<<historico[m].puntajeParcial<<" puntos"<<endl;
								cout<<"Pregunta: "<<historico[m].preguntasRespondidas<<". Respuesta: "<<historico[m].respuestasRespondidas<<". Resultado: "<<historico[m].resultado<<endl;
								cout<<"Hora: "<<historico[m].hora<<endl<<endl;	
							}
							cout<<"Presione 0 para continuar"<<endl;
							cin>>continuar;
							system("cls");
						}
						else{cout<<"Continuamos!"<<endl;	
						}
					}//cierro if
				}//cierro for
				t=t+1;
				int puntajeMaximo=0;
				int cantJugadoresMaximo=0;
				char jugadorGanador[30];
		
				for(int i=0;i<cantidadDeJugadores;i++){ 
					if(jugadores[i].puntajeTotal > puntajeMaximo){
						cantJugadoresMaximo=0;
						puntajeMaximo=jugadores[i].puntajeTotal;
						cantJugadoresMaximo=cantJugadoresMaximo+1;
						strcpy(jugadorGanador,jugadores[i].jugador);
					}
					else{ if(jugadores[i].puntajeTotal == puntajeMaximo){
							puntajeMaximo=jugadores[i].puntajeTotal;
							cantJugadoresMaximo=cantJugadoresMaximo+1;
							strcpy(jugadorGanador,jugadores[i].jugador);
							}
						
					}
				}
				
				if(cantJugadoresMaximo==1){
					cout<<"Tenemos un ganador"<<endl;
					hayGanador=true;
					cout<<jugadorGanador<<" ha ganado!"<<endl<<endl;
					for(int i=0;i<cantidadDeJugadores;i++){
						jugadores[i].habilitado=false;
					}
				
					cout<<"Presione 0 para continuar. Presione 1 para ver el Historico completo."<<endl;
					cin>>confirmacion;
					system("cls");
			
					if(confirmacion==1){
						cout<<"Historico completo:"<<endl<<endl;
						for(int m=0; m<contadorDePreguntas; m++){
							cout<<m+1<<")"<<endl;
							cout<<"Jugador: "<<historico[m].jugador<<". Puntaje total acumulado: "<<historico[m].puntajeParcial<<" puntos"<<endl;
							cout<<"Pregunta: "<<historico[m].preguntasRespondidas<<". Respuesta: "<<historico[m].respuestasRespondidas<<". Resultado: "<<historico[m].resultado<<endl;
							cout<<"Hora: "<<historico[m].hora<<endl<<endl;	
						}
						cout<<"Presione 0 para finalizar"<<endl;
						cin>>continuar;
						system("cls");
					}
					else{
						cout<<"La partida ha finalizado"<<endl;
					}
				
				}
				else{
					hayGanador=false;
				}			
					
			}//cierro while
			if(hayGanador!=true){
				cout<<"Limite de preguntas alcanzado."<<endl;
				cout<<"Presione 0 para continuar. Presione 1 para ver el Historico completo."<<endl;
				cin>>confirmacion;
				system("cls");
			
				if(confirmacion==1){
					cout<<"Historico completo:"<<endl<<endl;
					for(int m=0; m<contadorDePreguntas; m++){
						cout<<m+1<<")"<<endl;
						cout<<"Jugador: "<<historico[m].jugador<<". Puntaje total acumulado: "<<historico[m].puntajeParcial<<" puntos"<<endl;
						cout<<"Pregunta: "<<historico[m].preguntasRespondidas<<". Respuesta: "<<historico[m].respuestasRespondidas<<". Resultado: "<<historico[m].resultado<<endl;
						cout<<"Hora: "<<historico[m].hora<<endl<<endl;	
					}
					cout<<"Presione 0 para finalizar"<<endl;
					cin>>continuar;
					system("cls");
				}
				else{
					cout<<"Partida finalizada"<<endl; 
				}
				
				
			}
			break;
			
			
	}//cierre switch
	
	//Inserto todos los datos en una lista
	/*
	cout<<"Inserto en la lista"<<endl;
	for(int i=0;i<contadorDePreguntas;i++){
		insertarOrdenado(lista,historico[i]);
		;
	}
	cout<<"recorro la lista y encolo"<<endl;
	Nodo* listaAux=lista;
	while(listaAux!=NULL){
		encolar(colafte, colafin,listaAux->info);
		listaAux=listaAux->sig;
	}
	cout<<"recorro la lista y pongo en pila"<<endl;
	while(listaAux!=NULL){
		push(pila, listaAux->info);
		listaAux=listaAux->sig;
	}
	
	cout<<"Resultados de pila lista cola y la mar en coche"<<endl;
	cout<<"aca hago pop pila "<<endl;
		while(listaAux!=NULL){
			consolidado valor;
			valor=pop(pila);
			cout<<valor.jugador<<valor.preguntasRespondidas<<valor.respuestasRespondidas<<valor.resultado<<endl;
			listaAux=listaAux->sig;
		}
		cout<<"Presione 0 para continuar con la partida. "<<endl;
		cin>>continuar;
		system("cls");
		
		cout<<"aca hago desencolar "<<endl;
		while(colafte!=NULL){
			consolidado valor;
			valor=desencolar(colafte,colafin);
			cout<<valor.jugador<<valor.preguntasRespondidas<<valor.respuestasRespondidas<<valor.resultado<<endl;
		}
		*/
	fclose(billonario);
	fclose(history);
	
			
}	//cierre if(menu ==1)
	
	if(menu==2){
		rewind(history);
		/*
		cout<<"Recuperando datos de la partida anterior.."<<endl<<endl;
		cout<<"Historico hasta el momento:"<<endl<<endl;
		/*
		cout<<"aca lestura de archivo"<<endl;
		rewind(hi)
		cout<<"Estos son los jugadores:"<<endl<<endl;
		for(int  i=0;i<5;i++){
			fread(&historico,sizeof(consolidado),1,history);
		}
		cout<<"Presione 0 para continuar con la partida. "<<endl;
		cin>>continuar;
		system("cls");
		*/
		/*
		cout<<"aca hago pop pila "<<endl;
		while(pila!=NULL){
			consolidado valor;
			valor=pop(pila);
			cout<<valor.jugador<<valor.preguntasRespondidas<<valor.respuestasRespondidas<<valor.resultado<<endl;
			pila=pila->sig;
		}
			
		
		cout<<"Presione 0 para continuar con la partida. "<<endl;
		cin>>continuar;
		system("cls");
		
		cout<<"aca hago desencolar "<<endl;
		while(colafte!=NULL){
			desencolar(colafte,colafin);
			
		}
		cout<<"Presione 0 para continuar con la partida. "<<endl;
		cin>>continuar;
		system("cls");
		*/
		
		cout<<"aca muestro un struct"<<endl;
		cout<<"Estado Jugador: "<<historico[0].jugador<<endl;
		cout<<"Puntaje acumulado: "<<historico[0].puntajeParcial<<endl;
		cout<<"Pregunta: "<<historico[0].preguntasRespondidas<<endl;
		cout<<"Respuesta"<<historico[0].respuestasRespondidas<<endl;
		cout<<"Resultado"<<historico[0].resultado<<endl;
		cout<<"Hora"<<historico[0].hora<<endl<<endl;
						
		cout<<"Presione 0 para continuar con la partida. "<<endl;
		cin>>continuar;
		system("cls");
		
		
	}
	  
	
		

	


}
	

