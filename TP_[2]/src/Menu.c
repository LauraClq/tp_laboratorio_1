/*
 * Menu.c
 *
 *  Created on: 28 may 2022
 *      Author: Laura
 */

#include "Menu.h"

int menuOpciones()
{
	int opcion;

	printf("  MENU DE OPCIONES\n\n");
	printf("1. ALTAS\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. INFORMAR\n");
	printf("5. ALTA FORZADA\n");
	printf("6. SALIR\n");
	Utn_GetInt(&opcion,"Ingrese una opcion: ","\nError,dato invalido ingrese de 1 a 6.\n",MIN_OPTION,MAX_OPTION,ATTEMPTS);

	return opcion;
}

int menuModificar()
{
	int opcion;
	printf("\n MENU PARA MODIFICAR\n\n");
	printf("1. NOMBRE\n");
	printf("2. APELLIDO\n");
	printf("3. PRECIO\n");
	printf("4. TIPO DE PASAJERO\n");
	printf("5. CODIGO DE VUELO\n");
	printf("6. SALIR\n");
	Utn_GetInt(&opcion,"Ingrese una opcion: ","\nError,dato invalido ingrese de 1 a 6.\n",MIN_OPTION,MAX_OPTION,ATTEMPTS);

	return opcion;
}

int menuInformes()
{
	int opcion;
	printf("\n MENU DE INFORMES\n\n");
	printf("1. LISTAR PASAJEROS\n");
	printf("2. LISTA PASAJEROS ORDENADOS ALFABETICAMENTE POR APELLIDO Y TIPO DE PASAJERO\n");
	printf("3. TOTAL Y PROMEDIO DE LOS PRECIOS DE LOS PASAJES Y CUANTOS PASAJEROS SUPERAN EL PRECIO PROMEDIO\n");
	printf("4. LISTADO DE LOS PASAJEROS POR CODIGO DE VUELO Y ESTADOS DE VUELOS ACTIVO\n");
	printf("5. SALIR\n");
	Utn_GetInt(&opcion,"Ingrese una opcion: ","\nError,dato invalido ingrese de 1 a 4.\n",MIN_OPTION,MAX_OPTION_INFORM,ATTEMPTS);

	return opcion;
}
