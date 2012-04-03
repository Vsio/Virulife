/* ===========================
File : VigenereCipherAlphabet.java

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in Java programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

package packVigenereCipherAlphabet;

import java.io.*;
import java.util.*;

public class VigenereCipherAlphabet {
	
	// FIELD
	
	private String inputText_; /* input text */
	private String outputText_; /* output text */
	private String key_; /* key to encrypt/decrypt between plaintext and ciphertext */
	
	
	// CONSTRUCTOR
	
	public VigenereCipherAlphabet()
	/* construct VigenereCipherAlphabet instance */
	{
		this.inputText_ = "";
		this.outputText_ = "";
		this.key_ = "";
	}
	
	
	// ACCESSOR GET
	
	public String getInputText() 
	/* returns inputText_ value */
	{
		return this.inputText_;
	}
	
	public String getOutputText()
	/* returns outputText_ value */
	{
		return this.outputText_;
	}
	
	public String getKey()
	/* return key_ value */
	{
		return this.key_;
	}
	
	
	// ACCESSOR SET
	
	public void setInputText(String _newInputtext)
	/* changes inputText_ value */
	{
		this.inputText_ = _newInputtext;
	}
	
	public void setOutputText(String _newOutputText)
	/* changes outputText_ value */
	{
		this.outputText_ = _newOutputText;
	}
	
	public void setKey(String _newKey)
	/* changes key_ value */
	{
		this.key_ = _newKey;
	}
	
	
	// PREDICATE
	
	public boolean isKeyValid()
	/* returns whether key_ input is valid */
	{
		int i = 0;
		boolean output = true;
		
		if (this.key_.length() == 0) {
			output = false;
		}
		
		while ( (i != this.key_.length()) && (output == true) ) {
			if ( !(Character.isLetter(this.key_.charAt(i))) ) {
				output = false;
			}
			i++;
		}
		return output;
	}
	
	
	// METHOD
	
	public void menu() throws Exception
	/* displays command menu */
	{	
		Scanner myScanner = new Scanner(System.in);
		String index = "";		
		
		while (index != "5") {
			System.out.print("\n\n==> MENU\n\n");
			System.out.print("1. Encrypt\n");
			System.out.print("2. Encrypt with Auto-Key\n");
			System.out.print("3. Decrypt with Key\n");
			System.out.print("4. Decrypt with Auto-Key\n");
			System.out.print("5. Exit \n");
			System.out.print("\n> Select a number : ");
			index = myScanner.next();
			if (index.length() == 1) {
				switch((int)index.charAt(0)) {
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
					
					case ((int)'5'): {
						index = "5";				
					} break;
					
					default: {	
						System.out.print("Invalid Input \n \n");
						index = "0";
					}
				}
			} else {
				System.out.print("Invalid Input \n \n");
				index = "0";
			}
		}
	}
		
	public void inputKey()
	/* inputs key for encryption / decryption */
	{
		boolean keyValid = false;
		Scanner myScanner = new Scanner(System.in);
		
		while (keyValid == false) {
			System.out.print("Input Key : ");
			this.key_ = myScanner.nextLine();
			keyValid = isKeyValid();
			if (keyValid == false) {
				System.out.print("\n> Only alphabet is allowed or key cannot be empty. Try again.\n");			
			}
		}
	}
	
	public String getRepeatKey()
	/* returns repeated key with length equals plaintext's length */
	{
		String output = "";
		int i = 0;
		
		while (output.length() != this.inputText_.length()) {		
			output += Character.toUpperCase(this.key_.charAt(i));
			i++;
			if (i == (this.key_).length()) {
				i = 0;
			}
		}
		System.out.print("Key becomes : " + output + "\n");
		return output;
	}
	
	public String getAllUpperCase(String _value)
	/* returns String with all upper-case */
	{
		String output = "";
		int i = 0;
		
		while (output.length() != _value.length()) {		
			if ( Character.isLetter(_value.charAt(i)) ) {
				output += Character.toUpperCase(_value.charAt(i));			
			} else {
				output += _value.charAt(i);
			}
			i++;
		}
		
		return output;
	}
	
	public void encryptKey()
	/* encrypts plaintext using key_ */
	{
		String keyRepeated = getRepeatKey();
		String tempInput = getAllUpperCase(this.inputText_);
		
		for (int i=0; i<tempInput.length(); i++) {
			if ( Character.isLetter(tempInput.charAt(i)) ) {
				this.outputText_ += (char)((tempInput.charAt(i)- (int)'A'+keyRepeated.charAt(i) - (int)'A')%26 + (int)'A');
			} else {
				this.outputText_ += tempInput.charAt(i);
			}
		}
	}
	
	public void encryptAutoKey()
	/* encrypts plaintext using key_ with Auto-Key mode */
	{
		String keyAuto = "";	
		String tempInput = getAllUpperCase(this.inputText_);
		int i = 0;
		int sub = 0;
		
		while (keyAuto.length() != (this.inputText_).length()) {		
			if ( (!Character.isLetter(inputText_.charAt(i))) && (keyAuto.length() != (this.inputText_).length()) ) {
				keyAuto += " ";	
			} else {
				if (keyAuto.length() >= (this.key_).length()) {					
					if ( (Character.isLetter(inputText_.charAt(sub))) ) {
						if ( Character.isLetter(inputText_.charAt(sub)) ) {
							keyAuto += Character.toUpperCase(inputText_.charAt(sub));
						} 
					}
					sub++;
					while ( !Character.isLetter(this.inputText_.charAt(sub)) ) {
						sub++;					
					}
				} else {
					keyAuto += Character.toUpperCase(this.key_.charAt(i));
				}		
			}
			i++;
		}
		
		for (i=0; i<tempInput.length(); i++) {
			if ( Character.isLetter((tempInput.charAt(i))) ) {
				this.outputText_ += (char)((tempInput.charAt(i)- (int)'A'+keyAuto.charAt(i) - (int)'A')%26 + (int)'A');
			} else {
				this.outputText_ += tempInput.charAt(i);
			}
		}
	}
	
	public void decryptKey()
	/* decrypts ciphertext using key_ */
	{	
		String keyRepeated = getRepeatKey();
		String tempInput = getAllUpperCase(this.inputText_);
		char tempOutput = ' ';

		for (int i=0; i<tempInput.length(); i++) {
			if ( Character.isLetter(tempInput.charAt(i)) ) {
				tempOutput = (char)( (tempInput.charAt(i)- (int)'A'-keyRepeated.charAt(i) - (int)'A')%26 + (int)'A');
				if ( !(Character.isLetter(tempOutput)) ) {
					tempOutput = (char)((int)tempOutput+26);
				}
			} else {
				tempOutput = tempInput.charAt(i);
			}
			this.outputText_ += tempOutput;
			tempOutput = ' ';
		}	
		
	}
	
	public void decryptAutoKey() throws Exception
	/* decrypts ciphertext using key_ with Auto-Key mode */
	{
		try {
			String keyAuto;
			String tempInput = getAllUpperCase(this.inputText_);
			this.key_ = getAllUpperCase(this.key_);
			int keyInitLength = this.key_.length();
			int i = 0;
			int notAlpha = 0;
			char tempOutput = ' ';
			
			while ( this.outputText_.length() != tempInput.length() ) {
				if ( !Character.isLetter(tempInput.charAt(i)) ) {			
					this.outputText_ += tempInput.charAt(i);
					notAlpha -= 1;
				} else {
					tempOutput = (char)((tempInput.charAt(i)- (int)'A'-this.key_.charAt(i) - (int)'A')%26 + (int)'A');
					if ( !Character.isLetter(tempOutput) ) {
						tempOutput = (char)((int)tempOutput+26);
					}
					this.outputText_ += tempOutput;
					
					if ( ( this.key_.length() != tempInput.length() ) && (i+keyInitLength+notAlpha < tempInput.length()-1) ) {
						while ( (!Character.isLetter(tempInput.charAt(i+keyInitLength+notAlpha)) ) && (this.key_.length() != tempInput.length()) ) {
							this.key_ += " "; 			
							notAlpha += 1;
						}
						
						if ( Character.isLetter(tempInput.charAt(i+keyInitLength+notAlpha)) ) {
							this.key_ += tempOutput;
						}
					
					}
					
					tempOutput = ' ';		
				}	
				i++;
			}
		} catch (Exception e) {
			decryptAutoKey();
		}
	}
		
	public void inputDisplay()
	/* display input */
	{
		System.out.print("\n\n==> DISPLAY INPUT\n\n");
		System.out.print(this.inputText_);
		System.out.print("\n\n");
	}
	
	public void outputDisplay()
	/* display output */
	{
		System.out.print("\n\n==> DISPLAY OUTPUT\n\n");
		System.out.print(this.outputText_);
		System.out.print("\n\n");
	}
	
	public void inputFile() throws Exception
	/* reads input from a file */
	{
		try {
			BufferedReader input;
			FileReader inputFile;
			Scanner myScanner = new Scanner(System.in);
			String fileString = "";
			String line;
			
			System.out.print("\nInput file name: ");
			fileString = myScanner.nextLine();;		
			inputFile = new FileReader(fileString);
			input = new BufferedReader(inputFile);
			
			line = input.readLine();
			
			int i = 0;
			while (line != null) {
				this.inputText_ += line;
				this.inputText_ += "\r\n";
				line = input.readLine();
			}
			
			this.inputText_ = this.inputText_.substring(0,this.inputText_.length()-2);
			
			input.close();
		} catch (Exception e) {
			String pause;
			Scanner myScanner = new Scanner(System.in);
			
			System.out.print("Can't open the file. \n");
			System.out.print("\n\n==> END OF PROGRAM\n\n");	
			pause = myScanner.nextLine();
			System.exit(1);
		}
	}
	
	public void outputFileEncrypt() throws Exception
	/* writes ciphertext output into a file (outputEncrypt.txt) */
	{
		FileWriter outputFile = new FileWriter("outputEncrypt.txt");
		BufferedWriter output = new BufferedWriter(outputFile);

		output.write(this.outputText_);
		System.out.print("> Output has been saved into outputEncrypt.txt\n");
		output.close();
	}

	public void outputFileEncryptAutoKey() throws Exception
	/* writes ciphertext (with auto-key) output into a file (outputEncryptAutoKey.txt) */
	{
		FileWriter outputFile = new FileWriter("outputEncryptAutoKey.txt");
		BufferedWriter output = new BufferedWriter(outputFile);
		
		output.write(this.outputText_);
		System.out.print("> Output has been saved into outputEncryptAutoKey.txt\n");
		output.close();
	}
	
	public void outputFileDecrypt() throws Exception
	/* writes plaintext output into a file (outputDecrypt.txt) */
	{
		FileWriter outputFile = new FileWriter("outputDecrypt.txt");
		BufferedWriter output = new BufferedWriter(outputFile);
		
		output.write(this.outputText_);	
		System.out.print("> Output has been saved into outputDecrypt.txt\n");
		output.close();
	}
	
	public void outputFileDecryptAutoKey() throws Exception
	/* writes plaintext (with auto-key) output into a file (outputDecryptAutoKey.txt) */
	{
		FileWriter outputFile = new FileWriter("outputDecryptAutoKey.txt");
		BufferedWriter output = new BufferedWriter(outputFile);
		
		output.write(this.outputText_);		
		System.out.print("> Output has been saved into outputDecryptAutoKey.txt\n");
		output.close();
	}
	
	
	// DRIVER
	
	public void driver() throws Exception
	/* performs object functionally */
	{
		System.out.print("\n\n==> START PROGRAM\n\n");
		menu();
		System.out.print("\n\n==> END OF PROGRAM\n\n");	
	}
	
	
}