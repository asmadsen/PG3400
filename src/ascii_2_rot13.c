#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ascii_2_rot13.h"

void ascii_2_rot13(const char *input, char **output) {
    unsigned long strLen = strlen(input);
    char *tmp;
    tmp = malloc(sizeof(char) * strLen * 4);
    tmp[0] = 0;
    for (unsigned long i = 0; i < strLen; ++i) {
        int isNOrHigher = tolower(input[i]) >= 'n';
        sprintf(tmp + strlen(tmp), "%c",
                isalpha(input[i])
                ? input[i] + (isNOrHigher ? -13 : 13)
                : input[i]
        );
    }
    tmp[strlen(tmp)] = 0;
    *output = tmp;
}