#include "process.h"

int mainMenuPro(char mainMenuOption) {

    switch (mainMenuOption) {
        case '1':
            addEmployeePro();
            return 1;
        case '2':
            updateEmployeePro();
            return 1;
        case '3':
            deleteEmployeePro();
            return 1;
        case '4':
            while (1) {
                subMenuOut();
                if (subMenuPro(subMenuIn()) == 0) break;
            }
            return 1;
        case '5':
            return 0;
        default:
            return 1;
    }
}

int subMenuPro(char subMenuOption) {

    switch (subMenuOption) {
        case '1':
            listAllEmployeePro();
            return 1;
        case '2':
            statisticsEmployeePro();
            return 1;
        case '3':
            return 0;
        default:
            return 1;
    }
}

int addEmployeePro() {

    clearDisplay();

    FILE *file;
    file = fopen("res/db/employees.db", "rb+");
    if (file == NULL) {
        file = fopen("res/db/employees.db", "wb+");
        if (file == NULL) {
            fputs("ERROR: Database does not work!", stdout);
            return 0;
        }
    }

    int option = 'y';
    while (option == 'y' || option == 'Y') {

        Employee employee;

        if (addEmployeeIn(&employee) == 0) break;
        addEmployeeOut(&employee);

        fseek(file, 0, SEEK_END);
        fwrite(&employee, sizeof(Employee), 1, file);

        fputs("\n\nWould you like to add more employees?(Y/N): ", stdout);
        option = (char) fgetc(stdin);
        if (option != '\n') fgetc(stdin);
        fflush(stdin);
    }
    fclose(file);

    return 1;
}

int updateEmployeePro() {

    clearDisplay();

    FILE *file;
    file = fopen("res/db/employees.db", "rb+");
    if (file == NULL) {
        file = fopen("res/db/employees.db", "wb+");
        if (file == NULL) {
            fputs("ERROR: Database does not work!", stdout);
            return 0;
        }
    }

    int option = 'y';
    while (option == 'y' || option == 'Y') {

        Employee employee;
        const int name_buffer = 100;
        char nameTemp[name_buffer + 1];

        fputs("\n\nEnter first and last name to update: ", stdout);
        fgets(nameTemp, name_buffer, stdin);
        fflush(stdin);
        strtok(nameTemp, "\n");
        if (strcmp(nameTemp, "m") == 0) {
            fclose(file);
            return 0;
        }
        rewind(file);

        int result = 0;
        while (fread(&employee, sizeof(Employee), 1, file) == 1) {

            if (strcmp(employee.name, nameTemp) == 0) {

                if (updateEmployeeIn(&employee) == 0) break;
                updateEmployeeOut(&employee);

                fseek(file, -sizeof(Employee), SEEK_CUR);
                fwrite(&employee, sizeof(Employee), 1, file);
                result++;
                break;
            }
        }

        clearDisplay();
        if (result == 0) fputs("\nNOTE: No results found", stdout);
        fputs("\n\nWould you like to update more employees?(Y/N): ", stdout);
        option = (char) fgetc(stdin);
        if (option != '\n') fgetc(stdin);
        fflush(stdin);
    }
    fclose(file);

    return 1;
}

int deleteEmployeePro() {

    clearDisplay();

    int option = 'y';
    while (option == 'y' || option == 'Y') {

        Employee employee;
        const int name_buffer = 100;
        char nameTemp[name_buffer + 1];

        fputs("\n\nEnter first and last name to delete: ", stdout);
        fgets(nameTemp, name_buffer, stdin);
        fflush(stdin);
        strtok(nameTemp, "\n");
        if (strcmp(nameTemp, "m") == 0) return 0;


        FILE *file, *fileTemp;
        file = fopen("res/db/employees.db", "rb+");
        if (file == NULL) {
            fputs("ERROR: Database does not work!", stdout);
        }
        fileTemp = fopen("res/db/employeesTemp.db", "wb");
        if (file == NULL) {
            fputs("ERROR: Temporary database does not work!", stdout);
        }
        rewind(file);
        while (fread(&employee, sizeof(Employee), 1, file) == 1) {
            if (strcmp(employee.name, nameTemp) != 0) {
                fwrite(&employee, sizeof(Employee), 1, fileTemp);
            }
        }
        fclose(file);
        fclose(fileTemp);
        remove("res/db/employees.db");
        rename("res/db/employeesTemp.db", "res/db/employees.db");

        fputs("\n\nWould you like to delete more employees?(Y/N): ", stdout);
        option = (char) fgetc(stdin);
        if (option != '\n') fgetc(stdin);
        fflush(stdin);
    }

    return 1;
}


