/*
 * Informe.h
 *
 *  Created on: 16 abr 2022
 *      Author: laura
 */

#ifndef INFORME_H_
#define INFORME_H_
/// @brief Informe de los Resultados. Se encarga de mostrar un informe de las diferentes opciones de pago.
///
/// @param km variable que guarda los kilometros ingresados
/// @param y variable que guarda el precio de Aerolineas
/// @param z variable que guarda el precio de Latam
/// @param pDescA Es un puntero flotante que guarda el precio de Aerolineas con el descuento realizado
/// @param pDescL Es un puntero flotante que guarda el precio de Latam con el descuento realizado
/// @param pIntA Es un puntero flotante que guarda el precio de Aerolineas con el interes realizado
/// @param pIntL Es un puntero flotante que guarda el precio de Latam con el interes realizado
/// @param pBtcA Es un puntero flotante que guarda el precio de Aerolineas pagando con bitcoin
/// @param pBtcL Es un puntero flotante que guarda el precio de Latam pagando con bitcoin
/// @param uniA Es un puntero flotante que guarda el precio de Aerolienas por kilometros recorridos
/// @param uniL Es un puntero flotante que guarda el precio de Latam por kilometros recorridos
/// @param difPrecio Es un puntero flotante que guarda la diferencia de precio entre Aerolineas y Latam
void informarResultados(float km, float y, float z, float* pDescA, float* pDescL, float* pIntA, float* pIntL, float* pBtcA, float* pBtcL, float* uniA, float* uniL, float* difPrecio);

/// @brief Carga Forzada. Se encarga de harcodear las operaciones de los calculos y de los informes, con valores precargados
///
/// @param km variable precargada con el valor de kilometros
/// @param y variable precargada con el valor del precio de Aerolineas
/// @param z variable precargada con el valor del precio de Latam
/// @param valorBTC variable que almacena el valor del bitcoin
/// @param pDescA Es un puntero flotante que guardara el precio de Aerolineas con el descuento realizado
/// @param pDescL Es un puntero flotante que guardara el precio de Latam con el descuento realizado
/// @param pIntA Es un puntero flotante que guardara el precio de Aerolineas con el interes realizado
/// @param pIntL Es un puntero flotante que guardara el precio de Latam con el interes realizado
/// @param pBtcA Es un puntero flotante que guardara el precio de Aerolineas pagando con bitcoin
/// @param pBtcL Es un puntero flotante que guardara el precio de Latam pagando con bitcoin
/// @param pUniA Es un puntero flotante que guardara el precio de Aerolienas por kilometros recorridos
/// @param pUniL Es un puntero flotante que guardara el precio de Latam por kilometros recorridos
/// @param pDifPrecio Es un puntero flotante que guardara la diferencia de precio entre Aerolineas y Latam
void cargaForzada(float km, float y, float z, float valorBTC, float* pDescA, float* pDescL, float* pIntA, float* pIntL, float* pBtcA, float* pBtcL, float* pUniA, float* pUniL, float* pDifPrecio);

#endif /* INFORME_H_ */
