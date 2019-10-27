#include "proxy.h"
#include "test.h"

#include <cassert>

extern "C" {
#include "ascii_2_hex.h"
#include "utils.h"
}

static void test_1() {
    std::string output;

    {
        std::string input = "Give someone a program, you frustrate them for a day; teach them how to program, you frustrate them for a lifetime. - David Leinweber";
        Proxy proxy(input);
        char *uInput;
        getInput(&uInput, stdin);
        char *uOutput;
        ascii_2_hex(uInput, &uOutput);
        output.assign(uOutput);
        proxy.output();
    }

    std::string expect = "47 69 76 65 20 73 6f 6d 65 6f 6e 65 20 61 20 70 72 6f 67 72 61 6d 2c 20 79 6f 75 20 66 72 75 73 74 72 61 74 65 20 74 68 65 6d 20 66 6f 72 20 61 20 64 61 79 3b 20 74 65 61 63 68 20 74 68 65 6d 20 68 6f 77 20 74 6f 20 70 72 6f 67 72 61 6d 2c 20 79 6f 75 20 66 72 75 73 74 72 61 74 65 20 74 68 65 6d 20 66 6f 72 20 61 20 6c 69 66 65 74 69 6d 65 2e 20 2d 20 44 61 76 69 64 20 4c 65 69 6e 77 65 62 65 72";
    ASSERT_EQ(expect, output);
}

static void test_2() {
    std::string output;

    {
        std::string input = "Programming isn't about what you know; it's about what you can figure out. - Chris Pine";
        Proxy proxy(input);
        char *uInput;
        getInput(&uInput, stdin);
        char *uOutput;
        ascii_2_hex(uInput, &uOutput);
        output.assign(uOutput);
        proxy.output();
    }

    std::string expect = "50 72 6f 67 72 61 6d 6d 69 6e 67 20 69 73 6e 27 74 20 61 62 6f 75 74 20 77 68 61 74 20 79 6f 75 20 6b 6e 6f 77 3b 20 69 74 27 73 20 61 62 6f 75 74 20 77 68 61 74 20 79 6f 75 20 63 61 6e 20 66 69 67 75 72 65 20 6f 75 74 2e 20 2d 20 43 68 72 69 73 20 50 69 6e 65";
    ASSERT_EQ(expect, output);
}

static void test_3() {
    std::string output;

    {
        std::string input = "Every great developer you know got there by solving problems they were unqualified to solve\nuntil they actually did it. - Patrick McKenzie";
        Proxy proxy(input);
        char *uInput;
        getInput(&uInput, stdin);
        char *uOutput;
        ascii_2_hex(uInput, &uOutput);
        output.assign(uOutput);
        proxy.output();
    }

    std::string expect = "45 76 65 72 79 20 67 72 65 61 74 20 64 65 76 65 6c 6f 70 65 72 20 79 6f 75 20 6b 6e 6f 77 20 67 6f 74 20 74 68 65 72 65 20 62 79 20 73 6f 6c 76 69 6e 67 20 70 72 6f 62 6c 65 6d 73 20 74 68 65 79 20 77 65 72 65 20 75 6e 71 75 61 6c 69 66 69 65 64 20 74 6f 20 73 6f 6c 76 65 0a 75 6e 74 69 6c 20 74 68 65 79 20 61 63 74 75 61 6c 6c 79 20 64 69 64 20 69 74 2e 20 2d 20 50 61 74 72 69 63 6b 20 4d 63 4b 65 6e 7a 69 65";
    ASSERT_EQ(expect, output);
}

int main() {
    test_1();
    test_2();
    test_3();
    return EXIT_SUCCESS;
}
