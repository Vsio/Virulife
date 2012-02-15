/* ===========================
File : frequencyAnalysis_Alphabet.hpp

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in C++ programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#ifndef FREQUENCY_ANALYSIS_ALPHABET_H
#define FREQUENCY_ANALYSIS_ALPHABET_H

#include <fstream>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <string>

#include "Storer/storer.hpp"

using namespace std;


// global method

void header();
/* Writes description and header of the program */

class FrequencyAnalysisAlphabet {
	
	private:

	// FIELD
	
	string inputText_; /* text to be analyzed its frequency group lettter */
	int nGroupLetters_; /* how many letters each group to be counted (N-Graph)*/
	list<Storer> storer_;
	list<Storer>::iterator storerIt_;
	
	public:
	
	// CONSTRUCTOR
	
	FrequencyAnalysisAlphabet();
	/* constructs FrequencyAnalysisAlphabet instance */
	
	
	// DESTRUCTOR
	
	~FrequencyAnalysisAlphabet();
	/* destroys FrequencyAnalysisAlphabet instance */
	
	
	// ACCESSOR GET
	
	string getInputText();
	/* returns inputText_ value */

	int getNGroupLetters();
	/* returns groupLetters_ value */
	
	
	// ACCESSOR SET

	void setInputText(string);
	/* changes inputText_ value */

	void setNGroupLetters(int);
	/* changes groupLetters_ value */
	
	
	// METHOD
	
	void inputNGroupLetters();
	/* sets the length of the nGroupLetters_(N-Graph) */
	
	string filterAlphabets(string);
	/* removes all non-alphabet of a text */
	
	void countFrequency();
	/* counts the frequency of group letters */
	
	void displayInput();
	/* displays input */
	
	void displayOutput();
	/* displays output */
	
	void inputFile();
	/* reads input from a file */
	
	void outputFile();
	/* saves output as a file */
	
	float calculatesPercentage(int, string);
	/* calculates the percentage of a letter group and message's length (filtered) divided by letter group length */
	
	
	// DRIVER

	void driver();
	/* performs object functionally */
	
};

#endif // FREQUENCY_ANALYSIS_ALPHABET_H