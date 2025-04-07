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
      body {
        font-family: "Segoe UI", Tahoma, Geneva, Verdana, sans-serif;
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
        background: #e8f4fc;
        border-left: 4px solid #3498db;
        color: #2c3e50;
        border-radius: 4px;
      }
      input{
        width: 95%;
      }
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