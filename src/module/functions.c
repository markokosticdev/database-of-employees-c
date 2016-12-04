#include "functions.h"

void gotoxy(int x, int y) {
    printf("\n");
    printf("%c[%d;%df", 0x1B, y, x);
}

void clearDisplay() {

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

}

void load() {
    int load = 10;
    for (int i = 0; i < load + 1; i++) {
        clearDisplay();
        gotoxy(34, 12);
        for (int k = 0; k < i; k++) fprintf(stdout, "%c", '+');
        for (int k = 1; k < load - i + 1; k++) fprintf(stdout, "%c", '-');
        nanosleep((const struct timespec[]) {{0, 200 * 1000000}}, NULL);
    }
    clearDisplay();
}

int isNumber(const char *string) {

    if (string == NULL || *string == '\0' || isspace(*string)) return 0;
    char *p;
    strtod(string, &p);
    return *p == '\0';
/*
    int isNumber(const char *string) {

        if (atoi(string) == 0 && string[0] != '0') return 0;
        else return 1;
    }
*/

}