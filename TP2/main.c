#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "arrayEmployees.h"
#include "validaciones.h"

#define LENEMP 1000
#define LENSEC 5

int main()
{
    char  continueWith='s';
    char  confirm;
    char  requestedName[51];
    char  requestedLastName[51];
    float requestedSalary;
    int requestedRandomId;
    int requestedSector;
    int emptySpace;
    int contadorReintentos;
    int contadorEmpleados=0;
    int validacionNombre=0;
    int validacionApellido=0;
    int validacionSueldo=0;
    int validacionElegirSector=0;
    Employee employees[LENEMP];
    Sectors sectors[LENSEC];

    //Inicializo todos los indices del array employees con ".isEmpty=1"
    initEmployees(employees,LENEMP);
    //Hardcodeo sectores
    hardcodeSectors(sectors,LENSEC);

    do{
        switch(mainMenu()){
            case 1:
                /*
                    Cada vez que el usuario quiera dar de alta un empleado, pongo el contador
                    de reintentos en 0.
                */
                contadorReintentos=0;
                //Busco el primer indice libre
                emptySpace=findEmptyIndex(employees,LENEMP);
                //Si es mayor o igual a 0 comienzo el proceso de alta
                if(emptySpace>=0){
                    //Obtengo randomId del empleado
                    getRandomId(employees,LENEMP,&requestedRandomId);
                    do{
                        //Obtengo nombre validando el largo y que sean solo solo letras
                        validacionNombre=getString(requestedName,"Ingrese el nombre del empleado","Nombre invalido, cantidad de caracteres [min 2 - max 50]",2,50);
                        /*
                            Si la validacion dio:
                            - OK [1] = pido apellido
                            - FAIL [-1] = vuelvo a pedir nombre
                        */
                        if(validacionNombre==-1){
                            //Incremento en 1 el contador de Reintentos
                            contadorReintentos++;
                            //Si es mayor a 2, dejo de iterar y no sigo pidiendo datos
                            if(contadorReintentos>2){
                                break;
                            }
                        }
                    }while(validacionNombre==-1);
                    //Si validacion nombre OK, continuo pidiendo datos
                    if(validacionNombre!=-1){
                        contadorReintentos=0;
                        do{
                            //Obtengo apellido validando el largo y que sean solo solo letras
                            validacionApellido=getString(requestedLastName,"Ingrese el apellido del empleado","Apellido invalido, cantidad de caracteres [min 2 - max 50]",2,50);
                            /*
                                Si la validacion dio:
                                - OK [1] = pido sueldo
                                - FAIL [-1] = vuelvo a pedir apellido
                            */
                            if(validacionApellido==-1){
                                contadorReintentos++;
                                if(contadorReintentos>2){
                                    break;
                                }
                            }
                        }while(validacionApellido==-1);
                    }
                        //Si validacion nombre y apellido OK, continuo pidiendo datos
                        if(validacionNombre!=-1 && validacionApellido!=-1){
                            contadorReintentos=0;
                            do{
                                //Obtengo salario
                                validacionSueldo=getFloat(&requestedSalary,"Ingrese el salario del empleado","Salario invalido, rango [min 1 - max 999999]",1,1000000);
                                /*
                                    Si la validacion dio:
                                    - OK [1] = elijo sector
                                    - FAIL [-1] = vuelvo a pedir sueldo
                                */
                                if(validacionSueldo==-1){
                                    contadorReintentos++;
                                    if(contadorReintentos>2){
                                        break;
                                    }
                                }
                            }while(validacionSueldo==-1);
                        }
                        //Si validacion nombre, apellido y sueldo OK, continuo pidiendo datos
                        if(validacionNombre!=-1 && validacionApellido!=-1 && validacionSueldo!=-1){
                            do{
                                //Eleccion de sector deseado
                                validacionElegirSector=chooseSector(&requestedSector,"Elija sector al que pertenece el empleado","Opcion invalida, rango [1-5]",1,5,sectors,LENSEC);
                                /*
                                    Si la validacion dio:
                                    - OK [1] = le paso los valores a addEmployees
                                    - FAIL [-1] = vuelvo a pedir sector
                                */
                                if(validacionElegirSector==-1){
                                    contadorReintentos++;
                                    if(contadorReintentos>2){
                                        break;
                                    }
                                }
                            }while(validacionElegirSector==-1);
                        }
                        //Si los datos fueron validados correctamente, se los envio a la funcion addEmployees
                        if((validacionNombre!=-1) && (validacionApellido!=-1) && (validacionSueldo!=-1) && (validacionElegirSector!=-1)){
                            //Envio los datos validados del empleado pendiente a cargar a la funcion addEmployee
                            addEmployee(employees,LENEMP,requestedRandomId,requestedName,requestedLastName,requestedSalary,requestedSector,sectors,LENSEC);
                            contadorEmpleados++;
                        }else{
                            printf("No se pudo validar al empleado..!\n\n");
                        }
                    }else{
                        //si no hay espacio libre advierto al empleado
                        printf("No hay espacio para mas empleados..!!\n");
                    }
                system("pause");
                break;
            case 2:
                if(contadorEmpleados>0){
                    modifyEmployee(employees,LENEMP,sectors,LENSEC);
                }else{
                    printf("\nNo hay empleados para modificar!!\n\n");
                }
                system("pause");
                break;

            case 3:
                if(contadorEmpleados>0){
                    removeEmployee(employees,LENEMP,sectors,LENSEC);
                    contadorEmpleados--;
                }else{
                    printf("\nNo hay empleados para eliminar!!\n\n");
                }
                system("pause");
                break;
            case 4:
                if(contadorEmpleados>0){
                    reports(employees,LENEMP,sectors,LENSEC);
                }else{
                    printf("\nNo hay empleados para informar!!\n\n");
                }
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
