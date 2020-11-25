#include "../inc/LinkedList.h"
#ifndef DINOSAURIOS_H_INCLUDED
#define DINOSAURIOS_H_INCLUDED

typedef struct{
int id;
char especie[50];
float altura;
char tipo[50];
}eDinosaurio;
#endif // DINOSAURIOS_H_INCLUDED








/** \brief Crea un dinosaurio sin parametros
 *
 * \return un dinosaurio
 *
 */
eDinosaurio* dinosaur_new();

/** \brief Crea un nuevo dinosaurio con parametros
 *
 * \param id como string
 * \param nombre como string
* \param tipo como string
 * \param  tiempo como string
 * \return return nuevo dinosaurio
 *
 */
eDinosaurio* dinosaur_newParametros(char* idStr,char* especieStr,char* altura,char* tipo);
/** \brief Obtiene el id en un dinosaurio
 *
 * \param this un dinosaurio
 * \param int*  id puntero donde guardara el id
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int dinosaur_getId(eDinosaurio* this,int* id);
/** \brief Obtiene la especie de un dinosaurio
 *
 * \param this un dinosaurio
 * \param char*  especie puntero donde guardara la especie
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int dinosaur_getEspecie(eDinosaurio* this,char* especie);
/** \brief Obtiene la altura de un dinosaurio
 *
 * \param this un dinosaurio
 * \param float* altura puntero donde guardara la altura
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int dinosaur_getAltura(eDinosaurio* this,float* altura);
/** \brief Obtiene el tipo de un dinosaurio
 *
 * \param this un dinosaurio
 * \param char* altura puntero donde guardara el tipo
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int dinosaur_getTipo(eDinosaurio* this,char* tipo);
/** \brief Setea el id en un dinosaurio
 *
 * \param this un dinosaurio
 * \param int id
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int dinosaur_setId(eDinosaurio* this,int id);
/** \brief Setea la especie en un dinosaurio
 *
 * \param this un dinosaurio
 * \param char* especie
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int dinosaur_setEspecie(eDinosaurio* this,char* especie);
/** \brief Setea la altura en un dinosaurio
 *
 * \param this un dinosaurio
 * \param float altura
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int dinosaur_setAltura(eDinosaurio* this,float altura);
/** \brief Setea el tipo en un dinosaurio
 *
 * \param this un dinosaurio
 * \param char* tipo
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int dinosaur_setTipo(eDinosaurio* this,char* tipo);
/** \brief Muestra todos los dinosaurios de una lista
 *
 * \param this puntero lista
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int dinosaur_list(LinkedList* this);
/** \brief Parsea los datos de un archivo a una lista
 * \param char* path nombre del archivo
 * \param lista donde guardara los datos
 * \return 0 si esta ok ,-1 si hay un error
 *
 */
int parser_DinoFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Agrega un dinosaurio a la lista
 *
 * \param this puntero a la lista
 * \return 0 si esta ok ,-1 si hay un error
 *
 */
int dinosaur_add(LinkedList* this);
/** \brief Genera el proximo id
 *
 * \return id
 *
 */

int proximoId();
/** \brief Elimina un id
 *
 * \param this dinosaurio a eliminar
 *
 */
void dinosaur_delete(eDinosaurio* this);
/** \brief Filtra carnivoros de una lista
 *
 * \param a puntero a filtrar
 * \return 0 si esta ok ,-1 si hay un error
 *
 */

int filterCarnivoro(void* a);

/** \brief Edita un dinosaurio de la lista
 *
 * \param this puntero a la lista
 * \return 0 si esta ok ,-1 si hay un error
 *
 */
int dinosaur_edit(LinkedList* this);
/** \brief Busca por id
 *
 * \param this puntero a la lista
 * \param id a buscar
 * \return el indice
 *
 */
int dinosaur_findById(LinkedList* this, int id);
/** \brief Cambia el nombre de un dinosaurio
 *
 * \param this un dinosaurio
 * \return 0 si esta ok ,-1 si hay un error
 *
 */
int dinosaur_changeName(eDinosaurio* this);
/** \brief Cambia la altura de un dinosaurio
 *
 * \param this un dinosaurio
 * \return 0 si esta ok ,-1 si hay un error
 *
 */
int dinosaur_changeHeight(eDinosaurio* this);
/** \brief Cambia el tipo de un dinosaurio
 *
 * \param this un dinosaurio
 * \return 0 si esta ok ,-1 si hay un error
 *
 */
int dinosaur_changeType(eDinosaurio* this);
/** \brief Compara por nombre
 *
 * \param a primer puntero a comparar
 * \param b segundo puntero a comparar
 * \return 0 si son iguales, 1 si el primero es mayor, o -1 si el segundo es mayor
 *
 */

int dinosaur_sortByName(void* a,void* b);
/** \brief Compara por altura
 *
 * \param a primer puntero a comparar
 * \param b segundo puntero a comparar
 * \return 0 si son iguales, 1 si el primero es mayor, o -1 si el segundo es mayor
 *
 */
int dinosaur_sortByHeight(void* a,void* b);
/** \brief Compara por tipo
 *
 * \param a primer puntero a comparar
 * \param b segundo puntero a comparar
 * \return 0 si son iguales, 1 si el primero es mayor, o -1 si el segundo es mayor
 *
 */
int dinosaur_sortByType(void* a,void* b);
/** \brief Guarda archivo como texto
 *
 * \param path nombre del archivo nuevo
 * \param lista linkedlist a guardar
 * \return 0 si esta ok ,-1 si hay un error
 *
 */

int saveAsText(char* path, LinkedList* lista);
/** \brief Menu de eliminacion de dinosaurios
 *
 * \param this puntero a la lista
 * \return 0 si esta ok ,-1 si hay un error
 *
 */
int dinosaur_removeMenu(LinkedList* this);



