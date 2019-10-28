#include "test.h"

#include <cassert>

extern "C" {
#include "ascii_2_rot13.h"
#include "utils.h"
}

static void test_1() {
    std::string output;

    {
        char *input = (char *) "Be curious. Read widely. Try new things. I think a lot of what people call intelligence boils down to curiosity. - Aaron Swartz";
        char *uOutput;
        ascii_2_rot13(input, &uOutput);
        output.assign(uOutput);
    }

    std::string expect = "Or phevbhf. Ernq jvqryl. Gel arj guvatf. V guvax n ybg bs jung crbcyr pnyy vagryyvtrapr obvyf qbja gb phevbfvgl. - Nneba Fjnegm";
    ASSERT_EQ(expect, output);
}

static void test_2() {
    std::string output;

    {
        char *input = (char *) "Perfect software doesn't exist. No one in the brief history of computing has ever written a piece of perfect software. - Andrew Hunt";
        char *uOutput;
        ascii_2_rot13(input, &uOutput);
        output.assign(uOutput);
    }

    std::string expect = "Cresrpg fbsgjner qbrfa'g rkvfg. Ab bar va gur oevrs uvfgbel bs pbzchgvat unf rire jevggra n cvrpr bs cresrpg fbsgjner. - Naqerj Uhag";
    ASSERT_EQ(expect, output);
}

static void test_3() {
    std::string output;

    {
        char *input = (char *) "The only way to learn a new programming language is by writing programs in it. - Dennis Ritchie";
        char *uOutput;
        ascii_2_rot13(input, &uOutput);
        output.assign(uOutput);
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
