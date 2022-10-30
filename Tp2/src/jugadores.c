/*
 * jugadores.c
 *
 *  Created on: 26 oct 2022
 *      Author: usuario
 */


#include "jugadores.h"
#include "validaciones.h"


int iniciarIsEmptyJugadores(eJugador jugadores[],int tamJ)
{
	int todoOk=0;
	if(jugadores!=NULL && tamJ)
	{
		for(int i=0;i<tamJ;i++)
		{
			jugadores[i].isEmpty=1;
		}
		todoOk=1;
	}
	return todoOk;
}

int buscarLugarLibreJugador(eJugador jugadores[],int tamJ)
{
	int indice=-1;
	if(jugadores!=NULL && tamJ)
	{
		for(int i=0;i<tamJ;i++)
		{
			if(jugadores[i].isEmpty)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

void mostrarJugador(eJugador jugador, eConfederacion confederaciones[],int tamC)
{
	char descripcion[20];

		cargarConfederacion(confederaciones, tamC, jugador.idConfederacion, descripcion);

		printf("| %4d |  %15s   |  %15s     |   %2hd     |      %10.2f      |   %8s       |     %2hd      |\n",
				jugador.id,
				jugador.nombre,
				jugador.posicion,
				jugador.numeroCamiseta,
				jugador.salario,
				descripcion,
				jugador.anioContrato);

}

int mostrarJugadores(eJugador jugadores[],int tamJ,eConfederacion confederaciones[],int tamC)
{
	int todoOk=0;
	int flag=1;
	if(jugadores!=NULL && tamJ)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("|             MENU JUGADORES                  |\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("|  ID  |        NOMBRE      |       POSICION       | CAMISETA |        SALARIO        |  CONFEDERACION  |  CONTRATO   |\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


		for(int i=0;i<tamJ;i++)
		{
			if(!jugadores[i].isEmpty)
			{
			mostrarJugador(jugadores[i],confederaciones,tamC);
			flag=0;
			todoOk=1;
			}
		}
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		if(flag)
		{
			printf("No hay ningun jugador para mostrar!\n");
		}
	}
	return todoOk;
}


int hardcodearJugadores(int* pId,eJugador vec[], int tam, int cant)
{

    int todoOk = 0;

    eJugador almacenJugadores[] =
    {
        {3000,"Messi","DELANTERO",10,900000,101,3,0},
        {3001,"Paredes","MEDIOCAMPISTA",8,600000,102,4,0},
        {3002,"Dibu","ARQUERO",1,500000,102,5,0},
        {3003,"DiMaria","MEDIOCAMPISTA",7,700000,100,5,0},
        {3004,"Romero","DEFENSOR",6,550000,104,3,0},
        {3005,"Otamendi","DEFENSOR",2,500000,105,2,0},
        {3006,"Pezzella","DEFENSOR",5,380000,103, 5,0},
        {3007,"Martinez","DELANTERO",9,800000,105,6,0},
        {3008,"Tagliafico","DELANTERO",3,670000,105,3,0},
        {3009,"LoCelso","MEDIOCAMPISTA",11,600000,102,2,0}
    };


    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {
        for(int i = 0 ; i < cant ; i++)
        {

            vec[i] = almacenJugadores[i];
            *pId = *pId + 1;
        }
        todoOk = 1;
    }
    return todoOk;
}


int altaJugador(eJugador jugadores[],int tamJ,int* pId,eConfederacion confederaciones[],int tamC)
{
	int todoOk=0;
	int indice;
	eJugador auxJugador;
	int auxInt;

	if(jugadores!= NULL && tamJ>0&& confederaciones!= NULL && tamC >0)
	{
		system("cls");
		printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("|     ALTA JUGADOR    |\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~\n");

		indice= buscarLugarLibreJugador(jugadores, tamJ);

		if(indice == -1)
		{
			printf("No hay lugar para otro jugador!\n");
		}
		else
		{
			auxJugador.id=*pId;
			(*pId)++;

			getString(auxJugador.nombre, "Ingrese nombre de jugador: ", "ERROR.");



			switch(menuPosicion()){
			case 1:
				strcpy(auxJugador.posicion,"ARQUERO");
				break;
			case 2:
				strcpy(auxJugador.posicion,"DEFENSOR");
				break;
			case 3:
				strcpy(auxJugador.posicion,"MEDIOCAMPISTA");
				break;
			case 4:
				strcpy(auxJugador.posicion,"DELANTERO");
				break;
			}

			utn_getShort(&auxJugador.numeroCamiseta, "Ingrese numero de camiseta (1/99) : ", "ERROR .\n", 1, 99, 100);

			mostrarConfederaciones(confederaciones, tamC);
			printf("Ingrese confederacion por ID: ");
			fflush(stdin);
			scanf("%d",&auxInt);
			while(!validarIdConfederacion(auxInt, confederaciones, tamC))
			{
				printf("ID Invalido. Reingrese ID: ");
				fflush(stdin);
				scanf("%d",&auxInt);
			}
			auxJugador.idConfederacion=auxInt;

			fflush(stdin);
			utn_getFloat(&auxJugador.salario, "Ingrese salario: ", "ERROR .\n", 1000, 100000000, 100);


			utn_getShort(&auxJugador.anioContrato, "Ingrese  años de contrato (1/5): ", "ERROR. \n ", 1, 5, 100);

			auxJugador.isEmpty=0;
			jugadores[indice]=auxJugador;
			todoOk=1;
		}


	}
	return todoOk;
}



int bajaJugador(eJugador jugadores[],int tamJ,eConfederacion confederaciones[],int tamC)
{
	 int todoOk=0;
	 int opcion;
	 int indice;
	 char confirma;

		if(jugadores!= NULL && tamJ>0&& confederaciones!= NULL && tamC >0)
		{

			system("cls");
			printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("|     BAJA JUGADOR    |\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~\n");

			if(mostrarJugadores(jugadores, tamJ,confederaciones,tamC))
			{
			printf("Ingrese ID de jugador: ");
			scanf("%d",&opcion);

			indice = buscarJugadorId(jugadores, tamJ, opcion);

			if(indice == -1)
			{
				printf("No hay ningun jugador con ese ID!\n");
			}
			else
			{
				mostrarJugador(jugadores[indice],confederaciones,tamC);
				printf("Confirma Baja? (S/N): ");

				fflush(stdin);
				scanf("%c",&confirma);
				confirma= toupper(confirma);
				if(confirma=='S')
				{
					jugadores[indice].isEmpty=1;
					printf("Baja con exito!\n");
					todoOk=1;
				}
				else if(confirma=='N')
				{
					printf("Baja cancelada!\n");
				}
					else
					{
					printf("ERROR. Opcion incorrecta distinta de (S/N)\n"
							"Baja cancelada!\n");
					}
				}
			}
		}
	 return todoOk;
}






int buscarJugadorId(eJugador jugadores[],int tam, int id)
{
	int indice=-1;


	if(jugadores!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(!jugadores[i].isEmpty && jugadores[i].id==id)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}


int modificarJugador(eJugador jugadores[],int tamJ,eConfederacion confederaciones[],int tamC)
{
int todoOk=0;
int opcion;
int indice;
char confirma;
int auxInt;


	if(jugadores!= NULL && tamJ>0&& confederaciones!= NULL && tamC >0)
	{

		system("cls");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("|     MODIFICACION JUGADOR    |\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		if(mostrarJugadores(jugadores, tamJ,confederaciones,tamC))
		{



		printf("Ingrese ID de jugador: ");
		scanf("%d",&opcion);

		indice = buscarJugadorId(jugadores, tamJ, opcion);

		if(indice == -1)
		{
			printf("No hay ningun jugador con ese ID!\n");
		}
		else
		{
			mostrarJugador(jugadores[indice],confederaciones,tamC);
			printf("Confirma Jugador? (S/N) : ");
			fflush(stdin);
			scanf("%c",&confirma);
			confirma= toupper(confirma);
			if(confirma=='S')
			{
				fflush(stdin);
				switch(menuModificar())
				{

				case 1:
//					printf("Ingrese nuevo nombre de jugador: ");
//					fflush(stdin);
//					gets(jugadores[indice].nombre);
					getString(jugadores[indice].nombre, "Reingrese nombre de jugador: ", "ERROR.");
					break;

				case 2:
					printf("Ingrese nueva posicion por ID\n");
					switch(menuPosicion())
					{
					case 1:
						strcpy(jugadores[indice].posicion,"ARQUERO");
						break;
					case 2:
						strcpy(jugadores[indice].posicion,"DEFENSOR");
						break;
					case 3:
						strcpy(jugadores[indice].posicion,"MEDIOCAMPISTA");
						break;
					case 4:
						strcpy(jugadores[indice].posicion,"DELANTERO");
						break;
					}
					break;

					case 3:

						utn_getShort(&jugadores[indice].numeroCamiseta, "Reingrese numero de camiseta (1/99): ", "ERROR. \n", 1, 99, 100);
					break;

					case 4:
						mostrarConfederaciones(confederaciones, tamC);
						printf("Ingrese Nueva confederacion por ID: ");
						scanf("%d",&auxInt);
						while(!validarIdConfederacion(auxInt, confederaciones, tamC))
						{
							printf("ID Invalido. Reingrese ID: ");
							fflush(stdin);
							scanf("%d",&auxInt);
						}
						jugadores[indice].idConfederacion=auxInt;
						break;

					case 5:

						utn_getFloat(&jugadores[indice].salario, "Ingrese Salario: ", "ERROR. \n", 1000, 10000000, 100);
						break;

					case 6:

						utn_getShort(&jugadores[indice].anioContrato, "Ingrese nuevos años de contrato(1/5) : ", "ERROR. \n", 1, 5, 100);
						break;

					case 7:
						printf("Volviendo...\n");
						break;
				}

			}
			else if(confirma=='N')
			{
				printf("Modificacion cancelada!\n");
			}
				else
				{
					printf("ERROR. Opcion incorrecta distinta de (S/N) :\n"
							"Modificacion cancelada!\n");
				}
			}
		}
	}
return todoOk;
}



int ordenarJugadoresId(eJugador jugadores[],int tamJ)
{
	eJugador auxJugador;
	int todoOk=0;
	if(jugadores!=NULL && tamJ>0)
	{
		for(int i=0;i<tamJ-1;i++)
		{
			for(int j=i+1;j<tamJ;j++)
			{
				if(!jugadores[i].isEmpty && jugadores[i].id>jugadores[j].id)
				{
					auxJugador=jugadores[i];
					jugadores[i]=jugadores[j];
					jugadores[j]=auxJugador;
				}
			}
		}
		todoOk=1;
	}
	return todoOk;
}

