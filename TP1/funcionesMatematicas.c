#include <stdio.h>
#include <stdlib.h>
#include "funcionesMatematicas.h"

int pedirNum()
{
    int num1;
    printf("Ingrese num: \n");
    scanf("%d",&num1);

    return num1;
}




int sumador(int a,int b)
{
    int resp;

    resp=a+b;
    return resp;

}


int restador(int a,int b)
{
    int resp;

    resp=a-b;

    return resp;

}

int multiplicador(int a,int b)
{   int resp;

    resp=a*b;


    return resp;

}

float divisor(int a,int b)

{
    float resp;

    resp=(float)a/b;
    printf("%f esto es respuesta ,",resp);


    return resp;
}


int factorialNumber(int a)
{
    int fact = 0;

    if(a >= 0)
    {
       if(a==1 || a==0)
        {
            fact = 1;
        }
        else
        {
            fact = a * factorialNumber(a-1);
        }
    }

    return fact;
}

int menuDeOpciones()
{
    system("cls");

    int opcion;

    printf("***Menu de opciones***\n\n");
    printf("1) Ingresar 1er operando (A=x)\n");
    printf("2) Ingresar 2do operando (B=y)\n");
    printf("3) Calcular todas las operaciones\n");

    printf("4) Informar resultados\n");
    printf("5) Salir\n\n");
    printf("elija la opcion que desee:");
    scanf("%d",&opcion);


    return opcion;

}


