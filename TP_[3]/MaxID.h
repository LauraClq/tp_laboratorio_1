/*
 * MaxID.h
 *
 *  Created on: 27 jun 2022
 *      Author: laura
 */

#ifndef MAXID_H_
#define MAXID_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Defines.h"
#include "LinkedList.h"
#include "Passenger.h"

/// @brief open a file to save the id if it does not exist create a new one
///
/// @return lastid
int saveId();

/// @brief This function saves the last id entered in the list to a text file and updates it
///
/// @param idActual go to save
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int nextId(int idActual);

#endif /* MAXID_H_ */
