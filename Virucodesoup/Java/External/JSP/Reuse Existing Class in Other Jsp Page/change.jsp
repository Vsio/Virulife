<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Reuse Existing Class in Other Jsp Page</title>
		
		<jsp:useBean id="sc" class="packviru.SomeClass" scope="session" type="packviru.SomeClass"/>
		<% String jsp_intInput=request.getParameter("intInput"); %>
		<% String jsp_textInput=request.getParameter("textInput"); %>
	</head>
	<body>
		<div style="font-weight:bold;">Changed to: </div>
		<% sc.setSomeInt(Integer.parseInt(jsp_intInput)); %>
		<% sc.setSomeString(jsp_textInput); %>
	
		<%=sc.getSomeInt() %><br/>
		<%=sc.getSomeString() %>
		<br/>
		<br/>
		<a href="page1.jsp">Go to Page 1</a><br/>
		<a href="page2.jsp">Go to Page 2</a>
		
	</body>
</html>