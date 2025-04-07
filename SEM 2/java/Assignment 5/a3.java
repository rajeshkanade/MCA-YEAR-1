/**
 * Assignment 5 - Question 3
 * 
 * Create a Java Swing application to display all available font families on the system.
 * The application should:
 * - Use GraphicsEnvironment to get available font families
 * - Display the fonts in a scrollable JTextArea
 * - Show the fonts in a JFrame window
 * 
 * Features:
 * - Uses JFrame with BorderLayout
 * - Non-editable JTextArea for display
 * - JScrollPane for scrolling through fonts
 * - SwingUtilities.invokeLater for thread safety
 */
import javax.swing.*;
import java.awt.*;
import java.awt.GraphicsEnvironment;

class FontDisplay {
    public void createAndShowGUI() {
        JFrame frame = new JFrame("Available Font Families");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        
        JTextArea textArea = new JTextArea();
        textArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(textArea);
        frame.add(scrollPane, BorderLayout.CENTER);
        
        // Retrieve available font families
        String[] fontFamilies = GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();
        for (String font : fontFamilies) {
            textArea.append(font + "\n");
        }
        
        frame.setVisible(true);
    }
}

public class a3 {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            FontDisplay fontDisplay = new FontDisplay();
            fontDisplay.createAndShowGUI();
        });
    }
}
