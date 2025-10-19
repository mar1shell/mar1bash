#include "../include/main.h"
#include "../include/constants.h"
#include "../include/colors.h"

int STATUS = 0;

int main(int argc, char *argv[]) {
    char *line;

    printWelcomeMessage();
    printf("Type " GREEN"'help'"RESET " to see available commands.\n");
    printf("Type " GREEN"'exit'"RESET " or press " GREEN"Ctrl+D"RESET " to quit.\n\n");

    while (TRUE) {
        line = readShellLine();

        if (line == NULL) {
            printf("\nGoodbye from " GREEN"mar1bash!\n"RESET);
            break;
        } else if (line[0] == '\0') {
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