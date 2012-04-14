<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Hello World</title>
	</head>
	<body>
	<jsp:useBean id="hello" class="packviru.HelloWorld" />
	<%=hello.sayHelloWorld() %>
	</body>
</html>