int listAllEmployeePro() {

    clearDisplay();

    FILE *file;
    Employee employee;
    int order;

    file = fopen("res/db/employees.db", "rb+");
    if (file == NULL) {
        file = fopen("res/db/employees.db", "wb+");
        if (file == NULL) {
            printf("ERROR: Database does not work!");
            exit(1);
        }
    }
    rewind(file);
    order = 1;
    fprintf(stdout, "\n|#  \t|NAME  \t\t\t|YEARS  \t|SALARY   \t|");
    fprintf(stdout, "\n-----------------------------------------------------------------");
    while (fread(&employee, sizeof(employee), 1, file) == 1) {
        fprintf(stdout, "\n|%02d. \t|%-15s \t|%-10d \t|%-10.2f din\t|", order, employee.name, employee.years,
                employee.salary);
        order++;
    }
    fprintf(stdout, "\n\nReturn back with any key");
    fgetc(stdin);
    fflush(stdin);
    fclose(file);

    return 1;
}


int statisticsEmployeePro() {

    clearDisplay();
    FILE *file;
    Employee employee, *employees;
    int i, j;
    int nameMaxLength, nameMinLength, ageMax, ageMin;
    double ageAvg, salaryAvg, salaryMax, salaryMin, salaryTotal;

    const int name_buffer = 100;
    char nameLongest[name_buffer + 1], nameShortest[name_buffer + 1];

    file = fopen("res/db/employees.db", "rb+");
    if (file == NULL) {
        file = fopen("res/db/employees.db", "wb+");
        if (file == NULL) {
            printf("ERROR: Database does not work!");
            exit(1);
        }
    }

    rewind(file);
    employees = (Employee *) malloc(sizeof(Employee));

    i = 0;
    while (fread(&employee, sizeof(employee), 1, file) == 1) {
        if (i != 0)employees = realloc(employees, (i + 1) * sizeof(Employee));
        employees[i] = employee;
        i++;
    }
    j = i;

    nameMaxLength = 0;
    nameMinLength = INT_MAX;
    ageAvg = 0;
    ageMax = 0;
    ageMin = INT_MAX;
    salaryAvg = 0;
    salaryMax = 0;
    salaryMin = FLT_MAX;

    for (i = 0; i < j; i++) {
        if (strlen(employees[i].name) > nameMaxLength) {
            nameMaxLength = (int) strlen(employees[i].name);
            strcpy(nameLongest, employees[i].name);
        }
        if (strlen(employees[i].name) < nameMinLength) {
            nameMinLength = (int) strlen(employees[i].name);
            strcpy(nameShortest, employees[i].name);
        }

        ageAvg += employees[i].years;

        if (employees[i].years > ageMax) {
            ageMax = employees[i].years;
        }
        if (employees[i].years < ageMin) {
            ageMin = employees[i].years;
        }

        salaryAvg += employees[i].salary;

        if (employees[i].salary > salaryMax) {
            salaryMax = employees[i].salary;
        }
        if (employees[i].salary < salaryMin) {
            salaryMin = employees[i].salary;
        }

    }
    ageAvg = ageAvg / i;
    salaryTotal = salaryAvg;
    salaryAvg = salaryAvg / i;

    printf("\n|STATISTIC          \t\t|RESULT   \t\t|");
    printf("\n---------------------------------------------------------");
    printf("\n|Longest employee name    \t|%21s\t|", nameLongest);
    printf("\n|Shortest employee name   \t|%21s\t|", nameShortest);
    printf("\n|Average employee age     \t|%16.f  year\t|", ageAvg);
    printf("\n|Oldest employee        \t|%16d  year\t|", ageMax);
    printf("\n|Youngest employee         \t|%16d  year\t|", ageMin);
    printf("\n|Average employee salary   \t|%16.2f  euro\t|", salaryAvg);
    printf("\n|Maximum employee salary   \t|%16.2f  euro\t|", salaryMax);
    printf("\n|Minimum employee salary   \t|%16.2f  euro\t|", salaryMin);
    printf("\n|Total salary payment       \t|%16.2f  euro\t|", salaryTotal);
    fprintf(stdout, "\n\nReturn back with any key");
    fgetc(stdin);
    fflush(stdin);
    fclose(file);

    return 1;
}












