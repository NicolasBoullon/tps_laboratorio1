#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "menu.h"

//int menuPrincipal();
int main()
{
	setbuf(stdout,NULL);
    char option = 'n';
    int banderaOnce=0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* auxListaJugadores = ll_newLinkedList();
//	LinkedList* auxListaSelecciones = ll_newLinkedList();

//    puts("funciona ok");

    do{

        switch(menuPrincipal())
        {
            case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            	controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones);
                break;

			case 2:
				if(ll_isEmpty(listaJugadores))
				{
					printf("Primero debe dar de alta un jugador!\n");
				}
				else
				{
					if(controller_agregarJugador(listaJugadores))
					{
						printf("Jugador Agregado con Exito!\n");
					}
					else
					{
						printf("Hubo un error en la carga del jugador!\n");
					}
				}
				break;
			case 3:
				if(ll_isEmpty(listaJugadores))
				{
					printf("Primero debe dar de alta un jugador!\n");
				}
				else
				{
					if(controller_editarJugador(listaJugadores))
					{
						printf("Modificacion Completada con Exito!\n");
					}
					else
					{
						printf("Hubo un error en la modficacion del jugador!\n");
					}
				}
				break;

			case 4:
				if(ll_isEmpty(listaJugadores))
				{
					printf("Primero debe dar de alta un jugador!\n");
				}
				else
				{
				controller_removerJugador(listaJugadores,listaSelecciones);
				}
				break;

			case 5:
				if(ll_isEmpty(listaJugadores))
				{
					printf("Primero debe dar de alta un jugador!\n");
				}
				else
				{//------
					switch(menuListados())
					{
					case 1:
						controller_listarJugadores(listaJugadores);
						break;

					case 2:
						controller_listarSelecciones(listaSelecciones);
						break;

					case 3:
						controller_listarJugadoresConvocados(listaJugadores);
						break;
					case 4:
						printf("Volviendo...");
						break;
					}
				}
				break;

			case 6:
				if(ll_isEmpty(listaJugadores))
				{
					printf("Primero debe dar de alta un jugador!\n");
				}
				else
				{//------
					switch(menuConvocar())
					{
					fflush(stdin);
					case 1:
						controller_convocarJugador(listaJugadores, listaSelecciones);
						break;

					case 2:
						controller_quitarJugador(listaJugadores, listaSelecciones);
						break;
					}
				}
				break;

			case 7:
				if(ll_isEmpty(listaJugadores))
				{
					printf("Primero debe dar de alta un jugador!\n");
				}
				else
				{//------
				controller_ordenarJugadores(listaJugadores,listaSelecciones);
				}
				break;

			case 8:
				if(ll_isEmpty(listaJugadores))
				{
					printf("Primero debe dar de alta un jugador!\n");
				}
				else
				{//------
					banderaOnce=-1;
//					controller_cargarJugadoresDesdeBinario("auxJugadores.csv", auxListaJugadores);
					nuevaListaBinarioPorConfederacion(listaJugadores, listaSelecciones, auxListaJugadores);
					controller_guardarJugadoresModoBinario("listaJugadoresBinarios.bin", auxListaJugadores);
//					controller_listarJugadores(auxListaJugadores);
				}

				break;

			case 9:
				if(ll_isEmpty(listaJugadores))
				{
					printf("Primero debe dar de alta un jugador!\n");
				}
				else
				{//------
					controller_cargarJugadoresDesdeBinario("listaJugadoresBinarios.bin", auxListaJugadores);
					controller_listarJugadores(auxListaJugadores);
//					printf("entro toda\n");
				}

				break;

			case 10:
				if(ll_isEmpty(listaJugadores))
				{
					printf("Primero debe dar de alta un jugador!\n");
				}
				else
				{//------
					banderaOnce=1;
					controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
					controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones);
				}
				break;

			case 11:
				if(banderaOnce==0)
				{
					fflush(stdin);
					option=confirmaSalir();
				}
				else if(banderaOnce== -1)
				{
//					printf("Todavia no ha entrado al punto 10 para guardar los cambios")
					option=confirmaSiNo("Todavia no se ha ingresado al punto 10 para guardar los cambios, desea salir de todas formas? ","ERROR.");
				}
				else
				{
					fflush(stdin);
					confirmaSalir();
				}

				break;
        }
    }while(option =='n');
//	Jugador* j= jug_newParametros("500", "nicolas cArlos", "20", "delantero", "argentino", "4");

//	mostrarPersona(j);
    return 0;
}


