/*
 * Calculos.h
 *
 *  Created on: 16 abr 2022
 *      Author: laura
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
/// @brief Calculos. Se encarga de invocar a las funciones de las operaciones y pasarles sus respectivas variables.
///
/// @param km variable que guarda los kilometros ingresados
/// @param y variable que guarda el precio de Aerolineas
/// @param z varaiable que guarda el precio de Latam
/// @param valorBTC variable que almacena el valor del bitcoin
/// @param pDesA Es un puntero flotante donde se guardara el descuento de Aerolineas
/// @param pDescL Es un puntero flotante donde se guardara el descuento de Latam
/// @param pIntA Es un puntero flotante donde se guardara el interes de Aerolineas
/// @param pIntL Es un puntero flotante donde se guardara el interes de Latam
/// @param pBtcA Es un puntero flotante donde se guardara el precio pagando con bitcoin de Aerolineas
/// @param pBtcL Es un puntero flotante donde se guardara el precio pagando con bitcoin en Latam
/// @param pUniA Es un puntero flotante donde se guardara el precio unitario de Aerolineas
/// @param pUniL Es un puntero flotante donde se guardara el precio unitario de Latam
/// @param pDif Es un puntero flotante donde se guardara la diferencia de precio entre Aerolineas y Latam
void calculos(float km, float y, float z, float valorBTC, float* pDesA, float* pDescL, float* pIntA, float* pIntL, float* pBtcA, float* pBtcL, float* pUniA, float* pUniL, float* pDif);

/// @brief Descuento. Realiza un descuento de 10% al precio pagando con debito
///
/// @param precio varible que almacena el precio
/// @param pDescuento Es un puntero flotante donde se guardara el descuento realizado
/// @return retorna 1 indica que todo salio bien o 0 indicando que ocuurio un error
int descuento(float precio, float* pDescuento);

/// @brief Interes. Realiza un interes del 25% al precio pagando con credito
///
/// @param precio variable que almacena el precio
/// @param pInteres Es un puntero flotante donde se guardara el interes realizado
/// @return retorna 1 indica que todo salio bien o 0 indicando que ocuurio un error
int interes(float precio, float* pInteres);

/// @brief Bitcoin. Realiza la convercion de cuanto seria el precio pagando con bitcoin
///
/// @param precio variable que almacena el precio
/// @param pBitcoin Es un puntero flotante donde se guardara el resultado de la conversion
/// @param BTC variable que almacena el valor del bitcoin
/// @return retorna 1 indica que todo salio bien o 0 indicando que ocuurio un error
int bitcoin(float precio, float* pBitcoin, float BTC);

/// @brief Precio Unitario. Realiza la operacion de precio por kilometro
///
/// @param precio variable que almacena el precio
/// @param km  variable que guarda los kilometros
/// @param pUnitario Es un puntero flotante donde se guarda el resultado de el precio por km
/// @return retorna 1 indica que todo salio bien o 0 indicando que ocuurio un error
int precioUnitario(float precio, float km, float* pUnitario);

/// @brief Diferencia de Precio. Realiza la diferencia de precio que hay entre Aerolineas y Latam
///
/// @param y variable que guarda el precio de Aerolineas
/// @param z variable que guarda el precio de Latam
/// @param pDiferencia Es un puntero a flotante donde se guardara la diferencia de precio entre ambas aerolineas
/// @return retorna 1 indica que todo salio bien o 0 indicando que ocuurio un error
int diferenciaPrecio(float y, float z, float* pDiferencia);

#endif /* CALCULOS_H_ */
