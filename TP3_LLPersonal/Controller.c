#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validaciones.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int ok=-1;
    //Verifico si lo que recibo es invalido
    if(path!=NULL && pArrayListEmployee!=NULL){
        FILE* f = fopen(path,"r");
        //Verifico que el archivo exista
        if(f!=NULL){
            parser_EmployeeFromText(f,pArrayListEmployee);
            fclose(f);
            ok=1;
        }
    }else{
        ok=0;
    }
    return ok;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ok=-1;
    //Verifico si lo que recibo es invalido
    if(path!=NULL && pArrayListEmployee!=NULL){
        FILE* f = fopen(path,"rb");
        //Verifico que el archivo exista
        if(f!=NULL){
            parser_EmployeeFromBinary(f,pArrayListEmployee);
            fclose(f);
            ok=1;
        }else{
            ok=0;
        }
    }
    return ok;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ok=-1;
    if(pArrayListEmployee!=NULL){
        int auxId;
        int auxId2;
        int auxHoras;
        int largoArray=ll_len(pArrayListEmployee);
        int validacion;
        float auxSueldo;
        char auxNombre[21];

        system("cls");
        printf("*** ALTA EMPLEADO ***\n\n");

        Employee* newEmp = employee_new();
        Employee* auxEmp = employee_new();
        if(newEmp!=NULL){
            validacion=getInt(&auxId,"Ingrese ID","ERROR RANGO[1000-9999], ",1,9999);
            while(validacion==-1){
                validacion=getInt(&auxId,"Ingrese ID","ERROR RANGO[1000-9999], ",1,9999);
            }

            for(int i=0;i<largoArray;i++){
                auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(auxEmp,&auxId2);

                if(auxId2==auxId){
                    ok=2;
                    free(auxEmp);
                    break;
                }
            }

            if(ok!=2){
                validacion=getString(auxNombre,"Ingrese nombre","ERROR NOMBRE MUY LARGO, ",3,21);
                while(validacion==-1){
                    validacion=getString(auxNombre,"Ingrese nombre","ERROR NOMBRE MUY LARGO, ",3,21);
                }

                strlwr(auxNombre);
                auxNombre[0]=toupper(auxNombre[0]);

                validacion=getInt(&auxHoras,"Ingrese Horas trabajadas","ERROR RANGO[10-9999], ",10,9999);
                while(validacion==-1){
                    validacion=getInt(&auxHoras,"Ingrese Horas trabajadas","ERROR RANGO[10-9999], ",1000,9999);
                }

                validacion=getFloat(&auxSueldo,"Ingrese sueldo","ERROR RANGO[1000-100000], ",1000,100000);
                while(validacion==-1){
                    validacion=getFloat(&auxSueldo,"Ingrese sueldo","ERROR RANGO[1000-100000], ",1000,100000);
                }

                if(employee_setId(newEmp,auxId) && employee_setNombre(newEmp,auxNombre) &&
                    employee_setHorasTrabajadas(newEmp,auxHoras) && employee_setSueldo(newEmp,auxSueldo)){
                    ll_add(pArrayListEmployee,newEmp);
                    ok=1;
                    printf("Agrego el empleado ..!\n\n");
                    system("pause");
                }
            }
        }else{
            ok=0;
        }
    }
    return ok;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ok=-1;

    if(pArrayListEmployee!=NULL){
        int auxId=0;
        int auxId2=0;
        int auxHoras=0;
        int validacion=0;
        char auxNombre[21];
        char seguir='s';
        float auxSueldo=0;
        Employee* newEmp=employee_new();

        do{
            if(newEmp!=NULL){
                int largoArray=ll_len(pArrayListEmployee);
                system("cls");
                printf("*** MODIFICAR EMPLEADO ***\n\n");
                validacion=getInt(&auxId,"Ingrese el ID del empleado a editar","ERROR, Re",0,10000);

                while(validacion==-1){
                    validacion=getInt(&auxId,"Ingrese el ID del empleado a editar","ERROR, Re",0,10000);
                }
                //Primero verifico que el array tenga 1 empleado como minimo
                if(largoArray>0){
                    for(int i=0;i<largoArray;i++){
                        newEmp=(Employee*)ll_get(pArrayListEmployee,i);
                        employee_getId(newEmp,&auxId2);

                        if(auxId==auxId2){
                            switch(menuModificar()){
                            case 1:
                                mostrarEmpleado(newEmp);
                                validacion=getString(auxNombre,"Ingrese nuevo nombre","ERROR Nombre demasiado largo, ",3,21);
                                while(validacion==-1){
                                    validacion=getString(auxNombre,"Ingrese nuevo nombre","ERROR Nombre demasiado largo, ",3,21);
                                }
                                strlwr(auxNombre);
                                auxNombre[0]=toupper(auxNombre[0]);
                                employee_setNombre(newEmp,auxNombre);
                                system("pause");
                                ok=1;
                                break;
                            case 2:
                                mostrarEmpleado(newEmp);
                                validacion=getInt(&auxHoras,"Ingrese Horas trabajadas","ERROR RANGO[10-9999], ",10,9999);
                                while(validacion==-1){
                                    validacion=getInt(&auxHoras,"Ingrese Horas trabajadas","ERROR RANGO[10-9999], ",1000,9999);
                                }
                                employee_setHorasTrabajadas(newEmp,auxHoras);
                                system("pause");
                                ok=1;
                                break;
                            case 3:
                                mostrarEmpleado(newEmp);
                                validacion=getFloat(&auxSueldo,"Ingrese sueldo","ERROR RANGO[1000-100000], ",1000,100000);
                                while(validacion==-1){
                                    validacion=getFloat(&auxSueldo,"Ingrese sueldo","ERROR RANGO[1000-100000], ",1000,100000);
                                }
                                employee_setSueldo(newEmp,auxSueldo);
                                system("pause");
                                ok=1;
                                break;
                            case 4:
                                seguir='n';
                                system("pause");
                                break;
                            default:
                                printf("Opcion invalida..!!\n");
                                break;
                            }
                            break;
                        }
                        if(i==largoArray){
                            ok=2;
                        }
                    }
                }
            }else{
                ok=0;
            }

            printf("Desea modificar otro empleado? ingrese s o n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }while(seguir=='s');
    }

    return ok;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ok=-1;

    if(pArrayListEmployee!=NULL){
        ok=1;
        Employee* auxEmp;
        int len=ll_len(pArrayListEmployee);

        printf("%4s %14s %12s %12s\n","ID","NOMBRE","HRS.TRAB","SUELDO");
        printf("%4s %14s %12s %12s\n","--","------","--------","------");
        for(int i=0;i<len;i++){
            auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
            mostrarEmpleado(auxEmp);
        }
    }

    return ok;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ok=-1;

    if(pArrayListEmployee!=NULL){
        int auxId=0;
        int auxId2=0;
        int validacion=0;
        char seguir='s';
        char confirma='n';

        do{
            Employee* auxEmp=employee_new();
            if(auxEmp!=NULL){
                int largoArray=ll_len(pArrayListEmployee);
                system("cls");
                printf("*** ELIMINAR EMPLEADO ***\n\n");
                controller_ListEmployee(pArrayListEmployee);

                validacion=getInt(&auxId,"Ingrese el ID del empleado a editar","ERROR, Re",0,10000);
                while(validacion==-1){
                    validacion=getInt(&auxId,"Ingrese el ID del empleado a editar","ERROR, Re",0,10000);
                }
                //Primero verifico que el array tenga 1 empleado como minimo
                if(largoArray>0){
                    for(int i=0;i<largoArray;i++){
                        auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
                        employee_getId(auxEmp,&auxId2);

                        if(auxId==auxId2){
                            system("cls");
                            printf("*EMPLEADO A ELIMINAR*\n\n");
                            mostrarEmpleado(auxEmp);
                            printf("Confirma eliminacion del empleado? ingrese s o n: ");
                            fflush(stdin);
                            scanf("%c",&confirma);

                            if(confirma=='s'){
                                ll_remove(pArrayListEmployee,i);
                                ok=1;
                            }
                        }
                        if(i==largoArray){
                            ok=2;
                        }
                    }
                }
            }else{
                ok=0;
            }

            printf("Desea eliminar otro empleado? ingrese s o n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }while(seguir=='s');
    }
    return ok;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ok=-1;
    if(pArrayListEmployee!=NULL){
        char seguir='s';
        char confirma='n';
        do{
            switch(menuOrdenar()){
                case 1:
                    ll_sort(pArrayListEmployee,ordenarPorId,1);
                    ok=1;
                    break;
                case 2:
                    ll_sort(pArrayListEmployee,ordenarPorId,0);
                    ok=1;
                    break;
                case 3:
                    ll_sort(pArrayListEmployee,ordenarPorNombre,1);
                    ok=1;
                    break;
                case 4:
                    ll_sort(pArrayListEmployee,ordenarPorNombre,0);
                    ok=1;
                    break;
                case 5:
                    ll_sort(pArrayListEmployee,ordenarPorHoras,1);
                    ok=1;
                    break;
                case 6:
                    ll_sort(pArrayListEmployee,ordenarPorHoras,0);
                    ok=1;
                    break;
                case 7:
                    ll_sort(pArrayListEmployee,ordenarPorSueldo,1);
                    ok=1;
                    break;
                case 8:
                    ll_sort(pArrayListEmployee,ordenarPorSueldo,0);
                    ok=1;
                    break;
                case 9:
                    printf("Esta seguro que desea salir?, ingrese s o n: ");
                    fflush(stdin);
                    scanf("%c",&confirma);

                    if(confirma=='s'){
                        seguir='n';
                    }
                    break;
                default:
                    printf("Opcion invalida..!!\n");
                    break;
            }
        }while(seguir=='s');
    }

    return ok;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int ok=-1;
    if(path!=NULL && pArrayListEmployee!=NULL){
        FILE* f=fopen(path,"w");

        if(f!=NULL){
            int auxId;
            int auxHoras;
            float auxSueldo;
            char auxNombre[21];

            for(int i=0;i<ll_len(pArrayListEmployee);i++){
                Employee* auxEmp=(Employee*)ll_get(pArrayListEmployee,i);

                employee_getId(auxEmp,&auxId);
                employee_getNombre(auxEmp,auxNombre);
                employee_getHorasTrabajadas(auxEmp,&auxHoras);
                employee_getSueldo(auxEmp,&auxSueldo);

                fprintf(f,"%d,%s,%d,%.2f\n",auxId,auxNombre,auxHoras,auxSueldo);
            }
            fclose(f);
            ok=1;
        }else{
            //si el archivo es invalido..
            ok=0;
        }
    }

    return ok;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ok=-1;
    if(path!=NULL && pArrayListEmployee!=NULL){
        FILE* f=fopen(path,"wb");

        if(f!=NULL){
            for(int i=0;i<ll_len(pArrayListEmployee);i++){
                Employee* auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
                fwrite(auxEmp,sizeof(Employee),1,f);
            }
            fclose(f);
            ok=1;
        }else{
            //si el archivo es invalido..
            ok=0;
        }
    }

    return ok;
}
