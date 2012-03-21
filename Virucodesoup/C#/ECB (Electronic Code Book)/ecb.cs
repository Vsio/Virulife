/* ===========================
File : ecb.cs

Credit:
- Coded by (aka in cyber) Vsio Stitched
- Problem case inspired from my past in high school

Misc:
- Written in C# programming laguage

License:
- Free to use
- May include me or not in credit if included in other project
=========================== */

using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;


class ECB {

    // FIELD

    private String inputText_; /* text input whicih will be encrypted or decrypted */
    private String key_; /* binary input */
    private String outputText_; /* text output which is resulted from encryption or decryption */


    // CONSTRUCTOR

    public ECB()
    /* constructs ECB instance */
    {
        this.inputText_ = "";
        this.key_ = "";
        this.outputText_ = "";
    }

    public ECB(String _newInputText, String _newKey, String _newOutputText)
    /* constructs ECB instance */
    {
        this.inputText_ = _newInputText;
        this.key_ = _newKey;
        this.outputText_ = _newOutputText;
    }


    // ACCESSOR GET

    public String getInputText()
    /* gets inputText_ value */
    {
        return this.inputText_;
    }

    public String getKey()
    /* returns key_ value */
    {
        return this.key_;
    }

    public String getOutputText()
    /* returns outputText_ value */
    {
        return this.outputText_;
    }


    // ACCESSOR SET

    public void setInputText(String _newInputText)
    /* changes inputText_ value */
    {
        this.inputText_ = _newInputText;
    }

    public void setKey(String _newKey)
    /* changes key_ value */
    {
        this.key_ = _newKey;
    }

    public void setOutputText(String _newOutputText)
    /* changes outputText_ value */
    {
        this.outputText_ = _newOutputText;
    }


    // PREDICATE

	
    // METHOD

    public void menu()
    /* displays command menu */
    {
		String index = "0";
                
        while (index[0] != '3') {
            System.Console.WriteLine("\n\n==> MENU\n\n");
            System.Console.WriteLine("1. Encrypt");
            System.Console.WriteLine("2. Decrypt");
            System.Console.WriteLine("3. Exit");
            System.Console.Write("\nSelect a number : ");
            index = Console.ReadLine();
            System.Console.WriteLine();
            switch(index[0]) {
                case '1': {
                    loadFile();
                    inputKey();
                    encipher();
                    saveFile(0);
					goto case '3';
				}
                case '2': {
                    loadFile();
                    inputKey();
                    decipher();
                    saveFile(1);
					goto case '3';
                }
                case '3': {
                    index = "3";
					break;
                }
                default:{
                    System.Console.WriteLine("> Invalid Input");
                    index = "0";
					break;
                }

            }
        }
    }
	
	public void inputKey()
	/* input key_ value */
	{
		String value = " ";
		Regex regexConstraint = new Regex("^[0-1]+$");
		
		while (!regexConstraint.IsMatch(value)) {
			System.Console.Write("\nInput binary string: ");
			value = Console.ReadLine();
			if (!regexConstraint.IsMatch(value)) {
				System.Console.WriteLine("> Error: Only 0 or 1 is allowed");				
			}
		}
		
		this.key_ = value;
	}
	
	public String encryptionBlock(String _plainText)
	/* encryption blocks (in this example, a simple xor encryption is used) (You can define your own Encryption Block here) */
	{
		String plainText = _plainText;
		String output = "";
		String key = this.key_;
		
		for (int i=0;i!=key.Length;i++) {
			output += xorBit(plainText[i],key[i]);
		}
		
		return output;
	}

	public String decryptionBlock(String _cipherText)
	/* decryption blocks (in this example, a simple xor decryption is used) (You can define your own Decryption Block here) */
	{
		String cipherText = _cipherText;
		String output = "";
		String key = this.key_;
		
		for (int i=0;i!=key.Length;i++) {
			output += xorBit(cipherText[i],key[i]);
		}
		
		return output;
	}
	
	public string stringToBinary(string _string) 
	/* converts string into binary */
	{
		string input = _string;
		string reversedStr = "";
		UnicodeEncoding Unicode = new UnicodeEncoding();
		
		for (int i=input.Length-1;i!=-1;i-=1) {
			reversedStr += input[i];
		}
		
		byte[] stringBytes = Unicode.GetBytes(input);
		BitArray bits = new BitArray(stringBytes);
		string output = "";
		
		for (int i=0;i!=bits.Length;i+=1) {
			output += (bits[i] ? '1' : '0');
		}

		return output;
	}
	
