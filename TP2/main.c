#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "arrayEmployees.h"
#include "validaciones.h"

#define LENEMP 1000
#define LENSEC 10

int main()
{
    char continueWith='s';
    char confirm;
    char requestedName[51];
    char requestedLastName[51];
    float requestedSalary;
    int requestedRandomId;
    int requestedSector;
    int emptySpace;
    Employee employees[LENEMP];
    Sectors sectors[LENSEC];

    initEmployees(employees,LENEMP);
    hardcodeEmployees(employees,LENEMP);
    hardcodeSectors(sectors,LENSEC);

    do{
        system("cls");
        switch(mainMenu()){
            case 1:
                emptySpace=findEmptyIndex(employees,LENEMP);
                if(emptySpace>=0){
                    //Obtengo randomId del empleado
                    getRandomId(employees,LENEMP,&requestedRandomId);
                    //Obtengo nombre y despues apellido validando el largo y que sean solo solo letras
                    getString(requestedName,"Ingrese el nombre del empleado","Nombre invalido, cantidad de caracteres [min 2 - max 50]",2,50);
                    getString(requestedLastName,"Ingrese el apellido del empleado","Apellido invalido, cantidad de caracteres [min 2 - max 50]",2,50);
                    //Obtengo salario
                    getFloat(&requestedSalary,"Ingrese el salario del empleado","Salario invalido, rango [min 1 - max 999999]",1,100000);
                    //Obtengo id sector
                    chooseSector(&requestedSector,"Elija sector al que pertenece el empleado","Opcion invalida, rango [1-5]",1,5,sectors,LENSEC);
                    //Envio los datos del empleado pendiente a cargar a la funcion addEmployee
                    addEmployee(employees,LENEMP,requestedRandomId,requestedName,requestedLastName,requestedSalary,requestedSector,sectors,LENSEC);
                }else{
                    printf("No hay espacio para mas empleados..!!\n");
                }
                system("pause");
                break;
            case 2:
                emptySpace=findEmptyIndex(employees,LENEMP);

                if(emptySpace!=0){
                    modifyEmployee(employees,LENEMP,sectors,LENSEC);
                }else{
                    printf("No hay empleados para modificar..!!\n");
                }
                system("pause");
                break;

            case 3:
                if(emptySpace!=0){
                    removeEmployee(employees,LENEMP,sectors,LENSEC);
                }else{
                    printf("No hay empleados para modificar..!!\n");
                }
                system("pause");
                break;
            case 4:
               //reports(employees,LENEMP,sectors,LENSEC);
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
