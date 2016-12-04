#ifndef DATABASE_OF_EMPLOYEES_C_PROCESS_H
#define DATABASE_OF_EMPLOYEES_C_PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include "employee.h"
#include "input.h"
#include "output.h"

int mainMenuPro(char mainMenuOption); // main menu process

int subMenuPro(char subMenuOption); // sub menu process

int addEmployeePro(); // add employee process

int updateEmployeePro(); // update employee process

int deleteEmployeePro(); // delete employee process

int listAllEmployeePro(); // list all employee process

int statisticsEmployeePro(); // statistics employee process

#endif //DATABASE_OF_EMPLOYEES_C_PROCESS_H
