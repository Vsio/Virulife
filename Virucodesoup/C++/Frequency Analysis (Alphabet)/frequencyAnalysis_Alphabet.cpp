/* ===========================
File : frequencyAnalysis_Alphabet.cpp

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in C++ programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#include "frequencyAnalysis_Alphabet.hpp"

using namespace std;


// global method

void header() {
	cout << "\n==###== Frequency Analysis (Alphabet) ==###==\n";

	cout << "\n------------------------------------\n\n";
	cout << ">> Application to count the frequency of groups of letters. \n\n";

	cout <<"> Misc:\n";
	cout <<"- Written in C++ programming language\n\n";

	cout <<"> Credit:\n";
	cout <<"- Coded by (aka in cyber) Vsio Stitched \n";

	cout <<"\n------------------------------------\n\n";
}


// CONSTRUCTOR

FrequencyAnalysisAlphabet :: FrequencyAnalysisAlphabet() {
	inputText_ = "";
	nGroupLetters_ = 1;
	storer_.empty();
	storerIt_ = storer_.begin();
}


// DESTRUCTOR

FrequencyAnalysisAlphabet :: ~FrequencyAnalysisAlphabet() {

}


// ACCESSOR GET

string FrequencyAnalysisAlphabet :: getInputText() {
	return inputText_;
}

int FrequencyAnalysisAlphabet :: getNGroupLetters() {
	return nGroupLetters_;
}


// ACCESSOR SET

void FrequencyAnalysisAlphabet :: setInputText(string _newInputText) {
	inputText_ = _newInputText;
}

void FrequencyAnalysisAlphabet :: setNGroupLetters(int _newNGroupLetters) {
	nGroupLetters_ = _newNGroupLetters;
}


// METHOD

void FrequencyAnalysisAlphabet :: inputNGroupLetters() {

	try {		
		cout << "\nInput N-Graph : " << "\n> ";
		cin.clear();
		cin.ignore(100,'\n');
		cin >> nGroupLetters_;
		if (!cin >> nGroupLetters_) {
			throw "string input exception";
		}
	}
	catch (...) {
		cout << "\nError: Input must be a number. Try again.\n";
		inputNGroupLetters();
	}
}

string FrequencyAnalysisAlphabet :: filterAlphabets(string _value) {
	string output = "";
	for (int i=0; i!=_value.length(); i++) {
		if (isalpha(_value[i])) {
			output += toupper(_value[i]);
		}
	}
	
	while (output.length() % nGroupLetters_ != 0) {
		output += '?';
	}
	
	return output;
}

void FrequencyAnalysisAlphabet :: countFrequency() {
	int i = 0;
	int j = 0;
	int k = 0;
	string tempInput = filterAlphabets(inputText_);
	while (i < tempInput.length()) {
		if (i > 0) {
			storerIt_ = storer_.end();
			while (storerIt_ != storer_.begin() && ( (*storerIt_).getGroupLetters() != tempInput.substr(i,nGroupLetters_)) ) {
				storerIt_--;
			}
			if ( (*storerIt_).getGroupLetters() == tempInput.substr(i,nGroupLetters_)) {
				(*storerIt_).incAmount();
			} else {
				storerIt_ = storer_.end();
				storer_.insert(storerIt_,Storer(tempInput.substr(i,nGroupLetters_),1));
			}
			storerIt_ = storer_.end();
		} else {
			storer_.insert(storerIt_,Storer(tempInput.substr(i,nGroupLetters_),1));
		}
		i+=nGroupLetters_;
	}
}

void FrequencyAnalysisAlphabet :: displayInput() {
	cout << "\n" << inputText_;
}

void FrequencyAnalysisAlphabet :: displayOutput() {
	string tempInput = filterAlphabets(inputText_);
	cout.unsetf(ios::floatfield);
	cout.precision(2);
	for(storerIt_ = storer_.begin(); storerIt_ != storer_.end(); storerIt_++) {
		(*storerIt_).print();
		cout << " (" << calculatesPercentage((*storerIt_).getAmount(), tempInput) << "%)";
	}
}

void FrequencyAnalysisAlphabet :: inputFile() {
	ifstream input;	
	string fileString = "";
	string tempString = "";
	
	cout << "\nInput file name:" << "\n> ";
	cin >> fileString;		
	input.open(fileString.c_str());
	
	while (!input) {
		cout << "Error: File Not Found. Try again.\n";            
		cout << "\nInput file name: ";
		cin >> fileString;		
		input.open(fileString.c_str());
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

void FrequencyAnalysisAlphabet :: outputFile() {
	ofstream output;
	string tempInput = filterAlphabets(inputText_);
	
	output.open("output.txt");
	output.unsetf(ios::floatfield);
	output.precision(2);
	
	for(storerIt_ = storer_.begin(); storerIt_ != storer_.end(); storerIt_++) {
		output << (*storerIt_).getGroupLetters() << " => " << (*storerIt_).getAmount() << " (" << calculatesPercentage((*storerIt_).getAmount(), tempInput) << "%)"<< "\n";
	}	
	
	cout << "\n\n> Output has been saved into output.txt\n\n";
	
	output.close();
}

float FrequencyAnalysisAlphabet :: calculatesPercentage(int _groupLettersN, string _text) {
	return (float)_groupLettersN/((float)_text.length() / (float)nGroupLetters_) * 100.00f;
}


// DRIVER

void FrequencyAnalysisAlphabet :: driver() {
	inputFile();
	displayInput();
	cout << "\n";
	inputNGroupLetters();
	countFrequency();
	displayOutput();
	outputFile();
}