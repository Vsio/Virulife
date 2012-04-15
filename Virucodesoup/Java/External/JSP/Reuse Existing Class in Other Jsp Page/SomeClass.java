/* ===========================
File : SomeClass.java

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in Java programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

package packviru;


public class SomeClass {
	
	private int someInt;
	private String someString;
	
	// CONSTRUCTOR
	
	public SomeClass() {
		this.someInt = 0;
		this.someString = "Default";
	}
	
	
	// ACCESSOR GET

	public int getSomeInt() {
		return this.someInt;
	}

	public String getSomeString() {
		return this.someString;
	}
	
	
	// ACCESSOR SET
	
	public void setSomeInt(int _newSomeInt) {
		this.someInt = _newSomeInt;
	}

	public void setSomeString(String _newSomeString) {
		this.someString = _newSomeString;
	}
	
	
	// DRIVER
	
	public static void Main(String[] args) {
		SomeClass sc = new SomeClass();
		System.out.println(sc.getSomeInt());
		System.out.println(sc.getSomeString());
	}

}