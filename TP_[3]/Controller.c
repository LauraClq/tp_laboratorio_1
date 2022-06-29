
#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = ERROR;

	FILE* pFile1 = fopen(path, "r");

	if(pFile1 != NULL && pArrayListPassenger != NULL)
	{
		if(!parser_PassengerFromText(pFile1, pArrayListPassenger))
		{
			fclose(pFile1);
			retorno = OK;
		}
		else
		{
			printf("Error en el parser.\n");
		}
	}
	else
	{
		printf("Error en la validacion\n");
	}

	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = ERROR;
	FILE* pFile1 = fopen(path, "rb");

	if(pFile1 != NULL && pArrayListPassenger != NULL)
	{

		if(!parser_PassengerFromBinary(pFile1, pArrayListPassenger))
		{
			fclose(pFile1);
			retorno = OK;
		}
		else
		{
			printf("Error en el parser.\n");
		}
	}
	else
	{
		printf("Error en la validacion.\n");
	}

	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pPassenger = Passenger_new();
	int retorno = ERROR;
	int auxId;
	char auxNombre[TAM_STRING];
	char auxApellido[TAM_STRING];
	float auxPrecio;
	int auxTipoPass;
	char auxCodVuelo[TAM_FLYCODE];
	int auxEstVuelo;

	if(pArrayListPassenger != NULL && pPassenger != NULL)
	{
		if(!passenger_loadPassengers(auxNombre,auxApellido,&auxPrecio,&auxTipoPass,auxCodVuelo,&auxEstVuelo))
		{
			auxId = saveId();
			printf("%d\n",auxId);

			if(!Passenger_setId(pPassenger,auxId) &&
					!Passenger_setNombre(pPassenger, auxNombre) &&
					!Passenger_setApellido(pPassenger, auxApellido) &&
					!Passenger_setPrecio(pPassenger,auxPrecio) &&
					!Passenger_setTipoPasajero(pPassenger,auxTipoPass) &&
					!Passenger_setCodigoVuelo(pPassenger, auxCodVuelo) &&
					!Passenger_setEstadoVuelo(pPassenger, auxEstVuelo))
			{

				ll_add(pArrayListPassenger,pPassenger);
				nextId(auxId);
				printf("%d\n",auxId);
				retorno = OK;
			}
			else
			{
				printf("Ocurrio un error en los carga de datos\n");
			}

		}
		else
		{
			printf("Ocurrio un error en las validaciones\n");
		}

	}
	else
	{
		printf("Error\n");
	}

	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = ERROR;
	Passenger* pPassenger;
	int auxId;
	int index;

	if(pArrayListPassenger != NULL)
	{
		printf("\n                         *** MODIFICAR PASAJEROS ***        \n");
		printf("        -------------------------------------------------------------\n\n");

		controller_ListPassenger(pArrayListPassenger);
		Utn_GetInt(&auxId,"Ingrese el id que sea modificar: ","\nError, dato invalido\n",MIN_ID,MAX_ID,ATTEMPTS);

		index = Passenger_searchById(pArrayListPassenger, auxId);

		if(index != ERROR)
		{
			pPassenger = (Passenger*)ll_get(pArrayListPassenger, index);
			passenger_printfPassenger(pPassenger);

			if(!Passenger_editById(pPassenger))
			{
				retorno = OK;
			}
		}
	}

	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = ERROR;
	Passenger* pPassenger;
	int auxId;
	int index;
	char confirma;

	if(pArrayListPassenger != NULL)
	{
		printf("\n                         *** DAR DE BAJA PASAJEROS ***        \n");
		printf("        -------------------------------------------------------------\n\n");

		controller_ListPassenger(pArrayListPassenger);
		Utn_GetInt(&auxId,"Ingrese el id a dar de baja: ","\nError, dato invalido\n",MIN_ID,MAX_ID,ATTEMPTS);

		index = Passenger_searchById(pArrayListPassenger, auxId);

		if(index != ERROR)
		{
			pPassenger = (Passenger*)ll_get(pArrayListPassenger, index);
			passenger_printfPassenger(pPassenger);

			confirma = confirmacion("\nDesea confirmar a dar de baja (s - n)?: ");
			if(confirma == 's')
			{
				ll_remove(pArrayListPassenger, index);
				Passenger_delete(pPassenger);
				retorno = OK;
			}
			else
			{
				printf("Baja cancelada por el usuario.\n");
			}
		}

	}
	return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = ERROR;
	int len;
	Passenger* pPassenger = NULL;

	if(pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);

		printf("                                *** LISTA DE PASAJEROS ***\n");
		printf(" ---------------------------------------------------------------------------------------------------\n");
		printf(" |  ID   |     NAME     |   LASTNAME   |  PRICE   |   FLYCODE   |   TYPEPASSENGER  | STATUSFLIGHT  |\n");
		printf(" ---------------------------------------------------------------------------------------------------\n");
		for(int i=0; i < len; i++)
		{
			pPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
			if(pPassenger != NULL)
			{
				passenger_printfPassenger(pPassenger);
			}
		}
		printf(" |_______|______________|______________|__________|_____________|__________________|_______________|\n");
		printf("\n\n");
		retorno = OK;
	}
	else
	{
		printf("No hay pasajeros registrados.\n");
	}

	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = ERROR;

	if(pArrayListPassenger != NULL)
	{
		if(!Passenger_sortPassenger(pArrayListPassenger))
		{
			retorno = OK;
		}
	}

	return retorno;
}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = ERROR;
	Passenger* pPassenger;
	int len;
	int auxId;
	char auxNombre[TAM_STRING];
	char auxApellido[TAM_STRING];
	float auxPrecio;
	char auxCodVuelo[TAM_FLYCODE];
	int auxTipoPass;
	int auxEstVuelo;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* pFile = fopen(path, "w");

		if(pFile != NULL)
		{
			len = ll_len(pArrayListPassenger);
			pPassenger = Passenger_new();

			if(pPassenger != NULL)
			{
				fprintf(pFile,"id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo\n");

				for(int i=0; i<len; i++)
				{
					pPassenger = (Passenger*) ll_get(pArrayListPassenger, i);

					if(pPassenger != NULL)
					{
						Passenger_getId(pPassenger,&auxId);
						Passenger_getNombre(pPassenger,auxNombre);
						Passenger_getApellido(pPassenger,auxApellido);
						Passenger_getPrecio(pPassenger,&auxPrecio);
						Passenger_getTipoPasajero(pPassenger,&auxTipoPass);
						Passenger_getCodigoVuelo(pPassenger,auxCodVuelo);
						Passenger_getEstadoVuelo(pPassenger,&auxEstVuelo);

						fprintf(pFile,"%d,%s,%s,%.2f,%s,%d,%d\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodVuelo,auxTipoPass,auxEstVuelo);
						retorno = OK;
					}
					else
					{
						printf("Errror en el parametro.\n");
						break;
					}
				}
			}
		}
		fclose(pFile);
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = ERROR;
	Passenger* pPassenger;
	int len;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* pFile = fopen(path, "wb");

		if(pFile != NULL)
		{
			len = ll_len(pArrayListPassenger);
			for(int i=0; i<len; i++)
			{
				pPassenger = (Passenger*) ll_get(pArrayListPassenger, i);

				if(pPassenger != NULL )
				{
					if(fwrite(pPassenger, sizeof(Passenger),1, pFile))
					{
						retorno = OK;
					}
					else
					{
						printf("Error al escribir el archivo binario\n");
						break;
					}
				}
			}
		}
		fclose(pFile);
		ll_clear(pArrayListPassenger);
	}

	return retorno;
}


