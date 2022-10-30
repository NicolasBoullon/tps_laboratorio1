/*
 ============================================================================
 Name        : Proyectoprueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout,NULL);
	float costoHospedaje=0;
    float costoComida=0;
    float costoTransporte=0;

	int arqueros=0;
	int defensores=0;
	int mediocampistas=0;
	int delanteros=0;

	int contadorAsia=0;
	int contadorAfrica=0;
	int contadorNorte=0;
	int contadorSudamerica=0;
	int contadorOceania=0;
	int contadorEuropa=0;

	float promedioAsia;
	float promedioAfrica;
	float promedioNorte;
	float promedioSudamerica;
	float promedioOceania;
	float promedioEuropa;

	char jugador;

	int contadorJugadores=0;

	int pNumCamiseta;


	float valorAumento;
	float valorMantenimientoConAumento;

	int todoBienAumento;
	int todoOkDosTres;

	int banderaMenuTres=0;
	int banderaHospedaje=0;
	int banderaComida=0;
	int banderaTransporte=0;

	char opcionConfederacion;
	int todoOkPromedio=0;
	int nMenu;
	char nMenuMantenimiento;
	int okValidacion;
	float sumaMantenimiento;

	do{

	nMenu=MenuPrincipal(costoHospedaje,costoComida,costoTransporte,arqueros,defensores,mediocampistas,delanteros);

        switch(nMenu)
        {
        case 1:

        	do{
	        	//nMenuMantenimiento
        		nMenuMantenimiento=SubMenuMantenimiento(costoHospedaje,costoComida,costoTransporte);
        	switch(nMenuMantenimiento)
				{
				case 'a':
					system("cls");
					fflush(stdin);
					PedirNumero_Float("Ingrese costo de hospedaje: $","Ingrese un costo valido: $",&costoHospedaje,1000000,1000);
					banderaHospedaje=1;
					break;

				case 'b':
					system("cls");
					fflush(stdin);
					PedirNumero_Float("Ingrese costo de comida: $","Ingrese un costo valido: $",&costoComida,1000000,1000);
					banderaComida=1;
					break;

				case 'c':
					system("cls");
					fflush(stdin);
					PedirNumero_Float("Ingrese costo de transporte: $","Ingrese un costo valido: $",&costoTransporte,1000000,1000);
					banderaTransporte=1;
					break;

				case 'd':
					system("cls");
					break;
				}
        	}while(nMenuMantenimiento!='d');
        break;//break case 1

        case 2:
        	do{
        	  jugador=SubMenuCargaJugadores(arqueros,defensores,mediocampistas,delanteros);

        	  switch(jugador)
        	  {
        	  	  	  case 'a':
        	  		  system("cls");
        	  		  //pedircamiseta
        	  		  if(arqueros<2)
        	  		  {
						  PedirNumero_Int("Ingrese numero de camiseta: ","Ingrese un numero valido: ",&pNumCamiseta, 99,  1);

						  opcionConfederacion=SubMenuConfederacion();

						  contadorConfederacion(&contadorAsia,contadorAsia,&contadorAfrica,contadorAfrica,&contadorNorte,contadorNorte,&contadorSudamerica,contadorSudamerica,&contadorOceania,contadorOceania,&contadorEuropa,contadorEuropa,opcionConfederacion,&contadorJugadores,contadorJugadores);

						  arqueros++;

        	  		  }
        	  		  else
        	  		  {
        	  			  printf("Ya se ingresaron la cantidad maxima de arqueros\n");
        	  		  }
        	  		  break;

        	  	  	  case 'b':
        	  		  system("cls");
        	  		  if(defensores<8)
        	  		  {
						  PedirNumero_Int("Ingrese numero de camiseta: ","Ingrese un numero valido: ",&pNumCamiseta, 99,  1);

						  opcionConfederacion=SubMenuConfederacion();

						  contadorConfederacion(&contadorAsia,contadorAsia,&contadorAfrica,contadorAfrica,&contadorNorte,contadorNorte,&contadorSudamerica,contadorSudamerica,&contadorOceania,contadorOceania,&contadorEuropa,contadorEuropa,opcionConfederacion,&contadorJugadores,contadorJugadores);
						  defensores++;

        	  		  }
        	  		  else{
        	  			  printf("Ya se ingresaron la cantidad maxima de defensores\n");
        	  		  }
        	  		  break;

        	  	  	  case 'c':
        	  		  system("cls");
        	  		  if(mediocampistas<8)
        	  		  {
						  PedirNumero_Int("Ingrese numero de camiseta: ","Ingrese un numero valido: ",&pNumCamiseta, 99,  1);

						  opcionConfederacion=SubMenuConfederacion();

						  contadorConfederacion(&contadorAsia,contadorAsia,&contadorAfrica,contadorAfrica,&contadorNorte,contadorNorte,&contadorSudamerica,contadorSudamerica,&contadorOceania,contadorOceania,&contadorEuropa,contadorEuropa,opcionConfederacion,&contadorJugadores,contadorJugadores);
						  mediocampistas++;
        	  		  }
        	  		  else{
        	  			printf("Ya se ingresaron la cantidad maxima de mediocampistas\n");
        	  		  }
        	  		  break;

        	  	  	  case 'd':
        	  		  system("cls");
        	  		  if(delanteros<4)
        	  		  {
						  PedirNumero_Int("Ingrese numero de camiseta: ","Ingrese un numero valido: ",&pNumCamiseta, 99,  1);

						  opcionConfederacion=SubMenuConfederacion();

						  contadorConfederacion(&contadorAsia,contadorAsia,&contadorAfrica,contadorAfrica,&contadorNorte,contadorNorte,&contadorSudamerica,contadorSudamerica,&contadorOceania,contadorOceania,&contadorEuropa,contadorEuropa,opcionConfederacion,&contadorJugadores,contadorJugadores);
						  delanteros++;
        	  		  }
        	  		  else
        	  		  {
        	  			printf("Ya se ingresaron la cantidad maxima de delanteros\n");
        	  		  }
        	  		  break;

        	  	  	  case 'e':
        	  	  	  system("cls");
        	  	  	  break;
        	  	  }

        	}while(jugador!='e');

			break;//break case  2


			case 3:
					todoOkDosTres=validarUnoDos(banderaHospedaje,banderaComida,banderaTransporte,contadorJugadores);
					if(todoOkDosTres==1)
					{
					okValidacion=sumarCostosMantenimiento( costoHospedaje, costoComida, costoTransporte, &sumaMantenimiento);
					validarOk_Int(okValidacion,"La suma de los costos de mantenimiento resulto con exito\n","Hubo un error durante la operacion suma de los costos de mantenimiento\n");

					todoOkPromedio=calcularPromedioMercados(&promedioAsia,contadorAsia,&promedioAfrica,contadorAfrica,&promedioNorte,contadorNorte,&promedioSudamerica,contadorSudamerica,&promedioOceania,contadorOceania,&promedioEuropa,contadorEuropa,contadorJugadores);
					validarOk_Int(todoOkPromedio,"Los promedios se han calculado con exito\n","Hubo un error durante la operacion del promedio\n");

					todoBienAumento=aumentoEuropa(contadorAsia,contadorAfrica,contadorNorte,contadorSudamerica,contadorOceania,contadorEuropa,sumaMantenimiento,&valorAumento,&valorMantenimientoConAumento);
					validarOk_Int(todoBienAumento,"El aumento se ha calculado con exito\n\n","No fue necesario un aumento\n\n");

					banderaMenuTres=1;

					}


				break;


			case 4:

					if(banderaMenuTres==1)
					{
						mostrarResultadosFinales(promedioAsia,promedioAfrica,promedioNorte,promedioSudamerica,promedioOceania,promedioEuropa,sumaMantenimiento,todoBienAumento,valorAumento,valorMantenimientoConAumento);
					}
					else
					{
						printf("Primero debe ingresar el punto 3\n");
					}

        }//break del switchMENU


    }while(nMenu!=5);

	return EXIT_SUCCESS;
}
