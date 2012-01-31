/* ===========================
File : caesarCipher_Alphabet.hpp

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in C++ programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#ifndef CAESAR_CIPHER_ALPHABET_H
#define CAESAR_CIPHER_ALPHABET_H

#include <string>

using namespace std;


// global method

void header();
/* Writes description and header of the program */

class CaesarCipherAlphabet {

	private:

	// FIELD

	string inputText_; /* input text */
	string outputText_; /* output text */
	int key_; /* key to encrypt/decrypt between plaintext and ciphertext */
	
	public:

	// CONSTRUCTOR
	
	CaesarCipherAlphabet();
	/* construct CaesarCipherAlphabet instance */
	
	
	// DESTRUCTOR
	
	~CaesarCipherAlphabet();
	/* destroy CaesarCipherAlphabet instance */
	
	
	// ACCESSOR GET
	
	string getInputText();
	/* returns inputText_ value */
	
	string getOutputText();
	/* returns outputText_ value */
	
	int getKey();
	/* return key_ value */
	
	
	// ACCESSOR SET
	
	void setInputText(string);
	/* changes inputText_ value */
	
	void setOutputText(string);
	/* changes outputText_ value */
	
	void setKey(int);
	/* changes key_ value */
	
	
	// METHOD
	
	void menu();
	/* displays command menu */
	
	void inputKey();
	/* inputs key_ for encryption / decryption */
	
	void encryptKey();
	/* encrypts inputText_ using key_ */
	
	void decryptKey();
	/* decrypts inputText_ using key_ */
	
	void decryptBruteForce();
	/* decrypts inputText_ using exhaustive key search */
	
	void inputDisplay();
	/* display input */
	
	void outputDisplay();
	/* display output */
	
	void inputFile();
	/* reads input from a file */

	void outputFileEncrypt();
	/* writes inputText output into a file (outputEncrypt.txt) */
	
	void outputFileDecrypt();
	/* writes inputText output into a file (outputDecrypt.txt) */
	
	void outputFileDecryptBrute();
	/* writes inputText output into a file (outputDecryptExhaustiveSearch.txt) */
	
	
	// DRIVER
	
	void driver();
	/* performs object functionally */
	
};

#endif // CAESAR_CIPHER_ALPHABET_H