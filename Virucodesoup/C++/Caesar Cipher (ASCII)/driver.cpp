/* ===========================
File : driver.cpp

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in C++ programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "caesarCipher_ASCII.hpp"

using namespace std;

int main() {
	CaesarCipherASCII driver1;
	driver1.driver();
	cin.sync();
	cin.get(); 
	return 0;
}