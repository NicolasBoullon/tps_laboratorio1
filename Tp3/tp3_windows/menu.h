/*
 * menu.h
 *
 *  Created on: 21 nov 2022
 *      Author: usuario
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "inputs.h"
#endif /* MENU_H_ */


int menuSeleccion();
int cargarIdSeleccion(int idSeleccion,char* descripcion);
int menuSwitchPosicion(int opcion,char* posicion);
int menuPosicion();
int cargarMayorId(char* id);
int menuNacionalidad();
int cargarIdNacionalidad(int idNacionalidad,char* descripcion);
int cargarIdSeleccion(int idSeleccion,char* descripcion);
int menuModificacion();
int switchModificacion(int opcion, Jugador* jugador);
int menuPrincipal();
int menuOrdenamiento();
int menuListados();
int menuConvocar();
int menuConfederaciones();
int switchConfederaciones(int opcion, char* descripcion);
