/*
 * menu.c
 *
 *  Created on: 21 nov 2022
 *      Author: usuario
 */


#include "menu.h"
//#include "inputs.h"



int cargarMayorId(char* id)
{
	int todoOk=0;
	char idCad[50];
	int auxId;

	FILE* fId= fopen("ManejoId.txt","r");
	if(fId!=NULL)
	{
	fscanf(fId,"%[^\n]",idCad);
	strcpy(id,idCad);
	auxId = atoi(idCad);
	auxId++;
	}
	fclose(fId);

	fId=fopen("ManejoId.txt","w");
	if(fId!=NULL)
	{
		fprintf(fId,"%d",auxId);
		todoOk=1;
	}
	fclose(fId);
	return todoOk;
}

int menuPosicion()
{
	int opcion;
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			"|       POSICIONES       |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("| 1 |PORTERO             |\n"
			"| 2 |DEFENSA CENTRAL     |\n"
			"| 3 |LATERAL IZQUIERDO   |\n"
			"| 4 |LATERAL DERECHO     |\n"
			"| 5 |PIVOTE              |\n"
			"| 6 |MEDIOCENTRO         |\n"
			"| 7 |MEDIOCENTRO OFENSIVO|\n"
			"| 8 |EXTREMO IZQUEIRDO   |\n"
			"| 9 |EXTREMO DERECHO     |\n"
			"| 10|MEDIAPUNTA          |\n"
			"| 11|DELANTERO CENTRO    |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	utn_getInt(&opcion, "Ingrese posicion por numero: ", "ERROR. ", 1, 11, 100);
	return opcion;
}

int menuSwitchPosicion(int opcion,char* posicion)
{
	int todoOk=0;

	switch(opcion)
	{
		case 1:
			strcpy(posicion,"Portero");
			break;

		case 2:
			strcpy(posicion,"Defensa Central");
			break;

		case 3:
			strcpy(posicion,"Lateral Izquierdo");
			break;

		case 4:
			strcpy(posicion,"Lateral Derecho");
			break;

		case 5:
			strcpy(posicion,"Pivote");
			break;

		case 6:
			strcpy(posicion,"Mediocentro");
			break;

		case 7:
			strcpy(posicion,"Mediocentro ofensivo");
			break;

		case 8:
			strcpy(posicion,"Extremo Izquierdo");
			break;

		case 9:
			strcpy(posicion,"Extremo Derecho");
			break;

		case 10:
			strcpy(posicion,"Mediapunta");
			break;

		case 11:
			strcpy(posicion,"Delantero Centro");
			break;

			todoOk=1;
	}

	return todoOk;
}


int cargarIdNacionalidad(int idNacionalidad,char* descripcion)
{
	int todoOk=0;
//	int tam;

	if(descripcion!= NULL && idNacionalidad>0)
	{
		switch(idNacionalidad)
		{
		case 1:
			strcpy(descripcion,"Aleman");
			break;

		case 2:
			strcpy(descripcion,"Saudita");
			break;

		case 3:
			strcpy(descripcion,"Argentino")	;
			break;

		case 4:
			strcpy(descripcion,"Australiano")	;
			break;

		case 5:
			strcpy(descripcion,"Belga");
			break;

		case 6:
			strcpy(descripcion,"Brasilero");
			break;

		case 7:
			strcpy(descripcion,"Camerunes");
			break;

		case 8:
			strcpy(descripcion,"Canadiense");
			break;

		case 9:
			strcpy(descripcion,"Surcoreano");
			break;

		case 10:
			strcpy(descripcion,"Costarriquense");
			break;

		case 11:
			strcpy(descripcion,"Croata");
			break;

		case 12:
			strcpy(descripcion,"Danes");
			break;

		case 13:
			strcpy(descripcion,"Ecuatoriano");
			break;

		case 14:
			strcpy(descripcion,"Espanol");
			break;

		case 15:
			strcpy(descripcion,"Estadounidense");
			break;

		case 16:
			strcpy(descripcion,"Frances");
			break;

		case 17:
			strcpy(descripcion,"Gales");
			break;

		case 18:
			strcpy(descripcion,"Ghanes");
			break;

		case 19:
			strcpy(descripcion,"Holandes");
			break;

		case 20:
			strcpy(descripcion,"Ingles");
			break;

		case 21:
			strcpy(descripcion,"Irani") ;
			break;

		case 22:
			strcpy(descripcion,"Japones");
			break;

		case 23:
			strcpy(descripcion,"Marroqui") ;
			break;

		case 24:
			strcpy(descripcion,"Mexicano") ;
			break;

		case 25:
			strcpy(descripcion,"Polaco");
			break;

		case 26:
			strcpy(descripcion,"Portugues") ;
			break;

		case 27:
			strcpy(descripcion,"Qatari") ;
			break;

		case 28:
			strcpy(descripcion,"Senegales") ;
			break;

		case 29:
			strcpy(descripcion,"Serbio") ;
			break;

		case 30:
			strcpy(descripcion,"Suizo") ;
			break;

		case 31:
			strcpy(descripcion,"Tunecino");
			break;

		case 32:
			strcpy(descripcion,"Uruguayo");
			break;
		}
	}
	return todoOk;
}



