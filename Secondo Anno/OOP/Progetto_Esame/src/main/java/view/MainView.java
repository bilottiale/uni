package view;

import model.Prenotazione;
import model.Aula;
import utils.FileManager;
import utils.JsonUtils;

import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.*;
import java.util.List;

public class MainView extends JFrame {
    private JTable table;
    private JComboBox<String> dateSelector;
    private List<Aula> aule;
    private List<Prenotazione> prenotazioni;
    private FileManager fileManager;
    private Map<String, Color> colorMap = new HashMap<>();

    public MainView() {
        setTitle("Gestione Prenotazioni Aule");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        aule = JsonUtils.leggiAuleDaJson();
        try {
            prenotazioni = JsonUtils.leggiPrenotazioniDaJson("data/prenotazioni.json");
        } catch (IOException e) {
            prenotazioni = new ArrayList<>();
            JOptionPane.showMessageDialog(this, "Nessun file di prenotazioni trovato, iniziato con lista vuota.", "Avviso", JOptionPane.WARNING_MESSAGE);
        }

        dateSelector = new JComboBox<>(getDateOptions());
        dateSelector.addActionListener(e -> updateTable());
        add(dateSelector, BorderLayout.NORTH);

        table = new JTable();
        table.setCellSelectionEnabled(true);
        table.setDefaultEditor(Object.class, null);
        JScrollPane scrollPane = new JScrollPane(table);
        add(scrollPane, BorderLayout.CENTER);

        setupTableClickListener();

        this.fileManager = new FileManager();
        addSaveAndLoadButtons();

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                if (fileManager != null) {
                    fileManager.stopAutoSaving();
                }
                super.windowClosing(e);
            }
        });

        updateTable();
        setVisible(true);
    }

    private void addSaveAndLoadButtons() {
        JPanel buttonPanel = new JPanel();
        JButton saveButton = new JButton("Salva Prenotazioni");
        JButton loadButton = new JButton("Carica Prenotazioni");

        saveButton.addActionListener(e -> {
            fileManager.savePrenotazioni(prenotazioni);
        });

        loadButton.addActionListener(e -> {
            List<Prenotazione> loadedPrenotazioni = fileManager.loadPrenotazioni();
            if (loadedPrenotazioni != null) {
                this.prenotazioni = loadedPrenotazioni;
                updateTable();
            }
        });

        buttonPanel.add(saveButton);
        buttonPanel.add(loadButton);

        add(buttonPanel, BorderLayout.SOUTH);
    }

    private String[] getDateOptions() {
        return prenotazioni.stream()
                .map(p -> p.getData().toString())
                .distinct()
                .sorted()
                .toArray(String[]::new);
    }

    private void updateTable() {
        String selectedDateStr = (String) dateSelector.getSelectedItem();
        LocalDate selectedDate = LocalDate.parse(selectedDateStr);
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
                String cellContent = "";

                for (Prenotazione p : prenotazioni) {
                    if (p.getAula().getNumeroAula() == aula.getNumeroAula()
                            && p.getData().equals(selectedDate)) {
                        int startHour = p.getOraInizio().getHour();
                        int endHour = p.getOraFine().getHour();

                        if (startHour <= hour && endHour > hour) {
                            cellContent = p.getDescrizione();
                            break;
                        }
                    }
                }
                row[j + 1] = cellContent;
            }
            model.addRow(row);
        }

        table.setModel(model);
        table.setShowGrid(true);
        table.setDefaultRenderer(Object.class, new BookingRenderer());
    }

    private static class BookingRenderer extends DefaultTableCellRenderer {
        @Override
        public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
            Component comp = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);

            if (comp instanceof JComponent) {
                ((JComponent) comp).setBorder(null);
            }

            if (column > 0 && value != null && !value.toString().isEmpty()) {
                Color color = ((MainView) table.getRootPane().getParent()).getColorForBooking(value.toString());
                comp.setBackground(color);

                if (isPartOfLargerBooking(table, row, column)) {
                    comp.setBackground(color.brighter());
                }

                if (isFirstCellOfBooking(table, row, column)) {
                    assert comp instanceof JComponent;
                    ((JComponent) comp).setBorder(BorderFactory.createMatteBorder(1, 1, 0, 0, comp.getBackground()));
                } else if (isLastCellOfBooking(table, row, column)) {
                    assert comp instanceof JComponent;
                    ((JComponent) comp).setBorder(BorderFactory.createMatteBorder(0, 0, 1, 1, comp.getBackground()));
                } else {
                    assert comp instanceof JComponent;
                    ((JComponent) comp).setBorder(null);
                }

                setText(getBookingText(table, value, row, column));
            } else {
                comp.setBackground(Color.WHITE);
                setText(value != null ? value.toString() : "");
            }

            return comp;
        }

        private String getBookingText(JTable table, Object value, int row, int column) {
            if (row == 0 || !value.equals(table.getValueAt(row - 1, column))) {
                return value.toString();
            }
            return "";
        }

        private boolean isPartOfLargerBooking(JTable table, int row, int column) {
            Object value = table.getValueAt(row, column);
            if (row + 1 < table.getRowCount() && value.equals(table.getValueAt(row + 1, column))) {
                return true;
            }
            if (row > 0 && value.equals(table.getValueAt(row - 1, column))) {
                return true;
            }
            return false;
        }

        private boolean isFirstCellOfBooking(JTable table, int row, int column) {
            if (row == 0 || !table.getValueAt(row - 1, column).equals(table.getValueAt(row, column))) {
                return true;
            }
            return false;
        }

        private boolean isLastCellOfBooking(JTable table, int row, int column) {
            if (row + 1 >= table.getRowCount() || !table.getValueAt(row + 1, column).equals(table.getValueAt(row, column))) {
                return true;
            }
            return false;
        }
    }

    private Color getColorForBooking(String bookingDescription) {
        if (!colorMap.containsKey(bookingDescription)) {
            int hash = bookingDescription.hashCode();
            float hue = (hash % 360) / 360.0f; // hash ->  hue (0-1 range Color.HSBtoRGB)
            colorMap.put(bookingDescription, Color.getHSBColor(hue, 0.8f, 0.8f));
        }
        return colorMap.get(bookingDescription);
    }

    private void handleCellEdit(int row, int col) {
        String selectedDate = (String) dateSelector.getSelectedItem();
        LocalTime oraInizio = LocalTime.of(8 + row, 0);
        Aula selectedAula = aule.get(col - 1);

        Prenotazione existing = prenotazioni.stream()
                .filter(p -> {
                    Aula aula = p.getAula();
                    return aula != null &&
                            aula.getNumeroAula() == selectedAula.getNumeroAula() &&
                            p.getData().equals(LocalDate.parse(selectedDate)) &&
                            (p.getOraInizio().equals(oraInizio) ||
                                    (p.getOraInizio().isBefore(oraInizio) && p.getOraFine().isAfter(oraInizio)));
                })
                .findFirst()
                .orElse(null);

        Prenotazione newPrenotazione = showPrenotazioneDialog(selectedAula, oraInizio, existing);

        if (newPrenotazione != null) {
            System.out.println("New Prenotazione after creation - Nome: " + newPrenotazione.getNome() + ", Motivazione: " + newPrenotazione.getMotivazione());

            if (newPrenotazione.getNome().isEmpty() || newPrenotazione.getMotivazione().isEmpty()) {
                JOptionPane.showMessageDialog(
                        this,
                        "Nome o motivazione non possono essere vuoti!",
                        "Errore Prenotazione",
                        JOptionPane.ERROR_MESSAGE
                );
                return;
            }

            if (existing != null) {
                prenotazioni.remove(existing);
            }
            prenotazioni.add(newPrenotazione);
            updateTable();
        }
    }

    private void setupTableClickListener() {
        table.addMouseListener(new java.awt.event.MouseAdapter() {
            @Override
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                if (evt.getClickCount() == 2) {
                    int row = table.getSelectedRow();
                    int col = table.getSelectedColumn();
                    if (row > 0 && col > 0) {
                        handleCellEdit(row, col);
                    }
                }
            }
        });
    }

    private Prenotazione showPrenotazioneDialog(Aula aula, LocalTime oraInizio, Prenotazione existing) {
        // Create fields
        JTextField nomeField = new JTextField(existing != null ? existing.getNome() : "");
        JTextField motivazioneField = new JTextField(existing != null ? existing.getMotivazione() : "");
        JComboBox<String> aulaComboBox = new JComboBox<>(aule.stream().map(a -> "Aula " + a.getNumeroAula()).toArray(String[]::new));
        aulaComboBox.setSelectedIndex(aule.indexOf(aula)); // Select existing classroom

        JSpinner oraInizioSpinner = new JSpinner(new SpinnerNumberModel(oraInizio.getHour(), 8, 17, 1));
        JSpinner oraFineSpinner = getJSpinner(aula, oraInizio, existing);

        // If there's an existing booking, set the time fields
        if (existing != null) {
            oraInizioSpinner.setValue(existing.getOraInizio().getHour());
            oraFineSpinner.setValue(existing.getOraFine().getHour());
        } else {
            // Set default values for new bookings based on the initial aula type
            oraInizioSpinner.setValue(oraInizio.getHour());
            adjustSpinnerForAula(oraFineSpinner, aula, oraInizio.getHour());
        }

        // Adjust spinner behavior based on Aula type
        adjustSpinnerBehavior(oraInizioSpinner, oraFineSpinner, aula);

        JPanel panel = new JPanel(new GridLayout(7, 2));
        panel.add(new JLabel("Nome:"));
        panel.add(nomeField);
        panel.add(new JLabel("Data:"));
        panel.add(new JLabel((String) dateSelector.getSelectedItem())); // Show date
        panel.add(new JLabel("Orario Inizio:"));
        panel.add(oraInizioSpinner);
        panel.add(new JLabel("Ora Fine:"));
        panel.add(oraFineSpinner);
        panel.add(new JLabel("Motivazione:"));
        panel.add(motivazioneField);
        panel.add(new JLabel("Aula:"));
        panel.add(aulaComboBox);

        JButton deleteButton = new JButton("Elimina");
        deleteButton.setVisible(existing != null); // Only show if we're modifying an existing booking
        panel.add(new JLabel()); // Spacer
        panel.add(deleteButton);

        // Add an ItemListener to the aulaComboBox to adjust oraFineSpinner based on classroom type
        aulaComboBox.addItemListener(e -> {
            if (e.getStateChange() == ItemEvent.SELECTED) {
                String selectedAulaText = (String) e.getItem();
                int selectedAulaNumber = Integer.parseInt(selectedAulaText.split(" ")[1]);

                Aula newAula = aule.stream().filter(a -> a.getNumeroAula() == selectedAulaNumber).findFirst().orElse(null);
                if (newAula != null) {
                    adjustSpinnerForAula(oraFineSpinner, newAula, (int) oraInizioSpinner.getValue());
                    adjustSpinnerBehavior(oraInizioSpinner, oraFineSpinner, newAula); // Re-adjust spinner behavior
                }
            }
        });

        int result = JOptionPane.showConfirmDialog(null, panel, existing != null ? "Modifica Prenotazione" : "Aggiungi Prenotazione", JOptionPane.OK_CANCEL_OPTION);

        if (result == JOptionPane.OK_OPTION) {
            String nome = nomeField.getText().trim();
            String motivazione = motivazioneField.getText().trim();
            int oraInizioValue = (int) oraInizioSpinner.getValue();
            int oraFine = (int) oraFineSpinner.getValue();
            String selectedDate = (String) dateSelector.getSelectedItem();

            System.out.println("Nome: " + nome);
            System.out.println("Motivazione: " + motivazione);

            if (nome == null || nome.isEmpty() || motivazione == null || motivazione.isEmpty()) {
                JOptionPane.showMessageDialog(
                        null,
                        "Nome o motivazione non possono essere vuoti!",
                        "Errore Prenotazione",
                        JOptionPane.ERROR_MESSAGE
                );
                return null;
            }

            return new Prenotazione(
                    aula.getNumeroAula(),
                    LocalDate.parse(selectedDate),
                    LocalTime.of(oraInizioValue, 0),
                    LocalTime.of(oraFine, 0),
                    nome,
                    motivazione
            );
        }
        return null;
    }

    private void adjustSpinnerBehavior(JSpinner oraInizioSpinner, JSpinner oraFineSpinner, Aula aula) {
        SpinnerNumberModel inizioModel = (SpinnerNumberModel) oraInizioSpinner.getModel();
        SpinnerNumberModel fineModel = (SpinnerNumberModel) oraFineSpinner.getModel();

        if (aula.getTipo() == Aula.TipoAula.LABORATORIO) {
            inizioModel.setStepSize(2);
            inizioModel.setMaximum(16);
            oraInizioSpinner.setEditor(new JSpinner.NumberEditor(oraInizioSpinner, "#"));
            oraInizioSpinner.addChangeListener(e -> {
                int newStart = (int) oraInizioSpinner.getValue();
                int maxEnd = Math.min(newStart + 4, 18);
                fineModel.setMinimum(newStart + 2);
                fineModel.setMaximum(maxEnd);
                fineModel.setValue(Math.max((int) fineModel.getValue(), newStart + 2)); // Ensure value is at least min
            });

            fineModel.setStepSize(2);
            fineModel.setMaximum(18);
            oraFineSpinner.setEditor(new JSpinner.NumberEditor(oraFineSpinner, "#"));
            oraFineSpinner.addChangeListener(e -> {
                int start = (int) oraInizioSpinner.getValue();
                int end = (int) oraFineSpinner.getValue();
                int maxEnd = Math.min(start + 4, 18);
                if (end > maxEnd) {
                    fineModel.setValue(maxEnd);
                }
                if (end < start + 2) {
                    fineModel.setValue(start + 2);
                }
            });
        } else if (aula.getTipo() == Aula.TipoAula.DIDATTICA) {
            inizioModel.setStepSize(1);
            inizioModel.setMinimum(8);
            inizioModel.setMaximum(17);

            oraInizioSpinner.setEditor(new JSpinner.NumberEditor(oraInizioSpinner, "#"));

            oraInizioSpinner.addChangeListener(e -> {
                int newStart = (int) oraInizioSpinner.getValue();
                int maxEnd = Math.min(newStart + 8, 18);

                fineModel.setMinimum(newStart + 1);
                fineModel.setMaximum(maxEnd);

                if ((int) fineModel.getValue() < newStart + 1 || (int) fineModel.getValue() > maxEnd) {
                    fineModel.setValue(newStart + 1);
                }
            });

            fineModel.setStepSize(1);
            fineModel.setMinimum(9);
            fineModel.setMaximum(18);

            oraFineSpinner.setEditor(new JSpinner.NumberEditor(oraFineSpinner, "#"));
            oraFineSpinner.addChangeListener(e -> {
                int start = (int) oraInizioSpinner.getValue();
                int end = (int) oraFineSpinner.getValue();
                int maxEnd = Math.min(start + 8, 18);

                if (end > maxEnd) {
                    fineModel.setValue(maxEnd);
                } else if (end < start + 1) {
                    fineModel.setValue(start + 1);
                }
            });
        }
    }

    private Prenotazione createPrenotazioneFromDialog(Aula aula, JSpinner oraInizioSpinner, JSpinner oraFineSpinner,
                                                      JTextField nomeField, JTextField motivazioneField) {
        String nome = nomeField.getText().trim();
        String motivazione = motivazioneField.getText().trim();
        int oraInizioValue = (int) oraInizioSpinner.getValue();
        int oraFine = (int) oraFineSpinner.getValue();
        String selectedDate = (String) dateSelector.getSelectedItem();

        System.out.println("Nome: " + nome);
        System.out.println("Motivazione: " + motivazione);

        if (nome == null || nome.isEmpty() || motivazione == null || motivazione.isEmpty()) {
            JOptionPane.showMessageDialog(
                    null,
                    "Nome o motivazione non possono essere vuoti!",
                    "Errore Prenotazione",
                    JOptionPane.ERROR_MESSAGE
            );
            return null;
        }

        return new Prenotazione(
                aula.getNumeroAula(),
                LocalDate.parse(selectedDate),
                LocalTime.of(oraInizioValue, 0),
                LocalTime.of(oraFine, 0),
                nome,
                motivazione
        );
    }

    private void adjustSpinnerForAula(JSpinner oraFineSpinner, Aula aula, int oraInizio) {
        int maxEndHour = Math.min(oraInizio + (aula.getTipo() == Aula.TipoAula.LABORATORIO ? 4 : 8), 18);
        int minEndHour = oraInizio + (aula.getTipo() == Aula.TipoAula.LABORATORIO ? 2 : 1);

        SpinnerNumberModel model = (SpinnerNumberModel) oraFineSpinner.getModel();
        model.setMinimum(minEndHour);
        model.setMaximum(maxEndHour);
        model.setStepSize(aula.getTipo() == Aula.TipoAula.LABORATORIO ? 2 : 1);

        if (model.getValue() == null || (int) model.getValue() < minEndHour) {
            model.setValue(minEndHour);
        }
    }

    private static JSpinner getJSpinner(Aula aula, LocalTime oraInizio, Prenotazione existing) {
        int maxEndHour = Math.min(oraInizio.getHour() + 8, 18);
        int minEndHour = oraInizio.getHour() + 1;

        int initialEndHour;
        if (existing != null) {
            initialEndHour = existing.getOraFine().getHour();
        } else {
            initialEndHour = minEndHour;
        }

        SpinnerNumberModel oraFineModel = new SpinnerNumberModel(
                initialEndHour,
                minEndHour, maxEndHour,
                aula.getTipo() == Aula.TipoAula.DIDATTICA ? 1 : 2);
        JSpinner oraFineSpinner = new JSpinner(oraFineModel);
        return oraFineSpinner;
    }
}