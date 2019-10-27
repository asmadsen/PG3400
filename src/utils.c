#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void getInput(char **pString) {
    char * destination = malloc(sizeof(char) * 200);
    destination[0] = 0;
    while (1) {
        char *input = malloc((sizeof(char) * 100) + 1);
        input[0] = 0;
        fgets(input, 100, stdin);
        if (!strlen(input)) {
            break;
        }
        char *tmp = malloc(sizeof(char)* (strlen(destination) + 100));
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