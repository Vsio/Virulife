// ===========================
// File : formChangeWithRadioChoice.js
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

function ContentBasedRadioChoice() {
	
	// METHOD
	
	this.contentChoice = function(_formFood,_elmContent)
	/* shows content of what the user chose */
	{
		var content;
		if (_formFood.value == "pizza") {
			content = "Pizza, I haven't eaten a pizza in a year. I want eat some.";
		} else if (_formFood.value == "burger") {
			content = "There is someone selling burger near my place. But I need to decided when to buy it.";
		} else if (_formFood.value == "chicken steak") {
			content = "I have just eaten several chicken steaks in several days ago. Sometimes I mistakenly eat the fish steak which looks like chicken steak.";
		}

		document.getElementById(_elmContent).innerHTML = content;
		
	}
	
	this.display = function(_varStr) 
	/* displays interface */
	{
		document.write("<div name=\"contentChoice_"+_varStr+"\" >");
		document.write("<form name=\"choice\" id=\"choice"+_varStr+"\" >");
		document.write("Choice one of these below: <br />");
		document.write("<input name=\"food\" id=\"food1_"+_varStr+"\" type=\"radio\" value=\"pizza\" onClick=\""+_varStr+".contentChoice(this.form[0],'content_"+_varStr+"');\" /> Pizza");
		document.write("<input name=\"food\" id=\"food2_"+_varStr+"\" type=\"radio\" value=\"burger\" onClick=\""+_varStr+".contentChoice(this.form[1],'content_"+_varStr+"');\" /> Burger");
		document.write("<input name=\"food\" id=\"food3_"+_varStr+"\" type=\"radio\" value=\"chicken steak\" onClick=\""+_varStr+".contentChoice(this.form[2],'content_"+_varStr+"');\" /> Chicken Steak");
		document.write("</form>");
		document.write("</div>");
		document.write("<br /><div id=\"content_"+_varStr+"\" style=\"width:300px\" ></div>");
	}

}