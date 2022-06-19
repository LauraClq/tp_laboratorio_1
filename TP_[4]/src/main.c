/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/Menus.h"
#include "../inc/Defines.h"
#include "../inc/Controller.h"

int main(void)
{
	setbuf(stdout,NULL);
	//startTesting(1);  // ll_newLinkedList
	/* startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort*/

	int opcion;
	char salir;
	int carga = NADA;
	int lista;

	LinkedList* listEmpleados = ll_newLinkedList();

	do
	{
		opcion = menu();
		switch(opcion)
		{
		case 1:
			if(!carga)
			{
				controller_loadFromText("Empleados.csv",listEmpleados);
				carga = CARGO;
			}
			else
			{
				printf("Archivo empledos ya fue cargado\n\n");
			}
			break;
		case 2:
			if(!controller_addEmpleado(listEmpleados))
			{
				printf("Empleado dado de alta con exito!\n\n");
			}
			else
			{
				printf("Error en dar de alta empleado.\n\n");
			}
			break;
		case 3:
			lista = ll_isEmpty(listEmpleados);
			if(!lista)
			{
				if(!controller_editEmpleado(listEmpleados))
				{
					printf("Empleado modifcado con exito\n\n");
				}
				else
				{
					printf("Error en la modificacion del empleado.\n\n");
				}
			}
			else if(lista)
			{
				printf("Lista de empleados vacio. Tiene que dar de alta un empleado\n\n");
			}
			else
			{
				printf("Error en la validacion\n\n");
			}
			break;
		case 4:
			lista = ll_isEmpty(listEmpleados);
			if(!lista)
			{
				if(!controller_removePassenger(listEmpleados))
				{
					printf("Empleado dado de baja con exito!\n\n");
				}
				else
				{
					printf("Error en los parametros.\n\n");
				}
			}
			else if(lista)
			{
				printf("Lista de empleados vacio. Tiene que dar de alta un empleado\n\n");
			}
			else
			{
				printf("Error en la validacion\n\n");
			}
			break;
		case 5:
			lista = ll_isEmpty(listEmpleados);
			if(!lista)
			{
				controller_ListEmpleados(listEmpleados);
			}
			else if(lista)
			{
				printf("Lista de empleados vacio. Tiene que dar de alta un empleado\n\n");
			}
			else
			{
				printf("Error en la validacion\n\n");
			}
			break;
		case 6:
			if(!controller_subListEmpleados(listEmpleados))
			{
				printf("Recorte de la sublista exitosa!\n\n");
			}
			else
			{
				printf("Error en el recorte\n\n");
			}
			break;
		case 7:
			if(!controller_clearEmpleados(listEmpleados))
			{
				printf("Lista borrado con exito!\n\n");
			}
			else
			{
				printf("Error en el borrado.\n\n");
			}
			break;
		case 8:
			if(!controller_sortEmpleados(listEmpleados))
			{
				printf("Lista ordenada exitosamente\n\n");
			}
			else
			{
				printf("Ocurrio un error en el ordenamiento.\n\n");
			}
			break;
		case 9:
			if(!controller_cloneEmpleados(listEmpleados))
			{
				printf("Copia de la lista realiza con exito!\n\n");
			}
			else
			{
				printf("Error en la copia de la lista.\n\n");
			}
			break;
		case 10:
			if(!controller_reemplazarEmpleado(listEmpleados))
			{
				printf("Empleado reemplazo con exito!\n\n");
			}
			break;
		case 11:
			salir = confirmacion("Desea continuar en el programa? s - n: ");
			if(salir == 's')
			{
				printf("salida exitosa!\n");
				ll_deleteLinkedList(listEmpleados);
			}
			break;
		default:
			printf("Opcion invalida solo del 1 - 12\n");
			break;
		}

	}while(salir != 's');


}

































