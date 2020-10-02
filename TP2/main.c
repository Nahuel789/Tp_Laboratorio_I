#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployees.h"

#define TAM 5




int main()
{
    int opcion;
    int opcion2;
    int legajo =1;
    char auxNombre[100];
    char auxApellido[100];
    float auxSalario;
    int auxSector;
    int auxId;
    char seguir= 's';
    int rta;
    int flagAdd=1;
    int flagChange=1;
    int flagRemove=1;
    int criterio;


    Employee list[TAM];

    if((initEmployees(list,TAM))== 0)
    {
        printf("INICIALIZACION EXITOSA\n");
        system("pause");
    }

    do
    {

        system("cls");

        utn_getNumero(&opcion,"****Menu de Opciones****\n\n1- Altas\n2-Modificar\n3-Baja\n4-Informar:\n5-Salir\n","Error vuelva a ingresar\n",1,5,1);

        switch(opcion)
        {
        case 1:


            utn_getCadena(auxNombre,sizeof(auxNombre),1,"Ingrese nombre: \n","ERROR\n");
            utn_getCadena(auxApellido,sizeof(auxApellido),1,"Ingrese apellido: \n","ERROR.REINGRESE APELLIDO: \n");
            utn_getNumeroFloat(&auxSalario,"Ingrese salario: \n","Error Reingrese : \n",0,10000000000,2);
            utn_getNumero(&auxSector,"Ingrese sector(numero entero del 1 al 5)","Error. Reingrese: \n",1,5,2);

            if(!(addEmployee(list,TAM,legajo,auxNombre,auxApellido,auxSalario,auxSector)))
            {
                legajo++;

            }

            flagAdd=0;

            break;

        case 2:
            if(!flagAdd)
            {

                utn_getNumero(&auxId,"Ingrese el id que desea modificar: \n","Error id invalido\n",1,1000,2);

                changeEmployeeById(list,TAM,auxId);

                flagChange=0;


            }
            else
            {
                printf("Primero agregar un empleado\n");
                system("pause");
            }




            break;



        case 3:
            if(!flagChange)
            {

                utn_getNumero(&auxId,"Ingrese el id que desea borrar: \n","Error id invalido\n",1,1000,2);
                removeEmployee(list,TAM,auxId);
                flagRemove=0;


            }
            else
            {

                printf("Primero ingresar un empleado y modificarlo\n");
                system("pause");

            }


            break;
        case 4:

            if(!flagRemove)
            {
                utn_getNumero(&opcion2,"1.Mostrar Empleados por Apellido y Sector\n2.Total y promedio de los salarios, y cuantos superan el promedio.\n","Error . reingrese: ",1,2,1);

                switch(opcion2)
                {
                case 1:


                    utn_getNumero(&criterio,"Ingrese 1 si desea ordenar ascendente o 0 para descendente:\n","Error .Reingrese el dato\n",0,1,1);

                    rta=(sortEmployees(list,TAM,criterio));

                    if(rta == 0)
                    {
                        printf("Ordeno bien\n");
                        system("pause");
                        printEmployees(list,TAM);
                        system("pause");

                    }

                    break;


                case 2:

                    dataEmployees(list,TAM);
                    system("pause");



                    break;



                }
            }
            else
            {

                printf("Primero borrar un empleado\n");
                system("pause");
            }

            break;

        case 5:

            seguir= 'n';

            break;

        default:

            printf("Opcion Invalida\n");
            system("pause");
            break;

        }

    }
    while(seguir == 's');


    return 0;
}


