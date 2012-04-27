// ===========================
// File : textExample.js
//
// Credit:
// - Coded by (aka in cyber) Vsio Stitched
//
// Misc:
// - Written in Javascript programming language
// - Included Extension: Crafty
// 
// License:
// - Free to use
// - May include me or not in credit if included in other project
// ===========================

Crafty.c("TextExample", {
	init: function() {
		
		// INITIALIZE
		
		this.addComponent("Text","2D","DOM");
		
		
		// METHOD
		
		this.drawText = function(_text,_w,_h,_newX,_newY) 
		// draws Text
		{
			this.attr({w:_w,h:_h,x:_newX,y:_newY});
			this.text(_text).css({"text-align": "center","vertical-align": "middle"});;
		}
	}	
});

function TextExample_Driver() 
// performs object's functionality
{
	var te = Crafty.e("TextExample");
	te.drawText("This is text example",480,100,0,100);
}
