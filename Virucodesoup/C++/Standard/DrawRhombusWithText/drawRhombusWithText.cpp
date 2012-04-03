/* ===========================
File : drawRhombusWithText.cpp

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

// global method

void header() {
	cout << "\n==###== Draw Rhombus with Text ==###==\n";
	
	cout << "\n------------------------------------\n\n";
	cout << ">> Small application for drawing rhombus shape using text \n\n";
	
	cout <<"> Misc:\n";
	cout <<"- Written in C++ programming language\n\n";
	
	cout <<"> Credit:\n";
	cout <<"- Coded by (aka in cyber) Vsio Stitched \n";
	cout <<"- Problem case inspired from my past in high school \n";
	
	cout <<"\n------------------------------------\n\n";
}

// Constructor

Rhombus :: Rhombus() {
	char_ = '0';
	maxWidth_ = 0;
}

Rhombus :: Rhombus(char _newChar, int _newMaxWidth) {
	char_ = _newChar;
	maxWidth_ = _newMaxWidth;
}

// Destructor

Rhombus :: ~Rhombus() {

}

// Accessor

char Rhombus :: getChar() {
	return char_;
}

void Rhombus :: setChar(char _newChar) {
	char_ = _newChar;
}

int Rhombus :: getMaxWidth() {
	return maxWidth_;
}

void Rhombus :: setMaxWidth(int _newMaxWidth) {
	maxWidth_ = _newMaxWidth;
}

// Operation

void Rhombus :: drawRhombus() {
	int i, j;

	for (i=maxWidth_-1; i>=0 ;i--) {
		if (i%2 == 1) {
			cout << " ";
		}
			
		for (j=0; j<maxWidth_ ;j++) {		
			if ( ( j >= i/2) && (!(j >= maxWidth_-(i+1)/2) ) ) {
				cout << char_<< " ";
			} else { 
				cout <<"  ";
			}
		}
		cout << "\n";
	}

	for (i=1; i<maxWidth_ ;i++) {
		if (i%2 == 1) {
			cout << " ";			
		}
			
		for (j=0; j<maxWidth_ ;j++) {		
			if ( ( j >= i/2) && (!(j >= maxWidth_-(i+1)/2) ) ) {
				cout << char_ <<" ";
			} else { 
				cout << "  ";
			}
		}
		cout <<"\n";
	}
	
}