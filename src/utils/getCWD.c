#include "../../include/main.h"
#include "../../include/colors.h"


/**
 * Get the current working directory.
 * 
 * @param buf  Buffer to store the current working directory.
 * @param size Size of the buffer.
 * @return Pointer to the buffer containing the current working directory, or NULL on error.
 */
char *getCWD(char *buf, size_t size) {
    char *cwd = getcwd(buf, size);
    char *HOME = getenv("HOME");
    int homeLength = strlen(HOME);

    if (!cwd) {
        fprintf(stderr, RED"getcwd() error"RESET);
        return NULL;
    }
    
    // TODO: modify paths that start from /home with ~/
    if (strncmp(HOME, cwd, homeLength) == 0) {
        cwd[0] = '~';

        char *temp1 = cwd + 1;
        char *temp2 = cwd + homeLength;

        while (*temp2 != '\0') {
            *temp1 = *temp2;
            temp1++;
            temp2++;
        }

        *temp1 = '\0';
    }

    return cwd;
}