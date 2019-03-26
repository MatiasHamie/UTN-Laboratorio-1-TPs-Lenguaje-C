#include <stdio.h>
#include <stdlib.h>
int menuOperaciones ();

int main()
{
    float x, y;
    char seguir='s';

    do{
        switch(menuOperaciones()){
           case 1:
                printf("Ingrese el valor de x: \n");
                scanf("%f", &x);
                break;
           case 2:
                printf("Ingrese el valor de y: \n");
                scanf("%f", &y);
                break;
           case 3:
                printf("3. Calcular todas las operaciones\n");
                break;
           case 4:
                printf("4. Informar resultados\n");
                break;
           case 5:
                printf("5. Programa finalizado\n\n");
                seguir=getchar();
                break;
           default:
            printf("Opcion invalida...\n\n");
            break;
            }
        }while(seguir=='s');

        system("pause");

        return 0;
    }

    int menuOperaciones (){

    int opcion;
    float x=0, y=0;

        system("cls");

        printf("***** Bienvenido *****\n\n");
        printf("1. Ingresar 1er operando (A=%.2f)\n",x);
        printf("2. Ingresar 2do operando (B=%.2f)\n",y);
        printf("3. Calcular todas las operaciones\n");
            printf("a) Calcular la suma (A+B)\n");
            printf("b) Calcular la resta (A-B)\n");
            printf("c) Calcular la division (A/B)\n");
            printf("d) Calcular la multiplicacion (A*B)\n");
            printf("e) Calcular el factorial (A!)\n");
        printf("4. Informar resultados\n");
            printf("a) El resultado de A+B es: r\n");
            printf("b) El resultado de A-B es: r\n");
            printf("c) El resultado de A/B es: r\n");// o “No es posible dividir por cero”
            printf("d) El resultado de A*B es: r\n");
            printf("e) El factorial de A es: r1 y El factorial de B es: r2\n");
        printf("5. Salir\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

    return opcion;
}

