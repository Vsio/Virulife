<%--

===========================
File : doLogin.jsp

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

<%@ page import ="java.sql.*" %>
<%@ page import ="javax.sql.*" %>
<%

	// Checks whether already login

	if (session.getAttribute("username") != null) {
		response.sendRedirect("profile.jsp");
		return;
	}

	
	// Gets input from previous page's form

	String user=request.getParameter("username");	
	String pass=request.getParameter("password"); 
		
		
	// Makes connection to Mysql server
	
	Class.forName("com.mysql.jdbc.Driver"); 
	java.sql.Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/db_virucodesoup","root",""); // Replace argument 1 with your mysql username and replace argument 2 with your mysql password
	Statement statement= connection.createStatement(); 
	ResultSet resultSet=statement.executeQuery("SELECT * FROM user WHERE username='"+user+"'"); // query
	
	
	// Controls the flow from page to other page
	
	String pageTo=""; // page to depends on whether login is succeed or not
	String timing=""; // timing of redirection
	String message=""; // message based on whether login is succeed or not
	
	
	// Gets result from result set
	
	if(resultSet.next())  { 
		if(resultSet.getString(3).equals(pass))  {
			session.setAttribute("username",resultSet.getString(2)); 
			
			session.setAttribute("like",resultSet.getString(4));
			session.setAttribute("dislike",resultSet.getString(5));
			
			pageTo = "profile.jsp";
			timing = "0";
			message = "<div>Login successfully. Redirecting to profile.jsp.</div>";
			
		} else { 
			message = "<div>Username and password don't match. Redirecting to index.jsp.</div>";
			pageTo = "index.html";
			timing = "5";
		} 
	} else {
		message = "<div>If you refresh in this page, it will go null because of the 'request' from previous form. Other is caused the null result from result set.</div>"; 
	}
%>
<html>
	<head>
	<meta http-equiv="REFRESH" content="<%=timing%>;url=<%=pageTo%>">
	<title>Login and Logout</title>
	</head>
	<body>
		<%=message%>
	</body>
</html>

<%
	// Closes connection from Mysql server
	resultSet.close();
	statement.close();
	connection.close();
%>