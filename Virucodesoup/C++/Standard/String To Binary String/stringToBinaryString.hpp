/* ===========================
File : stringToBinaryString.hpp

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in C++ programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#ifndef _STRING_TO_BINARY_STRING_H_
#define _STRING_TO_BINARY_STRING_H_

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


void header();
/* Writes description and header of the program */

string stringToBinaryString();
/* converts string to string of binaries */

string saveOutput(string);
/* saves output into a output.txt */

#endif // _STRING_TO_BINARY_STRING_H_