#include "dinosaurios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "menu.h"

eDinosaurio* dinosaur_new()
{
    eDinosaurio* nuevoDino=NULL;
    nuevoDino=(eDinosaurio*)malloc(sizeof(eDinosaurio));
    if(nuevoDino != NULL)
    {
        nuevoDino->id=0;
        strcpy(nuevoDino->especie,"");
        nuevoDino->altura='0';
        strcpy(nuevoDino->tipo,"");
    }
    return nuevoDino;
}
eDinosaurio* dinosaur_newParametros(char* idStr,char* especieStr,char* altura,char* tipo)
{
    eDinosaurio* this=NULL;

    this=dinosaur_new();

    if(idStr!= NULL && especieStr!=NULL && altura!=NULL && tipo!=NULL)
    {
        if(!(!dinosaur_setId(this,atoi(idStr)) && !dinosaur_setEspecie(this,especieStr) && !dinosaur_setAltura(this,atof(altura)) && !dinosaur_setTipo(this,(tipo))))
        {
            dinosaur_delete(this); //ELIMINA EL PUNTERO AUXILIAR
        }
    }
    return this;
}
int dinosaur_getId(eDinosaurio* this,int* id)
{
    int retorno=-1;
    if(this != NULL && id != NULL )
    {
        *id=this->id;
        retorno=0; //EXITO
    }
    return retorno;
}
int dinosaur_getAltura(eDinosaurio* this,float* altura)
{
    int retorno=-1;
    if(this != NULL && altura!= NULL )
    {
        *altura=this->altura;
        retorno=0; //EXITO
    }
    return retorno;
}
int dinosaur_getTipo(eDinosaurio* this,char* tipo)
{
    int retorno=-1;
    if(this != NULL && tipo!= NULL )
    {
        strcpy(tipo,this->tipo);
        retorno=0; //EXITO
    }
    return retorno;
}
int dinosaur_getEspecie(eDinosaurio* this,char* especie)
{
    int retorno=-1;
    if(this != NULL && especie!= NULL )
    {
        strcpy(especie,this->especie);
        retorno=0; //EXITO
    }
    return retorno;
}
int dinosaur_setId(eDinosaurio* this,int id)
{
    int retorno=-1;
    {
        if(this != NULL && id >=0 )
        {
            this->id=id;
            retorno=0; //EXITO
        }
    }
    return retorno;
}
int dinosaur_setEspecie(eDinosaurio* this,char* especie)
{
    int retorno=-1;

    if(this != NULL && especie != NULL )
    {
        strcpy(this->especie,especie);
        retorno=0; //EXITO
    }
    return retorno;
}
int dinosaur_setAltura(eDinosaurio* this,float altura)
{
    int retorno=-1;

    if(this != NULL && altura >= 0 )
    {
        this->altura=altura;
        retorno=0; //EXITO
    }
    return retorno;

}
int dinosaur_setTipo(eDinosaurio* this,char* tipo)
{
    int retorno=-1;

    if(this != NULL && tipo != NULL )
    {
        strcpy(this->tipo,tipo);
        retorno=0; //EXITO
    }
    return retorno;

}

