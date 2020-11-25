#include "menu.h"
#include "utn.h"
#include <stdio.h>
int menu()
{
    int opcion;

    printf("MENU DE DINOSAURIOS\n");
    printf("1-Para abrir el archivo de texto!\n");
    printf("2-Si queres agregar un dino!\n");
    printf("3-Si Queres sacar un dino!\n");
    printf("4-Si queres modificar un dino!\n");
    printf("5-Si queres limpiar lista de dinos!\n");
    printf("6-Para mostrar todos los dinos!\n");
    printf("7-Si queres que te diga si la lista no esta vacia!\n");
    printf("8-para ordenar los dinos!\n");
    printf("9- para guardar!\n");
    printf("10 SALIR\n");
    utn_getNumero(&opcion,"Ingrese la opcion que desee: \n","Error.Reingrese: \n",1,10,2);
    return opcion;
}
int menuModificacion()
{
    int opcion;
    printf("SUBMENU DE MODIFICACION\n");
    printf("1 para cambiar nombre\n");
    printf("2 para cambiar altura!\n");
    printf("3 para cambiar tipo!\n");
    utn_getNumero(&opcion,"Ingrese la opcion que desee: \n","Error.Reingrese: \n",1,3,2);
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
