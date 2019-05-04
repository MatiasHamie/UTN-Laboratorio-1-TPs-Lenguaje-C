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

int mainMenu();
int reportsMenu();
int sortingMenu(Employee* employees, int lengthEmp);
int initEmployees(Employee* employees, int length);
int addEmployee(Employee* employees, int length, int id, char name[],char lastName[],float salary,int sector);
int findEmptyIndex(Employee* employees, int length);
int findEmployeeById(Employee* employees, int length,int id);
int removeEmployee(Employee* employees, int length, int id);
int modifyEmployee(Employee* employees, int length, int id);
int sortEmployees(Employee* employees, int length, int order);
int printEmployees(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec);
int printEmployee(Employee employee, Sectors* sectors, int lengthSec);
int reports(Employee* employees, int length, Sectors* sectors, int lengthSec);
int getSectorEmployee(int idEmployee, Sectors* sectors, int lengthSec);
int getRandomId(Employee* employees, int length, int* requestedRandomId);
int getSectorDescription(int idEmployee, Sectors* sectors, int lengthSec);
int chooseSector(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);
void bubbleSorting(Employee* employees, int length, int i, int j);
