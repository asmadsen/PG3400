#include <string.h>
#include <stdlib.h>

#include <stdio.h>

#include "ascii_2_base64.h"

void ascii_2_base64(const char *input, char **output) {
    char *base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    const int inputLength = strlen(input);
    int paddingLength;
    switch ((inputLength * 8) % 6) {
        case 2:
            paddingLength = 2;
            break;
        case 4:
            paddingLength = 1;
            break;
        default:
        case 0:
            paddingLength = 0;
            break;
    }
    int base64Length = ((inputLength * 8) / 6) + paddingLength;
    if (paddingLength != 0) {
        ++base64Length;
    }
    int *bits = malloc(sizeof(int) * base64Length * 6);
    memset(bits, 0, base64Length * 6);
    for (int i = 0; i < inputLength; ++i) {
        char c = input[i];
        for (int j = 7; j >= 0; j--) {
            bits[i*8 + (7 - j)] = (c >> j) & 1 ? 1 : 0;
        }
    }

    char *tmp = malloc(sizeof(char) * base64Length + 1);
    for (int i = 0; i < base64Length; ++i) {
        if (i >= base64Length - paddingLength) {
            tmp[i] = '=';
            continue;
        }
        char *bitBase = malloc(sizeof(char) * 6);
        for (int j = 0; j < 6; ++j) {
            char c = '0' + bits[i * 6 + j];
            bitBase[j] = c;
        }
        int total = 0;
        while (*bitBase) {
            total *= 2;
            if (*bitBase++ == '1') total += 1;
        }
        tmp[i] = base64Chars[total];
    }
    tmp[base64Length] = 0;

    *output = tmp;
}