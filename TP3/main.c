#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
    char seguir='s';

    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        system("cls");

        switch(menu())
        {
        case 1:
            if(!controller_loadFromText("data.csv",listaEmpleados))
            {
                printf("cargo ok\n");
                system("pause");
            }
            break;

        case 2:
            system("cls");
            controller_loadFromBinary("data.bin",listaEmpleados);
            system("pause");
            break;

        case 3:
            system("cls");
            controller_addEmployee(listaEmpleados);
            system("pause");
            break;

        case 4:
            system("cls");
            controller_editEmployee(listaEmpleados);
            system("pause");
            break;

        case 5:
            system("cls");
            controller_removeEmployee(listaEmpleados);
            system("pause");
            break;

        case 6:
            system("cls");
            controller_ListEmployee(listaEmpleados);
            system("pause");
            break;

        case 7:
            system("cls");
            controller_sortEmployee(listaEmpleados);
            system("pause");
            break;

        case 8:
            system("cls");
            if(!controller_saveAsText("data.csv",listaEmpleados))
            {
                printf("Guardado como texto con exito\n");
            }
            system("pause");
            break;

        case 9:
            system("cls");
            if(!controller_saveAsBinary("data.bin",listaEmpleados))
            {
              printf("Guardado como binario con exito\n");
            }
            system("pause");
            break;

        case 10:
            system("cls");

            seguir='n';
            break;
        }
    }
    while(seguir == 's');
    return 0;
}


