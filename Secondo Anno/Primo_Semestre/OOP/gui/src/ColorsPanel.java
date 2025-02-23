import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ColorsPanel extends JPanel implements ActionListener {
    private JButton b1, b2;

    public ColorsPanel() {
        super();
        b1 = new JButton("Rosso");
        b2 = new JButton("Azzurro");
        b1.addActionListener(this);
        b2.addActionListener(this);
        // il pannello fa da ascoltatore degli
        // eventi per entrambi i pulsanti
        add(b1);
        add(b2);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String nome = e.getActionCommand();
        if (nome.equals("Rosso"))
            setBackground(Color.red);
        else
            setBackground(Color.blue);
    }
}
