#ifndef MAIN_H
#define MAIN_H
 
// libraries

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <readline/history.h>
#include <readline/readline.h>

// utils

void printWelcomeMessage();
char *readShellLine();
char *getCWD(char *buf, size_t size);
char **lineTokenizer(char *line);
void executeCommand(char **args);
void interpretArgs(char **args, int argsCount);
int executeBuiltin(char **argv, int argc);
void handleSIGINT(int sig);

// builtins

int exitShell(char **argv, int argc);
int changeDirectory(char **args, int argc);

// functions

void *xMalloc(size_t size);
void *xRealloc(void *ptr, size_t size);
void xExecvp(const char *file, char *const argv[]);
pid_t xFork();
pid_t xWait(int *STATUS);
int isEmpty(char *string);

// globals

extern int STATUS;

// structs

typedef struct {
    char *name;
    int (* foo)(char **argv, int argc);
} builtin;

#endif /* MAIN_H */