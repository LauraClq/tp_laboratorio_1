/*
 * Menu.h
 *
 *  Created on: 6 jun 2022
 *      Author: Laura
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

/// @brief displays the menu.
///
/// @return the option that the user chosen.
int menu();

/// @brief displays the edit menu
///
/// @return the option that the user chosen.
int menuEdit();

/// @brief displays the sort menu
///
/// @return the option that the user chosen.
int menuSort();

#endif /* MENU_H_ */
