#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "menu.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee) //CARGA DE ARCHIVO DE TEXTO
{
    int retorno=-1;
    FILE* pFile;


    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"r");//ABRE EL ARCHIVO

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromText(pFile,pArrayListEmployee)) //PARSEA LOS DATOS
            {
                retorno=0; //EXITO
            }


            fclose(pFile); //CIERRE DE ARCHIVO
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
    FILE* pFile=NULL;


    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"rb"); //ABRE EL ARCHIVO

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee)) // PARSEA LOS DATOS BINARIOS
            {
                retorno=0; // EXITO
            }
        }

    }

    else
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    fclose(pFile); //CIERRE DEL ARCHIVO

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


        if(!employee_add(pArrayListEmployee)) //ALTA EMPLEADO
        {
        retorno=0; //EXITO
        }


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
        if(!employee_edit(pArrayListEmployee)) //EDITAR EMPLEADOS
        {
        retorno=0; //EXITO
        }
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
        if(!employe_delete(pArrayListEmployee)) //REMUEVE UN EMPLEADO DE LA LISTA
        {
            retorno=0; //EXITO
        }

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
        if(!employee_listEmployees(pArrayListEmployee)) //LISTA DE EMPLEADOS
        {
        retorno=0; //EXITO
        }
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
    int aux;

    if(pArrayListEmployee != NULL)
    {
        system("cls");

        switch(menuSort()) //MENU DE ORDENAMIENTO
        {
        case 1:
            system("cls");
            if(!utn_getNumero(&aux,"Ingrese el orden (1.ascendente/0.descendente): \n","Error. Reingrese : \n",0,1,3))
            {
                if(!ll_sort(pArrayListEmployee,employee_sortById,aux))
                {
                    printf("Ordenamiento por ID realizado con exito\n");
                    retorno=0; //EXITO
                }
                else
                {
                    printf("Fallo al ordenar por id\n");
                }
            }


            break;
        case 2:
            system("cls");
            if(!utn_getNumero(&aux,"Ingrese el orden (1.ascendente/0.descendente): \n","Error. Reingrese : \n",0,1,3))
            {
                if(!ll_sort(pArrayListEmployee,employee_sortByName,aux))
                {
                    printf("Ordenamiento por nombre realizado con exito\n");
                    retorno=0; //EXITO
                }
                else
                {
                    printf("Fallo al ordenar por nombre\n");
                }
            }
            break;

        case 3:
            system("cls");
            if(!utn_getNumero(&aux,"Ingrese el orden (1.ascendente/0.descendente): \n","Error. Reingrese : \n",0,1,3))
            {

                if(!ll_sort(pArrayListEmployee,employee_sortByHoursWorked,aux))
                {
                    printf("Ordenamiento por horas realizado con exito\n");
                    retorno=0;//EXITO
                }
                else
                {
                    printf("Fallo al ordenar por horas\n");
                }

            }
            break;

        case 4:
            system("cls");
            if(!utn_getNumero(&aux,"Ingrese el orden (1.ascendente/0.descendente): \n","Error. Reingrese : \n",0,1,3))
            {
                if(!ll_sort(pArrayListEmployee,employee_sortBySalary,aux))
                {
                    printf("Ordenamiento por salario realizado con exito\n");
                    retorno=0;//EXITO
                }
                else
                {
                    printf("Fallo al ordenar por salario\n");
                }

            }
            break;
        }


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
    int auxId;
    int auxSueldo;
    int auxHorasTrabajadas;
    char nombre[25];
    Employee* pEmpleado=NULL;
    tam=ll_len(pArrayListEmployee);

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"w"); //ABRE EL ARCHIVO EN EL QUE VA A GUARDAR LA INFORMACION

        if(pFile != NULL)
        {
            fprintf(pFile,"id,nombre,horas Trabajadas,sueldo\n");

            for(int i=0; i<tam; i++)
            {
                pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

                if(pEmpleado != NULL)
                {
                    if(!employee_getId(pEmpleado,&auxId) && !employee_getHorasTrabajadas(pEmpleado,&auxHorasTrabajadas) && !employee_getSueldo(pEmpleado,&auxSueldo) && !employee_getNombre(pEmpleado,nombre))
                    {
                        fprintf(pFile,"%d,%s,%d,%d\n",auxId,nombre,auxHorasTrabajadas,auxSueldo);
                        retorno=0; //EXITO
                    }

                }
            }
            fclose(pFile); //CIERRE DE ARCHIVO
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
    tam=ll_len(pArrayListEmployee);

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"wb"); //ABRE EL ARCHIVO EN EL QUE VA A GUARDAR LA INFORMACION

        if(pFile != NULL)
        {
            for(int i=0; i<tam; i++)
            {
                pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

                if(pEmpleado != NULL)
                {
                    fwrite(pEmpleado,sizeof(Employee),1,pFile);
                    retorno=0; //EXITO
                }

            }

            fclose(pFile); //CIERRA EL ARCHIVO
        }
    }
    return retorno;
}
