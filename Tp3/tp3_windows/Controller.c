#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "menu.h"
#include "inputs.h"
#include "parser.h"
#include "Controller.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int todoOk=0;
	FILE* f = fopen(path,"r");
	if(f!=NULL && pArrayListJugador!=NULL)
	{
		parser_JugadorFromText(f, pArrayListJugador);
		todoOk=1;
	}
	fclose(f);
    return todoOk;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int todoOk=0;
	FILE* f = fopen(path,"rb");//genera nueva lista en binario
	if(path!=NULL && pArrayListJugador!=NULL && f!=NULL)
	{
		parser_JugadorFromBinary(f, pArrayListJugador);
		todoOk=1;
	}
	fclose(f);
    return todoOk;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	system("cls");
	int todoOk=0;
	char id[50];
	char nombreCompleto[100];
	char edad[50];
	char posicion[30];
	char nacionalidad[30]; // gentilicio de nacionalidad
	int idElegido=0;
	int idSeleccion=0;//
	char seleccion[50];
//	int convocar=0;
	int auxEdad;
	int opcion;
//	char respuestaConvocado;

	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|     ALTA JUGADOR    |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
	Jugador* JugAux=NULL;
	if(pArrayListJugador!=NULL)
	{
		cargarMayorId(id);
		getString(nombreCompleto, "Ingrese nombre de jugador: ", "ERROR.", 100);
//		getString(edad, "Ingrese edad del jugador: ", "ERROR.", 50);
		utn_getInt(&auxEdad, "Ingrese edad del jugador: ", "ERROR.", 17, 60, 100);
		itoa(auxEdad,edad,10); // me pasa la edad a string
		opcion=menuPosicion(JugAux);   //printeo menu de las posiciones y lo tomo con opcion
		menuSwitchPosicion(opcion, posicion); // segun opcion elegida, se hace un strcpy en posicion. Donde ahora tengo escrito la posicion
		idElegido=menuNacionalidad(); // printeo menu de las nacionalidades para elegir y se me guarda la opcion
		cargarIdNacionalidad(idElegido, nacionalidad); // segun la nacionalidad elegida ahora la tengo guardada como string en nacionalidad
		fflush(stdin);
//		respuestaConvocado=confirmaSiNo("El jugador esta convocado a una seleccion? ", "Ingrese opcion correcta :"); // para podes convocarlo al momento del ingreso
//		if(respuestaConvocado=='s')
//		{
//			fflush(stdin);
//			idElegido=menuSeleccion();
			itoa(idSeleccion,seleccion,10);
//		}
//		itoa(idSeleccion,seleccion,10);
		JugAux=jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, seleccion);
		ll_add(pArrayListJugador, JugAux);
		todoOk=1;
	}
    return todoOk;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int todoOk=0;
	int idBuscar;
	int indice;
	int opcion;
	int respuesta;
	Jugador* JugAux;
	if(pArrayListJugador!=NULL)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("|       MENU MODIFICACION    |\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		controller_listarJugadores(pArrayListJugador);

		utn_getInt(&idBuscar, "Ingrese jugador a modificar por ID: ", "ERROR.", 1, 500, 100);

		indice=BuscarJugadorId(idBuscar, pArrayListJugador);

		if(indice==-1)
		{
			printf("No se encontro ningun jugador con ese ID!\n");
		}
		else
		{
			JugAux= ll_get(pArrayListJugador, indice);
			mostrarJugador(JugAux);
			respuesta=confirmaSiNo("Confirma jugador para modificar? ", "ERROR. Reingrese respuesta!\n");
			if(respuesta=='s')
			{
				opcion=menuModificacion();
				switchModificacion(opcion, JugAux);
			}
			else
			{
				printf("Modificacion cancelada por el usuario!\n");
			}
		todoOk=1;
		}

	}
    return todoOk;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int todoOk=0;
	int opcion;
	int indice;
	int respuesta;
