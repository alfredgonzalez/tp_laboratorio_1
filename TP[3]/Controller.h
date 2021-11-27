#include "Employee.h"
#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
Employee* controller_searchEmployeeID(LinkedList* pArrayListEmployee,int id, int* index);
int controller_showEmployee(Employee* pEmp);
int controller_CompararNombre(void* a, void* b );
int controller_CompararId(void* a, void* b );
int controller_CompararSueldo(void* a, void* b );
int controller_CompararHorasT(void* a, void* b);
int controller_IdSiguiente(LinkedList* pArrayListEmployee);

