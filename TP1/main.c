#include <stdio.h>
#include <stdlib.h>
#include "funcionesMatematicas.h"

int main()
{
    char seguir='s';
    char confirm;
    int y;
    int x;
    int respuestaSuma;
    int respuestaResta;
    int respuestaMultiplicacion;
    float respuestaDivision;
    int respuestaFactorial;


    do{
       system("cls");

        switch(menuDeOpciones())
        {
            case 1:
            x=primerNum();
            system("pause");
            break;
        case 2:
            y=segundoNum();
            system("pause");
            break;


        case 3:

            respuestaSuma = sumador(x,y);
            respuestaResta = restador(x,y);
            respuestaMultiplicacion = multiplicador(x,y);
            respuestaDivision = division(x,y);
            respuestaFactorial = factorialNumber(x);
            system("pause");

            break;

        case 4:
            printf("a)El resultado de A+B es: %d\n",respuestaSuma);
            printf("b) El resultado de A-B es: %d\n",respuestaResta);
            printf("c) El resultado de A/B es: %f o “No es posible dividir por cero”\n",respuestaDivision);
            printf("d) El resultado de A*B es: %d\n",respuestaMultiplicacion);
            printf("e) El factorial de A es: %d y El factorial de B es: r2\n",respuestaFactorial);
            system("pause");
            break;


        case 5:
            printf("Desea salir? s/n : \n");
            fflush(stdin);
            scanf("%c",&confirm);
            if(confirm=='s')
            {
                seguir='n';
            }
            system("pause");
            break;

        default:
            printf("Opcion Invalida!\n");
            system("pause");
            break;

        }

    }while(seguir=='s');



    return 0;
}


