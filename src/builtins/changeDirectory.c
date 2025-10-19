#include "../../include/main.h"
#include "../../include/colors.h"


/**
 * change the current working directory.
 * @param args the arguments array
 * @param argc the number of arguments
 * @return 0 on success, error code on failure
 */

 //TODO: implement cd -
int changeDirectory(char **args, int argc) {
    // static char prevDir[BUFSIZ] = "~";

    if (args == NULL) {
        fprintf(stderr, RED"cd: invalid arguments\n"RESET);
        return EINVAL;
    }

    if (argc > 2) {
        fprintf(stderr, RED"cd: too many arguments\n"RESET);
        return EINVAL;
    }

    const char *path = args[1];
    
    if (isEmpty(path) || strcmp(path, "~") == 0) {
        char *HOME = getenv("HOME");

        if (chdir(HOME) == 0) {
            // strcpy(prevDir, HOME);
            return 0;
        }

        fprintf(stderr ,RED"cd: HOME directory not found: %s\n"RESET, HOME);
        return ENOENT;
    }

    // if (strcmp(path, "-") == 0) {
    //     printf("%s\n", prevDir);
        
    //     if (prevDir[0] == '\0') {
    //         return 0;
    //     }

    //     char temp[BUFSIZ];
    //     strcpy(temp, prevDir);

    //     getCWD(prevDir, BUFSIZ);

    //     if (strcmp(temp, "~") == 0) {
    //         char *HOME = getenv("HOME");

    //         if (chdir(HOME) == 0) {
    //             return 0;
    //         }

    //         fprintf(stderr ,RED"cd: HOME directory not found: %s\n"RESET, HOME);
    //         return ENOENT;
    //         return 0;
    //     }

    //     if (chdir(temp) == 0) {
    //         return 0;
    //     } else {
    //         fprintf(stderr ,RED"cd: no such file or directory: %s\n"RESET, temp);
    //         return ENOENT;
    //     }
    // }

    // getCWD(prevDir, BUFSIZ);

    if (chdir(path) == 0) {
        return 0;
    }

    fprintf(stderr ,RED"cd: no such file or directory: %s\n"RESET, path);
    
    return ENOENT;
}