<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		
	<?php

	/* ===========================
	// File : post.php
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

	require("factorial.php");
	
	?>
		
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<title>Factorial</title>
		
	</head>
	<body>
	
		<span> Input: <?php echo $_POST["input"]; ?></span><br/>
		<span> Factorial Result:  <?php echo doFactorial($_POST["input"]); ?></span>		
	
	</body>
</html>
