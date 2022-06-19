/*
 * Controller.h
 *
 *  Created on: 18 jun 2022
 *      Author: laura
 */

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Defines.h"
#include "../inc/Parser.h"
#include "../inc/Empleados.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* puntero a char(direccion de memoria del archivo).
 * \param pArrayListEmployee LinkedList* puntero a estructura de la lista de empleados LinkedList.
 * \return int todoOk(0) si hay error. En caso de no haber error todoOk(1).
 *
 */
int controller_loadFromText(char* path , LinkedList* pListEmpleados);
int controller_addEmpleado(LinkedList* pListEmpleados);
int controller_editEmpleado(LinkedList* pListEmpleados);
int controller_removePassenger(LinkedList* pListEmpleados);
int controller_ListEmpleados(LinkedList* pListEmpleados);

int controller_clearEmpleados(LinkedList* pListEmpleados);
int controller_subListEmpleados(LinkedList* pListEmpleados);
int controller_sortEmpleados(LinkedList* pListEmpleados);
int controller_cloneEmpleados(LinkedList* pListEmpleados);

int controller_reemplazarEmpleado(LinkedList* pListEmpleados);

#endif /* INC_CONTROLLER_H_ */
