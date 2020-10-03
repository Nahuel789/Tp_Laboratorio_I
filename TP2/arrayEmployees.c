#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployees.h"


int initEmployees(Employee* list, int len)
{
    int retorno=-1;


    if(list != NULL && len > 0 )
    {


        for(int i=0; i<len; i++)
        {

            list[i].isEmpty=1;



        }

        retorno=0;

    }


    return retorno;





}


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{


    int retorno=-1;
    Employee nuevaPersona; //AUXILIAR
    int indice;
    if(list != NULL && len > 0 && id > 0 && name !=NULL && lastName != NULL && salary >=0 && sector >= 1  )
    {

        system("cls");

        indice= findFree(list,len);

        if(indice == -1)
        {
            printf("SISTEMA COMPLETO\n");
            system("pause");

        }
        else
        {

            nuevaPersona.id=id;
            nuevaPersona.isEmpty=0;
            strncpy(nuevaPersona.name,name,sizeof(nuevaPersona.name));
            strncpy(nuevaPersona.lastName,lastName,sizeof(nuevaPersona.lastName));
            nuevaPersona.salary=salary;
            nuevaPersona.sector=sector;


            list[indice]=nuevaPersona;




            retorno=0;

        }



    }




    return retorno;


}

int findEmployeeById(Employee* list, int len,int id)
{
    int retorno = -1;

    for(int i=0; i<len; i++)
    {
        if(list[i].id == id && !list[i].isEmpty)
        {

            retorno= i;
            break;

        }


    }



    return retorno;





}
int removeEmployee(Employee* list, int len, int id)
{
    int retorno = -1;
    int indice;
    char rta;




    if(list != NULL && len > 0)
    {


        system("cls");


        if((indice=findEmployeeById(list,len,id)) != -1)
        {


            printEmployee(list[indice]);
            utn_getCaracter(&rta,"Confirma la baja? (s/n)\n","Error\n",'n','s',2);
            if(rta == 's')
            {

                list[indice].isEmpty=1;
                retorno = 0;

            }
            else
            {
                retorno = -2;
            }








        }
        else
        {
            printf("Legajo mal ingresado\n");
            system("pause");
        }

    }

    return retorno;







}




int sortEmployees(Employee* list, int len, int order) // asc 1 desc 0
{
    int retorno = -1;
    Employee aux;



    if(list != NULL && len > 0)
    {

        for(int i=0; i<len-1 ; i++)
        {

            for(int j= i+1 ; j < len ; j++)
            {

                if(!list[j].isEmpty && !list[i].isEmpty)
                {
                    if((list[i].sector > list[j].sector && order)||
                            (list[i].sector < list[j].sector && !order)||
                            ((list[i].sector == list[j].sector) &&
                             ((strcmp(list[i].lastName,list[j].lastName)> 0 && order)
                              ||(strcmp(list[i].lastName,list[j].lastName)< 0 && !order))))
                    {

                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;

                        retorno =0;



                    }




                }




            }





        }


    }


    return retorno;


}






int printEmployees(Employee* list, int length)
{
    int retorno=-1;
    int flag=0;

    if(list != NULL && length > 0 )
    {
        retorno=0;


        printf("ID   NOMBRE       APELLIDO      SALARIO    SECTOR \n\n");

        for(int i=0; i<length; i++)
        {

            if(!list[i].isEmpty)
            {

                printEmployee(list[i]);
                flag=1;// FLAG PARA VER SI TODOS ESTAN VACIOS

            }



        }


        if(!flag)
        {

            printf("No hay personas para mostrar en la lista \n");


        }


    }


    return retorno;


}


void printEmployee(Employee employee)
{


    printf("%d  %10s  %10s   %.2f    %d\n", employee.id,employee.name,employee.lastName,employee.salary,employee.sector);


}


int findFree(Employee* list,int len)
{
    int retorno = -1;


    for(int i=0; i< len; i++)
    {

        if(list[i].isEmpty)
        {

            retorno = i;
            break;


        }



    }

    return retorno;
}


int changeEmployeeById(Employee* list,int len,int id)
{


    int retorno = -1;
    int indice;
    int opcion;
    char auxCadena[1000];
    float auxFloat;
    int auxInt;

    if(list != NULL && len > 0 && id >= 1 )
    {



        if((indice=findEmployeeById(list,len,id)) != -1)
        {


            printEmployees(list,len);
            system("pause");


            retorno = 0;




            system("cls");


            utn_getNumero(&opcion,"Ingrese  lo que desea modificar:\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n","Error .Reingrese",1,4,2);

            switch(opcion)
            {

            case 1 :

                utn_getCadena(auxCadena,sizeof(auxCadena),2,"ingrese el nuevo nombre :\n","Error.Reingrese\n");
                strncpy(list[indice].name,auxCadena,sizeof(list[indice].name));



                break;


            case 2:
                utn_getCadena(auxCadena,sizeof(auxCadena),2,"ingrese el nuevo apellido :\n","Error.Reingrese\n");
                strncpy(list[indice].lastName,auxCadena,sizeof(list[indice].lastName));

                break;

            case 3:
                utn_getNumeroFloat(&auxFloat,"Ingrese el nuevo salario : \n","Error.Reingrese",0,10000000,2);

                list[indice].salary=auxFloat;

                break;

            case 4:

                utn_getNumero(&auxInt,"Ingrese el nuevo sector :\n","Error . Reingrese",1,5,2);
                list[indice].sector=auxInt;




                break;




            }

        }
        else
        {
            printf("NO HAY LEGAJO\n");
            system("pause");
        }









    }





    return retorno;






}


int dataEmployees(Employee* list,int len)
{
    int retorno = -1;
    float promedio;
    float acumulador=0;
    int counter=0;
    int counterPromedio=0;


    if(list != NULL && len > 0 )
    {

        for(int i=0; i<len; i++)
        {
            if(!list[i].isEmpty)
            {

                acumulador += list[i].salary;
                counter++;
                retorno =0;


            }







        }
        if(counter > 0)
        {
            promedio =(float)(acumulador/counter);

            printf("el promedio es %f\n",promedio);

            printf("el total de salarios es : %.2f\n", acumulador);


        }



        for(int j=0; j<len; j++)
        {
            if(promedio < list[j].salary && list[j].isEmpty == 0)
            {

                counterPromedio++;
                retorno=0;

            }


        }
        if(counterPromedio > 1)
        {
            printf("La cantidad de empleados que superan el promedio son %d\n",counterPromedio);
        }
        else

        {
            printf("Nadie supera el promedio\n");
        }


    }



    return retorno;


}
