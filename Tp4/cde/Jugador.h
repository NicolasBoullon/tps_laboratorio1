#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

int mostrarJugador(Jugador* jugador);

int BuscarJugadorId(int id, LinkedList* this);

//---------------------------ORDENAMIENTOS
//A) JUGADORES POR NACIONALIDAD.
//B) SELECCIONES POR CONFEDERACIÓN.
//C) JUGADORES POR EDAD.
//D) JUGADORES POR NOMBRE.

int ordenarJugadoresPorNacionalidad(void* pPrimerJugador, void* pSegundoJugador);
int ordenarJugadoresPorNombre(void* pPrimerJugador, void* pSegundoJugador);
int ordenarJugadoresPorEdad(void* pPrimerJugador, void* pSegundoJugador);

//int jug_setIsEmpty(Jugador* this,int isEmpty);
//int jug_getIsEmpty(Jugador* this,int* isEmpty);



#endif // jug_H_INCLUDED
