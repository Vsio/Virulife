// ===========================
// File : rangedRandomNumbersGenerator.js
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

function RangedRandomNumbersGenerator() {
	
	// METHOD
	
	this.generateRandom = function(_elmResult,_elmMin, _elmMax)
	/* generates random numbers in range */
	{
		var isNumber = /[0-9]/;
		var elmMin = parseInt(document.getElementById(_elmMin).value);		
		var elmMax = parseInt(document.getElementById(_elmMax).value);

		if ( (isNumber.test(elmMin) == true) && (isNumber.test(elmMax) == true) ) {
			if (elmMax > elmMin) {
				document.getElementById(_elmResult).value = elmMin+Math.round((elmMax-elmMin)*Math.random());
			} else {
				document.getElementById(_elmResult).value = "Maximum must higher than Minimum";
			}
		}  else {
			document.getElementById(_elmResult).value = "Only Number is Allowed";
		}
	}
	
	this.display = function(_varStr) 
	/* displays interface */
	{
		document.write("<div style=\"font-weight:bold;font-size:20px;\">Ranged Random Numbers Generator</div><br/>");
		document.write("<div name=\"randomNumber"+_varStr+"\" >");
		document.write("<form name=\"choice\" id=\"choice"+_varStr+"\" >");
		document.write("Minimum :<input id=\"min_"+_varStr+"\" type=\"text\" /> <br /> ");
		document.write("Maximum :<input id=\"max_"+_varStr+"\" type=\"text\" /> <br /><br />");
		document.write("Result: <input id=\"result_"+_varStr+"\" type=\"text\" style=\"width:300px\" readonly=\"readonly\" />");
		document.write("<input id=\"generate_"+_varStr+"\" type=\"button\" value=\"Generate Random Numbers\" onClick=\""+_varStr+".generateRandom('result_"+_varStr+"','min_"+_varStr+"','max_"+_varStr+"')\" />");
		document.write("</form>");
		document.write("</div>");	
	}

}