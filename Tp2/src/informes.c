/*
 * informes.c
 *
 *  Created on: 28 oct 2022
 *      Author: usuario
 */


#include "informes.h"


int listadoJugadoresConfederacionAlfabeticamente(eJugador jugadores[],int tamJ,eConfederacion confederaciones[],int tamC)
{
	int todoOk=0;
	char descricpionI[20];
	char descricpionJ[20];
	eJugador auxJugador;

	if(jugadores!= NULL && tamJ >0 && confederaciones != NULL&& tamC>0)
	{
		for(int i=0;i<tamJ -1 ;i++)
		{
			for(int j= i+1; j<tamJ;j++)
			{
				cargarConfederacion(confederaciones, tamC, jugadores[i].idConfederacion, descricpionI);
				cargarConfederacion(confederaciones, tamC, jugadores[j].idConfederacion, descricpionJ);

				if((strcmp(descricpionI,descricpionJ)>0) || (strcmp(descricpionI,descricpionJ)==0 && strcmp(jugadores[i].nombre,jugadores[j].nombre)>0))
				{
					auxJugador=jugadores[i];
					jugadores[i]=jugadores[j];
					jugadores[j]=auxJugador;
				}
			}
		}
		mostrarJugadores(jugadores, tamJ, confederaciones, tamC);
		todoOk=1;
	}
	return todoOk;
}

int mostrarPersonasTodasConfederaciones(eConfederacion confederaciones[],int tamC,eJugador jugadores[],int tamJ)
{
	int todoOk=0;
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|     MENU JUGADORES CADA CONFEDERACION     |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");

	if(confederaciones!=NULL && tamC>0&& jugadores!= NULL && tamJ>0)
		{
			for(int i=0;i<tamC;i++)
			{
				if(!confederaciones[i].isEmpty){
				printf("\nConfederacion: %s\n",confederaciones[i].nombre);
				mostrarJugadoresIdConfederacion(confederaciones[i].id, confederaciones, tamC, jugadores, tamJ);
				}
			}

		}
	return todoOk;
}

int mostrarJugadoresIdConfederacion(int opcion,eConfederacion confederaciones[],int tamC,eJugador jugadores[],int tamJ)
{
	int todoOk=0;
	int flag=1;

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|  ID  |        NOMBRE      |       POSICION       | CAMISETA |        SALARIO       |   CONFEDERACION  |   CONTRATO  |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


			for(int i=0;i<tamJ;i++)
			{
				if(!jugadores[i].isEmpty && !confederaciones[i].isEmpty && jugadores[i].idConfederacion== opcion)
				{
					mostrarJugador(jugadores[i], confederaciones, tamC);
					flag=0;
				}
			}
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			if(flag)
			{
				printf("No hay personas para mostrar en esta confederacion\n");
			}

		return todoOk;
}


int promedioTodosSalarios(eJugador jugadores[],int tamJ)
{
	int todoOk=0;
	float promedioSalario;
	float acumSalario=0;
	int contador=0;

		if(jugadores!= NULL && tamJ>0)
			{
			system("cls");
			printf("    ***Promedio Salario***\n");

				for(int j=0; j<tamJ;j++)
					{
						if(!jugadores[j].isEmpty)
						{
							contador++;
							acumSalario += jugadores[j].salario;
						}
					}
				if(contador!=0)
				{
					promedioSalario =  acumSalario / contador;
				}
				printf("El total de los salarios es de %.2f y el promedio es de %.2f\n",acumSalario,promedioSalario);
				printf("Jugador o jugadores con promedio de salario mas alto \n");
				for(int i=0; i< tamJ;i++)
				{
					if(!jugadores[i].isEmpty &&jugadores[i].salario>=promedioSalario)
					{
						printf("%s\n",jugadores[i].nombre);
					}
				}
			todoOk=1;
			}
	return todoOk;
}



