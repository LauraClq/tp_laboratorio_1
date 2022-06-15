/*
 * ArrayTypePassenger.c
 *
 *  Created on: Jun 14, 2022
 *      Author: laura
 */
#include "ArrayTypePassenger.h"

int printTypePassengers(TypePassenger* list, int length)
{
	int Retorno = ERROR;

	if(list != NULL && length > 0)
	{
		printf("\n* LISTA DE TIPOS DE PASAJEROS *\n");
		printf(" -------------------------\n");
		printf(" | ID |   DESCRIPTION    |\n");
		printf(" -------------------------\n");
		for(int i=0; i<length; i++)
		{
			  printf(" | %-2d |  %-15s |\n",list[i].id,list[i].descripcion);
		}
		printf(" |____|__________________|\n\n");
		Retorno = OK;

	}
	return Retorno;
}

int loadDescriptionType(TypePassenger* list, int len, int id, char description[])
{
	int Retorno = ERROR;
	int indice;

	findTypeId(list, len, id, &indice);

	if(description != NULL && indice != ERROR)
	{
		strcpy(description, list[indice].descripcion);
		Retorno = OK;
	}

	return Retorno;
}

int findTypeId(TypePassenger* list, int len, int id, int* pIndice)
{
	int Retorno = ERROR;

	if(list != NULL && len > 0 && id > 0 && pIndice != NULL)
	{
		*pIndice = ERROR;
		for(int i=0; i<len; i++)
		{
			if( list[i].id == id)
			{
				*pIndice = i;
			}
		}
		Retorno = OK;
	}
	return Retorno;
}

int validTypePass(TypePassenger* list, int len, int id)
{
	int Retorno = ERROR;
	int indice;

	if(list != NULL && len > 0 && id > 0 )
	{
		findTypeId(list, len, id, &indice);

		if(indice != ERROR)
		{
			Retorno = OK;
		}
	}
	return Retorno;
}
