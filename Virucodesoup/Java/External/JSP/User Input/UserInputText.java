/* ===========================
File : UserInputText.java

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in Java programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

package packviru;


public class UserInputText {
	
	
	// CONSTRUCTOR
	
	public UserInputText() {
		
	}
	
	
	// METHOD
	
	public String input(String input) 
	// Returns text from what user have entered
	{
		return "You have entered: "+ input;
	}

	
	// DRIVER
	
	public static void Main(String[] args) {
		UserInputText uit = new UserInputText();
		System.out.println(uit.input("Test"));
	}
	
}