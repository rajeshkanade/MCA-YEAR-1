<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Color Selection</title>
    <style>
        .color-box {
            display: inline-block;
            width: 100px;
            height: 100px;
            margin: 10px;
            text-align: center;
            line-height: 100px;
        }
    </style>
</head>
<body>
    <h1>Select a Color</h1>
    
    <div>
        <a href="colorDisplay.jsp?color=red">
            <div class="color-box" style="background-color: red;">Red</div>
        </a>
        <a href="colorDisplay.jsp?color=blue">
            <div class="color-box" style="background-color: blue;">Blue</div>
        </a>
        <a href="colorDisplay.jsp?color=green">
            <div class="color-box" style="background-color: green;">Green</div>
        </a>
        <a href="colorDisplay.jsp?color=yellow">
            <div class="color-box" style="background-color: yellow;">Yellow</div>
        </a>
        <a href="colorDisplay.jsp?color=purple">
            <div class="color-box" style="background-color: purple;">Purple</div>
        </a>
    </div>
</body>
</html>
