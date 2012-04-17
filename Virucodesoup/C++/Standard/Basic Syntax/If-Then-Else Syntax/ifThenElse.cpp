/* ===========================
// File : IfThenElse.cpp
//
// Credit:
// - Coded by (aka in cyber) Vsio Stitched
//
// Misc:
// - Written in C++ programming language
//
// License:
// - Free to use
// - May include me or not in credit if included in other project
// =========================== */

// This is to simulate conditional If-Then-Else syntax. If true, then it will executes something. If false, it will also exexute something which usually different if the condional result is true. For practice, try to change var1 and var 2 value.

#include <iostream> // to enable printing

using namespace std;

int main() {
	
	int var1 = 5;
	int var2 = 5;
	
	if (var1 == var2) {
		cout << "Value is true" << endl; // If true, then prints "Value is true"
	} else {
		cout << "Value is false" << endl; // If false, then prints "Value is false"
	}
	
	cin.get(); // To pause, preventing instant end of program
	
}