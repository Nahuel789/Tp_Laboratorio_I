#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


/** \brief Crea un puntero empleado sin datos
 *
 * \return puntero empleado
 *
 */
Employee* employee_new();
/** \brief Crea un puntero empleado con los datos pasados por parametro
 *
 * \param idStr puntero a cadena id
 * \param nombreStr puntero a cadena nombre
 * \param horasTrabajadasStr puntero a cadena horas
 * \param sueldo puntero a cadena sueldo
 * \return puntero empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
/** \brief Elimina un puntero empleado
 */
void employee_delete();
/** \brief Carga el id de un empleado en el puntero especificado
 *
 * \param this puntero empleado a Cargar id
 * \param id entero a cargar
 * \return retorna -1 si se produce un error, 0 si esta todo ok
 *
 */
int employee_setId(Employee* this,int id);
/** \brief Obtiene el id de un empleado y guarda el dato en el puntero pasado por parametro
 *
 * \param this puntero empleado el cual que queremos obtener el id
 * \param id puntero donde sera guardado el valor
 * \return retorna -1 si se produce un error, 0 si esta todo ok
 *
 */
int employee_getId(Employee* this,int* id);
/** \brief Carga el nombre de un empleado en el puntero especificado
 *
 * \param this puntero empleado a Cargar nombre
 * \param nombre puntero a cargar
 * \return retorna -1 si se produce un error, 0 si esta todo ok
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief Obtiene el nombre de un empleado y guarda el dato en el puntero pasado por parametro
 *
 * \param this puntero empleado el cual que queremos obtener el nombre
 * \param nombre puntero donde sera guardado el valor
 * \return retorna -1 si se produce un error, 0 si esta todo ok
 *
 */
int employee_getNombre(Employee* this,char* nombre);
/** \brief Carga las horas trabajadas de un empleado en el puntero especificado
 *
 * \param this puntero empleado a Cargar horas trabajadas
 * \param horasTrabajadas que queremos cargar
 * \return retorna -1 si se produce un error, 0 si esta todo ok
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Obtiene las horas trabajadas de un empleado y guarda el dato en el puntero pasado por parametro
 *
 * \param this puntero empleado el cual que queremos obtener las horas
 * \param horasTrabajadas puntero donde sera guardado el valor
 * \return retorna -1 si se produce un error, 0 si esta todo ok
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief Carga el sueldo empleado en el puntero especificado
 *
 * \param this puntero empleado a Cargar sueldo
 * \param sueldo que queremos cargar
 * \return retorna -1 si se produce un error, 0 si esta todo ok
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief Obtiene el sueldo de un empleado y guarda el dato en el puntero pasado por parametro
 *
 * \param this puntero empleado el cual que queremos obtener el sueldo
 * \param sueldo puntero donde sera guardado el valor
 * \return retorna -1 si se produce un error, 0 si esta todo ok
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);
/** \brief Carga un empleado en la linked List
 *
 * \param this puntero a la linkedlist
 * \return retorna -1 si se produce un error, 0 si esta todo ok
 *
 */
int employee_add(LinkedList* this);
/** \brief Edita un empleado de la linked List
 *
 * \param this puntero a la linkedlist
 * \return retorna -1 si se produce un error, 0 si esta todo ok
 *
 */
int employee_edit(LinkedList* this);
/** \brief Busca un empleado en la lista , pasandole el id
 *
 * \param this puntero a la linkedlist
 * \param int id a buscar
 * \return retorna -1 si se produce un error, 0 si esta todo ok
 *
 */
int employee_findById(LinkedList* this, int id);
/** \brief Cambia el nombre de un empleado
 *
 * \param this puntero a empleado
 * \return retorna -1 si se produce un error, 0 si esta todo ok
 *
 */
int employee_changeName(Employee* this);
/** \brief Cambia el salario de un empleado
 *
 * \param this puntero a empleado
 * \return retorna -1 si se produce un error, 0 si esta todo ok
 *
 */
int employee_changeSalary(Employee* this);
/** \brief Cambia las horas trabajadas de un empleado
 *
 * \param this puntero a empleado
 * \return retorna -1 si se produce un error, 0 si esta todo ok
 *
 */
int employee_changeHoursWorked(Employee* this);
/** \brief Elimina un empleado de la lista
 *
 * \param this puntero a linkedList
 * \return  retorna -1 si se produce un error, 0 si esta todo ok
 *
 *
 */
int employe_delete(LinkedList* this);
/** \brief Compara los nombres de dos punteros a void empleados para poder ordenarlos
 *
 * \param employeeA puntero a void
 * \param employeeB puntero a void
 * \return 0 si son iguales, 1 si el primer puntero es mayor que el segundo,-1 si el primero es menor que el segundo
 *
 */
int employee_sortByName(void* employeeA,void* employeeB);

/** \brief Compara los salarios de dos punteros a void empleados para poder ordenarlos
 *
 * \param employeeA puntero a void
 * \param employeeB puntero a void
 * \return 0 si son iguales, 1 si el primer puntero es mayor que el segundo,-1 si el primero es menor que el segundo
 *
 */
int employee_sortBySalary(void* employeeA,void* employeeB);

/** \brief Compara las horas trabajadas de dos punteros a void empleados para poder ordenarlos
 *
 * \param employeeA puntero a void
 * \param employeeB puntero a void
 * \return 0 si son iguales, 1 si el primer puntero es mayor que el segundo,-1 si el primero es menor que el segundo
 *
 */
int employee_sortByHoursWorked(void* employeeA,void* employeeB);
/** \brief Compara los id de dos punteros a void empleados para poder ordenarlos
 *
 * \param employeeA puntero a void
 * \param employeeB puntero a void
 * \return 0 si son iguales, 1 si el primer puntero es mayor que el segundo,-1 si el primero es menor que el segundo
 *
 */
int employee_sortById(void* employeeA,void* employeeB);
/** \brief Nos da el proximo id de la lista
 *
 * \return el nuevo id
 *
 */
int proximoId();
/** \brief muestra la lista de empleados activos
 *
 * \param this puntero a linkedList
 * \return retorna -1 si hay un error, o 0 si esta todo ok
 *
 */
int employee_listEmployees(LinkedList* this);
#endif // employee_H_INCLUDED
