#include "Jugador.h"
#include "menu.h"

Jugador* jug_new()
{
	Jugador* j = (Jugador*) malloc(sizeof(Jugador));
	if(j!=NULL)
	{
		j->id=0;
		*(j->nombreCompleto)='\0';
		j->edad=0;
		*(j->posicion)='\0';
		*(j->nacionalidad)='\0';
		j->idSeleccion=0;
	}

	return j;
}


Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* j = jug_new();
	if(j !=  NULL)
	{
		if(!(jug_setId(j,atoi(idStr)) && jug_setNombreCompleto(j, nombreCompletoStr) && jug_setEdad(j, atoi(edadStr)) && jug_setPosicion(j, posicionStr) &&
				jug_setNacionalidad(j, nacionalidadStr) && jug_setIdSeleccion(j, atoi(idSelccionStr))))
		{
			free(j);
			j=NULL;
		}
	}
	return j;
}



//JUGADOR----------------------------------------------
//ID--------------------------
int jug_setId(Jugador* this,int id)
{
    int todoOk = 0;

    if(this != NULL && id >= 1)
    {
    	this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int jug_getId(Jugador* this,int* id)
{
    int todoOk = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}
//NOMBRECOMPLETO----------------------------------------
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int todoOk=0;
	char auxCadena[100];
	strcpy(auxCadena,nombreCompleto);
	int largo=strlen(auxCadena);

	if(this!=NULL  && strlen(auxCadena)<100)
	{

		for(int i=0; i<largo;i++)
		{
			auxCadena[i]=tolower(auxCadena[i]);
		}
		for(int i=0;i<largo;i++)
		{

			auxCadena[0]=toupper(auxCadena[0]);
			if(auxCadena[i]==' ')
			{
				auxCadena[i+1]=toupper(auxCadena[i+1]);
			}
		}
		strcpy(this->nombreCompleto,auxCadena);
		todoOk=1;
	}
	return todoOk;
}
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int todoOk=0;
	if(this!=NULL && nombreCompleto)
	{
		strcpy(nombreCompleto,this->nombreCompleto);
		todoOk=1;
	}
	return todoOk;
}
//POSICION---------------------------------------------------
int jug_setPosicion(Jugador* this,char* posicion)
{
	int todoOk=0;
	char auxCadena[30];
	strcpy(auxCadena,posicion);
	int largo=strlen(auxCadena);

	if(this!=NULL && posicion!= NULL && strlen(auxCadena)<30)
	{
		for(int i=0; i<largo;i++)
		{
			auxCadena[i]=tolower(auxCadena[i]);
		}
		auxCadena[0]=toupper(auxCadena[0]);
		strcpy(this->posicion,auxCadena);
		todoOk=1;
	}
	return todoOk;
}
int jug_getPosicion(Jugador* this,char* posicion)
{
	int todoOk=0;
	if(this!=NULL && posicion!=NULL)
	{
		strcpy(posicion,this->posicion);
		todoOk=1;
	}
	return todoOk;
}
//NACIONALIDAD----------------------------------------------------
int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int todoOk=0;
	char auxCadena[30];
	strcpy(auxCadena,nacionalidad);
	int largo=strlen(auxCadena);
	if(this!=NULL && nacionalidad!= NULL && strlen(auxCadena)<30)
	{
		for(int i=0; i<largo;i++)
		{
			auxCadena[i]=tolower(auxCadena[i]);
		}
		auxCadena[0]=toupper(auxCadena[0]);
		strcpy(this->nacionalidad,auxCadena);
		todoOk=1;
	}
	return todoOk;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int todoOk=0;
	if(this!=NULL && nacionalidad)
	{
		strcpy(nacionalidad,this->nacionalidad);
		todoOk=1;
	}
	return todoOk;
}
void jug_delete(Jugador* this)
{
	free(this);
}
//EDAD-------------------------
int jug_setEdad(Jugador* this,int edad)
{
    int todoOk = 0;

    if(this != NULL && edad >= 17 && edad <= 50)
    {
    	this->edad = edad;
        todoOk=1;
    }
    return todoOk;
}
int jug_getEdad(Jugador* this,int* edad)
{
    int todoOk = 0;

    if(this != NULL && edad != NULL)
    {
        *edad = this->edad;
        todoOk = 1;
    }
    return todoOk;
}
//IDSELECCION-----------------------------
int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
    int todoOk = 0;

    if(this != NULL && idSeleccion >= 0 && idSeleccion <= 1000)
    {
    	this->idSeleccion = idSeleccion;
        todoOk = 1;
    }
    return todoOk;
}
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
    int todoOk = 0;

    if(this != NULL && idSeleccion != NULL)
    {
        *idSeleccion = this->idSeleccion;
        todoOk = 1;
    }
    return todoOk;
}


