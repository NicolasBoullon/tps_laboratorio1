/*
 * informes.h
 *
 *  Created on: 28 oct 2022
 *      Author: usuario
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jugadores.h"
#endif /* INFORMES_H_ */

/// @brief esta funcion lista los jugadores ordenados alfabeticamente por confederacion, en el caso de igualdad los ordena alfabeticamente por nombre
///
/// @param jugadores array de jugadores
/// @param tamJ tamanio del array de jugadores
/// @param confederaciones array de confederaciones
/// @param tamC tamanio del array de confederaciones
/// @return devuelve 1 en caso de no haber ningun problema, devuelve 0 si hubo algun fallo
int listadoJugadoresConfederacionAlfabeticamente(eJugador jugadores[],int tamJ,eConfederacion confederaciones[],int tamC);

/// @brief esta funcion muestra cada confederacion con sus jugadores, con el uso de la funcion mostrarJugadoresIdConfederacion
///
/// @param confederaciones array de confederaciones
/// @param tamC tamanio del array de confederaciones
/// @param jugadores array de jugadores
/// @param tamJ tamanio del array de jugadores
/// @return devuelve 1 en caso de no haber ningun problema, devuelve 0 si hubo algun fallo
int mostrarPersonasTodasConfederaciones(eConfederacion confederaciones[],int tamC,eJugador jugadores[],int tamJ);

/// @brief  esta funcion muestra los jugadores de una confederacion, se usa dentro de la funcion mostrarPersonasTodasConfederaciones
///
/// @param opcion este es el id a buscar e igualar con jugadores.idConfederacion
/// @param confederaciones array de confederaciones
/// @param tamC tamanio del array de confederaciones
/// @param jugadores array de jugadores
/// @param tamJ tamanio del array de jugadores
/// @return devuelve 1 en caso de no haber ningun fallo, 0 en caso de fallar
int mostrarJugadoresIdConfederacion(int opcion,eConfederacion confederaciones[],int tamC,eJugador jugadores[],int tamJ);

/// @brief esta funcion muestra el promedio de los salarios e indica cuales son los jugadores que estan por encima de ese promedio
///
/// @param jugadores array de jugadores
/// @param tamJ tamanio del array de jugadores
/// @return devuelve 1 en el caso de funcionar con exito, 0 si fallo
int promedioTodosSalarios(eJugador jugadores[],int tamJ);


/// @brief esta funcion meustra las confederaciones con mayor anios de contrato
///
/// @param confederaciones array de confederaciones
/// @param tamC tamanio del array de confederaciones
/// @param jugadores array de jugadores
/// @param tamJ tamanio del array de jugadores
/// @return devuelve 1 en el caso de funcionar con exito, 0 si fallo
int ConfederacionMayorAniosContrato(eConfederacion confederaciones[],int tamC,eJugador jugadores[],int tamJ);

/// @brief funcion que muestra el porcentaje de jugadores por cada confederacion
///
/// @param confederaciones array de confederaciones
/// @param tamC tamanio del array de confederaciones
/// @param jugadores array de confederaciones
/// @param tamJ tamanio del array de confederaciones
/// @return devuelve 1 en el caso de funcionar con exito, 0 si fallo
int porcentajeJugadoresPorConfederacion(eConfederacion confederaciones[],int tamC,eJugador jugadores[],int tamJ);

/// brief muestra la region con mas jugadores e indica los nombres de estos
///
/// @param confederaciones array de confederaciones
/// @param tamC tamanio de array de confederaciones
/// @param jugadores array de jugadores
/// @param tamJ tamanio del array de jugadores
/// @return devuelve 1 en caso de que no haya problema, 0 si hubo algun fallo
int regionMasElegida(eConfederacion confederaciones[],int tamC,eJugador jugadores[],int tamJ);
