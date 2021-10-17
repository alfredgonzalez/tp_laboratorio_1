/*
 * ArrayEmployee.h
 *
 *  Created on: 8 oct 2021
 *  Author: Alfredo Gonzalez
 */

#ifndef ARRAYEMPLOYEE_H_
#define ARRAYEMPLOYEE_H_

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);
/// @fn int findEmptySpace(Employee*, int)
/// @brief recorre el array en busca de un indice vacio
/// @param list
/// @param len
/// @return int return -1 si es error - 0 si esta ok
int findEmptySpace(Employee* list, int len);
/// @fn int sortByLastName(Employee*, int, int)
/// @brief ordena a los empleados por el apellido de A->Z o de Z->A
/// @param list
/// @param len
/// @param order
/// @return int return -1 si es error(No pudo ordenar, direccion nula o longitud invalida) - 0 si esta ok y pudo ordenar
int sortByLastName(Employee* list, int len, int order);
/// @fn int sortEmployeeBySector(Employee*, int, int)
/// @brief ordena a los empleados por sector
/// @param list
/// @param len
/// @param order
/// @return int return -1 si es error(No pudo ordenar, direccion nula o longitud invalida) - 0 si esta ok y pudo ordenar
int sortEmployeeBySector(Employee* list, int  len , int order);
/// @fn int loadEmployee(int*, char[], char[], float*, int*)
/// @brief Realiza la carga de los distintos campos del empleado
/// @param pId
/// @param name
/// @param lastName
/// @param salary
/// @param sector
/// @return retorna -1 si no pudo realizar la carga - 0 si realizo la carga correctamente
int loadEmployee(int *pId, char name[],char lastName[],float *salary,int *sector);
/// @fn int modifyEmployee(Employee*, int)
/// @brief Pide el id del empleado a modificar y permite acceder a otro menu para modificar todos los campos con la informacion del empleado
/// @param list
/// @param len
/// @return retorna -1 si no pudo modificar(Id ingresado no valido, etc) - 0 si la modificacion fue exitosa
int modifyEmployee(Employee* list, int len);
/// @fn int contadorEmployee(Employee*, int*, int)
/// @brief recorre el array y suma a la variable contador +1 al encontrar un empleado, luego pasa ese contador por referencia
/// @param list
/// @param contEmployee
/// @param len
/// @return  retorna -1 si da error en la lista o en el tamaño - 0 si pudo acceder correctamente a la lista
int contadorEmployee(Employee* list, int *contEmployee, int len);
/// @fn void printEmployee(Employee)
/// @brief Muestra todos los campos de un empleado
/// @param x
void printEmployee(Employee x);
/// @fn int acumularSueldos(Employee*, int, float*)
/// @brief recorre el array y acumula los salarios de todos los empleados en una variable
/// @param list
/// @param len
/// @param acumuladorSueldos
/// @return retorna -1 si da error en la lista o en el tamaño  y 0 si pudo acceder correctamente a la lista
int acumularSueldos(Employee* list, int len, float *acumuladorSueldos);
/// @fn int calcularPromedioSalarios(Employee*, int, float*)
/// @brief llama a la funcion acumularSueldos y a la de contadorEmployee para calcular el promedio de los salarios
/// @param list
/// @param len
/// @param promedioSalarios
/// @return retorna -1 si da error en la lista o en el tamaño  y 0 si pudo acceder correctamente a la lista
int calcularPromedioSalarios(Employee* list, int len, float *promedioSalarios);
/// @fn int employeeArribaSalarioProm(Employee*, int)
/// @brief reccore la lista y compara el sueldo individualmente de cada empleado con el promedio previamente calculado e imprime la cantidad de empleados por encima de ese promedio
/// @param list
/// @param len
/// @return retorna -1 si da error en la lista o en el tamaño  y 0 si pudo acceder correctamente a la lista
int employeeArribaSalarioProm(Employee* list, int len);
/// @fn int mostrarPromedioSueldos(Employee*, int)
/// @brief LLama a la funcion calcularPromedioSalarios e imprime el promedio de sueldos
/// @param list
/// @param len
/// @return retorna -1 si da error en la lista o en el tamaño  y 0 si pudo acceder correctamente a la lista
int mostrarPromedioSueldos(Employee* list, int len);
/// @fn int mostrarTotalSueldos(Employee*, int)
/// @brief  LLama a la funcion acumularSueldos e imprime el total de sueldos
/// @param list
/// @param len
/// @return retorna -1 si da error en la lista o en el tamaño  y 0 si pudo acceder correctamente a la lista
int mostrarTotalSueldos(Employee* list, int len);




#endif /* ARRAYEMPLOYEE_H_ */
