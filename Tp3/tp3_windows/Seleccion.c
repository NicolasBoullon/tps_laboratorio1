#include "Seleccion.h"
//typedef struct
//{
//	int id;
//	char pais[30];
//	char confederacion[30];
//	int convocados;
//}Seleccion;
Seleccion* selec_new()
{
	Seleccion* s= (Seleccion*) malloc(sizeof(Seleccion));

	if(s!=NULL)
	{
		s->id=0;
		*(s->pais)='\0';
		*(s->confederacion)='\0';
		s->convocados=0;
	}

	return s;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* sel= selec_new();

	if(sel!=NULL)
	{
		if(!(selec_setId(sel, atoi(idStr)) &&
				selec_setPais(sel, paisStr) &&
				selec_setConfederacion(sel, confederacionStr) &&
				selec_setConvocados(sel, atoi(convocadosStr))))
		{
			sel=NULL;
		}
	}
	return sel;
}
//SELEC DELETE---------------------------------
void selec_delete(Seleccion* this)
{
	free(this);
}
//ID-------------------------------------------
int selec_setId(Seleccion* this,int id)
{
	int todoOk=0;
	if(this!= NULL && id >=1 && id <=32)
	{
		this->id=id;
		todoOk=1;
	}
	return todoOk;
}
int selec_getId(Seleccion* this,int* id)
{
	int todoOk=0;
	if(this!= NULL && id != NULL)
	{
		*id=this->id;
		todoOk=1;
	}
	return todoOk;
}
//SELEC PAIS------------------------------------------
int selec_setPais(Seleccion* this,char* pais)
{
	int todoOk=0;
	char auxCad[30];
	strcpy(auxCad,pais);
	int largo=strlen(auxCad);
	if(this!= NULL && pais!=NULL && strlen(auxCad)<30)
	{
		for(int i=0; i<largo;i++)
		{
			auxCad[i]=tolower(auxCad[i]);
		}
		auxCad[0]=toupper(auxCad[0]);
		strcpy(this->pais,auxCad);
		todoOk=1;
	}

	return todoOk;
}
int selec_getPais(Seleccion* this,char* pais)
{
	int todoOk=0;
	if(this!= NULL && pais!=NULL)
	{
		strcpy(pais,this->pais);
		todoOk=1;
	}

	return todoOk;
}
//SELEC CONFEDERACION------------------------------------------
int selec_setConfederacion(Seleccion* this,char* confederacion)
{
	int todoOk=0;
	char auxCad[30];
	strcpy(auxCad,confederacion);
	int largo=strlen(auxCad);
	if(this!= NULL && confederacion!=NULL && strlen(auxCad)<30)
	{
		for(int i=0; i<largo;i++)
		{
			auxCad[i]=tolower(auxCad[i]);
		}
		auxCad[0]=toupper(auxCad[0]);
		strcpy(this->confederacion,auxCad);
		todoOk=1;
	}

	return todoOk;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int todoOk=0;
	if(this!= NULL && confederacion!=NULL)
	{
		strcpy(confederacion,this->confederacion);
		todoOk=1;
	}

	return todoOk;
}

//SELEC CONVOCADOS------------------------------------------
int selec_setConvocados(Seleccion* this,int convocados)
{
	int todoOk=0;
	if(this != NULL && convocados<1000)
	{
		this->convocados=convocados;
		todoOk=1;
	}
	return todoOk;
}


int selec_getConvocados(Seleccion* this,int* convocados)
{
	int todoOk=0;
	if(this!= NULL && convocados != NULL)
	{
		*convocados=this->convocados;
		todoOk=1;
	}
	return todoOk;
}

int mostrarSeleccion(Seleccion* selecciones)
{
  int todoOk;
  int id;
  char pais[50];
  char confederacion[50];
  int convocados;

  if(selecciones!=NULL)
  {
    if(selec_getId(selecciones,&id) &&
		selec_getPais(selecciones, pais) &&
		selec_getConfederacion(selecciones, confederacion) &&
		selec_getConvocados(selecciones, &convocados))
    {
    	printf("|  %4d  |  %20s  |    %10s   |      %2d      |\n",id,pais,confederacion,convocados);
    	todoOk=1;
    }
  }

  return todoOk;
}


int BuscarSeleccionId(int id, LinkedList* this)
{
	int indice=-1;
	int tam;
	int idSel;

	Seleccion* SelAux=NULL;

	if(this!=NULL)
	{
		tam=ll_len(this);

		for(int i=0;i<tam;i++)
		{
			SelAux=ll_get(this,i);
			selec_getId(SelAux, &idSel);
			if(idSel==id)
			{
				indice=ll_indexOf(this, SelAux);
			}
		}
	}
	return indice;
}


int ordenarJugadoresPorConfederacion(void* pPrimerSeleccion, void* pSegundoSeleccion)
{
	int retorno=0;
	char confSeleccionUno[30];
	char confSeleccionDos[30];

	Seleccion* SelAuxUno=NULL;
	Seleccion* SelAuxDos=NULL;

	if(pPrimerSeleccion!=NULL && pSegundoSeleccion!=NULL)
	{
		SelAuxUno=(Seleccion*)pPrimerSeleccion;
		SelAuxDos=(Seleccion*)pSegundoSeleccion;

		selec_getConfederacion(SelAuxUno, confSeleccionUno);
		selec_getConfederacion(SelAuxDos, confSeleccionDos);
		retorno=strcmp(confSeleccionUno,confSeleccionDos);
	}
	return retorno;
}

