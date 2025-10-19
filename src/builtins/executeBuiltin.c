#include "../../include/main.h"
#include "../../include/constants.h"

builtin builtinCommands[] = {
    {"exit", exitShell},
    {NULL, NULL}
};

int executeBuiltin(char **argv, int argc) {
    if (argv == NULL) {
        perror("isBuiltin: Invalid command");
        exit(EXIT_FAILURE);
    }
    
    builtin *curr = builtinCommands;
    builtin *command = NULL;

    while (curr != NULL && curr->name != NULL) {
        if (strcmp(argv[0], curr->name) == 0) {
            command = curr;
            break;
        }

        curr++;
    }

    if (command == NULL) {
        return ENOENT;
    }

    return curr->foo(argv, argc);
}