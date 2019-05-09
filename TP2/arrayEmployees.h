/*
*********************************************
*           TRABAJO PRACTICO NRO 2          *
*               PROTOTIPOS                  *
*   Materia: Laboratorio de programacion 1  *
*   Alumno: Hamie Matias                    *
*   Curso: 1 'G'                            *
*                                           *
*********************************************
*/

/*
    Declaro 2 estructuras:
    1- Estructura empleado
    2- Estructura sectores:
        -   Creada para poder seleccionar un sector y mostrar
            un descriptivo con su correspondiente empleado
*/
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;

typedef struct
{
    int id;
    char description[51];

} Sectors;

/*
 ***************************************************
 * Declaracion de Funciones:                       *
 *      1) Obligatorias para el trabajo practico   *
 ***************************************************
*/

/**
* \brief  To indicate that all position in the array are empty,
*         this function put the flag (isEmpty) in TRUE in all
*         position of the array
*
* \param  list Employee* Pointer to array of employees
* \param  lengthEmp int Array
*
* \return int Return (-1) if Error - (0) if Ok*/
int initEmployees(Employee* employees, int lengthEmp);

/**
* \brief  add in a existing list of employees the values received as parameters
*         in the first empty position
*
* \param  list       employee*
* \param  lengthEmp  int
* \param  id         int
* \param  name[]     char
* \param  lastName[] char
* \param  salary     float
* \param  sector     int
* \param  list       *sectors
* \param  lengthSec  int
*
* \return int Return (-1) if Error - (0) if Ok*/
int addEmployee(Employee* employees, int lengthEmp, int id, char name[],char lastName[],float salary,int sector, Sectors* sectors, int lengthSec);

/**
* \brief find an Employee by Id en returns the index position in array.
*
* \param  list      Employee*
* \param  lengthEmp int
* \param  id        int
*
* \return Return employee index position or (-1) if*/
int findEmployeeById(Employee* employees, int lengthEmp,int id);
int removeEmployee(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec);
int printEmployees(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec);
int sortEmployeesByName(Employee* employees, int lengthEmp, int order);

/*
 *****************************
 * Declaracion de Funciones: *
 *      2) Funciones extras  *
 *****************************
*/

//MENUES

/**
* \brief Muestra un menu con las opciones principales del TPN2
*        y devuelve la opcion elegida
*
* \param  Se declara Int opcion
*
* \return Return opcion*/
int mainMenu();

/**
* \brief Muestra un menu con las opciones de reportes disponibles
*
* \param  Se declara funcion Int opcion
*
* \return Return opcion*/
int reportsMenu();

/**
* \brief Muestra un menu con las opciones de parametros del empleado a modificar disponibles
*
* \param  Se declara funcion Int opcion
*
* \return Return opcion*/
int modifyMenu();

/**
* \brief Harcode de sectores random (creados por mi)
*
* \param  list       *Employee
* \param  lengthEmp  int
*
*/
void hardcodeEmployees(Employee* employees, int lengthEmp);

/**
* \brief Harcode de empleados random (creados por mi)
*
* \param  list       *sectors
* \param  lengthSec  int
*
*/
void hardcodeSectors(Sectors* sectors,int LENSEC);

//Mostrar empleado
/**
* \brief  Recibe un solo empleado y lo muestra por pantalla.
* \brief  (La funcion "printEmployees" al final envia cada empleado
* \brief  que se desee listar a esta funcion)
*
* \param  Variable Local Int index = es el resultado que retorna la funcion
*         "getSectorDescription" (Indice del sector correspondiente)
*
* \return Return 0 - OK*/
int printEmployee(Employee employee, Sectors* sectors, int lengthSec);

/**
* \brief  Busca el primer legajo libre verificando el primer indice con el
*          el valor de ".isEmpty" en 1.
*
* \param  Variable Local Int index = es el resultado que retorna la funcion
*         "getSectorDescription" (Indice del sector correspondiente)
*
* \return Return 0 - OK*/
int findEmptyIndex(Employee* employees, int lengthEmp);

