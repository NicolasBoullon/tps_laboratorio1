/*
 * inputs.c
 *
 *  Created on: 19 nov 2022
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"




int getString(char string[],char mensaje[],char mensajeError[],int max)
{
	int todoOk=0;
	char bufferString[100];

	if(string!=NULL)
	{
		do{
			printf("%s",mensaje);
			fflush(stdin);
			fgets(bufferString,sizeof(bufferString),stdin);
			bufferString[strlen(bufferString)-1]='\0';


			todoOk= soloCaracter(bufferString);
			if(todoOk==1)
			{
				printf("%s",mensajeError);
			}
			else if(max<strlen(bufferString) || strlen(bufferString)==0)
			{
				printf("%s",mensajeError);
				todoOk=1;
			}
			else
			{
				strcpy(string,bufferString);
			}


		}while(todoOk==1);
	}
	return todoOk;
}


int soloCaracter(char string[])
{
	 int todoOk;
	 int tam;

	 tam= strlen(string);

	 for(int i=0;i<tam;i++)
	 {

		 if((string[i]>='a'&& string[i]<='z') || (string[i]>='A' && string[i]<='Z') || string[i]==' ')
		 {
			 todoOk=0;
		 }
		 else
		 {
			 todoOk=1;
			 break;
		 }
	 }

	 return todoOk;
}



int utn_getInt ( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int aux;
	int retorno = -1;
	fflush(stdin);
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(getInt(&aux)==1)
			{
				if (aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					retorno = 1;
					break;
				}
			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}

int getInt ( int * pResultado)
{
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof (buffer))==0 && esNumericaInt(buffer) == 1)
		{
			*pResultado = atoi (buffer);
			retorno = 1;
		}
	}
	return retorno;
}

int esNumericaInt(char * cadena)
{
	int retorno;
	int i=0;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		retorno = 1;
		while (cadena[i] != '\0' )
		{
			if (cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = -1;
				break ;
			}
			i++;
		}
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}

int myGets(char * cadena, int longitud)
{
	if (cadena != NULL && longitud >0 && fgets (cadena,longitud,stdin)==cadena)
	{
		fflush (stdin);
		if (cadena[ strlen (cadena)-1] == '\n' )
		{
			cadena[ strlen (cadena)-1] = '\0' ;
		}
		return 0;
	}
	return -1;
}

//-----------------------------------------------------------------------------------------

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int utn_getFloat( float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	float aux;
	int retorno = -1;
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(getFloat(&aux)==1)
			{
				if (aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					retorno = 1;
					break;
				}
			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}

float getFloat ( float * pResultado)
{
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof (buffer))==0 && esNumericaFloat(buffer) == 1)
		{
			*pResultado = atof (buffer);
			retorno = 1;
		}
	}
	return retorno;

}

float esNumericaFloat (char * cadena)
{
	int retorno;
	int i=0;
	int contador=0;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		retorno = 1;
		while (cadena[i] != '\0' )
		{
			if (cadena[i] < '.' || cadena[i] > '9' || cadena[i] == '/' || contador>1)
			{
				retorno = -1;
				break ;
			}
			if(cadena[i] == '.')
			{
				contador++;
			}
			i++;

		}

	}
	else
	{
		retorno = -1;
	}
	return retorno;
}


char confirmaSalir()
{
	char salir;
	printf("Seguro que desea salir?   (S/N): ");
	fflush(stdin);
	scanf("%c",&salir);
	while(salir!= 'S' && salir!= 's' && salir!='N' && salir!= 'n')
	{
		printf("Ingrese opcion correcta  (S/N): ");
		fflush(stdin);
		scanf("%c",&salir);
	}
	if(salir== 'N' || salir == 'n')
	{
		salir='n';
	}
	else if(salir== 'S' || salir == 's')
	{
		salir='s';
	}
	return salir;
}

char confirmaSiNo(char* mensaje,char* mensajeError)
{
	char salir;
	printf("%s   (S/N): ",mensaje);
	fflush(stdin);
	scanf("%c",&salir);
	while(salir!= 'S' && salir!= 's' && salir!='N' && salir!= 'n')
	{
		printf("%s  (S/N): ",mensajeError);
		fflush(stdin);
		scanf("%c",&salir);
	}
	if(salir== 'N' || salir == 'n')
	{
		salir='n';
	}
	else if(salir== 'S' || salir == 's')
	{
		salir='s';
	}
	return salir;
}
