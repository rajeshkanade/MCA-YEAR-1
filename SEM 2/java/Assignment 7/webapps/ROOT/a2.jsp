<%-- Assignment 7 - Question 2 Create a JSP page that: - Displays a color
selection interface - Provides clickable color boxes (Red, Blue, Green, Yellow,
Purple) - Links to a color display page with the selected color as parameter -
Uses CSS styling for visual presentation Features: - Responsive color boxes with
centered text - Clean HTML5 structure - Proper character encoding (UTF-8) -
Semantic HTML elements Technical Requirements: - Uses JSP page directives -
Passes color parameter via URL query string - Inline CSS for color box styling -
Accessible color names in boxes --%> <%@ page language="java"
contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
  <head>
    <title>Color Selection</title>
    <style>
      body {
        font-family: "Segoe UI", Tahoma, Geneva, Verdana, sans-serif;
        background-color: #f8f9fa;
        margin: 0;
        padding: 20px;
        display: flex;
        flex-direction: column;
        align-items: center;
        min-height: 100vh;
      }
      .container {
        max-width: 800px;
        width: 100%;
        text-align: center;
      }
      h1 {
        color: #343a40;
        margin-bottom: 30px;
        font-size: 2.5rem;
        text-shadow: 1px 1px 2px rgba(0, 0, 0, 0.1);
      }
      .color-grid {
        width: 100%;
        display: grid;
        grid-template-columns: repeat(auto-fit, minmax(150px, 1fr));
        gap: 20px;
        justify-items: center;
      }
      .color-box {
        width: 150px;
        height: 150px;
        border-radius: 10px;
        display: flex;
        align-items: center;
        justify-content: center;
        color: white;
        font-weight: bold;
        font-size: 1.2rem;
        text-shadow: 1px 1px 2px rgba(0, 0, 0, 0.5);
        box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
        transition: all 0.3s ease;
        cursor: pointer;
        text-decoration: none;
      }
      .color-box:hover {
        transform: translateY(-5px);
        box-shadow: 0 8px 16px rgba(0, 0, 0, 0.2);
      }
      .red {
        background-color: #e63946;
      }
      .blue {
        background-color: #1d3557;
      }
      .green {
        background-color: #2a9d8f;
      }
      .yellow {
        background-color: #e9c46a;
        color: #333;
        text-shadow: none;
      }
      .purple {
        background-color: #6a4c93;
      }
    </style>
  </head>
  <body>
    <div class="container">
      <h1>Choose Your Favorite Color</h1>

      <div class="color-grid">
        <a href="colorDisplay.jsp?color=red" class="color-box red">Red</a>
        <a href="colorDisplay.jsp?color=blue" class="color-box blue">Blue</a>
        <a href="colorDisplay.jsp?color=green" class="color-box green">Green</a>
        <a href="colorDisplay.jsp?color=yellow" class="color-box yellow"
          >Yellow</a
        >
        <a href="colorDisplay.jsp?color=purple" class="color-box purple"
          >Purple</a
        >
      </div>
    </div>
  </body>
</html>
