/*
 * Menu.c
 *
 *  Created on: 16 abr 2022
 *      Author: laura
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Menu.h"

int menuOpciones(float km, float y, float z)
{
	int opcion;

	    printf("Menu de Opciones: \n");
	    printf("1. Ingresar Kilometros: (km = %.2f)\n",km);
	    printf("2. Ingresar precios de vuelos: (Aerolineas = %.2f, Latam = %.2f)\n",y,z);
	    printf("3. Calcular todos los costos: \n");
	    printf("4. Informar resultados \n");
	    printf("5. Carga forzada de datos \n");
	    printf("6. Salir\n");

	    printf("Ingresar una opcion: ");
	    fflush(stdin);
	    scanf("%d", &opcion);

	    return opcion;
}

int ingresoKilometros(float* pKm)
{
	int todoBien = 0;
	float kilometros;

	if( pKm != NULL)
	{
		printf("Ingrese los kilometros: ");
		scanf("%f",&kilometros);

		while( kilometros <= 100 || kilometros >= 7500)
		{
			printf("Error.Intentelo de nuevo\n");
			printf("\nIngrese los kilometros mayor a 100 y menor a 7500: ");
		    scanf("%f",&kilometros);
		}
		*pKm = kilometros;
		todoBien = 1;
	}

	return todoBien;
}

int ingresoPrecio(float* pPrecio, char mensaje[])
{
	int todoBien = 0 ;
	float precio;

	if( pPrecio != NULL)
	{
		printf("%s",mensaje);
		scanf("%f",&precio);

		while( precio <= 1000 || precio >= 170000)
		{
		     printf("Error. Intentelo de nuevo\n");
		     printf("\nIngrese el precio de vuelo tiene que ser mayor a 1000 y menor a 170000: ");
		     scanf("%f",&precio);
		}
		*pPrecio = precio;
		todoBien = 1;
	}

	return todoBien;
}

int salida(char* pConfirma, char mensaje[])
{
	int todoBien = 0;
	char salida;

	if( pConfirma != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
	    scanf("%c",&salida);
		salida = tolower(salida);

		*pConfirma = salida;
		todoBien = 1;
	}

	return todoBien;
}

