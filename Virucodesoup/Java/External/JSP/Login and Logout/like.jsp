<%--

===========================
File : like.jsp

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

	// Checks whether not login yet

	if (session.getAttribute("username") == null) {
		response.sendRedirect("index.jsp");
		return;
	}

	
	// Gets value from currect session
	
	String uUsername = session.getAttribute("username").toString();
	String uLike = session.getAttribute("like").toString();
	
%>

<html>
	<head>
		<title>Login and Logout</title>
	</head>
	<body>
		<h2>Dislike Page</h2>
		<div><span style="font-weight:bold;"><%=uUsername%></span> likes <span style="font-weight:bold;"><%=uLike%></span>.</div><br /><br />
		
		<div style="font-weight:bold;">Other Page:</div>
		<div><a href="profile.jsp">Profile</a></div>
		<div><a href="dislike.jsp">Dislike Page</a></div><br />
		
		<div><a href="doLogout.jsp">Logout</a></div>
		
	</body>
</html>