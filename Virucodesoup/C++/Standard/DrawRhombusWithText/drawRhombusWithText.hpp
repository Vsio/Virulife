/* ===========================
File : drawRhombusWithText.hpp

Credit:
- Coded by (aka in cyber) Vsio Stitched
- Problem case inspired from my past in high school

Misc:
- Written in C++ programming laguage

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#ifndef DRAW_RHOMBUS_WITH_TEXT_H
#define DRAW_RHOMBUS_WITH_TEXT_H

using namespace std;

// global method

void header();
/* Writes description and header of the program */

class Rhombus {

	private :
	
	// Field
	
	char char_;
	int maxWidth_;

	public : 

	// Constructor

	Rhombus();
	/* Creates rhombus */	
	Rhombus(char, int);
	/* Creates rhombus */

	// Destructor 
	
	~Rhombus();
	
	// Accessor

	char getChar();
	/* Returns char_ value */
	void setChar(char);
	/* Changes char_ value */
	int getMaxWidth();
	/* Returns MaxWidth_ value */
	void setMaxWidth(int);
	/* Returns MaxWidth_ value */

	// Operation
	
	void drawRhombus();
	/* Draws the rhombus shape using char_ Character with maximum width equals MaxWidth_ */

};

#endif // DRAW_RHOMBUS_WITH_TEXT_H