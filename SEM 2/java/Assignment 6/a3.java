import java.sql.*;
import java.util.Scanner;

public class a3 {
    private static Connection connection;

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
            
            
            // Create book table
            createBookTable();
            
            // Insert sample records
            insertSampleRecords();
            
            System.out.println("Book table created and populated with 5 records successfully!");
            
            connection.close();
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private static void createBookTable() throws SQLException {
        String sql = "CREATE TABLE IF NOT EXISTS books (" +
                     "id INT AUTO_INCREMENT PRIMARY KEY," +
                     "book_name VARCHAR(100) NOT NULL," +
                     "author VARCHAR(100) NOT NULL," +
                     "ISBN_no VARCHAR(20) UNIQUE NOT NULL," +
                     "price DECIMAL(10,2) NOT NULL)";
        
        try (Statement stmt = connection.createStatement()) {
            stmt.execute(sql);
            System.out.println("Book table created/verified successfully");
        }
    }

    private static void insertSampleRecords() throws SQLException {
        // Sample book data
        String[][] books = {
            {"The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", "12.99"},
            {"To Kill a Mockingbird", "Harper Lee", "9780061120084", "10.50"},
            {"1984", "George Orwell", "9780451524935", "9.99"},
            {"Pride and Prejudice", "Jane Austen", "9780141439518", "8.75"},
            {"The Hobbit", "J.R.R. Tolkien", "9780547928227", "14.25"}
        };
        
        String sql = "INSERT INTO books (book_name, author, ISBN_no, price) VALUES (?, ?, ?, ?)";
        
        try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
            // Insert each book
            for (String[] book : books) {
                pstmt.setString(1, book[0]);
                pstmt.setString(2, book[1]);
                pstmt.setString(3, book[2]);
                pstmt.setBigDecimal(4, new java.math.BigDecimal(book[3]));
                
                try {
                    pstmt.executeUpdate();
                } catch (SQLException e) {
                    System.err.println("Error inserting book: " + book[0] + " - " + e.getMessage());
                }
            }
            System.out.println("Inserted " + books.length + " sample records");
        }
    }
}
