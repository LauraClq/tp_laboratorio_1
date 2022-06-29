/*
 * RegisterPassengers.c
 *
 *  Created on: 8 jun 2022
 *      Author: laura
 */

#include "FunctionsPassengers.h"

int passenger_loadPassengers(char* nombre,char* apellido,float* precio,int* tipoPasajero,char* codVuelo,int* estadoVuelo)
{
	int retorno = ERROR;
	char auxNombre[TAM_STRING];
	char auxApellido[TAM_STRING];
	float auxPrecio;
	int auxTipoPass;
	char auxCodVuelo[TAM_FLYCODE];
	int auxEstVuelo;

	if(nombre != NULL && apellido != NULL && precio != NULL && tipoPasajero != NULL && estadoVuelo != NULL)
	{
		if( !(Utn_GetString(auxNombre,TAM_STRING,"Ingrese su nombre: ","\nError, dato invalido solo letras.\n",ATTEMPTS))&&
				!(Utn_GetString(auxApellido,TAM_STRING,"Ingrese su apellido: ","\nError, dato invalido solo letras.\n",ATTEMPTS)) &&
				!(Utn_GetFloat(&auxPrecio,"Ingrese el precio del vuelo (10000 - 50000): ","\nError, dato invalido solo numeros.\n",MIN_PRICE,MAX_PRICE,ATTEMPTS)) &&
				!(Utn_GetInt(&auxTipoPass,"\n1 FirstClass - 2 ExecutiveClass - 3 EconomyClass\nIngrese tipo de pasajero: ","\nError, dato invalido solo de (1 - 3).\n",MIN_TYPE,MAX_TYPE,ATTEMPTS)) &&
				!(Utn_GetStringAlphanumeric(auxCodVuelo,TAM_FLYCODE,"Ingrese el codigo de vuelo: ","\nError, dato invalido fuera del rango.\n",ATTEMPTS)) &&
				!(Utn_GetInt(&auxEstVuelo,"\n1 En Horario - 2 Aterrizado - 3 Demorado - 4 En Vuelo\nIngrese el estado de su vuelo: ","\nError, dato invalido solo de (1 - 4)\n",MIN_STATUS,MAX_STATUS,ATTEMPTS)))
		{
			strcpy(nombre,auxNombre);
			strcpy(apellido,auxApellido);
			*precio = auxPrecio;
			*tipoPasajero = auxTipoPass;
			strcpy(codVuelo,auxCodVuelo);
			*estadoVuelo = auxEstVuelo;
			retorno = OK;
		}
	}

	return retorno;
}

int passenger_settersAllPassenger(int id, char* nombre, char* apellido, float precio, int tipoPass, char* codVuelo, int estVuelo)
{
	int retorno = ERROR;
	Passenger* pPassenger = Passenger_new();

	if( !(Passenger_setId(pPassenger,id) && Passenger_setNombre(pPassenger,nombre) &&
			Passenger_setApellido(pPassenger,apellido) && Passenger_setPrecio(pPassenger,precio) &&
			Passenger_setTipoPasajero(pPassenger,tipoPass) && Passenger_setCodigoVuelo(pPassenger,codVuelo) &&
			Passenger_setEstadoVuelo(pPassenger,estVuelo) ))
	{
		retorno = OK;
	}
	else
	{
		Passenger_delete(pPassenger);
	}

	return retorno;
}

