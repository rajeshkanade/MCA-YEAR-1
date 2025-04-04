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
