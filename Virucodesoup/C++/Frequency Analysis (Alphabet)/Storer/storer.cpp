/* ===========================
File : storer.cpp

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in C++ programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#include "storer.hpp"

using namespace std;

// CONSTRUCTOR

Storer :: Storer() {
	groupLetters_ = "";
	amount_ = 0;
}

Storer :: Storer(string _newGroupLetters, int _newAmount) {
	groupLetters_ = _newGroupLetters;
	amount_ = _newAmount;
}

// DESTRUCTOR

Storer :: ~Storer() {

}


// ACCESSOR GET

string Storer :: getGroupLetters() {
	return groupLetters_;
}

int Storer :: getAmount() {
	return amount_;
}


// ACCESSOR SET

void Storer :: setGroupLetters(string _newGroupLetters) {
	groupLetters_ = _newGroupLetters;
}

void Storer :: setAmount(int _newAmount) {
	amount_ = _newAmount;
}


// PREDICATE

bool Storer :: isSameGroup(Storer _otherStorer) {
	return (groupLetters_ == _otherStorer.groupLetters_);
}


// METHOD

void Storer :: print() {
	cout << "\n" << groupLetters_ << " => " << amount_;
}

void Storer :: incAmount() {
	amount_++;
}


// DRIVER

void Storer :: driver() {
	print();
}