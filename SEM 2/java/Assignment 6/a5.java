/**
 * Assignment 6 - Question 5
 * 
 * Create a Java Swing application for Student Record Management that:
 * - Connects to MySQL database (RAJESH28)
 * - Provides CRUD operations (Create, Read, Update, Delete)
 * - Includes search functionality by roll number
 * - Validates input fiel   qds
 * 
 * Features:
 * - Swing GUI with form fields and action buttons
 * - Database table creation if not exists
 * - Input validation for all fields
 * - Confirmation dialogs for delete operations
 * - Error handling with user feedback
 * 
 * Database Schema:
 * - Table: students
 * - Fields: rollNo (VARCHAR, PK), name (VARCHAR), totalMarks (INT)
 * 
 * Connection Details:
 * - URL: jdbc:mysql://192.168.28.3:3306/RAJESH28
 * - Username: mca28
 * - No password required
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class a5 {
    private Connection connection;
    private JFrame frame;
    private JTextField rollNoField, nameField, totalMarksField;
    private JButton addButton, deleteButton, updateButton, searchButton, clearButton;

    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            try {
                a5 window = new a5();
                window.frame.setVisible(true);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }
    public a5() {
        initialize();
        connectToDatabase();
    }

    private void initialize() {
        frame = new JFrame("Student Record Management");
        frame.setBounds(100, 100, 500, 350);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);

        // Labels
        JLabel lblRollNo = new JLabel("Roll Number:");
        lblRollNo.setBounds(30, 30, 100, 20);
        frame.getContentPane().add(lblRollNo);

        JLabel lblName = new JLabel("Name:");
        lblName.setBounds(30, 70, 100, 20);
        frame.getContentPane().add(lblName);

        JLabel lbltotalMarks = new JLabel("totalMarks:");
        lbltotalMarks.setBounds(30, 110, 100, 20);
        frame.getContentPane().add(lbltotalMarks);

        // Text Fields
        rollNoField = new JTextField();
        rollNoField.setBounds(140, 30, 200, 20);
        frame.getContentPane().add(rollNoField);
        rollNoField.setColumns(10);

        nameField = new JTextField();
        nameField.setBounds(140, 70, 200, 20);
        frame.getContentPane().add(nameField);
        nameField.setColumns(10);

        totalMarksField = new JTextField();
        totalMarksField.setBounds(140, 110, 200, 20);
        frame.getContentPane().add(totalMarksField);
        totalMarksField.setColumns(10);

        // Buttons
        addButton = new JButton("Add");
        addButton.setBounds(30, 160, 100, 30);
        addButton.addActionListener(e -> addRecord());
        frame.getContentPane().add(addButton);

        deleteButton = new JButton("Delete");
        deleteButton.setBounds(140, 160, 100, 30);
        deleteButton.addActionListener(e -> deleteRecord());
        frame.getContentPane().add(deleteButton);

        updateButton = new JButton("Update");
        updateButton.setBounds(250, 160, 100, 30);
        updateButton.addActionListener(e -> updateRecord());
        frame.getContentPane().add(updateButton);

        searchButton = new JButton("Search");
        searchButton.setBounds(360, 160, 100, 30);
        searchButton.addActionListener(e -> searchRecord());
        frame.getContentPane().add(searchButton);

        clearButton = new JButton("Clear");
        clearButton.setBounds(195, 210, 100, 30);
        clearButton.addActionListener(e -> clearFields());
        frame.getContentPane().add(clearButton);
    }

    private void connectToDatabase() {
        try {
             Class.forName("com.mysql.cj.jdbc.Driver");
            
            // Establish connection
            String url = "jdbc:mysql://192.168.28.3:3306/RAJESH28";
            String username = "mca28";
            String password = "";
            
            connection = DriverManager.getConnection(url, username, password);
            System.out.println("Connected to database successfully!");
            
            // Create table if not exists
            Statement stmt = connection.createStatement();
            stmt.execute("CREATE TABLE IF NOT EXISTS students (" +
                         "rollNo VARCHAR(20) PRIMARY KEY, " +
                         "name VARCHAR(100) NOT NULL, " +
                         "totalMarks INT NOT NULL)");
        } catch (Exception e) {
            JOptionPane.showMessageDialog(frame, "Database connection failed: " + e.getMessage(), 
                "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }
    }

    private void addRecord() {
        try {
            String rollNo = rollNoField.getText().trim();
            String name = nameField.getText().trim();
            String totalMarks = totalMarksField.getText().trim();

            if (rollNo.isEmpty() || name.isEmpty() || totalMarks.isEmpty()) {
                JOptionPane.showMessageDialog(frame, "All fields are required!", 
                    "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }

            String sql = "INSERT INTO students (rollNo, name, totalMarks) VALUES (?, ?, ?)";
            PreparedStatement pstmt = connection.prepareStatement(sql);
            pstmt.setString(1, rollNo);
            pstmt.setString(2, name);
            pstmt.setInt(3, Integer.parseInt(totalMarks));

            int rowsAffected = pstmt.executeUpdate();
            if (rowsAffected > 0) {
                JOptionPane.showMessageDialog(frame, "Record added successfully!");
                clearFields();
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, "totalMarks must be a number!", 
                "Error", JOptionPane.ERROR_MESSAGE);
        } catch (SQLIntegrityConstraintViolationException e) {
            JOptionPane.showMessageDialog(frame, "Roll number already exists!", 
                "Error", JOptionPane.ERROR_MESSAGE);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "Error adding record: " + e.getMessage(), 
                "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void deleteRecord() {
        String rollNo = rollNoField.getText().trim();
        if (rollNo.isEmpty()) {
            JOptionPane.showMessageDialog(frame, "Please enter roll number to delete", 
                "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        int confirm = JOptionPane.showConfirmDialog(frame, 
            "Are you sure you want to delete this record?", 
            "Confirm Delete", JOptionPane.YES_NO_OPTION);
        
        if (confirm == JOptionPane.YES_OPTION) {
            try {
                String sql = "DELETE FROM students WHERE rollNo = ?";
                PreparedStatement pstmt = connection.prepareStatement(sql);
                pstmt.setString(1, rollNo);

                int rowsAffected = pstmt.executeUpdate();
                if (rowsAffected > 0) {
                    JOptionPane.showMessageDialog(frame, "Record deleted successfully!");
                    clearFields();
                } else {
                    JOptionPane.showMessageDialog(frame, "Record not found!", 
                        "Error", JOptionPane.ERROR_MESSAGE);
                }
            } catch (SQLException e) {
                JOptionPane.showMessageDialog(frame, "Error deleting record: " + e.getMessage(), 
                    "Error", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    private void updateRecord() {
        String rollNo = rollNoField.getText().trim();
        if (rollNo.isEmpty()) {
            JOptionPane.showMessageDialog(frame, "Please enter roll number to update", 
                "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        try {
            String name = nameField.getText().trim();
            String totalMarks = totalMarksField.getText().trim();

            if (name.isEmpty() || totalMarks.isEmpty()) {
                JOptionPane.showMessageDialog(frame, "Name and totalMarks are required for update!", 
                    "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }

            String sql = "UPDATE students SET name = ?, totalMarks = ? WHERE rollNo = ?";
            PreparedStatement pstmt = connection.prepareStatement(sql);
            pstmt.setString(1, name);
            pstmt.setInt(2, Integer.parseInt(totalMarks));
            pstmt.setString(3, rollNo);

            int rowsAffected = pstmt.executeUpdate();
            if (rowsAffected > 0) {
                JOptionPane.showMessageDialog(frame, "Record updated successfully!");
            } else {
                JOptionPane.showMessageDialog(frame, "Record not found!", 
                    "Error", JOptionPane.ERROR_MESSAGE);
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, "totalMarks must be a number!", 
                "Error", JOptionPane.ERROR_MESSAGE);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "Error updating record: " + e.getMessage(), 
                "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void searchRecord() {
        String rollNo = JOptionPane.showInputDialog(frame, "Enter Roll Number to search:");
        if (rollNo == null || rollNo.trim().isEmpty()) return;

        try {
            String sql = "SELECT * FROM students WHERE rollNo = ?";
            PreparedStatement pstmt = connection.prepareStatement(sql);
            pstmt.setString(1, rollNo.trim());

            ResultSet rs = pstmt.executeQuery();
            if (rs.next()) {
                rollNoField.setText(rs.getString("rollNo"));
                nameField.setText(rs.getString("name"));
                totalMarksField.setText(rs.getString("totalMarks"));
            } else {
                JOptionPane.showMessageDialog(frame, "Record not found!", 
                    "Not Found", JOptionPane.INFORMATION_MESSAGE);
                clearFields();
            }
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "Error searching record: " + e.getMessage(), 
                "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void clearFields() {
        rollNoField.setText("");
        nameField.setText("");
        totalMarksField.setText("");
    }
}