/**
* \brief  Asigna (iniciando desde el numero 1000) legajos a cada empleado que
* \brief  se desee dar de alta
*
* \param  list              Employee*
* \param  lengthEmp         int
* \param  id                int*
* \param  requestedRandomId int*
* \param  Variable Local Int index = es el resultado que retorna la funcion
*         "findEmptyIndex", el cual es primer indice libre para dar de alta
*         un empleado
*
* \return Return 0 - OK / -1 - FAIL*/
int getRandomId(Employee* employees, int lengthEmp, int* requestedRandomId);

/**
* \brief  Recibe el id de un empleado, verifica a que sector pertenece y return del indice
*
* \param  list      Sectors*
* \param  empleado  Int
* \param  id        int*
* \param  index     int
*
* \return Return indice del sector asignado al empleado - OK / -1 - FAIL*/
int getSectorDescription(int idEmployee, Sectors* sectors, int lengthSec);

/*****************************************
Funciones de modificacion del empleado:  *
    - Principal:                         *
        - modifyEmployee                 *
            - Secundarias:               *
                - modifyNameEmployee     *
                - modifyLastNameEmployee *
                - modifySalaryEmployee   *
                - modifySectorEmployee   *
*****************************************/

/**
* \brief  Recibe los vectores empleados y sectores, busca por legajo por la funcion findEmployeeById
* \brief  si no lo encuentra devuelve un -1, si lo encuentra muestra por pantalla un menu para elegir
* \brief  que se desea modificar
*
* \param  list       Employee*
* \param  lengthEmp  Int
* \param  list       Sectors*
* \param  lengthSec  Int
* \param  idEmpleado int*
* \param  index      int
*
* \return Return 0 - OK / -1 - FAIL*/
int modifyEmployee(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec);

/**
* \brief  - Recibe el id del empleado
* \brief  - pide un nuevo nombre y lo guarda en un auxiliar
* \brief  - valida que sea solo letras (A-Z) y se encuentre entre el limite minimo y maximo
* \brief  - Reemplaza el nombre por el valor del auxiliar
*
* \param  list        Employee*
* \param  lengthEmp   Int
* \param  list        Sectors*
* \param  lengthSec   Int
* \param  idEmpleado  int
* \param  auxName     char
* \param  confirm     int
*
* \return Return 0 - OK / -1 - FAIL*/
int modifyNameEmployee(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec, int index);

/**
* \brief  - Recibe el id del empleado
* \brief  - Pide un nuevo apellido y lo guarda en un auxiliar
* \brief  - Valida que sea solo letras (A-Z) y se encuentre entre el limite minimo y maximo
* \brief  - Reemplaza el nombre por el valor del auxiliar
*
* \param  list        Employee*
* \param  lengthEmp   Int
* \param  list        Sectors*
* \param  lengthSec   Int
* \param  idEmpleado  int
* \param  auxLastName char
* \param  confirm     int
*
* \return Return 0 - OK / -1 - FAIL*/
int modifyLastNameEmployee(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec, int index);

/**
* \brief  Recibe el id del empleado, valida que sea solo letras (A-Z) y se encuentre entre
*         el limite minimo y maximo, y lo reemplaza en la variable nombre del empleado
*
* \param  list        Employee*
* \param  lengthEmp   Int
* \param  list        Sectors*
* \param  lengthSec   Int
* \param  idEmpleado  int
* \param  auxLastName char
* \param  confirm     int
*
* \return Return 0 - OK / -1 - FAIL*/
int modifySalaryEmployee(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec, int index);
int modifySectorEmployee(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec, int index);

int reports(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec);

void printSectors(Sectors* sectors, int lengthSec);

int sortingMenu(Employee* employees, int lengthEmp);
void bubbleSorting(Employee* employees, int lengthEmp, int i, int j);
