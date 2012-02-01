/* ===========================
File : caesarCipher_ASCII.cpp

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

#include "caesarCipher_ASCII.hpp"

using namespace std;


// global method

void header() {
	cout << "\n==###== Caesar Cipher (ASCII) ==###==\n";

	cout << "\n------------------------------------\n\n";
	cout << ">> Application to encrypt / decrypt plaintext / ciphertext by switching the ASCII based on its index to other ASCII based on its index. \n\n";

	cout <<"> Misc:\n";
	cout <<"- Written in C++ programming language\n\n";

	cout <<"> Credit:\n";
	cout <<"- Coded by (aka in cyber) Vsio Stitched \n";

	cout <<"\n------------------------------------\n\n";
}


// CONSTRUCTOR

CaesarCipherASCII :: CaesarCipherASCII() {
	inputText_ = "";
	outputText_ = "";
	key_ = 0;
}


// DESTRUCTOR

CaesarCipherASCII :: ~CaesarCipherASCII() {
	
}


// ACCESSOR GET

string CaesarCipherASCII :: getInputText() {
	return inputText_;
}

string CaesarCipherASCII :: getOutputText() {
	return outputText_;
}

int CaesarCipherASCII :: getKey() {
	return key_;
}


// ACCESSOR SET

void CaesarCipherASCII :: setInputText(string _newInputtext) {
	inputText_ = _newInputtext;
}

void CaesarCipherASCII :: setOutputText(string _newOutputText) {
	outputText_ = _newOutputText;
}

void CaesarCipherASCII :: setKey(int _newKey) {
	key_ = _newKey;
}


// METHOD

void CaesarCipherASCII :: menu() {
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

void CaesarCipherASCII :: inputKey() {
	cout << "Input Key : ";
	cin >> key_;
}

void CaesarCipherASCII :: encryptKey() {
	for (int i=0; i<inputText_.length(); i++) {
		outputText_ += (inputText_[i]+key_)%256;
		if ((int)outputText_[i] < 0) {
			outputText_[i] +=256;
		}			
	}	
}

void CaesarCipherASCII :: decryptKey() {
	for (int i=0; i<inputText_.length(); i++) {
		outputText_ += (inputText_[i]-key_)%256;
		if ((int)outputText_[i] < 0) {
			outputText_[i] +=256;
		}			
	}
}

void CaesarCipherASCII :: decryptBruteForce() {
	ofstream output;
	output.open("outputDecryptExhaustiveKeySearch.txt");
	
	string* outputText = new string[256];
	
	cout << "\n\n==> DISPLAY OUTPUT\n\n";
	
	for (int i=0;i<=255;i++) {
		key_ = i;
		decryptKey();
		outputText[i] = outputText_;
		cout << "\nKey = " << i << ": " << outputText_;
		outputText_ = "";
	}
	
	for (int i=0;i<=255;i++) {
		output << "Key = ";
		output << i;
		output << " : "+outputText[i]+"\n";
		
	}
	
	cout << "\n\n> Output has been saved into outputDecryptExhaustiveKeySearch.txt\n";
	
	output.close();
}

void CaesarCipherASCII :: inputDisplay() {
	cout << "\n\n==> DISPLAY INPUT\n\n";
	cout << inputText_;
	cout << "\n\n";
}

void CaesarCipherASCII :: outputDisplay() {
	cout << "\n\n==> DISPLAY OUTPUT\n\n";
	cout << outputText_;
	cout << "\n\n";
}

void CaesarCipherASCII :: inputFile() {
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

void CaesarCipherASCII ::  outputFileEncrypt() {
	ofstream output;
	output.open("outputEncrypt.txt");

	output << outputText_;
	
	cout << "> Output has been saved into outputEncrypt.txt\n";
	
	output.close();
}

void CaesarCipherASCII ::  outputFileDecrypt() {
	ofstream output;
	output.open("outputDecrypt.txt");
		
	output << outputText_;
	
	cout << "> Output has been saved into outputDecrypt.txt\n";
	
	output.close();
}


// DRIVER

void CaesarCipherASCII :: driver() {	
	header();
	cout << "\n\n==> START PROGRAM\n\n";
	menu();
	cout << "\n\n==> END OF PROGRAM\n\n";
}
