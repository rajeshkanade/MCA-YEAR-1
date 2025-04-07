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
      body {
        font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        background-color: #f5f7fa;
        margin: 0;
        padding: 0;
        display: flex;
        justify-content: center;
        align-items: center;
        min-height: 100vh;
      }
      .form-container {
        background: white;
        padding: 30px;
        border-radius: 10px;
        box-shadow: 0 4px 20px rgba(0, 0, 0, 0.1);
        width: 100%;
        max-width: 500px;
      }
      h1 {
        color: #2c3e50;
        text-align: center;
        margin-bottom: 25px;
      }
      .form-group {
        margin-bottom: 20px;
      }
      label {
        display: block;
        margin-bottom: 8px;
        color: #34495e;
        font-weight: 500;
      }
      input[type="text"],
      input[type="password"] {
        width: 95%;
        padding: 12px 15px;
        border: 1px solid #ddd;
        border-radius: 5px;
        font-size: 16px;
        transition: border-color 0.3s;
      }
      input[type="text"]:focus,
      input[type="password"]:focus {
        border-color: #3498db;
        outline: none;
        box-shadow: 0 0 0 3px rgba(52, 152, 219, 0.1);
      }
      input[type="submit"] {
        width: 100%;
        padding: 12px;
        background: #3498db;
        color: white;
        border: none;
        border-radius: 5px;
        font-size: 16px;
        font-weight: 500;
        cursor: pointer;
        transition: background 0.3s;
      }
      input[type="submit"]:hover {
        background: #2980b9;
      }
      .message {
        margin-top: 20px;
        padding: 15px;
        border-radius: 4px;
      }
      .success {
        background: #e8f4fc;
        border-left: 4px solid #3498db;
        color: #2c3e50;
      }
      .error {
        background: #fdecea;
        border-left: 4px solid #e53935;
        color: #c62828;
      }
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
