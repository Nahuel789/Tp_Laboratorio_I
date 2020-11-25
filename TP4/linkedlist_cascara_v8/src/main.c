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
#include "menu.h"
#include "dinosaurios.h"
#include "utn.h"

int main(void)
{
    LinkedList* linkedList1=ll_newLinkedList();
    char seguir ='s';
    int opc;
    do
    {
        system("cls");

        switch(menu())
        {
        case 1:
            system("cls");
            if(!parser_DinoFromText("datos.csv",linkedList1))
            {
                printf("DINOSAURIOS CARGADOS CON EXITO\n");
            }
            system("pause");
            break;
        case 2:
            system("cls");
            if(!dinosaur_add(linkedList1))
            {
                printf("DINO AGREGADO CON EXITO\n");
            }
            system("pause");
            break;
        case 3:
            if(!dinosaur_removeMenu(linkedList1))
            {
                printf("DINO ELIMINADO CON EXITO\n");
            }
            break;
        case 4:
            system("cls");
            if(!dinosaur_edit(linkedList1))
            {
                printf("EDITADO CON EXITO\n");
            }
            system("pause");
            break;

        case 5:
            system("cls");
            if(!ll_clear(linkedList1))
            {
                printf("BORRO TODA LA LISTA");
            }
            system("pause");
            break;
        case 6:
            system("cls");
            if(!dinosaur_list(linkedList1))
            {
                printf("LISTADO CON EXITO\n");
            }
            system("pause");
            break;
        case 7:
            system("cls");
            if(ll_isEmpty(linkedList1))
            {
                printf("ESTA VACIAAA!\n");
            }
            else
            {
                printf("No esta vacia\n");
            }
            system("pause");
            break;
        case 8:
            //MENU ORDENAMIENTO
            system("cls");
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
            system("pause");
            break;
        case 9:
            system("cls");
            if(!saveAsText("datos.csv",linkedList1))
            {
                printf("Guardado con exito\n");
            }
            system("pause");
            break;
        case 10:
            seguir='n';
            break;
        }
    }
    while(seguir == 's');
//    startTesting(1);  // ll_newLinkedList
//    startTesting(2);  // ll_len
//    startTesting(3);  // getNode - test_getNode
//    startTesting(4);  // addNode - test_addNode
//    startTesting(5);  // ll_add
//    startTesting(6);  // ll_get
//    startTesting(7);  // ll_set
//    startTesting(8);  // ll_remove
//     startTesting(9);  // ll_clear
//    startTesting(10); // ll_deleteLinkedList
//      startTesting(11); // ll_indexOf
//     startTesting(12); // ll_isEmpty
//     startTesting(13); // ll_push
//     startTesting(14); // ll_pop
//    startTesting(15); // ll_contains
//     startTesting(16); // ll_containsAll
//      startTesting(17); // ll_subList
//     startTesting(18); // ll_clone
//     startTesting(19); // ll_sort
//
//     */

    ll_deleteLinkedList(linkedList1);
    return 0;
}


