/*
 * Menus.c
 *
 *  Created on: 18 jun 2022
 *      Author: laura
 */

#include "../inc/Menus.h"

int menu()
{
	int opcion;

	printf("********************************************************************************\n");
	printf("Menu:\n\n");
	printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf(" 2. Alta de empleados.\n");
	printf(" 3. Modificar datos de empleados.\n");
	printf(" 4. Baja de empleados.\n"); //podria usar el ll_pop si quiero elimiar por sector y ver cual es el precio mas alto y eliminarlo sort
	printf(" 5. Listar empleados.\n");
	printf(" 6. Crear una sublista.\n");
	printf(" 7. Limpiar lista.\n");
	printf(" 8. Ordenar empleados.\n");
	printf(" 9. Crear una copia.\n");
	printf(" 10. Reeemplazar un empleado\n");
	printf(" 11. Salir.\n\n");
	printf("********************************************************************************\n");

	if(Utn_GetInt(&opcion, "\nElija una opción : ","\nError,dato invalido ingrese de 1 a 11.\n", MIN_OPTION,MAX_OPTION,ATTEMPTS) == ERROR)
	{
		opcion = ERROR;
	}
	return opcion;
}

int menuModificar()
{
	int opcion;

	printf("******************************\n");
	printf("Menu de campos a modificar:\n\n");
	printf(" 1. Nombre.\n");
	printf(" 2. Apellido.\n");
	printf(" 3. Sueldo.\n");
	printf(" 4. Sector.\n");
	printf(" 5. Salir.\n\n");
	printf("******************************\n");

	if(Utn_GetInt(&opcion, "\nElija una opción : ","\nError,dato invalido ingrese de 1 a 10.\n", MIN_OPTION,MAX_OPTION_EDIT,ATTEMPTS) == ERROR)
	{
		opcion = ERROR;
	}
	return opcion;
}

int menuInformes()
{
	int opcion;

	printf("**********************************************\n");
	printf("Menu de informes:\n\n");
	printf(" 1. Ordenar por nombre.\n");
	printf(" 2. Ordenar por apellido.\n");
	printf(" 3. Ordenar por el Sueldo.\n");
	printf(" 4. Salir.\n\n");
	printf("***********************************************\n");

	if(Utn_GetInt(&opcion, "\nElija una opción : ","\nError,dato invalido ingrese de 1 a 10.\n", MIN_OPTION,MAX_OPTION_INFORM,ATTEMPTS) == ERROR)
	{
		opcion = ERROR;
	}
	return opcion;
}
