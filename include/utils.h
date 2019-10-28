#include <stdio.h>

#ifndef C_ON_LINUX_HOME_EXAM_UTILS_H
#define C_ON_LINUX_HOME_EXAM_UTILS_H

void getInput(char **pString, FILE *stream);

int loadFromFile(const char *file, FILE **stream);

int binToDec(const int *bitArray);

#endif //C_ON_LINUX_HOME_EXAM_UTILS_H
