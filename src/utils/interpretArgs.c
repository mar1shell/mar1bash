#include "../../include/main.h"
#include "../../include/colors.h"
#include "../../include/constants.h"

/**
 * interpret the given arguments and execute the corresponding command.
 * @param argv the arguments array
 * @param argc the number of arguments
 */
void interpretArgs(char **argv, int argc) {
    if (argv == NULL) {
        return;
    }
        
    if (executeBuiltin(argv, argc) == ENOTBUILTIN) {
        executeCommand(argv);
    }

    printf("\n");
}