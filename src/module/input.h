#ifndef DATABASE_OF_EMPLOYEES_C_INPUT_H
#define DATABASE_OF_EMPLOYEES_C_INPUT_H

#include "functions.h"
#include "employee.h"

char mainMenuIn(); // main menu input

char subMenuIn(); // sub menu input

int addEmployeeIn(Employee *employee); // add employee input

int updateEmployeeIn(Employee *employee); // update employee input

#endif //DATABASE_OF_EMPLOYEES_C_INPUT_H
