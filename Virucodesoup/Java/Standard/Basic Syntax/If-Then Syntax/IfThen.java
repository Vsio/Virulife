/* ===========================
// File : IfThen.java
//
// Credit:
// - Coded by (aka in cyber) Vsio Stitched
//
// Misc:
// - Written in Java programming language
//
// License:
// - Free to use
// - May include me or not in credit if included in other project
// =========================== */

// This is to simulate conditional If-Then syntax. If true, then it will executes something. If false, nothing happens. For practice, try to change var1 and var 2 value.

package packviru;

import java.util.Scanner;

public class IfThen {

	public static void main(String[] args) {

		String pause;
		Scanner myScanner = new Scanner(System.in);
	
		int var1 = 5; // random value 1
		int var2 = 5; // random value 2

		if (var1 == var2) {
			System.out.println("Value is true"); // If true, then prints "Value is true"
		}

		pause = myScanner.nextLine(); // pauses command so it doesn't exit immediately

	}

}