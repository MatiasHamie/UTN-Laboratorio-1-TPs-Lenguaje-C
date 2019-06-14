#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/
int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();
    char seguir='s';
    int flagEmpleadosCargados=0;
    do{
        switch(menu())
        {
            case 1:
                switch(controller_loadFromText("data.csv",listaEmpleados)){
                    case -1:
                        printf("ERROR: Se recibio Lista = NULL o NO se recibio un path\n");
                        break;
                    case 0:
                        printf("ERROR: No se encontro el archivo..!!\n");
                        break;
                    case 1:
                        printf("Se cargo la informacion de forma exitosa..!!\n");
                        flagEmpleadosCargados=1;
                        break;
                }
                system("pause");
                break;
            case 2:
                switch(controller_loadFromBinary("data.bin",listaEmpleados)){
                    case -1:
                        printf("ERROR: Se recibio Lista = NULL o NO se recibio un path\n");
                        break;
                    case 0:
                        printf("ERROR: No se encontro el archivo..!!\n");
                        break;
                    case 1:
                        printf("Se cargo la informacion de forma exitosa..!!\n");
                        flagEmpleadosCargados=1;
                        break;
                }
                system("pause");
                break;
            case 3:
                if(flagEmpleadosCargados==0){
                    controller_loadFromText("data.csv",listaEmpleados);
                    printf("Se han encontrado y se cargaron empleados encontrados en la BD..!\n\n");
                    system("pause");
                    flagEmpleadosCargados=1;
                }
                switch(controller_addEmployee(listaEmpleados)){
                    case -1:
                        printf("ERROR: Se recibio una lista con valor NULL..!!\n");
                        break;
                    case 0:
                        printf("ERROR: No se pudo conseguir memoria libre..!!\n");
                        break;
                    case 1:
                        printf("Empleado creado de forma satisfactoria..!!\n");
                        break;
                    case 2:
                        printf("ERROR: Ya existe un empleado con ese ID..!!\n");
                        break;
                }
                system("pause");
                break;
            case 4:
                switch(controller_editEmployee(listaEmpleados)){
                    case -1:
                        printf("ERROR: Se recibio una lista con valor NULL..!!\n");
                        break;
                    case 0:
                        printf("ERROR: No se pudo conseguir memoria libre..!!\n");
                        break;
                    case 1:
                        printf("Empleado editado de forma satisfactoria..!!\n");
                        break;
                    case 2:
                        printf("ERROR: No se encontro al empleado en nuestra Base de datos..!!\n");
                        break;
                }
                system("pause");
                break;
            case 5:
                switch(controller_removeEmployee(listaEmpleados)){
                    case -1:
                        printf("ERROR: Se recibio una lista con valor NULL..!!\n");
                        break;
                    case 0:
                        printf("ERROR: No se pudo conseguir memoria libre..!!\n");
                        break;
                    case 1:
                        printf("Empleado eliminado de forma satisfactoria..!!\n");
                        break;
                }
                system("pause");
                break;
            case 6:
                switch(controller_ListEmployee(listaEmpleados)){
                    case -1:
                        printf("ERROR: Se recibio una lista con valor NULL..!!\n");
                        break;
                    case 1:
                        printf("Se listo el total de empleados satisfactoriamente..\n");
                        break;
                }
                system("pause");
                break;
            case 7:
                switch(controller_sortEmployee(listaEmpleados)){
                    case -1:
                        printf("ERROR: Se recibio una lista con valor NULL..!!\n");
                        break;
                    case 1:
                        printf("Empleados ordenados satisfactoriamente..!!\n");
                        break;
                }
                system("pause");
                break;
            case 8:
                switch(controller_saveAsText("data.csv",listaEmpleados)){
                    case -1:
                        printf("ERROR: Se recibio Lista = NULL o NO se recibio un path\n");
                        break;
                    case 0:
                        printf("ERROR: No se encontro el archivo..!!\n");
                        break;
                    case 1:
                        printf("Se guardo la informacion de forma exitosa..!!\n");
                        break;
                }
                system("pause");
                break;
            case 9:
                switch(controller_saveAsBinary("data.bin",listaEmpleados)){
                    case -1:
                        printf("ERROR: Se recibio Lista = NULL o NO se recibio un path\n");
                        break;
                    case 0:
                        printf("ERROR: No se encontro el archivo..!!\n");
                        break;
                    case 1:
                        printf("Se guardo la informacion de forma exitosa..!!\n");
                        break;
                }
                system("pause");
                break;
            case 10:
                seguir='n';
                system("pause");
                break;
            default:
                printf("Opcion invalida..!!\n");
                break;
        }
    }while(seguir == 's');

    return 0;
}
