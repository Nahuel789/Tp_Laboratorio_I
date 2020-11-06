/** \brief Hace el parseo de la carga de empleados de archivo csv
 *
 * \param pFile puntero a archivo
 * \param pArrayListEmployee puntero a linkedList
 * \return -1 si hay un error, 0 si esta todo ok
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief Hace el parseo de la carga de empleados de archivo binario
 *
 * \param pFile puntero a archivo
 * \param pArrayListEmployee puntero a linkedList
 * \return -1 si hay un error, 0 si esta todo ok
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
