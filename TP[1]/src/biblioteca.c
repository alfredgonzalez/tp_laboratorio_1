#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#define MAX 100

int ValidarSiEsEntero(float numeroIngresado)
{
    int numeroEntero;
    float resta;
    int verificacion;

    verificacion=0;

    numeroEntero = numeroIngresado;
    resta = numeroEntero - numeroIngresado;

    if(resta==0)
    {
        verificacion=1;
    }

    return verificacion;
}

float FactorialFloat(float numeroIngresado)
{

    float resultadoFactorial;
    float numero;


    resultadoFactorial=0;

    if(numeroIngresado>=0&&numeroIngresado<MAX)
    {
        resultadoFactorial=1;
        for(numero=numeroIngresado; numero>0; numero--)
        {
        resultadoFactorial = resultadoFactorial*numero;
        }
    }

    return resultadoFactorial;
}

float MultiplicarFloat(float variableA, float variableB)
{
    float resultadoMultiplicacion;

    resultadoMultiplicacion = variableA*variableB;

    return resultadoMultiplicacion;
}

float DividirFloat(float variableA, float variableB)
{
    float resultadoDivision;

    resultadoDivision = variableA/variableB;

    return resultadoDivision;
}

float RestarFloat(float variableA, float variableB)
{
    float resultadoResta;

    resultadoResta = variableA-variableB;

    return resultadoResta;
}


float SumarFloat(float variableA, float variableB)
{
    float resultadoSuma;

    resultadoSuma = variableA+variableB;

    return resultadoSuma;
}

float PedirFloat(char mensaje[])
{
    float numeroIngresado;

    printf("%s \n", mensaje);
    scanf("%f", &numeroIngresado);

    return numeroIngresado;
}
int DevolverOpcion(void)
{
    int opcion;
    printf("1. Ingresar el primer operando:\n");
    printf("2. Ingresar el segundo operando:\n");
    printf("3. Calcular todas las operaciones:\n");
    printf("4. Informar resultados:\n");
    printf("5. Salir:\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

