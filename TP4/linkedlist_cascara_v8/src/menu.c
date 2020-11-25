#include "menu.h"
#include "utn.h"
#include <stdio.h>
int menu()
{
    int opcion;

    printf("MENU DE DINOSAURIOS\n\n");
    printf("1-Para abrir el archivo de texto.\n");
    printf("2-Si queres agregar un dino.\n");
    printf("3-Si Queres sacar un dino.\n");
    printf("4-Si queres modificar un dino.\n");
    printf("5-Para mostrar los dinos de la lista principal.\n");
    printf("6-Verifica si la lista principal esta vacia.\n");
    printf("7-para ordenar los dinos de la lista principal.\n");
    printf("8-Realocar dinos de la lista principal.\n");
    printf("9-Clona la lista principal o la secundaria\n");
    printf("10-Verifica si la lista principal es igual a la nueva lista clonada.\n");
    printf("11-Crea una sublista a partir de la lista principal.\n");
    printf("12-Filtra los carnivoros de la lista principal.\n");
    printf("13-Salir.\n");
    utn_getNumero(&opcion,"Ingrese la opcion que desee: \n","Error.Reingrese: \n",1,14,20);
    return opcion;
}
int menuModificacion()
{
    int opcion;
    printf("SUBMENU DE MODIFICACION\n");
    printf("1 para cambiar nombre\n");
    printf("2 para cambiar altura\n");
    printf("3 para cambiar tipo\n");
    utn_getNumero(&opcion,"Ingrese la opcion que desee: \n","Error.Reingrese: \n",1,3,20);
    return opcion;
}

int menuOrdenamiento()
{
    int opcion;

    printf("SUBMENU DE ORDENAMIENTO\n");
    printf("1 Ordenar por nombre\n");
    printf("2 Ordenar por altura\n");
    printf("3 Ordenar por tipo\n");
    utn_getNumero(&opcion,"Ingrese la opcion que desee: \n","Error.Reingrese: \n",1,3,2);
    return opcion;
}
