#include "module/process.h"

int main(int argc, char **argv) {

    while (1) {
        mainMenuOut();
        if( mainMenuPro(mainMenuIn()) == 0) break;
    }
}


