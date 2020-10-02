#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;


#endif // ARRAYEMPLOYEES_H_INCLUDED





/** \brief Funcion que sirve para inicializar en 0 los isEmpty de cada estructura
 * \param list puntero al array de estructuras
 * \param len tamaño de el array de estructuras
 * \return 0 si esta todo ok, -1 si hay un error
 *
 */
int initEmployees(Employee* list, int len);

/** \brief Funcion que sirve para agregar un empleado en la lista
 *
  * \param list puntero al array de estructuras
 *  \param len tamaño de el array de estructuras
 *  \param id legajo del proximo empleado
 *  \param name nombre del empleado
 *  \param lastName apellido del empleado a agregar
 *  \param salary salario del empleado a agregar
 *  \param sector del empleado a agregar
 *  \return 0 si esta todo ok, -1 si hay un error
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief Funcion que sirve buscar empleado por ID
 *
 * \param list puntero al array de estructuras
 * \param len tamaño de el array de estructuras
 * \param id del empleado a buscar
 * \return -1 si hay un error , o el indice en el que se encuentra el empleado
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Funcion que sirve cambiar el empleado usando el ID
 *
 * \param list puntero al array de estructuras
 * \param len tamaño de el array de estructuras
 * \param id del empleado a buscar
 * \return 0 si esta todo ok, -1 si hay un error
 *
 */
int changeEmployeeById(Employee* list,int len,int id);

/** \brief Funcion que sirve remover un empleado
 *
 * \param list puntero al array de estructuras
 * \param len tamaño de el array de estructuras
 * \param id del empleado a buscar
 * \return 0 si esta todo ok, -1 si hay un error, -2 si el usuario cancela la baja
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Funcion que sirve ordenar la lista de empleados por nombre y sector
 *
 * \param list puntero al array de estructuras
 * \param len tamaño de el array de estructuras
 * \param order indica el orden, 0 descendente , 1 ascendente
 * \return 0 si esta todo ok, -1 si hay un error
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief Funcion que sirve para mostrar empleados
 *
 * \param list puntero al array de estructuras
 * \param len tamaño de el array de estructuras
 * \return 0 si esta todo ok, -1 si hay un error
 *
 */
int printEmployees(Employee* list, int length);

/** \brief Funcion que sirve para mostrar un unico empleado
 *
 * \param employee estructura empleado
 *
 */
void printEmployee(Employee employee);

/** \brief Funcion que sirve buscar un espacio libre
 *
 * \param list puntero al array de estructuras
 * \param len tamaño de el array de estructuras
 * \return , -1 si hay un error || el indice del primer espacio libre
 *
 */
int findFree(Employee* list,int len);

/** \brief Funcion que mostrar el total de sueldos de los empleados/el promedio de empleados/y la cantidad de los que supero el promedio
 *
 * \param list puntero al array de estructuras
 * \param len tamaño de el array de estructuras
 * \return 0 si esta todo ok, -1 si hay un error
 *
 */
int dataEmployees(Employee* list,int len);

