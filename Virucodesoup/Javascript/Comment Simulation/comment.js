// ===========================
// File : comment.js
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

function Comment() {

	// FIELD
	
	var curTime = new Date();
	this.name_ = "null"; /* name of the commenter */
	this.time_ = curTime.getHours() + ":" + curTime.getMinutes() + ":" + curTime.getSeconds(); /* time commented */
	this.date_ = curTime.getDate() + "-" + (curTime.getMonth()+1) + "-" + curTime.getFullYear(); /* date commented */
	this.content_ = "null content"; /* content inside spoiler */
	
	
	// ACCESSOR GET
	
	this.getName = function() 
	/* returns name_ value */
	{
		return this.name_;
	}
	
	this.getTime = function()
	/* returns time_ value */
	{
		return this.time_
	}

	this.getDate = function() 
	/* returns date_ value */
	{
		return this.date_;
	}
	
	this.getContent = function()
	/* returns content_ value */
	{
		return this.content_;
	}
	
		
	// ACCESSOR SET

	this.setName = function(_newName) 
	/* changes name_ value */
	{
		this.name_ = _newName;
	}
	
	this.setTime = function(_newTime)
	/* changes time_ value */
	{
		this.time_ = _newTime;
	}

	this.setDate = function(_newDate) 
	/* changes date_ value */
	{
		this.date_ = _newDate;
	}
	
	this.setContent = function(_newContent)
	/* gets content_ value */
	{
		this.content_ = _newContent;
	}
	
	
	// METHOD
		
	this.display = function(varStr) 
	/* displays interface */
	{
		
		var preventHTML = /</g;
		document.write("<div style=\"margin-bottom:10px; border:solid; width:300px; border-width:1px; \" id=\"comment"+varStr+"\">")
		document.write("<div style=\"font-weight:bold; \" >"+this.name_.replace(preventHTML,'&lt;')+"</div><hr />");
		document.write("<div style=\"font-size:12px; text-align:right; \" >Posted at "+this.time_+", "+this.date_+"</div>");
		document.write("<div>"+ this.content_.replace(preventHTML,'&lt;')+"</div>");
		document.write("</div>");
	}

}