<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Selected Color</title>
    <style>
    body {
        text-align: center;
        padding-top: 50px;
        font-family: Arial, sans-serif;
    }
    .color-display {
        font-size: 24px;
        padding: 20px;
        background-color: white;
        border-radius: 10px;
        display: inline-block;
        box-shadow: 0 0 10px rgba(0,0,0,0.2);
    }
    </style>
</head>
<body style="background-color: ${param.color}">
    <div class="color-display">
        You selected: ${param.color}
    </div>
</body>
</html>
