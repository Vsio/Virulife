/* ===========================
File : drawRhombusWithText.cs

Credit:
- Coded by (aka in cyber) Vsio Stitched
- Problem case inspired from my past in high school

Misc:
- Written in C# programming laguage

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

using System;

class Rhombus {
	
	private char char_;
	private int maxWidth_;

	// Constructor

	public Rhombus()
	/* Creates rhombus */
	{
		char_ = '0';
		maxWidth_ = 0;
	}
	
	public Rhombus(char _newChar, int _newMaxWidth)
	/* Creates rhombus */
	{
		char_ = _newChar;
		maxWidth_ = _newMaxWidth;
	}
	
	// Accessor

	public char getChar()
	/* Returns char_ value */
	{
		return char_;
	}
	
	public void setChar(char _newChar)
	/* Changes char_ value */
	{
		char_ = _newChar;
	}
	
	public int getMaxWidth() 
	/* Returns MaxWidth_ value */
	{
		return maxWidth_;
	}
	public void setMaxWidth(int _newMaxWidth)
	/* Returns MaxWidth_ value */
	{
		maxWidth_ = _newMaxWidth;
	}

	// Operation
	
	public void drawRhombus()
	/* Draws the rhombus shape using char_ Character with maximum width equals MaxWidth_ */
	{
		int i, j;

		for (i=maxWidth_-1; i>=0 ;i--) {
			if (i%2 == 1) {
				Console.Write(" ");
			}
				
			for (j=0; j<maxWidth_ ;j++) {		
				if ( ( j >= i/2) && (!(j >= maxWidth_-(i+1)/2) ) ) {
					Console.Write("{0} ",char_);
				} else { 
					Console.Write("  ");
				}
			}
			Console.Write("\n");
		}

		for (i=1; i<maxWidth_ ;i++) {
			if (i%2 == 1) {
				Console.Write(" ");			
			}
				
			for (j=0; j<maxWidth_ ;j++) {		
				if ( ( j >= i/2) && (!(j >= maxWidth_-(i+1)/2) ) ) {
					Console.Write("{0} ",char_);
				} else { 
					Console.Write("  ");
				}
			}
			Console.Write("\n");
		}
	}

}