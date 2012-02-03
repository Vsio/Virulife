/* ===========================
File : vigenereCipher_Alphabet.cpp

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

#include "vigenereCipher_Alphabet.hpp"

using namespace std;

void header() {
	cout << "\n==###== Vigenere Cipher (Alphabet) ==###==\n";

	cout << "\n------------------------------------\n\n";
	cout << ">> Application to encrypt / decrypt plaintext / ciphertext by switching the alphabet based on the keyword or phrases used. \n\n";

	cout <<"> Misc:\n";
	cout <<"- Written in C++ programming language\n\n";

	cout <<"> Credit:\n";
	cout <<"- Coded by (aka in cyber) Vsio Stitched \n";

	cout <<"\n------------------------------------\n\n";
}


// CONSTRUCTOR

VigenereCipherAlphabet :: VigenereCipherAlphabet() {
	inputText_ = "";
	outputText_ = "";
	key_ = "";
}

// DESTRUCTOR

VigenereCipherAlphabet :: ~VigenereCipherAlphabet() {

}


// ACCESSOR GET

string VigenereCipherAlphabet :: getInputText() {
	return inputText_;
}

string VigenereCipherAlphabet :: getOutputText() {
	return outputText_;
}

string VigenereCipherAlphabet :: getKey() {
	return key_;
}


// ACCESSOR SET

void VigenereCipherAlphabet :: setInputText(string _newInputtext) {
	inputText_ = _newInputtext;
}

void VigenereCipherAlphabet :: setOutputText(string _newOutputText) {
	outputText_ = _newOutputText;
}

void VigenereCipherAlphabet :: setKey(string _newKey) {
	key_ = _newKey;
}


// PREDICATE

bool VigenereCipherAlphabet :: isKeyValid() {
	int i = 0;
	bool output = true;
	
	while ( (i != key_.length()) && (output == true) ) {
		if (!isalpha(key_[i])) {
			output = false;
		}
		i++;
	}
	return output;
}
	

// METHOD

void VigenereCipherAlphabet :: menu() {
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

void VigenereCipherAlphabet :: inputKey() {
	bool keyValid = false;
	getline(cin,key_);
	while (keyValid == false) {
		cout << "Input Key : ";
		getline(cin,key_);
		cin.clear();
		cin.ignore(-1);		
		keyValid = isKeyValid();
		if (keyValid == false) {
			cout << "\n> Only alphabet is allowed. Try again.\n";			
		}
	}
}

string VigenereCipherAlphabet :: getRepeatKey() {
	string output = "";
	int i = 0;
	
	while (output.length() != inputText_.length()) {		
		output += toupper(key_[i]);
		i++;
		if (i == key_.length()) {
			i = 0;
		}
	}
	cout << "Key becomes : " << output << "\n";
	return output;
}

string VigenereCipherAlphabet :: getAllUpperCase(string _value) {
	string output = "";
	int i = 0;
	
	while (output.length() != _value.length()) {		
		if (isalpha(_value[i])) {
			output += toupper(_value[i]);			
		} else {
			output += _value[i];
		}
		i++;
	}
	
	return output;
}

void VigenereCipherAlphabet :: encryptKey() {
	string keyRepeated = getRepeatKey();
	string tempInput = getAllUpperCase(inputText_);
	for (int i=0; i<tempInput.length(); i++) {
		if ( isalpha(tempInput[i]) ) {
			outputText_ += (tempInput[i]- (int)'A'+keyRepeated[i] - (int)'A')%26 + (int)'A';
		} else {
			outputText_ += tempInput[i];
		}
	}
}

void VigenereCipherAlphabet :: encryptAutoKey() {
	string keyAuto;	
	int i = 0;
	int sub = 0;
	
	while (keyAuto.length() != inputText_.length()) {		
		if ( (!isalpha(inputText_[i])) && (keyAuto.length() != inputText_.length()) ) {
			keyAuto += " ";	
		} else {
			if (keyAuto.length() >= key_.length()) {					
				if (isalpha(inputText_[sub])) {
					if (isalpha(inputText_[sub])) {
						keyAuto += toupper(inputText_[sub]);
					} 
				}
				sub++;
				while (!isalpha(inputText_[sub])) {
					sub++;					
				}
			} else {
				keyAuto += toupper(key_[i]);			
			}		
		}
		i++;
	}
	
	string tempInput = getAllUpperCase(inputText_);
	for (int i=0; i<tempInput.length(); i++) {
		if ( isalpha(tempInput[i]) ) {
			outputText_ += (tempInput[i]- (int)'A'+keyAuto[i] - (int)'A')%26 + (int)'A';
		} else {
			outputText_ += tempInput[i];
		}
	}
}

void VigenereCipherAlphabet :: decryptKey() {
	string keyRepeated = getRepeatKey();
	string tempInput = getAllUpperCase(inputText_);

	for (int i=0; i<tempInput.length(); i++) {
		if ( isalpha(tempInput[i]) ) {
			outputText_ += (tempInput[i]- (int)'A'-keyRepeated[i] - (int)'A')%26 + (int)'A';
			if (!isalpha(outputText_[i])) {
				outputText_[i] += 26;
			}
		} else {
			outputText_ += tempInput[i];
		}
	}
}

void VigenereCipherAlphabet :: decryptAutoKey() {
	string keyAuto;		
	string tempInput = getAllUpperCase(inputText_);
	key_ = getAllUpperCase(key_);
	int keyInitLength = key_.length();
	int i = 0;
	int notAlpha = 0;
	string tempOutput = "";
	
	while (outputText_.length() != inputText_.length()) {
		if (!isalpha(tempInput[i])) {			
			outputText_ += tempInput[i];
			notAlpha -= 1;
		} else {
			tempOutput += (tempInput[i]- (int)'A'-key_[i] - (int)'A')%26 + (int)'A';
			if (!isalpha(tempOutput[0])) {
				tempOutput[0] += 26;
			}
			outputText_ += tempOutput[0];
			
			if (key_.length() != tempInput.length()) {
			
				while ( (!isalpha(tempInput[i+keyInitLength+notAlpha]) ) &&  (key_.length() != tempInput.length()) ){			
					key_ += "x"; 				
					notAlpha += 1;
				}
				tempInput[i+keyInitLength-1+notAlpha]; 
				
				if (isalpha(tempInput[i+keyInitLength+notAlpha]) ) {
					key_ += tempOutput;
				}
			
			}
			tempOutput = "";		
		}	
		i++;
	}
}

void VigenereCipherAlphabet :: inputDisplay() {
	cout << "\n\n==> DISPLAY INPUT\n\n";
	cout << inputText_;
	cout << "\n\n";
}

void VigenereCipherAlphabet :: outputDisplay() {
	cout << "\n\n==> DISPLAY OUTPUT\n\n";
	cout << outputText_;
	cout << "\n\n";
}

void VigenereCipherAlphabet :: inputFile() {
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

void VigenereCipherAlphabet :: outputFileEncrypt() {
	ofstream output;
	output.open("outputEncrypt.txt");

	output << outputText_;
	
	cout << "> Output has been saved into outputEncrypt.txt\n";
	
	output.close();
}

void VigenereCipherAlphabet :: outputFileEncryptAutoKey() {
	ofstream output;
	output.open("outputEncryptAutoKey.txt");

	output << outputText_;
	
	cout << "> Output has been saved into outputEncryptAutoKey.txt\n";
	
	output.close();
}

void VigenereCipherAlphabet :: outputFileDecrypt() {
	ofstream output;
	output.open("outputDecrypt.txt");

	output << outputText_;
	
	cout << "> Output has been saved into outputDecrypt.txt\n";
	
	output.close();
}

void VigenereCipherAlphabet :: outputFileDecryptAutoKey() {
	ofstream output;
	output.open("outputDecryptAutoKey.txt");

	output << outputText_;
	
	cout << "> Output has been saved into outputDecryptAutoKey.txt\n";
	
	output.close();
}


// DRIVER

void VigenereCipherAlphabet :: driver() {
	header();
	cout << "\n\n==> START PROGRAM\n\n";
	menu();
	cout << "\n\n==> END OF PROGRAM\n\n";
}