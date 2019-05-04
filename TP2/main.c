#include <stdio.h>
#include <stdlib.h>


#define OCUPPIED 1
#define EMPTY 0
#define LENEMP 11
#define LENSEC 4

int main()
{
    char continueWith='s';
    char confirm;

    eEmpleado listEmp[LENEMP];
    eSector   listSec[TAMSEC];

    initEmployees(listEmp,LENEMP);
    initSectors(listSec,TAMSEC);

    do{
        system("cls");
        switch(mainMenu(){
            case 1:
                addEmployee(listEmp,LENEMP,listSec,TAMSEC);
                system("pause");
                break;
            case 2:
                modifyEmployee(listEmp,TAMALM,listSec,TAMSEC);
                system("pause");
                break;
            case 3:
                removeEmployee(listEmp,LENEMP,listSec,TAMSEC);
                system("pause");
                break;
            case 4:
                reports(listEmp,LENEMP,listSec,TAMSEC);
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
