/* ===========================
File : vigenereCipher_ASCII.cpp

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

#include "vigenereCipher_ASCII.hpp"

using namespace std;

void header() {
	cout << "\n==###== Vigenere Cipher (ASCII) ==###==\n";

	cout << "\n------------------------------------\n\n";
	cout << ">> Application to encrypt / decrypt plaintext / ciphertext by switching the ascii based on the keyword or phrases used. \n\n";

	cout <<"> Misc:\n";
	cout <<"- Written in C++ programming language\n\n";

	cout <<"> Credit:\n";
	cout <<"- Coded by (aka in cyber) Vsio Stitched \n";

	cout <<"\n------------------------------------\n\n";
}


// CONSTRUCTOR

VigenereCipherASCII :: VigenereCipherASCII() {
	inputText_ = "";
	outputText_ = "";
	key_ = "";
}

// DESTRUCTOR

VigenereCipherASCII :: ~VigenereCipherASCII() {

}


// ACCESSOR GET

string VigenereCipherASCII :: getInputText() {
	return inputText_;
}

string VigenereCipherASCII :: getOutputText() {
	return outputText_;
}

string VigenereCipherASCII :: getKey() {
	return key_;
}


// ACCESSOR SET

void VigenereCipherASCII :: setInputText(string _newInputtext) {
	inputText_ = _newInputtext;
}

void VigenereCipherASCII :: setOutputText(string _newOutputText) {
	outputText_ = _newOutputText;
}

void VigenereCipherASCII :: setKey(string _newKey) {
	key_ = _newKey;
}


// METHOD

void VigenereCipherASCII :: menu() {
	string index = "";
	while (index != "5") {
		cout << "\n\n==> MENU\n\n";
		cout << "1. Encrypt\n";
		cout << "2. Encrypt with Auto-Key\n";
		cout << "3. Decrypt with Key\n";
		cout << "4. Decrypt with Auto-Key\n";
		cout << "5. Exit \n";
		cout << "\n> Select a number : ";
		cin >> index;
		if (index.length() == 1) {
			switch((int)index[0]) {
				case ((int)'1'): {
					inputFile();
					inputDisplay();
					inputKey();
					encryptKey(); 
					outputDisplay();
					outputFileEncrypt();
					index = "5";
				} break;
				
				case ((int)'2'): {
					inputFile();
					inputDisplay();
					inputKey();
					encryptAutoKey(); 
					outputDisplay();
					outputFileEncryptAutoKey();
					index = "5";
				} break;
				
				case ((int)'3'): {
					inputFile();
					inputDisplay();
					inputKey();
					decryptKey(); 
					outputDisplay();
					outputFileDecrypt();
					index = "5";				
				} break;
				
				case ((int)'4'): {
					inputFile();
					inputDisplay();
					inputKey();
					decryptAutoKey(); 
					outputDisplay();
					outputFileDecryptAutoKey();
					index = "5";				
				} break;				
				
				default: {	
					cout << "Invalid Input \n \n";
					index = "0";
				}
			}
		} else {
			cout << "Invalid Input \n \n";
			index = "0";
		}
	}
}

void VigenereCipherASCII :: inputKey() {

	cout << "Input Key : ";
	getline(cin,key_);
	getline(cin,key_);

}

string VigenereCipherASCII :: getRepeatKey() {
	string output = "";
	int i = 0;
	
	while (output.length() != inputText_.length()) {		
		output += key_[i];
		i++;
		if (i == key_.length()) {
			i = 0;
		}
	}
	cout << "Key becomes : " << output << "\n";
	return output;
}


void VigenereCipherASCII :: encryptKey() {
	string keyRepeated = getRepeatKey();
	string tempOutput = "";
	for (int i=0; i<inputText_.length(); i++) {
		tempOutput[0] = (char)((int)inputText_[i]+(int)keyRepeated[i])%256;
		outputText_ += tempOutput[0];
		tempOutput = "";
	}
}

void VigenereCipherASCII :: encryptAutoKey() {
	string keyAuto = key_;	
	int i = 0;
	int sub = 0;
	
	while (keyAuto.length() != inputText_.length()) {		
		keyAuto += inputText_[i];
		i++;
	}
	
	string tempOutput = "";
	for (int i=0; i<inputText_.length(); i++) {
		tempOutput[0] = (char)((int)inputText_[i]+(int)keyAuto[i])%256;		
		if (tempOutput[0] < 0) {
			tempOutput[0] += 256;
		}
		outputText_ += tempOutput[0];
		tempOutput = "";
	}
}

void VigenereCipherASCII :: decryptKey() {
	string keyRepeated = getRepeatKey();
	string tempOutput = "";

	for (int i=0; i<inputText_.length(); i++) {
		tempOutput[0] = (char)((int)inputText_[i]-(int)keyRepeated[i])%256;
		if ((int)tempOutput[0] < 0) {
			tempOutput[0] += 256;
		}
		outputText_ += tempOutput[0];
		tempOutput = "";
	}
}

void VigenereCipherASCII :: decryptAutoKey() {
	string keyAuto = key_;
	int i = 0;
	string tempOutput = "";
	
	while (outputText_.length() != inputText_.length()) {
		tempOutput[0] = (char)((int)inputText_[i]-(int)keyAuto[i])%256;		
		if (tempOutput[0] < 0) {
			tempOutput[0] += 256;
		}		
		outputText_ += tempOutput[0];
		keyAuto += tempOutput[0];
		tempOutput = "";		
		i++;
	}
}

void VigenereCipherASCII :: inputDisplay() {
	cout << "\n\n==> DISPLAY INPUT\n\n";
	cout << inputText_;
	cout << "\n\n";
}

void VigenereCipherASCII :: outputDisplay() {
	cout << "\n\n==> DISPLAY OUTPUT\n\n";
	cout << outputText_;
	cout << "\n\n";
}

void VigenereCipherASCII :: inputFile() {
	ifstream input;	
	string fileString = "";
	string tempString = "";
	
	printf("\nInput file name: ");
	cin >> fileString;		
	input.open(fileString.c_str());
	
	if (!input) {
		cout << "Can't open the file. \n";            
		cin.sync();
		cin.get();
		exit(1);
	}
	
	input >> noskipws;
	
	int i = 0;
	while (!input.eof()) {
		input >> tempString[i];		
		inputText_ += tempString[i];
	}
	
	inputText_ = inputText_.substr(0,inputText_.length()-1);
	input.close();
}

void VigenereCipherASCII :: outputFileEncrypt() {
	ofstream output;
	output.open("outputEncrypt.txt");

	output << outputText_;
	
	cout << "> Output has been saved into outputEncrypt.txt\n";
	
	output.close();
}

void VigenereCipherASCII :: outputFileEncryptAutoKey() {
	ofstream output;
	output.open("outputEncryptAutoKey.txt");

	output << outputText_;
	
	cout << "> Output has been saved into outputEncryptAutoKey.txt\n";
	
	output.close();
}

void VigenereCipherASCII :: outputFileDecrypt() {
	ofstream output;
	output.open("outputDecrypt.txt");

	output << outputText_;
	
	cout << "> Output has been saved into outputDecrypt.txt\n";
	
	output.close();
}

void VigenereCipherASCII :: outputFileDecryptAutoKey() {
	ofstream output;
	output.open("outputDecryptAutoKey.txt");

	output << outputText_;
	
	cout << "> Output has been saved into outputDecryptAutoKey.txt\n";
	
	output.close();
}


// DRIVER

void VigenereCipherASCII :: driver() {
	header();
	cout << "\n\n==> START PROGRAM\n\n";
	menu();
	cout << "\n\n==> END OF PROGRAM\n\n";
}