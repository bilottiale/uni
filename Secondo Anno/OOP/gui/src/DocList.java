import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.event.DocumentListener;

public class DocList extends JPanel implements DocumentListener {
    private JTextField txt1, txt2;

    public DocList() {
        super();
        txt1 = new JTextField("Il testo si aggiorna automaticamente!", 25);
        txt2 = new JTextField(25);
        txt2.setEditable(false);
        txt1.getDocument().addDocumentListener(this);

        add(txt1);
        add(txt2);
    }

    @Override
    public void insertUpdate(javax.swing.event.DocumentEvent e) {
        txt2.setText(txt1.getText());
    }

    @Override
    public void removeUpdate(javax.swing.event.DocumentEvent e) {
        txt2.setText(txt1.getText());
    }

    @Override
    public void changedUpdate(javax.swing.event.DocumentEvent e) {
        txt2.setText(txt1.getText());
    }
}
