/*
 * menu.c
 *
 *  Created on: 26 oct 2022
 *      Author: usuario
 */

#include "menu.h"
#include "validaciones.h"

int menuPrincipal()
{
	int opcion;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|      MENU OPCIONES    |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("| 1 | ALTA JUGADOR      |\n"
			"| 2 | BAJA JUGADOR      |\n"
			"| 3 | MODIFICAR JUGADOR |\n"
			"| 4 | INFORMES          |\n"
			"| 5 | SALIR             |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");

	utn_getInt(&opcion, "Ingrese opcion: ", "Opcion Invalida.\n", 1, 5, 100);

	return opcion;
}


int menuPosicion()
{
	int opcion;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|      POSICIONES       |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("| 1 | ARQUERO           |\n"
			"| 2 | DEFENSOR          |\n"
			"| 3 | MEDIOCAMPISTA     |\n"
			"| 4 | DELANTERO         |\n"
			"~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	utn_getInt(&opcion, "Ingrese opcion: ", "Opcion Invalida.\n", 1, 4, 100);

	return opcion;
}

int menuModificar()
{
	int opcion;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|       MODIFICAR       |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("| 1 | NOMBRE            |\n"
			"| 2 | POSICION          |\n"
			"| 3 |CAMISETA           |\n"
			"| 4 |CONFEDERACION      |\n"
			"| 5 |SALARIO            |\n"
			"| 6 |ANOS CONTRATO      |\n"
			"| 7 |SALIR              |\n");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~\n");

	utn_getInt(&opcion, "Ingrese opcion: ", "Opcion Invalida.\n", 1, 7, 100);
	return opcion;
}


int menuInformes()
{
	int opcion;
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|     MENU  INFORMES    |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("| 1 | Listado de jugadores ordenados alfabeticamente por nombre de confederacion y nombre de jugador |\n"
			"| 2 | Listado de confederaciones con sus jugadores                                                   |\n"
			"| 3 | Total y promedio de todos los salarios y cuantos jugadores cobran mas del salario promedio     |\n"
			"| 4 | Confederacion con mayor cantidad de anios de contratos total                                   |\n"
			"| 5 | Porcentaje de jugadores por cada confederacion                                                 |\n"
			"| 6 | Region con mas jugadores y el listado de los mismos                                            |\n"
			"| 7 | Salir                                                                                          |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	utn_getInt(&opcion, "Ingrese opcion: ", "Opcion Invalida.\n", 1, 7, 100);
	return opcion;
}


int menuModificarConfederacion()
{
	int opcion;
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|     MODIFICAR CONFEDERACION     |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("| 1 |  NOMBRE                     |\n"
			"| 2 | REGION                      |\n"
			"| 3 | ANIO CREACION               |\n"
			"| 4 | VOLVER                      |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	utn_getInt(&opcion, "Ingrese opcion: ", "Opcion Invalida.\n", 1, 4, 100);

	return opcion;
}
