package utils;

import model.Prenotazione;

import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

/**
 * Manages file operations for saving and loading {@link Prenotazione} objects.
 * Provides functionality to save bookings to a user-selected JSON file, load bookings from a file,
 * and automatically save the current state to a temporary file every 30 seconds.
 */
public class FileManager {

    private final JsonUtils jsonUtils;
    private final ScheduledExecutorService scheduler;
    private List<Prenotazione> currentPrenotazioni;

    /**
     * Constructs a new {@code FileManager} instance.
     * <p>
     * Initializes a {@link JsonUtils} instance for JSON operations and starts a scheduler
     * to periodically save the current bookings to a temporary file every 30 seconds.
     * </p>
     */
    public FileManager() {
        this.jsonUtils = new JsonUtils();
        this.scheduler = Executors.newSingleThreadScheduledExecutor();

        scheduler.scheduleAtFixedRate(this::saveToTempFile, 0, 30, TimeUnit.SECONDS);
    }

    /**
     * Saves the provided list of bookings to a user-selected JSON file.
     * <p>
     * Opens a file chooser dialog for the user to select a save location. If the selected file already exists,
     * prompts the user to confirm overwriting it. If the filename does not end with ".json", appends the extension.
     * Displays a success message upon successful save or an error message if an {@link IOException} occurs.
     * </p>
     *
     * @param prenotazioni The list of {@link Prenotazione} objects to save.
     * @throws IllegalArgumentException if the {@code prenotazioni} list is null.
     */
    public void savePrenotazioni(List<Prenotazione> prenotazioni) {
        if (prenotazioni == null) {
            throw new IllegalArgumentException("La lista delle prenotazioni non può essere null.");
        }
        this.currentPrenotazioni = prenotazioni;
        JFileChooser fileChooser = new JFileChooser();
        fileChooser.setDialogTitle("Salva prenotazioni");
        fileChooser.setFileFilter(new FileNameExtensionFilter("JSON files (*.json)", "json"));

        int userSelection = fileChooser.showSaveDialog(null);

        if (userSelection == JFileChooser.APPROVE_OPTION) {
            File fileToSave = fileChooser.getSelectedFile();
            String fileName = fileToSave.getName();
            if (!fileName.toLowerCase().endsWith(".json")) {
                fileToSave = new File(fileToSave.getParentFile(), fileName + ".json");
            }

            // Check if file exists and prompt for overwrite confirmation
            if (fileToSave.exists()) {
                int confirm = JOptionPane.showConfirmDialog(
                        null,
                        "Il file " + fileToSave.getName() + " esiste già. Vuoi sovrascriverlo?",
                        "Conferma Sovrascrittura",
                        JOptionPane.YES_NO_OPTION,
                        JOptionPane.WARNING_MESSAGE
                );
                if (confirm != JOptionPane.YES_OPTION) {
                    return; // User chose not to overwrite, exit the method
                }
            }

            try {
                jsonUtils.scriviPrenotazioniSuJson(fileToSave.getAbsolutePath(), prenotazioni);
                JOptionPane.showMessageDialog(null, "Prenotazioni salvate in " + fileToSave.getName(), "Salvataggio Completato", JOptionPane.INFORMATION_MESSAGE);
            } catch (IOException e) {
                JOptionPane.showMessageDialog(null, "Errore durante il salvataggio: " + e.getMessage(), "Errore", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    /**
     * Loads bookings from a user-selected JSON file.
     * <p>
     * Opens a file chooser dialog for the user to select a file to load. Displays a success message
     * upon successful load or an error message if an {@link IOException} occurs. Updates the
     * internal state with the loaded bookings if successful.
     * </p>
     *
     * @return A {@code List} of {@link Prenotazione} objects loaded from the file,
     *         or {@code null} if loading was cancelled or failed.
     */
    public List<Prenotazione> loadPrenotazioni() {
        JFileChooser fileChooser = new JFileChooser();
        fileChooser.setDialogTitle("Carica prenotazioni");
        fileChooser.setFileFilter(new FileNameExtensionFilter("JSON files (*.json)", "json"));

        int userSelection = fileChooser.showOpenDialog(null);

        if (userSelection == JFileChooser.APPROVE_OPTION) {
            File fileToOpen = fileChooser.getSelectedFile();
            try {
                List<Prenotazione> loadedPrenotazioni = JsonUtils.leggiPrenotazioniDaJson(fileToOpen.getAbsolutePath());
                JOptionPane.showMessageDialog(null, "Prenotazioni caricate da " + fileToOpen.getName(), "Caricamento Completato", JOptionPane.INFORMATION_MESSAGE);
                this.currentPrenotazioni = loadedPrenotazioni;
                return loadedPrenotazioni;
            } catch (IOException e) {
                JOptionPane.showMessageDialog(null, "Errore durante il caricamento: " + e.getMessage(), "Errore", JOptionPane.ERROR_MESSAGE);
            }
        }
        return null;
    }

    /**
     * Automatically saves the current list of bookings to a temporary file every 30 seconds.
     * <p>
     * Uses the system's temporary directory to store the file as "prenotazioni_temp.json".
     * Prints a success message to the console upon save or an error message to the error stream
     * if an {@link IOException} occurs. Does nothing if no bookings are currently set.
     * </p>
     */
    private void saveToTempFile() {
        if (currentPrenotazioni != null) {
            String tempFilePath = System.getProperty("java.io.tmpdir") + "prenotazioni_temp.json";
            try {
                jsonUtils.scriviPrenotazioniSuJson(tempFilePath, currentPrenotazioni);
                System.out.println("Prenotazioni salvate in file temporaneo: " + tempFilePath);
            } catch (IOException e) {
                System.err.println("Errore nel salvataggio del file temporaneo: " + e.getMessage());
            }
        }
    }

    /**
     * Stops the scheduled auto-saving process.
     * <p>
     * Shuts down the {@link ScheduledExecutorService} used for periodic saving,
     * preventing further automatic saves.
     * </p>
     */
    public void stopAutoSaving() {
        scheduler.shutdown();
    }
}