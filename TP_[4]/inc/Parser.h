/*
 * Parser.h
 *
 *  Created on: 18 jun 2022
 *      Author: laura
 */

#ifndef INC_PARSER_H_
#define INC_PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/Defines.h"
#include "../inc/Empleados.h"

/// @brief Parsea los datos de los empleados desde el archivo Empleados.csv (modo texto).
///
/// @param pFile char* puntero a char(direccion de memoria del archivo).
/// @param pListEmpleados LinkedList* puntero a estructura de la lista de empleados LinkedList.
/// @return int ERROR -1 o OK 0
int parser_EmpleadosFromText(FILE* pFile , LinkedList* pListEmpleados);

#endif /* INC_PARSER_H_ */
