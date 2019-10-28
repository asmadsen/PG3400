#include <string>
#ifndef C_ON_LINUX_HOME_EXAM_TEST_H
#define C_ON_LINUX_HOME_EXAM_TEST_H

void printSuccess(const char *function) {
  printf("%s: PASS\n", function);
}

void printError(const char *assertion, const char *file,
                unsigned int line, const char *function) {
  printf("%s: Assertion '%s' failed - %s:%d\n", function, assertion, file, line);
}

void printError(const char *lhs_name,
                const char *rhs_name,
                const std::string &lhs,
                const std::string &rhs,
                const char *file,
                unsigned int line,
                const char *function) {
  printf("%s: '%s' not equal to '%s' - %s:%d\n", function, lhs_name, rhs_name, file, line);
  printf("%s: %s\n", lhs_name, lhs.c_str());
  printf("%s: %s\n", rhs_name, rhs.c_str());
}

#define ASSERT_EQ(lhs, rhs)              \
     (static_cast <bool> (lhs == rhs)            \
      ? printSuccess(__ASSERT_FUNCTION)           \
      : printError (#lhs, #rhs, static_cast<std::string>(lhs), static_cast<std::string>(rhs), __FILE__, __LINE__, __ASSERT_FUNCTION))

#define ASSERT(expr)              \
     (static_cast <bool> (expr)            \
      ? printSuccess(__ASSERT_FUNCTION)           \
      : printError (#expr, __FILE__, __LINE__, __ASSERT_FUNCTION))

#endif //C_ON_LINUX_HOME_EXAM_TEST_H
