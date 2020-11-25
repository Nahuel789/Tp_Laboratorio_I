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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "dinosaurios.h"
#include "menu.h"
#include "utn.h"

int main(void)
{

    char seguir ='s';
    int opc;
    LinkedList* linkedList1=ll_newLinkedList();
    LinkedList* linkedList2=ll_newLinkedList();
    LinkedList* linkedList3=ll_newLinkedList();
    LinkedList* linkedList4=ll_newLinkedList();
    LinkedList* listaCarnivoros=ll_newLinkedList();
    eDinosaurio* auxDino=NULL;
    int minimo;
    int maximo;
    int flagParser=0;
    int resultado;
    do
    {
        system("cls");

        switch(menu())
        {
        case 1:
            system("cls");
            if(!parser_DinoFromText("listaDinos.csv",linkedList1))
            {
                printf("DINOSAURIOS CARGADOS CON EXITO\n");

                //CREO TRES DINOSAURIOS DE LA LISTA 1 EN LA LISTA 2
                printf("AL hacer el parser creo una lista Secundaria con el elemento 0 , 1 y 2 de la lista principal\n");
                ll_add(linkedList2,ll_get(linkedList1,0));
                ll_add(linkedList2,ll_get(linkedList1,1));
                ll_add(linkedList2,ll_get(linkedList1,2));

                flagParser=1;
            }
            system("pause");
            break;
        case 2://AGREGA UN DINOSAURIO
            system("cls");

            if(flagParser)
            {
                if(!dinosaur_add(linkedList1))
                {
                    printf("DINO AGREGADO CON EXITO\n");
                }
            }
            else
            {
                printf("Primero abrir el archivo\n");
            }
            system("pause");
            break;
        case 3://ELIMINA UN DINOSAURIO
            system("cls");
            if(flagParser)
            {
                if(!dinosaur_removeMenu(linkedList1))
                {
                    printf("DINO ELIMINADO CON EXITO\n");
                }
            }
            else
            {
                printf("Primero abrir el archivo\n");
            }
            system("pause");
            break;
        case 4://EDITA UN DINOSAURIO
            system("cls");
            if(flagParser)
            {
                if(!dinosaur_edit(linkedList1))
                {
                    printf("EDITADO CON EXITO\n");
                }

            }
            else
            {
                printf("Primero abrir el archivo\n");
            }
            system("pause");
            break;
        case 5://LISTAR UN DINOSAURIO
            system("cls");

            if(flagParser)
            {
                if(!dinosaur_list(linkedList1))
                {
                    printf("LISTADO CON EXITO\n");
                }
            }
            else
            {
                printf("Primero abrir el archivo\n");
            }

            system("pause");
            break;
        case 6://ESTA VACIA
            system("cls");
            if(ll_isEmpty(linkedList1))
            {
                printf("ESTA VACIA!\n");
            }
            else
            {
                printf("NO ESTA VACIA!\n");
            }
            system("pause");
            break;
        case 7://MENU ORDENAMIENTO
            system("cls");
            if(flagParser)
            {
                switch(menuOrdenamiento())
                {
                case 1 :
                    if(!utn_getNumero(&opc,"1 - (ascendente) / 0 - (descendente) :\n","Error.Reingrese:",0,1,4))
                    {
                        if(!ll_sort(linkedList1,dinosaur_sortByName,opc))
                        {
                            printf("ORDENAMIENTO POR NOMBRE EXITOSO ! \n");
                        }
                    }
                    break;
                case 2:
                    if(!utn_getNumero(&opc,"1 - (ascendente) / 0 - (descendente) :\n","Error.Reingrese:",0,1,4))
                    {
                        printf("%d",opc);
                        system("pause");
                        if(!ll_sort(linkedList1,dinosaur_sortByHeight,opc))
                        {
                            printf("ORDENAMIENTO POR ALTURA EXITOSO ! \n");
                        }
                    }
                    break;
                    system("pause");
                case 3:
                    system("cls");
                    if(!utn_getNumero(&opc,"1 - (ascendente) / 0 - (descendente) :\n","Error.Reingrese:",0,1,4))
                    {
                        if(!ll_sort(linkedList1,dinosaur_sortByType,opc))
                        {
                            printf("ORDENAMIENTO POR TIPO EXITOSO ! \n");
                        }
                    }
                    break;
                }
            }
            else
            {
                printf("Primero abrir el archivo\n");
            }
            system("pause");
            break;
        case 8://REALOCA UN DINOSAURIO
            system("cls");
            if(flagParser)
            {
                int indiceOrigen;
                int indiceDestino;

                dinosaur_list(linkedList1);

                if(!utn_getNumero(&indiceOrigen,"Ingrese el ID que quiere realocar: \n","Error.Reingrese",0,ll_len(linkedList1),50))
                {
                    if(!utn_getNumero(&indiceDestino,"Ingrese el indice destino: \n","Error.Reingrese",0,ll_len(linkedList1),50))
                    {
                        if(!ll_push(linkedList1,indiceDestino,ll_get(linkedList1,indiceOrigen-1)))
                        {
                            auxDino=(eDinosaurio*)ll_pop(linkedList1,indiceOrigen-1);
                            printf("REALOCACION HECHA DEl DINOSAURIO : %s\n",auxDino->especie);
                        }
                    }
                }
            }
            else
            {
                printf("Primero abrir el archivo\n");
            }
            system("pause");
            break;
        case 9: //CLONADOR DE LISTAS
            system("cls");
            if(flagParser)
            {
                if(!utn_getNumero(&resultado,"Bienvenido al clonador de listas\nIngrese 1 para clonar la lista principal\nIngrese 2 para clonar la lista secundaria\n","Error.Opcion invalida\n",1,2,1000))
                {
                    if(resultado == 1)
                    {
                        linkedList3=ll_clone(linkedList1);
                    }
                    else
                    {
                        linkedList3=ll_clone(linkedList2);
                    }
                }

            }
            else
            {
                printf("Primero abrir el archivo\n");
            }
            system("pause");
            break;
        case 10://VERIFICA SI LA LISTA 1 Y 3 SON IGUALES
            system("cls");
            if(flagParser)
            {
                if(ll_containsAll(linkedList1,linkedList3) == 0)
                {
                    printf("La lista 1 y la 3 son iguales\n");
                }
                else
                {
                    printf("Son diferentes\n");
                }
            }
            else
            {
                printf("Primero abrir el archivo\n");
            }
            system("pause");
            break;

        case 11://CREA UNA SUBLISTA
            system("cls");
            if(flagParser)
            {

                dinosaur_list(linkedList1);

                utn_getNumero(&minimo,"Ingrese el indice minimo :\n","Error.Reingrese: \n",0,10000,2);
                utn_getNumero(&maximo, "Ingrese el indice maximo: \n","Error.reingrese: \n",0,10000,2);

                linkedList4=ll_subList(linkedList1,minimo,maximo);

                if(linkedList4 != NULL)
                {
                    dinosaur_list(linkedList4);
                }
            }
            else
            {
                printf("Primero abrir el archivo\n");
            }
            system("pause");
            break;
        case 12: //FILTRAR CARNIVOROS
            system("cls");
            if(flagParser)
            {
                listaCarnivoros=ll_filter(linkedList1,filterCarnivoro);
                if(listaCarnivoros != NULL)
                {
                    dinosaur_list(listaCarnivoros);
                }
            }
            else
            {
                printf("Primero abrir el archivo\n");
            }
            system("pause");
            break;
        case 13:
            seguir='n';
            break;
        }
    }
    while(seguir == 's');


    ll_deleteLinkedList(linkedList1);
    ll_deleteLinkedList(linkedList2);
    ll_deleteLinkedList(linkedList3);
    ll_deleteLinkedList(linkedList4);
    ll_deleteLinkedList(listaCarnivoros);
    /*
        startTesting(1);  // ll_newLinkedList
           startTesting(2);  // ll_len
           startTesting(3);  // getNode - test_getNode
           startTesting(4);  // addNode - test_addNode
              startTesting(5);  // ll_add
           startTesting(6);  // ll_get
           startTesting(7);  // ll_set
           startTesting(8);  // ll_remove
           startTesting(9);  // ll_clear
           startTesting(10); // ll_deleteLinkedList
           startTesting(11); // ll_indexOf
           startTesting(12); // ll_isEmpty
           startTesting(13); // ll_push
           startTesting(14); // ll_pop
           startTesting(15); // ll_contains
           startTesting(16); // ll_containsAll
           startTesting(17); // ll_subList
           startTesting(18); // ll_clone
           startTesting(19); // ll_sort
    */
    return 0;
}


