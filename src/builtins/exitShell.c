#include "../../include/main.h"
#include "../../include/colors.h"

/**
 * Builtin command to exit the shell.
 * @param argv Array of argument strings.
 * @param argc Number of arguments.
 * @return Exit status code.
 */
int exitShell(char **argv, int argc) {
    if (argc > 1) {
        fprintf(stderr, "exit: too many arguments\n");
        return 1;
    }

    printf("\nGoodbye from " GREEN"mar1bash!\n"RESET);
    exit(EXIT_SUCCESS);
}
