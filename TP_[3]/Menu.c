/*
 * Menu.c
 *
 *  Created on: 6 jun 2022
 *      Author: laura
 */
#include "Menu.h"

int menu()
{
	int opcion;

	printf("********************************************************************************\n");
	printf("Menu:\n\n");
	printf(" 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
	printf(" 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
	printf(" 3. Alta de pasajero.\n");
	printf(" 4. Modificar datos de pasajero.\n");
	printf(" 5. Baja de pasajero.\n");
	printf(" 6. Listar pasajeros.\n");
	printf(" 7. Ordenar pasajeros.\n");
	printf(" 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
	printf(" 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
	printf(" 10. Salir.\n\n");
	printf("********************************************************************************\n");

	if(Utn_GetInt(&opcion, "\nElija una opción : ","\nError,dato invalido ingrese de 1 a 10.\n", MIN_OPTION,MAX_OPTION,ATTEMPTS) == ERROR)
	{
		opcion = ERROR;
	}
	return opcion;
}

int menuEdit()
{
	int opcion;

	printf("***************************\n");
	printf("MENU PARA MODIFICAR:\n\n");
	printf("1. NOMBRE\n");
	printf("2. APELLIDO\n");
	printf("3. PRECIO\n");
	printf("4. TIPO DE PASAJERO\n");
	printf("5. CODIGO DE VUELO\n");
	printf("6. ESTADO DE VUELO\n");
	printf("7. SALIR\n\n");
	printf("***************************\n");

	if(Utn_GetInt(&opcion,"Ingrese una opcion: ","\nError,dato invalido ingrese de 1 a 7.\n",MIN_OPTION,MAX_OPTION_EDIT,ATTEMPTS))
	{
		opcion = ERROR;
	}

	return opcion;
}

int menuSort()
{
	int opcion;

	printf("**************************************************************************************************\n");
	printf("MENU DE INFORMES:\n\n");
	printf("1. LISTA PASAJEROS ORDENADOS ALFABETICAMENTE POR NOMBRE\n");
	printf("2. LISTA PASAJEROS ORDENADOS ALFABETICAMENTE POR APELLIDO\n");
	printf("3. LISTA PASAJEROS ORDENADOS POR PRECIO\n");
	printf("**************************************************************************************************\n");

	if(Utn_GetInt(&opcion,"Ingrese una opcion: ","\nError,dato invalido ingrese de 1 a 7.\n",MIN_OPTION,MAX_OPTION_INFORM,ATTEMPTS))
	{
		opcion = ERROR;
	}

	return opcion;
}
