#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "arrayEmployees.h"
#include "validaciones.h"

#define OCUPPIED 1
#define EMPTY 0
#define LENEMP 11
#define LENSEC 4

int mainMenu()
{
    int opcion;

    printf("*** MENU ABM TP 2 ***\n\n");
    printf("1- Alta empleado\n");
    printf("2- Modificacion empleado\n");
    printf("3- Baja empleado\n");
    printf("4- Informes\n");
    printf("5- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int reportsMenu()
{
    int option;

    system("cls");

    printf("*** MENU de Informes *** \n\n");
    printf("1- Lista de empleados por orden alfabetico\n");
    printf("2- Lista de total y promedio de salarios\n");
    printf("\nIngrese option: ");
    scanf("%d",&option);

    return option;
}

int initEmployees(Employee* employees, int length)
{
    for(int i=0;i<length;i++){
        employees[i].isEmpty=EMPTY;
    }

    return 0;
}

int addEmployee(Employee* employees, int length, int id, char name[],char lastName[],float salary,int sector)
{
    int index;

    index=findEmptyIndex(employees,LENEMP);

    if(index>=0){
        //Obtengo legajo(id)
        getRandomId(employees,LENEMP);
        //Obtengo nombre y despues apellido validando el largo y que sean solo solo letras
        getString(employees[index].name,"Ingrese el nombre del empleado","Nombre invalido, cantidad de caracteres [min 2 - max 50]",2,50);
        getString(employees[index].lastName,"Ingrese el nombre del empleado","Apellido invalido, cantidad de caracteres [min 2 - max 50]",2,50);
        //Obtengo salario
        getFloat(employees[index].salary,"Ingrese el salario del empleado","Salario invalido, rango [min 1 - max 999999]");
    }
    return -1;
}

int findEmptyIndex(Employee* employees, int length)
{
    int index=-1;

    for(int i=0;i<length;i++){
        if(employees[i].isEmpty==EMPTY){
            index=i;
            break;
        }
    }

    return index;
}

int findEmployeeById(Employee* employees, int length,int id)
{
 return NULL;
}

int removeEmployee(Employee* employees, int length, int id)
{
 return -1;
}

int modifyEmployee(Employee* employees, int length, int id)
{
 return -1;
}

int sortEmployees(Employee* employees, int length, int order)
{
 return 0;
}

int printEmployees(Employee* employees, int length)
{
 return 0;
}

int getRandomId(Employee* employees, int length)
{
    int firstRandomId=1000;
    int index;
    int validation=-1;

    index=findEmptyIndex(employees,LENEMP);

    if(index>=0){
        employees[index].id=firstRandomId+index;
        validation=0;
    }

    return validation;
}

void bubbleSorting(Employee* employees, int length, int i, int j)
{
    Employee auxEmp;

    auxEmp=employee[i];
    employee[i]=employee[j];
    employee[j]=auxEmp;
}

