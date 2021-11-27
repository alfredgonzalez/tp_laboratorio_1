
#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"
#include "Biblio.h"
#include <ctype.h>
#include "parser.h"
#include <string.h>

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* pFile;

	if ( path != NULL && pArrayListEmployee != NULL )
	{
	     system("cls");
	     printf("Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");

	     pFile = fopen( path, "r");
	     if ( pFile == NULL )
	     {
	         printf("No se pudo abrir el archivo\n");
	     }
	     else
	     {
	         if (parser_EmployeeFromText(pFile, pArrayListEmployee))
	         {
	             printf( "Carga de archivo de texto exitosa\n" );
	             todoOk = 1;
	         }
	     }
	 }
	 fclose(pFile);
	 return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk  = 0;
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		system("cls");
		printf("CARGAR DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.BIN(modo bin).\n");
		pFile = fopen(path,"rb");
		if(pFile == NULL)
		{
			printf("Error al abrir el archivo\n");
		}
		else
		{
			if(parser_EmployeeFromBinary(pFile,pArrayListEmployee))
			{
				printf("Datos cargados correctamente\n");
				todoOk = 1;
			}
		}
	}
	fclose(pFile);
	return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* newEmpleado = NULL;
		char nombre[60];
		int horas;
		int sueldo;
		int todoOk = 0;
		int id;
		if(pArrayListEmployee != NULL)
		{

			id = controller_IdSiguiente(pArrayListEmployee);
			id++;
			ingresarString("Ingrese su nombre ", nombre);
			while(validarLargoString(nombre,1, 19))
			{
					printf("Error noombre invalido (no se puede ingresar mas de 19 caracteres) \n");
			}
			horas = ingresarEntero("Ingresar horas trabajadas : ");
			while(horas < 0 )
			{
				horas = ingresarEntero("Error... reingrese nuevamente horas trabajadas : ");
			}
			sueldo = ingresarEntero("Ingresar sueldo : ");
			while(sueldo < 0 )
			{
				sueldo = ingresarEntero("Error... reingrese nuevamente el sueldo : ");
			}


			newEmpleado = employee_new();
			if(newEmpleado != NULL)
			{
				if(employee_setId(newEmpleado,(id))&& employee_setNombre(newEmpleado,nombre)&& employee_setHorasTrabajadas(newEmpleado,horas)&& employee_setSueldo(newEmpleado,sueldo))
				{
					printf("\n----Empleado cargado con exito----\n");
					ll_add(pArrayListEmployee,newEmpleado);
				}
				else
				{
					free(newEmpleado);
					printf("\n--Error al cargar el empleado--\n");
				}
			}

			todoOk = 1;
		}
		else
		{
			printf("----Error en el espacio en memoria----\n");

		}

		return todoOk;
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int idIngresado;//Por el usuario
		int indice = -1;//
		Employee* auxEmployee = NULL;
		char nombre[128];
		int sueldo;
		int horas;
		int opcion;
		int todoOk = 0;
		if(pArrayListEmployee != NULL)
		{
			controller_ListEmployee(pArrayListEmployee);
			idIngresado = ingresarEntero("Ingresa ID: ");
			while(idIngresado < 0 )
			{
				idIngresado = ingresarEntero("Error ID invalido. Ingresa ID: ");

			}

			auxEmployee = controller_searchEmployeeID(pArrayListEmployee,idIngresado,&indice);
			if(indice != -1)
			{

				do
				{
				system("cls");
				printf("\nModificacion de datos de empleado\n   ID     Nombre        Horas Trabajadas    Sueldo\n");
				controller_showEmployee(auxEmployee);
				printf("\n 1. Nombre\n2. Horas Trabajadas\n3. Sueldo\n4. Salir \n");
				opcion = ingresarEntero("Ingresa opcion :  ");
				while(opcion < 1 || opcion > 4 )
				{
					printf("\n 1. Nombre\n2. Horas Trabajadas\n3. Sueldo\n4. Salir \n");
					opcion = ingresarEntero("Error . Ingresa opcion :  ");
				}
				printf("\nModificacion de datos de empleado\n   ID     Nombre        Horas Trabajadas    Sueldo\n");

				controller_showEmployee(auxEmployee);
				switch(opcion)
				{
				case 1:
					ingresarString("Ingresa el nombre : ", nombre);
					while(validarLargoString(nombre,1, 19))
					{
						printf("Error noombre invalido (no se puede ingresar mas de 19 caracteres) \n");
					}
					employee_setNombre(auxEmployee,nombre);
					break;
				case 2:
					horas = ingresarEntero("Ingresar horas trabajadas : ");
					while(horas < 0 )
					{
						horas = ingresarEntero("Error... reingrese nuevamente horas trabajadas : ");
					}
					employee_setHorasTrabajadas(auxEmployee,horas);
					break;
				case 3:
					sueldo = ingresarEntero("Ingresar sueldo : ");
					while(sueldo < 0 )
					{
						sueldo = ingresarEntero("Error... reingrese nuevamente el sueldo : ");
					}
					employee_setSueldo(auxEmployee,sueldo);
					break;
				case 4:
					printf("Cambios realizados correctamente\n");
					break;
				default:
					printf("Error \n");
					break;
				}
			}while(opcion != 4);

			todoOk = 1;
		}
		else
		{

			printf("------Empleado con el id %d no existe-------\n",idIngresado);
			todoOk = -1;
		}
	}

	return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int idIngresado;//Por el usuario
	int indice = -1;//
	Employee* auxEmployee = NULL;
	char confirm;
	int todoOk = 0;
	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		idIngresado = ingresarEntero("Ingresa ID: ");
		while(idIngresado < 0 )
		{
			idIngresado = ingresarEntero("Error el ID ingresado es invalido. Ingresa ID: ");

		}

		auxEmployee = controller_searchEmployeeID(pArrayListEmployee,idIngresado,&indice);

		if(indice != -1)
		{
			printf("\n 						  Empleado a remover \n");
			printf("--------------------------------------------------------------------------\n");
			printf(" ID         NOMBRE            HORAST              SUELDO        \n");
			printf("---------------------------------------------------------------------------\n");
			controller_showEmployee(auxEmployee);
			printf("Queres remover a este empleado? s/n: ");
			fflush(stdin);
			scanf(" %c",&confirm);
			confirm = tolower(confirm);
			if(confirm == 's')
			{
				if(ll_remove(pArrayListEmployee,indice) == 0)
				{
					printf("--- Empleado removido con exito ---\n");
				}
				employee_delete(auxEmployee);
				}
				else
				{
					printf("-- Error al eliminar el empleado --\n");
				}

				todoOk = 1;
			}
			else
			{

				printf("--- Empleado con el id %d no existe. ---\n",idIngresado);
				todoOk = -1;
			}
		}
	return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

	Employee* pEmpAux = NULL;
	int todoOk = 0;
	int tam;

	if(pArrayListEmployee != NULL)
	{
		tam =  ll_len(pArrayListEmployee);
		system("cls");
		printf("-------------------------Lista de Empleados-----\n");
		printf("--------------------------------------------------------------------------\n");
		printf(" ID         NOMBRE            HORAST              SUELDO         \n");
		printf("---------------------------------------------------------------------------\n");
		for(int i = 0; i < tam; i++)
		{
			pEmpAux = ll_get(pArrayListEmployee,i);
			controller_showEmployee(pEmpAux);

		}
		todoOk =1;
	}
	return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int opcion;
	int orden;
	if (pArrayListEmployee != NULL)
	{
		todoOk = 1;
		printf("Ordenar empleados\n");
		orden = ingresarEntero("Orden ascendente o descendente : 0 Descendente, 1 Ascendente ");
		while(orden < 0 || orden > 1)
		{
			orden = ingresarEntero("Error... Orden ascendente o descendente : 0 Descendente, 1 Ascendente ");
		}

		opcion = ingresarEntero("Ingresar opcion: 1.Ordenar por Id, 2.Ordenar por Nombre, 3.Ordenar por Horas, 4.Ordenar por sueldo, 5.Salir");
		while(opcion < 1 || opcion > 5)
		{
			opcion = ingresarEntero("Ingresar opcion: 1.Ordenar por Id, 2.Ordenar por Nombre, 3.Ordenar por Horas, 4.Ordenar por sueldo, 5.Salir");
		}
		system("cls");
		switch (opcion)
		{
		case 1:
			printf("ORDENADO POR ID");
			ll_sort( pArrayListEmployee, controller_CompararId, orden);
			controller_ListEmployee(pArrayListEmployee);
			break;
		case 2:
			printf("ORDENADO POR NOMBRE");
			ll_sort( pArrayListEmployee, controller_CompararNombre, orden);
			controller_ListEmployee(pArrayListEmployee);
			break;
		case 3:
			printf("ORDENADO POR HORAS TRABAJADAS");
			ll_sort( pArrayListEmployee,controller_CompararHorasT,orden);
			controller_ListEmployee(pArrayListEmployee);
			break;
		case 4:
			printf("ORDENADO POR SUELDO");
			ll_sort( pArrayListEmployee, controller_CompararSueldo,orden);
			controller_ListEmployee(pArrayListEmployee);
			break;
		case 5:
			printf("Ordenado correctamente \n");
			break;
		default:
			printf("Opcion invalida\n");
			break;
		}
	}
	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* pFile;
	int id;
	char nombre[50];
	int horasT;
	int sueldo;
	Employee* auxEmpleado;

	if ( path != NULL && pArrayListEmployee != NULL )
	{
		pFile = fopen(path, "w");
		if (pFile == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}

		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

		for (int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i);
			if ( employee_getId(auxEmpleado, &id) &&
				employee_getNombre(auxEmpleado, nombre) &&
				employee_getHorasTrabajadas(auxEmpleado, &horasT) &&
				employee_getSueldo(auxEmpleado, &sueldo)
				)
				{
					fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasT, sueldo);
					todoOk = 1;
				}
			}
		}
	fclose(pFile);
	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* pFile;
	Employee* auxEmpleado;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "wb");
		if (pFile == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}

		for (int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i);
			if ((auxEmpleado) != NULL)
			{
				fwrite(auxEmpleado, sizeof(Employee), 1, pFile);
				todoOk = 1;
			}
		}
	}
	fclose(pFile);
	return todoOk;
}

