/*
 * Empledos.c
 *
 *  Created on: 18 jun 2022
 *      Author: laura
 */

#include "../inc/Empleados.h"

eEmpleados* empleados_new()
{
	eEmpleados* nuevoEmpleado = (eEmpleados*) calloc(1,sizeof(eEmpleados));
	return nuevoEmpleado;
}

eEmpleados* empleado_newParametros(char* id,char* nombre,char* apellido,char* sueldo,char* sector)
{
	eEmpleados* nuevoEmpleado = empleados_new();
	int auxId;

	if(nuevoEmpleado != NULL && id != NULL && nombre != NULL && apellido != NULL && sueldo != NULL)
	{
		auxId = atoi(id);

		if(!(empleado_setId(nuevoEmpleado,&auxId) && empleado_setNombre(nuevoEmpleado,nombre) &&
				empleado_setApellido(nuevoEmpleado,apellido) && empleado_setSueldo(nuevoEmpleado,atof(sueldo)) &&
				empleado_setSector(nuevoEmpleado,atoi(sector))) )
		{
			empleado_delete(nuevoEmpleado);
			nuevoEmpleado = NULL;
		}
	}

	return nuevoEmpleado;
}

void empleado_delete(eEmpleados* empleado)
{
	free(empleado);
}

int empleado_setId(eEmpleados* empleado,int* id)
{
	int retorno = ERROR;

	if(empleado != NULL && id > 0)
	{
		empleado->id = *id;
		retorno = OK;
	}
	return retorno;
}

int empleado_getId(eEmpleados* empleado,int* pId)
{
	int retorno = ERROR;

	if(empleado != NULL && pId != NULL)
	{
		*pId = empleado->id;
		retorno = OK;
	}
	return retorno;
}

int empleado_setNombre(eEmpleados* empleado,char* nombre)
{
	int retorno = ERROR;

	if(empleado != NULL && nombre != NULL && strlen(nombre) < 50 && strlen(nombre) >= 2)
	{
		strcpy(empleado->nombre, nombre);
		strlwr(empleado->nombre);
		(empleado->nombre)[0] = toupper((empleado->nombre)[0]);
		retorno = OK;
	}
	return retorno;
}

int empleado_getNombre(eEmpleados* empleado,char* nombre)
{
	int retorno = ERROR;

	if(empleado != NULL && nombre != NULL)
	{
		strcpy(nombre, empleado->nombre);
		retorno = OK;
	}
	return retorno;
}

int empleado_setApellido(eEmpleados* empleado,char* apellido)
{
	int retorno = ERROR;

	if(empleado != NULL && apellido != NULL && strlen(apellido) < 50 && strlen(apellido) >= 2)
	{
		strcpy(empleado->apellido, apellido);
		strlwr(empleado->apellido);
		(empleado->apellido)[0] = toupper((empleado->apellido)[0]);
		retorno = OK;
	}
	return retorno;
}

int empleado_getApellido(eEmpleados* empleado,char* apellido)
{
	int retorno = ERROR;

	if(empleado != NULL && apellido != NULL)
	{
		strcpy(apellido,empleado->apellido);
		retorno = OK;
	}
	return retorno;
}

int empleado_setSueldo(eEmpleados* empleado,float sueldo)
{
	int retorno = ERROR;

	if(empleado != NULL && sueldo >= MIN_PRICE && sueldo <= MAX_PRICE)
	{
		empleado->sueldo = sueldo;
		retorno = OK;
	}
	return retorno;
}

int empleado_getSueldo(eEmpleados* empleado,float* sueldo)
{
	int retorno = ERROR;

	if(empleado != NULL && sueldo != NULL)
	{
		*sueldo = empleado->sueldo;
		retorno = OK;
	}
	return retorno;
}

int empleado_setSector(eEmpleados* empleado,int sector)
{
	int retorno = ERROR;

	if(empleado != NULL && sector >= MIN_SECT && sector <= MAX_SECT)
	{
		empleado->sector = sector;
		retorno = OK;
	}
	return retorno;
}

int empleado_getSector(eEmpleados* empleado,int* sector)
{
	int retorno = ERROR;

	if(empleado != NULL && sector != NULL)
	{
		*sector = empleado->sector;
		retorno = OK;
	}
	return retorno;
}

int getId(int* id)
{
	int retorno = ERROR;
	char idStr[50];
	*id = 1;
	FILE* pFile = fopen("LastId.txt","r");

	if(pFile != NULL)
	{
		fscanf(pFile,"%[^\n]",idStr);
		*id = atoi(idStr);
		retorno = OK;
	}
	else
	{
		pFile = fopen("LastId.txt", "w");
		fprintf(pFile, "%d\n",*id);
		retorno = OK;
	}

	fclose(pFile);

	return retorno;
}

