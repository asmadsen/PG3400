#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <string.h>
#include "ascii_2_hex.h"

void ascii_2_hex(const char *input, char **output) {
    unsigned long strLen = strlen(input);
    char *tmp;
    tmp = malloc(sizeof(char) * strLen * 4);
    tmp[0] = 0;
    for (unsigned long i = 0; i < strLen; ++i) {
        sprintf(tmp + strlen(tmp), "%02x ", input[i]);
    }
    tmp[strlen(tmp) - 1] = 0;
    *output = tmp;
}