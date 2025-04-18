<%-- 
    Assignment 7 - Question 1
    Create a JSP page that:
    - Takes a file extension as input
    - Lists all files in the webapp directory with that extension
    - Provides clickable links to the files
    - Handles case-insensitive matching
    - Shows appropriate message if no files found

    Features:
    - Simple form input for file extension
    - Dynamic file listing using Java IO
    - Error handling for empty input
    - Clean HTML output with proper formatting

    Technical Requirements:
    - Uses JSP scriptlet for server-side logic
    - Accesses application real path for directory scanning
    - Implements case-insensitive comparison
--%>
<%@ page import="java.io.*" %>
<html>
<head>
    <title>File List by Extension</title>
</head>
<body>
    <h2>Enter File Extension</h2>
    <form method="post">
        <input type="text" name="extension" placeholder="e.g. .jsp" required>
        <input type="submit" value="List Files">
    </form>

    <h2>Matching Files:</h2>
    <ul>
    <%
        String ext = request.getParameter("extension");
        if (ext != null && !ext.isEmpty()) {
            File dir = new File(application.getRealPath(""));
            File[] files = dir.listFiles();
            boolean found = false;
            
            if (files != null) {
                for (File file : files) {
                    if (file.isFile() && file.getName().toLowerCase().endsWith(ext.toLowerCase())) {
                        out.println("<li><a href=\"" + file.getName() + "\">" + file.getName() + "</a></li>");
                        found = true;
                    }
                }
            }
            if (!found) {
                out.println("<li>No files found with extension " + ext + "</li>");
            }
        }
    %>
    </ul>
</body>
</html>