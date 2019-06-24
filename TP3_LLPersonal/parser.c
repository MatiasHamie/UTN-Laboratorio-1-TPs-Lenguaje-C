#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char mBuffer[4][21];
    int cantidad=0;
    int ok=-1;
    Employee* newEmp;

    if(pArrayListEmployee!=NULL && pFile!=NULL){
        while(!feof(pFile)){
            cantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",mBuffer[0],mBuffer[1],mBuffer[2],mBuffer[3]);;
            newEmp=employee_newParametros(mBuffer[0],mBuffer[1],mBuffer[2],mBuffer[3]);

            if(newEmp!=NULL){
                ll_add(pArrayListEmployee,newEmp);
                ok=1;
            }
            if(cantidad<4){
                if(feof(pFile)){
                    break;
                }else{
                    ok=0;
                    break;
                }
            }
        }
    }

    return ok;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int cantidad=0;
    int ok=-1;
    Employee* newEmp=NULL;

    if(pArrayListEmployee!=NULL && pFile!=NULL){
        while(!feof(pFile)){
            newEmp=employee_new();
            cantidad=fread(newEmp,sizeof(Employee),1,pFile);
            if(newEmp!=NULL){
                if(cantidad<1){
                    if(feof(pFile)){
                        break;
                    }else{
                        ok=0;
                        break;
                    }
                }else{
                    ll_add(pArrayListEmployee,newEmp);
                    ok=1;
                }
            }
        }
    }

    return ok;
}
