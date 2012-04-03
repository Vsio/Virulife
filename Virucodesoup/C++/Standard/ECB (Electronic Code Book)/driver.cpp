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

#include "ecb.hpp"

using namespace std;


int main() {

	header();	
	cout << "\n\n==> START PROGRAM\n\n";
	ECB ecb = ECB();
	ecb.driver();
	cout << "\n\n==> END OF PROGRAM\n\n";
	
	return 0;
}