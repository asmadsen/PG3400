#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "utils.h"

void getInput(char **pString, FILE *stream) {
    char *destination = malloc(sizeof(char) * 200);
    destination[0] = 0;
    while (1) {
        char *input = malloc((sizeof(char) * 100) + 1);
        input[0] = 0;
        fgets(input, 100, stream);
        if (!strlen(input)) {
            break;
        }
        char *tmp = malloc(sizeof(char) * (strlen(destination) + 100));
        strncpy(tmp, destination, strlen(destination));
        strncpy(tmp + strlen(destination), input, strlen(input));
        tmp[strlen(destination) + strlen(input)] = 0;
        free(input);
        free(destination);
        destination = malloc(sizeof(char) * strlen(tmp) + 1);
        strncpy(destination, tmp, strlen(tmp) + 1);
        free(tmp);
    }

    *pString = destination;
}

int loadFromFile(const char *file, FILE **stream) {
    FILE *tmp;
    if ((tmp = fopen(file, "r"))) {
        *stream = tmp;
        return 0;
    }

    return 1;
}

int binToDec(const int *bitArray) {
    char *data = malloc(sizeof(char) * 9);
    for (int i = 0; i < 8; ++i) {
        data[i] = (char)('0' + bitArray[i]);
    }
    data[8] = 0;
    return (int)strtol(data, 0, 2);
}