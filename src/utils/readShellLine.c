#include "../../include/colors.h"
#include "../../include/main.h"

/**
 * @attention line must be freed after use
 */
char *readShellLine() {
    char cwd[BUFSIZ];
    char prompt[BUFSIZ];
    char *user = getenv("USER");

    user = (user == NULL) ? "" : user;

    snprintf(prompt, BUFSIZ, GREEN"┌["RESET BLUE"mar1bash"RESET"@"BLUE"%s"RESET GREEN"] "RESET YELLOW"%s\n"RESET
                                  GREEN"└─> "RESET, user, getCWD(cwd, BUFSIZ));

    char *line = readline(prompt);

    if (errno == EINTR) {
        errno = 0;

        if (line != NULL) {
            line[0] = '\0';
        }

        return line;
    }

    if (!isEmpty(line)) {
        add_history(line);
    }

    return line;
}