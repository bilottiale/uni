package view;

import model.AulaInterface;
import model.Prenotazione;
import utils.BookingRenderer;
import utils.FileManager;
import utils.JsonUtils;

import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.print.*;
import java.io.IOException;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * GUI for managing classroom bookings.
 * <p>
 * This class extends {@link JFrame} to provide a window displaying a table of bookings,
 * with options to save, load, and print the bookings. It implements {@link Printable}
 * to support printing the booking table. The interface allows users to view bookings by date,
 * edit or add new bookings via double-click.
 * </p>
 */
public class MainView extends JFrame implements Printable {
    /** The table for displaying bookings. */
    private JTable table;
    /** The combo box for selecting booking dates. */
    private JComboBox<String> dateSelector;
    /** The list of classrooms available for booking. */
    private List<AulaInterface> aule;
    /** The list of current bookings. */
    private List<Prenotazione> prenotazioni;
    /** The file manager for handling saving and loading of bookings. */
    private FileManager fileManager;
    /** The map of booking descriptions to colors for cell rendering. */
    private final Map<String, Color> colorMap = new HashMap<>();

    /**
     * Constructs a new {@code MainView} instance, initializing the GUI components and loading initial data.
     * <p>
     * Sets up the window with a table for bookings, a date selector, and buttons for saving, loading,
     * and printing. Loads classroom data from a JSON file and attempts to load various {@link Prenotazione} data,
     * falling back to an empty list if loading fails. Adds a window listener to prompt for saving
     * before closing.
     * </p>
     */
    public MainView() {
        setTitle("Gestione Prenotazioni Aule");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
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

                int confirm = JOptionPane.showConfirmDialog(
                        MainView.this,
                        "Vuoi salvare le modifiche prima di chiudere?",
                        "Conferma Uscita",
                        JOptionPane.YES_NO_CANCEL_OPTION,
                        JOptionPane.QUESTION_MESSAGE
                );

                if (confirm == JOptionPane.YES_OPTION) {
                    fileManager.savePrenotazioni(prenotazioni);
                    dispose();
                } else if (confirm == JOptionPane.NO_OPTION) {
                    dispose();
                }
            }
        });

        updateTable();
        setVisible(true);
    }

    /**
     * Adds save, load, and print buttons to the panel of the interface.
     * <p>
     * Configures action listeners for each button: saving bookings to a file, loading bookings from a file,
     * and printing the current table view.
     * </p>
     */
    private void addSaveAndLoadButtons() {
        JPanel buttonPanel = new JPanel();
        JButton saveButton = new JButton("Salva Prenotazioni");
        JButton loadButton = new JButton("Carica Prenotazioni");
        JButton printButton = new JButton("Stampa Prenotazioni");

        saveButton.addActionListener(e -> fileManager.savePrenotazioni(prenotazioni));

        loadButton.addActionListener(e -> {
            List<Prenotazione> loadedPrenotazioni = fileManager.loadPrenotazioni();
            if (loadedPrenotazioni != null) {
                this.prenotazioni = loadedPrenotazioni;
                updateTable();
            }
        });

        printButton.addActionListener(e -> printTable());

        buttonPanel.add(saveButton);
        buttonPanel.add(loadButton);
        buttonPanel.add(printButton);

        add(buttonPanel, BorderLayout.SOUTH);
    }

    /**
     * Retrieves a sorted array of unique booking dates for the date selector.
     *
     * @return An array of {@code String} representing booking dates in "yyyy-MM-dd" format.
     */
    private String[] getDateOptions() {
        return prenotazioni.stream()
                .map(p -> p.getData().toString())
                .distinct()
                .sorted()
                .toArray(String[]::new);
    }

    /**
     * Updates the table with booking data for the selected date.
     * <p>
     * Constructs a table model with columns for each classroom (including type, capacity, and accessories)
     * and rows for each hour from 8:00 to 18:00, filling in booking descriptions where applicable.
     * </p>
     */
    private void updateTable() {
        String selectedDateStr = (String) dateSelector.getSelectedItem();
        LocalDate selectedDate = LocalDate.parse(selectedDateStr);
        DefaultTableModel model = new DefaultTableModel();

        model.addColumn("Ora");
        for (AulaInterface aula : aule) {
            String tipoAula = aula.getTipo().toString();
            int capienza = aula.getCapienza();
            List<Integer> accessoriList = aula.getAccessoriAsListInt();
            StringBuilder accessoriStr = new StringBuilder();

            if (aula.getTipo() == AulaInterface.TipoAula.DIDATTICA) {
                accessoriStr.append("Lavagna: ").append(accessoriList.get(0) == 1 ? "Sì" : "No").append(", ");
                accessoriStr.append("Proiettore: ").append(accessoriList.get(1) == 1 ? "Sì" : "No");
            } else if (aula.getTipo() == AulaInterface.TipoAula.LABORATORIO) {
                accessoriStr.append("PC: ").append(accessoriList.get(0) == 1 ? "Sì" : "No").append(", ");
                accessoriStr.append("Prese: ").append(accessoriList.get(1) == 1 ? "Sì" : "No");
            }

            String columnHeader = String.format("Aula %d - %s - Capienza: %d - %s",
                    aula.getNumeroAula(), tipoAula, capienza, accessoriStr.toString());
            model.addColumn(columnHeader);
        }

        for (int hour = 8; hour <= 18; hour++) {
            Object[] row = new Object[aule.size() + 1];
            row[0] = hour + ":00";

            for (int j = 0; j < aule.size(); j++) {
                AulaInterface aula = aule.get(j);
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

    @Override
    public int print(Graphics g, PageFormat pf, int pageIndex) throws PrinterException {
        if (pageIndex > 0) {
            return NO_SUCH_PAGE; // Only one page
        }

        Graphics2D g2d = (Graphics2D) g;
        g2d.translate(pf.getImageableX(), pf.getImageableY());

        table.print(g2d);

        return PAGE_EXISTS;
    }

    /**
     * Initiates the printing process for the current booking table.
     * <p>
     * Opens a print dialog for user configuration. If confirmed, prints the table using the
     * {@link Printable} implementation, displaying an error message if a {@link PrinterException} occurs.
     * </p>
     */
    private void printTable() {
        PrinterJob job = PrinterJob.getPrinterJob();
        job.setPrintable(this);

        if (job.printDialog()) {
            try {
                job.print();
            } catch (PrinterException ex) {
                JOptionPane.showMessageDialog(this, "Errore durante la stampa: " + ex.getMessage(), "Errore di Stampa", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    /**
     * Generates a unique color for a given booking description using its hash code.
     *
     * @param bookingDescription The description of the booking (e.g., "Nome - Motivazione").
     * @return A {@link Color} object derived from the booking description’s hash value.
     */
    public Color getColorForBooking(String bookingDescription) {
        if (!colorMap.containsKey(bookingDescription)) {
            int hash = bookingDescription.hashCode();
            float hue = (hash % 360) / 360.0f; // Convert hash to hue (0-1 range for HSB)
            colorMap.put(bookingDescription, Color.getHSBColor(hue, 0.8f, 0.8f));
        }
        return colorMap.get(bookingDescription);
    }

    /**
     * Handles the editing or creation of a booking when a table cell is double-clicked.
     *
     * @param row The row index of the clicked cell.
     * @param col The column index of the clicked cell, corresponding to a classroom.
     */
    private void handleCellEdit(int row, int col) {
        String selectedDate = (String) dateSelector.getSelectedItem();
        LocalTime oraInizio = LocalTime.of(8 + row, 0);
        AulaInterface selectedAula = aule.get(col - 1);

        Prenotazione existing = prenotazioni.stream()
                .filter(p -> {
                    AulaInterface aula = p.getAula();
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

    /**
     * Sets up a double-click listener on the table to trigger booking editing or creation.
     */
    private void setupTableClickListener() {
        table.addMouseListener(new java.awt.event.MouseAdapter() {
            @Override
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                if (evt.getClickCount() == 2) {
                    int row = table.getSelectedRow();
                    int col = table.getSelectedColumn();
                    if (row >= 0 && col > 0) { // Ensure valid row and avoid header column
                        handleCellEdit(row, col);
                    }
                }
            }
        });
    }

    /**
     * Displays a dialog for adding or editing a booking.
     * <p>
     * Shows a form with fields for name, date, start time, end time, motivation, and classroom selection.
     * If editing an existing booking, pre-fills the fields and offers a delete option. Validates input
     * and returns a new {@link Prenotazione} object if confirmed, or {@code null} if cancelled or invalid.
     * </p>
     *
     * @param aula The {@link AulaInterface} representing the selected classroom.
     * @param oraInizio The initial start time for the booking.
     * @param existing The existing {@link Prenotazione} to edit, or {@code null} for a new booking.
     * @return A new {@link Prenotazione} object if the dialog is confirmed, or {@code null} if cancelled or invalid.
     */
    private Prenotazione showPrenotazioneDialog(AulaInterface aula, LocalTime oraInizio, Prenotazione existing) {
        JTextField nomeField = new JTextField(existing != null ? existing.getNome() : "");
        JTextField motivazioneField = new JTextField(existing != null ? existing.getMotivazione() : "");
        JComboBox<String> aulaComboBox = new JComboBox<>(aule.stream().map(a -> "Aula " + a.getNumeroAula()).toArray(String[]::new));
        aulaComboBox.setSelectedIndex(aule.indexOf(aula));

        JSpinner oraInizioSpinner = new JSpinner(new SpinnerNumberModel(oraInizio.getHour(), 8, 17, 1));
        JSpinner oraFineSpinner = getJSpinner(aula, oraInizio, existing);

        if (existing != null) {
            oraInizioSpinner.setValue(existing.getOraInizio().getHour());
            oraFineSpinner.setValue(existing.getOraFine().getHour());
        } else {
            oraInizioSpinner.setValue(oraInizio.getHour());
            adjustSpinnerForAula(oraFineSpinner, aula, oraInizio.getHour());
        }

        adjustSpinnerBehavior(oraInizioSpinner, oraFineSpinner, aula);

        JPanel panel = new JPanel(new GridLayout(7, 2));
        panel.add(new JLabel("Nome:"));
        panel.add(nomeField);
        panel.add(new JLabel("Data:"));
        panel.add(new JLabel((String) dateSelector.getSelectedItem()));
        panel.add(new JLabel("Orario Inizio:"));
        panel.add(oraInizioSpinner);
        panel.add(new JLabel("Ora Fine:"));
        panel.add(oraFineSpinner);
        panel.add(new JLabel("Motivazione:"));
        panel.add(motivazioneField);
        panel.add(new JLabel("Aula:"));
        panel.add(aulaComboBox);

        JButton deleteButton = new JButton("Elimina");
        deleteButton.setVisible(existing != null);
        panel.add(new JLabel());
        panel.add(deleteButton);

        aulaComboBox.addItemListener(e -> {
            if (e.getStateChange() == ItemEvent.SELECTED) {
                String selectedAulaText = (String) e.getItem();
                int selectedAulaNumber = Integer.parseInt(selectedAulaText.split(" ")[1]);

                AulaInterface newAula = aule.stream().filter(a -> a.getNumeroAula() == selectedAulaNumber).findFirst().orElse(null);
                if (newAula != null) {
                    adjustSpinnerForAula(oraFineSpinner, newAula, (int) oraInizioSpinner.getValue());
                    adjustSpinnerBehavior(oraInizioSpinner, oraFineSpinner, newAula);
                }
            }
        });

        deleteButton.addActionListener(e -> {
            int confirm = JOptionPane.showConfirmDialog(
                    this,
                    "Sei sicuro di voler eliminare questa prenotazione?",
                    "Conferma Eliminazione",
                    JOptionPane.YES_NO_OPTION
            );
            if (confirm == JOptionPane.YES_OPTION) {
                prenotazioni.remove(existing);
                updateTable();
                JOptionPane.showMessageDialog(this, "Prenotazione eliminata con successo.", "Eliminazione Completata", JOptionPane.INFORMATION_MESSAGE);
                ((JDialog) SwingUtilities.getWindowAncestor((Component) e.getSource())).dispose();
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

    /**
     * Adjusts the behavior of the start and end time spinners based on the classroom type.
     * <p>
     * Configures the step size, range, and constraints for didactic (1-hour steps, 1-8 hours) and
     * laboratory (2-hour steps, 2 or 4 hours) classrooms.
     * </p>
     *
     * @param oraInizioSpinner The {@link JSpinner} for the start time.
     * @param oraFineSpinner The {@link JSpinner} for the end time.
     * @param aula The {@link AulaInterface} representing the selected classroom.
     */
    private void adjustSpinnerBehavior(JSpinner oraInizioSpinner, JSpinner oraFineSpinner, AulaInterface aula) {
        SpinnerNumberModel inizioModel = (SpinnerNumberModel) oraInizioSpinner.getModel();
        SpinnerNumberModel fineModel = (SpinnerNumberModel) oraFineSpinner.getModel();

        if (aula.getTipo() == AulaInterface.TipoAula.LABORATORIO) {
            inizioModel.setStepSize(2);
            inizioModel.setMaximum(16);
            oraInizioSpinner.setEditor(new JSpinner.NumberEditor(oraInizioSpinner, "#"));
            oraInizioSpinner.addChangeListener(e -> {
                int newStart = (int) oraInizioSpinner.getValue();
                int maxEnd = Math.min(newStart + 4, 18);
                fineModel.setMinimum(newStart + 2);
                fineModel.setMaximum(maxEnd);
                fineModel.setValue(Math.max((int) fineModel.getValue(), newStart + 2));
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
        } else if (aula.getTipo() == AulaInterface.TipoAula.DIDATTICA) {
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

    /**
     * Configures the end time spinner based on the classroom type and start time.
     *
     * @param oraFineSpinner The {@link JSpinner} for the end time.
     * @param aula The {@link AulaInterface} representing the selected classroom.
     * @param oraInizio The start time hour (8-17) used to set the range.
     */
    private void adjustSpinnerForAula(JSpinner oraFineSpinner, AulaInterface aula, int oraInizio) {
        int maxEndHour = Math.min(oraInizio + (aula.getTipo() == AulaInterface.TipoAula.LABORATORIO ? 4 : 8), 18);
        int minEndHour = oraInizio + (aula.getTipo() == AulaInterface.TipoAula.LABORATORIO ? 2 : 1);

        SpinnerNumberModel model = (SpinnerNumberModel) oraFineSpinner.getModel();
        model.setMinimum(minEndHour);
        model.setMaximum(maxEndHour);
        model.setStepSize(aula.getTipo() == AulaInterface.TipoAula.LABORATORIO ? 2 : 1);

        if (model.getValue() == null || (int) model.getValue() < minEndHour) {
            model.setValue(minEndHour);
        }
    }

    /**
     * Creates and configures an end time spinner based on the classroom type and existing booking data.
     *
     * @param aula The {@link AulaInterface} representing the selected classroom.
     * @param oraInizio The initial start time for the booking.
     * @param existing The existing {@link Prenotazione} to pre-fill, or {@code null} for a new booking.
     * @return A configured {@link JSpinner} for selecting the end time.
     */
    private static JSpinner getJSpinner(AulaInterface aula, LocalTime oraInizio, Prenotazione existing) {
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
                aula.getTipo() == AulaInterface.TipoAula.DIDATTICA ? 1 : 2);
        JSpinner oraFineSpinner = new JSpinner(oraFineModel);
        return oraFineSpinner;
    }
}