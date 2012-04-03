/* ===========================
File : vigenereCipher_ASCII.hpp

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in C++ programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

#ifndef VIGENERE_CIPHER_ASCII_H
#define VIGENERE_CIPHER_ASCII_H

#include <string>

using namespace std;

// global method

void header();
/* Writes description and header of the program */

class VigenereCipherASCII {

	private:

	// FIELD

	string inputText_; /* input text */
	string outputText_; /* output text */
	string key_; /* key to encrypt/decrypt between plaintext and ciphertext */

	public:
	
	// CONSTRUCTOR
	
	VigenereCipherASCII();
	/* construct VigenereCipherASCII instance */
	
	
	// DESTRUCTOR
	
	~VigenereCipherASCII();
	/* destroy VigenereCipherASCII instance */
	
	
	// ACCESSOR GET
	
	string getInputText();
	/* returns inputText_ value */
	
	string getOutputText();
	/* returns outputText_ value */
	
	string getKey();
	/* return key_ value */
	
	
	// ACCESSOR SET
	
	void setInputText(string);
	/* changes inputText_ value */
	
	void setOutputText(string);
	/* changes outputText_ value */
	
	void setKey(string);
	/* changes key_ value */
	
	
	// METHOD
	
	void menu();
	/* displays command menu */
		
	void inputKey();
	/* inputs key for encryption / decryption */
	
	string getRepeatKey();
	/* returns repeated key with length equals plaintext's length */
	
	void encryptKey();
	/* encrypts plaintext using key_ */
	
	void encryptAutoKey();
	/* encrypts plaintext using key_ with Auto-Key mode */
	
	void decryptKey();
	/* decrypts ciphertext using key_ */
	
	void decryptAutoKey();
	/* decrypts ciphertext using key_ with Auto-Key mode */
	
	void inputDisplay();
	/* display input */
	
	void outputDisplay();
	/* display output */
	
	void inputFile();
	/* reads input from a file */
	
	void outputFileEncrypt();
	/* writes ciphertext output into a file (outputEncrypt.txt) */

	void outputFileEncryptAutoKey(); 
	/* writes ciphertext (with auto-key) output into a file (outputEncryptAutoKey.txt) */
	
	void outputFileDecrypt();
	/* writes plaintext output into a file (outputDecrypt.txt) */
	
	void outputFileDecryptAutoKey();
	/* writes plaintext (with auto-key) output into a file (outputDecryptAutoKey.txt) */
	
	
	// DRIVER
	
	void driver();
	/* performs object functionally */
	
};

#endif // VIGENERE_CIPHER_ASCII_H