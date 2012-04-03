/* ===========================
File : ecb.hpp

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in C++ programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#ifndef _ECB_H_
#define _ECB_H_

#include <bitset>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


// global method

void header();
/* Writes description and header of the program */


class ECB {

	private:
	
	// FIELD
	
	string inputText_; /* stores the input of text */
	string inputKey_; /* stores bit input of key */
	string outputText_; /* stores value of output data */
	
	
	public:

	// CONSTRUCTOR
	
	ECB(); 
	/* constructs ECB instance */

	ECB(string,string); 
	/* constructs ECB instance with set values */
	
	
	// DESTRUCTOR
	
	~ECB();
	/* destroys ECB instance */
	
	
	// PREDICATE
	
	bool isKeyValid();
	/* checks whether input key is bit */
	
	
	// ACCESSOR GET
	
	string getInputText();
	/* returns inputText_ value */
	
	string getInputKey();
	/* returns inputKey_ value */
	
	string getoutputText();
	/* returns outputText_ value */
	
	
	// ACCESSOR SET
	
	void setInputText(string);
	/* changes inputText_ value */
	
	void setInputKey(string);
	/* changes inputKey_ value */
	
	void setoutputText(string);
	/* changes outputText_ value */

	
	// METHOD
	
	void menu();
	/* displays interface */
	
	void inputKey();
	/* input keys */
	
	string generateBitKey();
	/* generates bit key per block depends on text input length */
	
	string generateTextKey();
	/* generates text key based on text input and binary key */
	
	bitset<8> set8Bitset(string);
	/* changes 8 bit value */
	
	void loadInput();
	/* loads inputText_ from a file */
	
	void saveOutput(int);
	/* saves encryption or decryption to a file */
	
	string getPaddedText();
	/* adds remaining padding bits if plainttext length is undividiable by key length */
	
	string encrypt();
	/* does ECB encryption */
	
	string decrypt();
	/* does ECB decryption */

	
	// DRIVER
	
	void driver();
	/* performs class functionality */
	
};


#endif // _ECB_H_