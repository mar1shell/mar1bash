#include "../../include/colors.h"
#include "../../include/main.h"

/**
 * @attention line must be freed after use
 */
char *readShellLine() {
    char cwd[BUFSIZ];
    char prompt[BUFSIZ];

    sprintf(prompt, GREEN"┌["RESET BLUE"mar1bash"RESET GREEN"] "RESET YELLOW"%s\n"RESET
                                  GREEN"└─> "RESET, getCWD(cwd, BUFSIZ));

    char *line = readline(prompt);

    if (line != NULL) {
        add_history(line);
    }

    return line;
}