// ===========================
// File : driver.js
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

var SCREEN_WIDTH = 480;
var SCREEN_HEIGHT = 240;

window.onload = function() {

	Crafty.init(SCREEN_WIDTH, SCREEN_HEIGHT);
	Crafty.canvas.init();
	Crafty.background("aqua");
	
	DrawImage_Driver();
	
};