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

} Sector;

int mainMenu();
int reportsMenu();
int initEmployees(Employee* employees, int length);
int addEmployee(Employee* employees, int length, int id, char name[],char lastName[],float salary,int sector);
int findEmptyIndex(Employee* employees, int length);
int findEmployeeById(Employee* employees, int length,int id);
int removeEmployee(Employee* employees, int length, int id);
int modifyEmployee(Employee* employees, int length, int id);
int sortEmployees(Employee* employees, int length, int order);
int printEmployees(Employee* employees, int length);
int getRandomId(Employee* employees, int length);
int reports(Employee* employees, int length, Sector* sectors, int lengthSec);
void bubbleSorting(Employee* employees, int length, int i, int j);
