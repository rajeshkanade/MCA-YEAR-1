<%@ page import="java.sql.*" %>
<%
// Database connection variables
String dbUrl = "jdbc:mysql://192.168.28.3:3306/RAJESH28";
String dbUser = "mca28";
String dbPass = "";

// Initialize variables
String firstName = "";
String message = "";

// Check if form was submitted
if ("get".equalsIgnoreCase(request.getMethod())) { 
    // Get form parameters
    firstName = request.getParameter("firstname");
    String lastName = request.getParameter("lastname");
    String username = request.getParameter("username");
    String password = request.getParameter("password");
    String address = request.getParameter("address");
    String contact = request.getParameter("contact");

    // Database operations
    Connection conn = null;
    PreparedStatement pstmt = null;
    
    try {
        // Load JDBC driver
        Class.forName("com.mysql.cj.jdbc.Driver");
        
        // Create connection
        conn = DriverManager.getConnection(dbUrl, dbUser, dbPass);
        
        // Prepare SQL statement
        String sql = "INSERT INTO users (firstname, lastname, username, password, address, contact) VALUES (?, ?, ?, ?, ?, ?)";
        pstmt = conn.prepareStatement(sql);
        pstmt.setString(1, firstName);
        pstmt.setString(2, lastName);
        pstmt.setString(3, username);
        pstmt.setString(4, password);
        pstmt.setString(5, address);
        pstmt.setString(6, contact);
        
        // Execute insert
        int rows = pstmt.executeUpdate();
        
        if (rows > 0) {
            message = "Welcome " + firstName;
        }
    } catch (Exception e) {
        message = "Error: " + e.getMessage();
    } finally {
        // Close resources
        if (pstmt != null) pstmt.close();
        if (conn != null) conn.close();
    }
}
%>
<!DOCTYPE html>
<html>
<head>
    <title>Registration Form</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        .form-container { max-width: 500px; margin: 0 auto; }
        .form-group { margin-bottom: 15px; }
        label { display: block; margin-bottom: 5px; }
        input[type="text"], input[type="password"] { width: 100%; padding: 8px; }
        input[type="submit"] { padding: 10px 15px; background: #4CAF50; color: white; border: none; cursor: pointer; }
        .message { margin-top: 20px; padding: 10px; background: #f0f0f0; }
    </style>
</head>
<body>
    <div class="form-container">
        <h1>Registration Form</h1>
        <form method="get">
            <div class="form-group">
                <label for="firstname">First Name:</label>
                <input type="text" id="firstname" name="firstname" required>
            </div>
            <div class="form-group">
                <label for="lastname">Last Name:</label>
                <input type="text" id="lastname" name="lastname" required>
            </div>
            <div class="form-group">
                <label for="username">Username:</label>
                <input type="text" id="username" name="username" required>
            </div>
            <div class="form-group">
                <label for="password">Password:</label>
                <input type="password" id="password" name="password" required>
            </div>
            <div class="form-group">
                <label for="address">Address:</label>
                <input type="text" id="address" name="address" required>
            </div>
            <div class="form-group">
                <label for="contact">Contact:</label>
                <input type="text" id="contact" name="contact" required>
            </div>
            <div class="form-group">
                <input type="submit" value="Register">
            </div>
        </form>
        
        <% if (!message.isEmpty()) { %>
            <div class="message"><%= message %></div>
        <% } %>
    </div>
</body>
</html>