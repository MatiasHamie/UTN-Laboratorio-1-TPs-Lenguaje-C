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

int mainMenu(){
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

int reportsMenu(){
    int option;

    system("cls");
    printf("*** MENU de Informes *** \n\n");
    printf("1- Lista de empleados por orden alfabetico\n");
    printf("2- Lista de total y promedio de salarios\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&option);

    return option;
}

int initEmployees(Employee* employees, int lengthEmp){
    for(int i=0;i<lengthEmp;i++){
        employees[i].isEmpty=EMPTY;
    }
    return 0;
}

int addEmployee(Employee* employees, int lengthEmp, int id, char name[],char lastName[],float salary,int sector){
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

int findEmptyIndex(Employee* employees, int lengthEmp){
    int index=-1;

    for(int i=0;i<lengthEmp;i++){
        if(employees[i].isEmpty==EMPTY){
            index=i;
            break;
        }
    }
    return index;
}

int findEmployeeById(Employee* employees, int lengthEmp,int id){
    int index;

    for(int i=0;i<lengthEmp;i++){
        if(employees[i].id==id){
            index=i;
        }
    }
    return index;
}

int removeEmployee(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec){
    int idEmployee;
    int validation=0;
    int index;
    char confirm;

    printf("Ingrese legajo del empleado a eliminar: ");
    scanf("%d",&idEmployee);

    index=findEmployeeById(employees,lengthEmp,idEmployee);

    if(index==-1){
        printf("No se ha encontrado al empleado\n");
        system("pause");
        validation=-1;
    }else{
        printEmployee(employees[index],sectors,lengthSec);
        printf("Confirma eliminacion?\n");
        printf("Ingrese s/n: ");
        scanf("%c",&confirm);

        if(confirm=='s'){
            employees[index].isEmpty=EMPTY;
            validation=0;
        }else{
            validation=-1;
        }
    }
    return validation;
}

int modifyEmployee(Employee* employees, int lengthEmp, Sectors* sectors,int lengthSec){
    int validation=0;
    int index;
    int idEmployee;
    int option;

    printf("Ingrese legajo del empleado a modificar: ");
    scanf("%d",&idEmployee);

    index=findEmployeeById(employees,lengthEmp,idEmployee);

    if(index==-1){
        printf("No se ha encontrado al empleado\n");
        system("pause");
        validation=-1;
    }else{
        printEmployee(employees[index],sectors,lengthSec);

        option=modifyMenu();

        switch(option){
            case 1:
                modifyNameEmployee(employees[index],sectors,lengthSec);
                break;
            case 2:
                modifyLastNameEmployee(employees[index],sectors,lengthSec);
                break;
            case 3:
                modifySalaryEmployee(employees[index],sectors,lengthSec);
                break;
            case 4:
                modifySectorEmployee(employees[index],sectors,lengthSec);
                break;
            default:
                printf("Opcion Invalida\n");
                break;
        }
    }
    return validation;
}

int modifyMenu(){
    int option;

    printf("Que desea modificar?\n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Salario\n");
    printf("4- Sector\n");

    printf("Ingrese opcion: ");
    scanf("%d",&option);

    return option;
}

int modifyNameEmployee(Employee employee, Sectors* sectors, int lengthSec){
    char auxName[51];
    char confirm;
    int validation;

    validation=getString(auxName,"Ingrese el NUEVO nombre del empleado","Nombre invalido, cantidad de caracteres [min 2 - max 50]",2,50);

    if(validation==1){
        printEmployee(employee,sectors,lengthSec);
        printf("Confirma NUEVO nombre: %s? s/n",auxName);
        scanf("%c",&confirm);

        if(confirm=='s'){
            strcpy(employee.name,auxName);
            validation=0;
        }else{
            validation=-1;
        }
    }else{
        validation=-1;
    }
    return validation;
}

int modifyLastNameEmployee(Employee employee, Sectors* sectors, int lengthSec){
    char auxLastName[51];
    char confirm;
    int validation;

    validation=getString(auxLastName,"Ingrese el NUEVO apellido del empleado","Apellido invalido, cantidad de caracteres [min 2 - max 50]",2,50);

    if(validation==1){
        printEmployee(employee,sectors,lengthSec);
        printf("Confirma NUEVO apellido: %s? s/n",auxLastName);
        scanf("%c",&confirm);

        if(confirm=='s'){
            strcpy(employee.lastName,auxLastName);
            validation=0;
        }else{
            validation=-1;
        }
    }else{
        validation=-1;
    }

    return validation;
}

int modifySalaryEmployee(Employee employee, Sectors* sectors, int lengthSec){
    float auxSalary;
    int validation;
    char confirm;

    validation=getFloat(&auxSalary,"Ingrese el NUEVO salario del empleado","Salario invalido, rango [min 1 - max 999999]",1,100000);

    if(validation==1){
        printEmployee(employee,sectors,lengthSec);
        printf("Confirma NUEVO salario: %.2f? s/n",auxSalary);
        scanf("%c",&confirm);

        if(confirm=='s'){
            employee.salary=auxSalary;
            validation=0;
        }else{
            validation=-1;
        }
    }else{
        validation=-1;
    }

    return validation;
}

int modifySectorEmployee(Employee employee, Sectors* sectors, int lengthSec){
    int auxIdSector;
    int validation;

    validation=chooseSector(&auxIdSector,"Elija el NUEVO sector al que pertenece el empleado","Opcion invalida, rango [1-5]",1,5,sectors,LENSEC);

    if(validation==1){
        employee.sector=auxIdSector;
    }else{
        validation=-1;
    }

    return validation;
}

void hardcodeSectors(Sectors* sectors,int lengthSec){
    Sectors auxSectors[]={
    {1,"RRHH"},
    {2,"Finanzas"},
    {3,"Telecom."},
    {4,"Sistemas"},
    {4,"Gerencia"},
    };

    for(int i=0;i<LENSEC;i++){
        sectors[i]=auxSectors[i];
    }
}
int sortingMenu(Employee* employees, int lengthEmp){
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

int sortEmployees(Employee* employees, int lengthEmp, int order){
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

void bubbleSorting(Employee* employees, int length, int i, int j){
    Employee auxEmp;

    auxEmp=employees[i];
    employees[i]=employees[j];
    employees[j]=auxEmp;
}

int printEmployees(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec){
    system("cls");

    printf("%8s %12s %12s %8s %10s\n", "Sector", "Legajo", "Apellido", "Nombre", "Sueldo");
    printf("%8s %12s %12s %8s %10s\n", "------", "------", "--------", "------", "------");

    for(int i=0;i<lengthEmp;i++){
        printEmployee(employees[i],sectors,lengthSec);
    }

    return 0;
}

int printEmployee(Employee employee, Sectors* sectors, int lengthSec){
    int index;

    system("cls");

    printf("%8s %12s %12s %8s %10s\n", "Sector", "Legajo", "Apellido", "Nombre", "Sueldo");
    printf("%8s %12s %12s %8s %10s\n", "------", "------", "--------", "------", "------");

    index=getSectorDescription(employee.id,sectors,lengthSec);

    printf("%8s %12d %12s %8s %10.2f\n", sectors[index].description, employee.id, employee.lastName, employee.name, employee.salary);

    return 0;
}

void printSectors(Sectors* sectors, int lengthSec){
    system("cls");
    printf("*** SECTORES ***\n\n");
    for(int i=0;i<lengthSec;i++){
        if(sectors[i].id>0){
            printf("%d %4s\n",sectors[i].id, sectors[i].description);
        }
    }
}

int getRandomId(Employee* employees, int length, int* requestedRandomId){
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


int getSectorDescription(int idEmployee, Sectors* sectors, int lengthSec){
    int index=-1;

    for(int i=0;i<lengthSec;i++){
        if(idEmployee==sectors[i].id){
            index=i;
        }
    }
    return index;
}

int chooseSector(int* input,char message[],char eMessage[], int lowLimit, int hiLimit, Sectors* sectors, int lengthSec){
    int todoOk=0;
    int isInteger=0;
    int numeroValidado=0;
    char auxNum[10]={'0'};

    do{
        if(todoOk==0){
            system("cls");
            printSectors(sectors,lengthSec);
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

void hardcodeEmployees(Employee* employees, int lengthEmp){
    Employee auxEmp[]={
//    ID    Name      LastName    Salary  Sector  IsEmpty
    {1092,"Matias",   "Hamie",    25000,    1,       1},
    {1123,"Juan",     "Diaz",     25124,    2,       1},
    {1241,"Martin",   "Fernandez",25123,    1,       1},
    {1232,"Sabrina",  "Carrasco", 27918,    3,       1},
    {1541,"Alejandra","Salerno",  30000,    1,       1},
    {1142,"Marcos",   "Riso",     21023,    2,       1},
    {1985,"Jesica",   "Gauto",    41020,    4,       1},
    {2003,"Nicolas",  "Pardo",    40123,    5,       1},
    {2010,"Bruno",    "Mujica",   33653,    2,       1},
    {1405,"Sol",      "Muñoz",    23023,    4,       1},
    {3001,"Federico", "Vitali",   23023,    3,       1},
    {2999,"Alberto",  "Riobo",    23023,    5,       1},
    };

    for(int i=0;i<lengthEmp;i++){
        employees[i]=auxEmp[i];
    }
}