int actualizarId(int id)
{
	int retorno = ERROR;

	FILE* pFile=fopen("LastId.txt", "w");

	if(pFile != NULL)
	{
		fprintf(pFile, "%d\n", id+1);
		retorno = OK;
	}
	fclose(pFile);

	return retorno;

}

int empleado_loadEmpleados(char* nombre, char* apellido, float* sueldo, int* sector)
{
	int retorno = ERROR;
	char auxNombre[TAM_STRING];
	char auxApellido[TAM_STRING];
	float auxSueldo;
	int auxSector;

	if(nombre != NULL && apellido != NULL && sueldo != NULL && sector != NULL)
	{
		if( !Utn_GetString(auxNombre,TAM_STRING,"Ingrese su nombre: ","\nError, dato invalido solo letras.\n",ATTEMPTS) &&
				!Utn_GetString(auxApellido,TAM_STRING,"Ingrese su apellido: ","\nError, dato invalido solo letras.\n",ATTEMPTS) &&
				!Utn_GetFloat(&auxSueldo,"Ingrese su sueldo (5000 - 20000): ","\nError, dato invalido.\n",MIN_PRICE,MAX_PRICE,ATTEMPTS) &&
				!Utn_GetInt(&auxSector,"\n1 Ventas - 2 RRHH - 3 Sistemas - 4 Contable\nIngrese al sector que pertenece: ","\nError, dato invalido solo de (1 - 4).\n",MIN_SECT,MAX_SECT,ATTEMPTS) )
		{
			strcpy(nombre,auxNombre);
			strcpy(apellido,auxApellido);
			*sueldo = auxSueldo;
			*sector = auxSector;
			retorno = OK;
		}
	}

	return retorno;
}

int empleado_setterAll(eEmpleados* empleado,int* id, char* nombre, char* apellido, float sueldo, int sector)
{
	int retorno = ERROR;

	if(empleado != NULL && id != NULL && nombre != NULL && apellido != NULL)
	{
		empleado_setId(empleado, id);
		empleado_setNombre(empleado, nombre);
		empleado_setApellido(empleado, apellido);
		empleado_setSueldo(empleado, sueldo);
		empleado_setSector(empleado, sector);

		retorno = OK;
	}

	return retorno;
}

