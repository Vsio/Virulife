<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>User Input Text</title>
		<jsp:useBean id="userInputText" class="packviru.UserInputText" scope="session" type="packviru.UserInputText"/>
	</head>
	<body>
		<div>This shows how to pass user input's value into class's property value.</div>
		<form method="get" action="result.jsp">
			Put some text: <input type="text" name="textInput" /><br />
			<input type="submit" name="submit" value="Submit" />
		</form>
	</body>
</html>