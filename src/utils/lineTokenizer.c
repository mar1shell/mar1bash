#include "../../include/main.h"

/**
 * @attention The tokens array must be freed after use to avoid memory leaks.
 */
char **lineTokenizer(char *line) {
    if (isEmpty(line)) {
        return NULL;
    }

    const char *DELIMITER = " ";
    size_t tokensSize = BUFSIZ; 
    char **tokens;
    char *token;
    int i = 0;

    tokens = xMalloc(tokensSize * sizeof(*tokens));
    token = strtok(line, DELIMITER);

    do {
        tokens[i++] = token;

        if (i >= tokensSize) {
            tokensSize *= 2;
            tokens = xRealloc(tokens, tokensSize);
        }
        
        token = strtok(NULL, DELIMITER);
    } while (token != NULL);

    tokens[i] = NULL;

    return tokens;
}