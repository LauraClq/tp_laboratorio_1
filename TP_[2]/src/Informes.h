/*
 * Informes.h
 *
 *  Created on: 30 may 2022
 *      Author: Laura
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "Menu.h"
#include "Defines.h"
#include "Input.h"

/// @brief report of the orders according to the option chosen by the user
///
/// @param list Pointer to array of Passenger.
/// @param len Array length.
/// @param listType list Pointer to array of TypePassenger.
/// @param lenType Array length of TypePassenger.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int informesGenerales(Passenger* list, int len, TypePassenger* listType, int lenType);

/// @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
///
/// @param list Passenger*
/// @param len int
/// @param order int [1] indicate UP - [0] indicate DOWN
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int sortPassengersByLastName(Passenger* list, int len, int order);

/// @brief filters passengers by active flight status
///
/// @param list Pointer to array of Passenger.
/// @param len Array length.
/// @param listType list Pointer to array of TypePassenger.
/// @param lenType Array length of TypePassenger.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int filterActive(Passenger* list, int len, TypePassenger* listType, int lenType);

/// @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
///
/// @param list Passenger*
/// @param len int
/// @param order int [1] indicate UP - [0] indicate DOWN
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int sortPassengersByCode(Passenger* list, int len, int order);

/// @brief It calculates the total and the average of all prices
///
/// @param list Pointer to array of Passenger.
/// @param len Array length.
/// @param listType list Pointer to array of TypePassenger.
/// @param lenType Array length of TypePassenger.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int sortTotalAveragePrice(Passenger* list, int len, TypePassenger* listType, int lenType);

#endif /* INFORMES_H_ */