int dinosaur_list(LinkedList* this) //LISTA DINOSAURIOS ACTIVOS
{
    int retorno=-1;
    eDinosaurio* pDinosaur=NULL;
    int auxId;
    char especie[50];
    float altura;
    char tipo[50];
    int flag=0;

    if(this != NULL && ll_len(this) > 0  )
    {

        printf(".............................................................................................................\n");
        printf(".............................................LISTA DE DINOSAURIOS............................................\n");
        printf(".............................................................................................................\n\n");
        printf("ID                       ESPECIE                           ALTURA(MTS)                               TIPO                \n\n");
        for(int i=0; i<ll_len(this); i++)
        {
            pDinosaur=(eDinosaurio*)ll_get(this,i);

            if(pDinosaur != NULL)
            {
                if(!dinosaur_getId(pDinosaur,&auxId))
                {
                    if(!dinosaur_getEspecie(pDinosaur,especie))
                    {
                        if(!dinosaur_getAltura(pDinosaur,&altura))
                        {
                            if(!dinosaur_getTipo(pDinosaur,tipo))
                            {
                                printf("%2d              %15s                             %1.2f                         %15s \n",auxId,especie,altura,tipo);
                                flag=1;
                                pDinosaur=NULL;
                                retorno=0;//EXITO
                            }
                        }
                    }
                }
            }
        }
    }
    if(!flag)
    {
        printf("No hay dinosaurios que listar\n");
    }
    return retorno;
}
int parser_DinoFromText(char* path, LinkedList* pArrayDinosaur)
{
    char id[100];
    char especie[100];
    char altura[100];
    char tipo[100];
    int retorno=-1;
    eDinosaurio* pDinosaurio;
    FILE* pFile;

    pFile=fopen(path,"r");
    if(pFile!=NULL && pArrayDinosaur !=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,especie,altura,tipo);
        do
        {
            if((fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,especie,altura,tipo))== 4)
            {
                pDinosaurio=dinosaur_newParametros(id,especie,altura,tipo);

                if(pDinosaurio != NULL)
                {
                    ll_add(pArrayDinosaur,pDinosaurio);
                    retorno=0;
                }
            }
            else
                break;

        }
        while(!feof(pFile));
    }
    else
    {
        printf("No existe el archivo\n");
        exit(EXIT_FAILURE);
    }
    return retorno;
}
int dinosaur_add(LinkedList* this) //AGREGA UN DINOSAURIO A LA LINKEDLIST
{
    int retorno=-1;
    eDinosaurio* pDinosaurio=NULL;
    char especie[128];
    char altura[128];
    char tipo[128];
    char id[128];

    if(this != NULL)
    {
        printf("......................................................................................................................\n");
        printf("................................................ALTA DE DINOSAURIO......................................................\n");
        printf("......................................................................................................................\n\n");

        sprintf(id,"%d",proximoId());

        if(!utn_getCadena(especie,sizeof(especie),1,"Ingrese la especie del dinosaurio: ","Error,reingrese: "))
        {
            if(!utn_getCadena(altura,sizeof(altura),1,"Ingrese la altura de este dinosaurio : ","Error.Reingrese: "))
            {
                if(!utn_getCadena(tipo,sizeof(tipo),1,"Ingrese el tipo del dinosaurio: ","Error.Reingrese: "))
                {
                    pDinosaurio=dinosaur_newParametros(id,especie,altura,tipo);

                    if(pDinosaurio != NULL)
                    {
                        if(!ll_add(this,pDinosaurio))
                        {
                            retorno=0;//EXIT0
                        }
                    }
                }
            }
        }

    }
    return retorno;
}


static int obtenerId()
{
    static int id=10;
    id++;
    return id;
}
int proximoId()
{
    return obtenerId();
}

void dinosaur_delete(eDinosaurio* this) //ELIMINA UN DINOSAURIO
{
    free(this);
    this=NULL;
}

int filterCarnivoro(void* a)
{
    int retorno=-1;

    eDinosaurio* dino=(eDinosaurio*)a;

    if(a != NULL)
    {
        if(strcmp("Carnivoro",dino->tipo) == 0)
        {
            retorno=1;
        }
    }
    return retorno;

}

