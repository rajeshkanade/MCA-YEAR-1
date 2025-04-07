/**
 * Assignment 6 - Question 1
 * 
 * Create a Java application that connects to a MySQL database and provides:
 * - Database metadata information (name, version, driver info)
 * - Listing of all tables in the database
 * - Detailed column information for any specified table
 * 
 * Features:
 * - Uses JDBC to connect to MySQL database
 * - Implements interactive menu system
 * - Utilizes DatabaseMetaData for schema information
 * - Includes ResultSetMetaData for table details
 * - Proper connection handling and error management
 * 
 * Database Connection Details:
 * - URL: jdbc:mysql://192.168.28.3:3306/RAJESH28
 * - Username: mca28
 * - No password required
 */
import java.sql.*;
import java.util.Scanner;

public class a1 {
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
            
            // Display menu
            while (true) {
                System.out.println("\nMenu:");
                System.out.println("1. Display database information");
                System.out.println("2. List all tables in database");
                System.out.println("3. Display column information for a table");
                System.out.println("4. Exit");
                System.out.print("Enter your choice: ");
                
                int choice = scanner.nextInt();
                scanner.nextLine(); // Consume newline
                
                switch (choice) {
                    case 1:
                        displayDatabaseInfo();
                        break;
                    case 2:
                        listAllTables();
                        break;
                    case 3:
                        displayColumnInfo();
                        break;
                    case 4:
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

    private static void displayDatabaseInfo() throws SQLException {
        DatabaseMetaData metaData = connection.getMetaData();
        
        System.out.println("\nDatabase Information:");
        System.out.println("Database Product Name: " + metaData.getDatabaseProductName());
        System.out.println("Database Product Version: " + metaData.getDatabaseProductVersion());
        System.out.println("Driver Name: " + metaData.getDriverName());
        System.out.println("Driver Version: " + metaData.getDriverVersion());
        System.out.println("URL: " + metaData.getURL());
        System.out.println("User Name: " + metaData.getUserName());
    }

    private static void listAllTables() throws SQLException {
        DatabaseMetaData metaData = connection.getMetaData();
        String catalog = connection.getCatalog();
        
        System.out.println("\nTables in database:");
        ResultSet tables = metaData.getTables(catalog, null, "%", new String[]{"TABLE"});
        
        System.out.printf("%-20s %-20s\n", "TABLE_NAME", "TABLE_TYPE");
        System.out.println("----------------------------------------");
        while (tables.next()) {
            System.out.printf("%-20s %-20s\n", 
                tables.getString("TABLE_NAME"), 
                tables.getString("TABLE_TYPE"));
        }
        tables.close();
    }

    private static void displayColumnInfo() throws SQLException {
        System.out.print("Enter table name: ");
        String tableName = scanner.nextLine();
        
        DatabaseMetaData metaData = connection.getMetaData();
        String catalog = connection.getCatalog();
        
        // Get column information using DatabaseMetaData
        System.out.println("\nColumn Information for table " + tableName + ":");
        ResultSet columns = metaData.getColumns(catalog, null, tableName, "%");
        
        System.out.printf("%-20s %-20s %-10s %-10s\n", 
            "COLUMN_NAME", "TYPE_NAME", "COLUMN_SIZE", "IS_NULLABLE");
        System.out.println("--------------------------------------------------------");
        while (columns.next()) {
            System.out.printf("%-20s %-20s %-10s %-10s\n", 
                columns.getString("COLUMN_NAME"),
                columns.getString("TYPE_NAME"),
                columns.getString("COLUMN_SIZE"),
                columns.getString("IS_NULLABLE"));
        }
        columns.close();
        
        // Additional info using ResultSetMetaData
        System.out.println("\nAdditional column details:");
        try {
            Statement stmt = connection.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM " + tableName + " LIMIT 1");
            ResultSetMetaData rsMetaData = rs.getMetaData();
            
            int columnCount = rsMetaData.getColumnCount();
            System.out.println("Total columns: " + columnCount);
            System.out.printf("%-20s %-20s %-20s\n", "Column", "Display Size", "Nullable");
            System.out.println("--------------------------------------------------------");
            
            for (int i = 1; i <= columnCount; i++) {
                System.out.printf("%-20s %-20s %-20s\n", 
                    rsMetaData.getColumnName(i),
                    rsMetaData.getColumnDisplaySize(i),
                    rsMetaData.isNullable(i) == ResultSetMetaData.columnNullable ? "YES" : "NO");
            }
            
            rs.close();
            stmt.close();
        } catch (SQLException e) {
            System.err.println("Error getting ResultSetMetaData: " + e.getMessage());
        }
    }
}
