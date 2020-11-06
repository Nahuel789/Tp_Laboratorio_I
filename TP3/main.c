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
    int flagLoadBin=0;
    int flagLoadText=0;
    int flagAdd=0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        system("cls");

        switch(menu())
        {
        case 1: //CARGA DE ARCHIVO DE TEXTO
            system("cls");
            if(!controller_loadFromText("data.csv",listaEmpleados))
            {
                printf("Archivo de texto cargado con exito\n");
                flagLoadText=1;
            }
            system("pause");
            break;
        case 2://CARGA DE ARCHIVO BINARIO
            system("cls");
            if(!controller_loadFromBinary("data.bin",listaEmpleados))
            {
                printf("Archivo binario cargado con exito!\n");
                flagLoadBin=1;

            }
            system("pause");
            break;

        case 3://ALTA DE EMPLEADO
            system("cls");

            if(!controller_addEmployee(listaEmpleados))
            {
                printf("Empleado cargado con exito!\n");
                flagAdd=1;
            }
            system("pause");
            break;

        case 4://EDICION DE EMPLEADOS
            system("cls");
            if(flagAdd || flagLoadBin || flagLoadText)
            {
            if(!controller_editEmployee(listaEmpleados))
            {
                printf("Empleado editado con exito!\n");
            }
            }
            else
            {
                printf("Cargar un empleado si desea editar\n");
            }

            system("pause");
            break;

        case 5://REMOVER EMPLEADO
            system("cls");

            if(flagAdd || flagLoadBin || flagLoadText)
            {

            if(!controller_removeEmployee(listaEmpleados))
            {
                printf("Empleado eliminado con exito!\n");
            }

            }else
            {
                printf("Cargar un empleado si desea remover\n");
            }
            system("pause");
            break;

        case 6://LISTA DE EMPLEADOS
            system("cls");

            if(flagAdd || flagLoadBin || flagLoadText)
            {
            controller_ListEmployee(listaEmpleados);

            }else
            {
                printf("Cargar un empleado si desea listar\n");
            }
            system("pause");
            break;

        case 7://ORDENAMIENTO DE EMPLEADOS
            system("cls");
            if(flagAdd || flagLoadBin || flagLoadText)
            {

            if(!controller_sortEmployee(listaEmpleados))
            {
                printf("ordenamiento exitoso!\n");
            }

            }else
            {
                printf("Cargar un empleado si desea ordenar\n");
            }
            system("pause");
            break;

        case 8://SALVAR COMO TEXTO
            system("cls");

            if(flagAdd || flagLoadBin || flagLoadText)
            {
            if(!controller_saveAsText("data.csv",listaEmpleados))
            {
                printf("Guardado como texto con exito!\n");
            }

            }else
            {
                printf("Cargar empleados si desea guardar en archivo csv\n");
            }

            system("pause");
            break;

        case 9://SALVAR COMO BINARIO
            system("cls");

             if(flagAdd || flagLoadBin || flagLoadText)
            {

            if(!controller_saveAsBinary("data.bin",listaEmpleados))
            {
                printf("Guardado como binario con exito!\n");
            }

            }else
            {
                printf("Cargar empleados si desea guardar en archivo binario\n");
            }
            system("pause");
            break;

        case 10: //SALIR
            system("cls");
            seguir='n';
            break;
        }
    }
    while(seguir == 's');
    return 0;
}
