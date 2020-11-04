#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;


    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"r");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromText(pFile,pArrayListEmployee))
            {
                retorno=0;
            }


            fclose(pFile);
        }


    }
    else
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *

 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;


    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"r");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            {
                retorno=0;
            }


            fclose(pFile);
        }

    }
    else
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    if(pArrayListEmployee != NULL)
    {

        employee_add(pArrayListEmployee);

        retorno=0;

    }
    return retorno;
}
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    if(pArrayListEmployee != NULL)
    {
        employee_edit(pArrayListEmployee);
        retorno=0;
    }

    return retorno;
}
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    if(pArrayListEmployee != NULL)
    {
        employe_delete(pArrayListEmployee);
        retorno=0;
    }

    return retorno;
}
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    if(pArrayListEmployee != NULL)
    {
        employee_listEmployees(pArrayListEmployee);
        retorno=0;
    }

    return retorno;
}
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    if(pArrayListEmployee != NULL)
    {

   // employee_sort(pArrayListEmployee);
    retorno=0;
    }
    return retorno;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    int tam;
    int* auxId=NULL;
    int* auxSueldo=NULL;
    int* auxHorasTrabajadas=NULL;
    char nombre[25];
    Employee* pEmpleado;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"w");

        if(pFile != NULL)
        {
            tam=ll_len(pArrayListEmployee);

            for(int i=0; i<tam; i++)
            {
                pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
                if(!employee_getId(pEmpleado,auxId) && !employee_getHorasTrabajadas(pEmpleado,auxHorasTrabajadas) && !employee_getSueldo(pEmpleado,auxSueldo) && !employee_getNombre(pEmpleado,nombre))
                {
                    fprintf(pFile,"%d,%s,%d,%d\n",auxId,nombre,auxHorasTrabajadas,auxSueldo);
                    retorno=0;
                }
            }

            fclose(pFile);
        }
    }
    return retorno;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    int tam;
    Employee* pEmpleado;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"wb");

        if(pFile != NULL)
        {
            tam=ll_len(pArrayListEmployee);

            for(int i=0; i<tam; i++)
            {
                pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
                fwrite(pEmpleado,sizeof(Employee),1,pFile);
                retorno=0;
            }

            fclose(pFile);
        }
    }
    return retorno;
}
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
