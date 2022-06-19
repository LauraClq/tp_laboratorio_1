/*
 * Empleados.h
 *
 *  Created on: 18 jun 2022
 *      Author: laura
 */

#ifndef SRC_EMPLEADOS_H_
#define SRC_EMPLEADOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../inc/LinkedList.h"
#include "../inc/Input.h"
#include "../inc/Defines.h"
#include "../inc/Menus.h"

typedef struct
{
	int id;
	char nombre[20];
	char apellido[20];
	float sueldo;
	int sector;

}eEmpleados;

eEmpleados* empleados_new();
eEmpleados* empleado_newParametros(char* id,char* nombre,char* apellido,char* sueldo,char* sector);

void empleado_delete(eEmpleados* empleado);

int empleado_loadEmpleados(char* nombre, char* apellido, float* sueldo, int* sector);
int empleado_searchById(LinkedList* pListEmpleados, int id);
int empleado_editById(eEmpleados* pEmpleado);

/// @brief Muestra los datos de un empleado.
///
/// @param unEmpleado puntero a estructura eEmpleados, para obtener los datos del mismo.
/// @return ERROR -1 o OK 0
int empleado_printfUnEmpleado(eEmpleados* unEmpleado);

/// @brief Invoca  a todos los setters
///
/// @param empleado puntero a estructura eEmpleados, para obtener los datos del mismo.
/// @param id int*
/// @param nombre char*
/// @param apellido char*
/// @param sueldo float
/// @param sector int
/// @return ERROR -1 o OK 0
int empleado_setterAll(eEmpleados* empleado,int* id, char* nombre, char* apellido, float sueldo, int sector);

/// @brief carga el id de un empleado.
///
/// @param empleado puntero a estructura eEmpleados de un empleado donde se asigna el id.
/// @param id guarda el valor del id.
/// @return ERROR -1 o OK 0
int empleado_setId(eEmpleados* empleado,int* id);

/// @brief Busca el empleado segun el id asignado al mismo.
///
/// @param empleado puntero a estructura eEmpleados de un empleado donde se asigna el id.
/// @param pId puntero a entero, que carga el valor del id del empleado.
/// @return ERROR -1 o OK 0
int empleado_getId(eEmpleados* empleado,int* pId);

/// @brief carga el nombre del empleado
///
/// @param empleado puntero a estructura eEmpleados de un empleado donde se asigna el nombre.
/// @param nombre
/// @return ERROR -1 o OK 0
int empleado_setNombre(eEmpleados* empleado,char* nombre);

/// @brief Busca el empleado segun el nombre asignado al mismo.
///
/// @param empleado puntero a estructura eEmpleados de un empleado donde se asigna el nombre.
/// @param nombre
/// @return ERROR -1 o OK 0
int empleado_getNombre(eEmpleados* empleado,char* nombre);

/// @brief carga el apellido del empleado
///
/// @param empleado  puntero a estructura eEmpleados de un empleado donde se asigna el apellido
/// @param apellido
/// @return ERROR -1 o OK 0
int empleado_setApellido(eEmpleados* empleado,char* apellido);

/// @brief Busca el empleado segun el apellido asignado al mismo.
///
/// @param empleado puntero a estructura eEmpleados de un empleado donde se asigna el apellido
/// @param apellido
/// @return ERROR -1 o OK 0
int empleado_getApellido(eEmpleados* empleado,char* apellido);

/// @brief carga el sueldo del empleado
///
/// @param empleado puntero a estructura eEmpleados de un empleado donde se asigna el sueldo
/// @param sueldo
/// @return ERROR -1 o OK 0
int empleado_setSueldo(eEmpleados* empleado,float sueldo);

/// @brief  Busca el empleado segun el sueldo asignado al mismo.
///
/// @param empleado puntero a estructura eEmpleados de un empleado donde se asigna el sueldo
/// @param sueldo
/// @return ERROR -1 o OK 0
int empleado_getSueldo(eEmpleados* empleado,float* sueldo);

/// @brief arga el sector del empleado
///
/// @param empleado puntero a estructura eEmpleados de un empleado donde se asigna el sector
/// @param sector
/// @return ERROR -1 o OK 0
int empleado_setSector(eEmpleados* empleado,int sector);

/// @brief Busca el empleado segun el sector asignado al mismo.
///
/// @param empleado puntero a estructura eEmpleados de un empleado donde se asigna el sector
/// @param sector
/// @return ERROR -1 o OK 0
int empleado_getSector(eEmpleados* empleado,int* sector);

/// @brief carga la descripcion segunsector
///
/// @param sector int
/// @param descripcion char*
/// @return ERROR -1 o OK 0
int empleado_DescripSector(int sector, char* descripcion);

/// @brief compara las esctuturas
///
/// @param empleadoA
/// @param empleadoB
/// @return criterio 1 o criterio -1
int empleado_sortNombre(void* empleadoA, void* empleadoB);
int empleado_sortApellido(void* empleadoA, void* empleadoB);
int empleado_sortSueldo(void* empleadoA, void* empleadoB);

int getId(int* id);
int actualizarId(int id);
int empleado_validId(LinkedList* pListEmpleados, int id);

#endif /* SRC_EMPLEADOS_H_ */
