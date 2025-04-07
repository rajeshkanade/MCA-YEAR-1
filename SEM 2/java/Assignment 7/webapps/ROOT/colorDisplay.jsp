<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
  <head>
    <title>Selected Color</title>
    <style>
      body {
        text-align: center;
        padding-top: 50px;
        font-family: Arial, sans-serif;
        background-color: '${param.color}';
      }
      .color-display {
        font-size: 24px;
        padding: 20px;
        background-color: white;
        border-radius: 10px;
        display: inline-block;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.2);
      }
    </style>
  </head>
  <body style="background-color: ${param.color}; opacity: 0.7;">
    <div class="color-display">You selected: ${param.color}</div>
    <div style="margin-top: 20px">
      <a
        href="a2.jsp"
        style="
          display: inline-block;
          padding: 10px 20px;
          background-color: #333;
          color: white;
          text-decoration: none;
          border-radius: 5px;
          transition: all 0.3s ease;
        "
      >
        ← Back to Colors
      </a>
    </div>
  </body>
</html>
