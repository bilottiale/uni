import java.awt.event.*;
import javax.swing.*;

public class Listener implements ActionListener {

    private JLabel l;

    public Listener(JLabel label) {
        l = label;
    }

    // deve farsi dare come parametro la JLabel su
    // cui dovrà andare ad agire
    public void actionPerformed(ActionEvent e) {
        if (l.getText().equals("Tizio"))
            l.setText("Caio");
        else
            l.setText("Tizio");
    }
}