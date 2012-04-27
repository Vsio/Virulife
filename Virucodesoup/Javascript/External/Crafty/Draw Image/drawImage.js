// ===========================
// File : drawImage.js
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

Crafty.c("DrawImage", {
	init: function() {
		
		// INITIALIZE
		
		this.addComponent("Image","2D","DOM");
		
		
		// METHOD
		
		this.drawImage = function(_imagePath,_w,_h,_newX,_newY) 
		// draws image
		{
			this.image(_imagePath);
			this.attr({w:_w,h:_h,x:_newX,y:_newY});
		}
	}	
});

function DrawImage_Driver() 
// performs object functionality
{
	var imagePath = "20110811.PNG";
	var hw = Crafty.e("DrawImage");
	hw.drawImage(imagePath,101,101,190,70);
}
