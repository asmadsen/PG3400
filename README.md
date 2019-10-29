# PG3400 Home Exam 2019 [![Build Status](https://travis-ci.com/Westerdals/pg3400-home-exam-asmadsen.svg?token=CtziNfWQqQxtrfWutyqx&branch=master)](https://travis-ci.com/Westerdals/pg3400-home-exam-asmadsen)

Your name and student id:
~~~~
Andreas Storesund Madsen
705313
~~~~

## Go through the [Setup Instructions](SETUP.md)

## Introduction

This project builds a tool to be used for converting between different 
kinds of "encodings".

The ones used in parts 1-4 are

* [ASCII](https://en.wikipedia.org/wiki/ASCII) - this encoding uses 7 bit 
of a byte for each letter, supporting mainly the English language.
* [ASCII as Hex](https://www.rapidtables.com/convert/number/hex-to-ascii.html) - 
scroll down to see the table mapping the decimal/hex/symbols to eachother.
* [Rot 13](https://en.wikipedia.org/wiki/ROT13) - which is such a simple
cypher that it can count as an encoding.
 
Since the tool should be able to read from standard in and write to
standard out, it can be chained like so:

~~~~
cat data/rot13_test_1.txt | ./rot132ascii | ./ascii2hex
~~~~

## Structure of the project

As you can see from the CMakeLists.txt file this project builds several artifacts:

* A library called **decoders**
* 4 different test binaries : **test_ascii_2_hex**, **test_hex_2_ascii**, **test_ascii_2_rot13**, **test_ascii_2_rot13**
* A commandline tool called **tool**

The projects **setup.sh** bash script creates 4 symlinks to the **tool** binary

* **ascii2hex**
* **hex2ascii**
* **rot132ascii**
* **ascii2rot13**

The main function for the the **tool** binary is in *src/main.c*

**Tip**: make sure the build directory is called *cmake-build-debug*: 
This is accomplished by in *Settings > CMake* the configuration is 
called *Debug*. If it isn't the symbolic links (symlinks) won't work.

## Functionality

The purpose of this project is to make a single **tool** binary that can
behave as different kinds of converters based on the name it was invoked
with. This functionality is already implemented in *src/main.c*.

This tool should read its input from stdin and write its output to stdout.
This means that it can be chained using pipes.

## Implementation

The majority of the coding in 1-4 is done by implementing the functions in
* *src/ascii_2_hex.c*
* *src/hex_2_ascii.c*
* *src/ascii_2_rot13.c*
* *src/rot13_2_ascii.c*

To implement 5 you need to make changes in *src/main.c* in addition to the above.

0. Set up the project so that it builds and runs the tests in ubuntu
1. ASCII to hex converter - Implement in : *src/ascii_2_hex.c*
~~~~
./cmake-build-debug/test_ascii_2_hex
cat data/ascii_test_1.txt | ./ascii2hex | diff data/hex_test_1.txt -
~~~~
2. Hex to ASCII converter - Implement in : *src/hex_2_ascii.c*
~~~~
./cmake-build-debug/test_hex_2_ascii
cat data/hex_test_1.txt | ./hex2ascii | diff data/ascii_test_1.txt -
~~~~
Put 1 and 2 together:
~~~~
cat data/hex_test_1.txt | ./hex2ascii | ./ascii2hex | diff data/hex_test_1.txt -
cat data/ascii_test_1.txt | ./ascii2hex | ./hex2ascii | diff data/ascii_test_1.txt -
~~~~
3. ASCII to Rot13 converter - Implement in : *src/ascii_2_rot13.c*
~~~~
./cmake-build-debug/test_ascii_2_rot13
cat data/rot13_test_1.txt | ./rot132ascii | diff data/ascii_test_1.txt -
~~~~
4. Rot13 to ASCII converter - Implement in : *src/rot13_2_ascii.c*
~~~~
./cmake-build-debug/test_rot13_2_ascii 
cat data/ascii_test_1.txt | ./ascii2rot13 | diff data/rot13_test_1.txt -
~~~~
5. Add support for reading from and writing to file - changes needed in many files
~~~~
./ascii2hex <input file> <output file>
./ascii2rot13 <input file> <output file>
./hex2ascii <input file> <output file>
./rot132ascii <input file> <output file>
~~~~
Testing examples
~~~~
./ascii2hex data/ascii_test_1.txt data/hex_output.txt
diff data/hex_output.txt data/hex_test_1.txt
~~~~
~~~~
./ascii2rot13 data/ascii_test_1.txt data/rot13_output.txt
diff data/rot13_output.txt data/rot13_test_1.txt
~~~~
~~~~
./hex2ascii data/hex_test_1.txt data/ascii_output.txt
diff data/ascii_output.txt data/ascii_test_1.txt
~~~~
~~~~
./rot132ascii data/rot13_test_1.txt data/ascii_output.txt
diff data/ascii_output.txt data/ascii_test_1.txt
~~~~

## Too Easy?
6. Add [Base64](https://en.wikipedia.org/wiki/Base64) encoding and decoding (including test and test files).

~~~~
./cmake-build-debug/test_ascii_2_base64
cat data/ascii_test_1.txt | ./ascii2base64 | diff data/base64_test_1.txt -
~~~~

~~~~
./cmake-build-debug/test_base64_2_ascii
cat data/base64_test_1.txt | ./base642ascii | diff data/ascii_test_1.txt -
~~~~

## Tips
- __READ THE TESTS__
- *Add more tests*
- Check out the man pages for these
~~~~
man 3 scanf
man 3 printf
man 3 fflush
man 2 read
man 3 strtol
~~~~
Useful converters:
- [https://www.rapidtables.com/convert/number/ascii-to-hex.html]
- [https://multiencoder.com]

## Tips for grading
* Try to keep the solution as simple as you can
* Add tests

## Notes
The Proxy class is used in the tests to test that the code reads and writes correctly to stdin and stdout. It is not related to the project and can be ignored.
