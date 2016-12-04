#ifndef DATABASE_OF_EMPLOYEES_C_FUNCTIONS_H
#define DATABASE_OF_EMPLOYEES_C_FUNCTIONS_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void gotoxy(int x, int y); // go to point in terminal

void clearDisplay(); // clear terminal

void load(); // load animation

int isNumber(const char *string); // is number

#endif //DATABASE_OF_EMPLOYEES_C_FUNCTIONS_H
