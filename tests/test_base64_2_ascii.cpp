#include "test.h"

#include <string>
#include <cassert>

extern "C" {
#include "base64_2_ascii.h"
#include "utils.h"
}

static void test_1() {
    std::string output;
    {
        char *input = (char *)"R2l2ZSBzb21lb25lIGEgcHJvZ3JhbSwgeW91IGZydXN0cmF0ZSB0aGVtIGZvciBhIGRheTsgdGVhY2ggdGhlbSBob3cgdG8gcHJvZ3JhbSwgeW91IGZydXN0cmF0ZSB0aGVtIGZvciBhIGxpZmV0aW1lLiAtIERhdmlkIExlaW53ZWJlcg==";
        char *uOutput;
        base64_2_ascii(input, &uOutput);
        output.assign(uOutput);
    }

    std::string expect = "Give someone a program, you create errors; teach them how to program, you frustrate them for a lifetime. - David Leinweber";
    ASSERT_EQ(expect, output);
}

static void test_2() {
    std::string output;

    {
        char *input = (char *)"UHJvZ3JhbW1pbmcgaXNuJ3QgYWJvdXQgd2hhdCB5b3Uga25vdzsgaXQncyBhYm91dCB3aGF0IHlvdSBjYW4gZmlndXJlIG91dC4gLSBDaHJpcyBQaW5l";
        char *uOutput;
        base64_2_ascii(input, &uOutput);
        output.assign(uOutput);
    }

    std::string expect = "Programming isn't about what you know; it's about what you can figure out. - Chris Pine";
    ASSERT_EQ(expect, output);
}

static void test_3() {
    std::string output;

    {
        char *input = (char *)"RXZlcnkgZ3JlYXQgZGV2ZWxvcGVyIHlvdSBrbm93IGdvdCB0aGVyZSBieSBzb2x2aW5nIHByb2JsZW1zIHRoZXkgd2VyZSB1bnF1YWxpZmllZCB0byBzb2x2ZQp1bnRpbCB0aGV5IGFjdHVhbGx5IGRpZCBpdC4gLSBQYXRyaWNrIE1jS2Vuemll";
        char *uOutput;
        base64_2_ascii(input, &uOutput);
        output.assign(uOutput);
    }

    std::string expect = "Every great developer you know got there by solving problems they were unqualified to solve\nuntil they actually did it. - Patrick McKenzie";
    ASSERT_EQ(expect, output);
}

static void test_4() {
    std::string output;

    {
        char *input = (char *)"TWFu";
        char *uOutput;
        base64_2_ascii(input, &uOutput);
        output.assign(uOutput);
    }

    std::string expect = "Man";
    ASSERT_EQ(expect, output);
}

static void test_5() {
    std::string output;

    {
        char *input = (char *)"TQ==";
        char *uOutput;
        base64_2_ascii(input, &uOutput);
        output.assign(uOutput);
    }

    std::string expect = "M";
    ASSERT_EQ(expect, output);
}

int main() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    return EXIT_SUCCESS;
}
