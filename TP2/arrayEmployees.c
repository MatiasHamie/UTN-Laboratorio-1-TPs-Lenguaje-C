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
#define ASCENDING 1
#define DESCENDING 0

int mainMenu()
{
    int option;

    printf("*** MENU ABM TP 2 ***\n\n");
    printf("1- Alta empleado\n");
    printf("2- Modificacion empleado\n");
    printf("3- Baja empleado\n");
    printf("4- Informes\n");
    printf("5- Salir\n\n");
    printf("Ingrese option: ");
    scanf("%d",&option);

    return option;
}

int reportsMenu()
{
    int option;

    system("cls");
    printf("*** MENU de Informes *** \n\n");
    printf("1- Lista de empleados por orden alfabetico\n");
    printf("2- Lista de total y promedio de salarios\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&option);

    return option;
}

int initEmployees(Employee* employees, int lengthEmp)
{
    for(int i=0;i<lengthEmp;i++){
        employees[i].isEmpty=EMPTY;
    }
    return 0;
}

int addEmployee(Employee* employees, int lengthEmp, int id, char name[],char lastName[],float salary,int sector)
{
    int validation=0;
    int index;

    index=findEmptyIndex(employees,LENEMP);

    if(index>=0){
        employees[index].id=id;
        strcpy(employees[index].name,name);
        strcpy(employees[index].lastName,lastName);
        employees[index].salary=salary;
        employees[index].sector=sector;
    }else{
        validation=-1;
    }
    return validation;
}

int findEmptyIndex(Employee* employees, int lengthEmp)
{
    int index=-1;

    for(int i=0;i<lengthEmp;i++){
        if(employees[i].isEmpty==EMPTY){
            index=i;
            break;
        }
    }
    return index;
}

int findEmployeeById(Employee* employees, int lengthEmp,int id)
{
    int index;

    for(int i=0;i<lengthEmp;i++){
        if(employees[i].id=id){

        }
    }

    return NULL;
}

int removeEmployee(Employee* employees, int lengthEmp, int id)
{
 return -1;
}

int modifyEmployee(Employee* employees, int lengthEmp, int id)
{
 return -1;
}

int sortingMenu(Employee* employees, int lengthEmp)
{
    int order;

    system("cls");
    printf("Elegir [A-Z] o [Z-A]");
    printf("1- [A-Z]\n");
    printf("2- [Z-A]\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&order);

    sortEmployees(employees,lengthEmp,order);

    return order;
}

int sortEmployees(Employee* employees, int lengthEmp, int order)
{
    int sortingOk=0;

    for(int i=0;i<lengthEmp-1;i++){
        for(int j=0;j<lengthEmp;j++){
            if((strlen(employees[i].lastName)==0)||(employees[i].sector==0)){
                sortingOk=-1;
                printf("Error, NULL Pointer\n");
                system("Pause");
            }else{
                if(employees[i].isEmpty==OCUPPIED){
                    if(order==ASCENDING){
                        if(employees[i].sector>employees[j].sector){
                            bubbleSorting(employees,LENEMP,i,j);
                        }else{
                            if((employees[i].sector==employees[j].sector)&&(stricmp(employees[i].lastName,employees[j].lastName)>0)){
                                bubbleSorting(employees,LENEMP,i,j);
                            }
                        }
                    }else{
                        if(employees[i].sector<employees[j].sector){
                            bubbleSorting(employees,LENEMP,i,j);
                        }else{
                            if((employees[i].sector==employees[j].sector)&&(stricmp(employees[i].lastName,employees[j].lastName)<0)){
                                bubbleSorting(employees,LENEMP,i,j);
                            }
                        }
                    }
                }
            }
        }
    }

    return sortingOk;
}

void bubbleSorting(Employee* employees, int length, int i, int j)
{
    Employee auxEmp;

    auxEmp=employees[i];
    employees[i]=employees[j];
    employees[j]=auxEmp;
}

int printEmployees(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec)
{
    system("cls");

    printf("%8s %12s %12s %8s %10s\n", "Sector", "Legajo", "Apellido", "Nombre", "Sueldo");
    printf("%8s %12s %12s %8s %10s\n", "------", "------", "--------", "------", "------");

    for(int i=0;i<lengthEmp;i++){
        printEmployee(employees[i],sectors,lengthSec);
    }

    return 0;
}

int printEmployee(Employee employee, Sectors* sectors, int lengthSec)
{
    int index;

    system("cls");

    printf("%8s %12s %12s %8s %10s\n", "Sector", "Legajo", "Apellido", "Nombre", "Sueldo");
    printf("%8s %12s %12s %8s %10s\n", "------", "------", "--------", "------", "------");

    index=getSectorDescription(employee.id,sectors,lengthSec);

    printf("%8s %12d %12s %8s %10.2f\n", sectors[index].description, employee.id, employee.lastName, employee.name, employee.salary);

    return 0;
}

int getRandomId(Employee* employees, int length, int* requestedRandomId)
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


int getSectorDescription(int idEmployee, Sectors* sectors, int lengthSec)
{
    int index=-1;

    for(int i=0;i<lengthSec;i++){
        if(idEmployee==sectors[i].id){
            index=i;
        }
    }

    return index;
}

int chooseSector(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int todoOk=0;
    int isInteger=0;
    int numeroValidado=0;
    char auxNum[10]={'0'};

    do{
        if(todoOk==0){
            printf("%s : ", message);
            scanf("%s", auxNum);
        }

        isInteger=isInt(auxNum);

        if(isInteger){
            numeroValidado=atoi(auxNum);

            if(numeroValidado<lowLimit || numeroValidado>hiLimit){
                printf("%s : ", eMessage);
                scanf("%s", auxNum);
                todoOk=-1;
            }else{
                todoOk=1;
            }
        }else{
            printf("Ingrese solo numeros!\n");
            scanf("%s", auxNum);
            system("pause");
            todoOk=-1;
        }

    }while(todoOk!=1);

    *input=numeroValidado;

    return todoOk;
}
