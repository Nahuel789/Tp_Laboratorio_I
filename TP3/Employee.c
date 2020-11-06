#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "utn.h"
#include "menu.h"

Employee* employee_new() //CREA UN EMPLEADO SIN DATOS
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
    return nuevoEmpleado; //PUNTERO EMPLEADO

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo) //CREA EMPLEADO CON PARAMETROS
{
    Employee* this=NULL;

    this=employee_new();

    if(idStr!= NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldo!=NULL)
    {
        if(!(!employee_setId(this,atoi(idStr)) && !employee_setNombre(this,nombreStr) && !employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) && !employee_setSueldo(this,atoi(sueldo))))
        {
            employee_delete(this); //ELIMINA EL PUNTERO AUXILIAR
        }

    }

    return this;
}
void employee_delete(Employee* this) //ELIMINA UN EMPLEADO
{
    free(this);
    this=NULL;
}

int employee_setId(Employee* this,int id) //CARGA UN ID EN UN EMPLEADO
{
    int retorno=-1;

    if(this !=NULL && id>=0)
    {
        this->id=id;
        retorno=0; //EXITO
    }

    return retorno;

}
int employee_getId(Employee* this,int* id) //NOS DA UN ID GUARDADO
{
    int retorno=-1;

    if(this !=NULL && id !=NULL )
    {
        *id=this->id;
        retorno=0; //EXITO
    }


    return retorno;

}

