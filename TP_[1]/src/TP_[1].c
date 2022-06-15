/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Laura Colque
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Menu.h"
#include "Calculos.h"
#include "Informe.h"
#define NADA 0
#define INGRESO 1

int main(void) {

	setbuf(stdout,NULL);

	char confirmar = 's';
	int opcionMenu;
	float kilometros = NADA;
	float precioAerolineas = NADA;
	float precioLatam =  NADA;
	int flagOpUno = NADA;
	int flagOpDos = NADA;
	int calcular = NADA;

	int verificarSalida;
	int verificarKm;
	int verificarPrecioA;
	int verificarPrecioL;

	float descuentoAerolineas;
	float descuentoLatam;
	float interesAerolineas;
	float interesLatam;
	float bitcoinAerolineas;
	float bitcoinLatam;
	float unitarioAerolineas;
	float unitarioLatam;
	float diferencia;

	float BTC = 4606954.55;
	float cargaKm = 7090;
	float cargaPrecioA = 162965;
	float cargaPrecioL = 159339;

	do{
		opcionMenu = menuOpciones(kilometros,precioAerolineas,precioLatam);
		switch(opcionMenu)
		{
		case 1:
			flagOpUno = INGRESO;
			verificarKm = ingresoKilometros(&kilometros);
			if(verificarKm)
			{
				printf("Operacion exitosa!!");
			}
			else
			{
				printf("Ups algo salio mal");
			}
			break;
		case 2:
			if(flagOpUno)
			{
				flagOpDos = INGRESO;
				verificarPrecioA = ingresoPrecio(&precioAerolineas,"\nIngrese el precio del vuelo de Aerolineas: ");
				verificarPrecioL = ingresoPrecio(&precioLatam, "\nIngrese el precio del vuelo de Latam: ");

				if(verificarPrecioA && verificarPrecioL)
				{
					printf("Operacion exitosa!!");
				}
				else
				{
					printf("Ups algo salio mal");
				}
			}
			else
			{
				printf("Error. Para ingresar precio primero tiene que ingresar los kilometros\n");
			}
			break;
		case 3:
			if(flagOpUno && flagOpDos)
			{
				calcular = INGRESO;
				calculos(kilometros,precioAerolineas,precioLatam,BTC,&descuentoAerolineas,&descuentoLatam,&interesAerolineas,&interesLatam,&bitcoinAerolineas,&bitcoinLatam,&unitarioAerolineas,&unitarioLatam,&diferencia);
			}
			else
			{
				printf("Error. Para calcular primero tiene ingresar el precio y los kilometros\n");
			}
			break;
		case 4:
			if(calcular)
			{
				informarResultados(kilometros, precioAerolineas, precioLatam, &descuentoAerolineas, &descuentoLatam, &interesAerolineas, &interesLatam, &bitcoinAerolineas, &bitcoinLatam, &unitarioAerolineas, &unitarioLatam, &diferencia);
			}
			else
			{
				printf("Para mostrar primero hay que calcular todos los costos\n");
			}
			break;
		case 5:
			cargaForzada(cargaKm,cargaPrecioA,cargaPrecioL,BTC,&descuentoAerolineas, &descuentoLatam, &interesAerolineas, &interesLatam, &bitcoinAerolineas, &bitcoinLatam, &unitarioAerolineas, &unitarioLatam, &diferencia);
			break;
		case 6:
			flagOpUno = NADA;
			flagOpDos = NADA;
			calcular = NADA;
			kilometros = NADA;
			precioAerolineas = NADA;
			precioLatam  = NADA;

			verificarSalida =  salida(&confirmar,"Desea continuar? s/n: ");
			if(verificarSalida && confirmar == 'n')
			{
				printf("\nSalida exitosa!!");
			}
			break;
		default:
			printf("Opcion invalida\n");
			break;
		}
		printf("\n");
		system("pause");
	}while(confirmar == 's');

	return 0;
}
