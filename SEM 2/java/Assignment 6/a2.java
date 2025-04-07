/**
 * Assignment 6 - Question 2
 * 
 * Create a Java application for Student/Alumni Management System that:
 * - Connects to MySQL database (RAJESH28)
 * - Provides CRUD operations (Create, Read, Update, Delete)
 * - Includes input validation for all fields
 * - Implements search functionality with multiple criteria
 * 
 * Features:
 * - Interactive menu-driven interface
 * - Dynamic SQL query generation for updates
 * - Comprehensive field validation (name, email, contact, etc.)
 * - Table creation if not exists
 * - Proper error handling and user feedback
 * 
 * Database Schema:
 * - Table: student_alumni
 * - Fields: id, name, address, designation, contact_no, email, year
 * 
 * Connection Details:
 * - URL: jdbc:mysql://192.168.28.3:3306/RAJESH28
 * - Username: mca28
 * - No password required
 */
import java.sql.*;
import java.util.Scanner;
import java.util.regex.*;

public class a2 {
    private static Connection connection;
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        try {
            // Load MySQL JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");
            
            // Establish connection
            String url = "jdbc:mysql://192.168.28.3:3306/RAJESH28";
            String username = "mca28";
            String password = "";
            
            connection = DriverManager.getConnection(url, username, password);
            System.out.println("Connected to database successfully!");
            
            // Create table if not exists
            createTableIfNotExists();
            
            // Display menu
            while (true) {
                System.out.println("\nStudent/Alumni Management System");
                System.out.println("1. Add Record");
                System.out.println("2. Delete Record");
                System.out.println("3. Update Record");
                System.out.println("4. Search Records");
                System.out.println("5. Exit");
                System.out.print("Enter your choice: ");
                
                int choice = scanner.nextInt();
                scanner.nextLine(); // Consume newline
                
                switch (choice) {
                    case 1:
                        addRecord();
                        break;
                    case 2:
                        deleteRecord();
                        break;
                    case 3:
                        updateRecord();
                        break;
                    case 4:
                        searchRecords();
                        break;
                    case 5:
                        System.out.println("Exiting program...");
                        connection.close();
                        return;
                    default:
                        System.out.println("Invalid choice! Try again.");
                }
            }
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private static void createTableIfNotExists() throws SQLException {
        String sql = "CREATE TABLE IF NOT EXISTS student_alumni (" +
                     "id INT AUTO_INCREMENT PRIMARY KEY," +
                     "name VARCHAR(100) NOT NULL," +
                     "address VARCHAR(200) NOT NULL," +
                     "designation VARCHAR(100) NOT NULL," +
                     "contact_no VARCHAR(15) NOT NULL," +
                     "email VARCHAR(100) NOT NULL," +
                     "year INT NOT NULL)";
        
        try (Statement stmt = connection.createStatement()) {
            stmt.execute(sql);
        }
    }

    private static void addRecord() {
        try {
            System.out.println("\nAdd New Student/Alumni Record");
            
            System.out.print("Enter Name: ");
            String name = scanner.nextLine();
            validateName(name);
            
            System.out.print("Enter Address: ");
            String address = scanner.nextLine();
            validateAddress(address);
            
            System.out.print("Enter Designation: ");
            String designation = scanner.nextLine();
            validateDesignation(designation);
            
            System.out.print("Enter Contact Number: ");
            String contactNo = scanner.nextLine();
            validateContactNo(contactNo);
            
            System.out.print("Enter Email: ");
            String email = scanner.nextLine();
            validateEmail(email);
            
            System.out.print("Enter Year: ");
            int year = Integer.parseInt(scanner.nextLine());
            validateYear(year);
            
            String sql = "INSERT INTO student_alumni (name, address, designation, contact_no, email, year) " +
                         "VALUES (?, ?, ?, ?, ?, ?)";
            
            try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
                pstmt.setString(1, name);
                pstmt.setString(2, address);
                pstmt.setString(3, designation);
                pstmt.setString(4, contactNo);
                pstmt.setString(5, email);
                pstmt.setInt(6, year);
                
                int rowsAffected = pstmt.executeUpdate();
                System.out.println(rowsAffected + " record(s) added successfully!");
            }
        } catch (Exception e) {
            System.err.println("Error adding record: " + e.getMessage());
        }
    }

