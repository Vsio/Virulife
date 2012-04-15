/* ===========================
// File : ifThenElse.cs
//
// Credit:
// - Coded by (aka in cyber) Vsio Stitched
//
// Misc:
// - Written in C# programming language
//
// License:
// - Free to use
// - May include me or not in credit if included in other project
// =========================== */

// This is to simulate conditional If-Then syntax. If true, then it will executes something. If false, it will also exexute something which usually different if the condional result is true. For practice, try to change var1 and var2 value.

using System;

class IfThenElse {

	public static void Main(String[] args) {

		int var1 = 5; // random value 1
		int var2 = 5; // random value 2

		if (var1 == var2) {
			Console.WriteLine("Value is true"); // If true, then prints "Value is true"
		} else {
			Console.WriteLine("Value is false"); // If false, then prints "Value is false"
		}

	Console.ReadLine(); // pauses command so it doesn't exit immediately
	
	}
	
}