void passenger_printfPassenger(Passenger* onePassenger)
{
	int auxId;
	char auxNombre[TAM_STRING];
	char auxApellido[TAM_STRING];
	float auxPrecio;
	int auxTipoPass;
	char auxCodVuelo[10];
	int auxEstVuelo;

	char descripcionTipo[30];
	char descripcionEstVuelo[21];

	Passenger_getId(onePassenger, &auxId);
	Passenger_getNombre(onePassenger, auxNombre);
	Passenger_getApellido(onePassenger, auxApellido);
	Passenger_getPrecio(onePassenger, &auxPrecio);
	Passenger_getTipoPasajero(onePassenger, &auxTipoPass);
	Passenger_getCodigoVuelo(onePassenger, auxCodVuelo);
	Passenger_getEstadoVuelo(onePassenger, &auxEstVuelo);

	Passenger_getDescriptionType(auxTipoPass, descripcionTipo);
	Passenger_getDescriptionEstVuelo(auxEstVuelo, descripcionEstVuelo);

	printf(" | %-5d | %-12s | %-12s | %-8.2f | %-11s |  %-14s  |  %-10s  |\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodVuelo,descripcionTipo,descripcionEstVuelo);

}

int Passenger_getDescriptionType(int tipoPass, char* descripcion)
{
	int retorno = ERROR;

	if(descripcion != NULL)
	{
		switch(tipoPass)
		{
		case 1:
			strcpy(descripcion,"FirstClass");
			break;
		case 2:
			strcpy(descripcion,"ExecutiveClass");
			break;
		case 3:
			strcpy(descripcion,"EconomyClass");
			break;
		}
		retorno = OK;
	}

	return retorno;
}

int Passenger_getDescriptionEstVuelo(int estVuelo, char* descripcion)
{
	int retorno = ERROR;

	if(descripcion != NULL)
	{
		switch(estVuelo)
		{
		case 1:
			strcpy(descripcion,"En Horario");
			break;
		case 2:
			strcpy(descripcion,"Aterrizado");
			break;
		case 3:
			strcpy(descripcion,"Demorado");
			break;
		case 4:
			strcpy(descripcion,"En vuelo");
			break;
		}
		retorno = OK;
	}

	return retorno;
}


int Passenger_searchById(LinkedList* this, int id)
{
	int retorno = ERROR;
	Passenger* pPassenger;
	int len;
	int idAux;

	if(this != NULL && id > 0)
	{
		len = ll_len(this);

		for(int i=0; i<len; i++)
		{
			pPassenger = ll_get(this, i);

			if(!Passenger_getId(pPassenger,&idAux) && idAux == id)
			{
				retorno = i;
			}
		}
	}
	return retorno;
}

int Passenger_editById(Passenger* pPassenger)
{
	int retorno = ERROR;
	int opcion;
	char salir = 's';

	char auxNombre[TAM_STRING];
	char auxApellido[TAM_STRING];
	float auxPrecio;
	int auxTipoPass;
	char auxCodVuelo[TAM_FLYCODE];
	int auxEstVuelo;

	int valida;

	if(pPassenger != NULL)
	{
		do
		{
			opcion = menuEdit();
			switch(opcion)
			{
			case 1:
				valida = Utn_GetString(auxNombre,TAM_STRING,"Ingrese su nuevo nombre: ","\nError, dato invalido solo letras.\n",ATTEMPTS);
				if(!valida && !Passenger_setNombre(pPassenger,auxNombre))
				{
					retorno = OK;
				}
				break;
			case 2:
				valida = Utn_GetString(auxApellido,TAM_STRING,"Ingrese su nuevo apellido: ","\nError, dato invalido solo letras.\n",ATTEMPTS);
				if(!valida && !Passenger_setApellido(pPassenger,auxApellido))
				{
					retorno = OK;
				}
				break;
			case 3:
				valida = Utn_GetFloat(&auxPrecio,"Ingrese el nuevo precio: ","\nError.Dato invalido solo permite numeros (5000 - 20000).\n",MIN_PRICE,MAX_PRICE,ATTEMPTS);
				if(!valida && !Passenger_setPrecio(pPassenger,auxPrecio))
				{
					retorno = OK;
				}
				break;
			case 4:
				valida  = Utn_GetInt(&auxTipoPass,"1 First Class - 2 ExecutiveClass - 3 EconomyClass\nIngrese el nuevo tipo de pasajero: ","\nError. Dato invalido solo (1 - 3)\n",MIN_TYPE,MAX_TYPE,ATTEMPTS);
				if(!valida && !Passenger_setTipoPasajero(pPassenger,auxTipoPass))
				{
					retorno = OK;
				}
				break;
			case 5:
				valida  = Utn_GetString(auxCodVuelo,TAM_FLYCODE,"Ingrese el nuevo codigo de su vuelo: ","\nError. Dato invalido fuera del rango\n",ATTEMPTS);
				if(!valida && !Passenger_setCodigoVuelo(pPassenger,auxCodVuelo))
				{
					retorno = OK;
				}
				break;
			case 6:
				valida = Utn_GetInt(&auxEstVuelo,"1 En horario - 2 Aterrizado - 3 Demorado\nIgrese en nuevo estado de su vuelo: ","\nError. Dato invalido solo de 1 - 3\n",MIN_STATUS,MAX_STATUS,ATTEMPTS);
				if(!valida && !Passenger_setEstadoVuelo(pPassenger,auxEstVuelo))
				{
					retorno = OK;
				}
				break;
			case 7:
				salir = 's';
				retorno = OK;
				break;
			default:
				printf("Opcion incorrecta solo de 1 - 7\n");
				break;
			}

		}while(salir != 's' && retorno != OK);
	}

	return retorno;
}

int Passenger_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = ERROR;
	int order;

	if(pArrayListPassenger != NULL)
	{
		switch(menuSort())
		{
		case 1:
			Utn_GetInt(&order,"De que forma desea ordenar? Ingrese 1 (Ascendente) o 0 (Descendente): ","\nError.Dato invalido solo numeros.\n",SORT_DESC,SORT_ASC,ATTEMPTS);
			printf("Espero unos segundos, ordenando la lista....\n\n");
			ll_sort(pArrayListPassenger,Passenger_sortByNombre,order);
			controller_ListPassenger(pArrayListPassenger);
			retorno = OK;
			break;
		case 2:
			Utn_GetInt(&order,"De que forma desea ordenar? Ingrese 1 (Ascendente) o 0 (Descendente): ","\nError.Dato invalido solo numeros.\n",SORT_DESC,SORT_ASC,ATTEMPTS);
			printf("Espero unos segundos, ordenando la lista....\n\n");
			ll_sort(pArrayListPassenger,Passenger_sortByApellido,order);
			controller_ListPassenger(pArrayListPassenger);
			retorno = OK;
			break;
		case 3:
			Utn_GetInt(&order,"De que forma desea ordenar? Ingrese 1 (Ascendente) o 0 (Descendente): ","\nError.Dato invalido solo numeros.\n",SORT_DESC,SORT_ASC,ATTEMPTS);
			printf("Espero unos segundos, ordenando la lista....\n\n");
			ll_sort(pArrayListPassenger,Passenger_sortByPrecio,order);
			controller_ListPassenger(pArrayListPassenger);
			retorno = OK;
			break;
		default:
			printf("Ocpion invalida solo de 1- 4\n");
			break;
		}
	}

	return retorno;
}

