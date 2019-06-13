#include "Employee.h"
#include "validaciones.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int employee_setId(Employee* this,int id){
    int todoOk=0;

    if(this!=NULL && id>0){
        this->id=id;
        todoOk=1;
    }

    return todoOk;
}

int employee_getId(Employee* this,int* id){
    int todoOk=0;

    if(this!=NULL && id!=NULL){
        *id=this->id;
        todoOk=1;
    }

    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre){
    int todoOk=0;

    if(this!=NULL && nombre!=NULL && strlen(nombre)>3){
        strcpy(this->nombre,nombre);
        todoOk=1;
    }

    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre){
    int todoOk=0;

    if(this!=NULL && nombre!=NULL){
        strcpy(nombre,this->nombre);
        todoOk=1;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int todoOk=0;

    if(this!=NULL && horasTrabajadas>0){
        this->horasTrabajadas=horasTrabajadas;
        todoOk=1;
    }

    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    int todoOk=0;

    if(this!=NULL && horasTrabajadas!=NULL){
        *horasTrabajadas=this->horasTrabajadas;
        todoOk=1;
    }

    return todoOk;
}
int employee_setSueldo(Employee* this,float sueldo){
    int todoOk=0;

    if(this!=NULL && sueldo>0){
        this->sueldo=sueldo;
        todoOk=1;
    }

    return todoOk;
}

int employee_getSueldo(Employee* this,float* sueldo){
    int todoOk=0;

    if(this!=NULL && sueldo!=NULL){
        *sueldo=this->sueldo;
        todoOk=1;
    }

    return todoOk;
}

Employee* employee_new(){
    Employee* this= (Employee*)malloc(sizeof(Employee));

    if(this!=NULL){
        this->id=0;
        strcpy(this->nombre,"");
        this->horasTrabajadas=0;
        this->sueldo=0;
    }

    return this;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr){
    Employee* this;

    if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL){
        this = employee_new();
        if(this!=NULL){
            if(!employee_setId(this,atoi(idStr)) ||
              (!employee_setNombre(this,nombreStr)) ||
              (!employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr))) ||
              (!employee_setSueldo(this,atoi(sueldoStr)))){
                free(this);
                this=NULL;
            }
        }
    }

    return this;
}

void mostrarEmpleado(Employee* emp){
    if(emp!=NULL){
        printf("%4d %15s %8d %14.2f\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
    }else{
        printf("No hay empleados para mostrar\n");
    }
}

int ordenarPorId(void* emp1,void* emp2){
    int retorno=0;
    Employee* p1=employee_new();
    Employee* p2=employee_new();

    if(emp1!=NULL && emp2!=NULL){
        p1=(Employee*)emp1;
        p2=(Employee*)emp2;

        if(p1->id > p2->id){
            retorno=1;
        }else if(p1->id < p2->id){
            retorno=-1;
        }else{
            retorno=0;
        }
    }

    return retorno;
}

int ordenarPorNombre(void* emp1,void* emp2){
    int retorno=0;
    Employee* p1=employee_new();
    Employee* p2=employee_new();

    if(emp1!=NULL && emp2!=NULL){
        p1=(Employee*)emp1;
        p2=(Employee*)emp2;

        if(stricmp(p1->nombre,p2->nombre)==1){
            retorno=1;
        }else if(stricmp(p1->nombre,p2->nombre)==-1){
            retorno=-1;
        }else{
            retorno=0;
        }
    }

    return retorno;
}

int ordenarPorHoras(void* emp1,void* emp2){
    int retorno=0;
    Employee* p1=employee_new();
    Employee* p2=employee_new();

    if(emp1!=NULL && emp2!=NULL){
        p1=(Employee*)emp1;
        p2=(Employee*)emp2;

        if(p1->horasTrabajadas > p2->horasTrabajadas){
            retorno=1;
        }else if(p1->horasTrabajadas < p2->horasTrabajadas){
            retorno=-1;
        }else{
            retorno=0;
        }
    }

    return retorno;
}

int ordenarPorSueldo(void* emp1,void* emp2){
    int retorno=0;
    Employee* p1=employee_new();
    Employee* p2=employee_new();

    if(emp1!=NULL && emp2!=NULL){
        p1=(Employee*)emp1;
        p2=(Employee*)emp2;

        if(p1->sueldo > p2->sueldo){
            retorno=1;
        }else if(p1->sueldo < p2->sueldo){
            retorno=-1;
        }else{
            retorno=0;
        }
    }

    return retorno;
}

int menu(){
    int opcion=0;
    int validacion=0;

    system("cls");
    printf("*** MENU TP3 ***\n\n");
    printf("1. Cargar los datos (modo texto)\n");
    printf("2. Cargar los datos (modo binario)\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos en archivo (modo texto)\n");
    printf("9. Guardar los datos en archivo (modo binario)\n");
    printf("10. Salir\n");

    validacion=getInt(&opcion,"Ingrese opcion","ERROR, Re",1,10);
    while(validacion==-1){
        validacion=getInt(&opcion,"Ingrese opcion","ERROR, Re",1,10);
    }

    return opcion;
}

int menuModificar(){
    int opcion=0;
    int validacion=0;

    system("cls");
    printf("*** MENU MODIFICAR EMPLEADO ***\n\n");
    printf("1. Modificar Nombre\n");
    printf("2. Modificar Horas trabajadas\n");
    printf("3. Modificar Sueldo\n");
    printf("4. Salir\n");

    validacion=getInt(&opcion,"Ingrese opcion","ERROR, Re",1,4);
    while(validacion==-1){
        validacion=getInt(&opcion,"Ingrese opcion","ERROR, Re",1,4);
    }

    return opcion;
}

int menuOrdenar(){
    int opcion=0;
    int validacion=0;

    system("cls");
    printf("*** MENU ORDENAR LISTADO ***\n\n");
    printf("1. Ordenar por Id [Menor a Mayor]\n");
    printf("2. Ordenar por Id [Mayor a Menor]\n");
    printf("3. Ordenar por Nombre [A-Z]\n");
    printf("4. Ordenar por Nombre [Z-A]\n");
    printf("5. Ordenar por Horas trabajadas [Menor a Mayor]\n");
    printf("6. Ordenar por Horas trabajadas [Mayor a Menor]\n");
    printf("7. Ordenar por Sueldo [Menor a Mayor]\n");
    printf("8. Ordenar por Sueldo [Mayor a Menor]\n");
    printf("9. Salir\n");

    validacion=getInt(&opcion,"Ingrese opcion","ERROR, Re",1,9);
    while(validacion==-1){
        validacion=getInt(&opcion,"Ingrese opcion","ERROR, Re",1,9);
    }

    return opcion;
}
