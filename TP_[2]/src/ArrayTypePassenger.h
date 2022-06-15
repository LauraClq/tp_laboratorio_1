/*
 * ArrayTypePassenger.h
 *
 *  Created on: Jun 14, 2022
 *      Author: laura
 */

#ifndef ARRAYTYPEPASSENGER_H_
#define ARRAYTYPEPASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "Defines.h"

struct
{
	int id;
	char descripcion[20];

}typedef TypePassenger;

/// @brief print the content of TypePassengers array.
///
/// @param list Pointer to array of TypePassenger.
/// @param length Array length.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int printTypePassengers(TypePassenger* list, int length);

/// @brief Load in the variable description of the passenger type chosen by the user.
///
/// @param list Pointer to array of TypePassenger.
/// @param len Array length.
/// @param id id of a passenger.
/// @param description field to load the description according to the passenger's position
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int loadDescriptionType(TypePassenger* list, int len, int id, char description[]);

/// @brief find an Passenger by Id returns the index position in array.
///
/// @param list Pointer to array of TypePassenger.
/// @param len Array length.
/// @param id id of a passenger.
/// @param pIndice pointer to the index that the function found.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int findTypeId(TypePassenger* list, int len, int id, int* pIndice);

/// @brief Validates if the id exists in the passenger array.
///
/// @param list Pointer to array of TypePassenger.
/// @param len Array length.
/// @param id id of a passenger.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int validTypePass(TypePassenger* list, int len, int id);

#endif /* ARRAYTYPEPASSENGER_H_ */
