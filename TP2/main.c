#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "arrayEmployees.h"

#define LENEMP 11
#define LENSEC 4

int main()
{
    char continueWith='s';
    char confirm;

    Employee listEmp[LENEMP];
    Sector listSec[LENSEC];

    initEmployees(listEmp,LENEMP);
    initSectors(listSec,LENSEC);

    do{
        system("cls");
        switch(mainMenu()){
            case 1:
                addEmployee(listEmp,LENEMP,listSec,LENSEC);
                system("pause");
                break;
            case 2:
                modifyEmployee(listEmp,TAMALM,listSec,LENSEC);
                system("pause");
                break;
            case 3:
                removeEmployee(listEmp,LENEMP);
                system("pause");
                break;
            case 4:
                reports(listEmp,LENEMP,listSec,LENSEC);
                system("pause");
                break;
            case 5:
                printf("Esta seguro que desea salir? s/n\n");
                fflush(stdin);
                confirm=getche();

                if(tolower(confirm)=='s'){
                    continueWith='n';
                    printf("Programa finalizado..!\n");
                    system("pause");
                }
                break;
        }
    }while(continueWith=='s');

    return 0;
}
