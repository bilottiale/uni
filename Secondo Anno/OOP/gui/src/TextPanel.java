import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class TextPanel extends JPanel implements ActionListener {
    private JButton b;
    private JTextField txt1, txt2;

    public TextPanel() {
        super();
        b = new JButton("Aggiorna");
        txt1 = new JTextField("Scrivere qui il testo", 25);
        txt2 = new JTextField(25);
        txt2.setEditable(false);
        b.addActionListener(this);
        
        add(txt1);
        add(txt2);
        add(b);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String s = txt1.getText();
        txt2.setText(s);
    }
}
