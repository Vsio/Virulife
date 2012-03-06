// ===========================
// File : spoiler.js
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

function Spoiler() {

	// FIELD
		
	this.stateHide_ = false; /* states whether content inside spoiler is hidden */
	this.content_ = ""; /* content inside spoiler */
	
	
	// METHOD
	
	this.showOrHideSpoiler = function(_idElmContent, _idElmButton)
	/* Hides content inside spoiler */
	{
		if (this.stateHide_ == false) {
			document.getElementById(_idElmContent).innerHTML = "";
			document.getElementById(_idElmButton).value = "Show Spoiler";	
			document.getElementById(_idElmContent).style.height = "5px";
			this.stateHide_ = true;
		} else {
			document.getElementById(_idElmContent).innerHTML = this.content_;
			document.getElementById(_idElmButton).value = "Hide Spoiler";
			document.getElementById(_idElmContent).style.height = "auto";
			this.stateHide_ = false;
		}
	}
	
	this.moves = function(_nameElmContent, _formElmContentInput) 
	/* moves content input from textarea into content area */
	{
		var preventHTML = /</g;
		
		if (this.stateHide_ == false) {
			document.getElementById(_nameElmContent).innerHTML = _formElmContentInput.value.replace(preventHTML,'&lt;');			
		}
		this.content_ = _formElmContentInput.value.replace(preventHTML,'&lt;');
	}
	
	this.display = function(_instanceVarStr) 
	/* displays interface */
	{
		document.write("<div name=\"spoiler"+_instanceVarStr+"\">")
		document.write("<form name=\"f_spoiler_"+_instanceVarStr+"\" >");
		document.write("Writes something below (Hint: You can use HTML tag too): <br /><textarea style=\"width:300px;\" name=\"ta_contentInput_"+_instanceVarStr+"\" onkeyup=\""+_instanceVarStr+".moves('content_"+_instanceVarStr+"',ta_contentInput_"+_instanceVarStr+");\" ></textarea>");
		document.write("</form><br />");
		document.write("<div id=\"content_"+_instanceVarStr+"\" style=\" width:300px; height:auto; border-color: #000000; border: solid; border-width:1px; word-wrap:break-word; \"></div>");
		document.write("<input id=\"i_doSpoiler_"+_instanceVarStr+"\" type=\"button\" value=\"Hide Content\" onclick=\""+_instanceVarStr+".showOrHideSpoiler('content_"+_instanceVarStr+"','i_doSpoiler_"+_instanceVarStr+"');\" /><br />");
		document.write("</div>");
	}

}