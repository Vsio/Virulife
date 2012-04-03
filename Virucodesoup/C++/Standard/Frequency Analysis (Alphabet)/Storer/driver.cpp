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

#include "storer.hpp"

using namespace std;

int main() {
	cout << "\n\n==> START PROGRAM\n\n";
	Storer storer1 = Storer("A",1);
	Storer storer2 = Storer("BA",2);
	storer1.driver();
	storer2.driver();
	cout << "\n\n==> END OF PROGRAM\n\n";
	cin.sync();
	cin.get(); 
	return 0;
}