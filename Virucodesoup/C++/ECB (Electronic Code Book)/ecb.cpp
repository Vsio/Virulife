/* ===========================
File : ecb.cpp

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in C++ programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#include "ecb.hpp"

using namespace std;


// global method

void header() {
	cout << "\n==###== ECB (Electronic Code Book) ==###==\n";

	cout << "\n------------------------------------\n\n";
	cout << ">> Encrypts/decrypts data with ECB (Electronic Code Book) method. \n\n";

	cout <<"> Misc:\n";
	cout <<"- Written in C++ programming language\n\n";

	cout <<"> Credit:\n";
	cout <<"- Coded by (aka in cyber) Vsio Stitched\n";

	cout <<"\n------------------------------------\n\n";
}


// CONSTRUCTOR

ECB :: ECB() {
	inputText_ = "";
	inputKey_ = "";
	outputText_ = "";
}

ECB :: ECB(string _newInputText, string _newInputKey) {
	inputText_ = _newInputText;
	inputKey_ = _newInputKey;
	outputText_ = "";
}


// DESTRUCTOR

ECB :: ~ECB() {

}


// ACCESSOR GET

string ECB :: getInputText() {
	return inputText_;
}

string ECB :: getInputKey() {
	return inputKey_;
}

string ECB :: getoutputText() {
	return outputText_;
}


// ACCESSOR SET

void ECB :: setInputText(string _newInputText) {
	inputText_ = _newInputText;
}

void ECB :: setInputKey(string _newInputKey) {
	inputKey_ = _newInputKey;
}

void ECB :: setoutputText(string _newOutputText) {
	outputText_ = _newOutputText;
}


// PREDICATE

bool ECB :: isKeyValid() {
	int i = 0;
	bool output = true;
	
	while ( (i != inputKey_.length()) && (output == true) ) {
		if ( (inputKey_[i] != '0') && (inputKey_[i] != '1') )  {
			output = false;
		}
		i++;
	}
	
	return output;
}


// METHOD

void ECB :: menu() {
	string index = "";
	
	while (index != "3") {
		cout << "\n\n==> MENU\n\n";
		cout << "1. Encrypt\n";
		cout << "2. Decrypt\n";
		cout << "3. Exit \n";
		cout << "\n> Select a number : ";
		getline(cin,index);
		if (index.length() == 1) {
			switch((int)index[0]) {
				case ((int)'1'): {
					loadInput();
					inputKey();
					outputText_ = encrypt();
					saveOutput(0);
					index = "3";
				} break;
				
				case ((int)'2'): {
					loadInput();
					inputKey();
					outputText_ = decrypt();
					saveOutput(1);
					index = "3";
				} break;
				
				case ((int)'3'): {
					/* exits loop */
				} break;
				
				default: {	
					cout << "Invalid Input \n \n";
					index = "";
				}
			}
		} else {
			cout << "Invalid Input \n \n";
			index = "0";
		}
	}
}

void ECB :: inputKey() {
	bool keyValid = false;
	inputKey_ = "";
	
	while (keyValid == false) {
		cout << "\nInput Binary Key (e.g.: 010110 ) : ";
		getline(cin,inputKey_);
		cin.clear();
		cin.ignore(-1);
		keyValid = isKeyValid();
		if (keyValid == false) {
			cout << "> Only 0 or 1 is allowed.\n";			
		}
	}
}

string ECB :: generateBitKey() {
	string key = inputKey_;
	string text = inputText_;
	
	while (key.length() < text.length()*8) {
		key += inputKey_;
	}
	
	while (key.length() % 8 != 0) {		
		key += '0';
	}
	
	return key;
}

string ECB :: generateTextKey() {

	string bitKey = generateBitKey();
	string textKey = "";
	int i =0;
	
	while (i != bitKey.length())
	{
		textKey += (char)(set8Bitset(bitKey.substr(i,8)).to_ulong());
		i += 8;
	}
	
	return textKey;
}

bitset<8> ECB :: set8Bitset(string _bit8string) {
	bitset<8> temp8Bit;
	string tempStr = _bit8string;
	
	for (int i=0;i!=8;i++) {
		temp8Bit.set(i,tempStr[i]-'0');
	}
	
	return temp8Bit;
}

void ECB :: loadInput() {
	ifstream input;	
	string fileString = "";
	string tempString = "";
	
	cout << "\nInput file name: ";	
	
	getline(cin,fileString);
	input.open(fileString.c_str());
	
	while (!input) {
		cout << "Can't open the file. \n";            
		cin.clear();
		cin.ignore(-1);		
		cout << "\nInput file name: ";
		getline(cin,fileString);
		input.open(fileString.c_str());
	}
	
	input >> noskipws;
	inputText_ = "";
	
	int i = 0;
	while (!input.eof()) {
		input >> tempString[i];
		inputText_ += tempString[i];
	}

	inputText_ = inputText_.substr(0,inputText_.length()-1);
	cout << inputText_ << "\n";
	input.close();
}

void ECB :: saveOutput(int _index) {
	ofstream output;
	
	if (_index == 0) {
		output.open("ecb_encrypt.txt");
		output << outputText_;
		cout << "\n> Output has been saved into ecb_encrypt.txt\n";
	} else if (_index == 1) {
		output.open("ecb_decrypt.txt");
		output << outputText_;
		cout << "\n> Output has been saved into ecb_decrypt.txt\n";	
	}
	
	output.close();
}

string ECB :: getPaddedText() {
	string key = generateTextKey();
	string output = inputText_;
	
	while (output.length() % key.length() != 0) {
		output += ' ';
	}
	
	return output;
}

string ECB :: encrypt() {
	string key = generateBitKey();
	string paddedText = getPaddedText();
	string output = "";
	
	for (int i=0;i!=paddedText.length();i++) {
		output += (char)key[i]^paddedText[i];
	}
	
	outputText_ = output;
	
	cout << "\nEncryption Result: ";
	cout << "\n" << outputText_ << "\n";
	
	return output;
}

string ECB :: decrypt() {
	string key = generateBitKey();
	string paddedText = inputText_;
	string output = "";
	
	for (int i=0;i!=paddedText.length();i++) {
		output += (char)key[i]^paddedText[i];
	}
	
	outputText_ = output;

	cout << "\nDecryption Result: ";
	cout << "\n" << outputText_ << "\n";
	
	return output;
}


// DRIVER

void ECB :: driver() {
	menu();
}