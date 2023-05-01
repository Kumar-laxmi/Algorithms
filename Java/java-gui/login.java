

import java.awt.*;
import java.awt.event.*;
import java.awt.event.ActionListener;
// import java.awt.event.WindowListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
// import javax.swing.*;
// import java.util.*;

class myframe extends Frame implements ActionListener {
    Label l1, l2;
    TextField tx1, tx2;
    Button b;
    String status = " ";

    myframe() {

        this.setVisible(true);
        this.setSize(300, 200);
        this.setLocation(550, 250);
        this.setLayout(new FlowLayout());
        this.setTitle("Login Page");
        this.setBackground(Color.lightGray);

        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });

        l1 = new Label("Username:");
        l2 = new Label("Password:");
        tx1 = new TextField(15);
        tx2 = new TextField(15);
        b = new Button("Login");

        b.addActionListener(this);

        add(l1);
        add(tx1);
        add(l2);
        add(tx2);
        add(b);

    }

    public void actionPerformed(ActionEvent ae) {
        String uname = tx1.getText();
        String upass = tx2.getText();
        if (uname.equals("saurabh") && upass.equals("1234")) {
            status = "login success";
        } else {
            status = "login failed";
        }
        repaint();
    }

    public void paint(Graphics g) {
        // super.paint(g);
        Font f = new Font("arial", Font.BOLD, 15);
        g.setFont(f);
        this.setForeground(Color.black);
        g.drawString("status:" + status, 40, 150);
    }

}

public class login {
    public static void main(String[] args) {
        new myframe();

    }
}