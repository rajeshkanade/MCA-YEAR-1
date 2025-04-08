/**
 * Assignment 5 - Question 2
 * 
 * Create a Java Swing application to search student marks by roll number and name.
 * The application should:
 * - Store student data (name, subjects, CE marks, ESE marks) in a HashMap
 * - Provide input fields for roll number and name
 * - Display matching student records in a table with subject-wise marks
 * - Calculate and display total marks (CE + ESE) for each subject
 * 
 * Features:
 * - Uses JFrame with BorderLayout
 * - Input validation for empty fields
 * - JTable to display results
 * - ActionListener for search button
 */
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;
import java.util.HashMap;
import java.util.Map;

class StudentMarksSearch {
    private Map<String, String[][]> studentData;
    private static JTable table;
    private static DefaultTableModel model;

    StudentMarksSearch() {
        studentData = new HashMap<>();
        studentData.put("101", new String[][]{ // Rajesh
            {"Rajesh", "C", "40", "80"},
            {"Rajesh", "Java", "50", "90"},
            {"Rajesh", "Python", "60", "70"},
            {"Rajesh", "DSA", "60", "70"},
            {"Rajesh", "DBMS", "70", "80"},
        });
        studentData.put("102", new String[][]{ // Sujit
            {"Sujit", "C", "30", "70"},
            {"Sujit", "Java", "40", "80"},
            {"Sujit", "Python", "50", "60"},
            {"Sujit", "DSA", "50", "60"},
            {"Sujit", "DBMS", "60", "70"},
        });
        studentData.put("103", new String[][]{ // Shreyash
            {"Shreyash", "C", "35", "75"},
            {"Shreyash", "Java", "45", "85"},
            {"Shreyash", "Python", "55", "65"},
            {"Shreyash", "DSA", "55", "65"},
            {"Shreyash", "DBMS", "65", "75"},
        });
        studentData.put("104", new String[][]{ // Shubham
            {"Shubham", "C", "25", "65"},
            {"Shubham", "Java", "35", "75"},
            {"Shubham", "Python", "45", "55"},
            {"Shubham", "DSA", "45", "55"},
            {"Shubham", "DBMS", "55", "65"},
        });
        studentData.put("105", new String[][]{ // Dhanesh
            {"Dhanesh", "C", "20", "60"},
            {"Dhanesh", "Java", "30", "70"},
            {"Dhanesh", "Python", "40", "50"},
            {"Dhanesh", "DSA", "40", "50"},
            {"Dhanesh", "DBMS", "50", "60"}
        });
    }

    public void createAndShowGUI() {
        JFrame frame = new JFrame("Student Marks Search");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);
        frame.setLayout(new BorderLayout());

        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new FlowLayout());

        JTextField rollNumberField = new JTextField(10);
        JTextField nameField = new JTextField(10);
        JButton searchButton = new JButton("Search");

        inputPanel.add(new JLabel("Roll Number:"));
        inputPanel.add(rollNumberField);
        inputPanel.add(new JLabel("Name:"));
        inputPanel.add(nameField);
        inputPanel.add(searchButton);

        frame.add(inputPanel, BorderLayout.NORTH);

        model = new DefaultTableModel(new String[]{"Subject", "CE Marks", "ESE Marks", "Total Marks"}, 0);
        table = new JTable(model);
        JScrollPane scrollPane = new JScrollPane(table);
        frame.add(scrollPane, BorderLayout.CENTER);

        searchButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String rollNumber = rollNumberField.getText().trim();
                String name = nameField.getText();
                if (rollNumber.isEmpty() || name.isEmpty()) {
                    JOptionPane.showMessageDialog(frame, "Please enter both Roll Number and Name.", "Input Error", JOptionPane.ERROR_MESSAGE);
                    return;
                }
                model.setRowCount(0); // Clear previous results
                for (String key : studentData.keySet()) { // Check roll number
                    if (!rollNumber.isEmpty() && !key.equals(rollNumber)) {
                        continue; // Skip if roll number does not match
                    }
                    for (String[] data : studentData.get(key)) {
                        if (data[0].equalsIgnoreCase(name)) {
                            int ceMarks = Integer.parseInt(data[2]);
                            int eseMarks = Integer.parseInt(data[3]);
                            int totalMarks = ceMarks + eseMarks;
                            model.addRow(new Object[]{data[1], ceMarks, eseMarks, totalMarks});
                        }
                    }
                }
            }
        });

        frame.setVisible(true);
    }
}

public class a2 {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            StudentMarksSearch sms = new StudentMarksSearch();
            sms.createAndShowGUI();
        });
    }
}
