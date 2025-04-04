// design a login screen having username and password filed  and also submit and cancel button

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class loginScreen{

    loginScreen(){
    JFrame frame = new JFrame("Login Screen");
    frame.setSize(200,200);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setLayout(new GridLayout(3,4));

    JLabel userLabel = new JLabel("Username : ");
    JTextField userTextField = new JTextField();
    JLabel passLabel = new JLabel("Password : ");
    JTextField passTextField = new JTextField();

    JButton submitBtn = new JButton("Submit");
    JButton cancelBtn = new JButton("Cancel");

    frame.add(userLabel);
    frame.add(userTextField);
    frame.add(passLabel);
    frame.add(passTextField);
    frame.add(submitBtn);
    frame.add(cancelBtn);

    submitBtn.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e){
            String username = userTextField.getText();
            String password = passTextField.getText();

            if(username.equals(password)){
                JOptionPane.showMessageDialog(frame , "Correct Login Details");
            }else{
                JOptionPane.showMessageDialog(frame, "Wrong Login Details ");
            }
        }
    });

    cancelBtn.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            userTextField.setText("");
            passTextField.setText("");
        }
    });

    frame.setVisible(true);
    }

}
public class a1{
    public static void main(String args[]){
        
        loginScreen l1 = new loginScreen();

    }
}