/*
 * Passenger.c
 *
 *  Created on: 8 jun. 2022
 *      Author: Laura
 */

#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* nuevoPassenger = (Passenger*) calloc(1,sizeof(Passenger));
	return nuevoPassenger;
}

Passenger* Passenger_newParametros(char* id,char* nombre,char* apellido,char* precio,char* tipoPasajero,char* codVuelo,char* estadoVuelo)
{
	Passenger* nuevoPassenger = Passenger_new();
	int auxId;
	float auxPrecio;
	int auxTipoPasajero;
	int auxEstVuelo;

	auxId = atoi(id);
	auxPrecio = atof(precio);
	auxTipoPasajero = atoi(tipoPasajero);
	auxEstVuelo = atoi(estadoVuelo);

	if(nuevoPassenger != NULL && nombre != NULL && apellido != NULL && precio != NULL && tipoPasajero != NULL && codVuelo != NULL && estadoVuelo != NULL)
	{
				Passenger_setId(nuevoPassenger,auxId);
				Passenger_setNombre(nuevoPassenger,nombre);
				Passenger_setApellido(nuevoPassenger,apellido);
				Passenger_setPrecio(nuevoPassenger,auxPrecio);
				Passenger_setTipoPasajero(nuevoPassenger,auxTipoPasajero);
				Passenger_setCodigoVuelo(nuevoPassenger,codVuelo);
				Passenger_setEstadoVuelo(nuevoPassenger,auxEstVuelo);

			//Passenger_delete(nuevoPassenger);
			//nuevoPassenger = NULL;
	}

	return nuevoPassenger;
}

void Passenger_delete(Passenger* passenger)
{
	free(passenger);
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = ERROR;

	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = OK;
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int* pId)
{
	int retorno = ERROR;

	if(this != NULL && pId != NULL)
	{
		*pId = this->id;
		retorno = OK;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = ERROR;

	if(this != NULL && nombre != NULL && strlen(nombre) < TAM_STRING && strlen(nombre) >= 2)
	{
		strcpy(this->nombre, nombre);
		strlwr(this->nombre);
		(this->nombre)[0] = toupper((this->nombre)[0]);
		retorno = OK;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = ERROR;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = OK;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = ERROR;

	if(this != NULL && apellido != NULL && strlen(apellido) < TAM_STRING && strlen(apellido) >= 2)
	{
		strcpy(this->apellido, apellido);
		strlwr(this->apellido);
		(this->apellido)[0] = toupper((this->apellido)[0]);
		retorno = OK;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = ERROR;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = OK;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = ERROR;

	if(this != NULL && codigoVuelo != NULL && strlen(codigoVuelo) <= TAM_FLYCODE)
	{
		strupr(codigoVuelo);
		strncpy(this->codigoVuelo,codigoVuelo,8);
		retorno = OK;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = ERROR;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = OK;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = ERROR;

	if(this != NULL && tipoPasajero >= MIN_TYPE && tipoPasajero <= MAX_TYPE)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = OK;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = ERROR;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = OK;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = ERROR;

	if(this != NULL && precio >= MIN_PRICE && precio <= MAX_PRICE)
	{
		this->precio = precio;
		retorno = OK;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = ERROR;

	if(this != NULL && precio != NULL )
	{
		*precio = this->precio;
		retorno = OK;
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo)
{
	int retorno = ERROR;

	if(this != NULL && estadoVuelo >= MIN_STATUS && estadoVuelo <= MAX_STATUS)
	{
		this->estadoVuelo = estadoVuelo;
		retorno = OK;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,int* pEstadoVuelo)
{
	int retorno = ERROR;

	if(this != NULL && pEstadoVuelo != NULL)
	{
		*pEstadoVuelo = this->estadoVuelo;
		retorno = OK;
	}
	return retorno;
}


