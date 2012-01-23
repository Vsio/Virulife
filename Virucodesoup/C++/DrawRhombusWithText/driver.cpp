/* ===========================
File : driver.cpp

Credit:
- Coded by (aka in cyber) Vsio Stitched
- Problem case inspired from my past in high school

Misc:
- Written in C++ programming laguage

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

using namespace std;

#include "drawRhombusWithText.hpp"
#include <iostream>

int main () {
	
	cout << "\n\n###### Program starts ######\n\n";
		
	Rhombus rhombus;
	char newChar;
	int newMaxWidth;

	header();

	cout << "\nInput a Character value => ";
	cin >> newChar;

	cout << "\nInput the Rhombus's maximum width value => ";
	cin >> newMaxWidth;

	cout << "\n\n";

	rhombus = Rhombus(newChar, newMaxWidth);

	rhombus.drawRhombus();
	
	cout << "\n\n###### Program ends ######\n\n";
	
	cin.sync();
	cin.get(); // Pause programs before exit

return 0;
}