int cargarIdSeleccion(int idSeleccion,char* descripcion)
{
	int todoOk=0;
//	int tam;

	if(descripcion!= NULL && idSeleccion>0)
	{
		switch(idSeleccion)
		{
		case 1:
			strcpy(descripcion,"Alemania");
			break;

		case 2:
			strcpy(descripcion,"Arabia Saudita");
			break;

		case 3:
			strcpy(descripcion,"Argentina")	;
			break;

		case 4:
			strcpy(descripcion,"Australia")	;
			break;

		case 5:
			strcpy(descripcion,"Belgica");
			break;

		case 6:
			strcpy(descripcion,"Brasil");
			break;

		case 7:
			strcpy(descripcion,"Camerun");
			break;

		case 8:
			strcpy(descripcion,"Canada");
			break;

		case 9:
			strcpy(descripcion,"Corea del Sur");
			break;

		case 10:
			strcpy(descripcion,"Costa Rica");
			break;

		case 11:
			strcpy(descripcion,"Croacia");
			break;

		case 12:
			strcpy(descripcion,"Dinamarca");
			break;

		case 13:
			strcpy(descripcion,"Ecuador");
			break;

		case 14:
			strcpy(descripcion,"Espana");
			break;

		case 15:
			strcpy(descripcion,"Estados Unidos");
			break;

		case 16:
			strcpy(descripcion,"Francia");
			break;

		case 17:
			strcpy(descripcion,"Gales");
			break;

		case 18:
			strcpy(descripcion,"Ghana");
			break;

		case 19:
			strcpy(descripcion,"Holanda");
			break;

		case 20:
			strcpy(descripcion,"Inglaterra");
			break;

		case 21:
			strcpy(descripcion,"Iran");
			break;

		case 22:
			strcpy(descripcion,"Japon");
			break;

		case 23:
			strcpy(descripcion,"Marruecos");
			break;

		case 24:
			strcpy(descripcion,"Mexico");
			break;

		case 25:
			strcpy(descripcion,"Polonia");
			break;

		case 26:
			strcpy(descripcion,"Portugal");
			break;

		case 27:
			strcpy(descripcion,"Qatar");
			break;

		case 28:
			strcpy(descripcion,"Senegal");
			break;

		case 29:
			strcpy(descripcion,"Serbia");
			break;

		case 30:
			strcpy(descripcion,"Suiza");
			break;

		case 31:
			strcpy(descripcion,"Tunez");
			break;

		case 32:
			strcpy(descripcion,"Uruguay");
			break;
		}
		todoOk=1;
	}
	return todoOk;
}



