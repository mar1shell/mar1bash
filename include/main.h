#ifndef MAIN_H
#define MAIN_H
 
// libraries

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

// utils

void printWelcomeMessage();
char *readShellLine();
char *getCWD(char *buf, size_t size);
char **lineTokenizer(char *line);
void executeCommand(char **args);

// functions

void *xMalloc(size_t size);
void *xRealloc(void *ptr, size_t size);
void xExecvp(const char *file, char *const argv[]);
pid_t xFork();
pid_t xWait(int *STATUS);

// globals

extern int STATUS;

#endif /* MAIN_H */