/*
 * Biblio.c
 *
 *  Created on: 8 oct 2021
 *  Author: Alfredo Gonzalez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Biblio.h"

int ingresarString(char mensaje[], char dato[])
{
	int allOk = 0;

	    if(mensaje != NULL && dato !=NULL)
	    {
	        printf("%s", mensaje);
	        fflush(stdin);
	        gets(dato);

	        allOk = 1;
	    }

	    return allOk;
}
int ingresarEntero(char mensaje[])
{
    int numeroIngresado;
    printf("%s",mensaje);

    scanf("%d",&numeroIngresado);

    return numeroIngresado;

}
float ingresarFlotante(char mensaje[])
{
    float numeroIngresado;
    printf("%s",mensaje);

    scanf("%f",&numeroIngresado);

    return numeroIngresado;

}
int validarRangoEntero(int valor, int limiteInferior, int limiteSuperior)
{
    int allOk = -1;
    if(valor >= limiteInferior && valor <= limiteSuperior )
    {
        allOk = 0;
    }
    return allOk;
}
int stringPrimeroLetraMayuscula(char string[])
{
    int allOk = -1;
    int i = 0;

    if(string != NULL)
    {
        strlwr(string);
        string[0] = toupper(string[0]);
        while(string[i] != '\0')
        {
            if(string[i] == ' ')
            {
                string[i+1] = toupper(string[i+1]);
            }

            i++;
        }
        allOk = 0;
    }
    return allOk;
}
int validarLargoString(char string[], int min , int max)
{
	int todoOk = 0;
	if(string != NULL)
	{

		if(strlen(string) < min || strlen(string) > max)
		{
			todoOk = 1;
		}

	}
	return todoOk;
}
int verificarSiContieneNumero(char list[])
{
    int todoOk = 0;
    if(list!= NULL)
    {
    	for (int i = 0; i < strlen(list); i++)
    	{
    		todoOk = -1;
    		if(!(isalpha(list[i])) && list[i] != ' ')
    		{
    			todoOk = 1;
    			break;
    		}
    	}
    }
    return todoOk;
  }

int menuOpcion()
{
	printf("-------------------------------\n");
	printf("-------ABM EMPLEADOS------\n\n");
	printf("-------------------------------\n");
	int opcion;
	system("cls");
	printf("1.CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.CSV (Modo Texto)\n");
	printf("2.CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.BIN (Modo Bin)\n");
	printf("3.ALTA EMPLEADO\n");
	printf("4.MODIFICAR DATOS DE EMPLEADO\n");
	printf("5.BAJA DE EMPLEADO \n");
	printf("6.LISTAR EMPLEADOS \n");
	printf("7.ORDENAR EMPLEADOS \n");
	printf("8.GUARDAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.CSV (Modo Texto) \n");
	printf("9.GUARDAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.BIN (Modo Bin) \n");
	printf("10.SALIR\n");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}