int mostrarJugador(Jugador* jugador)
{
	int todoOk=0;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[50];
//	int idNacionalidad;
	char nacionalidad[50];
	int idSeleccion;
	char descSeleccion[50];
//	itoa(idNacionalidad,nacionalidad,10);
	if(jugador!=NULL)
	{
		if(jug_getId(jugador, &id)&&
		jug_getNombreCompleto(jugador, nombreCompleto)&&
		jug_getEdad(jugador, &edad)&&
		jug_getPosicion(jugador, posicion)&&
		jug_getNacionalidad(jugador, nacionalidad) &&
		jug_getSIdSeleccion(jugador, &idSeleccion))
		{
//			itoa(nacionalidad,idNacionalidad,10);
			if(idSeleccion!=0)
			{
				cargarIdSeleccion(idSeleccion, descSeleccion);
			}
			else
			{
				strcpy(descSeleccion,"No convocado");
			}
		printf("| %4d |  %25s   |   %2d   |   %20s    |   %20s    |   %20s    |\n",id,nombreCompleto,edad,posicion,nacionalidad,descSeleccion);

		todoOk=1;
		}
	}

	return todoOk;
}

int BuscarJugadorId(int id, LinkedList* this)
{
	int indice=-1;
	int tam;


	Jugador* JugAux=NULL;

	if(id>0 && this!=NULL)
	{
		tam=ll_len(this);

		for(int i=0;i<tam;i++)
		{
			JugAux=(Jugador*)ll_get(this,i);

			if(JugAux->id==id)
			{
				indice=ll_indexOf(this, JugAux);
			}
		}
	}

	return indice;
}


int ordenarJugadoresPorNacionalidad(void* pPrimerJugador, void* pSegundoJugador)
{
	char nacionalidadJugadorUno[50];
	char nacionalidadJugadorDos[50];
	Jugador* JugAuxUno;
	Jugador* JugAuxDos;
	int retorno;

	if(pPrimerJugador!=NULL && pSegundoJugador!=NULL)
	{

		JugAuxUno=(Jugador*) pPrimerJugador;
		JugAuxDos=(Jugador*) pSegundoJugador;

		jug_getNacionalidad(JugAuxUno, nacionalidadJugadorUno);
		jug_getNacionalidad(JugAuxDos, nacionalidadJugadorDos);
		retorno=strcmp(nacionalidadJugadorUno,nacionalidadJugadorDos);
	}
	return retorno;
}

int ordenarJugadoresPorNombre(void* pPrimerJugador, void* pSegundoJugador)
{
	int retorno;
	char nombreJugadorUno[50];
	char nombreJugadorDos[50];
	Jugador* JugAuxUno;
	Jugador* JugAuxDos;


	if(pPrimerJugador!=NULL && pSegundoJugador!=NULL)
	{

		JugAuxUno=(Jugador*) pPrimerJugador;
		JugAuxDos=(Jugador*) pSegundoJugador;

		jug_getNombreCompleto(JugAuxUno, nombreJugadorUno);
		jug_getNombreCompleto(JugAuxDos, nombreJugadorDos);
		retorno=strcmp(nombreJugadorUno,nombreJugadorDos);
	}
	return retorno;
}

int ordenarJugadoresPorEdad(void* pPrimerJugador, void* pSegundoJugador)
{
	int retorno=0;
	int edadPrimerJugador;
	int edadSegundoJugador;

	Jugador* JugAuxUno;
	Jugador* JugAuxDos;
	if(pPrimerJugador!=NULL && pSegundoJugador!=NULL)
	{
		JugAuxUno=(Jugador*) pPrimerJugador;
		JugAuxDos=(Jugador*) pSegundoJugador;

		jug_getEdad(JugAuxUno, &edadPrimerJugador);
		jug_getEdad(JugAuxDos, &edadSegundoJugador);
		if(edadPrimerJugador>edadSegundoJugador)
		{
			retorno=1;
		}
		else if(edadPrimerJugador<edadSegundoJugador)
		{
			retorno=-1;
		}
	}
	return retorno;
}