int menuSeleccion()
{
	int opcion;
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("| 1  |Alemania           |\n"
			"| 2  |Arabia Saudita     |\n"
			"| 3  |Argentina          |\n"
			"| 4  |Australia          |\n"
			"| 5  |Belgica            |\n"
			"| 6  |Brasil             |\n"
			"| 7  |Camerun            |\n"
			"| 8  |Canada             |\n"
			"| 9  |Corea del Sur      |\n"
			"| 10 |Costa Rica         |\n"
			"| 11 |Croacia            |\n"
			"| 12 |Dinamarca          |\n"
			"| 13 |Ecuador            |\n"
			"| 14 |Espana             |\n"
			"| 15 |Estados Unidos     |\n"
			"| 16 |Francia            |\n"
			"| 17 |Gales              |\n"
			"| 18 |Ghana              |\n"
			"| 19 |Holanda            |\n"
			"| 20 |Inglaterra         |\n"
			"| 21 |Iran               |\n"
			"| 22 |Japon              |\n"
			"| 23 |Marruecos          |\n"
			"| 24 |Mexico             |\n"
			"| 25 |Polonia            |\n"
			"| 26 |Portugal           |\n"
			"| 27 |Qatar              |\n"
			"| 28 |Senegal            |\n"
			"| 29 |Serbia             |\n"
			"| 30 |Suiza              |\n"
			"| 31 |Tunez              |\n"
			"| 32 |Uruguay            |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	utn_getInt(&opcion, "Ingrese seleccion del jugador por numero: ", "ERROR. ", 1, 32, 100);
	return opcion;
}


int menuNacionalidad()
{
	int opcion;
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("| 1  |Aleman                 |\n"
			"| 2  |Saudi                  |\n"
			"| 3  |Argentino              |\n"
			"| 4  |Australiano            |\n"
			"| 5  |Belga                  |\n"
			"| 6  |Brasilero              |\n"
			"| 7  |Camerunes              |\n"
			"| 8  |Canadiense             |\n"
			"| 9  |Surcoreano             |\n"
			"| 10 |Costarriquense         |\n"
			"| 11 |Croata                 |\n"
			"| 12 |Danes                  |\n"
			"| 13 |Ecuatoriano            |\n"
			"| 14 |Espanol                |\n"
			"| 15 |Estadounidense         |\n"
			"| 16 |Frances                |\n"
			"| 17 |Gales                  |\n"
			"| 18 |Ghanes                 |\n"
			"| 19 |Holandes               |\n"
			"| 20 |Ingles                 |\n"
			"| 21 |Irani                  |\n"
			"| 22 |Japones                |\n"
			"| 23 |Marroqui               |\n"
			"| 24 |Mexicano               |\n"
			"| 25 |Polaco                 |\n"
			"| 26 |Portugues              |\n"
			"| 27 |Qatari                 |\n"
			"| 28 |Senegales              |\n"
			"| 29 |Serbio                 |\n"
			"| 30 |Suizo                  |\n"
			"| 31 |Tunecino               |\n"
			"| 32 |Uruguayo               |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	utn_getInt(&opcion, "Ingrese el nacionalidad del jugador por numero: ", "ERROR. ", 1, 32, 100);
	return opcion;
}


int menuModificacion()
{
	int opcion;
	printf("|~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("| 1 |NOMBRE            |\n"
			"| 2 |EDAD              |\n"
			"| 3 |POSICION          |\n"
			"| 4 |NACIONALIDAD      |\n"
			"| 5 |SALIR             |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~|\n");


	utn_getInt(&opcion, "Ingrese que desea modificar: ", "ERROR. ", 1, 5, 100);

	return opcion;
}

int switchModificacion(int opcion, Jugador* jugador)
{
	int todoOk=0;
	char string[100];
	int auxInt;
	int opcionId;
	char auxString[50];

	if(opcion>0 && jugador!=NULL)
	{
		switch(opcion)
		{
		case 1:
			getString(string, "Ingrese nuevo nombre de jugador: ", "ERROR.",100);
			strcpy(jugador->nombreCompleto,string);
			break;

		case 2:
			utn_getInt(&auxInt, "Ingrese nueva edad: ", "ERROR.", 17, 50, 100);
			jugador->edad=auxInt;
			break;

		case 3:
			opcionId=menuPosicion();   //printeo menu de las posiciones y lo tomo con opcion
			menuSwitchPosicion(opcionId, auxString); // segun opcion elegida, se hace un strcpy en posicion. Donde ahora tengo escrito la posicion
			strcpy(jugador->posicion,auxString);
			break;

		case 4:
			opcionId=menuNacionalidad(); // printeo menu de las nacionalidades para elegir y se me guarda la opcion
			cargarIdNacionalidad(opcionId, auxString); // segun la nacionalidad elegida ahora la tengo guardada como string en nacionalidad
			strcpy(jugador->nacionalidad,auxString);
			break;

		case 5:
			printf("Saliendo...\n");
			break;
		}
	}
	return todoOk;
}


int menuPrincipal()
{
	int opcion;
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			"|        MENU PRINCIPAL        |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			"| 1  | Carga de archivos       |\n"
			"| 2  | Alta jugador            |\n"
			"| 3  | Modificacion jugador    |\n"
			"| 4  | Baja jugador            |\n"
			"| 5  | Listados                |\n"
			"| 6  | Convocar jugadores      |\n"
			"| 7  | Ordenar y listar        |\n"
			"| 8  | Generar archivo binario |\n"
			"| 9  | Cargar archivo binario  |\n"
			"| 10 | Guardar archivos .csv   |\n"
			"| 11 | Salir                   |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
//			"Ingrese Opcion: ");
//	scanf("%d",&opcion);
	utn_getInt(&opcion, "Ingrese Opcion: ", "ERROR.", 1, 11, 100);
	return opcion;
}

int menuOrdenamiento()
{
	int opcion;

	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			"|              MENU ORDENAMIENTO           |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			"| 1 |Ordenar jugadores por nacionalidad    |\n"
			"| 2 |Ordenar selecciones por confederacion |\n"
			"| 3 |Ordenar jugadores por edad            |\n"
			"| 4 |Ordenar jugadores por nombre          |\n"
			"| 5 |Salir                                 |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	utn_getInt(&opcion, "Ingrese opcion a ordenar: ", "ERROR. Opcion invalida!\n", 1, 5, 100);

	return opcion;
}

int menuListados()
{
	int opcion;
//	A) TODOS LOS JUGADORES.
//	B) TODAS LAS SELECCIONES.
//	C) JUGADORES CONVOCADOS (únicamente).
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			"|               MENU LISTADOS              |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			"| 1 |Listar todos los jugadores            |\n"
			"| 2 |Listar todas las selecciones          |\n"
			"| 3 |Listar jugadores convocados(unicamente|\n"
			"| 4 |Salir                                 |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	utn_getInt(&opcion, "Ingrese opcion de listado: ", "ERROR. Opcion invalida!\n", 1, 4, 100);
	return opcion;
}


int menuConvocar()
{
	int opcion;

	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
		 	"|  			MENU CONVOCAR				   |\n"
		 	"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			"| 1 | Convocar jugador a una seleccion        |\n"
			"| 2 | Quitar jugador de una seleccion         |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	utn_getInt(&opcion, "Ingrese opcion: ", "ERROR. ", 1, 2, 100);

	return opcion;
}

int menuConfederaciones()
{
	int opcion;
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			"|  MENU CONFEDERACIONES  |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			"| 1 |AFC                 |\n"
			"| 2 |CAF                 |\n"
			"| 3 |CONCACAF            |\n"
			"| 4 |CONMEBOL            |\n"
			"| 5 |UEFA                |\n"
			"| 6 |SALIR               |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	utn_getInt(&opcion, "Ingrese opcion: ", "ERROR. ", 1, 6, 100);
	return opcion;
}

int switchConfederaciones(int opcion, char* descripcion)
{
	int todoOk=0;

	switch(opcion)
	{
	case 1:
		strcpy(descripcion,"Afc");
		break;

	case 2:
		strcpy(descripcion,"Caf");
		break;

	case 3:
		strcpy(descripcion,"Concacaf");
		break;

	case 4:
		strcpy(descripcion,"Conmebol");
		break;

	case 5:
		strcpy(descripcion,"Uefa");
		break;

	case 6:
		printf("Volviendo...\n");
		break;
	}

	return todoOk;
}
