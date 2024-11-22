import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MyPanel extends JPanel implements ActionListener {
    private JLabel l1; // Dichiarazione dell'etichetta

    public MyPanel() {
        super();
        l1 = new JLabel("ETICHETTA"); // Inizializzo l'etichetta
        add(l1); // Aggiungo l'etichetta al pannello

        JButton b = new JButton("Pulsante"); // Creazione del pulsante
        JButton b1 = new JButton("Pulsante"); // Creazione del pulsante
        b.addActionListener(this); // Aggiunta dell'ascoltatore
        b1.addActionListener(new Listener(l1));
        add(b); // Aggiungo il pulsante al pannello
        add(b1); // Aggiungo il pulsante al pannello
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);

        g.setColor(Color.red); // Imposto il colore rosso
        g.fillRect(20, 20, 100, 80); // Rettangolo pieno

        g.setColor(Color.blue); // Cambio colore a blu
        g.drawRect(30, 30, 80, 60); // Rettangolo vuoto

        g.setColor(Color.black); // Cambio colore a nero
        g.drawString("ciao", 50, 60); // Disegno una stringa
    }

    public void actionPerformed(ActionEvent e) {
        // Modifico il testo dell'etichetta quando il pulsante viene premuto
        if (l1.getText().equals("ETICHETTA")) {
            l1.setText("CIAO");
        } else {
            l1.setText("ETICHETTA");
        }
    }
}
