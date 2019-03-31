#include <stdio.h>
#include <stdlib.h>
#include "Hamie.h"

int main()
{
    /*
        Variables tipo INT:
        Flags:  Cada flag tiene la funcion de mostrar un tipo de menu
                u otro, y la diferencia entre ellos es mostrar
                los datos del enunciado como solo texto
                o con las variables A y B actualizadas.

        Opc:    Opcion elegida por el usuario
    */
    int opc, flagX=0, flagY=0, flagOpc3=0, flagOpc4=0;

    /*
        Variables tipo FLOAT:
        X e Y: son los numeros a operar
    */
    float x, y, suma, resta, division, multiplicacion;

    // Variable tipo CHAR: condicion para seguir ITERANDO
    char seguir='s';

    do
    {
        system("cls");//Borro la pantalla cada vez que itero

        printf("********************************\n");
        printf("**         Bienvenido         **\n");
        printf("********************************\n\n");
        printf("Menu de opciones: \n\n");

        /*
            flagX y flagY:
            En 0: Muestra solo enunciado
            En 1: Muestra el enunciado con las variables X e Y
                  modificadas por el usuario
        */

        if(flagX==1)
        {
            printf("1. Ingrese el 1er operando A=%.2f\n",x);
        }
        else
        {
            printf("1. Ingrese el 1er operando A=x\n");
        }

        if(flagY==1)
        {
            printf("2. Ingrese el 2do operando B=%.2f\n",y);
        }
        else
        {
            printf("2. Ingrese el 2do operando B=y\n");
        }

        printf("3. Calcular todas las operaciones: \n");

        /*
            flagOpc3:
            En 0: Muestra solo enunciado
            En 1: Muestra el enunciado con las variables X e Y
                  modificadas por el usuario
            En 2: Muestra que las operaciones aritmeticas se realizaron
        */

        switch(flagOpc3)
        {
            case 0:
                printf("\ta) Calcular la suma (A+B)\n");
                printf("\tb) Calcular la resta (A-B)\n");
                printf("\tc) Calcular la division (A/B)\n");
                printf("\td) Calcular la multiplicacion (A*B)\n");
                printf("\te) Calcular el factorial (A!) y (B!)\n");
                break;
            case 1:
                printf("\ta) Calcular la suma (%.2f)+(%.2f)\n",x,y);
                printf("\tb) Calcular la resta (%.2f)-(%.2f)\n",x,y);
                printf("\tc) Calcular la division (%.2f)/(%.2f)\n",x,y);
                printf("\td) Calcular la multiplicacion (%.2f)*(%.2f)\n",x,y);
                printf("\te) Calcular el factorial (%.2f!)y(%.2f!)\n",x,y);
                break;
            case 2:
                printf("\ta) Se ha calculado la suma\n");
                printf("\tb) Se ha calculado la resta\n");
                printf("\tc) Se ha calculado la division\n");
                printf("\td) Se ha calculado la multiplicacion\n");
                printf("\te) Se han calculado los factoriales de %.2f! y %.2f!\n",x,y);
        }
        printf("4. Informar resultados: \n");

        /*
            flagOpc4:
            En 0: Muestra solo enunciado
            En 1: Muestra los resultados de las operaciones aritmeticas con un condicional
                  que verifica que si el denominador ingresado por el usuario es 0
                  muestra la leyenda que no se puede dividir
        */

        if(flagOpc4==1)
        {
            printf("\ta) El resultado de (%.2f)+(%.2f) es: %.2f\n",x,y,suma);
            printf("\tb) El resultado de (%.2f)-(%.2f) es: %.2f\n",x,y,resta);

            if(y==0)
            {
                printf("\tc) No es posible dividir por cero\n");
            }
            else
            {
                printf("\tc) El resultado de (%.2f)/(%.2f) es: %.2f\n",x,y,division);
            }
            printf("\td) El resultado de (%.2f)*(%.2f) es: %.2f\n",x,y,multiplicacion);
            printf("\te) El factorial de %.2f es: %.2f y el factorial de %.2f es: %.2f\n",x,factorialNumero(x),y,factorialNumero(y));
        }
        else
        {
            printf("\ta) El resultado de A+B es: r\n");
            printf("\tb) El resultado de A-B es: r\n");
            printf("\tc) El resultado de A/B es: r\n");
            printf("\td) El resultado de A*B es: r\n");
            printf("\te) El factorial de A es: r1 y El factorial de B es: r2\n");
        }
        printf("5. Salir\n");
        printf("6. Reiniciar todos los valores\n\n");
        printf("Ingrese una opcion: \n");

        scanf("%d",&opc);//Guardar la opcion elegida en la variable opc

        switch(opc)
        {
            case 1://Pido el valor de A (o X) y modifico el printf (punto 1-) del menu
                printf("Ingrese el nuevo valor de x:\n");
                scanf("%f", &x);
                flagX=1;
                break;
            case 2:
                /*Pido el valor de B (o Y) y modifico el printf(punto 2-) del menu.
                  Como ya ingrese el segundo valor, pongo el flagOpc3 en 1
                  agregando los valores X y Y al menu de la opcion 3*/

                printf("Ingrese el nuevo valor de y:\n");
                scanf("%f", &y);
                flagY=1;
                break;
            case 3:
                /*Verifico que se hayan ingresado los operandos A y B para
                  poder continuar.*/

                if(flagX==0 && flagY==0)
                {
                    printf("ERROR, Debe ingresar el operando A y el operando B para continuar\n\n");
                    system("pause");
                    break;
                }
                    if(flagX==0)
                    {
                        printf("ERROR, Debe ingresar el operando A para continuar\n\n");
                        system("pause");
                        break;
                    }
                    else
                    {
                        if(flagY==0)
                        {
                            printf("ERROR, Debe ingresar el operando B para continuar\n\n");
                            system("pause");
                            break;
                        }
                    }

                /*En el caso de que ambos hayan sido ingresados:
                  - Calcula TODAS las operaciones.
                  - flagOpc3 = 2: Imprime "ya se ha realizado la suma, resta, etc..*/

                suma=sumaDosNumeros(x,y);
                resta=restaDosNumeros(x,y);
                division=divisionDosNumeros(x,y);
                multiplicacion=multiplicacionDosNumeros(x,y);
                factorialNumero(x);
                factorialNumero(y);
                flagOpc3=2;
                break;
            case 4:
                /*Verifico que se hayan calculado las operaciones para poder mostrarlas,
                  En el caso de que no se hayan calculado las operaciones advierto y vuelvo a pedir opciones.*/

                if(flagOpc3!=2)
                {
                   printf("Debe calcular los resultados antes de querer mostrarlos!!\n\n");
                   system("pause");
                   break;
                }
                else
                {
                   flagOpc4=1;
                }
                break;
            case 5://Modifico el condicional de iteracion para terminar
                printf("El programa ha finalizado\n\n");
                seguir='n';
                system("pause");
                break;
            case 6:
                /*Reinicio los valores de todos los flags para comenzar de vuelta.*/
                flagX=0;
                flagY=0;
                flagOpc3=0;
                flagOpc4=0;
                break;
            default://Caso de ingresar una opcion distinta de 1 al 6
                printf("\tLa opcion ingresada es invalida\n");
                system("pause");
                break;
        }
    }
    while(seguir=='s');
    return 0;
}
