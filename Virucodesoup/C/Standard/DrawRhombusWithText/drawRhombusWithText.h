/* ===========================
File : drawRhombusWithText.h

Credit:
- Coded by (aka in cyber) Vsio Stitched
- Problem case inspired from my past in high school

Misc:
- Written in C programming laguage

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#ifndef DRAW_RHOMBUS_WITH_TEXT_H
#define DRAW_RHOMBUS_WITH_TEXT_H

typedef struct {char char_; int maxWidth_;} Rhombus;

// Constructor

Rhombus makeRhombus(char, int);
/* Creates rhombus */

// Accessor

char getChar(Rhombus);
/* Returns char_ value */

void setChar(Rhombus*, char);
/* Changes char_ value */

int getMaxWidth_(Rhombus);
/* Returns MaxWidth_ value */

void setMaxWidth_(Rhombus*, int);
/* Returns MaxWidth_ value */

// Operation

void header();
/* Writes description and header of the program */

void drawRhombus(Rhombus);
/* Draws the rhombus shape using char_ Character with maximum width equals MaxWidth_ */


#endif // DRAW_RHOMBUS_WITH_TEXT_H