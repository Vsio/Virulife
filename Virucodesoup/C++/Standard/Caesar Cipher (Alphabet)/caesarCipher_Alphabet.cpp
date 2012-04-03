/* ===========================
File : caesarCipher_Alphabet.cpp

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in C++ programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "caesarCipher_Alphabet.hpp"

using namespace std;


// global method

void header() {
	cout << "\n==###== Caesar Cipher (Alphabet) ==###==\n";

	cout << "\n------------------------------------\n\n";
	cout << ">> Application to encrypt / decrypt plaintext / ciphertext by switching the alphabet based its index to another alphabet index number key. \n\n";

	cout <<"> Misc:\n";
	cout <<"- Written in C++ programming language\n\n";

	cout <<"> Credit:\n";
	cout <<"- Coded by (aka in cyber) Vsio Stitched \n";

	cout <<"\n------------------------------------\n\n";
}


// CONSTRUCTOR

CaesarCipherAlphabet :: CaesarCipherAlphabet() {
	inputText_ = "";
	outputText_ = "";
	key_ = 0;
}


// DESTRUCTOR

CaesarCipherAlphabet :: ~CaesarCipherAlphabet() {
	
}


// ACCESSOR GET

string CaesarCipherAlphabet :: getInputText() {
	return inputText_;
}

string CaesarCipherAlphabet :: getOutputText() {
	return outputText_;
}

int CaesarCipherAlphabet :: getKey() {
	return key_;
}


// ACCESSOR SET

void CaesarCipherAlphabet :: setInputText(string _newInputtext) {
	inputText_ = _newInputtext;
}

void CaesarCipherAlphabet :: setOutputText(string _newOutputText) {
	outputText_ = _newOutputText;
}

void CaesarCipherAlphabet :: setKey(int _newKey) {
	key_ = _newKey;
}


// METHOD

void CaesarCipherAlphabet :: menu() {
/*
1. Encrypt
2. Decrypt (with key)
3. Decrypt (with Exhaustive Search)
4. Exit
*/	
	int index = 0;
	while (index != 4) {
	cout << "\n\n==> MENU\n\n";
	cout << "1. Encrypt \n";
	cout << "2. Decrypt (with key) \n";
	cout << "3. Decrypt (with Exhaustive Key Search) \n";
	cout << "4. Exit \n";
	cout << "\n> Select a number : ";
	cin >> index;
		switch (index) {
			case 1: {
				inputFile();
				inputDisplay();
				inputKey();
				encryptKey(); 
				outputDisplay();
				outputFileEncrypt();
				index = 4;
			} break;
			
			case 2: {
				inputFile();
				inputDisplay();
				inputKey();
				decryptKey();
				outputDisplay();
				outputFileDecrypt();
				index = 4;
			} break;
			
			case 3: {
				inputFile();
				inputDisplay();
				decryptBruteForce() ;
				index = 4;
			} break;
			
			case 4: {
			
			} break;
			
			default : { 
				cout << "Invalid Input \n \n";
				index = 0;
			}
		}
	}
}

void CaesarCipherAlphabet :: inputKey() {
	cout << "Input Key : ";
	cin >> key_;
}

void CaesarCipherAlphabet :: encryptKey() {
	for (int i=0; i<inputText_.length(); i++) {
		if ( islower(inputText_[i]) ) {			
			outputText_ += (inputText_[i]+key_ - (int)'a')%26 + (int)'A';
			if ( !isupper(outputText_[i]) ) {
				outputText_[i] +=26;
			}			
		} else if ( isupper(inputText_[i]) ) {
			outputText_ += (inputText_[i]+key_ - (int)'A')%26 + (int)'A';
			if ( !isupper(outputText_[i]) ) {
				outputText_[i] +=26;
			}	
		} else {
			outputText_ += inputText_[i];
		}
	}
	
}

void CaesarCipherAlphabet :: decryptKey() {
	for (int i=0; i<inputText_.length(); i++) {
		if ( islower(inputText_[i]) ) {
			outputText_ += (inputText_[i]-key_ - (int)'a')%26 + (int)'A';
			if ( !isupper(outputText_[i]) ) {
				outputText_[i] +=26;
			}			
		} else if ( isupper(inputText_[i]) ) {		
			outputText_ += (inputText_[i]-key_ - (int)'A')%26 + (int)'A';
			if ( !isupper(outputText_[i]) ) {
				outputText_[i] +=26;
			}
		} else {
			outputText_ += inputText_[i];
		}
	}
}

void CaesarCipherAlphabet :: decryptBruteForce() {
	ofstream output;
	output.open("outputDecryptExhaustiveKeySearch.txt");
	
	string* outputText = new string[26];
	
	cout << "\n\n==> DISPLAY OUTPUT\n\n";
	
	for (int i=0;i<=25;i++) {
		key_ = i;
		decryptKey();
		outputText[i] = outputText_;
		cout << "\nKey = " << i << ": " << outputText_;
		outputText_ = "";
	}
	
	for (int i=0;i<=25;i++) {
		output << "Key = ";
		output << i;
		output << " : "+outputText[i]+"\n";
		
	}
	
	cout << "\n\n> Output has been saved into outputDecryptExhaustiveKeySearch.txt\n";
	
	output.close();
}

void CaesarCipherAlphabet :: inputDisplay() {
	cout << "\n\n==> DISPLAY INPUT\n\n";
	cout << inputText_;
	cout << "\n\n";
}

void CaesarCipherAlphabet :: outputDisplay() {
	cout << "\n\n==> DISPLAY OUTPUT\n\n";
	cout << outputText_;
	cout << "\n\n";
}

void CaesarCipherAlphabet :: inputFile() {
	ifstream input;	
	
	string fileString = "";
	printf("\nInput file name: ");
	cin >> fileString;		
	input.open(fileString.c_str());
	
	if (!input) {
	cout << "Can't open the file. \n";            
	cin.sync();
	cin.get();
	exit(1);
	}
	
	while (!input.eof() ) {
		getline(input, inputText_);
	}
	
	input.close();
}

void CaesarCipherAlphabet ::  outputFileEncrypt() {
	ofstream output;
	output.open("outputEncrypt.txt");

	output << outputText_;
	
	cout << "> Output has been saved into outputEncrypt.txt\n";
	
	output.close();
}

void CaesarCipherAlphabet ::  outputFileDecrypt() {
	ofstream output;
	output.open("outputDecrypt.txt");
		
	output << outputText_;
	
	cout << "> Output has been saved into outputDecrypt.txt\n";
	
	output.close();
}


// DRIVER

void CaesarCipherAlphabet :: driver() {	
	header();
	cout << "\n\n==> START PROGRAM\n\n";
	menu();
	cout << "\n\n==> END OF PROGRAM\n\n";
}
