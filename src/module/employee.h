#ifndef DATABASE_OF_EMPLOYEES_C_EMPLOYEE_H
#define DATABASE_OF_EMPLOYEES_C_EMPLOYEE_H

typedef struct Employee {
    char name[100+1];
    int years;
    double salary;
} Employee;

#endif //DATABASE_OF_EMPLOYEES_C_EMPLOYEE_H
