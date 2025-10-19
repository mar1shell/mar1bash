#include "../../include/main.h"

/**
 * @attention The tokens array must be freed after use to avoid memory leaks.
 */
char **lineTokenizer(char *line) {
    if (isEmpty(line)) {
        return NULL;
    }

    const char *DELIMITER = " ";
    size_t tokensSize = 16; 
    char **tokens;
    char *token;
    int i = 0;

    tokens = xMalloc(tokensSize * sizeof(*tokens));
    token = strtok(line, DELIMITER);

    do {
        tokens[i++] = token;

        if ((size_t)(i + 1) >= tokensSize) {
            tokensSize *= 2;
            tokens = xRealloc(tokens, tokensSize);
        }
        
        token = strtok(NULL, DELIMITER);
    } while (token != NULL);

    tokens[i] = NULL;

    return tokens;
}