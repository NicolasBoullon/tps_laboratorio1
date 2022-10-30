/*
 * confederacion.c
 *
 *  Created on: 26 oct 2022
 *      Author: usuario
 */


#include "confederacion.h"
#include "validaciones.h"
void mostrarConfederacion(eConfederacion confederacion)
{

	printf("|  %d  |  %15s   |  %25s     |         %4d       |\n",
			confederacion.id,
			confederacion.nombre,
			confederacion.region,
			confederacion.anioCreacion);

}

int mostrarConfederaciones(eConfederacion confederaciones[],int tamC)
{
	int todoOk=0;
	int flag=1;
	if(confederaciones!= NULL && tamC>0)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("|    MENU CONFEDERACIONES    |\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("|  ID   |       NOMBRE       |           REGION               |    ANIO CREACION   |\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		for(int i=0;i<tamC;i++)
		{
			if(!confederaciones[i].isEmpty)
			{
				mostrarConfederacion(confederaciones[i]);
				todoOk=1;
				flag=0;
			}
		}
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		if(flag)
		{
			printf("No hay ninguna confederacion para mostrar!\n");
		}
	}
	return todoOk;
}


int hardcodearConfederaciones(int* pId,eConfederacion vec[], int tam, int cant)
{

    int todoOk = 0;

    eConfederacion almacenConfederaciones[] =
    {
        {100,"CONMEBOL","SUDAMEREICA",1916,0},
        {101,"UEFA","EUROPA",1954,0},
        {102,"AFC","ASIA",1954,0},
        {103,"CAF","AFRICA",1957,0},
        {104,"CONCACAF","NORTE Y CENTRO AMERICA",1961,0},
        {105,"OFC","OCEANIA",1966,0}
    };


    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {

        for(int i = 0 ; i < cant ; i++)
        {

            vec[i] = almacenConfederaciones[i];
            *pId = *pId + 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarConfederacion(eConfederacion confederaciones[],int tamC, int id,char descricpion[])
{
	int todoOk=0;
	if(confederaciones!=NULL && tamC>0 && descricpion!=NULL)
		{
			for(int i=0;i<tamC;i++)
			{
				if(!confederaciones[i].isEmpty && confederaciones[i].id==id)
				{
					strcpy(descricpion,confederaciones[i].nombre);
				}
			}
			todoOk=1;
		}

	return todoOk;
}


int iniciarIsEmptyConfederacion(eConfederacion confederaciones[],int tamC)
{
	int todoOk=0;
	if(confederaciones!=NULL && tamC)
	{
		for(int i=0;i<tamC;i++)
		{
			confederaciones[i].isEmpty=1;
		}
		todoOk=1;
	}
	return todoOk;
}

int buscarLugarLibreConfederacion(eConfederacion confederaciones[],int tamC)
{
	int indice=-1;
	if(confederaciones!=NULL && tamC)
	{
		for(int i=0;i<tamC;i++)
		{
			if(confederaciones[i].isEmpty)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int altaConfederacion(eConfederacion confederaciones[],int tamC, int* pId)
{
	int indice;
	int todoOk=0;
	eConfederacion auxConfederacion;

	if(confederaciones!= NULL && tamC>0)
	{
	system("cls");
	printf("   *** ALTA CONFEDERACION***\n");

	indice = buscarLugarLibreConfederacion(confederaciones, tamC);

		if(indice == -1)
		{
			printf("No hay lugar disponible para otra confederacion!\n");
		}
		else
		{
			auxConfederacion.id=*pId;
			(*pId)++;

//			printf("Ingrese nombre de confederacion: ");
//			gets(auxConfederacion.nombre);
			getString(auxConfederacion.nombre, "Ingrese nombre de confederacion: ", "ERROR.");

//			printf("Ingrese region de confederacion: ");
//			gets(auxConfederacion.region);
			getString(auxConfederacion.region, "Ingrese nombre de la region de confederacion: ", "ERROR.");

			utn_getInt(&auxConfederacion.anioCreacion, "Ingrese año de creacion de la confederacion: ", "ERROR.\n", 1000, 2022, 100);

			auxConfederacion.isEmpty=0;
			confederaciones[indice]=auxConfederacion;
			todoOk=1;
		}


	}
	return todoOk;
}


int bajaConfederacion(eConfederacion confederaciones[],int tamC)
{
	int todoOk=0;
	int opcion;
	char confirma;
	int indice;
	if(confederaciones!= NULL && tamC>0)
	{
		system("cls");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("|     BAJA CONFEDERACION    |\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


		mostrarConfederaciones(confederaciones, tamC);

		printf("Ingrese confederacion por ID: ");
		fflush(stdin);
		scanf("%d",&opcion);
		indice = buscarConfederacionId(confederaciones, tamC, opcion);

		if(indice == -1)
		{
			printf("No se encontro ninguna confederacion con ese ID!\n");
		}
		else
		{
			fflush(stdin);
			mostrarConfederacion(confederaciones[indice]);
			printf("Confirma Confederacion? (S/N) : ");
			fflush(stdin);
			scanf("%c",&confirma);
			confirma= toupper(confirma);
			if(confirma=='S')
			{
				confederaciones[indice].isEmpty=1;
				printf("Baja completada\n");
			}
			else if(confirma=='N')
			{
				printf("Baja cancelada!\n");
			}
				else
				{
					printf("ERROR. Opcion incorrecta distinta de :(S/N)\n"
							"Baja cancelada!\n");
				}
			}
		todoOk=1;
		}
	return todoOk;
}

int modificarConfederacion(eConfederacion confederaciones[],int tamC)
{
	int todoOk=0;
	int opcion;
	char confirma;
	int indice;
	if(confederaciones!= NULL && tamC>0)
	{
		system("cls");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("|     MODIFICACION CONFEDERACION    |\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		mostrarConfederaciones(confederaciones, tamC);
		printf("Ingrese confederacion por ID: ");
		fflush(stdin);
		scanf("%d",&opcion);

		indice=buscarConfederacionId(confederaciones, tamC, opcion);

		if(indice == -1)
		{
			printf("No se encontro a nadie con ese ID\n");
		}
		else
		{
			fflush(stdin);
			mostrarConfederacion(confederaciones[indice]);
			printf("Confirma Confederacion? (S/N) : ");
			fflush(stdin);
			scanf("%c",&confirma);

			confirma= toupper(confirma);
			if(confirma=='S')
			{
				fflush(stdin);
				switch(menuModificarConfederacion())
				{
				case 1:
					printf("Ingrese nuevo nombre de confederacion: ");
					fflush(stdin);
					gets(confederaciones[indice].nombre);
					break;

				case 2:
					printf("Ingrese nueva region de confederacion: ");
					fflush(stdin);
					gets(confederaciones[indice].region);
					break;

				case 3:
					fflush(stdin);
					utn_getInt(&confederaciones[indice].anioCreacion, "Ingrese nuevo anio de creacion: ","ERROR.", 1000, 2022, 100);
					break;

				case 4:
					printf("Volviendo...");
					break;
				}

			}
			else if(confirma=='N')
			{
				printf("Modificacion cancelada!\n");
			}
				else
				{
					printf("ERROR. Opcion incorrecta distinta de :(S/N)\n"
							"Modificacion cancelada!\n");
				}
			}
		todoOk=1;
	}

	return todoOk;
}


int buscarConfederacionId(eConfederacion confederaciones[],int tamC, int id)
{
	int indice=-1;


	if(confederaciones!=NULL && tamC>0)
	{
		for(int i=0;i<tamC;i++)
		{
			if(!confederaciones[i].isEmpty && confederaciones[i].id==id)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}
