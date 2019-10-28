#include <string.h>
#include <stdlib.h>

#include <utils.h>

#include "base64_2_ascii.h"

void base64_2_ascii(const char *input, char **output) {
    char *base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    const int inputLength = (int)strlen(input);
    int paddingLength = 0;
    if (inputLength >= 1 && input[inputLength - 1] == '=') {
        ++paddingLength;
    }
    if (inputLength >= 2 && input[inputLength - 2] == '=') {
        ++paddingLength;
    }
    int outputLength = (((inputLength - paddingLength) * 6) - (paddingLength == 0 ? 0 : paddingLength == 1 ? 2 : 4)) / 8;
    char *tmp = malloc(sizeof(char) * (outputLength + 1));
    int tmpIndex = 0;
    int *bits = malloc(sizeof(int) * 8);
    int bitArrayIndex = 0;
    for (int i = 0; i < (inputLength - paddingLength); ++i) {
        int *bitArray = malloc(sizeof(int) * 8);
        int base64Index = 0;
        while (base64Chars[base64Index] != input[i]) {
            ++base64Index;
        }

        for (int j = 32; j > 0; j = j / 2) {
            if (base64Index / j >= 1) {
                bits[bitArrayIndex++] = 1;
                base64Index -= j;
            } else {
                bits[bitArrayIndex++] = 0;
            }
            if (bitArrayIndex == 8) {
                int c = binToDec(bits);
                tmp[tmpIndex++] = (char)c;
                bitArrayIndex = 0;
            }
        }
    }
    tmp[tmpIndex] = 0;
    *output = tmp;
}