int employee_setNombre(Employee* this,char* nombre) //CARGA UN NOMBRE EN UN EMPLEADO
{
    int retorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0; //EXITO
    }

    return retorno;

}
int employee_getNombre(Employee* this,char* nombre) //NOS DA UN NOMBRE GUARDADO
{
    int retorno=-1;

    if(this!=NULL && nombre !=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0; //EXITO
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas) //CARGA HORAS TRABAJADAS EN UN EMPLEADO
{
    int retorno=-1;

    if(this !=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0; //EXITO
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas) //NOS DA HORAS TRABAJADAS
{
    int retorno=-1;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;//EXITO
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo) //CARGA UN SUELDO EN UN EMPLEADO
{
    int retorno=-1;

    if(this!=NULL && sueldo>=0)
    {

        this->sueldo=sueldo;
        retorno=0;//EXITO

    }

    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo) //OBTIENE UN SUELDO GUARDADO
{
    int retorno=-1;

    if(this!=NULL && sueldo !=NULL)
    {

        *sueldo=this->sueldo;
        retorno=0;//EXITO
    }
    return retorno;
}

int employee_add(LinkedList* this) //AGREGA UN EMPLEADO A LA LINKEDLIST
{
    int retorno=-1;
    Employee* pEmpleado=NULL;
    char nombre[128];
    char horasTrabajadas[128];
    char sueldo[128];
    char id[128];

    if(this != NULL)
    {
        printf("......................................................................................................................\n");
        printf("................................................ALTA DE EMPLEADO......................................................\n");
        printf("......................................................................................................................\n\n");
        sprintf(id,"%d",proximoId());

        if(!utn_getCadena(nombre,sizeof(nombre),1,"Ingrese el nombre del empleado: ","Error,reingrese: "))
        {
            if(!utn_getCadena(horasTrabajadas,sizeof(horasTrabajadas),1,"Ingrese las horas trabajadas por este empleado : ","Error.Reingrese: "))
            {
                if(!utn_getCadena(sueldo,sizeof(sueldo),1,"Ingrese el sueldo del empleado: ","Error.Reingrese: "))
                {
                    pEmpleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);

                    if(pEmpleado != NULL)
                    {
                        if(!ll_add(this,pEmpleado))
                        {
                            retorno=0;//EXITO
                        }
                    }
                }
            }
        }

    }
    return retorno;
}
int employee_edit(LinkedList* this) //EDITA UN EMPLEADO
{
    int retorno=-1;
    int aux;
    int indice;

    Employee* pEmpleado=NULL;

    if(this != NULL)
    {
        printf("......................................................................................................................\n");
        printf(".............................................EDICION DE EMPLEADO......................................................\n");
        printf("......................................................................................................................\n\n");

        employee_listEmployees(this);
        utn_getNumero(&aux,"Ingrese el id que quiere: \n","Error.Reingrese:",1,ll_len(this),1);

        indice=employee_findById(this,aux);

        if(indice != -1)
        {
            pEmpleado=ll_get(this,indice);

            if(pEmpleado != NULL)
            {
                switch(menuModificacion()) //MENU MODIFICACION
                {
                case 1 :
                    system("cls");
                    if(!employee_changeName(pEmpleado))
                    {
                        retorno=0;//EXITO
                    }
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    if(!employee_changeSalary(pEmpleado))
                    {
                        retorno=0;//EXITO
                    }
                    system("pause");
                    break;

                case 3:
                    system("cls");
                    if(!employee_changeHoursWorked(pEmpleado))
                    {
                        retorno=0;//EXITO
                    }
                    system("pause");
                    break;

                }
            }
        }
        else
        {
            printf("No hay empleado que mostrar\n");
        }
    }
    return retorno;
}
int employee_findById(LinkedList* this, int id) //BUSCA EMPLEADOS POR ID
{
    int indice = -1;
    int len = ll_len(this);
    int auxId;
    Employee* empleado;

    for(int i = 0; i < len; i++)
    {
        empleado=(Employee*)ll_get(this,i);
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
int employee_changeName(Employee* this) //CAMBIA EL NOMBRE DE UN EMPLEADO
{
    int retorno=-1;
    char nombre[50];

    if(this != NULL)
    {
        if(!utn_getCadena(nombre,50,1,"Ingrese el nuevo nombre: \n","Error,Reingrese:\n"))
        {
            if(!employee_setNombre(this,nombre))
            {
                retorno=0;//EXITO
            }
        }


    }
    return retorno;
}
int employee_changeSalary(Employee* this)//CAMBIA EL SALARIO DE UN EMPLEADO
{
    int retorno=-1;
    int salary;

    if(this != NULL)
    {
        if(!utn_getNumero(&salary,"Ingrese el nuevo salario del empleado: \n","Error.Reingrese: \n",0,10000000,1))
        {
            if(!employee_setSueldo(this,salary))
            {
                retorno=0;//EXITO
            }

        }
    }

    return retorno;
}
int employee_changeHoursWorked(Employee* this)//CAMBIA LAS HORAS DE UN EMPLEADO
{
    int retorno=-1;
    int hoursWorked;

    if(this != NULL)
    {
        if(!utn_getNumero(&hoursWorked,"Ingrese el nuevo salario: \n","Error.Reingrese: \n",0,500,1))
        {
            if(!employee_setHorasTrabajadas(this,hoursWorked))
            {
                retorno=0;//EXITO
            }

        }
    }
    return retorno;
}
int employe_delete(LinkedList* this)//ELIMINA UN EMPLEADO EN EL INDICE SELECCIONADO
{
    int retorno=-1;
    int aux;
    int indice;

    if(this != NULL)
    {
        printf("......................................................................................................................\n");
        printf(".............................................BAJA DE EMPLEADO.........................................................\n");
        printf("......................................................................................................................\n\n");

        employee_listEmployees(this);

        if(!utn_getNumero(&aux,"Ingrese el indice del empleado que quiere eliminar : \n","Error.Reingrese: \n",1,ll_len(this),1))
        {

            indice=employee_findById(this,aux);

            if(indice != -1)
            {
                if(!ll_remove(this,indice))
                {
                    retorno=0;//EXITO
                }
            }


        }

    }
    return retorno;
}
int employee_listEmployees(LinkedList* this) //LISTA EMPLEADOS ACTIVOS
{
    int retorno=-1;
    Employee* pEmpleado=NULL;
    int auxId;
    char nombre[50];
    int horasTrabajadas;
    int salario;
    int flag=0;

    if(this != NULL && ll_len(this) > 0 )
    {

        printf(".............................................................................................................\n");
        printf(".............................................LISTA DE EMPLEADOS..............................................\n");
        printf(".............................................................................................................\n\n");
        printf("ID                       NOMBRE                           HORAS                                 SUELDO\n\n");
        for(int i=0; i<ll_len(this); i++)
        {
            pEmpleado=(Employee*)ll_get(this,i);

            if(pEmpleado != NULL)
            {
                if(!employee_getId(pEmpleado,&auxId))
                {
                    if(!employee_getNombre(pEmpleado,nombre))
                    {
                        if(!employee_getHorasTrabajadas(pEmpleado,&horasTrabajadas))
                        {
                            if(!employee_getSueldo(pEmpleado,&salario))
                            {
                                printf("%2d              %15s                              %2d                                 %2d \n",auxId,nombre,horasTrabajadas,salario);
                                flag=1;
                                pEmpleado=NULL;
                                retorno=0;//EXITO
                            }

                        }

                    }

                }

            }


        }


    }

    if(!flag)
    {
        printf("No hay empleados que listar\n");
    }
    return retorno;
}
int employee_sortByName(void* employeeA,void* employeeB) //COMPARA POR NOMBRE
{
    int retorno=0;
    Employee* pEmpA;
    Employee* pEmpB;

    if(employeeA != NULL && employeeB != NULL)
    {
        pEmpA=(Employee*)employeeA;
        pEmpB=(Employee*)employeeB;

        retorno=strcmp(pEmpA->nombre,pEmpB->nombre);

    }

    return retorno;
}
int employee_sortBySalary(void* employeeA,void* employeeB)//COMPARA POR SALARIO
{
    int retorno=0;
    Employee* pEmpA;
    Employee* pEmpB;

    if(employeeA != NULL && employeeB != NULL)
    {
        pEmpA=(Employee*)employeeA;
        pEmpB=(Employee*)employeeB;

        if(pEmpA->sueldo == pEmpB->sueldo)
        {
            retorno=0; //SI ES IGUAL
        }
        else if(pEmpA->sueldo > pEmpB->sueldo)
        {
            retorno=1; //SI ES MAYOR EL A
        }
        else
        {
            retorno=-1; //SI ES MENOR EL A
        }
    }

    return retorno;
}
int employee_sortById(void* employeeA,void* employeeB)//COMPARA POR ID
{
    int retorno=0;

    Employee* pEmpA;
    Employee* pEmpB;

    if(employeeA != NULL && employeeB != NULL)
    {

        pEmpA=(Employee*)employeeA;
        pEmpB=(Employee*)employeeB;


        if(pEmpA->id == pEmpB->id)
        {
            retorno=0;//SI ES IGUAL
        }
        else if(pEmpA->id > pEmpB->id)
        {
            retorno=1;//SI ES MAYOR EL A
        }
        else
        {
            retorno=-1;//SI ES MENOR EL A
        }

    }

    return retorno;
}
int employee_sortByHoursWorked(void* employeeA,void* employeeB)//COMPARA POR HORAS
{
    int retorno=0;

    Employee* pEmpA;
    Employee* pEmpB;

    if(employeeA != NULL && employeeB != NULL)
    {
        pEmpA=(Employee*)employeeA;
        pEmpB=(Employee*)employeeB;

        if(pEmpA->horasTrabajadas == pEmpB->horasTrabajadas)
        {
            retorno=0;//SI ES IGUAL
        }
        else if(pEmpA->horasTrabajadas > pEmpB->horasTrabajadas)
        {
            retorno=1;//SI ES MAYOR EL A
        }
        else
        {
            retorno=-1;//SI ES MENOR EL A
        }
    }
    return retorno;
}
/** \brief obtiene el id de manera estatica
 *
 * \return id nuevo
 *
 */
static int obtenerId()
{
    static int id=1000;
    id++;
    return id;
}
int proximoId()
{
    return obtenerId();
}
