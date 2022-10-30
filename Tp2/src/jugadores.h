/*
 * jugadores.h
 *
 *  Created on: 26 oct 2022
 *      Author: usuario
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "menu.h"
#include "confederacion.h"
//#include "validaciones.h"

typedef struct{
	int id;//PK
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	float salario;
	int idConfederacion;//ForeingKey
	short anioContrato;
	short isEmpty;
}eJugador;

#endif /* JUGADORES_H_ */

/// @brief Funcion que da de alta jugador, con id autoincremental, que pide y valida datos del jugador
///
/// @param jugadores array jugadores
/// @param tamJ tam array jugadores
/// @param pId id autoincremental
/// @param confederaciones array de confederaciones
/// @param tamC tamanio de array de confederaciones
/// @return me devuelve 1 si se pudo hacer , 0 si no
int altaJugador(eJugador jugadores[],int tamJ,int* pId,eConfederacion confederaciones[],int tamC);

/// @brief Funcion que da de baja de un jugador de forma logica, es decir colocar el campo isEmpty en 1
///
/// @param jugadores array de jugadores
/// @param tamJ tamanio de array de jugadores
/// @param confederaciones array de confederaciones
/// @param tamC tamanio array de confederaciones
/// @return devuelve 1 si se pudo hacer correctamente, 0 si no
int bajaJugador(eJugador jugadores[],int tamJ,eConfederacion confederaciones[],int tamC);

/// @brief Esta funcion me permite modificar cada campo de mi array de jugadores validando todo
///
/// @param jugadores array de jugadores
/// @param tamJ tamanio de array de jugadores
/// @param confederaciones array de confederaciones
/// @param tamC tamnio array de confederaciones
/// @return me devuelve 1 si se pudo hacer la modificacion con exito, 0 si no
int modificarJugador(eJugador jugadores[],int tamJ,eConfederacion confederaciones[],int tamC);
//--------------------------------------------------------------------------------------------------------

/// @brief Esta funcion recibe un solo jugador y me muestra en pantalla los datos del jugador, se usa dentro de otras funciones
///
/// @param jugador jugador recibido
/// @param confederaciones array de confederaciones
/// @param tamC tamanio de array de confederaciones
void mostrarJugador(eJugador jugador,eConfederacion confederaciones[],int tamC);

/// @brief esta funcion me muestra todos los jugadores totales con sus confederaciones y campos, usa dentro la funcion mostrarJugador a la cual le va pasando cada jugador mediante un for
///
/// @param jugadores array de jugadores
/// @param tamJ tamanio de array de jugadores
/// @param confederaciones  array de confederaciones
/// @param tamC tamanio de array de confederaciones
/// @return me devuelve 1 si salio todo con exito, 0 si no se pudo mostrar ningun jugador, y me lo informa
int mostrarJugadores(eJugador jugadores[],int tamJ,eConfederacion confederaciones[],int tamC);
//--------------------------------------------------------------------------------------------------------
/// @brief esta funcion sirve para buscar un jugador con el id recibido, para saber si existe el  jugador ingresado por id
///
/// @param jugadores array de jugadores
/// @param tam tamanio de array de jugadores
/// @param id recibe el id para igualarlo con el array de jugadores en campo id
/// @return devuelve el indice del jugador en el caso de encontrarlo sino devuelve -1
int buscarJugadorId(eJugador jugadores[],int tam, int id);

/// @brief esta funcion inicializa a todos los jugadores en el campo isempty en 1, para indicar que estan vacios
///
/// @param jugadores array de jugadores
/// @param tamJ tamanio de aarray de jugadores
/// @return devuelve 1 si se pudo hacer, 0 si fallo algo en la inicalizacion
int iniciarIsEmptyJugadores(eJugador jugadores[],int tamJ);

/// @brief esta funcion busca un lugar libre dentro del array  de jugadores y devuevlve el indice si es que lo encuentra
///
/// @param jugadores array de jugadores
/// @param tamJ tamanio de array de jugadores
/// @return devuelve el indice donde se encuentra el primer lugar libre, en el caso de no haber un lugar libre devuevle -1
int buscarLugarLibreJugador(eJugador jugadores[],int tamJ);

/// @brief esta funcion solo sirve para hardcodear jugadores y poder probar que funcione correctamente el programa
///
/// @param pId recibe el id ya que al hardodear jugadores tambien tiene que incrementar el id de los jugadores
/// @param vec array de jugadores
/// @param tam tamanio de array de jugadores
/// @param cant cantidad que yo quiera hardcodear, la funcion tiene 10 jugadores para hardcodear como maximo
/// @return devuelve 1 si se pudo hardcodear con exito, sino deuvelve 0
int hardcodearJugadores(int* pId,eJugador vec[], int tam, int cant);
//--------------------------------------------------------------------------------------------------------
/// @brief esta funcion ordena jugadores por ID, que se ordena asi en bajajugador y modficar jugador
///
/// @param jugadores	 array de jugadores
/// @param tamJ tamanio de array de jugadores
/// @return devuelve 1 si salio todo bien, 0 si hubo un problema
int ordenarJugadoresId(eJugador jugadores[],int tamJ);
