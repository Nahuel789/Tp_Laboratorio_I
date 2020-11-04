#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char id[100];
    char nombre[100];
    char horasTrabajadas[100];
    char sueldo[100];
    int aux;
    int retorno=-1;
    Employee* pEmpleado;

    if(pFile!=NULL && pArrayListEmployee !=NULL)
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);//PRIMERA LINEA

        do
        {

        aux=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        if(aux == 4)
        {
            pEmpleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);

            if(pEmpleado != NULL)
            {
                  ll_add(pArrayListEmployee,pEmpleado);
                  retorno=0;
            }

        }
        else
            break;

        }while(!feof(pFile));

        fclose(pFile);



    }
    else
    {
        printf("No existe el archivo\n");
         exit(EXIT_FAILURE);
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int aux;

    Employee* pEmpleado=NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {



        do
        {
            pEmpleado=employee_new();

            fread(pEmpleado,sizeof(Employee),1,pFile);//primeraLinea;

        aux=fread(pEmpleado,sizeof(Employee),1,pFile);

        if(aux == 1)
        {
            ll_add(pArrayListEmployee,pEmpleado);
            retorno = 0;
        }

        }while(!feof(pFile));


        fclose(pFile);

    }

    return retorno;
}
