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

public class FileManager {

    private final JsonUtils jsonUtils;
    private final ScheduledExecutorService scheduler;
    private List<Prenotazione> currentPrenotazioni;

    public FileManager() {
        this.jsonUtils = new JsonUtils();
        this.scheduler = Executors.newSingleThreadScheduledExecutor();

        scheduler.scheduleAtFixedRate(this::saveToTempFile, 0, 30, TimeUnit.SECONDS);
    }

    /**
     * Saves the list of bookings to a user-selected JSON file.
     *
     * @param prenotazioni The list of Prenotazione objects to save.
     */
    public void savePrenotazioni(List<Prenotazione> prenotazioni) {
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
     *
     * @return A List of Prenotazione objects from the file or null if loading was cancelled or failed.
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

    public void stopAutoSaving() {
        scheduler.shutdown();
    }
}