Employee* controller_searchEmployeeID(LinkedList* pArrayListEmployee,int id, int* index)
{
	Employee* auxEmployee = NULL;
	int auxId;
	*index = -1;
	for(int i = 0 ; i < ll_len(pArrayListEmployee) ; i++ )
	{
		auxEmployee  = (Employee*) ll_get(pArrayListEmployee,i);
		employee_getId(auxEmployee ,&auxId);
		if(auxEmployee  != NULL && auxId == id)
		{
			(*index) = i;
			break;
		}
	}

	return auxEmployee;
}

int controller_showEmployee(Employee* pEmp)
{
    int id;
    char nombre[40];
    int sueldo;
    int horas;
    int todoOk = 0;
    if(pEmp != NULL &&
        employee_getId(pEmp, &id) &&
        employee_getNombre(pEmp, nombre) &&
        employee_getHorasTrabajadas(pEmp,&horas) &&
        employee_getSueldo(pEmp,&sueldo) )
    {

        printf(" %d 	%-10s  		%-4d   		   $%-4d \n",id,nombre,horas,sueldo);
        todoOk = 1;
    }
    return todoOk;
}

int controller_CompararNombre(void* a, void* b )
{
	int todoOk = 0;
	char auxNombreA[40];
	char auxNombreB[40];
	if(a != NULL && b != NULL)
	{
		strcpy(auxNombreA,((Employee*)a)->nombre);
		strcpy(auxNombreB,((Employee*)b)->nombre);
		todoOk = strcmp(auxNombreA,auxNombreB);
	}
	return todoOk;
}

