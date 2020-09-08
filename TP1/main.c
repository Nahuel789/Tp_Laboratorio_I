#include <stdio.h>
#include <stdlib.h>
#include "funcionesMatematicas.h"

int main()
{
    char seguir='s';
    char confirm;
    int num1;
    int num2;
    int respuestaSuma;
    int respuestaResta;
    int respuestaMultiplicacion;
    float respuestaDivision;
    long long int respuestaFactorialUno;
    long long int respuestaFactorialDos;
    int flagNum1=0;
    int flagNum2=0;
    int flagRespuestas=0;

    do{
       system("cls");

        switch(menuDeOpciones())
        {
            case 1:
            num1=pedirNum();
            flagNum1=1;
            system("pause");
            break;
        case 2:
            if(flagNum1)
            {
            num2=pedirNum();
            flagNum2=1;
            system("pause");

            }
            else
            {
                printf("Primero ingresar el primer num \n");
                system("pause");
            }

            break;


        case 3:
            if(flagNum2 && flagNum1)
            {
            respuestaSuma = sumador(num1,num2);
            respuestaResta = restador(num1,num2);
            respuestaMultiplicacion = multiplicador(num1,num2);
            respuestaDivision = divisor(num1,num2);
            respuestaFactorialUno = factorialNumber(num1);
            respuestaFactorialDos = factorialNumber(num2);
            flagRespuestas=1;

            }else
            {
                printf("Primero ingresar los numeros de la opcion 1) y 2)\n");
            }


            system("pause");

            break;

        case 4:
            if(flagRespuestas==1)
            {
            printf("a) El resultado de A+B es: %d\n",respuestaSuma);
            printf("b) El resultado de A-B es: %d\n",respuestaResta);
            if(num2!=0)
            {
                printf("c) El resultado de A/B es: %.2f\n",respuestaDivision);
            }else
            {
                printf("c) No se puede dividir por cero. \n");
            }

            printf("d) El resultado de A*B es: %d\n",respuestaMultiplicacion);
            printf("e) El factorial de A es: %lld y El factorial de B es: %lld\n",respuestaFactorialUno,respuestaFactorialDos);
            system("pause");

            }
            else
            {
                printf("Primero elegir la opcion 3) antes de mostrar las respuestas \n");
                system("pause");
            }

            break;


        case 5:
            printf("Desea salir? s/n : \n");
            fflush(stdin);
            scanf("%c",&confirm);
            while(confirm!='s' && confirm!='n')
            {

            printf("Opcion Invalida, ingresar s/n : \n");
            fflush(stdin);
            scanf("%c",&confirm);

            }
            if(confirm=='s')
            {
                seguir='n';
            }
            system("pause");
            break;

        default:
            fflush(stdin);
            printf("Opcion Invalida!\n");
            system("pause");
            break;

        }

    }while(seguir=='s');


    return 0;
}


