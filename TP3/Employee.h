#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_add(LinkedList* this);
int employee_edit(LinkedList* this);

int employee_findById(LinkedList* this, int id);


int employee_changeName(Employee* this);
int employee_changeSalary(Employee* this);
int employee_changeHoursWorked(Employee* this);

int employe_delete(LinkedList* this);

int employee_sortByName(void* employeeA,void* employeeB);
int employee_sortBySalary(void* employeeA,void* employeeB);
int employee_sortByHoursWorked(void* employeeA,void* employeeB);
int employee_sortById(void* employeeA,void* employeeB);




#endif // employee_H_INCLUDED
