#include "../include/main.h"
#include "../include/constants.h"
#include "../include/colors.h"

int STATUS = 0;

int main(int argc, char *argv[]) {
    char *line;

    printWelcomeMessage();

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
        int i = 0, argsCount = 0;

        while (args[i] != NULL) {
            argsCount++;
            printf("%s\n", args[i++]);
        }

        printf("argscount = %d\n", argsCount);

        executeCommand(args);

        free(args);
        free(line);
    }


    return EXIT_SUCCESS;
}