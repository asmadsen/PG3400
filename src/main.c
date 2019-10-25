#include "ascii_2_hex.h"
#include "ascii_2_rot13.h"
#include "hex_2_ascii.h"
#include "rot13_2_ascii.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Mode {
  HEX_2_ASCII,
  ASCII_2_HEX,
  rot13_2_ASCII,
  ASCII_2_rot13,
  MODE_ERROR
};

enum Mode getMode(char *program_name) {

  if (!program_name)
    return MODE_ERROR;

  if (strcmp("/hex2ascii", program_name) == 0)
    return HEX_2_ASCII;
  if (strcmp("/ascii2hex", program_name) == 0)
    return ASCII_2_HEX;
  if (strcmp("/rot132ascii", program_name) == 0)
    return rot13_2_ASCII;
  if (strcmp("/ascii2rot13", program_name) == 0)
    return ASCII_2_rot13;

  return MODE_ERROR;
}

int main(int argc, char *argv[]) {

  char *program_name = strrchr(argv[0], '/');

  if (!(argc == 1 || argc == 3)) {
    printf("Usages:\n");
    printf(".%s\n", program_name);
    printf(".%s <input file> <output file>\n", program_name);
    return EXIT_FAILURE;
  }

  enum Mode mode = getMode(program_name);

  switch (mode) {
    case HEX_2_ASCII:
      hex_2_ascii();
      break;
    case ASCII_2_HEX:
      ascii_2_hex();
      break;
    case rot13_2_ASCII:
      rot13_2_ascii();
      break;
    case ASCII_2_rot13:
      ascii_2_rot13();
      break;
    case MODE_ERROR:
    default:
      break;
  }

  return EXIT_SUCCESS;
}
