/*
 * Parser.c
 *
 *  Created on: 18 jun 2022
 *      Author: laura
 */

#include "../inc/Parser.h"

int parser_EmpleadosFromText(FILE* pFile , LinkedList* pListEmpleados)
{

	eEmpleados* pEmpleados;
	int retorno = ERROR;
	int flag = CARGO;
	int cant;
	char buffer[5][20];

	if(pFile != NULL && pListEmpleados != NULL)
	{
		if(flag)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
			flag = NADA;
		}
		do
		{
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
			if(cant == 5)
			{
				pEmpleados = empleado_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

				if(!ll_add(pListEmpleados,pEmpleados))
				{
					retorno = OK;
				}
				else
				{
					empleado_delete(pEmpleados);
				}
			}
			else
			{
				break;
			}

		}while(!feof(pFile));
	}
	return retorno;
}