int empleado_searchById(LinkedList* pListEmpleados, int id)
{
	int retorno = ERROR;
	eEmpleados* pEmpelado;
	int len;
	int idAux;

	if(pListEmpleados != NULL && id > 0)
	{
		len = ll_len(pListEmpleados);

		for(int i=0; i<len; i++)
		{
			pEmpelado = ll_get(pListEmpleados, i);

			if(!empleado_getId(pEmpelado,&idAux) && idAux == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int empleado_validId(LinkedList* pListEmpleados, int id)
{
	int retorno = ERROR;
	int index;

	if(pListEmpleados != NULL && id > 0)
	{
		index = empleado_searchById(pListEmpleados, id);
		if(index != ERROR)
		{
			retorno = OK;
		}
	}

	return retorno;
}

int empleado_sortNombre(void* empleadoA, void* empleadoB)
{
	int criterio = 0;
	char nombreA[100];
	char nombreB[100];

	eEmpleados* auxEmpleadoA;
	eEmpleados* auxEmpleadoB;

	if(empleadoA != NULL && empleadoB != NULL)
	{
		auxEmpleadoA = (eEmpleados*) empleadoA;
		auxEmpleadoB = (eEmpleados*) empleadoB;

		empleado_getNombre(auxEmpleadoA,nombreA);
		empleado_getNombre(auxEmpleadoB,nombreB);

		if(strcmp(nombreA,nombreB) > 0)
		{
			criterio = 1;
		}
		else if(strcmp(nombreA,nombreB) < 0)
		{
			criterio = -1;
		}
	}
	return criterio;
}

int empleado_sortApellido(void* empleadoA, void* empleadoB)
{
	int criterio = 0;
	char apellidoA[100];
	char apellidoB[100];

	eEmpleados* auxEmpleadoA;
	eEmpleados* auxEmpleadoB;

	if(empleadoA != NULL && empleadoB != NULL)
	{
		auxEmpleadoA = (eEmpleados*) empleadoA;
		auxEmpleadoB = (eEmpleados*) empleadoB;

		empleado_getApellido(auxEmpleadoA, apellidoA);
		empleado_getApellido(auxEmpleadoB, apellidoB);

		if(strcmp(apellidoA,apellidoB) > 0)
		{
			criterio = 1;
		}
		else if(strcmp(apellidoA,apellidoB) < 0)
		{
			criterio = -1;
		}
	}
	return criterio;
}

int empleado_sortSueldo(void* empleadoA, void* empleadoB)
{
	int criterio = ERROR;
	float sueldoA;
	float sueldoB;

	eEmpleados* auxEmpleadoA;
	eEmpleados* auxEmpleadoB;

	if(empleadoA != NULL && empleadoB != NULL)
	{
		auxEmpleadoA = (eEmpleados*) empleadoA;
		auxEmpleadoB = (eEmpleados*) empleadoB;

		empleado_getSueldo(auxEmpleadoA, &sueldoA);
		empleado_getSueldo(auxEmpleadoB, &sueldoB);

		if(sueldoA > sueldoB)
		{
			criterio = SORT_ASC;
		}
		else if(sueldoA < sueldoB)
		{
			criterio = SORT_DESC;
		}
	}
	return criterio;
}

int empleado_editById(eEmpleados* pEmpleado)
{
	int retorno = ERROR;
	int opcion;
	char salir;
	int valida;
	char auxNombre[TAM_STRING];
	char auxApellido[TAM_STRING];
	float auxSueldo;
	int auxSector;

	if(pEmpleado != NULL)
	{
		do
		{
			opcion = menuModificar();
			switch(opcion)
			{
			case 1:
				valida = Utn_GetString(auxNombre,TAM_STRING,"Ingrese su nuevo nombre: ","\nError, dato invalido solo de letras.\n",ATTEMPTS);
				if(!valida && !empleado_setNombre(pEmpleado, auxNombre))
				{
					retorno = OK;
				}
				break;
			case 2:
				valida = Utn_GetString(auxApellido,TAM_STRING,"Ingrese su nuevo apellido: ","\nError, dato invalido solo de letras.\n",ATTEMPTS);
				if(!valida && !empleado_setApellido(pEmpleado, auxApellido))
				{
					retorno = OK;
				}
				break;
			case 3:
				valida = Utn_GetFloat(&auxSueldo,"Ingrese el nuevo sueldo: ","\nError.Dato invalido solo permite numeros (5000 - 20000).\n",MIN_PRICE,MAX_PRICE,ATTEMPTS);
				if(!valida && !empleado_setSueldo(pEmpleado, auxSueldo))
				{
					retorno = OK;
				}
				break;
			case 4:
				printf("1- Ventas\n2- RRHH\n3- Sistemas\n4- Contable\n");
				valida = Utn_GetInt(&auxSector,"Ïngrese el nuevo sector","\nError, dato invalido solo de 1 - 4\n",MIN_SECT,MAX_SECT,ATTEMPTS);
				if(!valida && !empleado_setSector(pEmpleado, auxSector))
				{
					retorno = OK;
				}
				break;
			case 5:
				salir = confirmacion("Desea salir del menu de modificacion? s - n: ");
				retorno = OK;
				break;
			default:
				printf("Ërror, solo opciones del 1 - 5\n");
				break;
			}

		}while(salir != 's' && retorno != OK);
	}

	return retorno;
}
int empleado_printfUnEmpleado(eEmpleados* unEmpleado)
{
	int retorno = ERROR;
	int auxId;
	char auxNombre[TAM_STRING];
	char auxApellido[TAM_STRING];
	float auxSueldo;
	int auxSector;

	char descripSector[TAM_STRING];

	if(unEmpleado != NULL)
	{
		empleado_getId(unEmpleado, &auxId);
		empleado_getNombre(unEmpleado, auxNombre);
		empleado_getApellido(unEmpleado, auxApellido);
		empleado_getSueldo(unEmpleado, &auxSueldo);
		empleado_getSector(unEmpleado, &auxSector);
		empleado_DescripSector(auxSector, descripSector);

		printf(" | %-3d | %-8s | %-8s | %-8.2f |%-10s|\n",auxId,auxNombre,auxApellido,auxSueldo,descripSector);

		retorno = OK;
	}

	return retorno;
}

int empleado_DescripSector(int sector, char* descripcion)
{
	int retorno = ERROR;

	if(descripcion != NULL)
	{
		switch(sector)
		{
		case 1:
			strcpy(descripcion,"Ventas");
			break;
		case 2:
			strcpy(descripcion,"RRHH");
			break;
		case 3:
			strcpy(descripcion,"Sistemas");
			break;
		case 4:
			strcpy(descripcion,"Contable");
			break;
		}
		retorno = OK;
	}

	return retorno;
}
