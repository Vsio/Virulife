// ===========================
// File : factorial.js
//
// Credit:
// - Coded by (aka in cyber) Vsio Stitched
//
// Misc:
// - Written in Javascript programming language
//
// License:
// - Free to use
// - May include me or not in credit if included in other project
// ===========================

function Factorial() {
	
	// PREDICATE
	
	this.isDigit = function(_value) 
	/* checks whether the _value is all digits */
	{
		var patt_digitOnly = /[0-9]/;
		return patt_digitOnly.test(_value);
	}
	
	
	// METHOD
	
	this.doFactorial = function(_value) 
	/* does factorial calculation */
	{
		if (_value == 1) {
			return 1;
		} else {
			return (_value*this.doFactorial(_value-1) );
		}	
	}
	
	this.calculate = function(_formElmNumber, _formElmResult) 
	/* does factorial calculation, if input is not digits, returns error */
	{
		if (this.isDigit(_formElmNumber.value)==true) {
			_formElmResult.value = this.doFactorial(_formElmNumber.value);		
		} else {
			_formElmResult.value = "Error: Input is not full numbers!";
		}
	}
	
	this.display = function(_instanceVarStr) 
	/* displays interface */
	{
		document.write("<div name=\"factorial_"+_instanceVarStr+"\">")
		document.write("<form name=\"f_factorial_"+_instanceVarStr+"\" >");
		document.write("Input Number: <input name=\"t_number_"+_instanceVarStr+"\" type=\"text\" />");
		document.write("<input name=\"i_doFactorial_"+_instanceVarStr+"\" type=\"button\" value=\"Do Factorial\" onclick=\""+_instanceVarStr+".calculate(this.form.t_number_"+_instanceVarStr+",this.form.ta_result_"+_instanceVarStr+");\" /><br /><br />");
		document.write("Result: <br /><textarea name=\"ta_result_"+_instanceVarStr+"\"></textarea>");
		document.write("</form>");
		document.write("</div>");
	}

}