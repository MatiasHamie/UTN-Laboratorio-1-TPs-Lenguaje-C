#include <stdio.h>
#include <stdlib.h>
#include "Hamie.h"

int main()
{
    /*
        **************************************************************
        Variables tipo INT:
        X e Y: Son los numeros a ingresar por el usuario

        Flags:  Cada flag tiene la funcion de mostrar un tipo de menu
                u otro, y la diferencia entre ellos es mostrar
                los datos del enunciado como solo texto
                o con las variables A y B actualizadas.

        Opc:    Opcion elegida por el usuario
        **************************************************************
    */
    int x, y, opc, flagX=0, flagY=0, flagOpc3=0, flagOpc4=0, suma, resta, multiplicacion;

    /*
        ****************************************************************
        Variable tipo FLOAT:
        division = resultado de la operacion dividirDosNumeros;
        ****************************************************************
    */
    float division;

    /*
        **************************************************************
        Variable tipo CHAR: condicion para seguir ITERANDO
        La unica forma de que se modifique a un valor distinto de 's'
        es que el usuario elija la opcion 5. Salir
        **************************************************************
    */
    char seguir='s';

    do
    {
        system("cls");//Borro la pantalla cada vez que itero

        printf("********************************\n");
        printf("**         Bienvenido         **\n");
        printf("********************************\n\n");
        printf("Menu de opciones: \n\n");

        /*
          ****************************************************
            flagX y flagY:
            En 0: Muestra solo enunciado
            En 1: Muestra el enunciado con las variables X e Y
                  modificadas por el usuario
          ****************************************************
        */

        if(flagX==1)
        {
            printf("1. Ingrese el 1er operando A=%d\n",x);
        }
        else
        {
            printf("1. Ingrese el 1er operando A=x\n");
        }

        if(flagY==1)
        {
            printf("2. Ingrese el 2do operando B=%d\n",y);
        }
        else
        {
            printf("2. Ingrese el 2do operando B=y\n");
        }

        printf("3. Calcular todas las operaciones: \n");

        /*
          *************************************************************
            flagOpc3:
            En 0: Muestra solo enunciado
            En 1: Muestra el enunciado con las variables X e Y
                  modificadas por el usuario
            En 2: Muestra que las operaciones aritmeticas se realizaron

            Condicionales.
            - Si el denominador Y vale 0, muestra "no se ha podido calcular la division"
            - Si X e Y o alguno de los dos es negativo, muestra "No se ha podido calcular el factorial de.."
          **************************************************************
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
                printf("\ta) Calcular la suma (%d)+(%d)\n",x,y);
                printf("\tb) Calcular la resta (%d)-(%d)\n",x,y);
                printf("\tc) Calcular la division (%d)/(%d)\n",x,y);
                printf("\td) Calcular la multiplicacion (%d)*(%d)\n",x,y);
                printf("\te) Calcular el factorial (%d!)y(%d!)\n",x,y);
                break;
            case 2:
                printf("\ta) Se ha calculado la suma\n");
                printf("\tb) Se ha calculado la resta\n");

                if(y==0)
                {
                    printf("\tc) No se pudo calcular la division\n");
                }
                else
                {
                    printf("\tc) Se ha calculado la division\n");
                }

                printf("\tc) Se ha calculado la division\n");
                printf("\td) Se ha calculado la multiplicacion\n");

                if(x>=0 && y>=0)
                {
                    printf("\te) Se han calculado los factoriales de %d! y %d!\n",x,y);
                }
                else
                {
                    if(x<0 && y<0)
                    {
                        printf("\te) No se han podido calcular los factoriales de %d! y %d!\n",x,y);
                    }
                    else
                    {
                        if(x<0 && y>=0)
                        {
                            printf("\te) No se ha podido calcular el factorial de %d! y se ha calculado el factorial de %d!\n",x,y);
                        }
                        else
                        {
                            printf("\te) Se ha calculado el factorial de %d! y no se ha podido calcular el factorial de %d!\n",x,y);;
                        }
                    }
                }
                break;
        }
        printf("4. Informar resultados: \n");

        /*
          **********************************************************************************************
            flagOpc4:
            En 0: Muestra solo enunciado

            En 1: Muestra los resultados de las operaciones aritmeticas con condicionales que verifican:

            Si el denomoinador (operando B) es 0: "muestra la leyenda que no se puede dividir por 0"

            Si alguno de los dos numeros (A o B) es menor a 0 (lease negativo): Muestro la leyenda
            "Los factoriales de X e Y no se pudieron calcular por ser negativos"
            "El factorial de (X o Y) no se pudo calcular por ser negativo"
          **********************************************************************************************
        */

        if(flagOpc4==1)
        {
            printf("\ta) El resultado de (%d)+(%d) es: %d\n",x,y,suma);
            printf("\tb) El resultado de (%d)-(%d) es: %d\n",x,y,resta);

            if(y==0)
            {
                printf("\tc) No es posible dividir por cero\n");
            }
            else
            {
                printf("\tc) El resultado de (%d)/(%d) es: %.2f\n",x,y,division);
            }
            printf("\td) El resultado de (%d)*(%d) es: %d\n",x,y,multiplicacion);

            if(x>=0 && y>=0)
            {
                printf("\te) El factorial de %d es: %.0f y el factorial de %d es: %.0f\n",x,factorialNumero(x),y,factorialNumero(y));
            }
            else
            {
                if(x<0 && y<0)
                {
                    printf("\te) El factorial de %d y el factorial de %d no se pudieron calcular por ser negativos AMBOS numeros\n",x,y);
                }
                else
                {
                    if(x<0 && y>=0)
                    {
                        printf("\te) El factorial de %d no se pudo calcular por ser negativo y el factorial de %d es: %.0f\n",x,y,factorialNumero(y));
                    }
                    else
                    {
                        printf("\te) El factorial de %d es: %.0f y el factorial de %d no se pudo calcular por ser negativo\n",x,factorialNumero(x),y);
                    }
                }
            }
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
                scanf("%d", &x);
                flagX=1;
                if(flagY==1)
                {
                    flagOpc3=1;
                }
                break;
            case 2:
                /*
                    Pido el valor de B (o Y) y modifico el printf(punto 2-) del menu.
                    Como ya ingrese el segundo valor, pongo el flagOpc3 en 1
                    agregando los valores X y Y al menu de la opcion 3
                */

                printf("Ingrese el nuevo valor de y:\n");
                scanf("%d", &y);
                flagY=1;
                if(flagX==1)
                {
                    flagOpc3=1;
                }
                break;
            case 3:
                /*
                    Verifico que se hayan ingresado los operandos A y B para
                    poder continuar, esto es posible verificando el valor de
                    flagX y flagY
                */

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

                /*
                    En el caso de que ambos hayan sido ingresados:
                    - Calcula TODAS las operaciones.
                    - flagOpc3 = 2: Imprime "ya se ha realizado la suma, resta, etc..
                */

                suma=sumaDosNumeros(x,y);
                resta=restaDosNumeros(x,y);
                division=divisionDosNumeros(x,y);
                multiplicacion=multiplicacionDosNumeros(x,y);
                flagOpc3=2;
                break;
            case 4:
                /*
                    Verifico que se hayan calculado las operaciones para poder mostrarlas,
                    "flagOpc3" se pone en 2 cuando se apreta la opcion "3. Calcular las operaciones".
                    En el caso de que no se hayan calculado las operaciones (flagOpc3!=2) advierto y vuelvo a pedir opciones.
                    En el caso de que SI se hayan calculado, muestro los resultados
                */

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
                /*Reinicio los valores de todos los flags y los numeros X e Y para comenzar de vuelta.*/
                x=0;
                y=0;
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
