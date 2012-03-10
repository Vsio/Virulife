/* ===========================
File : stringToBinaryString.cpp

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in C++ programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#include "stringToBinaryString.hpp"

using namespace std;


// METHOD


void header() {
	cout << "\n==###== String To Binary String ==###==\n";

	cout << "\n------------------------------------\n\n";
	cout << ">> Converts a String into Binary String. \n\n";

	cout <<"> Misc:\n";
	cout <<"- Written in C++ programming language\n\n";

	cout <<"> Credit:\n";
	cout <<"- Coded by (aka in cyber) Vsio Stitched\n";

	cout <<"\n------------------------------------\n\n";
}

string stringToBinaryString() {
	char buffer[8];
	string output = "";
	string text = "";
	string bit = "";
	
	cout << "\nInput some text: ";
	getline(cin, text);

	for (int i=0;i!=text.length();i++) {
		itoa(text[i],buffer,2);
		
		bit = buffer;
		
		while (bit.length() != 8) {
			bit = '0' + bit;
		}

		output += bit;
		bit = "";
	}

	cout << "\nResult:\n" << output;
	
	return output;
}

string saveOutput(string _input) {
	ofstream output;
	
	output.open("output.txt");
	output << _input;
	cout << "\n> Saved into output.txt";
	
	output.close();
}