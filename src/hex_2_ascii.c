#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hex_2_ascii.h"

int count_tokens(const char *input) {
    if (input == NULL) return 0;
    int tokensCount = 0;
    int stringLength = (int) strlen(input);
    int wasSpace = 1;
    for (int i = 0; i < stringLength; ++i) {
        if (input[i] == ' ') {
            wasSpace = 1;
            continue;
        } else if (wasSpace == 1) {
            tokensCount++;
        }
        wasSpace = 0;
    }
    return tokensCount;
}

int split_into_strings(const char *input, char ***output) {
    int tokensCount = count_tokens(input);

    char **array = malloc(tokensCount * sizeof(char *));
    int curToken = 0;
    int lastSpace = -1;
    int i = 0;
    while (input[i]) {
        if (input[i] == ' ') {
            int len = i - (lastSpace + 1);
            if (len == 0) continue;
            char *tmp = malloc((len + 1) * sizeof(char));
            strncpy(tmp, (input + (lastSpace + 1)), len);
            tmp[len] = 0;
            lastSpace = i;

            array[curToken++] = tmp;
        }
        i++;
    }
    int len = i - (lastSpace + 1);
    if (len > 0) {
        char *tmp = malloc((len + 1) * sizeof(char));
        strncpy(tmp, (input + (lastSpace + 1)), len);
        tmp[len] = 0;
        array[curToken] = tmp;
    }
    *output = array;
    return tokensCount;
}


void hex_2_ascii(const char *input, char **output) {
    unsigned long strLen = strlen(input);
    char **tokens;
    int tokensCount = split_into_strings(input, &tokens);
    char *tmp;
    tmp = malloc(sizeof(char) * tokensCount + 1);
    tmp[0] = 0;
    for (unsigned long i = 0; i < tokensCount; ++i) {
        sprintf(tmp + strlen(tmp), "%c", (int) strtol(tokens[i], NULL, 16));
    }
    tmp[strlen(tmp)] = 0;
    free(tokens);
    *output = tmp;
}