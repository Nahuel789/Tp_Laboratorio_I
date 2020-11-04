#include "menu.h"
#include <stdio.h>

int menu()
{
    int opcion;

     printf("MENU DE OPCIONES\n");
     printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
     printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
     printf("3. Alta de empleado\n");
     printf("4. Modificar datos de empleado\n");
     printf("5. Baja de empleado");
     printf("6. Listar empleados\n");
     printf("7. Ordenar empleados\n");
     printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
     printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
     printf("10. Salir\n");
     printf("Ingrese la opcion deseada: \n");
     fflush(stdin);
     scanf("%c",&opcion);


    return opcion;

}


int menuModificacion()
{
    int opcion;

     printf("MENU DE OPCIONES DE MODIFICACION\n");
     utn_getNumero(&opcion,"1)Modificacion de nombre\n2)Modificacion de horas trabajadas\n3)Modificacion de sueldo\nIngrese la opcion que desee: \n","Error,reingrese",1,3,1);

    return opcion;

}
