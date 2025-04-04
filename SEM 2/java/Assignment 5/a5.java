import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class a5 {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Font Customization");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(400, 300);
            frame.setLayout(new GridLayout(5, 2));

            JLabel fontFamilyLabel = new JLabel("Font Family:");
            String[] fontFamilies = GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();
            JComboBox<String> fontFamilyComboBox = new JComboBox<>(fontFamilies);

            JLabel fontSizeLabel = new JLabel("Font Size:");
            JTextField fontSizeField = new JTextField("12");

            JLabel fontStyleLabel = new JLabel("Font Style:");
            JCheckBox boldCheckBox = new JCheckBox("Bold");
            JCheckBox italicCheckBox = new JCheckBox("Italic");

            JTextField textField = new JTextField("hello everyone");
            textField.setEditable(false);

            JButton applyButton = new JButton("Apply");
            JButton exitButton = new JButton("Exit");

            frame.add(fontFamilyLabel);
            frame.add(fontFamilyComboBox);
            frame.add(fontSizeLabel);
            frame.add(fontSizeField);
            frame.add(fontStyleLabel);
            frame.add(boldCheckBox);
            frame.add(italicCheckBox);
            frame.add(textField);
            frame.add(applyButton);
            frame.add(exitButton);

            applyButton.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    String fontFamily = (String) fontFamilyComboBox.getSelectedItem();
                    int fontSize = Integer.parseInt(fontSizeField.getText());
                    int fontStyle = Font.PLAIN;
                    if (boldCheckBox.isSelected()) {
                        fontStyle |= Font.BOLD;
                    }
                    if (italicCheckBox.isSelected()) {
                        fontStyle |= Font.ITALIC;
                    }
                    textField.setFont(new Font(fontFamily, fontStyle, fontSize));
                }
            });

            exitButton.addActionListener(e -> System.exit(0));

            frame.setVisible(true);
        });
    }
}
