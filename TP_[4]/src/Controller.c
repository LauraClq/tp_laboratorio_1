/*
 * Controller.c
 *
 *  Created on: 18 jun 2022
 *      Author: laura
 */

#include "../inc/Controller.h"

int controller_loadFromText(char* path , LinkedList* pListEmpleados)
{
	int retorno = ERROR;

	if(path != NULL && pListEmpleados)
	{
		FILE* pFile = fopen(path,"r");

		if(pFile != NULL && !parser_EmpleadosFromText(pFile,pListEmpleados))
		{
			printf("El archivo en modo texto se cargo con exito!\n");
			retorno = OK;
		}
		else
		{
			printf("Error al cargar el archivo en modo texto.");
		}

		fclose(pFile);
	}

	return retorno;
}

int controller_addEmpleado(LinkedList* pListEmpleados)
{
	eEmpleados* pEmpleado = empleados_new();
	int retorno = ERROR;
	char auxNombre[TAM_STRING];
	char auxApellido[TAM_STRING];
	float auxSueldo;
	int auxSector;
	int idActual;


	if(pListEmpleados != NULL && pEmpleado != NULL && !getId(&idActual))
	{
		if(!empleado_loadEmpleados(auxNombre,auxApellido,&auxSueldo,&auxSector))
		{
			if(!empleado_setterAll(pEmpleado,&idActual,auxNombre,auxApellido,auxSueldo,auxSector))
			{
				ll_add(pListEmpleados,pEmpleado);
				actualizarId(idActual);
				retorno = OK;
			}
			else
			{
				empleado_delete(pEmpleado);
				printf("Error en los setters\n");
			}
		}
		else
		{
			printf("Error en las validaciones\n");
		}

	}
	else
	{
		printf("Error\n");
	}

	return retorno;
}

int controller_editEmpleado(LinkedList* pListEmpleados)
{
	int retorno = ERROR;
	eEmpleados* pEmpleado;
	int auxId;
	int index;

	if(pListEmpleados != NULL)
	{
		printf("\n               *** MODIFICAR EMPLEADOS ***        \n");
		printf("      --------------------------------------------------\n\n");

		controller_ListEmpleados(pListEmpleados);
		Utn_GetInt(&auxId,"Ingrese el id que desea modificar: ","\nError, dato invalido\n",MIN_ID,MAX_ID,ATTEMPTS);

		index = empleado_searchById(pListEmpleados, auxId);

		if(index != ERROR)
		{
			pEmpleado = (eEmpleados*)ll_get(pListEmpleados, index);
			empleado_printfUnEmpleado(pEmpleado);

			if(confirmacion("\nDesea modifcar al empleado? s - n: ") == 's') //no se si es necesario
			{
				if(!empleado_editById(pEmpleado))
				{
					retorno = OK;
				}
			}

		}
		else
		{
			printf("Error no se encontro el id.");
		}
	}

	return retorno;
}

int controller_removePassenger(LinkedList* pListEmpleados)
{
	int retorno = ERROR;
	eEmpleados* pEmpleado = NULL;
	int auxId;
	int index;
	char confirma;

	if(pListEmpleados != NULL)
	{
		printf("\n              *** DAR DE BAJA UN EMPLEADO ***        \n");
		printf("      -------------------------------------------------\n\n");

		controller_ListEmpleados(pListEmpleados);
		Utn_GetInt(&auxId,"Ingrese el id a dar de baja: ","\nError, dato invalido\n",MIN_ID,MAX_ID,ATTEMPTS);

		index = empleado_searchById(pListEmpleados, auxId);

		if(index != ERROR)
		{
			pEmpleado = (eEmpleados*)ll_get(pListEmpleados, index);
			empleado_printfUnEmpleado(pEmpleado);

			confirma = confirmacion("\nDesea confirmar a dar de baja (s - n)?: ");
			if(ll_contains(pListEmpleados,pEmpleado) && confirma == 's')
			{
				pEmpleado = ll_pop(pListEmpleados,index);
				empleado_delete(pEmpleado);
				retorno = OK;
			}
			else
			{
				printf("No contiene al empleado o baja cancelada por el usuario.\n");
			}
		}
		else
		{
			printf("Error, el id ingresado no se encontro.\n");
		}

	}
	return retorno;
}


int controller_ListEmpleados(LinkedList* pListEmpleados)
{
	int retorno = ERROR;
	int tam;
	eEmpleados* pEmpleado = NULL;

	if(pListEmpleados != NULL)
	{
		tam = ll_len(pListEmpleados);

		printf("                *** LISTA DE EMPLEADOS ***\n\n");
		printf(" ---------------------------------------------------\n");
		printf(" | ID  |  NOMBRE  | APELLIDO |  SUELDO  |  SECTOR  |\n");
		printf(" ---------------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			pEmpleado = (eEmpleados*)ll_get(pListEmpleados, i);

			if(!empleado_printfUnEmpleado(pEmpleado))
			{
				retorno = OK;
			}
			else
			{
				printf("Error en la carga de datos");
			}
		}
		printf(" |_____|__________|__________|__________|___________|\n\n");
	}
	else
	{
		printf("Ocurrio un error.\n");
		empleado_delete(pEmpleado);
	}

	return retorno;
}

int controller_clearEmpleados(LinkedList* pListEmpleados)
{
	int retorno = ERROR;
	char confirma;

	if(pListEmpleados != NULL)
	{
		confirma = confirmacion("Desea borrar todos los empleados de la lista? s - n: ");
		if(confirma == 's')
		{
			if(!ll_clear(pListEmpleados))
			{
				retorno = OK;
			}
			else
			{
				printf("Ocurrio un error en los parametros.\n");
			}
		}
		else
		{
			printf("Borrado cancelado por el usuario.\n");
		}
	}


	return retorno;
}

