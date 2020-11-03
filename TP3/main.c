#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int menu();


int main()
{
    int option = 0;


    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

        option=menu();

        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;

                 case 2:
                controller_loadFromBinary("data.csv",listaEmpleados);
                break;

                 case 3:
                controller_addEmployee();
                break;

                 case 4:
                controller_editEmployee();
                break;

                 case 5:
                controller_removeEmployee();
                break;

                 case 6:
                controller_ListEmployee();
                break;

                 case 7:
                controller_sortEmployee();
                break;

                 case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                break;

                 case 9:
                controller_saveAsBinary("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);
    return 0;
}


int menu();
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
