#include "output.h"

void mainMenuOut() {

    clearDisplay();

    fprintf(stdout, "\nDATABASE OF EMPLOYEES");
    fprintf(stdout, "\nreturn to menu: m + enter");
    fprintf(stdout, "\n\n1. Add employee");
    fprintf(stdout, "\n2. Update employee");
    fprintf(stdout, "\n3. Delete employee");
    fprintf(stdout, "\n4. List database");
    fprintf(stdout, "\n5. Exit");
    fprintf(stdout, "\nOption:");


    /*
    gotoxy(30,5);
    fprintf(stdout,"DATABASE OF EMPLOYEES");
    gotoxy(30,7);
    fprintf(stdout,"return to menu: m + enter");
    gotoxy(30,10);
    fprintf(stdout,"1. Add employee");
    gotoxy(30,12);
    fprintf(stdout,"2. Update employee");
    gotoxy(30,14);
    fprintf(stdout,"3. Delete employee");
    gotoxy(30,16);
    fprintf(stdout,"4. List database");
    gotoxy(30,18);
    fprintf(stdout,"5. Exit");
    gotoxy(30,20);
    fprintf(stdout,"Option:");
    */
}

void subMenuOut() {

    clearDisplay();

    fprintf(stdout, "\n\n\n\n1. List all");
    fprintf(stdout, "\n2. List izvestaja");
    fprintf(stdout, "\n3. Return to menu");
    fprintf(stdout, "\nOption:");


    /*
    gotoxy(30,10);
    fprintf(stdout,"1. List all");
    gotoxy(30,12);
    fprintf(stdout,"2. List izvestaja");
    gotoxy(30,14);
    fprintf(stdout,"3. Return to menu");
    gotoxy(30,16);
    fprintf(stdout,"Option:");
     */
}

void addEmployeeOut(Employee *employee) {

    clearDisplay();
    fprintf(stdout, "\nName: %s", employee->name);
    fprintf(stdout, "\nYears: %i", employee->years);
    fprintf(stdout, "\nSalary: %f", employee->salary);
}

void updateEmployeeOut(Employee *employee) {

    clearDisplay();
    fprintf(stdout, "\nName: %s", employee->name);
    fprintf(stdout, "\nYears: %i", employee->years);
    fprintf(stdout, "\nSalary: %f", employee->salary);
}