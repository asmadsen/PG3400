#include "proxy.h"
#include "test.h"

#include <cassert>

extern "C" {
#include "utils.h"
}

static void test_1() {
    std::string input = "Give someone a program, you frustrate them for a day; teach them how to program, you frustrate them for a lifetime. - David Leinweber";
    char *output;

    {
        Proxy proxy(input);
        getInput(&output);
    }

    ASSERT_EQ(input, output);
}

static void test_2() {
    std::string input = "Programming isn't about what you know; it's about what you can figure out. - Chris Pine";
    char *output;

    {
        Proxy proxy(input);
        getInput(&output);
    }

    ASSERT_EQ(input, output);
}

static void test_3() {
    std::string input = "Every great developer you know got there by solving problems they were unqualified to solve\nuntil they actually did it. - Patrick McKenzie";
    char *output;

    {
        Proxy proxy(input);
        getInput(&output);
    }

    ASSERT_EQ(input, output);
}

int main() {
    test_1();
    test_2();
    test_3();
    return EXIT_SUCCESS;
}