int controller_subListEmpleados(LinkedList* pListEmpleados)//
{
	LinkedList* subListEmpelados;
	int retorno = ERROR;
	int tam;
	int to;
	int from;

	if(pListEmpleados != NULL)
	{
		tam = ll_len(pListEmpleados);
		subListEmpelados = ll_clone(pListEmpleados);

		controller_ListEmpleados(subListEmpelados);

		Utn_GetInt(&from,"Ingrese el id desde donde quiere que empieze la lista: ","\nError, dato invalido.\n",MIN_ID,tam,ATTEMPTS);
		Utn_GetInt(&to, "Ingrese el id hasta donde quiere que se termine la lista: ","\nError,dato invalido\n",from,tam,ATTEMPTS);

		if(!empleado_validId(pListEmpleados, from) && !empleado_validId(pListEmpleados, to))
		{
			subListEmpelados = ll_subList(pListEmpleados, from-1, to);
			controller_ListEmpleados(subListEmpelados);
			ll_deleteLinkedList(subListEmpelados);
			retorno = OK;
		}
		else
		{
			printf("Error en la validacion del id\n");
		}
	}

	return retorno;
}

int controller_sortEmpleados(LinkedList* pListEmpleados)
{
	int retorno = ERROR;
	char salir;
	int opcion;
	int order;

	if(pListEmpleados != NULL)
	{
		do
		{
			opcion = menuInformes();
			switch(opcion)
			{
			case 1:
				Utn_GetInt(&order,"De que forma desea ordenar? Ingrese 1 (Ascendente) o 0 (Descendente): ","\nError.Dato invalido solo numeros.\n",SORT_DESC,SORT_ASC,ATTEMPTS);
				if(!ll_sort(pListEmpleados,empleado_sortNombre,order))
				{
					controller_ListEmpleados(pListEmpleados);
					retorno = OK;
				}
				break;
			case 2:
				Utn_GetInt(&order,"De que forma desea ordenar? Ingrese 1 (Ascendente) o 0 (Descendente): ","\nError.Dato invalido solo numeros.\n",SORT_DESC,SORT_ASC,ATTEMPTS);
				if(!ll_sort(pListEmpleados,empleado_sortApellido,order))
				{
					controller_ListEmpleados(pListEmpleados);
					retorno = OK;
				}
				break;
			case 3:
				Utn_GetInt(&order,"De que forma desea ordenar? Ingrese 1 (Ascendente) o 0 (Descendente): ","\nError.Dato invalido solo numeros.\n",SORT_DESC,SORT_ASC,ATTEMPTS);
				if(!ll_sort(pListEmpleados,empleado_sortSueldo,order))
				{
					controller_ListEmpleados(pListEmpleados);
					retorno = OK;
				}
				break;
			case 4:
				salir = confirmacion("Desea salir del menu del informes? s- n: ");
				break;
			}

		}while(salir != 's' && retorno != OK);
	}

	return retorno;
}

int controller_cloneEmpleados(LinkedList* pListEmpleados)
{
	int retorno = ERROR;
	LinkedList* cloneListEmpelados;

	if(pListEmpleados != NULL)
	{
		cloneListEmpelados = ll_clone(pListEmpleados);

		if(cloneListEmpelados != NULL)
		{
			if(ll_containsAll(pListEmpleados,cloneListEmpelados))
			{
				controller_ListEmpleados(cloneListEmpelados);
				retorno = OK;
			}
		}
	}

	return retorno;
}

int controller_reemplazarEmpleado(LinkedList* pListEmpleados)
{
	int retorno = ERROR;
	eEmpleados* pEmpleado = NULL;
	eEmpleados* pAuxEmpleado;
	int tam;
	int IdElegido;
	int indice;
	int idAux;
	char auxNombre[TAM_STRING];
	char auxApellido[TAM_STRING];
	float auxSueldo;
	int auxSector;
	char confirma;

	if(pListEmpleados != NULL)
	{
		tam = ll_len(pListEmpleados);
		controller_ListEmpleados(pListEmpleados);

		Utn_GetInt(&IdElegido,"Ingrese el id que quiere reemplazar: ","\nError dato invalido\n",MIN_ID,tam,ATTEMPTS);

		indice = empleado_searchById(pListEmpleados, IdElegido);
		pAuxEmpleado = ll_get(pListEmpleados, indice);

		if(ll_contains(pListEmpleados,pAuxEmpleado) && pAuxEmpleado != NULL)
		{
			confirma = confirmacion("Desea continuar con el reemplazo? s - n: ");
			if(confirma == 's')
			{
				pEmpleado = empleados_new();
				if(!empleado_loadEmpleados(auxNombre, auxApellido, &auxSueldo, &auxSector)&& !actualizarId(idAux))
				{

					empleado_setId(pEmpleado, &idAux);
					empleado_setNombre(pEmpleado, auxNombre);
					empleado_setApellido(pEmpleado, auxApellido);
					empleado_setSueldo(pEmpleado, auxSueldo);
					empleado_setSector(pEmpleado, auxSector);

					if(!ll_set(pListEmpleados,ll_indexOf(pListEmpleados,pAuxEmpleado),pEmpleado)&& !getId(&idAux))
					{
						controller_ListEmpleados(pListEmpleados);
						retorno = OK;
					}
					else
					{
						printf("Ocuurio un error\n");
					}
				}
				else
				{
					printf("Error en las validaciones.\n");
				}

			}
			else
			{
				printf("No contiene al elemento.\n");
			}
		}
	}
	return retorno;
}
