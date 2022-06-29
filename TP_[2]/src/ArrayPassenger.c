/*
 * ArrayPassenger.c
 *
 *  Created on: 28 may 2022
 *      Author: Laura
 */
#include "ArrayPassenger.h"

int initPassengers(Passenger* list, int len)
{
	int Retorno = ERROR;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			list[i].isEmpty = FREE;
			Retorno = OK;
		}
	}

	return Retorno;

}

int loadPassengers(Passenger* auxList, int* pId, TypePassenger* listType, int lenType)
{
	int Retorno = ERROR;
	int validName;
	int validLastName;
	int validPrice;
	int validType;
	int validFlycode;
	int validStatus;
	Passenger auxListP;

	if(auxList != NULL && pId != NULL && listType != NULL && lenType > 0)
	{
		printf("El id que se le asignara es: %d\n",*pId);

		validName = Utn_GetStringName("Ingrese su nombre: ","\nError. Dato invalido solo permite letras.\n","\nError se excedio del limite y no permite campos vacios.\n",auxListP.name,MIN_STRING,TAM_STRING);
		validLastName = Utn_GetString(auxListP.lastName,TAM_STRING,"Ingrese su apellido: ","\nError.Dato invalido solo permite letras.\n",ATTEMPTS);
		validPrice = Utn_GetFloat(&auxListP.price,"Ingrese el precio del vuelo: ","\nError.Dato invalido solo permite numeros.(5000 - 450000).\n",MIN_PRICE,MAX_PRICE,ATTEMPTS);

		printTypePassengers(listType, lenType);
		validType = Utn_GetInt(&auxListP.typePassenger,"Ingrese el tipo de pasajero: ","\nError.Dato invalido solo permite numeros.(1 - 4).\n",MIN_TYPE,MAX_TYPE,ATTEMPTS);
		while(validTypePass(listType, lenType,auxListP.typePassenger) == ERROR)
		{
			printTypePassengers(listType, lenType);
			validType = Utn_GetInt(&auxListP.typePassenger,"Ingrese el tipo de pasajero: ","\nError.Dato invalido solo permite numeros.(1 - 4).\n",MIN_TYPE,MAX_TYPE,ATTEMPTS);
			validTypePass(listType, lenType,auxListP.typePassenger);
		}

		validFlycode = Utn_GetStringAlphanumeric(auxListP.flycode,TAM_FLYCODE,"Ingrese el codigo del vuelo: ","\nError.Dato invalido solo permite numeros, letras y solo 10 caracteres.\n",ATTEMPTS);
		validStatus = Utn_GetInt(&auxListP.statusFlight,"\n1 Activo - 2 Demorado - 3 Cancelado\nIngrese el estado de su vuelo: ","\nError.Dato invalido solo permite numeros.(1 - 3).\n",MIN_STATUS,MAX_STATUS,ATTEMPTS);


		if(!validName && !validLastName && !validPrice && !validFlycode && !validType && !validStatus)
		{
			auxListP.id = *pId;
			*auxList = auxListP;
			(*pId)++;
			Retorno = OK;

		}
	}

	return Retorno;
}

int addPassengers(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight)
{
	int Retorno = ERROR;
	int index;

	if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL && price > 0 && typePassenger > 0 && flycode != NULL && statusFlight > 0)
	{
		findPositionFree(list, len,&index);
		if(index != -1)
		{
			strcpy(list[index].name,name);
			strcpy(list[index].lastName,lastName);
			list[index].price = price;
			list[index].typePassenger = typePassenger;
			strcpy(list[index].flycode,flycode);
			list[index].statusFlight = statusFlight;
			list[index].id = id;
			list[index].isEmpty = OCCUPIED;
			Retorno = OK;
		}
		else
		{
			printf("No hay una posicion libre para cargar al pasajero\n");
		}
	}

	return Retorno;
}

int findPositionFree(Passenger* list, int len, int* pIndex)
{
	int Retorno = ERROR;

	if(list != NULL && len > 0 && pIndex != NULL)
	{
		*pIndex = ERROR;

		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty)
			{
				*pIndex = i;
				break;
			}
		}
		Retorno = OK;
	}

	return Retorno;
}

