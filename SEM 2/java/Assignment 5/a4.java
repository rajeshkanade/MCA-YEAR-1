import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class a4 {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Number Conversion");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(400, 300);
            frame.setLayout(new GridLayout(5, 2));

            JLabel decimalLabel = new JLabel("Decimal:");
            JTextField decimalField = new JTextField();
            JLabel binaryLabel = new JLabel("Binary:");
            JTextField binaryField = new JTextField();
            JLabel octalLabel = new JLabel("Octal:");
            JTextField octalField = new JTextField();
            JLabel hexLabel = new JLabel("Hexadecimal:");
            JTextField hexField = new JTextField();

            JButton convertButton = new JButton("Convert");
            JButton exitButton = new JButton("Exit");

            frame.add(decimalLabel);
            frame.add(decimalField);
            frame.add(binaryLabel);
            frame.add(binaryField);
            frame.add(octalLabel);
            frame.add(octalField);
            frame.add(hexLabel);
            frame.add(hexField);
            frame.add(convertButton);
            frame.add(exitButton);

            convertButton.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    try {
                        int decimal = Integer.parseInt(decimalField.getText());
                        binaryField.setText(Integer.toBinaryString(decimal));
                        octalField.setText(Integer.toOctalString(decimal));
                        hexField.setText(Integer.toHexString(decimal).toUpperCase());
                    } catch (NumberFormatException ex) {
                        JOptionPane.showMessageDialog(frame, "Please enter a valid decimal number.", "Input Error", JOptionPane.ERROR_MESSAGE);
                    }
                }
            });

            exitButton.addActionListener(e -> System.exit(0));

            frame.setVisible(true);
        });
    }
}
