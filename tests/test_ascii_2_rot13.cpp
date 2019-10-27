#include "proxy.h"
#include "test.h"

#include <cassert>

extern "C" {
#include "ascii_2_rot13.h"
#include "utils.h"
}

static void test_1() {
  std::string output;

  {
    std::string input = "Be curious. Read widely. Try new things. I think a lot of what people call intelligence boils down to curiosity. - Aaron Swartz";
    Proxy proxy(input);
      char *uInput;
      getInput(&uInput, stdin);
      char *uOutput;
      ascii_2_rot13(uInput, &uOutput);
      output.assign(uOutput);
      proxy.output();
  }

  std::string expect = "Or phevbhf. Ernq jvqryl. Gel arj guvatf. V guvax n ybg bs jung crbcyr pnyy vagryyvtrapr obvyf qbja gb phevbfvgl. - Nneba Fjnegm";
  ASSERT_EQ(expect, output);
}

static void test_2() {
  std::string output;

  {
    std::string input = "Perfect software doesn't exist. No one in the brief history of computing has ever written a piece of perfect software. - Andrew Hunt";
    Proxy proxy(input);
      char *uInput;
      getInput(&uInput, stdin);
      char *uOutput;
      ascii_2_rot13(uInput, &uOutput);
      output.assign(uOutput);
      proxy.output();
  }

  std::string expect = "Cresrpg fbsgjner qbrfa'g rkvfg. Ab bar va gur oevrs uvfgbel bs pbzchgvat unf rire jevggra n cvrpr bs cresrpg fbsgjner. - Naqerj Uhag";
  ASSERT_EQ(expect, output);
}

static void test_3() {
  std::string output;

  {
    std::string input = "The only way to learn a new programming language is by writing programs in it. - Dennis Ritchie";
    Proxy proxy(input);
      char *uInput;
      getInput(&uInput, stdin);
      char *uOutput;
      ascii_2_rot13(uInput, &uOutput);
      output.assign(uOutput);
      proxy.output();
  }

  std::string expect = "Gur bayl jnl gb yrnea n arj cebtenzzvat ynathntr vf ol jevgvat cebtenzf va vg. - Qraavf Evgpuvr";
  ASSERT_EQ(expect, output);
}

int main() {
  test_1();
  test_2();
  test_3();
  return EXIT_SUCCESS;
}
