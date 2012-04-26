<%--

===========================
File : post.jsp

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

	// Controls page flow to other page

	String timing = "";
	String pageTo = "";
	String message = "";
	
	// Gets input from previous page

	String titleInput = request.getParameter("title");
	String tagsInput = request.getParameter("tags");
	
	if (titleInput == null) {
		titleInput = "";
	}
	
	if (tagsInput == null) {
		tagsInput = "";
	}	
	
	if ( (titleInput=="") || (tagsInput=="") ) {
		timing = "5";
		pageTo = "index.html";
		message = "<div>Error: Title nor Tags may not be null value. Returning to index.html.</div>";
	} else {
	
		timing = "5";
		pageTo = "view.jsp";
		message = "<div>Input successfully posted! Redirect to view.jsp.</div>";
	
		// Makes connection to Mysql server
	
		Class.forName("com.mysql.jdbc.Driver"); 
		java.sql.Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/db_virucodesoup","root",""); // Replace argument 1 with your mysql username and replace argument 2 with your mysql password
		Statement statement = connection.createStatement(); 	
		statement.executeUpdate("insert into Post values('0','"+titleInput+"','"+tagsInput+"')"); // Input to the MySQL server
		
		// Closes connection from Mysql server
		statement.close();
		connection.close();
	}

%>

<html>
	<head>
		<meta http-equiv="REFRESH" content="<%=timing%>;url=<%=pageTo%>">
		<title>Insert Data To MySQL</title>
	</head>
	<body>
		<%=message%>
	</body>
</html>