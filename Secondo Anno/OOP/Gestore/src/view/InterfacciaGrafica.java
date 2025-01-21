package view;

import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.io.*;
import java.time.LocalTime;
import java.util.*;
import java.util.List;

public class InterfacciaGrafica {
    private JTable tabella;
    private DefaultTableModel tabellaModel;
    private JComboBox<String> dateComboBox;
    private static final String PATH_PRENOTAZIONI = "./src/util/prenotazioni.csv";

    public InterfacciaGrafica() {
        JFrame frame = new JFrame("Occupazione Aule");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);

        // Modello della tabella
        tabellaModel = new DefaultTableModel() {
            @Override
            public boolean isCellEditable(int row, int column) {
                // Solo le celle delle prenotazioni sono modificabili (non la colonna delle ore)
                return column > 0;
            }
        };
        tabella = new JTable(tabellaModel);

        // Renderer personalizzato per la prima colonna (Ore)
        tabella.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
            @Override
            public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
                Component c = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
                if (column == 0) {
                    setHorizontalAlignment(SwingConstants.CENTER); // Centra le ore
                    setBackground(Color.LIGHT_GRAY); // Colore diverso per le ore
                } else {
                    setHorizontalAlignment(SwingConstants.LEFT); // Allinea a sinistra per altre colonne
                    setBackground(Color.WHITE); // Normale sfondo bianco
                }
                return c;
            }
        });

        JScrollPane scrollPane = new JScrollPane(tabella);
        frame.add(scrollPane, BorderLayout.CENTER);

        // Menu a tendina per selezionare le date
        dateComboBox = new JComboBox<>();
        dateComboBox.addActionListener(e -> {
            String giornoSelezionato = (String) dateComboBox.getSelectedItem();
            aggiornaOccupazione(giornoSelezionato);
        });

        // Pannello superiore con il menu a tendina
        JPanel topPanel = new JPanel(new FlowLayout());
        topPanel.add(new JLabel("Seleziona Data:"));
        topPanel.add(dateComboBox);
        frame.add(topPanel, BorderLayout.NORTH);

        // Carica le date disponibili nel menu
        caricaDate();

        // Pannello inferiore con bottone per salvare le modifiche
        JPanel bottomPanel = new JPanel();
        JButton salvaButton = new JButton("Salva Modifiche");
        salvaButton.addActionListener(e -> salvaModifiche());
        bottomPanel.add(salvaButton);
        frame.add(bottomPanel, BorderLayout.SOUTH);

        frame.setVisible(true);
    }

    private void caricaDate() {
        try (BufferedReader br = new BufferedReader(new FileReader(PATH_PRENOTAZIONI))) {
            String linea;
            Set<String> dateSet = new HashSet<>();
            // Salta l'intestazione
            br.readLine();
            // Legge tutte le date uniche
            while ((linea = br.readLine()) != null) {
                String[] dati = linea.split(",");
                if (dati.length < 6) continue;
                String data = dati[1].trim();
                dateSet.add(data);
            }
            // Ordina e aggiunge le date al menu
            List<String> dateList = new ArrayList<>(dateSet);
            dateList.sort(String::compareTo);
            for (String data : dateList) {
                dateComboBox.addItem(data);
            }
            // Seleziona la prima data come default
            if (!dateList.isEmpty()) {
                dateComboBox.setSelectedIndex(0);
                aggiornaOccupazione(dateList.get(0));
            }
        } catch (Exception e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(null, "Errore durante il caricamento delle date.");
        }
    }

    private void aggiornaOccupazione(String giornoSelezionato) {
        try (BufferedReader br = new BufferedReader(new FileReader(PATH_PRENOTAZIONI))) {
            String linea;
            List<String> tutteLeAule = new ArrayList<>();
            // Salta l'intestazione
            br.readLine();
            // Lettura per identificare tutte le aule presenti nel file
            while ((linea = br.readLine()) != null) {
                String[] dati = linea.split(",");
                if (dati.length < 6) continue;
                String aula = dati[0].trim();
                if (!tutteLeAule.contains(aula)) {
                    tutteLeAule.add(aula); // Aggiunge l'aula se non è già presente
                }
            }

            // Se non ci sono aule nel dataset
            if (tutteLeAule.isEmpty()) {
                JOptionPane.showMessageDialog(null, "Nessuna aula trovata nel dataset.");
                tabellaModel.setRowCount(0);
                tabellaModel.setColumnCount(0);
                return;
            }

            // Imposta le colonne della tabella con tutte le aule trovate
            String[] colonne = new String[tutteLeAule.size() + 1];
            colonne[0] = "Ore";
            for (int i = 0; i < tutteLeAule.size(); i++) {
                colonne[i + 1] = tutteLeAule.get(i);
            }
            tabellaModel.setColumnIdentifiers(colonne);
            // Imposta le righe della tabella per le ore del giorno (24 ore)
            tabellaModel.setRowCount(24);

            // Riempie la prima colonna con le ore del giorno
            for (int ora = 0; ora < 24; ora++) {
                tabellaModel.setValueAt(String.format("%02d:00", ora), ora, 0);
            }

            // **Pulisce tutte le celle della tabella (eccetto la colonna Ore)**
            for (int riga = 0; riga < 24; riga++) {
                for (int colonna = 1; colonna < tabellaModel.getColumnCount(); colonna++) {
                    tabellaModel.setValueAt(null, riga, colonna);
                }
            }

            // Riempimento delle prenotazioni per il giorno selezionato
            try (BufferedReader br2 = new BufferedReader(new FileReader(PATH_PRENOTAZIONI))) {
                br2.readLine(); // Salta l'intestazione
                while ((linea = br2.readLine()) != null) {
                    String[] dati = linea.split(",");
                    if (dati.length < 6) continue;
                    String aula = dati[0].trim();
                    String data = dati[1].trim();
                    if (!data.equals(giornoSelezionato)) continue; // Solo per il giorno selezionato
                    LocalTime oraInizio = LocalTime.parse(dati[2].trim());
                    LocalTime oraFine = LocalTime.parse(dati[3].trim());
                    String info = dati[4].trim() + " - " + dati[5].trim();
                    int colonna = tutteLeAule.indexOf(aula) + 1;
                    if (colonna != 0) {
                        for (int ora = oraInizio.getHour(); ora < oraFine.getHour(); ora++) {
                            // Riempie la cella con le informazioni di prenotazione
                            tabellaModel.setValueAt(info, ora, colonna);
                        }
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(null, "Errore durante il caricamento delle prenotazioni.");
        }
    }

    private void salvaModifiche() {
        try {
            // Leggi tutte le righe esistenti nel CSV
            List<String> prenotazioniEsistenti = new ArrayList<>();
            BufferedReader br = new BufferedReader(new FileReader(PATH_PRENOTAZIONI));
            String linea;
            while ((linea = br.readLine()) != null) {
                prenotazioniEsistenti.add(linea);
            }
            br.close();

            // Lista per le nuove righe, includendo l'header
            List<String> nuovePrenotazioni = new ArrayList<>();
            if (!prenotazioniEsistenti.isEmpty()) {
                nuovePrenotazioni.add(prenotazioniEsistenti.get(0)); // L'header è la prima riga
            }

            // Aggiungi le righe modificate o nuove
            for (int row = 0; row < tabellaModel.getRowCount(); row++) {
                for (int col = 1; col < tabellaModel.getColumnCount(); col++) {
                    String prenotazione = (String) tabellaModel.getValueAt(row, col);
                    if (prenotazione != null && !prenotazione.isEmpty()) {
                        String aula = tabellaModel.getColumnName(col);
                        String data = (String) dateComboBox.getSelectedItem();
                        String oraInizio = String.format("%02d:00", row);
                        String oraFine = String.format("%02d:00", row + 1);

                        // Crea una nuova prenotazione
                        String nuovaPrenotazione = aula + "," + data + "," + oraInizio + "," + oraFine + ","
                                + prenotazione.split(" - ")[0] + "," + prenotazione.split(" - ")[1];

                        boolean esistente = false;

                        // Verifica se la prenotazione esiste già nel CSV
                        for (int i = 1; i < prenotazioniEsistenti.size(); i++) {
                            String esistentePrenotazione = prenotazioniEsistenti.get(i);
                            // Se trova una prenotazione con gli stessi dettagli (Aula, Data, Ora Inizio, Ora Fine)
                            if (esistentePrenotazione.split(",")[0].equals(aula) &&
                                    esistentePrenotazione.split(",")[1].equals(data) &&
                                    esistentePrenotazione.split(",")[2].equals(oraInizio) &&
                                    esistentePrenotazione.split(",")[3].equals(oraFine)) {
                                // Aggiorna la riga esistente con la nuova prenotazione
                                nuovePrenotazioni.add(nuovaPrenotazione);
                                esistente = true;
                                break;
                            }
                        }

                        // Se la prenotazione non esiste, aggiungila come nuova
                        if (!esistente) {
                            nuovePrenotazioni.add(nuovaPrenotazione);
                        }
                    }
                }
            }

            // Scrivi tutte le righe nel file CSV (inclusi header e modifiche)
            FileWriter writer = new FileWriter(PATH_PRENOTAZIONI);
            for (String prenotazione : nuovePrenotazioni) {
                writer.write(prenotazione + "\n");
            }
            writer.close();

            JOptionPane.showMessageDialog(null, "Modifiche salvate correttamente!");

        } catch (IOException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(null, "Errore durante il salvataggio delle modifiche.");
        }
    }

}
