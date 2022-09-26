/*
 * funciones.c
 *
 *  Created on: 22 sept 2022
 *      Author: usuario
 */

#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>


int MenuPrincipal(float cHospedaje,float cComida,float  cTransporte,int arqueros,int defensores,int mediocampistas,int delanteros)
{
	int n;
    printf("  Menu principal  \n"
    		"1.Ingreso de los costos de mantenimiento\n"
            " -Costo de Hospedaje -> $%.4f\n"
            " -Costo de Comida -> $%.4f\n"
            " -Costo de Transporte -> $%.4f\n"
            "2.Carga de jugadores\n"
            " -Arqueros -> %d\n"
            " -Defensores -> %d\n"
            " -Mediocampistas -> %d\n"
            " -Delanteros -> %d\n"
            "3.Realizar todos los calculos\n"
            "4.Informar todos los resultados\n"
            "5.Salir\n"
    		"Ingrese una opcion: ",cHospedaje,cComida,cTransporte,arqueros,defensores,mediocampistas,delanteros);
    scanf("%d",&n);

    while(n!=1 && n!=2 && n!=3 && n!=4 && n!=5)
    {
    	printf("Ingrese un numero valido: \n");
    	fflush(stdin);
    	scanf("%d",&n);
    }
    return n;
}

char SubMenuMantenimiento(float cHospedaje,float cComida,float cTransporte)
{
	char n;
	system("cls");
    printf("  Menu mantenimiento  \n"
    		"Costos de mantenimiento:\n"
            " a)Costo de Hospedaje -> $%.4f\n"
            " b)Costo de Comida -> $%.4f\n"
            " c)Costo de Transporte -> $%.4f\n"
    		" d)Volver\n"
    		"Ingrese una opcion: ",cHospedaje,cComida,cTransporte);
	fflush(stdin);
	scanf("%c",&n);
    while(n !='a' && n!='b' && n!='c' && n!='d')
    {
    	printf("Ingrese una opcion valida: ");
    	fflush(stdin);
    	scanf("%c",&n);
    }
	return n;
}

char SubMenuCargaJugadores(int arqueros,int defensores,int mediocampistas,int delanteros)
{
	char ne;
	system("cls");
    printf("  Menu jugadores  \n"
    		"Jugadores:\n"
            " a)Arqueros -> %d\n"
            " b)Defensores -> %d\n"
            " c)Mediocampistas -> %d\n"
    		" d)Delanteros -> %d\n"
    		" e)Volver\n"
    		"Ingrese una opcion: ",arqueros,defensores,mediocampistas,delanteros);
	fflush(stdin);
    scanf("%c",&ne);
    while(ne !='a' && ne!='b' && ne!='c' && ne!='d' && ne!='e')
    {
    	printf("Ingrese una opcion valida: ");
    	fflush(stdin);
    	scanf("%c",&ne);
    }
    return ne;
}

char SubMenuConfederacion()
{
	char opcion;

 	printf("  Menu confederaciones  \n"
 			"Ingrese en que confederacion desarrolla sus actividades:\n"
			" a)AFC en Asia\n"
			" b)CAF en Africa\n"
			" c)CONCACAF en zona del Norte\n"
			" d)CONMEBOL en Sudamerica\n"
 			" e)OFC en Oceania\n"
 			" f)UEFA en Europa\n"
 			"Ingrese una opcion: ");
	fflush(stdin);
	scanf("%c",&opcion);

    while(opcion !='a' && opcion!='b' && opcion!='c' && opcion!='d' && opcion!='e' && opcion!='f')
    {
    	printf("Ingrese una opcion valida: ");
    	fflush(stdin);
    	scanf("%c",&opcion);
    }

    return opcion;
}

void mostrarResultadosFinales(float promedioAsia,float promedioAfrica, float promedioNorte, float promedioSudamerica, float promedioOceania,float promedioEuropa,float sMantenimiento,int okAumento,float aumento,float precioFinal)
{
    printf("\nPromedio AFC: %.4f\n"
    	"Promedio CAF: %.4f\n"
    	"Promedio CONCACAF: %.4f\n"
    	"Promedio CONMEBOL: %.4f\n"
    	"Promedio OFC: %.4f\n"
    	"Promedio UEFA: %.4f\n\n",promedioAsia,promedioAfrica,promedioNorte,promedioSudamerica,promedioOceania,promedioEuropa);


    printf("La suma de los costos de mantenimientos es de: $%.4f\n",sMantenimiento);
    if(okAumento==1)
    {
        printf("El aumento de los costos de mantenimiento fue de: $%.4f\n",aumento);
        printf("El precio final de los costos de mantenimiento es: $%.4f\n\n",precioFinal);
    }
}



