/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Laura
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "ArrayTypePassenger.h"
#include "Menu.h"
#include "Defines.h"
#include "Informes.h"

int main(void) {

	setbuf(stdout, NULL);

	Passenger aPassengers[ELEMENTS];
	Passenger auxPassgers;

	TypePassenger aTypePass[LEN_TYPE] =
	{
			{1,"First Class"},
			{2,"Business Class"},
			{3,"Economy Class"},
			{4,"Premium Economy"}
	};

	int ingreso = NADA;
	int id = 100;
	char salir;
	int opcion;
	int validAdd;
	int validModify;
	int validRemove;

	initPassengers(aPassengers,ELEMENTS);

	do{
		opcion = menuOpciones();

		switch(opcion)
		{
		case 1:
			ingreso = ALTA;
			if(loadPassengers(&auxPassgers,&id,aTypePass,LEN_TYPE) == OK)
			{
				validAdd = addPassengers(aPassengers, ELEMENTS, auxPassgers.id, auxPassgers.name, auxPassgers.lastName, auxPassgers.price, auxPassgers.typePassenger, auxPassgers.flycode, auxPassgers.statusFlight); // @suppress("Field cannot be resolved")
				if(!validAdd)
				{
					printf("ALTA EXITOSA!!\n");
				}
				else
				{
					printf("Ocurrio un error en dar de alta\n");
				}
			}
			else
			{
				printf("Error en la carga de datos\n");
			}
			break;
		case 2:
			if(ingreso)
			{
				validModify = modifyPassenger(aPassengers,ELEMENTS,aTypePass,LEN_TYPE);
				if(!validModify)
				{
					printf("MODIFICACION EXITOSA!!\n");
				}
				else if(validModify)
				{
					printf("Modificacion cancelada\n");
				}
				else
				{
					printf("Ocurrio un error en los parametros\n");
				}
			}
			else
			{
				printf("Para modificar primero dar de alta\n");
			}
			break;
		case 3:
			if(ingreso)
			{
				validRemove = removePassengerById(aPassengers,ELEMENTS,aTypePass,LEN_TYPE);
				if(!validRemove)
				{
					printf("BAJA EXITOSA!!\n");
				}
				else if(validRemove == ERROR)
				{
					printf("Error en los parametros\n");
				}
			}
			else
			{
				printf("Para dar de baja primero dar de alta\n");
			}
			break;
		case 4:
			if(ingreso)
			{
				informesGenerales(aPassengers,ELEMENTS,aTypePass,LEN_TYPE);
			}
			else
			{
				printf("Para informar primero dar de alta\n");
			}
			break;
		case 5:
			if(!altaForzadaPassengers(aPassengers,ELEMENTS,&id))
			{
				printf("ALTA FORZADA EXITOSA!!\n");
				printPassengers(aPassengers,ELEMENTS,aTypePass,LEN_TYPE);
			}
			break;
		case 6:
			salir = confirmacion("Desea salir del programa? s - n: ");
			if(salir == 's')
			{
				printf("SALIDA EXITOSA");
			}
			break;
		default:
			printf("Opcion invalida\n");
			break;
		}
		printf("\n\n\n\n");

	}while(salir != 's');

	return 0;
}
