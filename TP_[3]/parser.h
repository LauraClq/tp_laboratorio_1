#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Defines.h"
#include "FunctionsPassengers.h"

/// @brief This function parses the employee data from the data.csv file (text mode).
///
/// @param pFile This is the file to be parsed in text mode.
/// @param pArrayListPassenger pointer to linkedList pointing to the passenger list.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/// @brief
///
/// @param pFile This is the file to be parsed in binary mode.
/// @param pArrayListPassenger pointer to linkedList pointing to the passenger list.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

