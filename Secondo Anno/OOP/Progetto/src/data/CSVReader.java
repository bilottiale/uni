package data;

import java.io.*;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.*;
import model.*;

public class CSVReader {
    /**
     * Legge le prenotazioni da un file CSV
     * 
     * @param filePrenotazioni
     * @return
     */
    public static List<Prenotazione> readPrenotazioni(String filePrenotazioni) {
        System.out.println("Reading prenotazioni from file: " + filePrenotazioni);
    List<Prenotazione> prenotazioni = new ArrayList<>();
    try (BufferedReader br = new BufferedReader(new FileReader(filePrenotazioni))) {
        String line;
        boolean firstLine = true;

        // Leggi il file riga per riga
        while ((line = br.readLine()) != null) {
            // Salta l'intestazione
            if (firstLine) {
                firstLine = false;
                continue;
            }

            // Salta righe vuote o malformate
            if (line.trim().isEmpty()) {
                continue;
            }

            // Dividi la riga in base alla virgola
            String[] parts = line.split(",");

            // Verifica che la riga abbia esattamente il numero corretto di campi
            if (parts.length != 6) {
                System.err.println("Riga malformata, saltata: " + line);
                continue;
            }

            try {
                // Parsing dei dati
                int idAula = Integer.parseInt(parts[0].trim()); // idAula
                LocalDate data = LocalDate.parse(parts[1].trim()); // data
                LocalTime oraInizio = LocalTime.parse(parts[2].trim()); // oraInizio
                LocalTime oraFine = LocalTime.parse(parts[3].trim()); // oraFine
                String nomePrenotante = parts[4].trim(); // nomePrenotante
                String motivazione = parts[5].trim(); // motivazione

                // Crea l'oggetto Prenotazione
                Prenotazione prenotazione = new Prenotazione(idAula, data, oraInizio, oraFine, nomePrenotante, motivazione);
                prenotazioni.add(prenotazione);
            } catch (Exception e) {
                // Gestisci eventuali errori di parsing
                System.err.println("Errore durante il parsing della riga, saltata: " + line);
                e.printStackTrace();
            }
        }
    } catch (IOException e) {
        e.printStackTrace();
    }
    return prenotazioni;
    }

    /**
     * Legge le aule da un file CSV
     * 
     * @param fileAule
     * @return
     */
    public static List<Aula> readAule(String fileAule) {
        System.out.println("Reading aule from file: " + fileAule);
        List<Aula> aule = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(fileAule))) {
            String line;
            boolean firstLine = true;

            // Leggi il file riga per riga
            while ((line = br.readLine()) != null) {
                // Salta l'intestazione
                if (firstLine) {
                    firstLine = false;
                    continue;
                }

                // Dividi la riga in base alla virgola
                String[] parts = line.split(",");
                System.out.println("DEBUG");

                // Parsing dei dati
                int id = Integer.parseInt(parts[0]); // id
                int capienza = Integer.parseInt(parts[1]); // capienza
                String nome = parts[2]; // nome
                System.out.println(nome);

                if ("Laboratorio".equals(nome)) {
                    System.out.println("DEBUG LABORATORIO");
                    boolean accessorio1 = Boolean.parseBoolean(parts[3]); // pc
                    boolean accessorio2 = Boolean.parseBoolean(parts[4]); // prese elettriche
                    Aula aula = new Laboratorio(id, capienza, nome, accessorio1, accessorio2);
                    aule.add(aula);
                } else if ("Didattica".equals(nome)) {
                    boolean accessorio1 = Boolean.parseBoolean(parts[3]); // proiettore
                    boolean accessorio2 = Boolean.parseBoolean(parts[4]); // lavagna
                    Aula aula = new AulaDidattica(id, capienza, nome, accessorio1, accessorio2);
                    aule.add(aula);
                    System.out.println("DEBUG AULA DIDATTICA");
                }

            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return aule;
    }

    // write prenotazioni in base al
    public static void aggiungiPrenotazione(String filePrenotazioni, Prenotazione prenotazione) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePrenotazioni, true))) {
            bw.write(prenotazione.getIdAula() + "," + prenotazione.getData() + "," + prenotazione.getOraInizio() + ","
                    + prenotazione.getOraFine() + "," + prenotazione.getNomePrenotante() + ","
                    + prenotazione.getMotivazione());
            bw.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}