#include <stdio.h>
#include <stdlib.h>
#include <utils.h>
#include <string.h>
#include <ctype.h>
#include "ascii_2_rot13.h"

void ascii_2_rot13() {
    char *str;
    getInput(&str);
    unsigned long strLen = strlen(str);
    char *output;
    output = malloc(sizeof(char) * strLen * 4);
    output[0] = 0;
    for (unsigned long i = 0; i < strLen; ++i) {
        int isNOrHigher = tolower(str[i]) >= 'n';
        sprintf(output + strlen(output), "%c",
                isalpha(str[i])
                ? str[i] + (isNOrHigher ? -13 : 13)
                : str[i]
                );
    }
    output[strlen(output)] = 0;
    printf("%s", output);
}