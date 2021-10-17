/*
 * ArrayEmployee.c
 *
 *  Created on: 8 oct 2021
 *  Author: Alfredo Gonzalez
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


int initEmployees(Employee *list, int len)
{
    int allOk = -1;

    for(int i=0;i<len; i++)
    {
    	list[i].isEmpty = VACIO;
    }
    allOk = 0;

    return allOk;
}

int findEmptySpace(Employee* list, int len)
{
    int indice = -1;

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty == VACIO)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int allOk = -1;
    Employee auxEmployee;
    int indice;

    if(list != NULL && name != NULL && lastName != NULL && len > 0)
    {
        indice = findEmptySpace(list, len);
        if(indice == -1)
        {
            printf("Error al agregar empleado\n");
        }
        else
        {
            auxEmployee.id = id;
            strncpy(auxEmployee.name,name,sizeof(auxEmployee.name));
            strncpy(auxEmployee.lastName,lastName,sizeof(auxEmployee.lastName));
            auxEmployee.salary = salary;
            auxEmployee.sector = sector;
            auxEmployee.isEmpty = CARGADO;
            list[indice] = auxEmployee;
            allOk= 0;
        }
    }

    return allOk;
}


int findEmployeeById(Employee* list, int len,int id)
{
    int indice= -1;

    for(int i=0;i<len; i++)
    {
        if(id == list[i].id && list[i].isEmpty == CARGADO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int removeEmployee(Employee* list, int len, int id)
{
    int allOk= -1;
    int indice;
    int remover;

    if(list !=NULL && len > 0)
    {
    	indice = findEmployeeById(list,id,len);
    	if(indice == -1)
    	{
    		printf("Error \n");
    	}
    	else
    	{
    		printf(" Id       Name     	LastName     Salary    	Sector \n");
    		remover = ingresarEntero("Desea remover el empleado? 1=Si.\t0=No");
    		while(remover!=1&&remover!=0)
    		{
    			printf("Error.. selecciona 1 Para remover. 0 para cancelar\n");
    		}
    		switch(remover)
    		{
    		case 1:
    			list[indice].isEmpty = VACIO;
    		break;
    		case 2:
    			printf("La baja fue cancelada\n");
    		break;
    		}
    		allOk=0;
    	}
    }

    return allOk;
}

int sortEmployees(Employee* list, int len, int order)
{
    int allOk=-1;
    int opcion;
    if(list != NULL && len > 0)
    {
        opcion = ingresarEntero("\nPresiona\n 1. Ordenar por apellido \n 2. Ordenar por sector\n");
        while(opcion!=1&&opcion!=2)
        {
        	opcion = ingresarEntero("\nPresiona 1. Ordenar por apellido \n 2. Ordenar por sector\n");
        }
        switch(opcion)
        {
        case 1:
        	sortByLastName(list, len, order);
        break;
        case 2:
        	sortEmployeeBySector(list, len, order);
        break;
        }
        allOk=0;
    }

    return allOk;
}
int sortByLastName(Employee* list, int len, int order)
{
    int allOk=-1;
    Employee auxEmployee;
    int auxiliar;
    if(list != NULL && len > 0)
    {
        for(int i=0;i<len-1;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                auxiliar = strcmp(list[i].lastName,list[j].lastName);
                if(list[j].isEmpty == CARGADO)
                {
                	if((auxiliar== 1 && order)|| (auxiliar== -1 && !order) || (auxiliar == 0  && list[i].sector > list[j].sector && order) || (auxiliar == 0 && list[i].sector < list[j].sector && !order))
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
            }
        }
        allOk=0;
    }

    return allOk;
}
int sortEmployeeBySector(Employee* list, int  len , int order)
{
    int allOk=-1;
    int auxiliar;
    Employee auxEmployee;
    if(list != NULL && len > 0)
    {
        for(int i = 0 ; i < len - 1; i++)
        {
            for(int j = i + 1; j < len ; j++)
            {
                auxiliar = strcmp(list[i].lastName,list[j].lastName);
                if(list[j].isEmpty== CARGADO)
                {
                    if((list[i].sector > list[j].sector && order) || (list[i].sector < list[j].sector && !order)
                    || (auxiliar == 1 && order) || (auxiliar == -1 && !order))
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
            }
        }
        allOk=0;
    }
    return allOk;
}

int loadEmployee(int *pId, char name[],char lastName[],float *salary,int *sector)
{
    int allOk=-1;
    char auxiliarName[50];
    char auxiliarLastName[50];

    if(name != NULL && lastName != NULL && pId != NULL && salary != NULL && sector != NULL)
    {
    	(*pId)++;
        ingresarString("Ingresa el nombre : ", auxiliarName);
        while(strlen(auxiliarName) > 15)
        {
        	ingresarString("Error.. volve a ingresar el nombre: ", auxiliarName);
        }
        ingresarString("Ingresa el apellido: ", auxiliarLastName);
        while(strlen(auxiliarLastName) > 20)
        {
        	ingresarString("Error.. volve a ingresar el apellido: ", auxiliarLastName);
        }
        *salary = ingresarFlotante("Ingresa el salario del empleado: ");
        *sector = ingresarEntero("Ingresa el numero de sector del empleado: ");
        strcpy(name,auxiliarName);
        strcpy(lastName, auxiliarLastName);
        allOk=0;
    }
    return allOk;
}
int modifyEmployee(Employee* list, int len)
{
    int allOk=0;
    int indice;
    int id;
    int option;
    int optionSeguir = 0;


    if(list != NULL && len >0)
    {
        id = ingresarEntero("Ingresa el id del empleado a modificar: ");
        indice = findEmployeeById(list, len, id);
        if(indice==-1)
        {
            printf("Error.. el id(%d) ingresado no corresponde\n", id);
        }
        else
        {

            do
            {
                printf(" Id       Name     	LastName     Salary    	Sector \n");
                option = ingresarEntero("Option\n 1.Name\n 2.LastName\n 3.Salary\n 4.Sector\n ");
                while(option!=1&&option!=2&&option!=3&&option!=4)
                {
                    option = ingresarEntero("Error.. selecciona la opcion que corresponda. Option\n 1.Name\n 2.LastName\n 3.Salary\n 4.Sector\n");
                }
                switch(option)
                {
                case 1:
                	ingresarString("Ingresa el nombre del empleado : ",list[indice].name);
                break;
                case 2:
                	ingresarString("Ingresa el Apellido del empleado : ",list[indice].lastName);
                break;
                case 3:
                    list[indice].salary = ingresarFlotante("Ingresa el salario del empleado: ");
                break;
                case 4:
                    list[indice].sector = ingresarEntero("Ingresa el sector del empleado: ");
                break;
                default:
                    printf("Error.. la opcion no es correcta\n");
                break;
                }
            optionSeguir = ingresarEntero("Queres realizar otro cambio? 1=si, 0 = no: \n");
            while(optionSeguir!=0 && optionSeguir!=1)
            {
            	optionSeguir = ingresarEntero("Queres realizar otro cambio? 1=si, 0 = no: \n");
            }
        	}while(optionSeguir!=0);
            allOk=1;
        }
    }

    return allOk;
}
int contadorEmployee(Employee* list, int *contEmployee, int len)
{
	int auxiliarCont=0;
	int allOk=-1;

	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == CARGADO)
			{
				auxiliarCont++;
			}
		}

		allOk=0;
	}
	*contEmployee = auxiliarCont;
	return allOk;
}
void printEmployee(Employee x)
{
	printf("\n %-4d %-20s %-20s %.3f %10d \n",x.id,x.name,x.lastName,x.salary,x.sector);
}
int printEmployees(Employee* list, int len)
{
	int allOk=-1;

	if(list != NULL && len > 0)
	{

		printf("\nLista de Empleados: ");
		printf("\n_________________________________________________________________________________________\n");
		printf(" Id   Name                LastName             Salary    	Sector \n");
		printf("_________________________________________________________________________________________\n");
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == CARGADO)
			{
					printEmployee(list[i]);
			}
		}
		allOk=0;
	}
	return allOk;
}
int acumularSueldos(Employee* list, int len, float *acumuladorSueldos)
{
	int allOk=-1;
	float auxAcumulador=0;

	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == CARGADO)
			{
				auxAcumulador=auxAcumulador+list[i].salary;
			}
		}
		allOk=0;
	}

	*acumuladorSueldos = auxAcumulador;

	return allOk;
}

int calcularPromedioSalarios(Employee* list, int len, float *promedioSalarios)
{
	int allOk=-1;
	float acum;
	int contador;

	if(list != NULL && len > 0)
	{
		contadorEmployee(list, &contador, len);
		acumularSueldos(list, len, &acum);
		*promedioSalarios=acum/contador;
		allOk=0;
	}
	return allOk;
}
int employeeArribaSalarioProm(Employee* list, int len)
{
	int allOk=-1;
	int contador=0;
	float promSalarios;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			calcularPromedioSalarios(list, len, &promSalarios);
			if(list[i].isEmpty==CARGADO && list[i].salary > promSalarios)
			{
				contador++;
			}
		}
		allOk=0;
	}
	printf("La cantidad que superan el promedio es: %d \n", contador);
	return allOk;
}
int mostrarTotalSueldos(Employee* list, int len)
{
	int allOk=-1;
	float acumuladorSueldos;
	if(list != NULL && len > 0)
	{
		acumularSueldos(list, len, &acumuladorSueldos);
		allOk=0;
		printf("El total de los sueldos son: %.3f \n", acumuladorSueldos);

	}
	return allOk;
	}
int mostrarPromedioSueldos(Employee* list, int len)
{
	int allOk=-1;
	float promedio;
	if(list != NULL && len > 0)
	{
		calcularPromedioSalarios(list, len, &promedio);
		allOk=0;
		printf("El promedio de los sueldos son: %.3f\n" ,promedio);
	}

	return allOk;
}
