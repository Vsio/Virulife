<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>User Input Text</title>
		<jsp:useBean id="userInputText" class="packviru.UserInputText"  type="packviru.UserInputText"/>
		<% String jsp_textInput=request.getParameter("textInput"); %>
	</head>
	<body>
	
		<%=userInputText.input(jsp_textInput) %>
	</body>
</html>