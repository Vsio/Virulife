<%--

===========================
File : view.jsp

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
<%@ page import ="java.util.ArrayList" %>

<%

	// Makes connection to Mysql server
	
	Class.forName("com.mysql.jdbc.Driver"); 
	java.sql.Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/db_virucodesoup","root",""); // Replace argument 1 with your mysql username and replace argument 2 with your mysql password
	Statement statement = connection.createStatement(); 
	ResultSet resultSet = statement.executeQuery("SELECT * FROM Post ORDER BY id DESC");
	
	
	// Extracts result from query
	
	ArrayList<String> id = new ArrayList<String>(); // 1
	ArrayList<String> title = new ArrayList<String>(); // 2
	ArrayList<String> tag = new ArrayList<String>(); // 3
	
	while (resultSet.next()) {
		try {
			id.add(resultSet.getString(1));		
			title.add(resultSet.getString(2));
			tag.add(resultSet.getString(3));
		} finally {
			
		}
	}	

%>

<html>
	<head>
		<title>Insert Data To MySQL</title>
	</head>
	<body>
		<% 
			// Prints result to the web
		
			for (int i=0;i!=id.size();i+=1) {
				out.println("<div style=\"font-weight:bold;\">"+(i+1)+". "+title.get(i)+"</div>");
				out.println("<div>Tag(s): "+tag.get(i)+"</div><br />");
			}
		%>
	</body>
</html>

<%
	// Closes connection from Mysql server
	resultSet.close();
	statement.close();
	connection.close();
%>