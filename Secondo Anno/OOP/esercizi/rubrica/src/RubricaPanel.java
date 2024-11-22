import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class RubricaPanel extends JPanel {
  private JTextField ricercaField;
  private JLabel risultatoLabel;

  public RubricaPanel(Contatto[] contatti) {
    setLayout(new BorderLayout());

    // Crea il modello dei dati
    RubricaTableModel tableModel = new RubricaTableModel(contatti);

    // Crea la tabella e la aggiunge a uno scroll pane
    JTable table = new JTable(tableModel);
    JScrollPane scrollPane = new JScrollPane(table);

    // Pannello per la ricerca
    JPanel ricercaPanel = new JPanel(new FlowLayout());
    ricercaField = new JTextField(20);
    JButton ricercaButton = new JButton("Cerca");
    risultatoLabel = new JLabel("Risultato: ");
    ricercaPanel.add(new JLabel("Cerca per nome o cognome:"));
    ricercaPanel.add(ricercaField);
    ricercaPanel.add(ricercaButton);
    ricercaPanel.add(risultatoLabel);

    // Aggiungi la tabella e il pannello di ricerca al pannello principale
    add(scrollPane, BorderLayout.CENTER);
    add(ricercaPanel, BorderLayout.SOUTH);

    // Listener per il pulsante di ricerca
    ricercaButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        String testoRicerca = ricercaField.getText().trim();
        Contatto risultato = cercaContatto(contatti, testoRicerca);

        if (risultato != null) {
          risultatoLabel.setText("Risultato: " + risultato.getNome() + " " + risultato.getCognome() +
              ", " + risultato.getIndirizzo() + ", " + risultato.getTelefono());
        } else {
          risultatoLabel.setText("Risultato: Nessun contatto trovato.");
        }
      }
    });
  }

  // Metodo per cercare un contatto in base a una parte del nome o cognome
  private Contatto cercaContatto(Contatto[] contatti, String testo) {
    for (Contatto contatto : contatti) {
      if (contatto.getNome().toLowerCase().contains(testo.toLowerCase()) ||
          contatto.getCognome().toLowerCase().contains(testo.toLowerCase())) {
        return contatto;
      }
    }
    return null;
  }
}