int findPassengerById(Passenger* list, int len, int id)
{
	int index = ERROR;

	if(list != NULL && len > 0 && id > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(!list[i].isEmpty && list[i].id == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int modifyPassenger(Passenger* list, int len, TypePassenger* listType, int lenType)
{
	int Retorno = ERROR;
	int id;
	int index;

	if(list != NULL && len > 0 && listType != NULL && lenType > 0)
	{
		Retorno = VALIDA;
		printf("\n                         *** MODIFICAR PASAJEROS ***        \n");
		printf("        -------------------------------------------------------------\n\n");

		printPassengers(list,len,listType,lenType);
		Utn_GetInt(&id,"Ingrese el id del pasajero a modificar: ","\nError.Dato invalido solo numeros.\n",MIN_ID,MAX_ID,ATTEMPTS);

		index = findPassengerById(list,len,id);

		if(index != ERROR)
		{
			printf("\n");
			onePassenger(&list[index],listType,lenType);

			if(!modifyPassengerById(list,len,index,listType,lenType))
			{
				Retorno = OK;
			}
		}
		else
		{
			printf("No se encontro el id seleccionado\n");
		}
	}

	return Retorno;
}

int modifyPassengerById(Passenger* list, int len, int index, TypePassenger* listType, int lenType)
{
	int Retorno = ERROR;
	char salir;
	Passenger auxList;
	int opcion;

	if(list != NULL && len > 0 && index >= 0 && listType != NULL && lenType > 0)
	{
		do{
			opcion = menuModificar();
			switch(opcion)
			{
			case 1:
				Utn_GetString(auxList.name,TAM_STRING,"Ingrese su nuevo nombre: ","\nError.Dato invalido solo permite letras.\n",ATTEMPTS);
				strcpy(list[index].name,auxList.name);
				Retorno = OK;
				break;
			case 2:
				Utn_GetString(auxList.lastName,TAM_STRING,"Ingrese su nuevo apellido: ","\nError.Dato invalido solo permite letras.\n",ATTEMPTS);
				strcpy(list[index].lastName,auxList.lastName);
				Retorno = OK;
				break;
			case 3:
				Utn_GetFloat(&auxList.price,"Ingrese el nuevo precio del vuelo: ","\nError.Dato invalido solo permite numeros (5000 - 450000).\n",MIN_PRICE,MAX_PRICE,ATTEMPTS);
				list[index].price = auxList.price;
				Retorno = OK;
				break;
			case 4:
				printTypePassengers(listType, lenType);
				Utn_GetInt(&auxList.typePassenger,"Ingrese el nuevo tipo de pasajero: ","\nError.Dato invalido solo permite numeros (1 - 4).\n",MIN_TYPE,MAX_TYPE,ATTEMPTS);
				if(validTypePass(listType, lenType, auxList.typePassenger) == OK)
				{
					list[index].typePassenger = auxList.typePassenger;
					Retorno = OK;
				}
				break;
			case 5:
				Utn_GetStringAlphanumeric(auxList.flycode,TAM_FLYCODE,"Ingrese el nuevo codigo del vuelo: ","\nError.Dato invalido.Fuera del rango.\n",ATTEMPTS);
				strcpy(list[index].flycode,auxList.flycode);
				Retorno = OK;
				break;
			case 6:
				salir = confirmacion("Desea salir del menu de modificacion? s - n: ");
				if(salir == 's')
				{
					printf("SALIDA EXITOSA\n");
				}
				break;
			default:
				printf("Opcion invalida solo de 1- 6\n");
				break;
			}

		}while(salir != 's' && Retorno != OK);
	}

	return Retorno;
}

int removePassenger(Passenger* list, int len, int id, TypePassenger* listType, int lenType)
{
	int Retorno = ERROR;
	int index;
	char confirma;

	if(list != NULL && len > 0 && id > 0 && listType != NULL && lenType > 0)
	{
		index = findPassengerById(list,len,id);
		if(index != ERROR)
		{
			printf("\n");
			onePassenger(&list[index],listType,lenType);
			confirma = confirmacion("\nDesea confirmar a dar de baja (s - n)?: ");

			if(confirma == 's')
			{
				list[index].isEmpty = FREE;
				Retorno = OK;
			}
		}
	}

	return Retorno;
}

int removePassengerById(Passenger* list, int len, TypePassenger* listType, int lenType)
{
	int Retorno = ERROR;
	int id;

	if(list != NULL && len > 0 && listType != NULL && lenType > 0)
	{
		Retorno = VALIDA;
		printf("\n                        *** DAR DE BAJA PASAJEROS ***    \n");
		printf("           ------------------------------------------------------\n\n");
		printPassengers(list,len,listType,lenType);

		Utn_GetInt(&id,"Ingrese el id del pasajero a dar de baja: ","\nError.Dato invalido solo numeros.\n",MIN_ID,MAX_ID,ATTEMPTS);

		if(!removePassenger(list,len,id,listType,lenType))
		{
			Retorno = OK;
		}
		else
		{
			printf("Baja cancelada por el usuario\n");
		}
	}

	return Retorno;
}

int printPassengers(Passenger* list, int length, TypePassenger* listType, int lenType)
{
	int Retorno = ERROR;
	int flag = ERROR;

	if(list != NULL && length > 0 && listType != NULL && lenType > 0)
	{
		printf("                          *** LISTA DE PASAJEROS ***\n\n");
		printf(" -------------------------------------------------------------------------------------------\n");
		printf(" | ID  |     NAME     | LASTNAME |  PRICE   |   FLYCODE   |  TYPEPASSENGER  | STATUSFLIGHT |\n");
		printf(" -------------------------------------------------------------------------------------------\n");
		for(int i=0; i<length; i++)
		{
			if(!list[i].isEmpty)
			{
				onePassenger(&list[i],listType,lenType);
				flag = OK;
				Retorno = OK;
			}
		}
		printf(" |_____|______________|__________|__________|_____________|_________________|______________|\n");

		if(flag == ERROR)
		{
			printf("\nNO HAY PASAJEROS REGISTRADOS.");
		}
		printf("\n\n");
	}
	return Retorno;
}

int onePassenger(Passenger* passenger, TypePassenger* listType, int lenType)
{
	int Retorno = ERROR;
	char status[20];
	char descriptionType[20];
	int validDescription;

	validDescription = loadDescriptionType(listType, lenType,passenger->typePassenger,descriptionType);

	if(passenger->statusFlight == 1)
	{
		strcpy(status,"Activo");
	}
	else if(passenger->statusFlight == 2)
	{
		strcpy(status,"Demorado");
	}
	else if(passenger->statusFlight == 3)
	{
		strcpy(status,"Cancelado");
	}
	if(passenger != NULL && listType != NULL && lenType > 0 && !validDescription && status != NULL)
	{
		printf(" | %-3d | %-12s | %-8s | %-8.2f |   %-6s    | %-15s |  %-10s  |\n",
				passenger->id,
				passenger->name,
				passenger->lastName,
				passenger->price,
				passenger->flycode,
				descriptionType,
				status);

		Retorno = OK;
	}

	return Retorno;
}

int altaForzadaPassengers(Passenger* list, int len, int* pId)
{
	int Retorno = ERROR;
	int index;
	int cant;
	int j = 0;

	Utn_GetInt(&cant,"Ingrese la cantidad que desea insertar entre (1 - 10): ","Error dato invalido solo numeros.\n",MIN,MAX,ATTEMPTS);

	Passenger altaPassengers[] =
	{
			{0,"Laura","Rufalo",5000.12,"aab1",1,1,0},
			{0,"Marcos","Alvarez",5500,"aef3",1,2,0},
			{0,"Octavio","Vargas",5700.23,"acd2",2,3,0},
			{0,"Manuel","Colque",6000.50,"aab3",4,3,0},
			{0,"Lois","Colque",10550.55,"aab2",2,3,0},
			{0,"Karen","Marc",12800.56,"aef4",2,1,0},
			{0,"Dori","Ponce",15800.34,"aac1",4,1,0},
			{0,"Lucas","Rufalo",20000,"aad3",2,1,0},
			{0,"Denis","Rufalo",19800.23,"aef3",3,2,0},
			{0,"Malcom","Fonci",6000.23,"acb1",1,2,0}
	};

	if(list != NULL && len > 0 && pId != NULL)
	{
		Retorno = OK;
		findPositionFree(list, len, &index);

		if(index != ERROR)
		{
			for(int i=index; i<(cant+index); i++)
			{
				list[i] = altaPassengers[j];
				list[i].id = *pId;
				(*pId)++;
				j++;
			}
		}
		else
		{
			Retorno = ERROR;
		}
	}

	return Retorno;
}

