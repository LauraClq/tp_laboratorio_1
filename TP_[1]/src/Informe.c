/*
 * Informe.c
 *
 *  Created on: 16 abr 2022
 *      Author: laura
 */
#include <stdio.h>
#include <stdlib.h>
#include "Informe.h"
#include "Calculos.h"

void informarResultados(float km, float y, float z, float* pDescA, float* pDescL, float* pIntA, float* pIntL, float* pBtcA, float* pBtcL, float* uniA, float* uniL, float* difPrecio)
{
	printf("\n");
	printf("KMs Ingresados: %.2f Km\n\n",km);
	printf("Precio Aerolineas: $ %.2f\n",y);
	printf("a) Precio con tarjeat de debito: $ %.2f\n",*pDescA);
	printf("b) Precio con tarjeta de credito: $ %.2f\n",*pIntA);
	printf("c) Precio pagando con bitcoin: %.7f BTC\n",*pBtcA);
	printf("d) Mostrar precio unitario: $ %.2f\n\n",*uniA);

	printf("Precio Latam: $ %.2f\n",z);
	printf("a) Precio con tarjeat de debito: $ %.2f\n",*pDescL);
	printf("b) Precio con tarjeta de credito: $ %.2f\n",*pIntL);
	printf("c) Precio pagando con bitcoin: %.7f BTC\n",*pBtcL);
	printf("d) Mostrar precio unitario: $ %.2f\n\n",*uniL);

	printf("La diferencia de precio es: $ %.2f\n\n",*difPrecio);
}

void cargaForzada(float km, float y, float z,float valorBTC, float* pDescA, float* pDescL, float* pIntA, float* pIntL, float* pBtcA, float* pBtcL, float* pUniA, float* pUniL, float* pDifPrecio)
{
	calculos(km,y,z,valorBTC,pDescA,pDescL,pIntA,pIntL,pBtcA,pBtcL,pUniA,pUniL,pDifPrecio);
	informarResultados(km, y, z, pDescA, pDescL, pIntA, pIntL, pBtcA, pBtcL, pUniA, pUniL, pDifPrecio);
}

