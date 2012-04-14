/* ===========================
File : HelloWorld.java

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in Java programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

package packviru;


public class HelloWorld {
	
	
	// CONSTRUCTOR
	
	public HelloWorld() {
		
	}
	
	
	// METHOD
	
	public String sayHelloWorld() 
	// Says Hello World!
	{
		//System.out.print("Hello World!");
		return "Hello World!";
	}
	
	
	// DRIVER
	
	public static void main(String[] args) {
		HelloWorld hw = new HelloWorld();
		System.out.println(hw.sayHelloWorld());
	}

}