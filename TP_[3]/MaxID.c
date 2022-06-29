/*
 * MaxID.c
 *
 *  Created on:  jun 2022
 *      Author: laura
 */

#include "MaxID.h"

int saveId()
{
	int lastID = 1;
	char lastIdStr[100];

	FILE* pFile = fopen("LastID.txt","r");

	if(pFile != NULL)
	{
		fscanf(pFile,"%[^\n]",lastIdStr);
		lastID = atoi(lastIdStr);

	}
	else
	{
		pFile = fopen("LastID.txt","w");
		fprintf(pFile,"%d\n",lastID);
	}

	fclose(pFile);

	return lastID;
}

int nextId(int idActual)
{
	int retorno = ERROR;

	FILE* pFile = fopen("LastID.txt","w");

	if(pFile != NULL)
	{
		fprintf(pFile,"%d\n",idActual+1);
		fclose(pFile);
		retorno = OK;
	}

	return retorno;
}
