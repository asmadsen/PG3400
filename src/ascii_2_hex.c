#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <string.h>
#include "ascii_2_hex.h"

void ascii_2_hex() {
    char *str;
    getInput(&str);
    unsigned long strLen = strlen(str);
    char *output;
    output = malloc(sizeof(char) * strLen * 4);
    output[0] = 0;
    for (unsigned long i = 0; i < strLen; ++i) {
        sprintf(output + strlen(output), "%02x ", str[i]);
    }
    output[strlen(output) - 1] = 0;
    printf("%s", output);
}