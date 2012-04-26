<%--

===========================
File : index.jsp

Credit:
- Coded by (aka in cyber) Vsio Stitched

Misc:
- Written in Java programming language
- Included Extension : JSP

License:
- Free to use
- May include me or not in credit if included in other project
===========================

--%>

<%

	// Checks whether already login
	
	if (session.getAttribute("username") != null) {
		response.sendRedirect("profile.jsp");
		return;
	}
%>

<html>
	<head>
		<title>Login and Logout</title>
	</head>
	<body>
	<div>Demonstrates how to login and logout</div><br />
	
	<form action="doLogin.jsp" method="post">
	Username: <input type="text" name="username" /><br />
	Password: <input type="password" name="password" /><br />
	<input type="submit" />

	</form>
	</body>

</html>