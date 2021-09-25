/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Alfredo Damian Gonzalez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/
#include <stdio.h>
#define MAX 100
#include "biblioteca.h"

int main()
{
	int opcion;
	float variableA;
	float variableB;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoFactorialA;
	float resultadoFactorialB;
	float resultadoMultiplicacion;
	int validarFactorialA;
	int validarFactorialB;
	int flagNum1=0;
    int flagNum2=0;
    int operacionesRealizadas=0;

    setbuf(stdout, NULL);

	do
	{
    	opcion = DevolverOpcion();
		switch(opcion)
		{
			case 1:
				variableA = PedirFloat("Ingrese el primer numero: ");
				flagNum1 = 1;
			break;
			case 2:
				variableB = PedirFloat("Ingrese el segundo numero: ");
				flagNum2 = 1;
			break;
			case 3:
			     if(flagNum1==1&& flagNum2 == 1)
                {
                    printf("Calcular la suma (%.2f+%.2f)\n", variableA, variableB);
                    resultadoSuma = SumarFloat(variableA, variableB);
                    printf("Calcula la resta (%.2f-%.2f)\n", variableA, variableB);
                    resultadoResta = RestarFloat(variableA, variableB);
                    printf("Calcular la division(%.2f/%.2f)\n", variableA, variableB);
                    resultadoDivision = DividirFloat(variableA, variableB);
                    printf("Calcular la multiplicacion(%.2f*%.2f)\n", variableA, variableB);
                    resultadoMultiplicacion = MultiplicarFloat(variableA, variableB);
                    printf("Calcular el factorial (!%.0f), (!%.0f)\n", variableA, variableB);
                    validarFactorialA = ValidarSiEsEntero(variableA);
                    resultadoFactorialA = FactorialFloat(variableA);
                    validarFactorialB = ValidarSiEsEntero(variableB);
                    resultadoFactorialB = FactorialFloat(variableB);
                    operacionesRealizadas=1;
			    }
			    else
			    {
			        if(flagNum1==0&& flagNum2 ==0)
                    {
                        printf("No ingresaste ningun numero\n");
                    }
                    else
                    {
                        if(flagNum1==0)
                        {
                            printf("No ingresaste num 1\n");
                        }
                        else
                        {
                            printf("No ingresaste num 2\n");
                        }
                    }
			    }
			break;
			case 4:
			    if(operacionesRealizadas == 1)
                {
			        printf("El resultado de %.2f+%.2f es: %.2f\n", variableA, variableB, resultadoSuma);
                    printf("El resultado de %.2f-%.2f es: %.2f\n", variableA, variableB, resultadoResta);
                    if(variableB==0)
                    {
                        printf("No es posible dividir por 0\n");
                    }
                    else
                    {
                        printf("El resultado de %.2f/%.2f es: %.2f\n", variableA, variableB, resultadoDivision);
                    }
                    printf("El resultado de %.2f*%.2f es: %.2f\n", variableA, variableB, resultadoMultiplicacion);
                    if(validarFactorialA==1&&resultadoFactorialA!=0)
                    {
                        printf("El factorial de %.0f es: %f\n", variableA, resultadoFactorialA);
                    }
                    else
                    {
                    printf("No es posible realizar el factorial de un numero negativo o con decimal. O el numero ingresado es demasiado grande\n");
                    }
                    if(validarFactorialB==1&&resultadoFactorialB!=0)
                    {
                        printf("El factorial de %.0f es: %f\n", variableB, resultadoFactorialB);
                    }
                    else
                    {
                        printf("No es posible realizar el factorial de un numero negativo o con decimal. O el numero ingresado es demasiado grande\n");
                    }
                }
                else
                {
                    if(flagNum1== 1&& flagNum2 == 1)
                    {
                        printf("No calculaste las operaciones\n");
                    }
                    else
                    {
                        if(flagNum1==0&& flagNum2 ==0)
                        {
                            printf("No ingresaste ningun numero\n");
                        }
                        else
                        {
                            if(flagNum1==0)
                            {
                                printf("No ingresaste num 1\n");
                            }
                            else
                            {
                                printf("No ingresaste num 2\n");
                            }
                        }
                    }
                }
			break;
            case 5:
                printf("Gracias por elegir nuestro servicio.\n");
            break;
		}
	}while(opcion!=5);

    return 0;
}
