/*
 * menu.h
 *
 *  Created on: 26 oct 2022
 *      Author: usuario
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>



#endif /* MENU_H_ */


/// @brief esta funcion me muestra el menu principal con sus funciones y valida que no sea otra opcion de las requeridas
///
/// @return devuelve la opcion ingresada
int menuPrincipal();

/// @brief esta funcion me muestra el menu de las posiciones del jugador, validandolo para que no sea alguna incorrecta
///
/// @return devuelve la posicion elegida
int menuPosicion();

/// @brief este el menu de modificar, valida que la opcion sea una dentro de lo requerido y que no sea algo incorrecto
///
/// @return devuelve la opcion de la modificacion
int menuModificar();

/// @brief esta funcion es el menu de informes , valida que no sea una opcion fuera de lo requerido
///
/// @return me devuelve la opcion del informe a mostrar
int menuInformes();

/// @brief  este es el menu de modificar pero para las confederaciones, tambien validando que no sea una opcion fuera de lo requerido
///
/// @return devuelve la opcion para modificar la confederacion
int menuModificarConfederacion();

