<?php

/* ===========================
// File : factorial.php
//
// Credit:
// - Coded by (aka in cyber) Vsio Stitched
//
// Misc:
// - Written in PHP programming language
//
// License:
// - Free to use
// - May include me or not in credit if included in other project
// =========================== */

function doFactorial($_value)
// calculates factorial operasi
{
	$regexConstrain = "/[^0-9]/";
	$value = $_value;
	
	try {
	
		if (preg_match($regexConstrain,$value)) {
			throw new Exception("Not number");
		}
		
		if ($value < 0) {
			throw new Exception("Less than 0");
		}
		
		if ($value == 0) {
			return 1;
		} else {
			return $value*(doFactorial($value-1));
		}	
	
	}
	catch (Exception $e) {
		if (preg_match($regexConstrain,$value)) {
			echo "Error: Input must be number.";
			return "";
		}
	
		if ($value < 0) {
			echo "Error: Input must more than equal 0.";
			return "";
		}
		
		return "";
	}
}

?>