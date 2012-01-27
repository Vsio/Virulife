/* ===========================
File : FBH2012_AlphabetSoup.hpp

Credit:
- Coded by (aka in cyber) Vsio Stitched
- Problem case from Facebook Hacker Cup 2012 Qualification Round ( https://www.facebook.com/hackercup/problems.php?pid=341666075863455&round=146094915502528 )

Misc:
- Written in C++ programming laguage

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#ifndef FBH2012_ALPHABETSOUP_H
#define FBH2012_ALPHABETSOUP_H

#include <string>

using namespace std;

// global method

void header();
/* Writes description and header of the program */

class AlphabetSoup {
	
	private :
	
	// FIELD
	
	int T_;// Number of Cases
	int H_, A_, C_, K_, E_, R_, U_, P_; // HACKERCUP builder with each letter minimum equal 1 except C which is 2
	string* stringInput_;
	int stringInputLength_;
	int hackerCupCount_;
	int output_[20];
	
	public :
	
	// CONSTRUCTOR
	
	AlphabetSoup();
	/* Construct AlphabetSoup */
	
	
	// ACCESSOR GET
	
	int getT();
	/* returns T_ value */
	
	int getH();
	/* returns H_ value */
	
	int getA();
	/* returns A_ value */
	
	int getC();
	/* returns C_ value */
	
	int getK();
	/* returns K_ value */
	
	int getE();
	/* returns E_ value */
	
	int getR();
	/* returns R_ value */
	
	int getU();
	/* returns U_ value */
	
	int getP();
	/* returns P_ value */
	
	string getStringInput(int);
	/* returns stringInput_ value with targeted index */
	
	int getStringInputLength();
	/* returns stringInputLength value */
	
	int getHackerCupCount();
	/* returns hackerCupCount_ value */
	
	int getOutput(int);
	/* returns output_ value */
	
	
	// ACCESSOR SET
	
	void setT(int);
	/* sets T_ value */
	
	void setH(int);
	/* sets H_ value */
	
	void setA(int);
	/* sets A_ value */
	
	void setC(int);
	/* sets C_ value */
	
	void setK(int);
	/* sets K_ value */
	
	void setE(int);
	/* sets E_ value */
	
	void setR(int);
	/* sets R_ value */
	
	void setU(int);
	/* sets U_ value */
	
	void setP(int);
	/* sets P_ value */
	
	void setStringInput(int, string);
	/* sets stringInput_ value with targeted index */
	
	void setStringInputLength(int);
	/* sets stringInputLength value */
	
	void setHackerCupCount(int);
	/* sets hackerCupCount_ */

	void setOutput(int, int);
	/* sets output_ value */	
	
	// PREDICATE
	
	void isTValid();
	/* check whether T_ is more than 0 and less equal than 20. If false,  program exits. */
	
	void isStringInputValid(string);
	/* check whether stringInput_ is more than 0 characters and less equal than 1000 characters; and string contain only UpperCase letter and Space. If false, program exits. */
	
	bool hackerCupValid();
	/* returns true if there is enough letters to create HACKERCUP word from amount of H, A, C, K, E, R, U, and P letters. */
	
	
	// METHOD
	
	void reset();
	/* resets the numbers of  H, A, C, K, E, R, U, P and hackerCupCount_ to 0 so it can be used to the next case */
	
	void letterCount(char);
	/* counts letter of H, A, C, K, E, R, U, and P based on a char input */
	
	void letterScan(string);
	/* matchs letter from string input so its letter can be counted */
	
	void countHackerCup();
	/* add 1 to hackerCupCount_ if the number of H, A, C, K, E, R, U, and P letters are sufficient. If sufficient, reduce number of each letter by 1 except for C which is 2 */
	
	void inputFile();
	/* read text file as input */
	
	void outputFile();
	/* write text file as output */
	
	void AlphabetSoupPrintInput(int);
	/* print input from text file */
	
	void AlphabetSoupPrintOutput(int);
	/* print output after get processed */
	
	// DRIVER
	
	void AlphabetSoupDriver();
	/* performs object functionally */
	
};

#endif // FBH2012_ALPHABETSOUP_H