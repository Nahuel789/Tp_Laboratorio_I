/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
/** \brief Crea una nueva linkedList
 *
 * \return puntero a la linkedList
 *
 */
LinkedList* ll_newLinkedList(void);
/** \brief Calcula el tamanio de la linkedList
 *
 * \param this puntero a linkedList
 * \return un entero que representa el tamanio, o -1 si se produjo un error
 *
 */

int ll_len(LinkedList* this);
/** \brief agrega un puntero void a la LinkedList
 *
 * \param this puntero de tipo LinkedList
 * \param pElement puntero a void del elemento a agregar
 * \return -1 si hay un error, 0 si esta todo ok
 *
 */
int ll_add(LinkedList* this, void* pElement);

/** \brief Retorna un puntero a void , pasando el indice como parametro
 *
 * \param this puntero a linkedList
 * \param index indice del elemento a obtener
 * \return puntero a void del elemento obtenido
 *
 */
void* ll_get(LinkedList* this, int index);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int ll_remove(LinkedList* this,int index);
/** \brief ordena los elementos de la lista , pasandole una funcion como parametro
 *
 * \param this puntero a linkedList
 * \param pFunc funcion para determinar que ordenamiento tendra
 * \param order 1 ascendente , 0 descendente
 * \return
 *
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