int controller_CompararId(void* a, void* b )
{
	int todoOk;
	if(a != NULL && b != NULL)
	{
		if(((Employee*)a)->id > ((Employee*)b)->id)
		{
			todoOk = 1;
		}
		else
		{
			if(((Employee*)a)->id < ((Employee*)b)->id)
			{
				todoOk = -1;
			}
		}
	}


	return todoOk;
}

int controller_CompararSueldo(void* a, void* b )
{
	int todoOk = 0;
	if(a != NULL && b != NULL)
	{
		if(((Employee*)a)->sueldo > ((Employee*)b)->sueldo)
		{
			todoOk = 1;
		}
		else
		{
			if(((Employee*)a)->sueldo < ((Employee*)b)->sueldo)
			{
				todoOk = -1;
			}
		}
	}
	return todoOk;
}

int controller_CompararHorasT(void* a, void* b)
{
	int todoOk = 0;
	if(a != NULL && b != NULL)
	{
		if(((Employee*)a)->horasTrabajadas > ((Employee*)b)->horasTrabajadas)
		{
			todoOk = 1;
		}
		else
		{
			if(((Employee*)a)->horasTrabajadas < ((Employee*)b)->horasTrabajadas)
			{
				todoOk = -1;
			}
		}
	}

	return todoOk;
}

int controller_IdSiguiente(LinkedList* pArrayListEmployee)
{
	Employee* auxEmpleado = NULL;
	int maximo;
	int id;
	int tam;
	if(pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);
		for(int i = 0; i < tam ; i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee,i);
			employee_getId(auxEmpleado, &id);
			if(id > maximo || i == 0)
			{
				maximo = id;
			}
		}
	}
	return maximo;
}