int ConfederacionMayorAniosContrato(eConfederacion confederaciones[],int tamC,eJugador jugadores[],int tamJ)
{
	int tamanioConfederaciones=tamC;
	int todoOk=0;
	int acumContrato[tamanioConfederaciones];
	int mayor=0;

	if(confederaciones!=NULL && tamC>0 && jugadores!= NULL && tamJ>0)
		{

		system("cls");
		printf("    ***Confederacion mayor años de contrato***\n");
		for(int i=0;i<tamC;i++)
			{
			acumContrato[i]=0;
			for(int j=0; j<tamJ;j++)
				{
					if(!jugadores[j].isEmpty && confederaciones[i].id==jugadores[j].idConfederacion)
					{
						acumContrato[i] += jugadores[j].anioContrato;
					}
				}

			}
			for(int i=0; i<tamC;i++)
			{
				if(i==0 || acumContrato[i]>mayor)
				{
					mayor=acumContrato[i];
				}
			}
			for(int i=0; i< tamC;i++)
			{
				if(acumContrato[i]==mayor && acumContrato>0)
				{
					printf("%s   %d\n",confederaciones[i].nombre,acumContrato[i]);
				}
			}
		todoOk=1;
		}
return todoOk;
}

//★ Informar porcentaje de jugadores por cada confederación.
//★ Informar cual es la región con más jugadores y el listado de los mismos.*/


int porcentajeJugadoresPorConfederacion(eConfederacion confederaciones[],int tamC,eJugador jugadores[],int tamJ)
{
	int tamanioConfederaciones=tamC;
	int todoOk=0;
	float porcentajes[tamanioConfederaciones];
	int contador=0;
	int contadorJugadores=0;

		if(confederaciones!=NULL && tamC>0&& jugadores!= NULL && tamJ>0)
			{

			system("cls");
			printf("    ***Porcentaje de jugador por confederacion***\n");

			for(int i=0;i<tamJ;i++)
				{
				if(!jugadores[i].isEmpty)
				{
					contadorJugadores++;
				}
			}

			for(int i=0;i<tamC;i++)
			{
				contador=0;

				for(int j=0; j<tamJ;j++)
					{
						if(!jugadores[j].isEmpty  && confederaciones[i].id==jugadores[j].idConfederacion)
						{
							contador++;
						}
					}
				if(contador!=0)
				{
					porcentajes[i] = (float)(contador * 100) / contadorJugadores;
				}
			}

			printf("Porcentaje de jugador por confederaciones \n");
				for(int i=0; i< tamC;i++)
				{
					if(!confederaciones[i].isEmpty){
					printf("%s   %%%.2f\n",confederaciones[i].nombre,porcentajes[i]);
					}
				}
			todoOk=1;
			}
	return todoOk;
}



int regionMasElegida(eConfederacion confederaciones[],int tamC,eJugador jugadores[],int tamJ)
{
	int tamanioConfederaciones=tamC;
	int todoOk=0;
	int contadores[tamanioConfederaciones];
	int mayor=0;

	if(confederaciones!=NULL && tamC>0&& jugadores!= NULL && tamJ>0)
		{

		system("cls");
		printf("    ***Region con mas jugadores***\n");
		for(int i=0;i<tamC;i++)
			{
			contadores[i]=0;
			for(int j=0; j<tamJ;j++)
				{
					if(!jugadores[j].isEmpty && confederaciones[i].id==jugadores[j].idConfederacion)
					{
						contadores[i]++;
					}
				}
			}
			for(int i=0; i< tamC;i++)
			{
				if(i==0 || contadores[i]>mayor)
				{
					mayor=contadores[i];
				}
			}
			printf("La region o regiones con mas jugadores son\n");
			for(int i=0; i< tamC;i++)
			{
				if(contadores[i]==mayor && contadores[i]>0)
				{
					printf("%s  con %d  jugadores.\n",confederaciones[i].region,contadores[i]);
					for(int j=0;j<tamJ;j++)
					{
					if(!jugadores[j].isEmpty && confederaciones[i].id==jugadores[j].idConfederacion)
						{
							printf("Los jugadores son %s\n",jugadores[j].nombre);
						}
					}
				}
			}
		todoOk=1;
		}
return todoOk;
}


