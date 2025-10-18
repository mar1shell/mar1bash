#include "../../include/main.h"
#include "../../include/colors.h"

/**
 * interpret the given arguments and execute the corresponding command.
 * @param args the arguments array
 * @param argsCount the number of arguments
 */
void interpretArgs(char **args, int argsCount) {
    if (args == NULL) {
        return;
    }

    // TODO
    // if (isBuiltin(args[0])) {
    //     executeBuiltin(args, argsCount);
    // } else if (isCommand(args[0])) {
    //     executeCommand(args);
    // } else if (isExecutable()) {
    //     executeFile(args, argsCount);
    // } else {
    //     printf(RED"mar1bash: command not found: %s\n"RESET, args[0]);
    //     STATUS = ENOENT;
    // }
}