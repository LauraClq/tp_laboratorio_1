#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
 *****************************************************/



int main()
{
	setbuf(stdout, NULL);

	int opcion;
	char salir;
	int flagText = NADA;
	int flagBinary = NADA;
	int loadText = NADA;
	int loadBinary = NADA;

	LinkedList* listaPasajeros = ll_newLinkedList();
	do{
		opcion = menu();
		switch(opcion)
		{
		case 1:
			if(!flagText)
			{
				if(!controller_loadFromText("data.csv",listaPasajeros))
				{
					printf("Los pasajeros se cargaron con exito!\n\n");
					flagText = CARGO;
				}
				else
				{
					printf("Hubo un error al cargar los pasajeros.\n\n");
				}
			}
			else
			{
				printf("Ya se cargo el archivo de texto.\n");
			}
			break;
		case 2:
			if(!flagBinary)
			{
				if(!controller_loadFromBinary("dataB.bin",listaPasajeros))
				{
					printf("Los pasajeros se cargaron con exito!\n\n");
					flagBinary = CARGO;
				}
				else
				{
					printf("Hubo un error al cargar los pasajeros.\n\n");
				}
			}
			else
			{
				printf("Ya se cargo el archivo binario.\n");
			}
			break;
		case 3:
			if(!controller_addPassenger(listaPasajeros))
			{
				printf("El pasajero se dio de alta con exito!\n\n");

			}
			else
			{
				printf("Error al dar de alta un pasajero.\n\n");
			}
			break;
		case 4:
			if(!controller_editPassenger(listaPasajeros))
			{
				printf("El pasajero se modifico con exito!\n\n");
			}
			else
			{
				printf("Error al modificar un pasajero.\n\n");
			}
			break;
		case 5:
			if(!controller_removePassenger(listaPasajeros))
			{
				printf("El pasajero se elimino con exito!\n\n");
			}
			else
			{
				printf("Error al eleminar un pasajero.\n\n");
			}
			break;
		case 6://flagAlta
			if(controller_ListPassenger(listaPasajeros) == ERROR)
			{
				printf("Error al mostrar pasajeros.\n\n");
			}
			break;
		case 7://flagAlta
			if(!controller_sortPassenger(listaPasajeros))
			{
				controller_ListPassenger(listaPasajeros);
			}
			else
			{
				printf("Error al ordenar la lista de pasajeros.\n\n");
			}
			break;
		case 8:
			if(flagText)
			{
				if(!loadText)
				{
					if(!controller_saveAsText("data.csv",listaPasajeros))
					{
						printf("El archivo de texto se guardo con exito!\n");
						loadText = CARGO;
					}
					else
					{
						printf("Error al guardar el archivo.\n\n");
					}
				}
				else
				{
					printf("Ya se guardo el archivo de texto.\n");
				}

			}
			else
			{
				printf("Para guardar primero el archivo de texto.\n");
			}
			break;
		case 9:
			if(flagBinary)
			{
				if(!loadBinary)
				{
					if(!controller_saveAsBinary("dataB.bin",listaPasajeros))
					{
						printf("Los pasajeros se guardaron con exito!\n");
						loadBinary = CARGO;
					}
					else
					{
						printf("Error al guardar los pasajeros.\n\n");
					}
				}
				else
				{
					printf("Ya se guardo el archivo binario.\n");
				}

			}
			else
			{
				printf("Para guardar primero cargar el archivo binario.\n");
			}
			break;
		case 10:
			if(loadText || loadBinary)
			{
				salir = confirmacion("Desea salir del programa? s - n: ");
				if(salir == 's')
				{
					printf("Salida exitosa.\n");
					ll_deleteLinkedList(listaPasajeros);
				}
			}
			else
			{
				printf("Para salir del programa primero hay que guardar el archivo binario o de texto.\n");
			}
			break;
		}
	}while(salir != 's');

	return 0;
}

