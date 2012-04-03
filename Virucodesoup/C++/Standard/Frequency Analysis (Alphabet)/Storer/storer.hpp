/* ===========================
File : storer.hpp

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in C++ programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#ifndef STORER_H
#define STORER_H

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Storer {
	
	private:

	// FIELD
	
	string groupLetters_;
	int amount_;
	
	public:
	
	// CONSTRUCTOR
	
	Storer();
	/* constructs Storer instance */
	
	Storer(string, int);
	/* constructs Storer instance with set groupLetters_ and amount_ value */
	
	// DESTRUCTOR
	
	~Storer();
	/* destroys Storer instance */
	
	
	// ACCESSOR GET
	
	string getGroupLetters();
	/* returns groupLetters_ value */

	int getAmount();
	/* returns amount_ value */
	
	
	// ACCESSOR SET

	void setGroupLetters(string);
	/* changes groupLetters_ value */

	void setAmount(int);
	/* changes amount_ value */

	
	// PREDICATE
	
	bool isSameGroup(Storer);
	/* checks whether a Storer with other Storer */
	
	
	// METHOD
	
	void print();
	/* displays groupLetters_ and amount_ value */
	
	void incAmount();
	/* increase amount_ by 1 */
	
	
	// DRIVER

	void driver();
	/* performs object functionally */
	
};

#endif // STORER_H