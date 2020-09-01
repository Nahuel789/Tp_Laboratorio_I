#include <stdio.h>
#include <stdlib.h>
#include "funcionesMatematicas.h"

int primerNum()
{
    int num1;
    printf("Ingrese primer num: \n");
    scanf("%d",&num1);

    return num1;
}


int segundoNum()
{
    int num2;
    printf("Ingrese primer num: \n");
    scanf("%d",&num2);

    return num2;
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

float division(int a,int b)

{
    int resp;
    resp=(float)a/b;

    return resp;
}

int factorialNumber(int a)
{
    int factorialNum;

    for(int i=1; i<=a; i++)
    {

        factorialNum=factorialNum*i;


    }

    return factorialNum;



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


