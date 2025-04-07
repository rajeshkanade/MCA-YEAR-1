<%-- 
    Assignment 7 - Question 4
    Create a JSP login form that:
    - Authenticates users against the RAJESH28 database
    - Shows appropriate success/error messages
    - Maintains username in form after submission
    - Uses POST method for security

    Features:
    - Clean responsive form layout with CSS
    - Secure password field
    - Color-coded message display
    - Form field persistence
    - Database connection handling

    Technical Requirements:
    - JDBC for database operations
    - Prepared statements to prevent SQL injection
    - Proper resource cleanup
    - Connection details:
      - URL: jdbc:mysql://192.168.28.3:3306/RAJESH28
      - User: mca28
      - No password
--%>
<%@ page import="java.sql.*" %>
<%
// Database connection variables (same as a3.jsp)
String dbUrl = "jdbc:mysql://192.168.28.3:3306/RAJESH28";
String dbUser = "mca28";
String dbPass = "";

// Initialize variables
String message = "";
String username = "";

// Check if form was submitted
if ("POST".equalsIgnoreCase(request.getMethod())) {
    // Get form parameters
    username = request.getParameter("username");
    String password = request.getParameter("password");

    // Database operations
    Connection conn = null;
    PreparedStatement pstmt = null;
    ResultSet rs = null;
    
    try {
        // Load JDBC driver
        Class.forName("com.mysql.jdbc.Driver");
        
        // Create connection
        conn = DriverManager.getConnection(dbUrl, dbUser, dbPass);
        
        // Prepare SQL statement
        String sql = "SELECT firstname FROM users WHERE username = ? AND password = ?";
        pstmt = conn.prepareStatement(sql);
        pstmt.setString(1, username);
        pstmt.setString(2, password);
        
        // Execute query
        rs = pstmt.executeQuery();
        
        if (rs.next()) {
            String firstName = rs.getString("firstname");
            message = "Login successful! Welcome back " + firstName;
        } else {
            message = "Invalid username or password";
        }
    } catch (Exception e) {
        message = "Error: " + e.getMessage();
    } finally {
        // Close resources
        if (rs != null) rs.close();
        if (pstmt != null) pstmt.close();
        if (conn != null) conn.close();
    }
}
%>
<!DOCTYPE html>
<html>
<head>
    <title>Login Form</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        .form-container { max-width: 500px; margin: 0 auto; }
        .form-group { margin-bottom: 15px; }
        label { display: block; margin-bottom: 5px; }
        input[type="text"], input[type="password"] { width: 100%; padding: 8px; }
        input[type="submit"] { padding: 10px 15px; background: #4CAF50; color: white; border: none; cursor: pointer; }
        .message { margin-top: 20px; padding: 10px; }
        .success { background: #dff0d8; color: #3c763d; }
        .error { background: #f2dede; color: #a94442; }
    </style>
</head>
<body>
    <div class="form-container">
        <h1>Login Form</h1>
        <form method="post">
            <div class="form-group">
                <label for="username">Username:</label>
                <input type="text" id="username" name="username" value="<%= username %>" required>
            </div>
            <div class="form-group">
                <label for="password">Password:</label>
                <input type="password" id="password" name="password" required>
            </div>
            <div class="form-group">
                <input type="submit" value="Login">
            </div>
        </form>
        
        <% if (!message.isEmpty()) { %>
            <div class="message <%= message.contains("Welcome") ? "success" : "error" %>">
                <%= message %>
            </div>
        <% } %>
    </div>
</body>
</html>
