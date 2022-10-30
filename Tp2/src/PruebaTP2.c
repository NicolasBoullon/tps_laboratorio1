/*
 ============================================================================
 Name        : PruebaTP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugadores.h"
#include "confederacion.h"
#include "menu.h"
#include "informes.h"
#include "validaciones.h"
#define TAM_J 30 // TAM jugadores
#define TAM_CF 10//TAM Confederaciones



int main(void)
{

	setbuf(stdout,NULL);

	int banderaAlta=0;
	char seguir = 'n';
	int nextId=3000;
	int nextIdConfederaciones=100;
	eJugador jugadores[TAM_J];

	eConfederacion confederaciones[TAM_CF];
//	eConfederacion confederaciones[TAM_CF]={
//	        {1000, "CONMEBOL", "SUDAMERICA",1916},
//	        {1001, "UEFA", "EUROPA", 1954},
//	        {1002, "AFC", "ASIA", 1954},
//	        {1003, "CAF",  "AFRICA", 1957},
//	        {1004, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961},
//	        {1005, "OFC", "OCEANIA", 1966},
//	};


	if(!iniciarIsEmptyJugadores(jugadores, TAM_J))
	{
		printf("Error al iniciar\n");
	}

	if(!iniciarIsEmptyConfederacion(confederaciones, TAM_CF))
	{
		printf("Error al iniciar!\n");
	}

	hardcodearJugadores(&nextId, jugadores, TAM_J, 10);
	if(hardcodearConfederaciones(&nextIdConfederaciones, confederaciones, TAM_CF, 6))
	{
		banderaAlta=1;
	}

	//mostrarJugadores(jugadores, TAM_J);

	do{
		fflush(stdin);
		switch(menuPrincipal())
		{

		case 1:
			if(!altaJugador(jugadores, TAM_J, &nextId,confederaciones,TAM_CF))
			{
				printf("Hubo un error durante el alta!\n");
			}
			else
			{
				printf("Alta completada!\n");
			}
			banderaAlta=1;
			break;

		case 2:
			ordenarJugadoresId(jugadores, TAM_J);
			bajaJugador(jugadores, TAM_J, confederaciones, TAM_CF);
			break;

		case 3:
			ordenarJugadoresId(jugadores, TAM_J);
			modificarJugador(jugadores, TAM_J, confederaciones, TAM_CF);
			break;

		case 4:
			if(banderaAlta==1){
			switch(menuInformes())
			{

			case 1:
				if(!listadoJugadoresConfederacionAlfabeticamente(jugadores, TAM_J, confederaciones, TAM_CF))
					{
					printf("Hubo un error durante el listado!\n");
					}
				else
				{
					printf("Informe completado\n");
				}
				break;

			case 2:
				mostrarPersonasTodasConfederaciones(confederaciones, TAM_CF, jugadores, TAM_J);
				break;

			case 3:
				promedioTodosSalarios(jugadores, TAM_J);
				break;

			case 4:
				ConfederacionMayorAniosContrato(confederaciones, TAM_CF, jugadores, TAM_J);
				break;

			case 5:
				porcentajeJugadoresPorConfederacion(confederaciones, TAM_CF, jugadores, TAM_J);
				break;

			case 6:
				regionMasElegida(confederaciones, TAM_CF, jugadores, TAM_J);
				break;

			case 7:
				printf("Volviendo...\n");
				break;
			}
			}
			else
			{
				printf("Debe dar de alta un jugador para poder ingresar a informes!\n");
			}
			break;

		case 5:
			printf("Saliendo...\n");
			seguir=confirmaSalir();
			break;

		}

	}while (seguir== 'n');

	return EXIT_SUCCESS;
}


