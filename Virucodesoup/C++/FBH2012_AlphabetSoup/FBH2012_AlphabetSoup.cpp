/* ===========================
File : FBH2012_AlphabetSoup.cpp

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

using namespace std;

// global method

void header() {
	cout << "\n==###== Alphabet Soup (Facebook Hacker Cup 2012) ==###==\n";

	cout << "\n------------------------------------\n\n";
	cout << ">> Application to count how many HACKERCUP word can be created from H, A, C, K, E, R, U, and P letters received.\n\n";

	cout <<"> Misc:\n";
	cout <<"- Written in C++ programming language\n\n";

	cout <<"> Credit:\n";
	cout <<"- Coded by (aka in cyber) Vsio Stitched \n";
	cout <<"- Problem case from Facebook Hacker Cup 2012 Qualification Round ( https://www.facebook.com/hackercup/problems.php?pid=341666075863455&round=146094915502528 ) \n";

	cout <<"\n------------------------------------\n\n";
}

// CONSTRUCTOR

AlphabetSoup :: AlphabetSoup() {
	T_ = 0;
	H_ = 0;
	A_ = 0;
	C_ = 0;
	K_ = 0;
	E_ = 0;
	R_ = 0;
	U_ = 0;
	P_ = 0;
	stringInput_ = new string[21];
	hackerCupCount_ = 0;
}

	
// ACCESSOR GET

int AlphabetSoup :: getT() {
	return T_;
}

int AlphabetSoup :: getH() {
	return H_;
}

int AlphabetSoup :: getA() {
	return A_;
}

int AlphabetSoup :: getC() {
	return C_;
}

int AlphabetSoup :: getK() {
	return K_;
}

int AlphabetSoup :: getE() {
	return E_;
}

int AlphabetSoup :: getR() {
	return R_;
}

int AlphabetSoup :: getU() {
	return U_;
}

int AlphabetSoup :: getP() {
	return P_;
}

string AlphabetSoup :: getStringInput(int _index) {
	return stringInput_[_index];
}

int AlphabetSoup :: getStringInputLength() {
	return stringInputLength_;
}

int AlphabetSoup :: getHackerCupCount() {
	return hackerCupCount_;
}

int AlphabetSoup :: getOutput(int _index) {
	return output_[_index];
}

// ACCESSOR SET

void AlphabetSoup :: setT(int _value) {
	T_ = _value;
}

void AlphabetSoup :: setH(int _value) {
	H_ = _value;
}

void AlphabetSoup :: setA(int _value) {
	A_ = _value;
}

void AlphabetSoup :: setC(int _value) {
	C_ = _value;
}

void AlphabetSoup :: setK(int _value){
	K_ = _value;
}

void AlphabetSoup :: setE(int _value) {
	E_ = _value;
}

void AlphabetSoup :: setR(int _value) {
	R_ = _value;
}

void AlphabetSoup :: setU(int _value) {
	U_ = _value;
}

void AlphabetSoup :: setP(int _value) {
	P_ = _value;
}

void AlphabetSoup :: setStringInput(int _index, string _value) {
	stringInput_[_index] = _value;
}

void AlphabetSoup :: setStringInputLength(int _value) {
	stringInputLength_ = _value;
}

void AlphabetSoup :: setHackerCupCount(int _value) {
	hackerCupCount_ = _value;
}

void AlphabetSoup :: setOutput(int _index, int _value) {
	output_[_index] = _value;
}
	

// PREDICATE

void AlphabetSoup :: isTValid() {
	if ((T_ > 0) && (T_ <= 20)) {
		// you shall pass
	} else {
	cout << "Error: T is 0 or T more than 20. \n";
	cout << "Exit program. \n";
	exit(1);
	}
}

void AlphabetSoup :: isStringInputValid(string _stringInput) {
	bool isNot0Chars = (_stringInput.length() > 0);
	bool isLess1000Chars = (_stringInput.length() <= 1000);
	bool isUpperOrSpace = true;
	int i = 0;
	
	while (i<_stringInput.length()) {
		if ( ( (isupper(_stringInput[i])) || (isspace(_stringInput[i])) ) ){
			// pass
		} else {
			isUpperOrSpace = false;
			cout << "Error: String input contains other than UpperCase Letter and Space.\n";
			cout << "Exit program.\n";
			exit(1);
		}
		i++;
	}
		
	
	if ((isNot0Chars==true) && (isLess1000Chars==true)) {
		// pass		
	} else {
		cout << "Error: String line input equals 0 or more than 1000. \n";
		cout << "Exit program. \n";
		exit(1);
	}

}

bool AlphabetSoup :: hackerCupValid() {
	bool output = false;
	if (H_ >= 1) {
		if (A_ >= 1) {
			if (C_ >= 2) {	
				if (K_ >= 1) {
					if (E_ >= 1) {
						if (R_ >= 1) {
							if (U_ >= 1) {
								if (P_ >= 1) {
									output = true;
								}
							}
						}
					}
				}		
			}		
		}
	}
	return output;
}

// METHOD

void AlphabetSoup :: reset() {
	H_ = 0;
	A_ = 0;
	C_ = 0;
	K_ = 0;
	E_ = 0;
	R_ = 0;
	U_ = 0;
	P_ = 0;
	hackerCupCount_ = 0;
}

void AlphabetSoup :: letterCount(char _char) {
	switch(_char) {
		case 'H': H_ += 1;break;
		case 'A': A_ += 1;break;
		case 'C': C_ += 1;break;
		case 'K': K_ += 1;break;
		case 'E': E_ += 1;break;
		case 'R': R_ += 1;break;
		case 'U': U_ += 1;break;
		case 'P': P_ += 1;break;
	}
}

void AlphabetSoup :: letterScan(string _inputString) {
	for (int i=0;i<=_inputString.length();i++){
		letterCount(_inputString[i]);
	}
}

void AlphabetSoup :: countHackerCup() {
	while (hackerCupValid() == true) {
		hackerCupCount_ += 1;
		H_ -= 1;
		A_ -= 1;
		C_ -= 2;
		K_ -= 1;
		E_ -= 1;
		R_ -= 1;
		U_ -= 1;
		P_ -= 1;
	}
}

void AlphabetSoup :: inputFile() {
		ifstream input;	
		
		string fileString = "";
		printf("Input file name: ");
		cin >> fileString;		
		input.open(fileString.c_str());
		
		
		printf("\n");
		
		if (!input) {
		cout << "Can't open the file. \n";            
		cin.sync();
		cin.get();
		exit(1);
		}
		
		
		input >> T_;
		getline(input, fileString);
		for (int i=1;i<=T_;i++) {
			getline(input, stringInput_[i]);
		}
		
		input.close();
}

void AlphabetSoup :: outputFile() {
	ofstream output;
	output.open("output.txt");

	output << "Number of Case: " << T_ << "\n \n";
	
	output << "INPUT :\n\n";
	
	for (int i=1;i<=T_;i++) {
		output << "Case #" << i << ": " <<stringInput_[i] << "\n";
	}
	
	output << "\nOUTPUT :\n\n";
	
	for (int i=1;i<=T_;i++) {
		output << "Case #" << i << ": " << output_[i] << "\n";
		reset();
	}
		
	output.close();
}

void AlphabetSoup :: AlphabetSoupPrintInput(int _index) {
	cout << stringInput_[_index] << "\n";
}

void AlphabetSoup :: AlphabetSoupPrintOutput(int _index) {
	cout << "Case #" << _index << ": " << hackerCupCount_ << "\n";
}

// DRIVER

void AlphabetSoup :: AlphabetSoupDriver() {

	cout << "\n\n==> START PROGRAM\n\n";
	
	inputFile();
	
	cout << "\n\n==> SCAN INPUT\n\n";
	
	for (int i=1;i<=T_;i++) {
		isTValid();
		isStringInputValid(stringInput_[i]);
	}
	cout << "Result: Input is valid.\n\n";
	
	cout << "\n\n==> DISPLAY INPUT\n\n";
	
	cout << T_ << "\n";
	for (int i=1;i<=T_;i++) {
		AlphabetSoupPrintInput(i);
	}
	
	cout << "\n\n==> DISPLAY OUTPUT\n\n";
	
	for (int i=1;i<=T_;i++) {	
		letterScan(stringInput_[i]); 
		countHackerCup();
		AlphabetSoupPrintOutput(i);
		output_[i] = hackerCupCount_;
		reset();
	}
	
	outputFile();
	
	cout << "\nOutput has been saved into output.txt\n";
	
	cout << "\n\n==> END OF PROGRAM\n\n";
}