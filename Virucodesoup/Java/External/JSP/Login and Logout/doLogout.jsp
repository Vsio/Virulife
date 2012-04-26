<%--

===========================
File : doLogout.jsp

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
	session.invalidate();
%>

<html>
	<head>
		<meta http-equiv="REFRESH" content="5;url=index.jsp">
		<title>Login and Logout</title>
	</head>
	<body>
		<div>You have logged out successfully. Redirecting to index.jsp.</div>
		
	</body>
</html>