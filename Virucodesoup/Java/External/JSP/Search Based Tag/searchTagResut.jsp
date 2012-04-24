<%--

===========================
File : searchTagResut.jsp

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

	// Gets input from previous page

	String tagFilter = request.getParameter("tag");

	if (tagFilter==null) {
		tagFilter = "";
	}
	
	
	// Makes connection to Mysql server
	
	Class.forName("com.mysql.jdbc.Driver"); 
	java.sql.Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/db_virucodesoup","root",""); // Replace argument 1 with your mysql username and replace argument 2 with your mysql password
	Statement statement = connection.createStatement(); 
	ResultSet resultSet = statement.executeQuery("SELECT * FROM Post");
	
	
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
	
	
	// Checks whether required tag exists in a post
	
	ArrayList<String> tagId = new ArrayList<String>();
	
	for (int i=0;i!=id.size();i++) {
		String[] tags = tag.get(i).split(",");
		Boolean contain = false;
		
		for (String str:tags) {
			Boolean charCheck = true;
			for (int j=0;j!=str.length();j++) {
				if (str.length()!=tagFilter.length()) {
					charCheck = false;
					break;
				}
				
				if (str.charAt(j)!=tagFilter.charAt(j)) {					
					charCheck = false;
				}
				
			}
			if (charCheck==true) {
				contain = true;
				break;
			}
		}
		if (contain==true) {
			tagId.add(Integer.toString(i));
		}
	}

%>

<html>
	<head>
		<title>Search Based Tag</title>
	</head>
	<body>
		<% 
			// Prints result to the web
		
			out.println("<div>Search result contains tag \""+tagFilter+"\" with "+tagId.size()+" result(s) : </div><br />");
			int j = 0;
			for (int i=0;i!=id.size();i+=1) {
					if (tagId.contains(Integer.toString(i))) {
					out.println("<div style=\"font-weight:bold;\">"+(j+1)+". "+title.get(i)+"</div>");
					out.println("<div>Tag: "+tag.get(i)+"</div><br />");
					j++;
				}
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