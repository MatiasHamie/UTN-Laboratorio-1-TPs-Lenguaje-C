#include <stdio.h>
#include <stdlib.h>
#include "Hamie.h"

int main()
{
    int opc, flagX=0, flagY=0, flagOpc3=0, flagOpc4=0, x=0, y=0, suma, resta;
    float division,multiplicacion;

    do{
        system("cls");

        printf("********************************\n");
        printf("**         Bienvenido         **\n");
        printf("********************************\n\n");

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

        switch(flagOpc3){
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
                 printf("\te) Calcular la factorial (%d!)y(%d!)\n",x,y);
                 break;
            case 2:
                 printf("\ta) Se ha calculado la suma\n");
                 printf("\tb) Se ha calculado la resta\n");
                 printf("\tc) Se ha calculado la division\n");
                 printf("\td) Se ha calculado la multiplicacion\n");
                 printf("\te) Se han calculado los factoriales de %d! y %d!\n",x,y);
        }
        printf("4. Informar resultados: \n");

        if(flagOpc4==1)
        {
             printf("\ta) El resultado de (%d)+(%d) es: %d\n",x,y,suma);
             printf("\tb) El resultado de (%d)-(%d) es: %d\n",x,y,resta);
             printf("\tc) El resultado de (%d)/(%d) es: %.2f\n",x,y,division);
             printf("\td) El resultado de (%d)*(%d) es: %.2f\n",x,y,multiplicacion);
             printf("\te) El factorial de %d es: r1 y El factorial de %d es: r2\n",x,y);
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

        switch(opc){
            case 1:
                printf("Ingrese el nuevo valor de x:\n");
                scanf("%d", &x);
                flagX=1;
                break;
            case 2:
                printf("Ingrese el nuevo valor de y:\n");
                scanf("%d", &y);
                flagY=1;
                flagOpc3=1;
                break;
            case 3:
                flagOpc3=2;
                suma=sumaDosNumeros(x,y);
                resta=restaDosNumeros(x,y);
                division=divisionDosNumeros(x,y);
                multiplicacion=multiplicacionDosNumeros(x,y);
                break;
            case 4:
                flagOpc4=1;
                break;
            case 5:
                printf("El programa ha finalizado\n\n");
                system("pause");
                break;
        }
    }while(opc!=5);
    return 0;
}
