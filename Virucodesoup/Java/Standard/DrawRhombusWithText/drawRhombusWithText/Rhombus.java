/* ===========================
File : Rhombus.java

Credit:
- Coded by (aka in cyber) Vsio Stitched
- Problem case inspired from my past in high school

Misc:
- Written in Java programming laguage

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

package drawRhombusWithText;

public class Rhombus {

	char char_;
	int maxWidth_;
	
	// Constructor

	public Rhombus()
	/* Creates rhombus */	
	{
		this.char_ = 0;
		this.maxWidth_ = 0;
	}
	
	public Rhombus(char _char, int _maxWidth)
	/* Creates rhombus */
	{
		this.char_ = _char;
		this.maxWidth_ = _maxWidth;	
	}
	
	// Accessor

	public char getChar()
	/* Returns char_ value */
	{
		return this.char_;
	}
	
	public void setChar(char _char)
	/* Changes char_ value */
	{
		this.char_ = _char;
	}
	
	public int getMaxWidth()
	/* Returns MaxWidth_ value */ 
	{
		return this.maxWidth_;
	}
	
	public void setMaxWidth(int _maxWidth)
	/* Returns MaxWidth_ value */
	{
		this.maxWidth_ = _maxWidth;
	}
	
	// Operation
	
	public void drawRhombus()
	/* Draws the rhombus shape using char_ Character with maximum width equals MaxWidth_ */
	{
		int i, j;

		for (i=maxWidth_-1; i>=0 ;i--) {
			if (i%2 == 1) {
				System.out.print(" ");
			}
				
			for (j=0; j<maxWidth_ ;j++) {		
				if ( ( j >= i/2) && (!(j >= maxWidth_-(i+1)/2) ) ) {
					System.out.print(char_+" ");
				} else { 
					System.out.print("  ");
				}
			}
			System.out.print("\n");
		}

		for (i=1; i<maxWidth_ ;i++) {
			if (i%2 == 1) {
				System.out.print(" ");			
			}
				
			for (j=0; j<maxWidth_ ;j++) {		
				if ( ( j >= i/2) && (!(j >= maxWidth_-(i+1)/2) ) ) {
					System.out.print(char_+" ");
				} else { 
					System.out.print("  ");
				}
			}
			System.out.print("\n");
		}
	
	}

}