    private static void deleteRecord() {
        try {
            System.out.println("\nDelete Student/Alumni Record");
            System.out.print("Enter ID of record to delete: ");
            int id = Integer.parseInt(scanner.nextLine());
            
            String sql = "DELETE FROM student_alumni WHERE id = ?";
            
            try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
                pstmt.setInt(1, id);
                
                int rowsAffected = pstmt.executeUpdate();
                if (rowsAffected > 0) {
                    System.out.println(rowsAffected + " record(s) deleted successfully!");
                } else {
                    System.out.println("No record found with ID: " + id);
                }
            }
        } catch (Exception e) {
            System.err.println("Error deleting record: " + e.getMessage());
        }
    }

    private static void updateRecord() {
        try {
            System.out.println("\nUpdate Student/Alumni Record");
            System.out.print("Enter ID of record to update: ");
            int id = Integer.parseInt(scanner.nextLine());
            
            // First check if record exists
            String checkSql = "SELECT * FROM student_alumni WHERE id = ?";
            try (PreparedStatement checkStmt = connection.prepareStatement(checkSql)) {
                checkStmt.setInt(1, id);
                ResultSet rs = checkStmt.executeQuery();
                
                if (!rs.next()) {
                    System.out.println("No record found with ID: " + id);
                    return;
                }
            }
            
            System.out.println("Enter new values (leave blank to keep current value):");
            
            System.out.print("Name: ");
            String name = scanner.nextLine();
            if (!name.isEmpty()) validateName(name);
            
            System.out.print("Address: ");
            String address = scanner.nextLine();
            if (!address.isEmpty()) validateAddress(address);
            
            System.out.print("Designation: ");
            String designation = scanner.nextLine();
            if (!designation.isEmpty()) validateDesignation(designation);
            
            System.out.print("Contact Number: ");
            String contactNo = scanner.nextLine();
            if (!contactNo.isEmpty()) validateContactNo(contactNo);
            
            System.out.print("Email: ");
            String email = scanner.nextLine();
            if (!email.isEmpty()) validateEmail(email);
            
            System.out.print("Year: ");
            String yearStr = scanner.nextLine();
            Integer year = yearStr.isEmpty() ? null : Integer.parseInt(yearStr);
            if (year != null) validateYear(year);
            
            // Build dynamic update query
            StringBuilder sql = new StringBuilder("UPDATE student_alumni SET ");
            boolean needsComma = false;
            
            if (!name.isEmpty()) {
                sql.append("name = ?");
                needsComma = true;
            }
            if (!address.isEmpty()) {
                if (needsComma) sql.append(", ");
                sql.append("address = ?");
                needsComma = true;
            }
            if (!designation.isEmpty()) {
                if (needsComma) sql.append(", ");
                sql.append("designation = ?");
                needsComma = true;
            }
            if (!contactNo.isEmpty()) {
                if (needsComma) sql.append(", ");
                sql.append("contact_no = ?");
                needsComma = true;
            }
            if (!email.isEmpty()) {
                if (needsComma) sql.append(", ");
                sql.append("email = ?");
                needsComma = true;
            }
            if (year != null) {
                if (needsComma) sql.append(", ");
                sql.append("year = ?");
            }
            
            sql.append(" WHERE id = ?");
            
            try (PreparedStatement pstmt = connection.prepareStatement(sql.toString())) {
                int paramIndex = 1;
                
                if (!name.isEmpty()) pstmt.setString(paramIndex++, name);
                if (!address.isEmpty()) pstmt.setString(paramIndex++, address);
                if (!designation.isEmpty()) pstmt.setString(paramIndex++, designation);
                if (!contactNo.isEmpty()) pstmt.setString(paramIndex++, contactNo);
                if (!email.isEmpty()) pstmt.setString(paramIndex++, email);
                if (year != null) pstmt.setInt(paramIndex++, year);
                
                pstmt.setInt(paramIndex, id);
                
                int rowsAffected = pstmt.executeUpdate();
                System.out.println(rowsAffected + " record(s) updated successfully!");
            }
        } catch (Exception e) {
            System.err.println("Error updating record: " + e.getMessage());
        }
    }

    private static void searchRecords() {
        try {
            System.out.println("\nSearch Student/Alumni Records");
            System.out.println("1. Search by ID");
            System.out.println("2. Search by Name");
            System.out.println("3. Search by Year");
            System.out.println("4. View All Records");
            System.out.print("Enter your choice: ");
            
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline
            
            String sql;
            PreparedStatement pstmt;
            
            switch (choice) {
                case 1:
                    System.out.print("Enter ID: ");
                    int id = Integer.parseInt(scanner.nextLine());
                    sql = "SELECT * FROM student_alumni WHERE id = ?";
                    pstmt = connection.prepareStatement(sql);
                    pstmt.setInt(1, id);
                    break;
                case 2:
                    System.out.print("Enter Name (partial match): ");
                    String name = scanner.nextLine();
                    sql = "SELECT * FROM student_alumni WHERE name LIKE ?";
                    pstmt = connection.prepareStatement(sql);
                    pstmt.setString(1, "%" + name + "%");
                    break;
                case 3:
                    System.out.print("Enter Year: ");
                    int year = Integer.parseInt(scanner.nextLine());
                    sql = "SELECT * FROM student_alumni WHERE year = ?";
                    pstmt = connection.prepareStatement(sql);
                    pstmt.setInt(1, year);
                    break;
                case 4:
                    sql = "SELECT * FROM student_alumni";
                    pstmt = connection.prepareStatement(sql);
                    break;
                default:
                    System.out.println("Invalid choice!");
                    return;
            }
            
            ResultSet rs = pstmt.executeQuery();
            
            System.out.printf("\n%-5s %-20s %-20s %-15s %-15s %-25s %-5s\n", 
                "ID", "Name", "Address", "Designation", "Contact No", "Email", "Year");
            System.out.println("--------------------------------------------------------------------------------------------------");
            
            boolean found = false;
            while (rs.next()) {
                found = true;
                System.out.printf("%-5d %-20s %-20s %-15s %-15s %-25s %-5d\n",
                    rs.getInt("id"),
                    rs.getString("name"),
                    rs.getString("address"),
                    rs.getString("designation"),
                    rs.getString("contact_no"),
                    rs.getString("email"),
                    rs.getInt("year"));
            }
            
            if (!found) {
                System.out.println("No records found matching your criteria.");
            }
            
            rs.close();
            pstmt.close();
        } catch (Exception e) {
            System.err.println("Error searching records: " + e.getMessage());
        }
    }

    // Validation methods
    private static void validateName(String name) throws Exception {
        if (name == null || name.trim().isEmpty()) {
            throw new Exception("Name cannot be empty");
        }
        if (!name.matches("^[a-zA-Z\\s]+$")) {
            throw new Exception("Name can only contain letters and spaces");
        }
    }

    private static void validateAddress(String address) throws Exception {
        if (address == null || address.trim().isEmpty()) {
            throw new Exception("Address cannot be empty");
        }
    }

    private static void validateDesignation(String designation) throws Exception {
        if (designation == null || designation.trim().isEmpty()) {
            throw new Exception("Designation cannot be empty");
        }
    }

    private static void validateContactNo(String contactNo) throws Exception {
        if (contactNo == null || contactNo.trim().isEmpty()) {
            throw new Exception("Contact number cannot be empty");
        }
        if (!contactNo.matches("^[0-9]{10,15}$")) {
            throw new Exception("Contact number must be 10-15 digits");
        }
    }

    private static void validateEmail(String email) throws Exception {
        if (email == null || email.trim().isEmpty()) {
            throw new Exception("Email cannot be empty");
        }
        String emailRegex = "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$";
        if (!Pattern.matches(emailRegex, email)) {
            throw new Exception("Invalid email format");
        }
    }

    private static void validateYear(int year) throws Exception {
        if (year < 1900 || year > 2100) {
            throw new Exception("Year must be between 1900 and 2100");
        }
    }
}
