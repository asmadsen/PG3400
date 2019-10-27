#include "proxy.h"
#include "test.h"

#include <cassert>

extern "C" {
#include "hex_2_ascii.h"
#include "utils.h"
}

static void test_1() {
    std::string output;

    {
        std::string input = "50 72 6f 67 72 61 6d 6d 69 6e 67 20 69 73 20 6e 6f 74 20 61 62 6f 75 74 20 74 79 70 69 6e 67 2c 20 69 74 27 73 20 61 62 6f 75 74 20 74 68 69 6e 6b 69 6e 67 2e 20 2d 20 52 69 63 68 20 48 69 63 6b 65 79";
        Proxy proxy(input);
        char *uInput;
        getInput(&uInput, stdin);
        char *uOutput;
        hex_2_ascii(uInput, &uOutput);
        output.assign(uOutput);
        proxy.output();
    }

    std::string expect = "Programming is not about typing, it's about thinking. - Rich Hickey";
    ASSERT_EQ(expect, output);
}

static void test_2() {
    std::string output;

    {
        std::string input = "4a 61 76 61 20 69 73 20 74 6f 20 4a 61 76 61 53 63 72 69 70 74 20 77 68 61 74 20 43 61 72 20 69 73 20 74 6f 20 43 61 72 70 65 74 2e 20 2d 20 43 68 72 69 73 20 48 65 69 6c 6d 61 6e 6e";
        Proxy proxy(input);
        char *uInput;
        getInput(&uInput, stdin);
        char *uOutput;
        hex_2_ascii(uInput, &uOutput);
        output.assign(uOutput);
        proxy.output();
    }

    std::string expect = "Java is to JavaScript what Car is to Carpet. - Chris Heilmann";
    ASSERT_EQ(expect, output);

}

static void test_3() {
    std::string output;

    {
        std::string input = "49 66 20 69 74 20 64 6f 65 73 6e 27 74 20 77 6f 72 6b 2c 20 69 74 20 64 6f 65 73 6e 27 74 20 6d 61 74 74 65 72 20 68 6f 77 20 66 61 73 74 20 69 74 20 64 6f 65 73 6e 27 74 20 77 6f 72 6b 2e 20 2d 20 4d 69 63 68 20 52 61 76 65 72 61";
        Proxy proxy(input);
        char *uInput;
        getInput(&uInput, stdin);
        char *uOutput;
        hex_2_ascii(uInput, &uOutput);
        output.assign(uOutput);
        proxy.output();
    }

    std::string expect = "If it doesn't work, it doesn't matter how fast it doesn't work. - Mich Ravera";
    ASSERT_EQ(expect, output);
}

int main() {
    test_1();
    test_2();
    test_3();
    return EXIT_SUCCESS;
}
