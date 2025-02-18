package view;

import model.Prenotazione;
import model.Aula;
import utils.JsonUtils;

import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class MainView extends JFrame {
    private JTable table;
    private JComboBox<String> dateSelector;
    private List<Aula> aule;
    private List<Prenotazione> prenotazioni;

    public MainView() {
        setTitle("Gestione Prenotazioni Aule");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        aule = JsonUtils.leggiAuleDaJson("data/aule.json");
        prenotazioni = JsonUtils.leggiPrenotazioniDaJson("data/prenotazioni.json");

        dateSelector = new JComboBox<>(getDateOptions());
        dateSelector.addActionListener(e -> updateTable());
        add(dateSelector, BorderLayout.NORTH);

        table = new JTable();
        JScrollPane scrollPane = new JScrollPane(table);
        add(scrollPane, BorderLayout.CENTER);

        setupTableClickListener(); // Attiva il doppio clic sulle celle

        updateTable();
        setVisible(true);
    }

    private String[] getDateOptions() {
        return prenotazioni.stream()
                .map(p -> p.getData().toString()) // Convertiamo LocalDate in String
                .distinct()
                .sorted()
                .toArray(String[]::new); // Ora il tipo è corretto
    }

    private void updateTable() {
        String selectedDateStr = (String) dateSelector.getSelectedItem();
        LocalDate selectedDate = LocalDate.parse(selectedDateStr); // Converti in LocalDate
        DefaultTableModel model = new DefaultTableModel();

        model.addColumn("Ora");
        for (Aula aula : aule) {
            model.addColumn("Aula " + aula.getNumeroAula());
        }

        for (int hour = 8; hour <= 18; hour++) {
            Object[] row = new Object[aule.size() + 1];
            row[0] = hour + ":00";

            for (int j = 0; j < aule.size(); j++) {
                Aula aula = aule.get(j);
                row[j + 1] = getPrenotazioneInfo(aula, hour, selectedDate);
            }
            model.addRow(row);
        }

        table.setModel(model);
        table.setDefaultRenderer(Object.class, new CellRenderer());
    }

    private String getPrenotazioneInfo(Aula aula, int hour, LocalDate date) {
        for (Prenotazione p : prenotazioni) {
            if (p.getAula().getNumeroAula() == aula.getNumeroAula()
                    && p.getData().equals(date)
                    && p.getOraInizio().getHour() <= hour
                    && p.getOraFine().getHour() > hour) {
                return p.getDescrizione();
            }
        }
        return "";
    }

    private static class CellRenderer extends DefaultTableCellRenderer {
        @Override
        public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
            Component cell = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
            if (value != null && !value.toString().isEmpty()) {
                cell.setBackground(Color.GREEN);
                setText(value.toString());
            } else {
                cell.setBackground(Color.WHITE);
            }
            return cell;
        }
    }

    private void handleCellEdit(int row, int col) {
        String selectedDate = (String) dateSelector.getSelectedItem();
        LocalTime oraInizio = LocalTime.of(8 + row, 0); // Converte l'ora in LocalTime
        Aula selectedAula = aule.get(col - 1); // Colonne corrispondono alle aule

        // Cerchiamo una prenotazione esistente per quell'aula, ora e data
        Prenotazione existing = prenotazioni.stream()
                .filter(p -> p.getAula().getNumeroAula() == selectedAula.getNumeroAula() &&
                        p.getData().equals(selectedDate) &&
                        (p.getOraInizio().equals(oraInizio) ||
                                (p.getOraInizio().isBefore(oraInizio) && p.getOraFine().isAfter(oraInizio))))
                .findFirst()
                .orElse(null);

        // Apriamo la finestra di dialogo per inserire/modificare
        Prenotazione newPrenotazione = showPrenotazioneDialog(selectedAula, oraInizio, existing);

        if (newPrenotazione != null) {
            if (existing != null) {
                prenotazioni.remove(existing); // Rimuoviamo la prenotazione esistente
            }
            prenotazioni.add(newPrenotazione); // Aggiungiamo la nuova prenotazione
            updateTable(); // Aggiorniamo la tabella
        }
    }

    private void setupTableClickListener() {
        table.addMouseListener(new java.awt.event.MouseAdapter() {
            @Override
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                if (evt.getClickCount() == 2) { // Doppio clic
                    int row = table.getSelectedRow();
                    int col = table.getSelectedColumn();
                    if (row > 0 && col > 0) { // Evitiamo intestazioni
                        handleCellEdit(row, col);
                    }
                }
            }
        });
    }

    private Prenotazione showPrenotazioneDialog(Aula aula, LocalTime oraInizio, Prenotazione existing) {
        // Creiamo i campi
        JTextField nomeField = new JTextField(existing != null ? existing.getDescrizione() : "");
        JTextField motivazioneField = new JTextField(existing != null ? existing.getMotivazione() : "");
        JComboBox<String> aulaComboBox = new JComboBox<>(aule.stream().map(a -> "Aula " + a.getNumeroAula()).toArray(String[]::new));
        aulaComboBox.setSelectedIndex(aule.indexOf(aula)); // Selezioniamo l'aula esistente
        JSpinner oraFineSpinner = new JSpinner(new SpinnerNumberModel(oraInizio.getHour() + 1, oraInizio.getHour() + 1, 18, 1));

        // Se esiste una prenotazione, impostiamo anche il campo dell'orario di fine
        if (existing != null) {
            oraFineSpinner.setValue(existing.getOraFine().getHour());
        }

        JPanel panel = new JPanel(new GridLayout(5, 2));
        panel.add(new JLabel("Nome:"));
        panel.add(nomeField);
        panel.add(new JLabel("Data:"));
        panel.add(new JLabel((String) dateSelector.getSelectedItem())); // Mostra la data
        panel.add(new JLabel("Orario Inizio:"));
        panel.add(new JLabel(oraInizio.toString())); // Mostra l'orario di inizio
        panel.add(new JLabel("Ora Fine:"));
        panel.add(oraFineSpinner);
        panel.add(new JLabel("Motivazione:"));
        panel.add(motivazioneField);
        panel.add(new JLabel("Aula:"));
        panel.add(aulaComboBox);

        int result = JOptionPane.showConfirmDialog(null, panel, existing != null ? "Modifica Prenotazione" : "Aggiungi Prenotazione", JOptionPane.OK_CANCEL_OPTION);

        if (result == JOptionPane.OK_OPTION) {
            String nome = nomeField.getText().trim();
            String motivazione = motivazioneField.getText().trim();
            int oraFine = (int) oraFineSpinner.getValue();
            String selectedDate = (String) dateSelector.getSelectedItem();

            return new Prenotazione(
                    aula.getNumeroAula(),
                    LocalDate.parse(selectedDate),
                    oraInizio,
                    LocalTime.of(oraFine, 0),
                    nome,
                    motivazione
            );
        }
        return null;
    }
}
