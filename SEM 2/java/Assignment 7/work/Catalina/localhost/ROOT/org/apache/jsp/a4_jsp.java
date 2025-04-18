/*
 * Generated by the Jasper component of Apache Tomcat
 * Version: Apache Tomcat/8.5.76
 * Generated at: 2025-04-07 07:40:28 UTC
 * Note: The last modified time of this file was set to
 *       the last modified time of the source file after
 *       generation to assist with modification tracking.
 */
package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.sql.*;

public final class a4_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent,
                 org.apache.jasper.runtime.JspSourceImports {

  private static final javax.servlet.jsp.JspFactory _jspxFactory =
          javax.servlet.jsp.JspFactory.getDefaultFactory();

  private static java.util.Map<java.lang.String,java.lang.Long> _jspx_dependants;

  private static final java.util.Set<java.lang.String> _jspx_imports_packages;

  private static final java.util.Set<java.lang.String> _jspx_imports_classes;

  static {
    _jspx_imports_packages = new java.util.HashSet<>();
    _jspx_imports_packages.add("java.sql");
    _jspx_imports_packages.add("javax.servlet");
    _jspx_imports_packages.add("javax.servlet.http");
    _jspx_imports_packages.add("javax.servlet.jsp");
    _jspx_imports_classes = null;
  }

  private volatile javax.el.ExpressionFactory _el_expressionfactory;
  private volatile org.apache.tomcat.InstanceManager _jsp_instancemanager;

  public java.util.Map<java.lang.String,java.lang.Long> getDependants() {
    return _jspx_dependants;
  }

  public java.util.Set<java.lang.String> getPackageImports() {
    return _jspx_imports_packages;
  }

  public java.util.Set<java.lang.String> getClassImports() {
    return _jspx_imports_classes;
  }

  public javax.el.ExpressionFactory _jsp_getExpressionFactory() {
    if (_el_expressionfactory == null) {
      synchronized (this) {
        if (_el_expressionfactory == null) {
          _el_expressionfactory = _jspxFactory.getJspApplicationContext(getServletConfig().getServletContext()).getExpressionFactory();
        }
      }
    }
    return _el_expressionfactory;
  }

  public org.apache.tomcat.InstanceManager _jsp_getInstanceManager() {
    if (_jsp_instancemanager == null) {
      synchronized (this) {
        if (_jsp_instancemanager == null) {
          _jsp_instancemanager = org.apache.jasper.runtime.InstanceManagerFactory.getInstanceManager(getServletConfig());
        }
      }
    }
    return _jsp_instancemanager;
  }

  public void _jspInit() {
  }

  public void _jspDestroy() {
  }

  public void _jspService(final javax.servlet.http.HttpServletRequest request, final javax.servlet.http.HttpServletResponse response)
      throws java.io.IOException, javax.servlet.ServletException {

    final java.lang.String _jspx_method = request.getMethod();
    if (!"GET".equals(_jspx_method) && !"POST".equals(_jspx_method) && !"HEAD".equals(_jspx_method) && !javax.servlet.DispatcherType.ERROR.equals(request.getDispatcherType())) {
      response.sendError(HttpServletResponse.SC_METHOD_NOT_ALLOWED, "JSPs only permit GET, POST or HEAD. Jasper also permits OPTIONS");
      return;
    }

    final javax.servlet.jsp.PageContext pageContext;
    javax.servlet.http.HttpSession session = null;
    final javax.servlet.ServletContext application;
    final javax.servlet.ServletConfig config;
    javax.servlet.jsp.JspWriter out = null;
    final java.lang.Object page = this;
    javax.servlet.jsp.JspWriter _jspx_out = null;
    javax.servlet.jsp.PageContext _jspx_page_context = null;


    try {
      response.setContentType("text/html");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;

      out.write('\n');
      out.write('\n');

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

      out.write("\n");
      out.write("<!DOCTYPE html>\n");
      out.write("<html>\n");
      out.write("<head>\n");
      out.write("    <title>Login Form</title>\n");
      out.write("    <style>\n");
      out.write("      body {\n");
      out.write("        font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;\n");
      out.write("        background-color: #f5f7fa;\n");
      out.write("        margin: 0;\n");
      out.write("        padding: 0;\n");
      out.write("        display: flex;\n");
      out.write("        justify-content: center;\n");
      out.write("        align-items: center;\n");
      out.write("        min-height: 100vh;\n");
      out.write("      }\n");
      out.write("      .form-container {\n");
      out.write("        background: white;\n");
      out.write("        padding: 30px;\n");
      out.write("        border-radius: 10px;\n");
      out.write("        box-shadow: 0 4px 20px rgba(0, 0, 0, 0.1);\n");
      out.write("        width: 100%;\n");
      out.write("        max-width: 500px;\n");
      out.write("      }\n");
      out.write("      h1 {\n");
      out.write("        color: #2c3e50;\n");
      out.write("        text-align: center;\n");
      out.write("        margin-bottom: 25px;\n");
      out.write("      }\n");
      out.write("      .form-group {\n");
      out.write("        margin-bottom: 20px;\n");
      out.write("      }\n");
      out.write("      label {\n");
      out.write("        display: block;\n");
      out.write("        margin-bottom: 8px;\n");
      out.write("        color: #34495e;\n");
      out.write("        font-weight: 500;\n");
      out.write("      }\n");
      out.write("      input[type=\"text\"],\n");
      out.write("      input[type=\"password\"] {\n");
      out.write("        width: 95%;\n");
      out.write("        padding: 12px 15px;\n");
      out.write("        border: 1px solid #ddd;\n");
      out.write("        border-radius: 5px;\n");
      out.write("        font-size: 16px;\n");
      out.write("        transition: border-color 0.3s;\n");
      out.write("      }\n");
      out.write("      input[type=\"text\"]:focus,\n");
      out.write("      input[type=\"password\"]:focus {\n");
      out.write("        border-color: #3498db;\n");
      out.write("        outline: none;\n");
      out.write("        box-shadow: 0 0 0 3px rgba(52, 152, 219, 0.1);\n");
      out.write("      }\n");
      out.write("      input[type=\"submit\"] {\n");
      out.write("        width: 100%;\n");
      out.write("        padding: 12px;\n");
      out.write("        background: #3498db;\n");
      out.write("        color: white;\n");
      out.write("        border: none;\n");
      out.write("        border-radius: 5px;\n");
      out.write("        font-size: 16px;\n");
      out.write("        font-weight: 500;\n");
      out.write("        cursor: pointer;\n");
      out.write("        transition: background 0.3s;\n");
      out.write("      }\n");
      out.write("      input[type=\"submit\"]:hover {\n");
      out.write("        background: #2980b9;\n");
      out.write("      }\n");
      out.write("      .message {\n");
      out.write("        margin-top: 20px;\n");
      out.write("        padding: 15px;\n");
      out.write("        border-radius: 4px;\n");
      out.write("      }\n");
      out.write("      .success {\n");
      out.write("        background: #e8f4fc;\n");
      out.write("        border-left: 4px solid #3498db;\n");
      out.write("        color: #2c3e50;\n");
      out.write("      }\n");
      out.write("      .error {\n");
      out.write("        background: #fdecea;\n");
      out.write("        border-left: 4px solid #e53935;\n");
      out.write("        color: #c62828;\n");
      out.write("      }\n");
      out.write("    </style>\n");
      out.write("</head>\n");
      out.write("<body>\n");
      out.write("    <div class=\"form-container\">\n");
      out.write("        <h1>Login Form</h1>\n");
      out.write("        <form method=\"post\">\n");
      out.write("            <div class=\"form-group\">\n");
      out.write("                <label for=\"username\">Username:</label>\n");
      out.write("                <input type=\"text\" id=\"username\" name=\"username\" value=\"");
      out.print( username );
      out.write("\" required>\n");
      out.write("            </div>\n");
      out.write("            <div class=\"form-group\">\n");
      out.write("                <label for=\"password\">Password:</label>\n");
      out.write("                <input type=\"password\" id=\"password\" name=\"password\" required>\n");
      out.write("            </div>\n");
      out.write("            <div class=\"form-group\">\n");
      out.write("                <input type=\"submit\" value=\"Login\">\n");
      out.write("            </div>\n");
      out.write("        </form>\n");
      out.write("        \n");
      out.write("        ");
 if (!message.isEmpty()) { 
      out.write("\n");
      out.write("            <div class=\"message ");
      out.print( message.contains("Welcome") ? "success" : "error" );
      out.write("\">\n");
      out.write("                ");
      out.print( message );
      out.write("\n");
      out.write("            </div>\n");
      out.write("        ");
 } 
      out.write("\n");
      out.write("    </div>\n");
      out.write("</body>\n");
      out.write("</html>\n");
    } catch (java.lang.Throwable t) {
      if (!(t instanceof javax.servlet.jsp.SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          try {
            if (response.isCommitted()) {
              out.flush();
            } else {
              out.clearBuffer();
            }
          } catch (java.io.IOException e) {}
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
