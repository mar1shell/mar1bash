#include "../include/main.h"
#include "../include/constants.h"
#include "../include/colors.h"

int STATUS = 0;

int main(int argc, char *argv[]) {
    char *line;

    signal(SIGINT, handleSIGINT);
    
    printWelcomeMessage();
    
    char *HOME = getenv("HOME");
    
    if (chdir(HOME) != 0) {
        fprintf(stderr ,RED"HOME directory not found, mar1bash will use the current directory\n"RESET);
    }

    while (TRUE) {
        line = readShellLine();

        if (line == NULL) {
            printf("\nGoodbye from " GREEN"mar1bash!\n"RESET);
            break;
        } else if (isEmpty(line)) {
            printf("\n");
            continue;
        }

        char **args = lineTokenizer(line);

        if (args == NULL) {
            continue;
        }

        int i = 0, argsCount = 0;

        while (args[i++] != NULL) {
            argsCount++;
        }

        interpretArgs(args, argsCount);

        free(args);
        free(line);
    }


    return EXIT_SUCCESS;
}