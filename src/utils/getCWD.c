#include "../../include/main.h"


/**
 * Get the current working directory.
 * 
 * @param buf  Buffer to store the current working directory.
 * @param size Size of the buffer.
 * @return Pointer to the buffer containing the current working directory, or NULL on error.
 */
char *getCWD(char *buf, size_t size) {
    char *cwd = getcwd(buf, size);

    if (!cwd) {
        perror("getcwd() error");
        return NULL;
    }

    // TODO: modify paths that start from /home with ~/
    return cwd;
}