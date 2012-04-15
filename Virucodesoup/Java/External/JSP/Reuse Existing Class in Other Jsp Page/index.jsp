<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Reuse Existing Class in Other Jsp Page</title>

		<jsp:useBean id="sc" class="packviru.SomeClass" scope="session" type="packviru.SomeClass"/>
		
	</head>
	<body>
		<div style="font-weight:bold;">This sisulates how to keep class between pages so it can be used in other jsp pages. To achieve it, set scope into "session" and set type into "PathOfPackageName" (check source code) </div><br />
		<form method="get" action="change.jsp">
			Fill random number: <input type="text" name="intInput" />(Returns error page if not number)<br />
			Fill random text: <input type="text" name="textInput" /><br />
			<input type="submit" name="submit" value="Submit" />
		</form>
	
	</body>
</html>