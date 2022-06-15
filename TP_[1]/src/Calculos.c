/*
 * Calculos.c
 *
 *  Created on: 16 abr 2022
 *      Author: laura
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Calculos.h"

void calculos(float km, float y, float z, float valorBTC, float* pDesA, float* pDescL, float* pIntA, float* pIntL, float* pBtcA, float* pBtcL, float* pUniA, float* pUniL, float* pDif)
{
	int descuentoA;
	int descuentoL;
	int interesA;
	int interesL;
	int bitcoinA;
	int bitcoinL;
	int unitarioA;
	int unitarioL;
	int diferencia;

	descuentoA = descuento(y, pDesA);
	descuentoL = descuento(z, pDescL);
	interesA = interes(y, pIntA);
	interesL = interes(z, pIntL);
	bitcoinA = bitcoin(y, pBtcA,valorBTC);
	bitcoinL = bitcoin(z, pBtcL, valorBTC);
	unitarioA = precioUnitario(y, km, pUniA);
	unitarioL = precioUnitario(z,km, pUniL);
	diferencia = diferenciaPrecio(y, z, pDif);

	if(descuentoA && descuentoL && interesA && interesL && bitcoinA && bitcoinL && unitarioA && unitarioL && diferencia)
	{
		printf("Todos los costos realizados con exito!!\n\n");
	}
	else
	{
		printf("Ups algo ocurrio al hacer los costos\n");
	}

}

int descuento(float precio, float* pDescuento)
{
	int todoBien = 0;
	float descuento;

	if( pDescuento != NULL)
	{
		descuento = precio * 0.90;

		*pDescuento = descuento;
		todoBien = 1;
	}

	return todoBien;
}

int interes(float precio, float* pInteres)
{
	int todoBien = 0;
	float interes;

	if( pInteres != NULL)
	{
		interes = (precio * 0.25) + precio;

		*pInteres = interes;
		todoBien = 1;
	}

	return todoBien;
}

int bitcoin(float precio, float* pBitcoin, float BTC)
{
	int todoBien = 0;
	float btc;

	if( pBitcoin != NULL)
	{
		btc = precio/BTC;

		*pBitcoin = btc;
		todoBien = 1;
	}

	return todoBien;
}

int precioUnitario(float precio, float km, float* pUnitario)
{
	int todoBien = 0;
	float unitario;

	if( pUnitario != NULL)
	{
		unitario = precio/km;

		*pUnitario = unitario;
		todoBien = 1;
	}

	return todoBien;
}

int diferenciaPrecio(float y, float z, float* pDiferencia)
{
	int todoBien = 0;

	if(pDiferencia != NULL)
	{
		*pDiferencia = y - z;
		todoBien = 1;
	}

	return todoBien;
}

