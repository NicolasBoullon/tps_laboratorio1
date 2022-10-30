/*
 * funciones.h
 *
 *  Created on: 22 sept 2022
 *      Author: usuario
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @brief  Esta funcion imprime el menu completo y muestra los resultados de las operaciones mientras va avanzando el programa a tiempo real
///
/// @param cHospedaje el costo de hospedaje ingresado
/// @param cComida el costo de comida ingresado
/// @param cTransporte el costo de transporte ingresado
/// @param arqueros la cantidad de arqueros ingresados hasta el momento
/// @param defensores la cantidad de defensores ingresados hasta el momento
/// @param mediocampistas la cantidad de mediocampistas ingresados hasta el momento
/// @param delanteros la cantidad de delanteros ingresados hasta el momento
/// @return devuelve un numero validado entre 1 y 5, para cada opcion del menu
int MenuPrincipal(float cHospedaje,float cComida,float  cTransporte,int arqueros,int defensores,int mediocampistas,int delanteros);

/// @brief Esta funcion imprime el menu de mantenimiento y los valores de los costos ingresados
///
/// @param cHospedaje este es el costo de hospedaje que es mostrado
/// @param cComida costo de comida que es mostrado
/// @param cTransporte costo de transporte que es mostrado
/// @return  devuelve un caracter, segun lo que quiera ingresar, entre 'a' y 'd'
char SubMenuMantenimiento(float cHospedaje,float cComida,float cTransporte);

/// @brief  imprime el menu de confederaciones, tambien pide caracter y valida entre las opciones
///
/// @return devuelve caracter elegido para la confederacion, entre 'a' y 'f'
char SubMenuConfederacion();

/// @brief imprime menu de los jugadores a tiempo real a medida que se cargan los datos, tambien pide caracter para elegir entre las posiciones y lo valida
///
/// @param arqueros contador de arqueros que se muestra en el menu
/// @param defensores contador de defensores que se muestra en el menu
/// @param mediocampistas contador de mediocampistas que se muestra en el menu
/// @param delanteros contador de delanteros que se muestra en el menu
/// @return me devuelve un caracter entre 'a' y 'e'
char SubMenuCargaJugadores(int arqueros,int defensores,int mediocampistas,int delanteros);

/// @brief imprime los promedios ya calculados, que son dados por parametro, tambien imprime la suma de los costos de mantenimiento y tambien aumento si fue necesario
///
/// @param promedioAsia valor del promedio para mostrar
/// @param promedioAfrica valor del promedio para mostrar
/// @param promedioNorte valor del promedio para mostrar
/// @param promedioSudamerica valor del promedio para mostrar
/// @param promedioOceania valor del promedio para mostrar
/// @param promedioEuropa valor del promedio para mostrar
/// @param sMantenimiento
/// @param okAumento 1 o 0 en caso de necesitar aumento, 1 si necesita aumento, 0 si no, lo valida dentro de la funcion.
/// @param aumento precio del aumento ya calculado, se muestra en caso de necesitar aumento
/// @param precioFinal este el precio final ya calculado, se muestra en caso de aumento
void mostrarResultadosFinales(float promedioAsia,float promedioAfrica, float promedioNorte, float promedioSudamerica, float promedioOceania,float promedioEuropa,float sMantenimiento,int okAumento,float aumento,float precioFinal);

/// @brief  pide numero entero, con return void, por parametro se le pasa mensaje para pedir numero, mensaje error dependiendo de maximo y minimo, tambien por parametro
///
/// @param mensaje se muestra antes de el scanf, mensaje para pedir num
/// @param mensajeError mensaje error en caso de no cumplir con los parametros de maximo y minimo
/// @param num1 en este puntero donde se almacena el nuevo valor de direccion de memoria
/// @param maximo parametro maximo para numero ingresado
/// @param minimo parametro minimo para numero ingresado
void PedirNumero_Int(char mensaje[],char mensajeError[], int* num1, int maximo, int minimo);

/// @brief  pide numero float, con return void, por parametro se le pasa mensaje para pedir numero, mensaje error dependiendo de maximo y minimo, tambien por parametro
///
/// @param mensaje se muestra antes de el scanf, mensaje para pedir num
/// @param mensajeError mensaje error en caso de no cumplir con los parametros de maximo y minimo
/// @param num1 en este puntero donde se almacena el nuevo valor de direccion de memoria, sin restriccion para decimales
/// @param maximo parametro maximo para numero ingresado
/// @param minimo parametro minimo para numero ingresado
void PedirNumero_Float(char mensaje[],char mensajeError[], float* num1, float maximo, float minimo);

/// @brief la funcion es un contador de cada confederacion, le paso por parametros, el valor y direccion de memoria de la misma variable, hago lo mismo con variable que uso como contador de jugadores
///
/// @param pContadorAsia puntero contador asia
/// @param contadorAsia contador asia
/// @param pContadorAfrica puntero contador africa
/// @param contadorAfrica contador africa
/// @param pContadorNorte puntero contador norte
/// @param contadorNorte contador norte
/// @param pContadorSudamerica puntero contador sudamerica
/// @param contadorSudamerica contador sudamerica
/// @param pContadorOceania puntero contador oceania
/// @param contadorOceania contador oceania
/// @param pContadorEuropa puntero contador europa
/// @param contadorEuropa contador europa
/// @param opcion la opcion segun la confederacion es dada por parametro para usarla dentro de un switch
/// @param pContJugadores puntero de jugadores
/// @param contJugadores contador de jugadores
void contadorConfederacion(int* pContadorAsia,int contadorAsia,int* pContadorAfrica,int contadorAfrica,int* pContadorNorte,int contadorNorte,int* pContadorSudamerica,int contadorSudamerica,int* pContadorOceania,int contadorOceania,int* pContadorEuropa,int contadorEuropa,char opcion,int* pContJugadores,int contJugadores);

/// @brief esta funcion suma los costos de comida, transporte y hospedaje y devuelve el resultado por puntero
///
/// @param costoHospedaje float de costo de hospedaje
/// @param costoComida float de costo de comida
/// @param costoTransporte float costo de transporte
/// @param resultado puntero donde devuelve resultado de suma
/// @return me devuelve un 1 si se logro hacer la suma
int sumarCostosMantenimiento(float costoHospedaje,float costoComida,float costoTransporte,float* resultado);

/// @brief esta funcion sirve para validar un numero, si es muestra mensaje de exito y sino, mensaje error
///
/// @param numIng numero por parametro para validar si es 1, mensaje exitoso
/// @param mensaje mensaje a mostrar si num ing es 1
/// @param mensajeError mensaje error si num ing no es 1
void validarOk_Int(int numIng,char mensaje[],char mensajeError[]);

/// @brief la funcion valida si el contador de la confederacion de europa es mayor a las demas confederaciones, si es el caso, se le aplica el aumento del 35%
///
/// @param cAsia contador de confederacion  de asia
/// @param cAfrica contador de confederacion de africa
/// @param cNorte contador de conferacion del norte
/// @param cSud contador de conferacion de sudamerica
/// @param cOceania contador de conferacion de oceania
/// @param cEuropa contador de conferacion de europa
/// @param costoMantenimiento este es el costo total de mantenimiento, ya sumados los 3 costos
/// @param aumento puntero del aumento realizando en la funcion, este es el 35%
/// @param resultadoFinal puntero de resultado final, el costo mantenimiento mas el aumento
/// @return devuelve un 1 si se pudo hacer de manera efectiva
int aumentoEuropa(int cAsia,int cAfrica,int cNorte,int cSud,int cOceania,int cEuropa,float costoMantenimiento,float* aumento,float* resultadoFinal);

/// @brief esta funcion es la que valida si el punto 1 y 2 estan hechos mediante banderas y si se ingreso al menos un jugador
///
/// @param banderaHospedaje es la bandera que se pone en 1 al momento de ingresar un costo de hospedaje
/// @param banderaComida es la bandera que se pone en 1 al momento de ingresar un costo de comida
/// @param banderaTransporte es la bandera que se pone en 1 al momento de ingresar un costo de transporte
/// @param contadorJugadores es el contador que me valida si se ingreso un jugador como minimo
/// @return devuelve un 1 si ya se cumplieron las condiciones, las 3 banderas y al menos un jugador ingresado
int validarUnoDos(int banderaHospedaje,int banderaComida,int banderaTransporte,int contadorJugadores);

/// @brief la funcion me calcula el promedio de jugador por cada confederacion, recibe por parametro, los punteros de promedio de cada confederacion, y el contador de jugadores de cada confederacion, el promedio se guarda en los punteros de promedio
///
/// @param pPromAsia puntero donde se va a guardar el promedio de asia
/// @param contadorAsia el contador que contiene la cantidad de jugadores ingresados hasta el momento en la confederacion
/// @param pPromAfrica puntero donde se va a guardar el promedio de africa
/// @param contadorAfrica el contador que contiene la cantidad de jugadores ingresados hasta el momento en la confederacion
/// @param pPromNorte puntero donde se va a guardar el promedio de norte
/// @param contadorNorte el contador que contiene la cantidad de jugadores ingresados hasta el momento en la confederacion
/// @param pPromSud puntero donde se va a guardar el promedio de asia sudamerica
/// @param contadorSudamerica el contador que contiene la cantidad de jugadores ingresados hasta el momento en la confederacion
/// @param pPromOceania puntero donde se va a guardar el promedio de oceania
/// @param contadorOceania el contador que contiene la cantidad de jugadores ingresados hasta el momento en la confederacion
/// @param pPromEuropa puntero donde se va a guardar el promedio de europa
/// @param contadorEuropa el contador que contiene la cantidad de jugadores ingresados hasta el momento en la confederacion
/// @param contadorJugadores este es el contador de jugadores totales ingresados hasta el momento
/// @return devuelve 1 si se pudo hacer todos los promedios
int calcularPromedioMercados(float* pPromAsia,int contadorAsia,float* pPromAfrica,int contadorAfrica,float* pPromNorte,int contadorNorte,float* pPromSud,int contadorSudamerica,float* pPromOceania,int contadorOceania,float* pPromEuropa,int contadorEuropa,int contadorJugadores);
#endif /* FUNCIONES_H_ */
