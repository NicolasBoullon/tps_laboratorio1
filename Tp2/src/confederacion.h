/*
 * confederacion.h
 *
 *  Created on: 26 oct 2022
 *      Author: usuario
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct{
	int id;//PK
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;

}eConfederacion;



#endif /* CONFEDERACION_H_ */
/// @brief muestra en pantalla una confederacion con sus campos, se utiliza en conexion con otras funciones
///
/// @param confederacion recibe la confederacion a mostrar sus campos
void mostrarConfederacion(eConfederacion confederacion);

/// @brief esta funcion muestra todas las confederacion con sus campos, llama dentro de ella a la funcion mostrarConfederacion
///
/// @param confederaciones array de confederaciones
/// @param tamC tamanio del array de confederaciones
/// @return devuelve 1 en caso de mostrar confederaciones, devuelve 0 si no hay ninguna cargada y lo informa
int mostrarConfederaciones(eConfederacion confederaciones[],int tamC);
//--------------------------------------------------------------------------------------------------------
/// @brief esta funcion sirve solo para hardcodear las confederaciones principales
///
/// @param pId recibe el id autoincremental  para que no se repita de cada confederacion
/// @param vec array de confederaciones
/// @param tam tamanio del array de confederaciones
/// @param cant cantidad que quiero hardcodear confederaciones
/// @return devuelve 1 si se pudo hardcodear con exito, si no returnea 0
int hardcodearConfederaciones(int* pId,eConfederacion vec[], int tam, int cant);
//--------------------------------------------------------------------------------------------------------
/// @brief esta funcion me carga en un string, la descripcion de la confederacion pedida por id
///
/// @param confederaciones array de confederaciones
/// @param tamC tamanio del array de confederaciones
/// @param id este es el id que compara con el id de cada confederacion, si encuentra igualdad, carga el nombre de la confederacion en mi string pasado por parametro
/// @param descricpion mi puntero al string para poder copiar el nombre de la confederacion , en el caso de encontrar igualdad
/// @return devuelve 1 si no hubo ningun problema, sino, retorna 0
int cargarConfederacion(eConfederacion confederaciones[],int tamC, int id,char descricpion[]);
//--------------------------------------------------------------------------------------------------------
/// @brief esta funcion da de alta una confederacion en el caso de querer dar de alta
///
/// @param confederaciones array de confederaciones
/// @param tamC tamanio del array de confederaciones
/// @param pId  recibe el id para que se vaya aumentando de forma autoincremental y que no se repita
/// @return devuelve 1 si se pudo hacer  el alta, 0 si hubo algun problema
int altaConfederacion(eConfederacion confederaciones[],int tamC, int* pId);

/// @brief esta funcion da de baja logica una confederacion
///
/// @param confederaciones array de confederaciones
/// @param tamC tamanio de array de confederaciones
/// @return devuelve 1 si salio todo bien , 0 si hubo un problema
int bajaConfederacion(eConfederacion confederaciones[],int tamC);

/// @brief esta funcion me deja modificar cualquier campo de la confederacion ingresada por id, todo validado
///
/// @param confederaciones array de confederaciones
/// @param tamC tamanio del array de confederaciones
/// @return devuelve 1 si salio todo ok, 0 si no
int modificarConfederacion(eConfederacion confederaciones[],int tamC);

/// @brief  esta funcion inicializa  mi array de confederaciones en el campo isEmpty en 1 para indicar que estan todos los isEmptys libre
///
/// @param confederaciones array de confederaciones
/// @param tamC tamanio del array de confederaciones
/// @return devuelve 1 si se pudo hacer, 0 si hubo algun problema
int iniciarIsEmptyConfederacion(eConfederacion confederaciones[],int tamC);

/// @brief esta funcion busca el primer lugar libre y la funcion retorna el indice donde lo encuentra
///
/// @param confederaciones array de confederaciones
/// @param tamC tamnio del array de confederaciones
/// @return deuelve el indice donde encontro el primer lugar libre, devuelve -1 si no hay ningun lugar libre
int buscarLugarLibreConfederacion(eConfederacion confederaciones[],int tamC);

/// @brief esta funcion busca la igualdad entre el id de la confederacion y el id recibido
///
/// @param confederaciones array de confederaciones
/// @param tamC tamanio del array de confederaciones
/// @param id este es el id que recibe para buscar la igualdad con los id de confederacion
/// @return devuelve el indice de donde esta la igualdad , si no encontro ningun id de confederacion con el id recibido, devuelve -1
int buscarConfederacionId(eConfederacion confederaciones[],int tamC, int id);
