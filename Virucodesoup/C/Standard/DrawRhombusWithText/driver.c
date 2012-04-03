/* ===========================
File : driver.c

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

int main () {
	
	printf("\n\n###### Program starts ######\n\n");
		
	Rhombus rhombus;
	char newChar;
	int newMaxWidth;

	header();

	printf("\nInput a Character value => ");
	scanf("%c", &newChar);

	printf("\nInput the Rhombus's maximum width value => ");
	scanf("%d", &newMaxWidth);

	printf("\n\n");

	rhombus = makeRhombus(newChar, newMaxWidth);

	drawRhombus(rhombus);
	
	printf("\n\n###### Program ends ######\n\n");
	getch(); // Pause programs before exit

return 0;
}