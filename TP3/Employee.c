#include "Employee.h"
#include <stdlib.h>
#include <string.h>

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

int employee_add(LinkedList* pArray)
{
    int retorno=-1;

    if(pArray != NULL)
    {


    }






   return retorno;
}
