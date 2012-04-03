// ===========================
// File : listOfComment.js
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

function ListOfComments() {

	// FIELD
		
	this.LoComment_ = []; /* lists that store the comments */
	
	
	// ACCESSOR GET
	
	this.getLoComment = function()
	/* gets LoComment_ value*/
	{
		return this.LoComment_;
	}
	
	
	// METHOD
	
	this.commentForm = function(_instanceVarStr, _elmNewComment) 
	/* displays submission form interface */
	{
		document.write("<div id=\"commentForm"+_instanceVarStr+"\" style=\"border:solid; border-width:1px; width:300px;\" ><span style=\"font-weight:bold; font-size:18px;\" >New Comment:</span><br />");
		document.write("<form>");
		document.write("Name: <input type=\"text\" id=\"nameInput"+_instanceVarStr+"\" /><br />");
		document.write("Comment: <br /><textarea id=\"commentInput"+_instanceVarStr+"\" /></textarea><br />");		
		document.write("<input type=\"button\" id=\"submitInput"+_instanceVarStr+"\" value=\"Submit\" onClick=\""+_instanceVarStr+".addNewComment('nameInput"+_instanceVarStr+"','commentInput"+_instanceVarStr+"','"+_elmNewComment+"','"+_instanceVarStr+"')\" /><br />");		
		document.write("</form>");
		document.write("</div>");
		
	}
	
	this.display = function(_instanceVarStr) 
	/* displays interface */
	{
		for (var i=0;i!=this.LoComment_.length;i++) {
			this.LoComment_[i].display(_instanceVarStr+"_"+i);
		}
		document.write("<div id=\"newComment_"+_instanceVarStr+i+"\" ></div>");
		
		this.commentForm(_instanceVarStr,"newComment_"+_instanceVarStr+i);
	}
	
	this.addNewComment = function(_elmName, _elmContent, _elmNewComment, _instanceVarStr) 
	/* adds new comment to the list*/
	{
		this.LoComment_.push(new Comment());
		var tempName = document.getElementById(_elmName).value;
		var tempContent = document.getElementById(_elmContent).value;		
		var curTime = new Date();
		var tempTime = curTime.getHours() + ":" + curTime.getMinutes() + ":" + curTime.getSeconds();
		var tempDate = curTime.getDate() + "-" + (curTime.getMonth()+1) + "-" + curTime.getFullYear();
		this.LoComment_[this.LoComment_.length-1].setName(tempName);
		this.LoComment_[this.LoComment_.length-1].setContent(tempContent);
		this.LoComment_[this.LoComment_.length-1].setTime(tempTime);
		this.LoComment_[this.LoComment_.length-1].setDate(tempDate);
		
		var preventHTML = /</g;
		
		var line1 = "<div style=\"margin-bottom:10px; border:solid; width:300px; border-width:1px;\" id=\"comment"+_instanceVarStr+this.LoComment_.length+"\">";
		var line2 = "<div style=\"font-weight:bold; \" >"+tempName.replace(preventHTML,'&lt;')+"</div><span></span><hr />";
		var line3 = "<div style=\"font-size:12px; text-align:right; \" >Posted at "+tempTime+", "+tempDate+"</div>";
		var line4 = "<div>"+tempContent.replace(preventHTML,'&lt;')+"</div>";
		var line5 = "</div>";

		var newLine = "<div id=\"newComment_"+_instanceVarStr+this.LoComment_.length+"\" ></div>";
		
		document.getElementById(_elmNewComment).innerHTML = line1 + line2 + line3 + line4 + line5 + newLine;
		
		var newCommentForm1 = "<span style=\"font-weight:bold; font-size:18px;\" >New Comment:</span><br /><form>";
		var newCommentForm2 = "Name: <input type=\"text\" id=\"nameInput"+_instanceVarStr+"\" /><br />";
		var newCommentForm3 = "Comment: <br /><textarea id=\"commentInput"+_instanceVarStr+"\" /></textarea><br />";
		var newCommentForm4 = "<input type=\"button\" id=\"submitInput"+_instanceVarStr+"\" value=\"Submit\" onClick=\""+_instanceVarStr+".addNewComment('nameInput"+_instanceVarStr+"','commentInput"+_instanceVarStr+"','newComment_"+_instanceVarStr+this.LoComment_.length+"','"+_instanceVarStr+"');\" /><br />";
		var newCommentForm5 = "</form>";
		
		var newCommentForm = newCommentForm1+newCommentForm2+newCommentForm3+newCommentForm4+newCommentForm5;
		document.getElementById("commentForm"+_instanceVarStr).innerHTML = newCommentForm;
		
	}

}