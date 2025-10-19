#include "../../include/main.h"

/**
 * execute the given command with arguments.
 * @param args the arguments array
 * @param argsCount the number of arguments
 */
void executeCommand(char **args) {
    if (xFork() == 0) {
        xExecvp(args[0], args);
    } else {
        wait(&STATUS);
    }
}