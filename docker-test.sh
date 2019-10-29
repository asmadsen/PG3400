#!/bin/bash
set -e
cp -r /tmp/app /tmp/testing
cd /tmp/testing
/usr/bin/cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" /tmp/testing
/usr/bin/cmake --build /tmp/testing --target all -- -j 4
./test_base64_2_ascii
./test_utils
./test_ascii_2_base64
./test_ascii_2_rot13
./test_ascii_2_hex
./test_rot13_2_ascii
./test_hex_2_ascii