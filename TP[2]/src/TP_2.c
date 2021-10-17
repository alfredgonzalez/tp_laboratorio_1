/*
 ============================================================================
 Name        : TP_2.c
 Author      : Alfredo Gonzalez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployee.h"
#include "Biblio.h"
#define TAM 1000
#define VACIO 1
#define CARGADO 0
#define UP 1
#define DOWN 0

int main(void)
{
	setbuf(stdout, NULL);

    int continuar= 1;
    int idEmployee = 1000;
    float salary;
    int sector;
    char name[50];
    char lastName[50];
    int contEmployee=0;
    int idBaja;
    int opcion;
    int orden;

    Employee lista[TAM];


    if(initEmployees(lista,TAM) == -1)
    {
        printf("Error....\n");
    }
    do
    {
		switch(pedirOpcion())
		{
		case 1:
		    printf("\nAlta empleado\n");
		    if(findEmptySpace(lista, TAM)==-1)
		    {
		        printf("Error.. no se encontro un lugar libre\n");
		    }
		    else
		    {
		        loadEmployee(&idEmployee, name, lastName, &salary, &sector);
		        addEmployee(lista, TAM, idEmployee, name, lastName, salary, sector);
		        printf("Alta realizada con exito\n");
		        contEmployee++;
		    }
		    break;
		case 2:
		    if(contEmployee==0)
		    {
		        printf("ERROR.... tenes que ingresar algun empleado como minimo \n");
		    }
		    else
		    {
		    	if(!modifyEmployee(lista, TAM))
		    	{
		    		printf("No se pudo modificar el empleado\n");
		    	}
		    	else
		    	{
		    		printf("Modificacion realizada con exito\n");
		    	}
		    }
		    break;
		case 3:
			if(contEmployee==0)
			{
				printf("ERROR.. tenes que ingresar algun empleado como minimo \n");
			}
			else
			{
				idBaja = ingresarEntero("Ingresa el ID");
				if(removeEmployee(lista, TAM, idBaja)==-1)
				{
					printf("Error.. no fue posible realizar la baja, intentelo nuevamente");
				}
				else
				{
					contEmployee--;
					printf("Baja realizada con exito");
				}
			}
		break;
		case 4:
			contadorEmployee(lista, &contEmployee, TAM);
			if(contEmployee==0)
			{
				printf("ERROR... tenes que ingresar algun empleado como minimo \n");
			}
			else
			{
				printf("Presione 1. Para ordenar alfabeticamente por Apellido y sector. \nPresione 2 para ver el total y promedio de los salarios, y cuanta cantidad supera el promedio\n");
				scanf("%d", &opcion);
				while(opcion!=1&&opcion!=2&&opcion!=3)
				{
					printf("Presione 1. Para ordenar alfabeticamente por Apellido y sector. \n ");
					scanf("%d", &opcion);
				}
				switch(opcion)
				{
				case 1:
					orden = ingresarEntero("Ingrese 1. Para orden Ascendente(A->Z). \nIngrese 2. Para orden descendente(Z->A): ");
					if(orden==1)
					{
						sortEmployees(lista, TAM, UP);
					}
					else
					{
						sortEmployees(lista, TAM, DOWN);
					}
					printEmployees(lista, TAM);
				break;
				case 2:
					mostrarTotalSueldos(lista, TAM);
					mostrarPromedioSueldos(lista, TAM);
					employeeArribaSalarioProm(lista, TAM);

				break;
				case 3:
					printf("Funcion cancelada correctamente\n");
				break;

				}
			}
		break;
		case 5:
			printf("Gracias por elegirnos\n");
			continuar = 0;
		break;
		}
    }while(continuar == 1);

	return EXIT_SUCCESS;
}