void contadorConfederacion(int* pContadorAsia,int contadorAsia,int* pContadorAfrica,int contadorAfrica,int* pContadorNorte,int contadorNorte,int* pContadorSudamerica,int contadorSudamerica,int* pContadorOceania,int contadorOceania,int* pContadorEuropa,int contadorEuropa,char opcion,int* pContJugadores,int contJugadores)
{


		switch(opcion)
				{//llave switch
					case 'a':

						contadorAsia++;
						*pContadorAsia=contadorAsia;
						contJugadores++;
						*pContJugadores=contJugadores;
						break;

					case 'b':

						contadorAfrica++;
						*pContadorAfrica=contadorAfrica;
						contJugadores++;
						*pContJugadores=contJugadores;
						break;

					case 'c':

						contadorNorte++;
						*pContadorNorte=contadorNorte;
						contJugadores++;
						*pContJugadores=contJugadores;
						break;

					case 'd':

						contadorSudamerica++;
						*pContadorSudamerica=contadorSudamerica;
						contJugadores++;
						*pContJugadores=contJugadores;
						break;

					case 'e':

						contadorOceania++;
						*pContadorOceania=contadorOceania;
						contJugadores++;
						*pContJugadores=contJugadores;
						break;

					case 'f':

						contadorEuropa++;
						*pContadorEuropa=contadorEuropa;
						contJugadores++;
						*pContJugadores=contJugadores;
						break;

				}//llave switch

}


void PedirNumero_Float(char mensaje[],char mensajeError[], float* num1, float maximo, float minimo)
{
	float num;


	if(num1!=NULL)
	{
	printf("%s",mensaje);
	scanf("%f",&num);

	while(num>maximo || num<minimo)
		{
			printf("%s",mensajeError);
			scanf("%f",&num);
		}
	*num1=num;


	}

}

int sumarCostosMantenimiento(float costoHospedaje,float costoComida,float costoTransporte,float* resultado)
{
	int todoOk=0;

		if(resultado!=NULL)
		{
		*resultado= costoHospedaje + costoComida + costoTransporte;
		todoOk=1;
		}

	return todoOk;
}


int calcularPromedioMercados(float* pPromAsia,int contadorAsia,float* pPromAfrica,int contadorAfrica,float* pPromNorte,int contadorNorte,float* pPromSud,int contadorSudamerica,float* pPromOceania,int contadorOceania,float* pPromEuropa,int contadorEuropa,int contadorJugadores)
{
	int todoOk=0;

	if(pPromAsia!=NULL && pPromAfrica!=NULL && pPromNorte!=NULL && pPromSud!=NULL && pPromOceania!=NULL && pPromEuropa!=NULL)
	{


	*pPromAsia=(float)contadorAsia/contadorJugadores;
	*pPromAfrica= (float)contadorAfrica/contadorJugadores;
	*pPromNorte= (float)contadorNorte/contadorJugadores;
	*pPromSud= (float)contadorSudamerica/contadorJugadores;
	*pPromOceania= (float)contadorOceania/contadorJugadores;
	*pPromEuropa= (float)contadorEuropa/contadorJugadores;
	todoOk=1;
	}
	return todoOk;
}



int aumentoEuropa(int cAsia,int cAfrica,int cNorte,int cSud,int cOceania,int cEuropa,float costoMantenimiento,float* aumento,float* resultadoFinal)
{
	int salioBien=0;
	int aum;
	if(aumento!= NULL && resultadoFinal!=NULL)
	{
		if(cEuropa>cAsia && cEuropa>cAfrica && cEuropa>cNorte && cEuropa>cSud && cEuropa>cOceania)
		{
			aum= (costoMantenimiento * 35)/100;
			*aumento=aum;
			*resultadoFinal= costoMantenimiento + aum;
			salioBien=1;
		}
	}

	return salioBien;
}



void validarOk_Int(int numIng,char mensaje[],char mensajeError[])
{
	if(numIng==1)
		{
			printf("%s\n",mensaje);
		}
	else
		{
			printf("%s\n",mensajeError);
		}
}


int validarUnoDos(int banderaHospedaje,int banderaComida,int banderaTransporte,int contadorJugadores)
{
    int todoOk=0;

    				if((banderaHospedaje==0 || banderaComida==0 || banderaTransporte==0) && contadorJugadores>0)
					{
	                    printf("Primero debe ingresar todos los costos de mantenimiento\n");
					}
					else
	                {
	                    if((banderaHospedaje==1 || banderaComida==1 || banderaTransporte==1) && contadorJugadores==0)
	                    {
	                        printf("Primero debe ingresar al menos un jugador\n");
	                    }
	                    else
	                    {
	                        if((banderaHospedaje==0 || banderaComida==0 || banderaTransporte==0) && contadorJugadores==0)
	                        {
	                            printf("Debe ingresar el punto 1 y 2 para acceder al 3\n");
	                        }
	                        else
	                        {
                                todoOk=1;
	                        }
	                    }
	                }
	            return todoOk;
}


void PedirNumero_Int(char mensaje[],char mensajeError[], int* num1, int maximo, int minimo)
{
	int num;


	if(num1!=NULL)
	{
	printf("%s",mensaje);
	scanf("%d",&num);

	while(num>maximo || num<minimo)
		{
			printf("%s",mensajeError);
			scanf("%d",&num);
		}
	*num1=num;
	}

}

