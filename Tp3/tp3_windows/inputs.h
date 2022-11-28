/*
 * inputs.h
 *
 *  Created on: 19 nov 2022
 *      Author: usuario
 */

#ifndef INPUTS_H_
#define INPUTS_H_



#endif /* INPUTS_H_ */


/// @brief toma string y evalua con la funcion soloCaracter, que sea valido
///
/// @param string
/// @param mensaje
/// @param mensajeError
/// @return
int getString(char string[],char mensaje[],char mensajeError[],int max);
/// @brief valida si es caracter
///
/// @param string
/// @return devuelve 0 si el string esta compuesto solo por caracteres , sino 1
int soloCaracter(char string[]);


/// @brief esta es una combinacion con otras 2 funciones que sirven para pedir un dato y validar que el dato ingresado sea un entero, y ninguna otra cosa. LLama a get int
///
/// @param pResultado este es el puntero donde se guardara la variable en caso de ser ingresado correctamente
/// @param mensaje este es el mensaje que se mostrara para pedir el numero
/// @param mensajeError mensaje de error que imprime en pantalla cuando el numero ingresado no cumple con los parametros
/// @param minimo minimo a ingresar entre el numero pedido
/// @param maximo maximo a ingresar del numero a pedir
/// @param reintentos la cantidad de reintetos que se quiera pedir
/// @return devuelve -1 en el caso de haber un problema, sino, retorna 1
int utn_getInt( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @brief esta funcion me sirve para verificar que sea entero, ya que llama a es numerica y myGets
///
/// @param pResultado puntero donde se guardara la variable
/// @return devuelve -1 si hubo un fallo, 1 si salio todo ok
int getInt ( int * pResultado);

/// @brief esta funcion valida segun el codigo asscii que sea solamente numeros
///
/// @param cadena recibe la cadena ingresada, y verifica caracter por caracter que sea numero
/// @return devuelve -1 en caso de fallar algo, o 1 si es un numero correcto
int esNumericaInt ( char * cadena);
/// @brief esta funcion valida que no haya ningun espacio en la cadena y nigun caracter terminador
///
/// @param cadena cadena a analizar
/// @param longitud longitud del buffer
/// @return devuelve -1 si fallo, 0 si no hubo problema
int myGets ( char * cadena, int longitud);

/// @brief esta es una combinacion con otras 2 funciones que sirven para pedir un dato y validar que el dato ingresado sea un float, y ninguna otra cosa. LLama a get float
///
/// @param pResultado  este es el puntero donde se guardara la variable en caso de ser ingresado correctamente
/// @param mensaje este es el mensaje que se mostrara para pedir el numero
/// @param mensajeError mensaje de error que imprime en pantalla cuando el numero ingresado no cumple con los parametros
/// @param minimo minimo a ingresar entre el numero pedido
/// @param maximo maximo a ingresar del numero a pedir
/// @param reintentos la cantidad de reintetos que se quiera pedir
/// @return devuelve -1 en el caso de haber un problema, sino, retorna 1
int utn_getFloat( float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @brief esta funcion sirve para verificar que sea un float, utiliza a la funcion es numerica float y mygets
///
/// @param pResultado puntero donde se guardara la variable
/// @return devuelve -1 si hubo un fallo, o 1 si no hubbo ningun problema
float getFloat ( float * pResultado);

/// @brief  esta funcion valida segun el codigo ascii que sea solo numeros, y no mas que un solo ., ya que al ser flotante puede haber un .
///
/// @param cadena cadena a verificar caracter por caracter que no haya ningun problema
/// @return deuvelve -1 en caso de fallar, o 1 si el numero es correcto
float esNumericaFloat ( char * cadena);

/// @brief funcion que confirma la salida con s o n
///
/// @return devuelve s o n en tolower
char confirmaSalir();

char confirmaSiNo(char* mensaje,char* mensajeError);