int dinosaur_edit(LinkedList* this) //EDITA UN DINOSAURIO
{
    int retorno=-1;
    int aux;
    int indice;

    eDinosaurio* pDinosaurio=NULL;

    if(this != NULL)
    {
        printf("......................................................................................................................\n");
        printf(".............................................EDICION DE DINOS.........................................................\n");
        printf("......................................................................................................................\n\n");

        dinosaur_list(this);

        if(!utn_getNumero(&aux,"Ingrese el id que quiere: \n","Error.Reingrese:",1,100000,3))
        {
            indice=dinosaur_findById(this,aux);

            if(indice != -1)
            {
                pDinosaurio=ll_get(this,indice);

                if(pDinosaurio != NULL)
                {
                    switch(menuModificacion()) //MENU MODIFICACION
                    {
                    case 1 :
                        system("cls");
                        if(!dinosaur_changeName(pDinosaurio))
                        {
                            retorno=0;//EXITO
                        }
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        if(!dinosaur_changeHeight(pDinosaurio))
                        {
                            retorno=0;//EXITO
                        }
                        system("pause");
                        break;

                    case 3:
                        system("cls");
                        if(!dinosaur_changeType(pDinosaurio))
                        {
                            retorno=0;//EXITO
                        }
                        system("pause");
                        break;

                    }
                }
            }
            else
            {
                printf("No hay dino que mostrar\n");
            }

        }
    }
    return retorno;
}
int dinosaur_findById(LinkedList* this, int id) //BUSCA DINOSAURIOS POR ID
{
    int indice = -1;
    int len = ll_len(this);
    int auxId;
    eDinosaurio* pDino;

    for(int i = 0; i < len; i++)
    {
        pDino=(eDinosaurio*)ll_get(this,i);
        dinosaur_getId(pDino,&auxId);

        if(auxId == id)
        {
            indice = i;
            break;
        }
    }
    if(indice == -1)
    {
        printf("No se encontro el id\n");
    }
    return indice;
}
int dinosaur_changeName(eDinosaurio* this) //CAMBIA EL NOMBRE DE UN DINOSAURIO
{
    int retorno=-1;
    char nombre[50];

    if(this != NULL)
    {
        if(!utn_getCadena(nombre,50,1,"Ingrese el nuevo nombre del dino: \n","Error,Reingrese:\n"))
        {
            if(!dinosaur_setEspecie(this,nombre))
            {
                retorno=0;//EXITO
            }
        }
    }
    return retorno;
}
int dinosaur_changeHeight(eDinosaurio* this)//CAMBIA LA ALTURA DE UN DINOSAURIO
{
    int retorno=-1;
    float altura;

    if(this != NULL)
    {
        if(!utn_getNumeroFloat(&altura,"Ingrese la nueva altura del dinosaurio: \n","Error.Reingrese: \n",0,10000000,1))
        {
            if(!dinosaur_setAltura(this,altura))
            {
                retorno=0;//EXITO
            }

        }
    }

    return retorno;
}
int dinosaur_changeType(eDinosaurio* this)//CAMBIA EL TIPO DE UN DINOSAURIO
{
    int retorno=-1;
    char tipo[50];

    if(this != NULL)
    {
        if(!utn_getCadena(tipo,sizeof(tipo),2,"Ingrese el nuevo tipo del dino: \n","Error. Reingrese: \n"))
        {
            if(!dinosaur_setTipo(this,tipo))
            {
                retorno=0;//EXITO
            }

        }
    }
    return retorno;
}
int dinosaur_sortByName(void* a, void* b)//COMPARA POR NOMBRE
{
    int retorno=0;
    eDinosaurio* pA=(eDinosaurio*)a;
    eDinosaurio* pB=(eDinosaurio*)b;
    if(strcmp(pA->especie,pB->especie) > 0)
    {
        retorno=1;
    }
    else if(strcmp(pA->especie,pB->especie) < 0)
    {
        retorno=-1;
    }
    return retorno;
}
int dinosaur_sortByHeight(void* a, void* b)//COMPARA ALTURA
{
    int retorno=0;
    eDinosaurio* pA=(eDinosaurio*)a;
    eDinosaurio* pB=(eDinosaurio*)b;
    if((pA->altura) > (pB->altura))
    {

        retorno=1;
    }
    else if((pA->altura) < (pB->altura))
    {

        retorno=-1;
    }
    else
    {
        printf("SON IGUALES");
        retorno=0;
    }
    return retorno;
}
int dinosaur_sortByType(void* a, void* b)//COMPARA TIPOS
{
    int retorno=0;
    eDinosaurio* pA=(eDinosaurio*)a;
    eDinosaurio* pB=(eDinosaurio*)b;

    if(strcmp(pA->tipo,pB->tipo) > 0)
    {
        retorno=1;

    }
    else if(strcmp(pA->tipo,pB->tipo) < 0)
    {
        retorno=-1;
    }
    return retorno;
}

int saveAsText(char* path, LinkedList* lista)//SALVA COMO TEXTO
{
    int retorno=-1;
    FILE* pFile;
    int tam;
    int auxId;
    char especie[25];
    float auxAltura;
    char tipo[25];
    eDinosaurio* pDino=NULL;
    tam=ll_len(lista);

    if(path != NULL && lista != NULL)
    {
        pFile=fopen(path,"w"); //ABRE EL ARCHIVO EN EL QUE VA A GUARDAR LA INFORMACION

        if(pFile != NULL)
        {
            fprintf(pFile,"id,Especie,Altura,Tipo\n");

            for(int i=0; i<tam; i++)
            {
                pDino=(eDinosaurio*)ll_get(lista,i);

                if(pDino != NULL)
                {
                    if(!dinosaur_getId(pDino,&auxId) && !dinosaur_getTipo(pDino,tipo) && !dinosaur_getAltura(pDino,&auxAltura) && !dinosaur_getEspecie(pDino,especie))
                    {
                        fprintf(pFile,"%d,%s,%f,%d\n",auxId,especie,auxAltura,tipo);
                        retorno=0; //EXITO
                    }
                }
            }
            fclose(pFile); //CIERRE DE ARCHIVO
        }
    }
    return retorno;
}

int dinosaur_removeMenu(LinkedList* this)//ELIMINA UN DINO EN EL INDICE SELECCIONADO
{
    int retorno=-1;
    int aux;
    int indice;
    eDinosaurio* auxDino;
    if(this != NULL)
    {
        printf("......................................................................................................................\n");
        printf(".............................................BAJA DE DINOS............................................................\n");
        printf("......................................................................................................................\n\n");

        dinosaur_list(this);
        if(!utn_getNumero(&aux,"Ingrese el indice del dino que quiere eliminar : \n","Error.Reingrese: \n",1,ll_len(this),1))
        {
            indice=dinosaur_findById(this,aux);
            if(indice != -1)
            {
                auxDino=(eDinosaurio*)ll_pop(this,indice);
                if(auxDino != NULL)
                {
                    printf("Eliminaste a el dino del indice %d llamado %s\n",auxDino->id,auxDino->especie);
                    system("pause");
                }
                retorno=0;//EXITO
            }
        }
    }
    return retorno;
}
