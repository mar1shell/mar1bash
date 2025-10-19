#include "../../include/colors.h"
#include "../../include/main.h"
#include "../../include/constants.h"

/**
 * Print the welcome message.
 * This function displays an ASCII art welcome message to the console.
 */
void printWelcomeMessage() {
    printf(GREEN"███╗   ███╗ █████╗ ██████╗  ██╗██████╗  █████╗ ███████╗██╗  ██╗\n"
                "████╗ ████║██╔══██╗██╔══██╗███║██╔══██╗██╔══██╗██╔════╝██║  ██║\n"
                "██╔████╔██║███████║██████╔╝╚██║██████╔╝███████║███████╗███████║\n"
                "██║╚██╔╝██║██╔══██║██╔══██╗ ██║██╔══██╗██╔══██║╚════██║██╔══██║\n"
                "██║ ╚═╝ ██║██║  ██║██║  ██║ ██║██████╔╝██║  ██║███████║██║  ██║\n"
                "╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n"
                "---------------------------------------------------------------\n"RESET);
    printf("Type " GREEN"'help'"RESET " to see available commands.\n");
    printf("Type " GREEN"'exit'"RESET " or press " GREEN"Ctrl+D"RESET " to quit.\n\n");
}

/**
 * Malloc wrapper with error checking.
 * Allocates memory and checks for allocation failure.
 */
void *xMalloc(size_t size) {
    if (size == 0) {
        fprintf(stderr, RED"Attempt to allocate zero bytes\n"RESET);
        exit(EXIT_FAILURE);
    }

    void *ptr = malloc(size);

    if (ptr == NULL) {
        fprintf(stderr, RED"Memory allocation failed\n"RESET);
        exit(EXIT_FAILURE);
    }

    return ptr;
}

/**
 * Realloc wrapper with error checking.
 * Reallocates memory and checks for allocation failure.
 */
void *xRealloc(void *ptr, size_t size) {
    if (size == 0) {
        fprintf(stderr, RED"Attempt to reallocate zero bytes\n"RESET);
        exit(EXIT_FAILURE);
    }

    void *new_ptr = realloc(ptr, size);

    if (new_ptr == NULL) {
        fprintf(stderr, RED"Memory reallocation failed\n"RESET);
        exit(EXIT_FAILURE);
    }

    return new_ptr;
}


/**
 * Fork wrapper with error checking.
 * Creates a new process and checks for fork failure.
 */
pid_t xFork() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, RED"Fork failed: %s\n"RESET, strerror(errno));
        STATUS = errno;
    }

    return pid;
}

/**
 * excvp wrapper with error checking.
 * Executes a program and checks for execution failure.
 */

void xExecvp(const char *file, char *const argv[]) {
    if (file == NULL || argv == NULL) {
        fprintf(stderr, RED"Invalid arguments to execvp\n"RESET);
        return;
    }

    if (execvp(file, argv) == -1) {
        fprintf(stderr, RED"Execution failed: %s\n"RESET, strerror(errno));
        STATUS = errno;
        exit(EXIT_FAILURE);
    }
}

/**
 * Wait wrapper with error checking.
 * Waits for a child process to change state and checks for wait failure.
 */

pid_t xWait(int *STATUS) {
    if (STATUS == NULL) {
        fprintf(stderr, RED"Invalid STATUS pointer for wait\n"RESET);
        return -1;
    }

    pid_t result = wait(STATUS);

    if (result == -1) {
        fprintf(stderr, RED"Wait failed: %s\n"RESET, strerror(errno));
        *STATUS = errno;
    }

    if (WIFEXITED(*STATUS)) {
        *STATUS = WEXITSTATUS(*STATUS);
    } else {
        *STATUS = -1; // Indicate abnormal termination
        fprintf(stderr, RED"Child process did not terminate normally\n"RESET);
    }

    return result;
}


/**
 * trim a string from leading and trailling whitspaces
 */
int isEmpty(const char *string) {
    if (string == NULL || string[0] == '\0') {
        return TRUE;
    }

    const char *currChar = string;

    while (*currChar != '\0') {
        if (!isspace((unsigned char) *currChar)) {
            return FALSE;
        }

        currChar++;
    }

    return TRUE;
}