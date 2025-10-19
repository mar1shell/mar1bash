#include "../../include/main.h"

/**
 * execute the given command with arguments.
 * @param args the arguments array
 * @param argsCount the number of arguments
 */
void executeCommand(char **args) {
    if (xFork() == 0) {
        signal(SIGINT, SIG_DFL);
        xExecvp(args[0], args);
    } else {
        signal(SIGINT, SIG_IGN);

        wait(&STATUS);

        signal(SIGINT, handleSIGINT);
    }
}