<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Reuse Existing Class in Other Jsp Page</title>
		<jsp:useBean id="sc" class="packviru.SomeClass" scope="session" type="packviru.SomeClass"/>
	</head>
	<body>
		<div style="font-weight:bold;">Page 1</div><br/>
		<%=sc.getSomeInt() %><br/>
		<%=sc.getSomeString() %>
		<br/>
		<br/>
		<a href="page2.jsp">Go to Page 2</a>
	</body>
</html>