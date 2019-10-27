#include "rot13_2_ascii.h"
#include "ascii_2_rot13.h"

void rot13_2_ascii(const char *input, char **output) {
    ascii_2_rot13(input, output);
}