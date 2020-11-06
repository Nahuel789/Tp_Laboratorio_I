#include "menu.h"
#include <stdio.h>
#include "utn.h"
#include "stdlib.h"

int menu()
{
    system("cls");
    int opcion;

    printf("MENU DE OPCIONES\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");
    printf("Ingrese la opcion deseada: \n");
    fflush(stdin);
    scanf("%d",&opcion);


    return opcion;

}


int menuModificacion()
{
    system("cls");
    int opcion;

    printf("MENU DE OPCIONES DE MODIFICACION\n");
    utn_getNumero(&opcion,"1)Modificacion de nombre\n2)Modificacion de horas trabajadas\n3)Modificacion de sueldo\n4)Salir\nIngrese la opcion que desee: \n","Error,reingrese",1,4,1);

    return opcion;

}

int menuSort()
{
    system("cls");
    int opcion;

    printf("MENU DE OPCIONES DE ORDENAMIENTO\n");
    utn_getNumero(&opcion,"1)Ordenar Por id\n2)Ordenar por nombre\n3)Ordenar por horas trabajadas\n4)Ordenar por sueldo\nIngrese la opcion que desee: \n","Error,reingrese",1,4,1);

    return opcion;
}