int Passenger_sortByNombre(void* passengerA, void* passengerB)
{
	int retorno = ERROR;
	char auxNombreUno[TAM_STRING];
	char auxNombreDos[TAM_STRING];
	Passenger* passA;
	Passenger* passB;

	if(passengerA != NULL && passengerB != NULL)
	{
		passA = (Passenger*) passengerA;
		passB = (Passenger*) passengerB;

		if(!Passenger_getNombre(passA, auxNombreUno) && !Passenger_getNombre(passB,auxNombreDos))
		{
			retorno = strcmp(passA->nombre,passB->nombre);
		}
		passA = NULL;
		passB = NULL;
	}
	return retorno;
}

int Passenger_sortByApellido(void* passengerA, void* passengerB)
{
	int retorno = ERROR;
	char auxApellidoUno[TAM_STRING];
	char auxApellidoDos[TAM_STRING];
	Passenger* passA;
	Passenger* passB;

	if(passengerA != NULL && passengerB != NULL)
	{
		passA = (Passenger*) passengerA;
		passB = (Passenger*) passengerB;

		if(!Passenger_getApellido(passA,auxApellidoUno) && !Passenger_getApellido(passB,auxApellidoDos))
		{
			retorno = strcmp(passA->apellido,passB->apellido);
		}
		passA = NULL;
		passB = NULL;
	}
	return retorno;
}

int Passenger_sortByPrecio(void* passengerA, void* passengerB)
{
	int retorno = ERROR;
	float auxPrecioUno;
	float auxPrecioDos;
	Passenger* passA;
	Passenger* passB;


	if(passengerA != NULL && passengerB != NULL)
	{
		passA = (Passenger*) passengerA;
		passB = (Passenger*) passengerB;

		if(!Passenger_getPrecio(passA,&auxPrecioUno) && !Passenger_getPrecio(passB,&auxPrecioDos))
		{
			if(auxPrecioUno != auxPrecioDos && auxPrecioUno > auxPrecioDos)
			{
				retorno = SORT_ASC;
			}
			else if(auxPrecioUno != auxPrecioDos && auxPrecioUno < auxPrecioDos)
			{
				retorno = SORT_DESC;
			}
		}
	}
	return retorno;
}
