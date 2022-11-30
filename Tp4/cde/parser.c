#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int todoOk=0;

	Jugador* JugAux=NULL;

	char id[50];
	char nombreCompleto[100];
	char edad[50];
	char posicion[30];
	char nacionalidad[30];
	char idSeleccion[50];
	char fantasma[500];

	if(pFile!=NULL && pArrayListJugador!=NULL)
	{
		fscanf(pFile,"%s",fantasma);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
			JugAux=jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			ll_add(pArrayListJugador, JugAux);
			todoOk=1;
		}
	}
	fclose(pFile);

    return todoOk;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* auxPArrayListJugador)
{
	int todoOk=0;
	int cant;
	Jugador* JugAux=NULL;

	if(pFile!=NULL && auxPArrayListJugador!=NULL)
	{
		while(!feof(pFile))
		{
			JugAux=jug_new();
			cant=fread(JugAux,sizeof(Jugador),1,pFile);
			if(cant<1)
			{
				break;
			}
			ll_add(auxPArrayListJugador,JugAux);
			todoOk=1;
//			if(feof(pFile))
//			{
//				break;
//			}
		}
	}

    return todoOk;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int todoOk=0;

	  Seleccion* SelAux=NULL;

	  char id[30];
	  char pais[30];
	  char confederacion[30];
	  char convocados[30];
	  char fantasma[500];

	  if(pFile!=NULL && pArrayListSeleccion!=NULL)
	  {
	    fscanf(pFile,"%s",fantasma);
	    while(!feof(pFile))
	    {
	      fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);
	      SelAux=selec_newParametros(id,pais,confederacion,convocados);
	      ll_add(pArrayListSeleccion,SelAux);
	      todoOk=1;
	    }
	  }


    return todoOk;
}

