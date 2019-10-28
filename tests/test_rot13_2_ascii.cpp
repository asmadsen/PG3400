#include "test.h"

#include <cassert>

extern "C" {
#include "rot13_2_ascii.h"
#include "utils.h"
}

static void test_1() {
    std::string output;

    {
        char *input = (char *) "Svefg qb vg, gura qb vg evtug, gura qb vg orggre. - Nqql Bfznav";
        char *uOutput;
        rot13_2_ascii(input, &uOutput);
        output.assign(uOutput);
    }

    std::string expect = "First do it, then do it right, then do it better. - Addy Osmani";
    ASSERT_EQ(expect, output);
}

static void test_2() {
    std::string output;

    {
        char *input = (char *) "Gur tbbq arjf nobhg pbzchgref vf gung gurl qb jung lbh gryy gurz gb qb. Gur onq arjf vf gung gurl qb jung lbh gryy gurz gb qb. - Grq Aryfba";
        char *uOutput;
        rot13_2_ascii(input, &uOutput);
        output.assign(uOutput);
    }

    std::string expect = "The good news about computers is that they do what you tell them to do. The bad news is that they do what you tell them to do. - Ted Nelson";
    ASSERT_EQ(expect, output);
}

static void test_3() {
    std::string output;

    {
        char *input = (char *) "Gubfr ubhef bs cenpgvpr, naq snvyher, ner n arprffnel cneg bs gur yrneavat cebprff. - Tvan Fvcyrl";
        char *uOutput;
        rot13_2_ascii(input, &uOutput);
        output.assign(uOutput);
    }

    std::string expect = "Those hours of practice, and failure, are a necessary part of the learning process. - Gina Sipley";
    ASSERT_EQ(expect, output);
}

int main() {
    test_1();
    test_2();
    test_3();
    return EXIT_SUCCESS;
}
