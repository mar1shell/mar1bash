#include "../../include/main.h"
#include "../../include/colors.h"


void handleSIGINT(int sig) {
    printf("\n\nGoodbye from " GREEN"mar1bash!\n"RESET);

    exit(EXIT_SUCCESS);
}