//	int indiceJugador;
	int idSeleccion;
	char opcionConfirma;
	Jugador* JugAux;

	if(pArrayListJugador!=NULL)
	{
		system("cls");
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
				"|       MENU BAJA JUGADOR        |\n"
				"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");

		controller_listarJugadores(pArrayListJugador);
		utn_getInt(&opcion, "Ingrese jugador a dar de baja por ID: ","ERROR. ", 1, 600, 100);
		indice=BuscarJugadorId(opcion, pArrayListJugador);
		if(indice==-1)
		{
			printf("No se encontro ningun jugador con ese ID!\n");
		}
		else
		{

			JugAux=ll_get(pArrayListJugador, indice);
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
			printf("|  ID  |        NOMBRE           |    EDAD    |         POSICION         |      NACIONALIDAD     |      SELECCION     |\n");
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
			mostrarJugador(JugAux);
			respuesta=confirmaSiNo("Confirma jugador para dar de baja? ", "ERROR. Reingrese respuesta!\n");
			if(respuesta)
			{
				jug_getSIdSeleccion(JugAux, &idSeleccion);
				if(idSeleccion==0)
				{
					ll_remove(pArrayListJugador, indice);
					jug_delete(JugAux);
					printf("Jugador dado de baja!\n");

					}
					else if(idSeleccion!=0)
					{
						printf("El jugador seleccionado para eliminar esta convocado a una seleccion.\n Para poder dar de baja un jugador, primero hay que quitarlo de la seleccion.\n");
						opcionConfirma=confirmaSiNo("Quiere dar de baja la convocacion a la seleccion? ", "ERROR. ");
						if(opcionConfirma=='s')
						{
							controller_quitarJugador(pArrayListJugador, pArrayListSeleccion);
							ll_remove(pArrayListJugador, indice);
							jug_delete(JugAux);
							printf("Jugador dado de baja!\n");
					}
				}
			}
			else
			{
				printf("Baja cancelada por el usuario!\n");
			}
			todoOk=1;
		}
	}

    return todoOk;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int todoOk=0;
	int tam;

	Jugador* JugAux=NULL;
	if(pArrayListJugador!=NULL)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("|             MENU JUGADORES                  |\n");
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("|  ID  |            NOMBRE            |  EDAD  |          POSICION         |         NACIONALIDAD      |          SELECCION        |\n");
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		tam=ll_len(pArrayListJugador);
		for(int i=0;i<tam;i++)
		{
			JugAux=(Jugador*)ll_get(pArrayListJugador, i);
			mostrarJugador(JugAux);
			todoOk=1;
		}
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	}

	return todoOk;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int todoOk=0;
	int opcion;
	int opcionOrdenar;
	if(pArrayListJugador!=NULL)
	{
		opcion=menuOrdenamiento();
		fflush(stdin);
		utn_getInt(&opcionOrdenar, "Ingrese 1 para ordenar de forma Ascendente. Ingrese 0 para ordenar de forma Descendente: ", "ERROR.",0, 1, 100);
		switch(opcion)
		{
		fflush(stdin);
			case 1:
				ll_sort(pArrayListJugador, ordenarJugadoresPorNacionalidad, opcionOrdenar);
				controller_listarJugadores(pArrayListJugador);
				break;

			case 2:
				ll_sort(pArrayListSeleccion,ordenarJugadoresPorConfederacion, opcionOrdenar);
				controller_listarSelecciones(pArrayListSeleccion);
				break;

			case 3:
				ll_sort(pArrayListJugador, ordenarJugadoresPorEdad, opcionOrdenar);
				controller_listarJugadores(pArrayListJugador);
				break;

			case 4:
				ll_sort(pArrayListJugador, ordenarJugadoresPorNombre, opcionOrdenar);
				controller_listarJugadores(pArrayListJugador);
				break;

			case 5:
				printf("Volviendo...\n");
				break;
		}

	}

    return todoOk;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int todoOk=0;
	Jugador* JugAux=NULL;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	int tam;
	FILE* f=fopen(path,"w");

	tam=ll_len(pArrayListJugador);

	if(path!=NULL && pArrayListJugador!=NULL && f!=NULL)
	{
	fprintf(f,"id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
		for(int i=0;i<tam;i++)
		{
			JugAux=(Jugador*)ll_get(pArrayListJugador, i);
			jug_getId(JugAux, &id);
			jug_getNombreCompleto(JugAux, nombreCompleto);
			jug_getEdad(JugAux, &edad);
			jug_getPosicion(JugAux, posicion);
			jug_getNacionalidad(JugAux, nacionalidad);
			jug_getSIdSeleccion(JugAux, &idSeleccion);
			fprintf(f,"%d,%s,%d,%s,%s,%d\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
			todoOk=1;
		}
	}
	fclose(f);
    return todoOk;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int todoOk=0;
	int tam;
	FILE* f;
	Jugador* JugAux=NULL;
	if(path!=NULL && pArrayListJugador!=NULL)
	{
		f = fopen(path,"wb");
		tam=ll_len(pArrayListJugador);
		for(int i=0; i<tam;i++)
		{
			JugAux=(Jugador*)ll_get(pArrayListJugador,i);
			fwrite(JugAux,sizeof(Jugador),1,f);
			todoOk=1;
		}
	}
    return todoOk;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
  int  todoOk=0;

  	  FILE* f= fopen(path,"r");
	  if(f!=NULL && pArrayListSeleccion!=NULL)
	  {
		parser_SeleccionFromText(f, pArrayListSeleccion);
		todoOk=1;
	  }
	  fclose(f);
  return todoOk;
}

/** \brief Modificar datos de seleccion
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion,int id,int opcion)
{
	int indice=-1;
//	int tam;
//	int idSelec;
//	int indiceAux;
	int cantConvocados;
	Seleccion* SelAux=NULL;

	if(id>=0 && pArrayListSeleccion!=NULL)
	{
//		tam=ll_len(pArrayListSeleccion);

//		for(int i=0;i<tam;i++)
//		{
			SelAux=(Seleccion*)ll_get(pArrayListSeleccion,id);
//			indiceAux=ll_indexOf(pArrayListSeleccion, SelAux);
			selec_getConvocados(SelAux, &cantConvocados);
//			if(indiceAux==id)
//			{
//			printf("%d\n",cantConvocados);
				switch(opcion)
				{
				case 1:
					cantConvocados++;
					selec_setConvocados(SelAux, cantConvocados);
//					selec_se
					break;

				case 2:
					cantConvocados--;
					selec_setConvocados(SelAux, cantConvocados);
					printf("%d\n",cantConvocados);
					break;
				}
//			}
//		}
	}
	return indice;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int todoOk=0;
	int tam;

	Seleccion* SelAux=NULL;
	if(pArrayListSeleccion!=NULL)
	{
	tam=ll_len(pArrayListSeleccion);
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			"|                          MENU SELECCIONES                        |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			"|    ID  |      SELECCIONES       |  CONFEDERACION  |  CONVOCADOS  |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
			for(int i=0;i<tam;i++)
			{
				SelAux=(Seleccion*)ll_get(pArrayListSeleccion,i);
				mostrarSeleccion(SelAux);
				todoOk=1;
			}
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	}
    return todoOk;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int todoOk=0;
	Seleccion* SelAux=NULL;
	int id;
	char pais[100];
	char confederacion[100];
	int convocados;

	int tam;
	FILE* f=fopen(path,"w");

	tam=ll_len(pArrayListSeleccion);

	if(path!=NULL && pArrayListSeleccion!=NULL && f!=NULL)
	{
	fprintf(f,"id,pais,confederacion,convocados\n");
		for(int i=0;i<tam;i++)
		{
			SelAux=(Seleccion*)ll_get(pArrayListSeleccion, i);
			selec_getId(SelAux, &id);
			selec_getPais(SelAux, pais);
			selec_getConfederacion(SelAux, confederacion);
			selec_getConvocados(SelAux, &convocados);
			fprintf(f,"%d,%s,%s,%d\n",id,pais,confederacion,convocados);
			todoOk=1;
		}
	}
	fclose(f);
    return todoOk;
}


int controller_convocarJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int todoOk=0;
		int idBuscar;
		int indice;
//		int opcion;
		int respuesta;
		int opcionSeleccion;
		int respuestaSeleccion;
		int indiceSeleccion;
		int convocados;

		Jugador* JugAux=NULL;
		Seleccion* SelAux=NULL;
		if(pArrayListJugador!=NULL)
		{
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("|       MENU CONVOCACION     |\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

			controller_listarJugadores(pArrayListJugador);

			utn_getInt(&idBuscar, "Ingrese jugador a convocar por ID: ", "ERROR.", 1, 500, 100);

			indice=BuscarJugadorId(idBuscar, pArrayListJugador);

			if(indice==-1)
			{
				printf("No se encontro ningun jugador con ese ID!\n");
			}
			else
			{
				JugAux=(Jugador*)ll_get(pArrayListJugador, indice);
				mostrarJugador(JugAux);
				respuesta=confirmaSiNo("Confirma jugador para convocar? ", "ERROR. Reingrese respuesta!\n");
				if(respuesta=='s')
				{
					controller_listarSelecciones(pArrayListSeleccion);
					utn_getInt(&opcionSeleccion, "Ingrese ID de seleccion a convocar: ", "ERROR. ", 1, 32, 100);

					indiceSeleccion=BuscarSeleccionId(opcionSeleccion, pArrayListSeleccion);

					SelAux=(Seleccion*)ll_get(pArrayListSeleccion,indiceSeleccion);

					mostrarSeleccion(SelAux);

					respuestaSeleccion=confirmaSiNo("Confirma seleccion para convocar? ", "ERROR. Reingrese respuesta!\n");
					selec_getConvocados(SelAux, &convocados);

					if(respuestaSeleccion=='s' && convocados<22)
					{
						jug_setIdSeleccion(JugAux, opcionSeleccion);//duda
						controller_editarSeleccion(pArrayListSeleccion, indiceSeleccion,1);
					}
				}
				else
				{
					printf("Convocacion cancelada por el usuario!\n");
				}
			todoOk=1;
			}

		}
	    return todoOk;
}


int controller_quitarJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int todoOk=0;
		int idBuscar;
		int indice;
//		int opcion;
		int respuesta;
//		int opcionSeleccion=0;
//		int respuestaSeleccion;
		int indiceSeleccion;
		int seleccion;
		int convocados;

		Jugador* JugAux=NULL;
		Seleccion* SelAux=NULL;
		if(pArrayListJugador!=NULL)
		{
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
			printf("|       MENU QUITAR JUGADOR SELECCION     |\n");
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");

			controller_listarJugadores(pArrayListJugador);

			utn_getInt(&idBuscar, "Ingrese jugador a quitar por ID: ", "ERROR.", 1, 500, 100);

			indice=BuscarJugadorId(idBuscar, pArrayListJugador);

			if(indice==-1)
			{
				printf("No se encontro ningun jugador con ese ID!\n");
			}
			else
			{
				JugAux= (Jugador*)ll_get(pArrayListJugador, indice);
				mostrarJugador(JugAux);

				respuesta=confirmaSiNo("Confirma jugador para quitar? ", "ERROR. Reingrese respuesta!\n");
				jug_getSIdSeleccion(JugAux, &seleccion);
				indiceSeleccion=BuscarSeleccionId(seleccion, pArrayListSeleccion);
				SelAux= (Seleccion*)ll_get(pArrayListSeleccion, indiceSeleccion);
				selec_getConvocados(SelAux, &convocados);

				if(convocados>0)
				{
					if(respuesta=='s')
					{
//							jug_getSIdSeleccion(JugAux, &indiceSeleccion);
							jug_setIdSeleccion(JugAux, 0);
							controller_editarSeleccion(pArrayListSeleccion, indiceSeleccion,2);
					}
					else
					{
						printf("Operacion cancelada por el usuario!\n");
					}
				}
				else
				{
					printf("No hay jugadores convocados en esa seleccion!\n");
				}

			todoOk=1;
			}

		}
	    return todoOk;
}


int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador)
{
	int todoOk=0;
	int tam;
	int idConvocado;

	Jugador* JugAux=NULL;
	if(pArrayListJugador!=NULL)
	{
		printf("                          |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("                          |               MENU JUGADORES CONVOCADOS                 |\n");
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("|  ID  |           NOMBRE             |  EDAD  |         POSICION          |        NACIONALIDAD       |         SELECCION         |\n");
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		tam=ll_len(pArrayListJugador);
		for(int i=0;i<tam;i++)
		{

			JugAux=(Jugador*)ll_get(pArrayListJugador, i);
			jug_getSIdSeleccion(JugAux, &idConvocado);
			if(idConvocado!=0)
			{
			mostrarJugador(JugAux);
			todoOk=1;
			}
		}
	}

	return todoOk;
}




int nuevaListaBinarioPorConfederacion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion,LinkedList* pArrayListaNuevaJugadores)
{
    int todoOk=0;
    int idAux;
    int tamJug;
    int idSeleccionAux;
    int tamSel;
//  int tamAuxSel;
    int opcion;
    char opcionConfederaciones[50];
//	char AuxOpcionConfederacion[30]
    char confederacionSeleccionAux[50];

    opcion=menuConfederaciones();
    switchConfederaciones(opcion,opcionConfederaciones);
    Jugador* JugAux=NULL;
    Seleccion* SelAux=NULL;

    if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL && pArrayListaNuevaJugadores!=NULL)
    {
    	tamSel=ll_len(pArrayListSeleccion);
    	tamJug=ll_len(pArrayListJugador);
        for(int i=0;i<tamJug;i++)
        {

        	JugAux=ll_get(pArrayListJugador, i);
            jug_getSIdSeleccion(JugAux, &idAux);

            for(int j=0;j<tamSel;j++)
            {
//            	printf("Entro toda toda!\n");
            	SelAux=ll_get(pArrayListSeleccion, j);
                selec_getId(SelAux, &idSeleccionAux);
                selec_getConfederacion(SelAux, confederacionSeleccionAux);
                //if(!confederacionSeleccionAux==opcionConfederaciones && idAux==idSeleccionAux && idAux!=0 )
                if(strcmp(confederacionSeleccionAux, opcionConfederaciones)==0 && idAux==idSeleccionAux && idAux!=0 )
                {
                    ll_add(pArrayListaNuevaJugadores, JugAux);
//                    mostrarJugador(JugAux);
                }

            }
            todoOk=1;
        }
    }

    return todoOk;
}
