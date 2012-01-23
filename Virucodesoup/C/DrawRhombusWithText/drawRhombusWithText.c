/* ===========================
File : drawRhombusWithText.c

Credit:
- Coded by (aka in cyber) Vsio Stitched
- Problem case inspired from my past in high school

Misc:
- Written in C programming laguage

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#include "drawRhombusWithText.h"
#include <stdio.h>

// Constructor

Rhombus makeRhombus(char _newChar, int _newMaxWidth) {
	Rhombus rhombus;
	rhombus.char_ = _newChar;
	rhombus.maxWidth_ = _newMaxWidth;
	return rhombus;
}

// 

// Accessor

char getChar(Rhombus _rhombus) {
	return _rhombus.char_;
}

void setChar(Rhombus* _rhombus, char _newChar) {
	(*_rhombus).char_ = _newChar;
}

int getMaxWidth(Rhombus _rhombus) {
	return _rhombus.maxWidth_;
}

void setMaxWidth(Rhombus* _rhombus, int _newMaxWidth) {
	(*_rhombus).maxWidth_ = _newMaxWidth;
}

// Operation

void header() {
	printf("\n==###== Draw Rhombus with Text ==###==\n");
	
	printf("\n------------------------------------\n\n");
	printf(">> Small application for drawing rhombus shape using text \n\n");
	
	printf("> Misc:\n");
	printf("- Written in C programming language\n\n");
	
	printf("> Credit:\n");
	printf("- Coded by (aka in cyber) Vsio Stitched \n");
	printf("- Problem case inspired from my past in high school \n");
	
	printf("\n------------------------------------\n\n");
}

void drawRhombus(Rhombus _rhombus) {
	int i, j;

	for (i=_rhombus.maxWidth_-1; i>=0 ;i--) {
		if (i%2 == 1) {
			printf(" ");			
		}
			
		for (j=0; j<_rhombus.maxWidth_ ;j++) {		
			if ( ( j >= i/2) && (!(j >= _rhombus.maxWidth_-(i+1)/2) ) ) {
				printf("%c ", _rhombus.char_);
			} else { 
				printf("  ");
			}
		}
		printf("\n");
	}

	for (i=1; i<_rhombus.maxWidth_ ;i++) {
		if (i%2 == 1) {
			printf(" ");			
		}
			
		for (j=0; j<_rhombus.maxWidth_ ;j++) {		
			if ( ( j >= i/2) && (!(j >= _rhombus.maxWidth_-(i+1)/2) ) ) {
				printf("%c ", _rhombus.char_);
			} else { 
				printf("  ");
			}
		}
		printf("\n");
	}
	
}




