/* ===========================
File : driver.cpp

Credit:
- Coded by (aka in cyber) Vsio Stitched
- Problem case from Facebook Hacker Cup 2012 Qualification Round ( https://www.facebook.com/hackercup/problems.php?pid=341666075863455&round=146094915502528 )

Misc:
- Written in C++ programming laguage

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#include "FBH2012_AlphabetSoup.hpp"

#include <fstream>
#include <stdlib.h>
#include <string>
#include <iostream>

int main() {
	header();
	AlphabetSoup alphabetSoup = AlphabetSoup();
	alphabetSoup.AlphabetSoupDriver();	
	cin.sync();
	cin.get(); // Pause programs before exit	
	
	return 0;
}