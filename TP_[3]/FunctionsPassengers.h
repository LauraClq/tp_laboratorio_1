/*
 * RegisterPaassengers.h
 *
 *  Created on: 8 jun 2022
 *      Author: laura
 */

#ifndef FUNCTIONSPASSENGERS_H_
#define FUNCTIONSPASSENGERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "Controller.h"
#include "LinkedList.h"
#include "Menu.h"
#include "Defines.h"
#include "Input.h"

/// @brief uploads data to the passenger list
///
/// @param nombre
/// @param apellido
/// @param precio
/// @param tipoPasajero
/// @param codVuelo
/// @param estadoVuelo
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int passenger_loadPassengers(char* nombre,char* apellido,float* precio,int* tipoPasajero,char* codVuelo,int* estadoVuelo);

/// @brief edit a passenger according to id
///
/// @param pPassenger
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_editById(Passenger* pPassenger);

/// @brief get the description according to the entered number
///
/// @param tipoPass
/// @param descripcion
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_getDescriptionType(int tipoPass, char* descripcion);

/// @brief get the description according to the entered number
///
/// @param estVuelo
/// @param descripcion
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_getDescriptionEstVuelo(int estVuelo, char* descripcion);

/// @brief search for the entered id
///
/// @param this
/// @param id
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_searchById(LinkedList* this, int id);

/// @brief shows the list of passengers
///
/// @param onePassenger
void passenger_printfPassenger(Passenger* onePassenger);

/// @brief displays a menu and generates a report according to the chosen option
///
/// @param pArrayListPassenger pointer to linkedList pointing to the passenger list.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_sortPassenger(LinkedList* pArrayListPassenger);

/// @brief sort by first name in order of choice
///
/// @param passengerA parameters to match
/// @param passengerB parameters to match
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_sortByNombre(void* passengerA, void* passengerB);

/// @brief sort by last name according to the order chosen
///
/// @param passengerA parameters to match
/// @param passengerB parameters to match
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_sortByApellido(void* passengerA, void* passengerB);

/// @brief sort by price according to the order chosen
///
/// @param passengerA parameters to match
/// @param passengerB parameters to match
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int Passenger_sortByPrecio(void* passengerA, void* passengerB);

#endif /* FUNCTIONSPASSENGERS_H_ */
