#include "Employee.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

Employee* employee_new()
{

    Employee* nuevoEmpleado=NULL;

    nuevoEmpleado=(Employee*)malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id=0;
        strcpy(nuevoEmpleado->nombre,"");
        nuevoEmpleado->horasTrabajadas='0';
        nuevoEmpleado->sueldo=0;
    }
    return nuevoEmpleado;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* this=NULL;

    this=employee_new();

    if(idStr!= NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldo!=NULL)
    {
        if(!(!employee_setId(this,atoi(idStr)) && !employee_setNombre(this,nombreStr) && !employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) && !employee_setSueldo(this,atoi(sueldo))))
        {

            employee_delete(this);
            this=NULL;

        }

    }

    return this;
}
void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{
    int retorno=-1;

    if(this !=NULL && id>=0)
    {
        this->id=id;
        retorno=0;
    }

    return retorno;

}
int employee_getId(Employee* this,int* id)
{
    int retorno=-1;

    if(this !=NULL && id !=NULL )
    {
        *id=this->id;
        retorno=0;
    }


    return retorno;

}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }

    return retorno;

}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL && nombre !=NULL)
    {
        nombre=this->nombre;
        retorno=0;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;

    if(this !=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;

    if(this!=NULL && sueldo>=0)
    {

        this->sueldo=sueldo;
        retorno=0;

    }

    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;

    if(this!=NULL && sueldo !=NULL)
    {

        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_add(LinkedList* this)
{
    int retorno=-1;
    Employee* pEmpleado=NULL;
    char nombre[128];
    char horasTrabajadas[128];
    char sueldo[128];
    char id[128];
    int nextId=proximoId();


    if(this != NULL)
    {

        itoa(nextId,id,10);

        if(!utn_getCadena(nombre,128,1,"Ingrese el nombre del empleado: ","Error,reingrese: "))
        {
            if(!utn_getCadena(horasTrabajadas,128,1,"Ingrese las horas trabajadas por este empleado : ","Error.Reingrese: "))
            {
                if(!utn_getCadena(sueldo,128,1,"Ingrese el sueldo del empleado: ","Error.Reingrese: "))
                {
                    pEmpleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);

                    if(pEmpleado != NULL)
                    {
                        ll_add(this,pEmpleado);
                        retorno=0;
                    }
                }
            }
        }

    }
    return retorno;
}
int employee_edit(LinkedList* this)
{
    int retorno=-1;
    int aux;
    int indice;

    Employee* pEmpleado=NULL;

    if(this != NULL)
    {
        //employe_print();

        utn_getNumero(&aux,"Ingrese el id que quiere: \n","Error.Reingrese:",1,ll_len(this),1);

        indice=employee_findById(this,aux);

        if(indice != -1)
        {
            pEmpleado=ll_get(this,indice);

            if(pEmpleado != NULL)
            {
                switch(menuModificacion())
                {
                case 1 :
                    system("cls");
                    employee_changeName(pEmpleado);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    employee_changeSalary(pEmpleado);
                    system("pause");
                    break;

                case 3:
                    system("cls");
                    employee_changeHoursWorked(pEmpleado);
                    system("pause");
                    break;
                }

                 retorno=0;
            }


        }

    }

    return retorno;
}


int employee_findById(LinkedList* this, int id)
{
    int indice = -1;
    int len = ll_len(this);
    int auxId;
    Employee* empleado;

    for(int i = 0; i < len; i++)
    {
        empleado = (Employee*)ll_get(this,i);
        employee_getId(empleado,&auxId);

        if(auxId == id)
        {
            indice = i;
            break;
        }
    }
    if(indice == -1)
    {
        printf("No se encontro el id\n");
    }
    return indice;
}
int employee_changeName(Employee* this)
{
    int retorno=-1;
    char nombre[50];

    if(this != NULL)
    {
        utn_getCadena(nombre,50,1,"Ingrese el nuevo nombre: \n","Error,Reingrese:\n");
        employee_setNombre(this,nombre);
        retorno=0;
    }
    return retorno;
}
int employee_changeSalary(Employee* this)
{
    int retorno=-1;
    int salary;

    if(this != NULL)
    {
    utn_getNumero(&salary,"Ingrese el nuevo salario del empleado: \n","Error.Reingrese: \n",0,10000000,1);
    employee_setSueldo(this,salary);
    retorno=0;
    }

    return retorno;
}
int employee_changeHoursWorked(Employee* this)
{
    int retorno=-1;
    int hoursWorked;

    if(this != NULL)
    {
    utn_getNumero(&hoursWorked,"Ingrese el nuevo salario: \n","Error.Reingrese: \n",0,160,1);
    employee_setHorasTrabajadas(this,hoursWorked);
    retorno=0;
    }
    return retorno;
}
int employe_delete(LinkedList* this)
{
    int retorno=-1;
    int aux;
    int indice;
    Employee* pEmpleado=NULL;

    if(this != NULL)
    {
        utn_getNumero(&aux,"Ingrese el indice del empleado que quiere eliminar : \n","Error.Reingrese: \n",1,ll_len(this),1);

        indice=employee_findById(this,aux);

        if(indice != -1)
        {
            ll_remove(this,indice);
            retorno=0;
        }
    }
    return retorno;
}


int employee_listEmployees(LinkedList* this)
{
    int retorno=-1;
    Employee* pEmpleado=NULL;

    if(this != NULL)
    {
        for(int i=0;i<ll_len(this);i++)
        {
           pEmpleado=(Employee*)ll_get(this,i);
           employee_print(pEmpleado);
           retorno=0;
        }


    }
    return retorno;
}

int employee_print(Employee* this)
{
    int retorno=-1;

    if(this != NULL)
    {
        printf("%d    %s    %d       %d\n", this->id,this->nombre,this->horasTrabajadas,this->sueldo);
    }

    return retorno;


}
/*
int employee_sort(LinkedList* this)
{
    int retorno=-1;

    if(this != NULL)
    {
        for(int i=0;i<ll_len();i++)
        {


            for()





        }

        retorno=0;
    }

    return retorno;

}
*/
