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

eDinosaurio* dinosaur_new();
eDinosaurio* dinosaur_newParametros(char* idStr,char* especieStr,char* altura,char* tipo);
int dinosaur_getId(eDinosaurio* this,int* id);
int dinosaur_getEspecie(eDinosaurio* this,char* especie);
int dinosaur_getAltura(eDinosaurio* this,float* altura);
int dinosaur_getTipo(eDinosaurio* this,char* tipo);
int dinosaur_setId(eDinosaurio* this,int id);
int dinosaur_setEspecie(eDinosaurio* this,char* especie);
int dinosaur_setAltura(eDinosaurio* this,float altura);
int dinosaur_setTipo(eDinosaurio* this,char* tipo);
int dinosaur_list(LinkedList* this);
int parser_DinoFromText(char* path , LinkedList* pArrayListEmployee);
int dinosaur_add(LinkedList* this);
int proximoId();
void dinosaur_delete(eDinosaurio* this);
int filterCarnivoro(void* a);
int dinosaur_edit(LinkedList* this);
int dinosaur_findById(LinkedList* this, int id);
int dinosaur_changeName(eDinosaurio* this);
int dinosaur_changeHeight(eDinosaurio* this);
int dinosaur_changeType(eDinosaurio* this);
int dinosaur_sortByName(void* a,void* b);
int dinosaur_sortByHeight(void* a,void* b);
int dinosaur_sortByType(void* a,void* b);
int saveAsText(char* path, LinkedList* pArrayListEmployee);
int dinosaur_removeMenu(LinkedList* this);



