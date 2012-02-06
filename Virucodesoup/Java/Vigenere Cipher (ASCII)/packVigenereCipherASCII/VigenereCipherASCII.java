/* ===========================
File : VigenereCipherASCII.java

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in Java programming language

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

package packVigenereCipherASCII;

import java.io.*;
import java.util.*;

public class VigenereCipherASCII {
	
	// FIELD
	
	private String inputText_; /* input text */
	private String outputText_; /* output text */
	private String key_; /* key to encrypt/decrypt between plaintext and ciphertext */
	
	
	// CONSTRUCTOR
	
	public VigenereCipherASCII()
	/* constructs VigenereCipherASCII instance */
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
	/* returns key_ value */
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
	
	
	// METHOD
	
	public char convertAnsiToUnicode(int _value) 
	/* converts certain extended ANSI index into Unicode index */
	{
		char output;
		switch(_value) {
			case 128 : {output = (char)8364;} break;
			case 130 : {output = (char)8218;} break;
			case 131 : {output = (char)402;} break;
			case 132 : {output = (char)8222;} break;		
			case 133 : {output = (char)8230;} break;
			case 134 : {output = (char)8224;} break;
			case 135 : {output = (char)8225;} break;
			case 136 : {output = (char)710;} break;
			case 137 : {output = (char)8240;} break;
			case 138 : {output = (char)352;} break;
			case 139 : {output = (char)8249;} break;
			case 140 : {output = (char)338;} break;
			case 142 : {output = (char)381;} break;
			case 145 : {output = (char)8216;} break;
			case 146 : {output = (char)8217;} break;
			case 147 : {output = (char)8220;} break;
			case 148 : {output = (char)8221;} break;
			case 149 : {output = (char)8226;} break;
			case 150 : {output = (char)8211;} break;		
			case 151 : {output = (char)8212;} break;
			case 152 : {output = (char)732;} break;
			case 153 : {output = (char)8482;} break;
			case 154 : {output = (char)353;} break;
			case 155 : {output = (char)8250;} break;
			case 156 : {output = (char)339;} break;
			case 158 : {output = (char)382;} break;
			case 159 : {output = (char)376;} break;
			default : {output = (char)_value;}
		}
		return output;
	}
	
	public char convertUnicodeToANSI(int _value) 
	/* converts certain extended Unicode index into ANSI index*/
	{
		char output;
		switch(_value) {
			case 8364 : {output = (char)128;} break;
			case 8218 : {output = (char)130;} break;
			case 402 : {output = (char)131;} break;
			case 8222 : {output = (char)132;} break;		
			case 8230 : {output = (char)133;} break;
			case 8224 : {output = (char)134;} break;
			case 8225 : {output = (char)135;} break;
			case 710 : {output = (char)136;} break;
			case 8240 : {output = (char)137;} break;
			case 352 : {output = (char)138;} break;
			case 8249 : {output = (char)139;} break;
			case 338 : {output = (char)140;} break;
			case 381 : {output = (char)142;} break;
			case 8216 : {output = (char)145;} break;
			case 8217 : {output = (char)146;} break;
			case 8220 : {output = (char)147;} break;
			case 8221 : {output = (char)148;} break;
			case 8226 : {output = (char)149;} break;
			case 8211 : {output = (char)150;} break;		
			case 8212 : {output = (char)151;} break;
			case 732 : {output = (char)152;} break;
			case 8482 : {output = (char)153;} break;
			case 353 : {output = (char)154;} break;
			case 8250 : {output = (char)155;} break;
			case 339 : {output = (char)156;} break;
			case 382 : {output = (char)158;} break;
			case 376 : {output = (char)159;} break;
			default : {output = (char)_value;}
		}
		return output;
	}
	
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
		Scanner myScanner = new Scanner(System.in);
		
		System.out.print("Input Key : ");
		this.key_ = myScanner.nextLine();
	}
	
	public String getRepeatKey()
	/* returns repeated key with length equals plaintext's length */
	{
		String output = "";
		int i = 0;
		
		while (output.length() != this.inputText_.length()) {		
			output += this.key_.charAt(i);
			i++;
			if (i == this.key_.length()) {
				i = 0;
			}
		}
		System.out.print("Key becomes : " + output + "\n");
		return output;
	}

	
	public void encryptKey()
	/* encrypts plaintext using key_ */
	{
		char tempOutput = ' ';
		String keyRepeated = getRepeatKey();
		
		for (int i=0; i<this.inputText_.length(); i++) {
			tempOutput = convertAnsiToUnicode((((int)inputText_.charAt(i)+(int)keyRepeated.charAt(i))%256));
						
			outputText_ += tempOutput;
			tempOutput = ' ';
		}
	}
	
	public void encryptAutoKey()
	/* encrypts plaintext using key_ with Auto-Key mode */
	{
		char tempOutput = ' ';
		int i = 0;
		String keyAuto = this.key_;
		
		while (keyAuto.length() != this.inputText_.length()) {		
			keyAuto += inputText_.charAt(i);
			i++;
		}
		
		for (i=0; i<inputText_.length(); i++) {
			tempOutput = convertAnsiToUnicode( ((int)inputText_.charAt(i)+(int)keyAuto.charAt(i))%256 );			
			outputText_ += tempOutput;
			tempOutput = ' ';
		}
	}
	
	public void decryptKey()
	/* decrypts ciphertext using key_ */
	{	
		char tempOutput = ' ';
		String keyRepeated = getRepeatKey();
		String tempInput = this.inputText_;
		
		for (int i=0; i<tempInput.length(); i++) {
			if (convertUnicodeToANSI((int)tempInput.charAt(i))-(int)convertUnicodeToANSI(keyRepeated.charAt(i)) >= 0) {
				tempOutput = convertAnsiToUnicode((int)convertUnicodeToANSI((int)tempInput.charAt(i))-(int)convertUnicodeToANSI((int)keyRepeated.charAt(i)));
			} else {
				tempOutput = convertAnsiToUnicode(convertUnicodeToANSI((int)tempInput.charAt(i))-convertUnicodeToANSI((int)keyRepeated.charAt(i)) +256);
			}
								
			if ((int)tempOutput < 0) {
				tempOutput = (char)((int)tempOutput+256);
			}

			this.outputText_ += tempOutput;
			tempOutput = ' ';
		}	
		
	}
	
	public void decryptAutoKey() throws Exception
	/* decrypts ciphertext using key_ with Auto-Key mode */
	{
		try {
			char tempOutput = ' ';
			int i = 0;
			String keyAuto = this.key_;

			while (outputText_.length() != inputText_.length()) {
				if ((int)convertUnicodeToANSI((int)this.inputText_.charAt(i))-(int)convertUnicodeToANSI((int)keyAuto.charAt(i)) >= 0) {
					tempOutput = convertAnsiToUnicode( ((int)convertUnicodeToANSI((int)this.inputText_.charAt(i))-(int)convertUnicodeToANSI((int)keyAuto.charAt(i)) )%256);
				} else {
					tempOutput = convertAnsiToUnicode((int)convertUnicodeToANSI((int)this.inputText_.charAt(i))-(int)convertUnicodeToANSI((int)keyAuto.charAt(i)) +256 );
				}
			
				outputText_ += tempOutput;
				keyAuto += tempOutput;
				tempOutput = ' ';		
				i++;
			}
		} catch (Exception e) {
			decryptAutoKey();
		}
	}
		
	public void inputDisplay()
	/* displays input */
	{
		System.out.print("\n\n==> DISPLAY INPUT\n\n");
		System.out.print(this.inputText_);
		System.out.print("\n\n");
	}
	
	public void outputDisplay()
	/* displays output */
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