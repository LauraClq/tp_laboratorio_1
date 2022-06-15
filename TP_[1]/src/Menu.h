/*
 * Menu.h
 *
 *  Created on: 16 abr 2022
 *      Author: laura
 */

#ifndef MENU_H_
#define MENU_H_
/// @brief Menu de opciones. Despliega un menu de opciones y pide al usuario ingresar una opcion
///
/// @param km El primer valor actual cargado que se muestraa en el menu
/// @param y El segundo valor actual cargado que se muestra en el menu
/// @param z El tercer valor actual cargado que se muestra en el menu
/// @return La opcion seleccionada
int menuOpciones(float km, float y, float z);

/// @brief Ingreso de kilometros. Pide al usuario ingresar kilometros
///
/// @param km Es un puntero flotante, donde se guarda el valor ingresado
/// @return retorna 1 indica que todo salio bien o 0 indicando que ocuurio un error
int ingresoKilometros(float* pKm);

/// @brief Ingreso de precio. Pide al usuario ingresar el precio de su vuelo
///
/// @param pPrecio Es un puntero a flotante, donde se guarda el precio
/// @param mensaje se muestra al usuario de cual aerolinea ingresa el precio
/// @return retorna 1 indica que todo salio bien o 0 indicando que ocuurio un error
int ingresoPrecio(float* pPrecio, char mensaje[]);

/// @brief Salida. Pregunta al usuario si desea salir del programa
///
/// @param pConfirma Es un puntero a char, donde se guarda la respuesta
/// @param mensaje se muestra al usuario si desea salir
/// @return retorna 1 indica que todo salio bien o 0 indicando que ocuurio un error
int salida(char* pConfirma, char mensaje[]);

#endif /* MENU_H_ */
