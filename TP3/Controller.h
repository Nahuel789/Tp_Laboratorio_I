/** \brief nos sirve para controlar la carga del archivo de texto
 *
 * \param path nombre de la ruta del archivo + modo
 * \param pArrayListEmployee puntero a linkedList
 * \return -1 si hay error, 0 si esta todo ok
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Controla la carga del archivo binario
 *
 * \param path nombre de la ruta del archivo + modo
 * \param pArrayListEmployee puntero a linkedList
 * \return -1 si hay error, 0 si esta todo ok
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Llama a la funcion que agrega un empleado a la linkedlist
 *
 * \param pArrayListEmployee puntero a linkedList
 * \return -1 si hay error, 0 si esta todo ok
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief llama a la funcion que edita un empleado de la linkedlist
 *
 * \param pArrayListEmployee puntero a linkedList
 * \return  -1 si hay error, 0 si esta todo ok
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief llama a la funcion que remueve un empleado de la linkedlist
 *
 * \param pArrayListEmployee puntero a linkedList
 * \return -1 si hay error, 0 si esta todo ok
 *
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief llama a la funcion que muestra los empleados de la lista
 *
 * \param pArrayListEmployee puntero a linkedList
 * \return -1 si hay error, 0 si esta todo ok
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief llama a la funcion que ordena empleados de la lista
 *
 * \param pArrayListEmployee puntero a linkedList
 * \return -1 si hay error, 0 si esta todo ok
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief guarda la informacion en un archivo de texto
 *
 * \param path nombre de la ruta del archivo + modo
 * \param  pArrayListEmployee puntero a linkedList
 * \return -1 si hay error, 0 si esta todo ok
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief guarda la informacion en un archivo binario
 *
 * \param path nombre de la ruta del archivo + modo
 * \param  pArrayListEmployee puntero a linkedList
 * \return -1 si hay error, 0 si esta todo ok
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);



