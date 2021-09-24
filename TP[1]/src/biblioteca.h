
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/// @fn int DevolverOpcion(void)
/// @brief Muestra el menu de opciones al usuario y devuelve la opcion elegida
/// @return El numero de opcion que eligio el usuario
int DevolverOpcion(void);
/// @fn float PedirFloat(char[])
/// @brief Pide el primer y segundo operador al usuario en numeros flotantes
/// @param mensaje El texto que se muestra al pedir el numero flotante
/// @return El numero flotante ingresado
float PedirFloat(char mensaje[]);
/// @fn float SumarFloat(float, float)
/// @brief Suma los dos numeros flotantes ingresados previamente
/// @param variableA primer operador ingresado por el usuario
/// @param variableB segundo operador ingresado por el usuario
/// @return El resultado de la suma de los dos operadores
float SumarFloat(float variableA, float variableB);
/// @fn float RestarFloat(float, float)
/// @brief Resta los dos numeros flotantes ingresados previamente
/// @param variableA primer operador ingresado por el usuario
/// @param variableB segundo operador ingresado por el usuario
/// @return El resultado de la resta de los dos operadores
float RestarFloat(float variableA, float variableB);
 /// @fn float DividirFloat(float, float)
 /// @brief Divide los dos numeros flotantes ingresados previamente
 /// @param variableA Primer operador ingresado por el usuario
 /// @param variableB segundo operador ingresado por el usuario
 /// @return El resultado de la division de los dos operadores. (La validacion de que no se divida por 0 esta realizada en el main)
float DividirFloat(float variableA, float variableB);
/// @fn float MultiplicarFloat(float, float)
/// @brief Multiplica los dos numeros flotantes ingresados previamente
/// @param variableA Primer operador ingresado por el usuario
/// @param variableB Segundo operador ingresado por el usuario
/// @return El resultado de la multiplicacion de los dos operadores.
float MultiplicarFloat(float variableA, float variableB);
/// @fn float FactorialFloat(float)
/// @brief Factoriza el numero ingresado previamente. Valida que no sea negativo y que el operador no sea mayor a 100 para garantizar mayor efectividad en la respuesta.
/// @param numeroIngresado Operador que ingresa el usuario
/// @return Falsa si el numero ingresado es negativo o mayor a 100, y verdadera si el numero ingresado es apto para operar.
float FactorialFloat(float numeroIngresado);
/// @fn int ValidarSiEsEntero(float)
/// @brief Valida que el numero a factorizar sea un entero y no un decimal.
/// @param numeroIngresado Operador que ingresa el usuario
/// @return verificacion falsa si el numero es decimal y verdadera si el numero es entero
int ValidarSiEsEntero(float numeroIngresado);
/// @fn void InformarResultado(char[])
/// @brief Informa los resultados de las funciones
/// @param mensaje El texto que muestra al informar los resultados
void InformarResultado(char mensaje[]);


#endif /* BIBLIOTECA_H_ */
