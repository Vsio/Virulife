/* ===========================
// File : stringReplacer.cs
// 
//  Credit:
//  - Coded by (aka in cyber) Vsio Stitched
// 
//  Misc:
//  - Written in C# programming language
// 
//  License:
//  - Free to use
//  - May include me or not in credit if included in other project
//  =========================== */


using System;
using System.IO;
using System.Collections;
using System.Text;

class StringReplacer {

	// FIELD

	private string inputText_; // text input whicih will be encrypted or decrypted
	private string replaceTarget_; // string which wants to be replaced
	private string replaceAfter_; // string which replaces the string target
	private string outputText_; // text output which is resulted from encryption or decryption

	
    // CONSTRUCTOR

    public StringReplacer()
    /* constructs StringReplacer instance */
    {
        this.inputText_ = "";
        this.replaceTarget_ = "";
        this.replaceAfter_ = "";
		this.outputText_ = "";
    }
	
	// ACCESSOR GET
	
	public string getInputText() 
	/* returns inputText_ value */
	{
		return this.inputText_;
	}
	
	public string getReplaceTarget() 
	/* returns replaceTarget_ value */
	{
		return this.replaceTarget_;
	}
	
	public string getReplaceAfter() 
	/* returns replaceAfter_ value */
	{
		return this.replaceAfter_;
	}
	
	public string getOutputText() 
	/* returns outputText_ value */
	{
		return this.outputText_;
	}

	
	// ACCESSOR SET
	
	public void setInputText(string _newInputText) 
	/* changes inputText_ value */
	{
		this.inputText_ = _newInputText;
	}
	
	public void setReplaceTarget(string _newReplaceTarget) 
	/* changes replaceTarget_ value */
	{
		this.replaceTarget_ = _newReplaceTarget;
	}
	
	public void setReplaceAfter(string _newReplaceAfter) 
	/* changes replaceAfter_ value */
	{
		this.replaceAfter_ = _newReplaceAfter;
	}
	
	public void setOutputText(string _newOutputText) 
	/* changes outputText_ value */
	{
		this.outputText_ = _newOutputText;
	}
	
	
    // PREDICATE

	
    // METHOD
	
	public string promptGetStringTarget()
	// prompt to get replaceTarget_ value
	{
	
		Console.WriteLine("> Input string which want to be replaced ");
		this.replaceTarget_ = Console.ReadLine();
		
		return this.replaceTarget_;
	}
	
	public string promptGetStringAfter() {
	// prompt to get replaceAfter_
	
		Console.WriteLine("> Input string which replaces the target string");
		this.replaceAfter_ = Console.ReadLine();
		
		return this.replaceAfter_;
	}
	
	public string doStringReplace() {
	// replaces string
	
		this.outputText_ = this.inputText_.Replace(this.replaceTarget_,this.replaceAfter_);	
		Console.Write(this.outputText_);
		
		return this.outputText_;
	}
	
	public bool loadFile()
	// loads input from a file
	{
		string fileString = "";
		UTF8Encoding utf8 = new UTF8Encoding();
	
		try {
			Console.Write("> Input File: ");
			fileString = Console.ReadLine();
			byte[] bytes = File.ReadAllBytes(fileString);			
			this.inputText_ = utf8.GetString(bytes);
			Console.WriteLine(this.inputText_+"\n");
			
			return true;
		} catch (Exception) {
			Console.WriteLine("> File not found. Try again.");
			loadFile();
			return false;
		}
	}
	
	public bool saveFile()
	// saves output a file
	{	
		try {
			File.WriteAllText("output.txt", this.outputText_);	
			Console.WriteLine("\n\n> New string has been saved into output.txt");
			
			return true;
		} catch (Exception) {
			Console.WriteLine("> File not found.");
			
			return false;
		}
	}	
	
	
	// DRIVER
	
	public void driver()
    /* simulates instance functionality */
    {
		loadFile();
		promptGetStringTarget();
		promptGetStringAfter();
		Console.WriteLine("> Output: ");
		doStringReplace();
		saveFile();
    }
		
	public static void Main(String[] args)
	/* executes class program */
	{
		StringReplacer sr = new StringReplacer();
		Console.Write("\n===== String Replacer =====\n");
		Console.Write("\n\n== START PROGRAM ==\n\n");
		sr.driver();
		Console.Write("\n\n== END PROGRAM ==\n\n");
		Console.ReadLine();		
	}
	
}
