/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Defines.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	int estadoVuelo;

}Passenger;

/// @brief It is in charge of adding a new passenger and saving it in the dynamic memory, it is a constructor without parameters
///
/// @return Retorna el puntero del pasajero asignado en la memoria.
Passenger* Passenger_new();

/// @brief It is in charge of adding a new passenger and saving it in the dynamic memory.
///
/// @param id of type char
/// @param nombre of type char
/// @param apellido of type char
/// @param precio of type char
/// @param tipoPasajero of type char
/// @param codVuelo of type char
/// @param estadoVuelo of type char
/// @return the pointer of the passemger allocated in memory
Passenger* Passenger_newParametros(char* id,char* nombre,char* apellido,char* precio,char* tipoPasajero,char* codVuelo,char* estadoVuelo);

/// @brief removes a passenger from the list and frees the dynamic memory that was used for that passenger
///
/// @param passenger it is the passenger to be eliminated.
void Passenger_delete(Passenger* passenger);

/// @brief insert the id to the passenger list
///
/// @param this
/// @param id
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_setId(Passenger* this,int id);

/// @brief gets the passenger's id in the general list.
///
/// @param this
/// @param pId
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_getId(Passenger* this,int* pId);

/// @brief insert the name to the passenger list
///
/// @param this
/// @param nombre
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_setNombre(Passenger* this,char* nombre);

/// @brief gets the passenger's name in the general list.
///
/// @param this
/// @param nombre
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_getNombre(Passenger* this,char* nombre);

/// @brief insert the lastname to the passenger list
///
/// @param this
/// @param apellido
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_setApellido(Passenger* this,char* apellido);

/// @brief gets the passenger's lastname in the general list.
///
/// @param this
/// @param apellido
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_getApellido(Passenger* this,char* apellido);

/// @brief insert the flycode to the passenger list
///
/// @param this
/// @param codigoVuelo
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief gets the passenger's flycode in the general list.
///
/// @param this
/// @param codigoVuelo
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief insert the type passenger to the passenger list
///
/// @param this
/// @param tipoPasajero
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);

/// @brief gets the passenger's type passenger in the general list.
///
/// @param this
/// @param tipoPasajero
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/// @brief insert the price to the passenger list
///
/// @param this
/// @param precio
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_setPrecio(Passenger* this,float precio);

/// @brief gets the passenger's price in the general list.
///
/// @param this
/// @param precio
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_getPrecio(Passenger* this,float* precio);

/// @brief insert the status fly to the passenger list
///
/// @param this
/// @param estadoVuelo
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);

/// @brief gets the passenger's status fly in the general list.
///
/// @param this
/// @param pEstadoVuelo
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_getEstadoVuelo(Passenger* this,int* pEstadoVuelo);


#endif /* PASSENGER_H_ */
