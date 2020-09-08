#ifndef FUNCIONESMATEMATICAS_H_INCLUDED
#define FUNCIONESMATEMATICAS_H_INCLUDED



#endif // FUNCIONESMATEMATICAS_H_INCLUDED


/** \brief Esta funcion sirve para tomar un numero
 * \return retorna el numero ingresado
 */
int pedirNum();
/** \brief Suma dos numeros
 *
 * \param 1er numero entero
 * \param 2do numero entero
 * \return la suma de ambos numeros
 *
 */
int sumador(int a,int b);
/** \brief resta dos numeros enteros
 *
 * \param 1er numero entero
 * \param 2do numero entero
 * \return la resta de ambos numeros
 *
 */

int restador(int a,int b);
/** \brief multiplica dos numeros enteros
 *
 * \param 1er numero entero
 * \param 2do numero entero
 * \return el producto resultante entre ambos.
 *
 */
int multiplicador(int a,int b);
/** \brief divide dos numeros enteros
 *
 * \param 1er numero entero
 * \param 2do numero entero
 * \return el cociente resultante.
 *
 */

float divisor(int a, int b);
/** \brief calcula el factorial de un numero
 *
 * \param numero entero
 * \return el factorial de ese numero.
 *
 */

long long int factorialNumber(int a);
/** \brief Menu de opciones
 *
 * \return el numero entero de la opcion elegida.
 *
 */

int menuDeOpciones();
