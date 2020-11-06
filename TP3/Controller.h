/** \brief nos sirve para controlar la carga del archivo de texto
 *
 * \param path nombre de la ruta del archivo + modo
 * \param pArrayListEmployee puntero a linkedList
 * \return -1 si hay error, 0 si esta todo ok
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);



