package util;

import controller.GestorePrenotazioni;
import model.Aula;
import model.Prenotazione;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import static controller.GestoreAule.aulaToString;

public class FileManager {

    private static final String PATH_AULE = "./src/util/aule.csv";
    private static final String PATH_PRENOTAZIONI = "./src/util/prenotazioni.csv";

    // Metodo per creare i file se non esistono
    public static void createFiles() {
        createFile(PATH_AULE, "Numero,Capienza,Tipo,Lavagna,Accessorio1,Accessorio2\n");
        createFile(PATH_PRENOTAZIONI, "Aula,Data,OraInizio,OraFine,Docente\n");
    }

    private static void createFile(String filePath, String header) {
        File file = new File(filePath);
        if (!file.exists()) {
            try (FileWriter writer = new FileWriter(file)) {
                writer.write(header);
                System.out.println("Creato file: " + filePath);
            } catch (IOException e) {
                System.err.println("Errore nella creazione del file: " + filePath);
                e.printStackTrace();
            }
        } else {
            System.out.println("Il file esiste già: " + filePath);
        }
    }

    // Add aula, controlla che non esista già(n_aula)
    public static void addAula(Aula aula) {
        String aula_toString = aulaToString(aula);
        try (FileWriter writer = new FileWriter(PATH_AULE, true)) {
            // Controllo se l'aula è già presente
            java.util.Scanner scanner = new java.util.Scanner(new File(PATH_AULE));
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] values = line.split(",");
                if (values[0].equals(String.valueOf(aula.getN_aula()))) {
                    System.err.println("Aula già presente: " + aula_toString);
                    return;
                }
            }
            writer.write(aula_toString);
            System.out.println("Aula aggiunta: " + aula_toString);
        } catch (IOException e) {
            System.err.println("Errore nell'aggiunta dell'aula: " + aula_toString);
            e.printStackTrace();
        }
    }

    // print aule
    public static void getAule() {
        try (java.util.Scanner scanner = new java.util.Scanner(new File(PATH_AULE))) {
            System.out.println("Aule:");
            while (scanner.hasNextLine()) {
                System.out.println(scanner.nextLine());
            }
        } catch (IOException e) {
            System.err.println("Errore nella lettura del file: " + PATH_AULE);
            e.printStackTrace();
        }
    }

    public static void deleteAula(int n_aula) {
        try {
            File file = new File(PATH_AULE);
            File tempFile = new File("temp.csv");

            // Scrivi l'intestazione nel file temporaneo
            try (FileWriter writer = new FileWriter(tempFile)) {
                writer.write("Numero,Capienza,Tipo,Accessorio1,Accessorio2\n");
            }

            if (file.exists()) {
                try (java.util.Scanner scanner = new java.util.Scanner(file)) {
                    boolean isHeader = true; // Variabile per ignorare l'header
                    while (scanner.hasNextLine()) {
                        String line = scanner.nextLine();

                        // Salta la riga di intestazione
                        if (isHeader) {
                            isHeader = false;
                            continue;
                        }

                        String[] values = line.split(",");
                        if (Integer.parseInt(values[0]) != n_aula) {
                            try (FileWriter writer2 = new FileWriter(tempFile, true)) {
                                writer2.write(line + "\n");
                            }
                        }
                    }
                }

                // Elimina il file originale e rinomina il file temporaneo
                if (file.delete() && tempFile.renameTo(file)) {
                    System.out.println("Aula eliminata: " + n_aula);
                } else {
                    System.err.println("Errore nel rinominare il file temporaneo.");
                }
            } else {
                System.err.println("Il file non esiste: " + PATH_AULE);
            }
        } catch (IOException | NumberFormatException e) {
            System.err.println("Errore nell'eliminazione dell'aula: " + n_aula);
            e.printStackTrace();
        }
    }

    // Add prenotazione, controlla che non esista già (stesso n_aula, data, oraInizio, oraFine)
    public static void addPrenotazione(Prenotazione prenotazione) {
        String prenotazione_toString = GestorePrenotazioni.prenotazioneToString(prenotazione);
        try (FileWriter writer = new FileWriter(PATH_PRENOTAZIONI, true)) {
            // Controllo se la prenotazione è già presente
            java.util.Scanner scanner = new java.util.Scanner(new File(PATH_PRENOTAZIONI));
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] values = line.split(",");
                if (values[0].equals(String.valueOf(prenotazione.getAula().getN_aula())) &&
                        values[1].equals(String.valueOf(prenotazione.getData())) &&
                        values[2].equals(String.valueOf(prenotazione.getOraInizio())) &&
                        values[3].equals(String.valueOf(prenotazione.getOraFine()))) {
                    System.err.println("Prenotazione già presente: " + prenotazione_toString);
                    return;
                }
            }
            writer.write(prenotazione_toString);
            System.out.println("Prenotazione aggiunta: " + prenotazione_toString);
        } catch (IOException e) {
            System.err.println("Errore nell'aggiunta della prenotazione: " + prenotazione_toString);
            e.printStackTrace();
        }
    }

    // print prenotazioni
    public static void getPrenotazioni() {
        try (java.util.Scanner scanner = new java.util.Scanner(new File(PATH_PRENOTAZIONI))) {
            System.out.println("Prenotazioni:");
            while (scanner.hasNextLine()) {
                System.out.println(scanner.nextLine());
            }
        } catch (IOException e) {
            System.err.println("Errore nella lettura del file: " + PATH_PRENOTAZIONI);
            e.printStackTrace();
        }
    }
}
