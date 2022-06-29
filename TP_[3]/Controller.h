
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Defines.h"
#include "FunctionsPassengers.h"
#include "Menu.h"
#include "Input.h"
#include "MaxID.h"

/// @brief Load passenger data from the data.csv file (text mode).
///
/// @param path file where the data will be loaded
/// @param pArrayListPassenger pointer to linkedList pointing to the passenger list.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/// @brief Load passenger data from the data.csv file (binary mode).
///
/// @param path ile where the data will be loaded
/// @param pArrayListPassenger pointer to linkedList pointing to the passenger list.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/// @brief add in a existing list of passenger the values received as parameters in the first empty position
///
/// @param pArrayListPassenger pointer to linkedList pointing to the passenger list.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int controller_addPassenger(LinkedList* pArrayListPassenger);

/// @brief Gets the passenger id to modify and calls the function "Passenger_editrById"
///
/// @param pArrayListPassenger pointer to linkedList pointing to the passenger list.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int controller_editPassenger(LinkedList* pArrayListPassenger);

/// @brief Remove a Passenger by Id
///
/// @param pArrayListPassenger pointer to linkedList pointing to the passenger list.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int controller_removePassenger(LinkedList* pArrayListPassenger);

/// @brief print the content of passengers.
///
/// @param pArrayListPassenger pointer to linkedList pointing to the passenger list.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/// @brief  sort passengers in ascending or descending order according to the chosen option
///
/// @param pArrayListPassenger
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/// @brief Saves passenger data in the file data.csv (text mode).
///
/// @param path file where the data will be save
/// @param pArrayListPassenger
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/// @brief Saves passenger data in the file data.csv (binary mode).
///
/// @param path file where the data will be save
/// @param pArrayListPassenger
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


