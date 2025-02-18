package view;

import java.awt.*;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.List;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import model.Prenotazione;
import utils.PrenotazioneUtils;

public class FinestraPrenotazioni {

    private JFrame frame;

    public FinestraPrenotazioni(List<Prenotazione> prenotazioni) {
        // Impostazione della finestra
        frame = new JFrame("Tabella Prenotazioni");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);

        // Creazione della tabella
        String[] columnNames = { "Aula", "Data", "Ora Inizio", "Ora Fine", "Nome", "Motivazione" };
        DefaultTableModel model = new DefaultTableModel(columnNames, 0);
        JTable table = new JTable(model);

        // Aggiunta delle righe alla tabella
        for (Prenotazione p : prenotazioni) {
            Object[] row = {
                    p.getnAula(),
                    p.getData().toString(),
                    p.getInizio().toString(),
                    p.getFine().toString(),
                    p.getNome(),
                    p.getMotivazione()
            };
            model.addRow(row);
        }

        JButton salvaButton = new JButton("Salva");
        salvaButton.addActionListener(e -> {
            // Ottieni la riga selezionata
            int selectedRow = table.getSelectedRow();
            if (selectedRow == -1) {
                JOptionPane.showMessageDialog(frame, "Seleziona una prenotazione da modificare.");
                return;
            }

            // Ottieni i dati dalla riga selezionata
            int numeroAula = (int) table.getValueAt(selectedRow, 0);
            LocalDate data = LocalDate.parse((String) table.getValueAt(selectedRow, 1));
            LocalTime oraInizio = LocalTime.parse((String) table.getValueAt(selectedRow, 2));
            LocalTime oraFine = LocalTime.parse((String) table.getValueAt(selectedRow, 3));
            String nome = (String) table.getValueAt(selectedRow, 4);
            String motivazione = (String) table.getValueAt(selectedRow, 5);

            // Chiedi i nuovi dati
            String nuovoNome = JOptionPane.showInputDialog(frame, "Nuovo Nome:", nome);
            String nuovaMotivazione = JOptionPane.showInputDialog(frame, "Nuova Motivazione:", motivazione);

            // Aggiorna la prenotazione
            PrenotazioneUtils.aggiornaPrenotazione(prenotazioni, numeroAula, data, oraInizio, oraFine, nuovoNome,
                    nuovaMotivazione);

            // Salva le prenotazioni aggiornate nel file
            PrenotazioneUtils.salvaPrenotazioni("data/prenotazioni.json", prenotazioni);
            JOptionPane.showMessageDialog(frame, "Prenotazione aggiornata e salvata con successo!");
        });

        // Aggiunta della tabella allo scroll panel per gestire la visualizzazione
        JScrollPane scrollPane = new JScrollPane(table);
        frame.getContentPane().add(scrollPane, BorderLayout.CENTER);

        // Impostazione visibilità della finestra
        frame.setVisible(true);
    }
}
