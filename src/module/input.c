#include "input.h"

char mainMenuIn() {

    char option;
    option = (char) fgetc(stdin);
    if (option != '\n') fgetc(stdin);
    fflush(stdin);

    return option;
}

char subMenuIn() {

    char option;
    option = (char) fgetc(stdin);
    if (option != '\n') fgetc(stdin);
    fflush(stdin);

    return option;
}

int addEmployeeIn(Employee *employee) {

    const int name_buffer = 100, years_buffer = 11, salary_buffer = 25;
    char name[name_buffer + 1], years[years_buffer + 1], salary[salary_buffer + 1];

    int pass = 0;
    int error = 0;

    do {
        clearDisplay();
        if (pass != 0) {
            switch (error) {
                case 1:
                    fputs("\nNOTE: Enter name with a space", stdout);
                    break;
                case 2:
                    fputs("\nNOTE: Enter less name", stdout);
                    break;
                default:
                    break;
            }
        }
        else pass++;
        fputs("\n\nEnter first and last name: ", stdout);
        fgets(name, name_buffer, stdin);
        fflush(stdin);
        strtok(name, "\n");
        if (strcmp(name, "m") == 0) return 0;
        else if (!strstr(name, " ")) error = 1;
        else if (strlen(name) > 100) error = 2;
        else error = 0;
    } while (error != 0);
    fflush(stdin);

    error = 0;
    pass = 0;

    do {
        clearDisplay();
        if (pass != 0) {
            switch (error) {
                case 1:
                    fputs("\nNOTE: Enter number", stdout);
                    break;
                case 2:
                    fputs("\nNOTE: Enter min. 18 years", stdout);
                    break;
                case 3:
                    fputs("\nNOTE: Enter max. 62 years", stdout);
                    break;
                default:
                    break;
            }
        }
        else pass++;
        fputs("\n\nEnter years: ", stdout);
        fgets(years, years_buffer, stdin);
        fflush(stdin);
        strtok(years, "\n");
        if (strcmp(years, "m") == 0) return 0;
        else if (!isNumber(years)) error = 1;
        else if (18 > atoi(years)) error = 2;
        else if (atoi(years) > 62) error = 3;
        else error = 0;
    } while (error != 0);
    fflush(stdin);

    error = 0;
    pass = 0;

    do {
        clearDisplay();
        if (pass != 0) {
            switch (error) {
                case 1:
                    fputs("\nNOTE: Enter number", stdout);
                    break;
                default:
                    break;
            }
        }
        else pass++;
        fputs("\n\nEnter salary: ", stdout);
        fgets(salary, salary_buffer, stdin);
        fflush(stdin);
        strtok(salary, "\n");
        if (strcmp(salary, "m") == 0) return 0;
        else if (!isNumber(salary)) error = 1;
        else error = 0;
    } while (error != 0);
    fflush(stdin);

    strcpy(employee->name, name);
    employee->years = atoi(years);
    employee->salary = atof(salary);

    return 1;
}

int updateEmployeeIn(Employee *employee) {

    const int name_buffer = 100, years_buffer = 11, salary_buffer = 25;
    char salary[salary_buffer + 1], name[name_buffer + 1], years[years_buffer + 1];

    int pass = 0;
    int error = 0;

    do {
        clearDisplay();
        if (pass != 0) {
            switch (error) {
                case 1:
                    fputs("\nNOTE: Enter name with a space", stdout);
                    break;
                case 2:
                    fputs("\nNOTE: Enter less name", stdout);
                    break;
                default:
                    break;
            }
        }
        else pass++;
        fputs("\n\nEnter first and last name: ", stdout);
        fgets(name, name_buffer, stdin);
        fflush(stdin);
        strtok(name, "\n");
        if (strcmp(name, "m") == 0) return 0;
        else if (!strstr(name, " ")) error = 1;
        else if (strlen(name) > 100) error = 2;
        else error = 0;
    } while (error != 0);
    fflush(stdin);

    error = 0;
    pass = 0;

    do {
        clearDisplay();
        if (pass != 0) {
            switch (error) {
                case 1:
                    fputs("\nNOTE: Enter number", stdout);
                    break;
                case 2:
                    fputs("\nNOTE: Enter min. 18 years", stdout);
                    break;
                case 3:
                    fputs("\nNOTE: Enter max. 62 years", stdout);
                    break;
                default:
                    break;
            }
        }
        else pass++;
        fputs("\n\nEnter years: ", stdout);
        fgets(years, years_buffer, stdin);
        fflush(stdin);
        strtok(years, "\n");
        if (strcmp(years, "m") == 0) return 0;
        else if (!isNumber(years)) error = 1;
        else if (18 > atoi(years)) error = 2;
        else if (atoi(years) > 62) error = 3;
        else error = 0;
    } while (error != 0);
    fflush(stdin);

    error = 0;
    pass = 0;

    do {
        clearDisplay();
        if (pass != 0) {
            switch (error) {
                case 1:
                    fputs("\nNOTE: Enter number", stdout);
                    break;
                default:
                    break;
            }
        }
        else pass++;
        fputs("\n\nEnter salary: ", stdout);
        fgets(salary, salary_buffer, stdin);
        fflush(stdin);
        strtok(salary, "\n");
        if (strcmp(salary, "m") == 0) return 0;
        else if (!isNumber(salary)) error = 1;
        else error = 0;
    } while (error != 0);
    fflush(stdin);

    strcpy(employee->name, name);
    employee->years = atoi(years);
    employee->salary = atof(salary);

    return 1;
}