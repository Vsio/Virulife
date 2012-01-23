/* ===========================
File : Driver.java

Credit:
- Coded by (aka in cyber) Vsio Stitched
- Problem case inspired from my past in high school

Misc:
- Written in Java programming laguage

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

import java.util.*;
import drawRhombusWithText.*;

class Driver {

	public static void main(String args[]) {
	
		Scanner myScanner = new Scanner(System.in);
	
		System.out.print("\n\n###### Program starts ######\n\n");
			
		Rhombus rhombus = new Rhombus();
		char newChar;
		int newMaxWidth;
		int pause;
		
		header();

		System.out.print("\nInput a Character value => ");
		newChar = myScanner.next().charAt(0);

		System.out.print("\nInput the Rhombus's maximum width value => ");
		newMaxWidth = myScanner.nextInt();
		
		System.out.print("\n\n");

		rhombus.setChar(newChar);
		rhombus.setMaxWidth(newMaxWidth);

		rhombus.drawRhombus();
		
		System.out.print("\n\n###### Program ends ######\n\n");
		
		pause = myScanner.next().charAt(0);
		
	}
	
	static void header() 
	/* Display header */
	{
		System.out.print("\n==###== Draw Rhombus with Text ==###==\n");
		
		System.out.print("\n------------------------------------\n\n");
		System.out.print(">> Small application for drawing rhombus shape using text \n\n");
		
		System.out.print("> Misc:\n");
		System.out.print("- Written in Java programming language\n\n");
		
		System.out.print("> Credit:\n");
		System.out.print("- Coded by (aka in cyber) Vsio Stitched \n");
		System.out.print("- Problem case inspired from my past in high school \n");
		
		System.out.print("\n------------------------------------\n\n");
	}
	
}