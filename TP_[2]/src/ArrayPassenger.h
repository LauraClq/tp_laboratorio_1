/*
 * ArrayPassenger.h
 *
 *  Created on: 28 may 2022
 *      Author: Laura
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayTypePassenger.h"
#include "Input.h"
#include "Defines.h"
#include "Menu.h"

struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}typedef Passenger;

/// @brief  print the content of passengers array.
///
/// @param list Pointer to array of Passenger.
/// @param length Array length.
/// @param listType Pointer to array of TypePassenger.
/// @param lenType Array length of TypePassenger.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int printPassengers(Passenger* list, int length, TypePassenger* listType, int lenType);

/// @brief prints the content of one passenger.
///
/// @param passenger Pointer to array of Passenger.
/// @param listType Pointer to array of TypePassenger.
/// @param lenType  Array length of TypePassenger.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int onePassenger(Passenger* passenger, TypePassenger* listType, int lenType);

/// @brief To indicate that all position in the array are empty, this function put (isEmpty) in FREE in all position of the array.
///
/// @param list Passenger* Pointer to array of Passenger.
/// @param len Array length.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int initPassengers(Passenger* list, int len);

/// @brief Creates an passenger.
///
/// @param auxList Pointer to array of Passenger.
/// @param pId self incremental id.
/// @param listType Pointer to array of TypePassenger.
/// @param lenType Array length of TypePassenger
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int loadPassengers(Passenger* auxList, int* pId, TypePassenger* listType, int lenType);

/// @brief add in a existing list of passenger the values received as parameters in the first empty position
///
/// @param list Pointer to array of Passenger.
/// @param len Array length.
/// @param id int
/// @param name string
/// @param lastName string
/// @param price float
/// @param typePassenger int
/// @param flycode string
/// @param statusFlight int
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int addPassengers(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight);

/// @brief looks for an empty position on the array of Passenger.
///
/// @param list Pointer to array of Passenger.
/// @param len Array length.
/// @param pIndex  pointer to the index that the function found.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int findPositionFree(Passenger* list, int len, int* pIndex);

/// @brief find an Passenger by Id returns the index position in array.
///
/// @param list Pointer to array of Passenger.
/// @param len  Array length
/// @param id int
/// @return Return index position or (-1) ERROR if [Invalid len or NULL pointer received or Passenger not found].
int findPassengerById(Passenger* list, int len, int id);

/// @brief Gets the passenger id to modify and calls the function "modifyPassengerById"
///
/// @param list Pointer to array of Passenger.
/// @param len Array length
/// @param listType Pointer to array of TypePassenger.
/// @param lenType Array length of TypePassenger.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK or (1) if VALID parameters
int modifyPassenger(Passenger* list, int len, TypePassenger* listType, int lenType);

/// @brief Modifies the passenger information according to the option received by parameter.
///
/// @param list Pointer to array of Passenger.
/// @param len Array length
/// @param index position of the passenger array that contains the chosen employee to modify.
/// @param listType Pointer to array of TypePassenger.
/// @param lenType Array length of TypePassenger.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int modifyPassengerById(Passenger* list, int len, int index, TypePassenger* listType, int lenType);

/// @brief  Remove a Passenger by Id
///
/// @param list Pointer to array of Passenger.
/// @param len Array length
/// @param id Id of the passenger who is going to be removed.
/// @param listType Pointer to array of TypePassenger.
/// @param lenType Array length of TypePassenger.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int removePassenger(Passenger* list, int len, int id, TypePassenger* listType, int lenType);

/// @brief  ask for the id of an passenger to remove him.
///
/// @param list Pointer to array of Passenger.
/// @param len Array length
/// @param listType Pointer to array of TypePassenger.
/// @param lenType Array length of TypePassenger.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK or (1) if VALID parameters
int removePassengerById(Passenger* list, int len, TypePassenger* listType, int lenType);

/// @brief  forces a data load to the passenger array
///
/// @param list Pointer to array of Passenger.
/// @param len Array length
/// @param pId self incremental id.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int altaForzadaPassengers(Passenger* list, int len, int* pId);

#endif /* ARRAYPASSENGER_H_ */
