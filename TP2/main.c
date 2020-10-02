#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define TAM 3


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;





int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int changeEmployeeById(Employee* list,int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
void printEmployee(Employee employee);
int findFree(Employee* list,int len);


int main()
{
    int opcion;
    int legajo =1;
    char auxNombre[100];
    char auxApellido[100];
    float auxSalario;
    int auxSector;
    int auxId;
    char seguir= 's';


    Employee list[TAM]={{1,"Nahuel","Carbajal",200000,1,0},{2,"Beatriz","Vasconcelos",2001100,1,0},{3,"Fernanda","Ferrari",20040000,2,0}};


    do
    {

        system("cls");

        utn_getNumero(&opcion,"****Menu de Opciones****\n\n1- Altas\n2-Modificar\n3-Baja\n4-Informar:\n1.Listado de empleados\n2.Total y promedio de los salarios, y empleados que superan el salario promedio\n5-Salir\n","Error vuelva a ingresar\n",1,5,1);

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


            break;

        case 2:


            utn_getNumero(&auxId,"Ingrese el id que desea modificar: \n","Error id invalido\n",1,1000,2);

            changeEmployeeById(list,TAM,auxId);


            break;



        case 3:

            utn_getNumero(&auxId,"Ingrese el id que desea borrar: \n","Error id invalido\n",1,1000,2);
            removeEmployee(list,TAM,auxId);

            break;
        case 4:

           // sortEmployees(list,TAM,1);
            printEmployees(list,TAM);
            system("pause");
       //  sortEmployees(list,TAM,0);
          //  printEmployees(list,TAM);

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





int initEmployees(Employee* list, int len)
{
    int retorno=1;


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


    int retorno=1;
    Employee nuevaPersona; //AUXILIAR
    int indice;
    if(list != NULL && len > 0 && id > 0 && name !=NULL && lastName != NULL && salary >=0 && sector >= 1  )
    {

        system("cls");

        indice= findFree(list,len);

        if(indice == -1)
        {
            printf("SISTEMA COMPLETO\n");

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
    int retorno = 1;
    int indice;
    char rta;

    system("cls");

    if(list != NULL && len > 0)
    {

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
                retorno = 2;
            }








        }
        else
        {
            printf("Legajo mal ingresado\n");
        }

    }

    return retorno;







}

//Ordena el array de empleados por apellido
// sector de manera ascendente o descendente.

int sortEmployees(Employee* list, int len, int order) // asc 1 desc 0
{
    int retorno = -1;
    Employee aux;



    if(list != NULL && len > 0 )
    {

        for(int i=0; i<len-1; i++)
        {

            for(int j=i+1; i<len; j++)
            {

                if((list[i].sector > list[j].sector && order)||(list[i].sector < list[j].sector && !order)||(list[i].sector == list[j].sector) && ((strcmp(list[i].lastName,list[j].lastName)> 0 && order)|| (!order && strcmp(list[i].lastName,list[j].lastName)< 0)))
                {
                    aux.sector=list[i].sector;
                    list[i].sector=list[j].sector;
                    list[j].sector=aux.sector;

                }




            }





        }

        retorno = 0;

    }



    return retorno;

}

int printEmployees(Employee* list, int length)
{
    int retorno=1;
    int flag=0;

    if(list != NULL && length > 0 )
    {
        retorno=0;


        printf("ID NOMBRE  APELLIDO  SALARIO   SECTOR \n\n");

        for(int i=0; i<length; i++)
        {

            if(list[i].isEmpty == 0)
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


    printf("%d  %s  %s   %f    %d\n", employee.id,employee.name,employee.lastName,employee.salary,employee.sector);


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


    int retorno = 1;
    int indice;
    int opcion;
    char auxCadena[1000];
    float auxFloat;
    int auxInt;


    if(list != NULL && len > 0 && id >= 1 )
    {

        if((indice=findEmployeeById(list,len,id)) != -1)
        {



            system("cls");

            printEmployee(list[indice]);

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

                utn_getNumero(&auxInt,"Ingrese el nuevo sector :\n","Error . Reingrese",1,50,2);
                list[indice].sector=auxInt;




                break;




            }

        }
        else
        {
            printf("NO HAY LEGAJO\n");
        }









    }





    return retorno;






}
