/* ===========================
File : Driver.java

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in Java programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

import java.io.*;
import java.util.*;
import packVigenereCipherASCII.*;

class Driver {

	public static void main(String args[]) throws Exception {
		String pause;
		Scanner myScanner = new Scanner(System.in);
		
		header();		
		VigenereCipherASCII driver1 = new VigenereCipherASCII();	
		driver1.driver();		
		pause = myScanner.nextLine();
	}
	
	static void header() 
	/* Display header */
	{
		System.out.print("\n==###== Vigenere Cipher (ASCII) ==###==\n");
		
		System.out.print("\n------------------------------------\n\n");
		System.out.print(">> Application to encrypt / decrypt plaintext / ciphertext by switching the ASCII based on the keyword or phrases used. \n\n");
		
		System.out.print("> Misc:\n");
		System.out.print("- Written in Java programming language\n\n");
		
		System.out.print("> Credit:\n");
		System.out.print("- Coded by (aka in cyber) Vsio Stitched \n");
		
		System.out.print("\n------------------------------------\n\n");
	}

}