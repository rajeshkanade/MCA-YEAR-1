import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class a4 {
    private Connection connection;
    private Statement statement;
    private ResultSet resultSet;
    private int currentRecord = 0;
    private int totalRecords = 0;

    private JFrame frame;
    private JTextField rollNoField, nameField, marksField, recordCounterField;
    private JButton firstButton, prevButton, nextButton, lastButton;

    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            try {
                a4 window = new a4();
                window.frame.setVisible(true);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    public a4() {
        initialize();
        connectToDatabase();
        loadRecords();
        showRecord(currentRecord);
    }

    private void initialize() {
        frame = new JFrame("Student Records");
        frame.setBounds(100, 100, 450, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);

        JLabel lblRollNo = new JLabel("Roll Number:");
        lblRollNo.setBounds(30, 30, 100, 20);
        frame.getContentPane().add(lblRollNo);

        rollNoField = new JTextField();
        rollNoField.setBounds(140, 30, 200, 20);
        rollNoField.setEditable(false);
        frame.getContentPane().add(rollNoField);
        rollNoField.setColumns(10);

        JLabel lblName = new JLabel("Name:");
        lblName.setBounds(30, 60, 100, 20);
        frame.getContentPane().add(lblName);

        nameField = new JTextField();
        nameField.setBounds(140, 60, 200, 20);
        nameField.setEditable(false);
        frame.getContentPane().add(nameField);
        nameField.setColumns(10);

        JLabel lblMarks = new JLabel("Total Marks:");
        lblMarks.setBounds(30, 90, 100, 20);
        frame.getContentPane().add(lblMarks);

        marksField = new JTextField();
        marksField.setBounds(140, 90, 200, 20);
        marksField.setEditable(false);
        frame.getContentPane().add(marksField);
        marksField.setColumns(10);

        recordCounterField = new JTextField();
        recordCounterField.setBounds(180, 130, 80, 20);
        recordCounterField.setHorizontalAlignment(JTextField.CENTER);
        recordCounterField.setEditable(false);
        frame.getContentPane().add(recordCounterField);

        firstButton = new JButton("<<");
        firstButton.setBounds(30, 170, 80, 30);
        firstButton.addActionListener(e -> showFirstRecord());
        frame.getContentPane().add(firstButton);

        prevButton = new JButton("<");
        prevButton.setBounds(120, 170, 80, 30);
        prevButton.addActionListener(e -> showPreviousRecord());
        frame.getContentPane().add(prevButton);

        nextButton = new JButton(">");
        nextButton.setBounds(210, 170, 80, 30);
        nextButton.addActionListener(e -> showNextRecord());
        frame.getContentPane().add(nextButton);

        lastButton = new JButton(">>");
        lastButton.setBounds(300, 170, 80, 30);
        lastButton.addActionListener(e -> showLastRecord());
        frame.getContentPane().add(lastButton);
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
            statement = connection.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(frame, "Database connection failed: " + e.getMessage(), 
                "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }
    }

    private void loadRecords() {
        try {
            resultSet = statement.executeQuery("SELECT * FROM students");
            
            // Get total records
            resultSet.last();
            totalRecords = resultSet.getRow();
            resultSet.beforeFirst();
            
            updateRecordCounter();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "Error loading records: " + e.getMessage(), 
                "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void showRecord(int index) {
        try {
            if (totalRecords == 0) {
                clearFields();
                return;
            }

            resultSet.absolute(index + 1);
            rollNoField.setText(resultSet.getString("rollNo"));
            nameField.setText(resultSet.getString("name"));
            marksField.setText(resultSet.getString("totalMarks"));
            
            currentRecord = index;
            updateRecordCounter();
            updateButtonStates();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "Error displaying record: " + e.getMessage(), 
                "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void showFirstRecord() {
        showRecord(0);
    }

    private void showLastRecord() {
        showRecord(totalRecords - 1);
    }

    private void showNextRecord() {
        if (currentRecord < totalRecords - 1) {
            showRecord(currentRecord + 1);
        }
    }

    private void showPreviousRecord() {
        if (currentRecord > 0) {
            showRecord(currentRecord - 1);
        }
    }

    private void updateRecordCounter() {
        recordCounterField.setText((totalRecords == 0) ? "0/0" : (currentRecord + 1) + "/" + totalRecords);
    }

    private void updateButtonStates() {
        firstButton.setEnabled(currentRecord > 0);
        prevButton.setEnabled(currentRecord > 0);
        nextButton.setEnabled(currentRecord < totalRecords - 1);
        lastButton.setEnabled(currentRecord < totalRecords - 1);
    }

    private void clearFields() {
        rollNoField.setText("");
        nameField.setText("");
        marksField.setText("");
    }
}
