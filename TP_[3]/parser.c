#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = ERROR;
	Passenger* pPassenger = NULL;
	int cant;
	char auxTipoPass[1000];
	char auxCodVuelo[1000];
	char buffer[7][100];
	int auxId;
	int flag = 1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		auxId = saveId();
		do
		{
			if(flag)
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],auxCodVuelo,auxTipoPass,buffer[6]); //lectura fantasma
				flag = 0;
			}

			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],auxCodVuelo,auxTipoPass,buffer[6]);

			if(cant == 7)
			{
				pPassenger = Passenger_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],auxTipoPass,auxCodVuelo,buffer[6]);
				if(pPassenger != NULL)
				{
					pPassenger->id = auxId;
					auxId++;
					ll_add(pArrayListPassenger, pPassenger);
					retorno = OK;
				}
				else
				{
					printf("Ocurrio un error en la validacion.\n");
				}
			}
			else
			{
				printf("Error en leer.\n");
				break;
			}

		}while(!feof(pFile));
		nextId(auxId-1);
	}
	else
	{
		printf("Error en las validaciones\n");
	}

	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = ERROR;
	Passenger* pPassenger = NULL;
	int auxId;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		auxId = saveId();
		do
		{
			pPassenger = Passenger_new();
			if(fread(pPassenger, sizeof(Passenger),1,pFile))
			{
				pPassenger->id = auxId;
				auxId++;
				ll_add(pArrayListPassenger,pPassenger);
			}

		}while(!feof(pFile));
		nextId(auxId);
		retorno = OK;
	}
	else
	{
		printf("Error en las validaciones.\n");
	}

	return retorno;
}

