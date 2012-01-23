/* ===========================
File : driver.cs

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

class Driver {

	static void Main(string[] args)
	{
		Console.Write("\n\n###### Program starts ######\n\n");
			
		Rhombus rhombus = new Rhombus();
		string newChar;
		int newMaxWidth;

		header();

		Console.Write("\nInput a Character value => ");
		newChar = Console.ReadLine();

		Console.Write("\nInput the Rhombus's maximum width value => ");
		newMaxWidth = Convert.ToInt32(Console.ReadLine());

		Console.WriteLine("\n\n");

		rhombus.setChar(newChar[0]);
		rhombus.setMaxWidth(newMaxWidth);

		rhombus.drawRhombus();
		
		Console.Write("\n\n###### Program ends ######\n\n");
		
		Console.ReadLine(); // Pause programs before exit
	}
	
	static void header()
	/* Writes description and header of the program */
	{
		Console.Write("\n==###== Draw Rhombus with Text ==###==\n");
	
		Console.Write("\n------------------------------------\n\n");
		Console.Write(">> Small application for drawing rhombus shape using text \n\n");
	
		Console.Write("> Misc:\n");
		Console.Write("- Written in C# programming language\n\n");
	
		Console.Write("> Credit:\n");
		Console.Write("- Coded by (aka in cyber) Vsio Stitched \n");
		Console.Write("- Problem case inspired from my past in high school \n");
	
		Console.Write("\n------------------------------------\n\n");
	}
	
}

