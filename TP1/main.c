#include <stdio.h>
#include <stdlib.h>
#include "Hamie.h"

int main()
{
    int opc, flagX=0, flagY=0, flagOpc3=0, flagOpc4=0;
    float x=0, y=0, suma, resta, division, multiplicacion;
    char seguir='s';

    do
    {
        system("cls");

        printf("********************************\n");
        printf("**         Bienvenido         **\n");
        printf("********************************\n\n");
        printf("Menu de opciones: \n\n");
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
            printf("\te) Calcular la factorial (%.2f!)y(%.2f!)\n",x,y);
            break;
        case 2:
            printf("\ta) Se ha calculado la suma\n");
            printf("\tb) Se ha calculado la resta\n");
            printf("\tc) Se ha calculado la division\n");
            printf("\td) Se ha calculado la multiplicacion\n");
            printf("\te) Se han calculado los factoriales de %.2f! y %.2f!\n",x,y);
        }
        printf("4. Informar resultados: \n");

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
        printf("5. Salir\n\n");
        printf("Ingrese una opcion: \n");

        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
            printf("Ingrese el nuevo valor de x:\n");
            scanf("%f", &x);
            flagX=1;
            break;
        case 2:
            printf("Ingrese el nuevo valor de y:\n");
            scanf("%f", &y);
            flagY=1;
            flagOpc3=1;
            break;
        case 3:
            flagOpc3=2;
            suma=sumaDosNumeros(x,y);
            resta=restaDosNumeros(x,y);
            division=divisionDosNumeros(x,y);
            multiplicacion=multiplicacionDosNumeros(x,y);
            factorialNumero(x);
            factorialNumero(y);
            break;
        case 4:
            flagOpc4=1;
            break;
        case 5:
            printf("El programa ha finalizado\n\n");
            seguir='n';
            system("pause");
            break;
        default:
            printf("\tLa opcion ingresada es invalida\n");
            system("pause");
            break;
        }
    }
    while(seguir=='s');
    return 0;
}
