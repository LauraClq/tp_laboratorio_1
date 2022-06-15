/*
 * Informes.c
 *
 *  Created on: 30 may 2022
 *      Author: Laura
 */
#include "Informes.h"

int informesGenerales(Passenger* list, int len, TypePassenger* listType, int lenType)
{
	int Retorno = ERROR;
	char salir;
	int opcion;
	int order = 0;
	int validaOrder;

	if(list != NULL && len > 0 && listType != NULL && lenType > 0)
	{
		do
		{
			opcion = menuInformes();
			switch(opcion)
			{
			case 1:
				validaOrder = Utn_GetInt(&order,"De que forma desea ordenar? Ingrese 1 (Ascendente) o 0 (Descendente): ","\nError.Dato invalido solo numeros.\n",SORT_DESC,SORT_ASC,ATTEMPTS);
				if(!validaOrder)
				{
					if(!sortPassengersByLastName(list, len, order))
					{
						printPassengers(list, len, listType, lenType);
					}
					else
					{
						printf("Error al ordernar apellido\n");
					}
				}
				break;
			case 2:
				if(!sortTotalAveragePrice(list, len, listType, lenType))
				{
					printf("\nOperacion exitosa!!\n\n");
				}
				else
				{
					printf("\nError el calcular el promedio!!\n\n");
				}
				break;
			case 3:
				validaOrder = Utn_GetInt(&order,"De que forma desea ordenar? Ingrese 1 (Ascendente) o 0 (Descendente): ","\nError.Dato invalido solo numeros.\n",SORT_DESC,SORT_ASC,ATTEMPTS);
				if(!validaOrder)
				{
					if(!sortPassengersByCode(list, len, order))
					{
						if(!filterActive(list, len, listType, lenType))
						{
							printf("Ordenamiento exitoso!!\n\n");
						}

					}
					else
					{
						printf("Error al ordernar codigo de vuelo\n");
					}
				}
				break;
			case 4:
				salir = confirmacion("Desea salir del menu de los informes? s - n: ");
				if(salir == 's')
				{
					printf("SALIDA EXITOSA");
				}
				break;
			default:
				printf("Opcion invalida\n");
				break;
			}

		}while(salir != 's');
		Retorno = OK;
	}

	return Retorno;
}

int sortPassengersByLastName(Passenger* list, int len, int order)
{
	int Retorno = ERROR;
	Passenger auxPassenger;
	int orderLastName;

	if(list != NULL && len > 0 && order >= 0 && order <= 1)
	{
		for(int i=0; i<len-1; i++)
		{
			for(int j=i+1; j<len; j++)
			{
				orderLastName = strcmp(list[i].lastName,list[j].lastName);

				if( !list[i].isEmpty && order == SORT_ASC)
				{
					if((orderLastName == 0 && list[i].typePassenger != list[j].typePassenger && list[i].typePassenger > list[j].typePassenger) || orderLastName > 0 )
					{
						auxPassenger = list[i];
						list[i] = list[j];
						list[j] = auxPassenger;
						Retorno = OK;
					}

				}
				else if( !list[i].isEmpty && order == SORT_DESC)
				{
					if( (orderLastName == 0 && list[i].typePassenger != list[j].typePassenger && list[i].typePassenger < list[j].typePassenger) || (orderLastName < 0))
					{
						auxPassenger = list[i];
						list[i] = list[j];
						list[j] = auxPassenger;
						Retorno = OK;
					}
				}
			}
		}
	}

	return Retorno;
}

int sortTotalAveragePrice(Passenger* list, int len, TypePassenger* listType, int lenType)
{
	int Retorno = ERROR;
	int contTotal = 0;
	float acumPrice = 0;
	float averagePrice = 0;
	int flag = ERROR;


	if(list != NULL && len > 0 && listType != NULL && lenType > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(!list[i].isEmpty)
			{
				contTotal++;
				acumPrice += list[i].price;
				Retorno = 1;
			}
		}
	}

	averagePrice = acumPrice / contTotal;

	printf("\nEl total de precios de los pasajes es: $%.2f\n",acumPrice);
	printf("El promedio de precios de los pasajes es: $%.2f\n\n",averagePrice);

	printf("   *** LISTA DE PASAJEROS QUE SUPERAN EL PRECIO PROMEDIO ***\n");
	printf(" -------------------------------------------------------------------------------------\n");
	printf(" | ID  |   NAME   | LASTNAME |  PRICE   |  FLYCODE  | TYPEPASSENGER  | STATUSFLIGHT |\n");
	printf(" -------------------------------------------------------------------------------------\n");
	for(int i=0; i<len; i++)
	{
		if(!list[i].isEmpty && averagePrice > 0 && list[i].price > averagePrice)
		{
			onePassenger(&list[i],listType,lenType);
			flag = OK;
		}
	}
	printf(" |_____|__________|__________|__________|___________|________________|______________|\n");

	if(flag == ERROR)
	{
		printf("No hay pasajeros que superen el precio del promedio\n");
	}

	return Retorno;
}


int sortPassengersByCode(Passenger* list, int len, int order)
{
	int Retorno = ERROR;
	int orderFlycode;
	Passenger auxPassenger;

	if(list != NULL && len > 0 && order >= 0 && order <= 1)
	{
		for(int i=0; i<len-1; i++)
		{
			if(!list[i].isEmpty)
			{
				for(int j=i+1; j<len; j++)
				{
					orderFlycode = strcmp(list[i].flycode,list[j].flycode);
					if((order == SORT_ASC && orderFlycode >= 0 ) || (order == SORT_DESC && orderFlycode <= 0 ))
					{
						auxPassenger = list[i];
						list[i] = list[j];
						list[j] = auxPassenger;
						Retorno = OK;
					}
				}
			}
		}

	}

	return Retorno;
}

int filterActive(Passenger* list, int len, TypePassenger* listType, int lenType)
{
	int Retorno = ERROR;
	int flag = ERROR;

	if(list != NULL && len > 0 && listType != NULL && lenType > 0)
	{
		printf("\n  *** LISTA DE PASAJEROS CON STATUSFLIGHT ACTIVO ORDENADOS POR FLYCODE ***\n");
		printf(" -------------------------------------------------------------------------------------\n");
		printf(" | ID  |   NAME   | LASTNAME |   PRICE  |  FLYCODE  |  TYPEPASSENGER  | STATUSFLIGHT |\n");
		printf(" -------------------------------------------------------------------------------------\n");
		for(int i=0; i<len; i++)
		{
			if(!list[i].isEmpty && list[i].statusFlight == 1)
			{
				onePassenger(&list[i],listType,lenType);
				flag = OK;
				Retorno = OK;
			}
		}
		printf(" |_____|__________|__________|__________|___________|_________________|______________|\n");

		if(flag == ERROR)
		{
			printf(" No hay pasajeros con estado de vuelo activo\n");
		}
	}

	return Retorno;
}


