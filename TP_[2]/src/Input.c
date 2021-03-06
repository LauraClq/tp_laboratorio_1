/*
 * Input.c
 *
 *  Created on: 28 may 2022
 *      Author: Laura
 */
#include "Input.h"
#include <ctype.h>

int Utn_GetInt(int* refInt,char message[], char errorMessage[], int min ,int max, int attempts)
{
	int retorno = ERROR;
	int auxInt;

	if(refInt != NULL && message != NULL && errorMessage != NULL && min <= max  && attempts >= 0)
	{
		do
		{
			printf("%s",message);

			if(GetInt(&auxInt) == OK && auxInt >= min && auxInt <= max)
			{
				*refInt = auxInt;
				retorno = OK;
				break;
			}
			else
			{
				printf("%s",errorMessage);
				attempts--;
			}

		}while(attempts >= 0);

	}

	return retorno;
}

int Utn_GetFloat(float* refFloat,char message[], char errorMessage[], int min ,int max, int attempts)
{
	int retorno = ERROR;
	float auxFloat;

	if(refFloat != NULL && message != NULL && errorMessage != NULL && min <= max && attempts >= 0)
	{
		do
		{
			printf("%s",message);
			if(GetFloat(&auxFloat) == OK && auxFloat >= min && auxFloat <= max)
			{
				*refFloat = auxFloat;
				retorno = OK;
				break;
			}
			else
			{
				printf("%s",errorMessage);
				attempts--;
			}

		}while(attempts >= 0);
	}

	return retorno;
}

int GetString(char* refAux, int limit)
{
	char auxString[256];
	int retorno = ERROR;

	if(refAux != NULL && limit > 0)
	{
		fflush(stdin);
		fgets(auxString,sizeof(auxString),stdin);

		if(auxString[strlen(auxString) - 1] == '\n')
		{
			auxString[strlen(auxString) - 1] = '\0';
		}

		if(strlen(auxString) <= limit)
		{
			strncpy(refAux,auxString,limit);
			retorno = OK;
		}
	}

	return retorno;
}

int IsInt(char* refAux)
{
	int retorno = ERROR;
	int i = 0;

	do
	{
		if(*(refAux + i) < 48 || *(refAux + i) > 57)
		{
			break;
		}

		i++;
	}
	while (i < strlen(refAux));
	if(i == strlen(refAux))
	{
		retorno = OK;
	}

	return retorno;
}

int GetInt(int* refAux)
{
	char auxString[256];
	int retorno = ERROR;

	if(GetString(auxString, 256) == OK && IsInt(auxString) == OK)
	{
		*refAux = atoi(auxString);
		retorno = OK;
	}

	return retorno;
}

int IsFloat(char* refAux)
{
	int retorno = ERROR;
	int i = 0;
	int dots = 0;

	do
	{
		if(*(refAux + i) == '.')
		{
			dots++;

			if(dots == 2)
			{
				break;
			}
		}
		else
		{
			if(*(refAux + i) < 48 || *(refAux + i) > 57)
			{
				break;
			}
		}

		i++;

	}while (i < strlen(refAux));

	if(i == strlen(refAux))
	{
		retorno = OK;
	}

	return retorno;
}

int GetFloat(float* refAux)
{
	char auxString[256];
	int retorno = ERROR;

	if(GetString(auxString,200) == OK && IsFloat(auxString) == OK)
	{
		*refAux = atof(auxString);
		retorno = OK;
	}

	return retorno;
}

int Utn_GetString(char* refAux, int limit, char message[], char errorMessage[], int attempts)
{
	int retorno = ERROR;
	char auxString[limit];

	if(refAux != NULL && limit > 0 && attempts >= 0)
	{
		do
		{
			printf("%s", message);

			if(GetString(auxString,limit) == OK && IsChar(auxString) == OK)
			{
				strncpy(refAux,auxString,limit);
				retorno = OK;
				break;
			}
			else
			{
				printf("%s",errorMessage);
				attempts--;
			}

		}while(attempts > 0);
	}

	return retorno;
}

int IsChar(char* refAux)
{
	int retorno = ERROR;
	int i = 0;

	if(refAux != NULL)
	{
		do
		{
			if((*(refAux + i) < 65 || *(refAux + i) > 90) && (*(refAux + i) < 97||*(refAux + i) > 122) && *(refAux + i) != '\0')
			{
				break;
			}
			i++;

		}while(i < strlen(refAux));

		if(i == strlen(refAux))
		{
			retorno = OK;
		}

	}

	return retorno;
}

int Utn_GetStringAlphanumeric(char* refAux, int limit, char message[], char errorMessage[], int attempts)
{
	int retorno = ERROR;
	char auxString[limit];

	if(refAux != NULL && limit > 0 && attempts >= 0)
	{
		do
		{
			printf("%s", message);

			if(GetString(auxString,limit) == OK && esAlfaNumerico(auxString) == OK)
			{
				strupr(auxString);//
				strncpy(refAux,auxString,limit);
				retorno = OK;
				break;
			}
			else
			{
				printf("%s",errorMessage);
				attempts--;
			}

		}while(attempts > 0);
	}

	return retorno;
}

int esAlfaNumerico(char* refAux)
{
	int retorno = ERROR;
	int i = 0;

	if(refAux != NULL)
	{
		do
		{
			if((*(refAux + i) < 65 || *(refAux + i) > 90) && (*(refAux + i) < 97||*(refAux + i) > 122) && *(refAux + i) != '\0' && (*(refAux + i) < 48 || *(refAux + i) > 57) )
			{
				break;
			}

			i++;

		}while(i < strlen(refAux));

		if(i == strlen(refAux))
		{
			retorno = OK;
		}
	}

	return retorno;
}

char confirmacion(char mensaje[])
{
	char confirma;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&confirma);

	confirma = tolower(confirma);

	while(confirma != 's' && confirma != 'n')
	{
		printf("Error. Ingrese s o n : ");
		fflush(stdin);
		scanf("%c",&confirma);
		confirma = tolower(confirma);
	}

	return confirma;
}

int Utn_GetStringName(char message[],char errorMessage[], char errorMessageLenght[],char* refAux, int lowLimit,int maxLenght)
{
    int retorno = ERROR;
    char buffer[999];

    while(1)
    {
        if(getStringCharacters(message,buffer) == ERROR)
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        if(strlen(buffer) > maxLenght || strlen(buffer) < lowLimit)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno = OK;
        strcpy(refAux,buffer);
        break;

    }

     return retorno;
}

int getStringCharacters(char mensaje[],char* refAux)
{
    char aux[750];

    getString(mensaje,aux);

    if(sonLetras(aux))
    {
        strcpy(refAux,aux);
        return OK;
    }
    return ERROR;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    fgets(input,200,stdin);
    limpiarEnter(input,200);
}

int limpiarEnter(char input[], int tam)
{
    int retorno = ERROR;

    if(input != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(input[i] == '\n')
            {
            	input[i] = '\0';
                break;
            }
        }
        retorno = OK;
    }
    return retorno;
}

int sonLetras(char str[])
{
   int i=0;
   str = strlwr(str);

   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       if(i == 0)
       {
    	   str[i] = toupper(str[i]);
       }
       else if(str[i] == ' ')
       {
    	  str[i+1] = toupper(str[i+1]);
       }
       i++;
   }
   return 1;
}