	public char binaryToChar(string _binaryString) 
	/* converts binary to char */
	{
		string binary = _binaryString;
		int i = 0;
		int measure = 0;
		int total = 0;
		
		for (i=0;i!=binary.Length;i++) {
			if (binary[binary.Length-1-i]=='0') {
				measure = 0;
			} else if (binary[binary.Length-1-i]=='1') {
				measure = 1;
			}
			total += ((int)Math.Pow(2*measure,binary.Length-1-i)*measure);
		}
		
		return (char)total;
	}
	
	public string binaryToString(string _binaryString)
	/* converts binary to string */
	{
		string binaries = _binaryString;
		string output = "";
		int i = 0;
		while (i!=binaries.Length) {			
			output += binaryToChar(binaries.Substring(i,16));
			i+=16;
		}
		
		return output;
	}
	
	public char xorBit(char _bit1,char _bit2) 
	/* does xor operator with bits in char types */
	{
		return ((_bit1==_bit2) ? '0':'1') ;
	}
	
	public void encipher()
	/* enciphers with ECB method */
	{	
		string inputBit = stringToBinary(this.inputText_);
		int inputBitLength = inputBit.Length;
		String key = this.key_;
		int blockLength = key.Length;
		String blockTemp = "";
		String output = "";
		String outputText = "";
		int i = 0;
		int j = 0;

		while (inputBit.Length % blockLength != 0) {
			inputBit += '0';
		}

		while (i != inputBit.Length) {
			
			for (j=0;j!=blockLength;j++) {
				blockTemp += inputBit[j+i];
			}
			
			output += encryptionBlock(blockTemp);
			blockTemp = "";
			j = 0;
			i += blockLength;
		}

		outputText = binaryToString(output.Substring(0,inputBitLength));

		i = 0;
		
		this.outputText_ = outputText;
		
		System.Console.WriteLine("\n>Encryption Result:");
		System.Console.WriteLine(outputText);
	}
	
	public void decipher()
	/* deciphers with ECB method */
	{
		string inputBit = stringToBinary(this.inputText_);
		int inputBitLength = inputBit.Length;
		String key = this.key_;
		int blockLength = key.Length;
		String blockTemp = "";
		String output = "";
		String outputText = "";
		int i = 0;
		int j = 0;
		
		while (inputBit.Length % blockLength != 0) {
			inputBit += '0';
		}
		
		while (i != inputBit.Length) {
			
			for (j=0;j!=blockLength;j++) {
				blockTemp += inputBit[j+i];
			}
			
			output += decryptionBlock(blockTemp);
			blockTemp = "";
			j = 0;
			i += blockLength;
		}

		outputText = binaryToString(output.Substring(0,inputBitLength));
		
		i = 0;
		
		this.outputText_ = outputText;
		System.Console.WriteLine("\n>Decryption Result:");
		System.Console.WriteLine(outputText);
	}
	
	public void loadFile()
	/* loads input from a file */
	{
		System.IO.StreamReader file;
		String fileString = "";
		
		try {			
			System.Console.Write("\nInput file name: ");
			fileString = Console.ReadLine();
			System.Console.WriteLine();
			file = new System.IO.StreamReader(fileString);	
			this.inputText_ = file.ReadToEnd();
			System.Console.WriteLine(this.inputText_);
			file.Close();
		} catch (Exception) {
			System.Console.WriteLine("> File not found. Try again.");
			loadFile();
		}
	}
	
	public void saveFile(int _index)
	/* saves output a file */
	{	
		if (_index == 0) {
			try {
				StreamWriter file = new System.IO.StreamWriter("output_encipher.txt");
				
				file.Write(this.outputText_);
				System.Console.WriteLine("\n> ECB enciphering result has been saved into output_encipher.txt");
				file.Close();
			} catch (Exception) {
				System.Console.WriteLine("> File not found.");
			}
		} else if (_index == 1) {
			try {
				StreamWriter file = new System.IO.StreamWriter("output_decipher.txt");
				
				file.Write(this.outputText_);
				System.Console.WriteLine("\n> ECB deciphering result has been saved into output_decipher.txt");
				file.Close();
			} catch (Exception) {
				System.Console.WriteLine("> File not found.");
			}
		}
	}
	
	
    // DRIVER

    public void driver()
    /* simulates instance functionality */
    {
		menu();
    }

    public static void Main(String[] args)
    /* executes class program */
    {
		
        ECB ecb = new ECB();
        
		System.Console.Write("\n===== ECB (Electronic Code Book) =====\n");
		System.Console.Write("\n\n== START PROGRAM ==\n\n");
		ecb.driver();
		System.Console.Write("\n\n== END PROGRAM ==\n\n");
		Console.ReadLine();
    }
	
}