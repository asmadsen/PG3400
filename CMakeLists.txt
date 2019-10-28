cmake_minimum_required(VERSION 3.10)
project(c_on_linux_home_exam C CXX)

include_directories(include)

## Library:

set(DECODING_LIBRARY decoding)

add_library(${DECODING_LIBRARY} SHARED
        include/ascii_2_rot13.h
        include/ascii_2_hex.h
        include/rot13_2_ascii.h
        include/hex_2_ascii.h
        include/ascii_2_base64.h
        include/base64_2_ascii.h
        include/utils.h
        src/ascii_2_rot13.c
        src/ascii_2_hex.c
        src/rot13_2_ascii.c
        src/hex_2_ascii.c
        src/ascii_2_base64.c
        src/base64_2_ascii.c
        src/utils.c)

## Tool:

add_executable(tool src/main.c)
set_target_properties(tool PROPERTIES C_STANDARD 11)
target_link_libraries(tool ${DECODING_LIBRARY})

## Tests:

set(TEST_PROXY tests/proxy.cpp tests/proxy.h tests/test.h)
set(TEST_LIBRARIES ${DECODING_LIBRARY})
set(TEST_PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)

# ASCII_2_rot13
add_executable(test_ascii_2_rot13 ${TEST_PROXY} tests/test_ascii_2_rot13.cpp)
target_link_libraries(test_ascii_2_rot13 ${TEST_LIBRARIES})
set_target_properties(test_ascii_2_rot13 PROPERTIES ${TEST_PROPERTIES})

# ASCII_2_HEX
add_executable(test_ascii_2_hex ${TEST_PROXY} tests/test_ascii_2_hex.cpp)
target_link_libraries(test_ascii_2_hex ${TEST_LIBRARIES})
set_target_properties(test_ascii_2_hex PROPERTIES ${TEST_PROPERTIES})

# rot13_2_ASCII
add_executable(test_rot13_2_ascii ${TEST_PROXY} tests/test_rot13_2_ascii.cpp)
target_link_libraries(test_rot13_2_ascii ${TEST_LIBRARIES})
set_target_properties(test_rot13_2_ascii PROPERTIES ${TEST_PROPERTIES})

# HEX_2_ASCII
add_executable(test_hex_2_ascii ${TEST_PROXY} tests/test_hex_2_ascii.cpp)
target_link_libraries(test_hex_2_ascii ${TEST_LIBRARIES})
set_target_properties(test_hex_2_ascii PROPERTIES ${TEST_PROPERTIES})

# ASCII_2_BASE64
add_executable(test_ascii_2_base64 ${TEST_PROXY} tests/test_ascii_2_base64.cpp)
target_link_libraries(test_ascii_2_base64 ${TEST_LIBRARIES})
set_target_properties(test_ascii_2_base64 PROPERTIES ${TEST_PROPERTIES})

# BASE64_2_ASCII
add_executable(test_base64_2_ascii ${TEST_PROXY} tests/test_base64_2_ascii.cpp)
target_link_libraries(test_base64_2_ascii ${TEST_LIBRARIES})
set_target_properties(test_base64_2_ascii PROPERTIES ${TEST_PROPERTIES})

# Utils
add_executable(test_utils ${TEST_PROXY} tests/test_utils.cpp)
target_link_libraries(test_utils ${TEST_LIBRARIES})
set_target_properties(test_utils PROPERTIES ${TEST_PROPERTIES})
